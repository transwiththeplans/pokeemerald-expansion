#!/usr/bin/env python3
"""
Calculate Pokemon .backPicYOffset values from this project's back sprite PNGs.

This is intentionally standalone: keep it outside the repo and run it against a
checkout, for example from WSL:

    python3 /tmp/generate_back_pic_y_offsets.py /home/belial/omniversal-emerald

By default it only reports differences. Use --write to update species_info files.
"""

from __future__ import annotations

import argparse
import dataclasses
import pathlib
import re
import struct
import sys
import zlib


GRAPHICS_HEADER = pathlib.Path("src/data/graphics/pokemon.h")
SPECIES_INFO_DIR = pathlib.Path("src/data/pokemon/species_info")


@dataclasses.dataclass(frozen=True)
class BackPicAsset:
    symbol: str
    png_path: pathlib.Path
    is_gba_style: bool


@dataclasses.dataclass
class Finding:
    file: pathlib.Path
    line: int
    expr_start: int
    expr_end: int
    symbol: str
    current_expr: str
    replacement_expr: str | None
    details: str

    @property
    def changed(self) -> bool:
        return self.replacement_expr is not None and self.current_expr != self.replacement_expr


def extract_numbers_from_offset_expr(expr: str) -> list[int] | None:
    expr = expr.strip()
    if re.fullmatch(r"\d+", expr):
        return [int(expr)]

    ternary = re.fullmatch(r"P_GBA_STYLE_SPECIES_GFX\s*\?\s*(\d+)\s*:\s*(\d+)", expr)
    if ternary:
        return [int(ternary.group(1)), int(ternary.group(2))]

    return None


def max_offset_change(current_expr: str, replacement_expr: str) -> int | None:
    current = extract_numbers_from_offset_expr(current_expr)
    replacement = extract_numbers_from_offset_expr(replacement_expr)
    if current is None or replacement is None or len(current) != len(replacement):
        return None
    return max(abs(a - b) for a, b in zip(current, replacement))


def paeth(a: int, b: int, c: int) -> int:
    p = a + b - c
    pa = abs(p - a)
    pb = abs(p - b)
    pc = abs(p - c)
    if pa <= pb and pa <= pc:
        return a
    if pb <= pc:
        return b
    return c


def unpack_bits(row: bytes, bit_depth: int, width: int) -> bytes:
    if bit_depth == 8:
        return row[:width]

    mask = (1 << bit_depth) - 1
    out = bytearray()
    per_byte = 8 // bit_depth
    for byte in row:
        for shift in range(8 - bit_depth, -1, -bit_depth):
            out.append((byte >> shift) & mask)
            if len(out) == width:
                return bytes(out)
    return bytes(out)


def read_png_indices_or_alpha(path: pathlib.Path) -> tuple[int, int, list[list[int | tuple[int, int, int, int]]]]:
    data = path.read_bytes()
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        raise ValueError("not a PNG")

    offset = 8
    width = height = bit_depth = color_type = interlace = None
    trns = b""
    idat = bytearray()

    while offset < len(data):
        if offset + 8 > len(data):
            raise ValueError("truncated PNG chunk")
        length = struct.unpack(">I", data[offset:offset + 4])[0]
        chunk_type = data[offset + 4:offset + 8]
        chunk_data = data[offset + 8:offset + 8 + length]
        offset += 12 + length

        if chunk_type == b"IHDR":
            width, height, bit_depth, color_type, _compression, _filter, interlace = struct.unpack(">IIBBBBB", chunk_data)
        elif chunk_type == b"tRNS":
            trns = chunk_data
        elif chunk_type == b"IDAT":
            idat.extend(chunk_data)
        elif chunk_type == b"IEND":
            break

    if width is None or height is None or bit_depth is None or color_type is None or interlace is None:
        raise ValueError("missing IHDR")
    if interlace != 0:
        raise ValueError("interlaced PNGs are not supported")
    if color_type not in (3, 6):
        raise ValueError(f"unsupported PNG color type {color_type}; expected indexed or RGBA")

    if color_type == 3:
        bits_per_pixel = bit_depth
        bytes_per_pixel = 1
        scanline_len = (width * bit_depth + 7) // 8
    else:
        if bit_depth != 8:
            raise ValueError("only 8-bit RGBA PNGs are supported")
        bits_per_pixel = 32
        bytes_per_pixel = 4
        scanline_len = width * 4

    raw = zlib.decompress(bytes(idat))
    rows: list[list[int | tuple[int, int, int, int]]] = []
    prev = bytearray(scanline_len)
    pos = 0

    for _y in range(height):
        filter_type = raw[pos]
        pos += 1
        row = bytearray(raw[pos:pos + scanline_len])
        pos += scanline_len

        recon = bytearray(scanline_len)
        for i, value in enumerate(row):
            left = recon[i - bytes_per_pixel] if i >= bytes_per_pixel else 0
            up = prev[i]
            up_left = prev[i - bytes_per_pixel] if i >= bytes_per_pixel else 0
            if filter_type == 0:
                recon[i] = value
            elif filter_type == 1:
                recon[i] = (value + left) & 0xFF
            elif filter_type == 2:
                recon[i] = (value + up) & 0xFF
            elif filter_type == 3:
                recon[i] = (value + ((left + up) // 2)) & 0xFF
            elif filter_type == 4:
                recon[i] = (value + paeth(left, up, up_left)) & 0xFF
            else:
                raise ValueError(f"unsupported PNG filter {filter_type}")

        prev = recon

        if color_type == 3:
            rows.append(list(unpack_bits(bytes(recon), bit_depth, width)))
        else:
            rgba = []
            for x in range(0, len(recon), 4):
                rgba.append(tuple(recon[x:x + 4]))  # type: ignore[arg-type]
            rows.append(rgba)

    return width, height, rows


def is_visible_pixel(pixel: int | tuple[int, int, int, int], transparent_index: int) -> bool:
    if isinstance(pixel, tuple):
        return pixel[3] != 0
    return pixel != transparent_index


def calculate_y_offset(path: pathlib.Path, transparent_index: int) -> tuple[int, int, int, int]:
    width, height, rows = read_png_indices_or_alpha(path)
    min_x = width
    min_y = height
    max_x = -1
    max_y = -1

    for y, row in enumerate(rows):
        for x, pixel in enumerate(row):
            if is_visible_pixel(pixel, transparent_index):
                min_x = min(min_x, x)
                min_y = min(min_y, y)
                max_x = max(max_x, x)
                max_y = max(max_y, y)

    if max_y < 0:
        raise ValueError("no visible pixels found")

    y_offset = (height - 1) - max_y
    drawn_width = max_x - min_x + 1
    drawn_height = max_y - min_y + 1
    return y_offset, drawn_width, drawn_height, max_y


def incbin_path_to_png(path_str: str) -> pathlib.Path:
    for suffix in (".4bpp.smol", ".4bpp.lz", ".4bpp", ".lz"):
        if path_str.endswith(suffix):
            return pathlib.Path(path_str[: -len(suffix)] + ".png")
    return pathlib.Path(path_str)


def load_back_pic_assets(repo: pathlib.Path) -> dict[str, list[BackPicAsset]]:
    header = repo / GRAPHICS_HEADER
    text = header.read_text()
    pattern = re.compile(
        r"const\s+u32\s+(gMonBackPic_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\(\"([^\"]+)\"\);"
    )

    assets: dict[str, list[BackPicAsset]] = {}
    for symbol, incbin_path in pattern.findall(text):
        png_path = incbin_path_to_png(incbin_path)
        assets.setdefault(symbol, []).append(
            BackPicAsset(symbol=symbol, png_path=png_path, is_gba_style="_gba" in png_path.name)
        )
    return assets


def format_offsets_for_symbol(
    repo: pathlib.Path,
    symbol: str,
    current_expr: str,
    assets_by_symbol: dict[str, list[BackPicAsset]],
    transparent_index: int,
    target_style: str,
) -> tuple[str | None, str]:
    assets = assets_by_symbol.get(symbol, [])
    if not assets:
        return None, "no asset mapping found"

    calculated: list[tuple[BackPicAsset, int, int, int, int]] = []
    errors: list[str] = []
    for asset in assets:
        path = repo / asset.png_path
        if not path.exists():
            errors.append(f"{asset.png_path}: missing")
            continue
        try:
            calculated.append((asset, *calculate_y_offset(path, transparent_index)))
        except Exception as exc:  # noqa: BLE001 - report all image issues per file.
            errors.append(f"{asset.png_path}: {exc}")

    if not calculated:
        return None, "; ".join(errors) if errors else "no readable assets"

    normal_values = [item[1] for item in calculated if not item[0].is_gba_style]
    gba_values = [item[1] for item in calculated if item[0].is_gba_style]
    unique_values = sorted({item[1] for item in calculated})

    detail_parts = []
    for asset, y_offset, drawn_width, drawn_height, max_y in calculated:
        style = "gba" if asset.is_gba_style else "normal"
        detail_parts.append(f"{style}:{asset.png_path} y={y_offset} bbox={drawn_width}x{drawn_height} bottom={max_y}")
    if errors:
        detail_parts.extend(errors)

    expr = current_expr.strip()
    ternary = re.fullmatch(r"(P_GBA_STYLE_SPECIES_GFX\s*\?\s*)(\d+)(\s*:\s*)(\d+)", expr)
    if ternary and gba_values and normal_values:
        replacement = f"{ternary.group(1)}{gba_values[0]}{ternary.group(3)}{normal_values[0]}"
        return replacement, "; ".join(detail_parts)
    if ternary and normal_values:
        replacement = f"{ternary.group(1)}{ternary.group(2)}{ternary.group(3)}{normal_values[0]}"
        return replacement, "no GBA back asset found; preserved GBA branch; " + "; ".join(detail_parts)

    if re.fullmatch(r"\d+", expr) and len(unique_values) == 1:
        return str(unique_values[0]), "; ".join(detail_parts)

    if re.fullmatch(r"\d+", expr) and target_style == "normal" and normal_values:
        return str(normal_values[0]), "forced normal style; " + "; ".join(detail_parts)

    if re.fullmatch(r"\d+", expr) and target_style == "gba" and gba_values:
        return str(gba_values[0]), "forced GBA style; " + "; ".join(detail_parts)

    if re.fullmatch(r"\d+", expr) and target_style == "ternary" and normal_values and gba_values:
        return f"P_GBA_STYLE_SPECIES_GFX ? {gba_values[0]} : {normal_values[0]}", "expanded to style ternary; " + "; ".join(detail_parts)

    if re.fullmatch(r"\d+", expr) and len(unique_values) > 1:
        return None, "multiple style-dependent values; " + "; ".join(detail_parts)

    return None, "unsupported offset expression; " + "; ".join(detail_parts)


def find_species_back_offsets(
    repo: pathlib.Path,
    assets_by_symbol: dict[str, list[BackPicAsset]],
    transparent_index: int,
    target_style: str,
) -> list[Finding]:
    findings: list[Finding] = []
    file_pattern = re.compile(r"\.h$")
    entry_pattern = re.compile(
        r"(?P<prefix>\.backPic\s*=\s*(?P<symbol>gMonBackPic_[A-Za-z0-9_]+)\s*,)"
        r"(?P<body>.*?)"
        r"(?P<offset_prefix>\.backPicYOffset\s*=\s*)(?P<expr>[^,\n]+)(?P<suffix>\s*,)",
        re.DOTALL,
    )

    for path in sorted((repo / SPECIES_INFO_DIR).iterdir()):
        if not path.is_file() or not file_pattern.search(path.name):
            continue
        text = path.read_text()
        for match in entry_pattern.finditer(text):
            symbol = match.group("symbol")
            expr = match.group("expr").strip()
            replacement, details = format_offsets_for_symbol(repo, symbol, expr, assets_by_symbol, transparent_index, target_style)
            line = text.count("\n", 0, match.start("expr")) + 1
            findings.append(
                Finding(
                    file=path.relative_to(repo),
                    line=line,
                    expr_start=match.start("expr"),
                    expr_end=match.end("expr"),
                    symbol=symbol,
                    current_expr=expr,
                    replacement_expr=replacement,
                    details=details,
                )
            )
    return findings


def apply_findings(repo: pathlib.Path, findings: list[Finding]) -> int:
    by_file: dict[pathlib.Path, list[Finding]] = {}
    for finding in findings:
        if finding.changed:
            by_file.setdefault(finding.file, []).append(finding)

    changed_files = 0
    for rel_path, file_findings in by_file.items():
        path = repo / rel_path
        text = path.read_text()
        original = text
        for finding in sorted(file_findings, key=lambda item: item.expr_start, reverse=True):
            current_slice = text[finding.expr_start:finding.expr_end]
            if current_slice.strip() != finding.current_expr:
                print(
                    f"warning: refusing stale/non-exact replacement in {rel_path}:{finding.line}: "
                    f"expected {finding.current_expr!r}, found {current_slice.strip()!r}",
                    file=sys.stderr,
                )
                continue
            text = text[:finding.expr_start] + str(finding.replacement_expr) + text[finding.expr_end:]
        if text != original:
            path.write_text(text)
            changed_files += 1
    return changed_files


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("repo", type=pathlib.Path, help="path to the repository root")
    parser.add_argument("--write", action="store_true", help="update species_info files in place")
    parser.add_argument("--all", action="store_true", help="print unchanged entries too")
    parser.add_argument("--only", help="only report entries whose file path or backPic symbol contains this text")
    parser.add_argument("--summary-only", action="store_true", help="print only the final summary")
    parser.add_argument("--max-change", type=int, help="skip writes/reports where any numeric offset branch changes by more than this")
    parser.add_argument(
        "--target-style",
        choices=("auto", "normal", "gba", "ternary"),
        default="auto",
        help=(
            "how to handle a single numeric offset when both normal and GBA back sprites exist. "
            "auto skips ambiguous values; normal/gba force that style; ternary expands the value."
        ),
    )
    parser.add_argument("--transparent-index", type=int, default=0, help="palette index treated as transparent for indexed PNGs")
    args = parser.parse_args()

    repo = args.repo.resolve()
    if not (repo / GRAPHICS_HEADER).exists() or not (repo / SPECIES_INFO_DIR).is_dir():
        print(f"error: {repo} does not look like this project root", file=sys.stderr)
        return 2

    assets_by_symbol = load_back_pic_assets(repo)
    findings = find_species_back_offsets(repo, assets_by_symbol, args.transparent_index, args.target_style)
    if args.only:
        needle = args.only.lower()
        findings = [
            finding for finding in findings
            if needle in str(finding.file).lower() or needle in finding.symbol.lower()
        ]
    if args.max_change is not None:
        filtered: list[Finding] = []
        for finding in findings:
            if finding.replacement_expr is None:
                filtered.append(finding)
                continue
            max_change = max_offset_change(finding.current_expr, finding.replacement_expr)
            if max_change is not None and max_change > args.max_change:
                finding.replacement_expr = None
                finding.details = f"change exceeds --max-change {args.max_change}; " + finding.details
            filtered.append(finding)
        findings = filtered
    changed = [finding for finding in findings if finding.changed]
    blocked = [finding for finding in findings if finding.replacement_expr is None]

    if not args.summary_only:
        for finding in findings:
            if not args.all and not finding.changed and finding.replacement_expr is not None:
                continue
            status = "CHANGE" if finding.changed else "SKIP" if finding.replacement_expr is None else "OK"
            target = finding.replacement_expr if finding.replacement_expr is not None else "n/a"
            print(
                f"{status} {finding.file}:{finding.line} {finding.symbol} "
                f"{finding.current_expr} -> {target} | {finding.details}"
            )

    print(
        f"\nScanned {len(findings)} backPicYOffset entries. "
        f"{len(changed)} would change. {len(blocked)} need manual review/unsupported expressions."
    )

    if args.write:
        changed_files = apply_findings(repo, findings)
        print(f"Wrote changes to {changed_files} file(s).")
    else:
        print("Dry run only. Re-run with --write to update files.")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())

// Copyright(c) 2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstdio>
#include <cstdarg>
#include <stdexcept>
#include <string>
#include <memory>
#include <cstring>
#include <cerrno>
#include <cstdlib>
#include <vector>
#include "preproc.h"
#include "c_file.h"
#include "char_util.h"
#include "utf8.h"
#include "string_parser.h"
#include "io.h"

static int ConvertPreprocDigit(char c, int radix)
{
    int digit;

    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'A' && c <= 'F')
        digit = 10 + c - 'A';
    else if (c >= 'a' && c <= 'f')
        digit = 10 + c - 'a';
    else
        return -1;

    return (digit < radix) ? digit : -1;
}

static std::vector<unsigned char> ReadGlyphWidths(const char *name)
{
    FILE *fp = std::fopen("src/fonts.c", "rb");
    std::vector<unsigned char> widths;

    if (fp == NULL)
        return widths;

    std::fseek(fp, 0, SEEK_END);
    long size = std::ftell(fp);
    std::rewind(fp);

    std::string buffer(size, 0);

    if (std::fread(&buffer[0], size, 1, fp) != 1)
    {
        std::fclose(fp);
        return widths;
    }

    std::fclose(fp);

    size_t pos = buffer.find(name);
    if (pos == std::string::npos)
        return widths;

    pos = buffer.find('{', pos);
    if (pos == std::string::npos)
        return widths;

    while (++pos < buffer.size() && buffer[pos] != '}')
    {
        if (IsAsciiDigit(buffer[pos]))
        {
            char *end;
            unsigned long value = std::strtoul(&buffer[pos], &end, 10);
            widths.push_back((unsigned char)value);
            pos = end - &buffer[0];
        }
    }

    return widths;
}

static const std::vector<unsigned char>& GetGlyphWidthsForFont(int fontId)
{
    static const std::vector<unsigned char> smallNarrow = ReadGlyphWidths("gFontSmallNarrowLatinGlyphWidths");
    static const std::vector<unsigned char> small = ReadGlyphWidths("gFontSmallLatinGlyphWidths");
    static const std::vector<unsigned char> narrow = ReadGlyphWidths("gFontNarrowLatinGlyphWidths");
    static const std::vector<unsigned char> shortFont = ReadGlyphWidths("gFontShortLatinGlyphWidths");
    static const std::vector<unsigned char> normal = ReadGlyphWidths("gFontNormalLatinGlyphWidths");
    static const std::vector<unsigned char> narrower = ReadGlyphWidths("gFontNarrowerLatinGlyphWidths");
    static const std::vector<unsigned char> smallNarrower = ReadGlyphWidths("gFontSmallNarrowerLatinGlyphWidths");
    static const std::vector<unsigned char> shortNarrow = ReadGlyphWidths("gFontShortNarrowLatinGlyphWidths");
    static const std::vector<unsigned char> shortNarrower = ReadGlyphWidths("gFontShortNarrowerLatinGlyphWidths");
    static const std::vector<unsigned char> empty;

    switch (fontId)
    {
    case 0:
        return small;
    case 1:
        return normal;
    case 2:
    case 3:
    case 4:
    case 5:
        return shortFont;
    case 7:
        return narrow;
    case 8:
        return smallNarrow;
    case 10:
        return narrower;
    case 11:
        return smallNarrower;
    case 12:
        return shortNarrow;
    case 13:
        return shortNarrower;
    default:
        return empty;
    }
}

static int GetPreprocGlyphWidth(int fontId, unsigned char c)
{
    if (fontId < 0 || fontId >= 14)
        return 0;

    if (c == 0xFE || c == 0xFF)
        return 0;
    if (c == 0x00)
        return 3;

    const std::vector<unsigned char>& widths = GetGlyphWidthsForFont(fontId);
    if (c < widths.size())
        return widths[c];

    if (fontId == 6 || fontId == 9)
        return 8;

    switch (fontId)
    {
    case 0:  // FONT_SMALL
    case 8:  // FONT_SMALL_NARROW
    case 11: // FONT_SMALL_NARROWER
        return 5;
    case 7:  // FONT_NARROW
    case 10: // FONT_NARROWER
        return 5;
    default:
        return 6;
    }
}

static int GetStringWidthForFont(const std::vector<unsigned char>& text, int fontId, int start, int end)
{
    int width = 0;

    for (int i = start; i < end; i++)
    {
        if (text[i] == 0xFE)
            break;
        width += GetPreprocGlyphWidth(fontId, text[i]);
    }

    return width;
}

CFile::CFile(const char * filenameCStr, bool isStdin)
{
    if (isStdin)
        m_filename = std::string{"<stdin>/"}.append(filenameCStr);
    else
        m_filename = std::string(filenameCStr);

    m_buffer = ReadFileToBuffer(filenameCStr, isStdin, &m_size);

    m_pos = 0;
    m_lineNum = 1;
    m_isStdin = isStdin;
}

CFile::CFile(CFile&& other) : m_filename(std::move(other.m_filename))
{
    m_buffer = other.m_buffer;
    m_pos = other.m_pos;
    m_size = other.m_size;
    m_lineNum = other.m_lineNum;
    m_isStdin = other.m_isStdin;

    other.m_buffer = NULL;
}

CFile::~CFile()
{
    free(m_buffer);
}

void CFile::Preproc()
{
    char stringChar = 0;

    while (m_pos < m_size)
    {
        if (stringChar)
        {
            if (m_buffer[m_pos] == stringChar)
            {
                std::putchar(stringChar);
                m_pos++;
                stringChar = 0;
            }
            else if (m_buffer[m_pos] == '\\' && m_buffer[m_pos + 1] == stringChar)
            {
                std::putchar('\\');
                std::putchar(stringChar);
                m_pos += 2;
            }
            else
            {
                if (m_buffer[m_pos] == '\n')
                    m_lineNum++;
                std::putchar(m_buffer[m_pos]);
                m_pos++;
            }
        }
        else
        {
            TryConvertString();
            TryConvertIncbin();

            if (m_pos >= m_size)
                break;

            char c = m_buffer[m_pos++];

            std::putchar(c);

            if (c == '\n')
                m_lineNum++;
            else if (c == '"')
                stringChar = '"';
            else if (c == '\'')
                stringChar = '\'';
        }
    }
}

bool CFile::ConsumeHorizontalWhitespace()
{
    if (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
    {
        m_pos++;
        return true;
    }

    return false;
}

bool CFile::ConsumeNewline()
{
    if (m_buffer[m_pos] == '\r' && m_buffer[m_pos + 1] == '\n')
    {
        m_pos += 2;
        m_lineNum++;
        std::putchar('\n');
        return true;
    }

    if (m_buffer[m_pos] == '\n')
    {
        m_pos++;
        m_lineNum++;
        std::putchar('\n');
        return true;
    }

    return false;
}

void CFile::SkipWhitespace()
{
    while (ConsumeHorizontalWhitespace() || ConsumeNewline())
        ;
}

void CFile::TryConvertString()
{
    if (TryConvertFormattedString())
        return;

    TryConvertPlainString();
}

bool CFile::TryConvertPlainString()
{
    long oldPos = m_pos;
    long oldLineNum = m_lineNum;
    bool noTerminator = false;

    if (m_buffer[m_pos] != '_' || (m_pos > 0 && IsIdentifierChar(m_buffer[m_pos - 1])))
        return false;

    m_pos++;

    if (m_buffer[m_pos] == '_')
    {
        noTerminator = true;
        m_pos++;
    }

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_lineNum = oldLineNum;
        return false;
    }

    m_pos++;

    SkipWhitespace();

    std::printf("{ ");

    while (1)
    {
        SkipWhitespace();

        if (m_buffer[m_pos] == '"')
        {
            unsigned char s[kMaxStringLength];
            int length;
            StringParser stringParser(m_buffer, m_size);

            try
            {
                m_pos += stringParser.ParseString(m_pos, s, length);
            }
            catch (std::runtime_error& e)
            {
                RaiseError(e.what());
            }

            for (int i = 0; i < length; i++)
                printf("0x%02X, ", s[i]);
        }
        else if (m_buffer[m_pos] == ')')
        {
            m_pos++;
            break;
        }
        else
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF");
            if (IsAsciiPrintable(m_buffer[m_pos]))
                RaiseError("unexpected character '%c'", m_buffer[m_pos]);
            else
                RaiseError("unexpected character '\\x%02X'", m_buffer[m_pos]);
        }
    }

    if (noTerminator)
        std::printf(" }");
    else
        std::printf("0xFF }");

    return true;
}

bool CFile::TryConvertFormattedString()
{
    long oldPos = m_pos;
    long oldLineNum = m_lineNum;

    if (m_buffer[m_pos] != '_' || m_buffer[m_pos + 1] != 'f' || (m_pos > 0 && IsIdentifierChar(m_buffer[m_pos - 1])))
        return false;

    m_pos += 2;

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_lineNum = oldLineNum;
        return false;
    }

    m_pos++;
    SkipWhitespace();

    int fontId = ReadIntegerArgument();
    ExpectComma();
    int width = ReadIntegerArgument();
    ExpectComma();

    std::vector<unsigned char> text;

    while (1)
    {
        SkipWhitespace();

        if (m_buffer[m_pos] == '"')
        {
            unsigned char s[kMaxStringLength];
            int length;
            StringParser stringParser(m_buffer, m_size);

            try
            {
                m_pos += stringParser.ParseString(m_pos, s, length);
            }
            catch (std::runtime_error& e)
            {
                RaiseError(e.what());
            }

            text.insert(text.end(), s, s + length);
        }
        else if (m_buffer[m_pos] == ')')
        {
            m_pos++;
            break;
        }
        else
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF");
            if (IsAsciiPrintable(m_buffer[m_pos]))
                RaiseError("unexpected character '%c'", m_buffer[m_pos]);
            else
                RaiseError("unexpected character '\\x%02X'", m_buffer[m_pos]);
        }
    }

    FormatString(text, fontId, width);
    std::printf("{ ");
    PrintStringBytes(text.data(), text.size());
    std::printf("0xFF }");

    return true;
}

int CFile::ReadIntegerArgument()
{
    int value = 0;

    SkipWhitespace();

    if (IsIdentifierStartingChar(m_buffer[m_pos]))
    {
        long startPos = m_pos;

        m_pos++;

        while (IsIdentifierChar(m_buffer[m_pos]))
            m_pos++;

        std::string ident(&m_buffer[startPos], m_pos - startPos);

        if (ident == "FONT_SMALL")
            return 0;
        if (ident == "FONT_NORMAL")
            return 1;
        if (ident == "FONT_SHORT")
            return 2;
        if (ident == "FONT_SHORT_COPY_1")
            return 3;
        if (ident == "FONT_SHORT_COPY_2")
            return 4;
        if (ident == "FONT_SHORT_COPY_3")
            return 5;
        if (ident == "FONT_BRAILLE")
            return 6;
        if (ident == "FONT_NARROW")
            return 7;
        if (ident == "FONT_SMALL_NARROW")
            return 8;
        if (ident == "FONT_BOLD")
            return 9;
        if (ident == "FONT_NARROWER")
            return 10;
        if (ident == "FONT_SMALL_NARROWER")
            return 11;
        if (ident == "FONT_SHORT_NARROW")
            return 12;
        if (ident == "FONT_SHORT_NARROWER")
            return 13;
        if (ident == "ABILITY_DESCRIPTION_FONT")
            return 1;
        if (ident == "ABILITY_DESCRIPTION_WIDTH")
            return 104;

        RaiseError("unknown integer argument '%s'", ident.c_str());
    }

    if (!IsAsciiDigit(m_buffer[m_pos]))
        RaiseError("expected integer argument");

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        m_pos += 2;
        while (ConvertPreprocDigit(m_buffer[m_pos], 16) != -1)
        {
            int digit = ConvertPreprocDigit(m_buffer[m_pos], 16);
            value = (value * 16) + digit;
            m_pos++;
        }

        SkipWhitespace();
        return value;
    }

    while (IsAsciiDigit(m_buffer[m_pos]))
    {
        value = (value * 10) + (m_buffer[m_pos] - '0');
        m_pos++;
    }

    SkipWhitespace();
    return value;
}

void CFile::ExpectComma()
{
    SkipWhitespace();

    if (m_buffer[m_pos] != ',')
        RaiseError("expected comma");

    m_pos++;
}

void CFile::PrintStringBytes(const unsigned char *s, int length)
{
    for (int i = 0; i < length; i++)
        printf("0x%02X, ", s[i]);
}

void CFile::FormatString(std::vector<unsigned char>& text, int fontId, int width)
{
    int lineStart = 0;
    int lastSpace = -1;

    for (int i = 0; i < (int)text.size(); i++)
    {
        if (text[i] == 0xFE)
        {
            lineStart = i + 1;
            lastSpace = -1;
            continue;
        }

        if (text[i] == 0x00)
            lastSpace = i;

        if (GetStringWidthForFont(text, fontId, lineStart, i + 1) > width && lastSpace >= lineStart)
        {
            text[lastSpace] = 0xFE;
            lineStart = lastSpace + 1;
            lastSpace = -1;

            for (int j = lineStart; j <= i; j++)
            {
                if (text[j] == 0x00)
                    lastSpace = j;
            }
        }
    }
}

bool CFile::CheckIdentifier(const std::string& ident)
{
    unsigned int i;

    for (i = 0; i < ident.length() && m_pos + i < (unsigned)m_size; i++)
        if (ident[i] != m_buffer[m_pos + i])
            return false;

    return (i == ident.length());
}

std::unique_ptr<unsigned char[]> CFile::ReadWholeFile(const std::string& path, int& size)
{
    FILE* fp = std::fopen(path.c_str(), "rb");

    if (fp == nullptr)
        RaiseError("Failed to open \"%s\" for reading.\n", path.c_str());

    std::fseek(fp, 0, SEEK_END);

    size = std::ftell(fp);

    std::unique_ptr<unsigned char[]> buffer = std::unique_ptr<unsigned char[]>(new unsigned char[size]);

    std::rewind(fp);

    if (std::fread(buffer.get(), size, 1, fp) != 1)
        RaiseError("Failed to read \"%s\".\n", path.c_str());

    std::fclose(fp);

    return buffer;
}

int ExtractData(const std::unique_ptr<unsigned char[]>& buffer, int offset, int size)
{
    switch (size)
    {
    case 1:
        return buffer[offset];
    case 2:
        return (buffer[offset + 1] << 8)
            | buffer[offset];
    case 4:
        return (buffer[offset + 3] << 24)
            | (buffer[offset + 2] << 16)
            | (buffer[offset + 1] << 8)
            | buffer[offset];
    default:
        FATAL_ERROR("Invalid size passed to ExtractData.\n");
    }
}

void CFile::TryConvertIncbin()
{
    std::string idents[8] = { "INCBIN_S8", "INCBIN_U8", "INCBIN_S16", "INCBIN_U16", "INCBIN_S32", "INCBIN_U32", "DUMMY", "INCBIN_COMP"};
    int incbinType = -1;

    for (int i = 0; i < 8; i++)
    {
        if (CheckIdentifier(idents[i]))
        {
            incbinType = i;
            break;
        }
    }

    if (incbinType == -1)
        return;

    int size = 1 << (incbinType / 2);
    if (size > 4)
        size = 4;
    bool isSigned = ((incbinType % 2) == 0);

    long oldPos = m_pos;
    long oldLineNum = m_lineNum;

    m_pos += idents[incbinType].length();

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_lineNum = oldLineNum;
        return;
    }

    m_pos++;

    std::printf("{");

    while (true)
    {
        SkipWhitespace();

        if (m_buffer[m_pos] != '"')
            RaiseError("expected double quote");

        m_pos++;

        int startPos = m_pos;

        while (m_buffer[m_pos] != '"')
        {
            if (m_buffer[m_pos] == 0)
            {
                if (m_pos >= m_size)
                    RaiseError("unexpected EOF in path string");
                else
                    RaiseError("unexpected null character in path string");
            }

            if (m_buffer[m_pos] == '\r' || m_buffer[m_pos] == '\n')
                RaiseError("unexpected end of line character in path string");

            if (m_buffer[m_pos] == '\\')
                RaiseError("unexpected escape in path string");

            m_pos++;
        }

        std::string path(&m_buffer[startPos], m_pos - startPos);

        // INCBIN_COMP; include *compressed* version of file
        if (incbinType == 7)
            path = path.append(".smol");

        m_pos++;

        int fileSize;
        std::unique_ptr<unsigned char[]> buffer = ReadWholeFile(path, fileSize);

        if ((fileSize % size) != 0)
            RaiseError("Size %d doesn't evenly divide file size %d.\n", size, fileSize);

        int count = fileSize / size;
        int offset = 0;

        for (int i = 0; i < count; i++)
        {
            int data = ExtractData(buffer, offset, size);
            offset += size;

            if (isSigned)
                std::printf("%d,", data);
            else
                std::printf("%uu,", data);
        }

        SkipWhitespace();

        if (m_buffer[m_pos] != ',')
            break;

        m_pos++;
    }

    if (m_buffer[m_pos] != ')')
        RaiseError("expected ')'");

    m_pos++;

    std::printf("}");
}

// Reports a diagnostic message.
void CFile::ReportDiagnostic(const char* type, const char* format, std::va_list args)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    std::vsnprintf(buffer, bufferSize, format, args);
    std::fprintf(stderr, "%s:%ld: %s: %s\n", m_filename.c_str(), m_lineNum, type, buffer);
}

#define DO_REPORT(type)                   \
do                                        \
{                                         \
    std::va_list args;                    \
    va_start(args, format);               \
    ReportDiagnostic(type, format, args); \
    va_end(args);                         \
} while (0)

// Reports an error diagnostic and terminates the program.
void CFile::RaiseError(const char* format, ...)
{
    DO_REPORT("error");
    std::exit(1);
}

// Reports a warning diagnostic.
void CFile::RaiseWarning(const char* format, ...)
{
    DO_REPORT("warning");
}

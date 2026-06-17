#define ABILITY_DESCRIPTION_WIDTH 144
#define FORMAT_ABILITY_DESCRIPTION(str) (const u8[]) _f(FONT_SMALL_NARROWER, ABILITY_DESCRIPTION_WIDTH, str)

const u8 sText_InnateLockedUntilLevel_SwSh[] = _f(FONT_SMALL_NARROWER, ABILITY_DESCRIPTION_WIDTH, "This POKéMON innate is currently locked until level {STR_VAR_1}.");

const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = FORMAT_ABILITY_DESCRIPTION("No special ability."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("Stench"),
        .description = FORMAT_ABILITY_DESCRIPTION("May cause a foe to flinch."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Drizzle"),
        .description = FORMAT_ABILITY_DESCRIPTION("Summons rain in battle."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Speed Boost"),
        .description = FORMAT_ABILITY_DESCRIPTION("Gradually boosts Speed."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Battle Armor"),
        .description = FORMAT_ABILITY_DESCRIPTION("Blocks critical hits."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Sturdy"),
        .description = FORMAT_ABILITY_DESCRIPTION("Negates 1-hit KO attacks."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Damp"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents self-destruction."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Limber"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents paralysis."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Sand Veil"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups evasion in a sandstorm."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Static"),
        .description = FORMAT_ABILITY_DESCRIPTION("Paralyzes on contact."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Volt Absorb"),
        .description = FORMAT_ABILITY_DESCRIPTION("Turns electricity into HP."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Water Absorb"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes water into HP."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Oblivious"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents attraction."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Cloud Nine"),
        .description = FORMAT_ABILITY_DESCRIPTION("Negates weather effects."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("Compound Eyes"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises accuracy."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnia"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents sleep."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Color Change"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes type to foe's move."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Immunity"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents poisoning."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Flash Fire"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up if hit by fire."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Shield Dust"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents added effects."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Own Tempo"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents confusion."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Suction Cups"),
        .description = FORMAT_ABILITY_DESCRIPTION("Firmly anchors the body."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers the foe's Attack."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Shadow Tag"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents the foe's escape."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Rough Skin"),
        .description = FORMAT_ABILITY_DESCRIPTION("Hurts to touch."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Wonder Guard"),
        .description = FORMAT_ABILITY_DESCRIPTION("Only “Supereffective” hits."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Levitate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Not hit by Ground attacks."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EELEVATE] =
    {
        .name = _("Eelevate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Not hit by Ground attacks and KOs boost best stat."),
        .aiRating = 10,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Effect Spore"),
        .description = FORMAT_ABILITY_DESCRIPTION("Leaves spores on contact."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Synchronize"),
        .description = FORMAT_ABILITY_DESCRIPTION("Passes on status problems."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Clear Body"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents ability reduction."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Natural Cure"),
        .description = FORMAT_ABILITY_DESCRIPTION("Heals upon switching out."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("Lightning Rod"),
        .description = FORMAT_ABILITY_DESCRIPTION("Draws electrical moves."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Serene Grace"),
        .description = FORMAT_ABILITY_DESCRIPTION("Promotes added effects."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Swift Swim"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Speed in rain."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Chlorophyll"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Speed in sunshine."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Illuminate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Increases accuracy."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Trace"),
        .description = FORMAT_ABILITY_DESCRIPTION("Copies special ability."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Huge Power"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Attack."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Poison Point"),
        .description = FORMAT_ABILITY_DESCRIPTION("Poisons foe on contact."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("Inner Focus"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents flinching."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Magma Armor"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents freezing."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Water Veil"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents burns."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("Magnet Pull"),
        .description = FORMAT_ABILITY_DESCRIPTION("Traps Steel-type Pokémon."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Soundproof"),
        .description = FORMAT_ABILITY_DESCRIPTION("Avoids sound-based moves."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Rain Dish"),
        .description = FORMAT_ABILITY_DESCRIPTION("Slight HP recovery in rain."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Sand Stream"),
        .description = FORMAT_ABILITY_DESCRIPTION("Summons a sandstorm."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Pressure"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises foe's PP usage."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Thick Fat"),
        .description = FORMAT_ABILITY_DESCRIPTION("Heat-and-cold protection."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Early Bird"),
        .description = FORMAT_ABILITY_DESCRIPTION("Awakens quickly from sleep."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Flame Body"),
        .description = FORMAT_ABILITY_DESCRIPTION("Burns the foe on contact."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Run Away"),
        .description = FORMAT_ABILITY_DESCRIPTION("Makes escaping easier."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Keen Eye"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents loss of accuracy."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Hyper Cutter"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents Attack reduction."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Pickup"),
        .description = FORMAT_ABILITY_DESCRIPTION("May pick up items."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Truant"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moves only every two turns."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Hustle"),
        .description = FORMAT_ABILITY_DESCRIPTION("Trades accuracy for power."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Cute Charm"),
        .description = FORMAT_ABILITY_DESCRIPTION("Infatuates on contact, reduces damage."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up with Minus."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Minus"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up with Plus."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Forecast"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes with the weather."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Sticky Hold"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents item theft."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Shed Skin"),
        .description = FORMAT_ABILITY_DESCRIPTION("Heals the body by shedding."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Guts"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Attack if suffering."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Marvel Scale"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Defense if suffering."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Liquid Ooze"),
        .description = FORMAT_ABILITY_DESCRIPTION("Draining causes injury."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Overgrow"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Grass moves in a pinch."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Blaze"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Fire moves in a pinch."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Torrent"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Water moves in a pinch."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Swarm"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Bug moves in a pinch."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Rock Head"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents recoil damage."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Drought"),
        .description = FORMAT_ABILITY_DESCRIPTION("Summons sunlight in battle."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Arena Trap"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents fleeing."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Vital Spirit"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents sleep."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("White Smoke"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents ability reduction."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Pure Power"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Attack."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Shell Armor"),
        .description = FORMAT_ABILITY_DESCRIPTION("Blocks critical hits."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Air Lock"),
        .description = FORMAT_ABILITY_DESCRIPTION("Negates weather effects."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Tangled Feet"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups evasion if confused."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motor Drive"),
        .description = FORMAT_ABILITY_DESCRIPTION("Electricity raises Speed."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalry"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up against rivals."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Steadfast"),
        .description = FORMAT_ABILITY_DESCRIPTION("Flinching raises Speed."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Snow Cloak"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups evasion in Hail or Snow."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gluttony"),
        .description = FORMAT_ABILITY_DESCRIPTION("Eats Berries early."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Anger Point"),
        .description = FORMAT_ABILITY_DESCRIPTION("Critical hits raise Attack."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Unburden"),
        .description = FORMAT_ABILITY_DESCRIPTION("Using a hold item ups Speed."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Heatproof"),
        .description = FORMAT_ABILITY_DESCRIPTION("Heat and burn protection."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simple"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prone to wild stat changes."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Dry Skin"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prefers moisture to heat."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Download"),
        .description = FORMAT_ABILITY_DESCRIPTION("Adjusts power favorably."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Iron Fist"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts punching moves."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Poison Heal"),
        .description = FORMAT_ABILITY_DESCRIPTION("Restores HP if poisoned."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Adaptability"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts same type attacks."),
        .aiRating = 8,
    },

    [ABILITY_FUSION_POWER] =
    {
        .name = _("Fusion Power"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts same type attacks."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Skill Link"),
        .description = FORMAT_ABILITY_DESCRIPTION("Multi-hit moves hit 5 times."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hydration"),
        .description = FORMAT_ABILITY_DESCRIPTION("Cures status in rain."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Solar Power"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up in sunshine."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Quick Feet"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Speed if suffering."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalize"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moves become Normal-type."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Sniper"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts critical hits."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Magic Guard"),
        .description = FORMAT_ABILITY_DESCRIPTION("Only damaged by attacks."),
        .aiRating = 9,
    },

    [ABILITY_IMPENETRABLE] =
    {
        .name = _("Impenetrable"),
        .description = FORMAT_ABILITY_DESCRIPTION("Only damaged by attacks."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("No Guard"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ensures that all moves hit."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("Stall"),
        .description = FORMAT_ABILITY_DESCRIPTION("Always moves last."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Technician"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts weaker moves."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("Leaf Guard"),
        .description = FORMAT_ABILITY_DESCRIPTION("Blocks status in sunshine."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("Klutz"),
        .description = FORMAT_ABILITY_DESCRIPTION("Can't use hold items."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Mold Breaker"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moves hit through abilities."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Super Luck"),
        .description = FORMAT_ABILITY_DESCRIPTION("Critical hits land often."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Aftermath"),
        .description = FORMAT_ABILITY_DESCRIPTION("Fainting damages the foe."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Anticipation"),
        .description = FORMAT_ABILITY_DESCRIPTION("Senses dangerous moves."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Forewarn"),
        .description = FORMAT_ABILITY_DESCRIPTION("Determines a foe's move."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Unaware"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ignores stat changes."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Tinted Lens"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups “not very effective”."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filter"),
        .description = FORMAT_ABILITY_DESCRIPTION("Weakens “supereffective”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("Slow Start"),
        .description = FORMAT_ABILITY_DESCRIPTION("Takes a while to get going."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Scrappy"),
        .description = FORMAT_ABILITY_DESCRIPTION("Hits Ghost-type Pokémon."),
        .aiRating = 6,
    },

    [ABILITY_GENIUS] =
    {
        .name = _("Genius"),
        .description = FORMAT_ABILITY_DESCRIPTION("Psychic hits Dark-type Pokémon."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Storm Drain"),
        .description = FORMAT_ABILITY_DESCRIPTION("Draws in Water moves."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Ice Body"),
        .description = FORMAT_ABILITY_DESCRIPTION("HP recovery in Hail or Snow."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Solid Rock"),
        .description = FORMAT_ABILITY_DESCRIPTION("Weakens “supereffective”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Snow Warning"),
    #if B_SNOW_WARNING >= GEN_9
        .description = FORMAT_ABILITY_DESCRIPTION("Summons snow in battle."),
    #else
        .description = FORMAT_ABILITY_DESCRIPTION("Summons hail in battle."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Honey Gather"),
        .description = FORMAT_ABILITY_DESCRIPTION("May gather Honey."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Frisk"),
        .description = FORMAT_ABILITY_DESCRIPTION("Checks a foe's item."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Reckless"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts moves with recoil."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("Multitype"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes type to its Plate."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("Flower Gift"),
        .description = FORMAT_ABILITY_DESCRIPTION("Allies power up in sunshine."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Bad Dreams"),
        .description = FORMAT_ABILITY_DESCRIPTION("Damages sleeping Pokémon."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Pickpocket"),
        .description = FORMAT_ABILITY_DESCRIPTION("Steals the foe's held item."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Sheer Force"),
        .description = FORMAT_ABILITY_DESCRIPTION("Trades effects for power."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("Contrary"),
        .description = FORMAT_ABILITY_DESCRIPTION("Inverts stat changes."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Unnerve"),
        .description = FORMAT_ABILITY_DESCRIPTION("Foes can't eat Berries."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Defiant"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowered stats up Attack."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("Defeatist"),
        .description = FORMAT_ABILITY_DESCRIPTION("Gives up at half HP."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Cursed Body"),
        .description = FORMAT_ABILITY_DESCRIPTION("Disables moves on contact."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Healer"),
        .description = FORMAT_ABILITY_DESCRIPTION("Heals partner Pokémon."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Friend Guard"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers damage to partner."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Weak Armor"),
        .description = FORMAT_ABILITY_DESCRIPTION("Its stats change when hit."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("Heavy Metal"),
        .description = FORMAT_ABILITY_DESCRIPTION("Doubles weight."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Light Metal"),
        .description = FORMAT_ABILITY_DESCRIPTION("Halves weight."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiscale"),
        .description = FORMAT_ABILITY_DESCRIPTION("Halves damage at full HP."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Toxic Boost"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Attack if poisoned."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Flare Boost"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Sp. Atk if burned."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Harvest"),
        .description = FORMAT_ABILITY_DESCRIPTION("May recycle a used Berry."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("Telepathy"),
        .description = FORMAT_ABILITY_DESCRIPTION("Can't be damaged by an ally."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("Moody"),
        .description = FORMAT_ABILITY_DESCRIPTION("Stats change gradually."),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Overcoat"),
        .description = FORMAT_ABILITY_DESCRIPTION("Blocks weather and powder."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Poison Touch"),
        .description = FORMAT_ABILITY_DESCRIPTION("Poisons foe on contact."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Regenerator"),
        .description = FORMAT_ABILITY_DESCRIPTION("Heals upon switching out."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Big Pecks"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents Defense loss."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Sand Rush"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Speed in a sandstorm."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Wonder Skin"),
        .description = FORMAT_ABILITY_DESCRIPTION("May avoid status problems."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analytic"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moving last boosts power."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("Illusion"),
        .description = FORMAT_ABILITY_DESCRIPTION("Appears as a partner."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Imposter"),
        .description = FORMAT_ABILITY_DESCRIPTION("Transforms into the foe."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("Infiltrator"),
        .description = FORMAT_ABILITY_DESCRIPTION("Passes through barriers."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("Mummy"),
        .description = FORMAT_ABILITY_DESCRIPTION("Spreads with contact."),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Moxie"),
        .description = FORMAT_ABILITY_DESCRIPTION("KOs raise Attack."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Justified"),
        .description = FORMAT_ABILITY_DESCRIPTION("Dark hits raise Attack."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Rattled"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Speed when scared."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Magic Bounce"),
        .description = FORMAT_ABILITY_DESCRIPTION("Reflects status moves."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Sap Sipper"),
        .description = FORMAT_ABILITY_DESCRIPTION("Grass increases Attack."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("Prankster"),
        .description = FORMAT_ABILITY_DESCRIPTION("Status moves go first."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Sand Force"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up in a sandstorm."),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Iron Barbs"),
        .description = FORMAT_ABILITY_DESCRIPTION("Hurts to touch."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("Zen Mode"),
        .description = FORMAT_ABILITY_DESCRIPTION("Transforms at half HP."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("Victory Star"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises party accuracy."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("Turboblaze"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moves hit through abilities."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("Teravolt"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moves hit through abilities."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("Aroma Veil"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents limiting of moves."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("Flower Veil"),
        .description = FORMAT_ABILITY_DESCRIPTION("Protects Grass-types."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("Cheek Pouch"),
        .description = FORMAT_ABILITY_DESCRIPTION("Eating Berries restores HP."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("Protean"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes type to used move."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("Fur Coat"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Defense."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("Magician"),
        .description = FORMAT_ABILITY_DESCRIPTION("Steals the foe's held item."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Bulletproof"),
        .description = FORMAT_ABILITY_DESCRIPTION("Avoids some projectiles."),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Competitive"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowered stats up Sp. Atk."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("Strong Jaw"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts biting moves."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Refrigerate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves become Ice."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("Sweet Veil"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents party from sleep."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("Stance Change"),
        .description = FORMAT_ABILITY_DESCRIPTION("Transforms as it battles."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("Gale Wings"),
        .description = FORMAT_ABILITY_DESCRIPTION("Flying moves go first."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("Mega Launcher"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts pulse moves."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("Grass Pelt"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Defense in grass."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("Symbiosis"),
        .description = FORMAT_ABILITY_DESCRIPTION("Passes its item to an ally."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("Tough Claws"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts contact moves."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Pixilate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves become Fairy."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Gooey"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers Speed on contact."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("Aerilate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves become Flying."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("Parental Bond"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moves hit twice."),
        .aiRating = 10,
    },

    [ABILITY_DOPPLER_EFFECT] =
    {
        .name = _("Doppler Effect"),
        .description = FORMAT_ABILITY_DESCRIPTION("Sound moves hit twice."),
        .aiRating = 10,
    },
    
    [ABILITY_SEED_DISPERSAL] =
    {
        .name = _("Seed Dispersal"),
        .description = FORMAT_ABILITY_DESCRIPTION("Sets Leech Seed on hit."),
        .aiRating = 10,
    },
    
    [ABILITY_HEAT_LIGHTNING] =
    {
        .name = _("Heat Lightning"),
        .description = FORMAT_ABILITY_DESCRIPTION("Electric moves can burn."),
        .aiRating = 10,
    },
    
    [ABILITY_COLD_CURRENT] =
    {
        .name = _("Cold Current"),
        .description = FORMAT_ABILITY_DESCRIPTION("Electric moves can frostbite."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("Dark Aura"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts Dark moves."),
        .aiRating = 6,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("Fairy Aura"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts Fairy moves."),
        .aiRating = 6,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("Aura Break"),
        .description = FORMAT_ABILITY_DESCRIPTION("Reverse aura abilities."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("Primordial Sea"),
        .description = FORMAT_ABILITY_DESCRIPTION("Summons heavy rain."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("Desolate Land"),
        .description = FORMAT_ABILITY_DESCRIPTION("Summons intense sunlight."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("Delta Stream"),
        .description = FORMAT_ABILITY_DESCRIPTION("Summons strong winds."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("Stamina"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts Defense when hit."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("Wimp Out"),
        .description = FORMAT_ABILITY_DESCRIPTION("Flees at half HP."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("Emergency Exit"),
        .description = FORMAT_ABILITY_DESCRIPTION("Flees at half HP."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("Water Compaction"),
        .description = FORMAT_ABILITY_DESCRIPTION("Water boosts Defense."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("Merciless"),
        .description = FORMAT_ABILITY_DESCRIPTION("Criticals poisoned foes."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("Shields Down"),
        .description = FORMAT_ABILITY_DESCRIPTION("Shell breaks at half HP."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("Stakeout"),
        .description = FORMAT_ABILITY_DESCRIPTION("Stronger as foes switch in."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("Water Bubble"),
        .description = FORMAT_ABILITY_DESCRIPTION("Guards from fire and burns."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Steelworker"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up Steel moves."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("Berserk"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts Sp. Atk at low HP."),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Slush Rush"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Speed in Hail/Snow."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Long Reach"),
        .description = FORMAT_ABILITY_DESCRIPTION("Never makes contact."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Liquid Voice"),
        .description = FORMAT_ABILITY_DESCRIPTION("Makes sound moves Water."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Triage"),
        .description = FORMAT_ABILITY_DESCRIPTION("Healing moves go first."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Galvanize"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves turn Electric."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("Surge Surfer"),
        .description = FORMAT_ABILITY_DESCRIPTION("Faster on electricity."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("Schooling"),
        .description = FORMAT_ABILITY_DESCRIPTION("Forms a school when strong."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("Disguise"),
        .description = FORMAT_ABILITY_DESCRIPTION("Decoy protects it once."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("Battle Bond"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes form after a KO."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("Power Construct"),
        .description = FORMAT_ABILITY_DESCRIPTION("Cells aid it when weakened."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("Corrosion"),
        .description = FORMAT_ABILITY_DESCRIPTION("Poisons any type."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("Comatose"),
        .description = FORMAT_ABILITY_DESCRIPTION("Always drowsing."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("Queenly Majesty"),
        .description = FORMAT_ABILITY_DESCRIPTION("Protects from priority."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("Innards Out"),
        .description = FORMAT_ABILITY_DESCRIPTION("Hurts foe when defeated."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("Dancer"),
        .description = FORMAT_ABILITY_DESCRIPTION("Dances along with others."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Battery"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts ally's Sp. Atk."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("Fluffy"),
        .description = FORMAT_ABILITY_DESCRIPTION("Tougher but flammable."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Dazzling"),
        .description = FORMAT_ABILITY_DESCRIPTION("Protects from priority."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Soul-Heart"),
        .description = FORMAT_ABILITY_DESCRIPTION("KOs raise Sp. Atk."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("Tangling Hair"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers Speed on contact."),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receiver"),
        .description = FORMAT_ABILITY_DESCRIPTION("Copies ally's ability."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("Power Of Alchemy"),
        .description = FORMAT_ABILITY_DESCRIPTION("Copies ally's ability."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Beast Boost"),
        .description = FORMAT_ABILITY_DESCRIPTION("KOs boost best stat."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("RKS System"),
        .description = FORMAT_ABILITY_DESCRIPTION("Memories change its type."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("Electric Surge"),
        .description = FORMAT_ABILITY_DESCRIPTION("Field becomes Electric."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("Psychic Surge"),
        .description = FORMAT_ABILITY_DESCRIPTION("Field becomes weird."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("Misty Surge"),
        .description = FORMAT_ABILITY_DESCRIPTION("Field becomes misty."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("Grassy Surge"),
        .description = FORMAT_ABILITY_DESCRIPTION("Field becomes grassy."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("Full Metal Body"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents stat reduction."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("Shadow Shield"),
        .description = FORMAT_ABILITY_DESCRIPTION("Halves damage at full HP."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("Prism Armor"),
        .description = FORMAT_ABILITY_DESCRIPTION("Weakens “supereffective”."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("Neuroforce"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups “supereffective”."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("Intrepid Sword"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Attack on entry."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("Dauntless Shield"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Defense on entry."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("Libero"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes type to move's."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("Ball Fetch"),
        .description = FORMAT_ABILITY_DESCRIPTION("Fetches failed Poké Ball."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Cotton Down"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lower Speed of all when hit."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("Propeller Tail"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ignores foe's redirection."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("Mirror Armor"),
        .description = FORMAT_ABILITY_DESCRIPTION("Reflect stat decreases."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("Gulp Missile"),
        .description = FORMAT_ABILITY_DESCRIPTION("If hit, spits prey from sea."),
        .aiRating = 3,
        .cantBeCopied = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("Stalwart"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ignores foe's redirection."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Steam Engine"),
        .description = FORMAT_ABILITY_DESCRIPTION("Fire or Water hits up Speed."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk Rock"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups and resists sound."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("Sand Spit"),
        .description = FORMAT_ABILITY_DESCRIPTION("Creates a sandstorm if hit."),
        .aiRating = 5,
    },

    [ABILITY_TYPHOON] =
    {
        .name = _("Thyphoon"),
        .description = FORMAT_ABILITY_DESCRIPTION("Creates rain if hit."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Ice Scales"),
        .description = FORMAT_ABILITY_DESCRIPTION("Halves special damage."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("Ripen"),
        .description = FORMAT_ABILITY_DESCRIPTION("Doubles effect of Berries."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("Ice Face"),
        .description = FORMAT_ABILITY_DESCRIPTION("Hail or Snow renew free hit."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("Power Spot"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up ally moves."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("Mimicry"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes type on terrain."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("Screen Cleaner"),
        .description = FORMAT_ABILITY_DESCRIPTION("Removes walls of light."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("Steely Spirit"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts ally's Steel moves."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("Perish Body"),
        .description = FORMAT_ABILITY_DESCRIPTION("Foe faints in 3 turns if hit."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("Wandering Spirit"),
        .description = FORMAT_ABILITY_DESCRIPTION("Trade abilities on contact."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("Gorilla Tactics"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Attack and locks move."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("Neutralizing Gas"),
        .description = FORMAT_ABILITY_DESCRIPTION("All Abilities are nullified."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("Pastel Veil"),
        .description = FORMAT_ABILITY_DESCRIPTION("Protects team from poison."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("Hunger Switch"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes form each turn."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("Quick Draw"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moves first occasionally."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("Unseen Fist"),
        .description = FORMAT_ABILITY_DESCRIPTION("Contact evades protection."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("Curious Medicine"),
        .description = FORMAT_ABILITY_DESCRIPTION("Remove ally's stat changes."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Electric-type moves."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("Dragon's Maw"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Dragon-type moves."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("Chilling Neigh"),
        .description = FORMAT_ABILITY_DESCRIPTION("KOs boost Attack stat."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("Grim Neigh"),
        .description = FORMAT_ABILITY_DESCRIPTION("KOs boost Sp. Atk stat."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("As One"),
        .description = FORMAT_ABILITY_DESCRIPTION("Unnerve and Chilling Neigh."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("As One"),
        .description = FORMAT_ABILITY_DESCRIPTION("Unnerve and Grim Neigh."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("Lingering Aroma"),
        .description = FORMAT_ABILITY_DESCRIPTION("Spreads with contact."),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("Seed Sower"),
        .description = FORMAT_ABILITY_DESCRIPTION("Affects terrain when hit."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("Thermal Exchange"),
        .description = FORMAT_ABILITY_DESCRIPTION("Fire hits up Attack."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("Anger Shell"),
        .description = FORMAT_ABILITY_DESCRIPTION("Gets angry at half HP."),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("Purifying Salt"),
        .description = FORMAT_ABILITY_DESCRIPTION("Protected by pure salts."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("Well-Baked Body"),
        .description = FORMAT_ABILITY_DESCRIPTION("Strengthened by Fire."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Wind Rider"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Attack if hit by wind."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("Guard Dog"),
        .description = FORMAT_ABILITY_DESCRIPTION("Cannot be intimidated."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("Rocky Payload"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up Rock moves."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("Wind Power"),
        .description = FORMAT_ABILITY_DESCRIPTION("Gets charged by wind."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("Zero to Hero"),
        .description = FORMAT_ABILITY_DESCRIPTION("Changes form on switch out."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("Commander"),
        .description = FORMAT_ABILITY_DESCRIPTION("Commands from Dondozo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("Electromorphosis"),
        .description = FORMAT_ABILITY_DESCRIPTION("Gets Charged when hit."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("Protosynthesis"),
        .description = FORMAT_ABILITY_DESCRIPTION("Sun boosts best stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("Quark Drive"),
        .description = FORMAT_ABILITY_DESCRIPTION("Elec. field ups best stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("Good as Gold"),
        .description = FORMAT_ABILITY_DESCRIPTION("Avoids status moves."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("Vessel of Ruin"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers foes' sp. damage."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("Sword of Ruin"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers foes' Defense."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("Tablets of Ruin"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers foes' damage."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("Beads of Ruin"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers foes' Sp. Defense."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("Orichalcum Pulse"),
        .description = FORMAT_ABILITY_DESCRIPTION("Summons sunlight in battle."),
        .aiRating = 8,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("Hadron Engine"),
        .description = FORMAT_ABILITY_DESCRIPTION("Field becomes Electric."),
        .aiRating = 8,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("Opportunist"),
        .description = FORMAT_ABILITY_DESCRIPTION("Copies foe's stat change."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Cud Chew"),
        .description = FORMAT_ABILITY_DESCRIPTION("Eats a used berry again."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Sharpness"),
        .description = FORMAT_ABILITY_DESCRIPTION("Strengthens slicing moves."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("Supreme Overlord"),
        .description = FORMAT_ABILITY_DESCRIPTION("Inherits fallen's strength."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("Costar"),
        .description = FORMAT_ABILITY_DESCRIPTION("Copies ally's stat changes."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("Toxic Debris"),
        .description = FORMAT_ABILITY_DESCRIPTION("Throws poison spikes if hit."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("Armor Tail"),
        .description = FORMAT_ABILITY_DESCRIPTION("Protects from priority."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("Earth Eater"),
        .description = FORMAT_ABILITY_DESCRIPTION("Eats ground to heal HP."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("Mycelium Might"),
        .description = FORMAT_ABILITY_DESCRIPTION("Status moves never fail."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("Hospitality"),
        .description = FORMAT_ABILITY_DESCRIPTION("Restores ally's HP."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("Mind's Eye"),
        .description = FORMAT_ABILITY_DESCRIPTION("Keen Eye and Scrappy."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("Embody Aspect"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Speed."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("Embody Aspect"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Attack."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("Embody Aspect"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Sp. Def."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("Embody Aspect"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Defense."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("Toxic Chain"),
        .description = FORMAT_ABILITY_DESCRIPTION("Moves can poison."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("Supersweet Syrup"),
        .description = FORMAT_ABILITY_DESCRIPTION("Lowers the foe's Evasion."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("Tera Shift"),
        .description = FORMAT_ABILITY_DESCRIPTION("Terastallizes upon entry."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("Tera Shell"),
        .description = FORMAT_ABILITY_DESCRIPTION("Resists all at full HP."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("Teraform Zero"),
        .description = FORMAT_ABILITY_DESCRIPTION("Zeroes weather and terrain."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("Poison Puppeteer"),
        .description = FORMAT_ABILITY_DESCRIPTION("Confuses poisoned foes."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
	
	[ABILITY_FOSSILIZE] =
    {
        .name = _("Fossilize"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves become Rock."),
        .aiRating = 8,
    },

    [ABILITY_GRAVITY_WELL] =
    {
        .name = _("Gravity Well"),
        .description = FORMAT_ABILITY_DESCRIPTION("Intensifies gravity."),
        .aiRating = 7,
    },

    [ABILITY_COUNTERPROOF] =
    {
        .name = _("Counterproof"),
        .description = FORMAT_ABILITY_DESCRIPTION("Not hit by Fighting attacks."),
        .aiRating = 9,
    },

    [ABILITY_EMANATE] =
    {
        .name = _("Emanate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves become Psychic."),
        .aiRating = 7,
    },

    [ABILITY_SNOW_SPEW] =
    {
        .name = _("Snow Spew"),
        .description = FORMAT_ABILITY_DESCRIPTION("Creates a snowstorm if hit."),
        .aiRating = 7,
    },

    [ABILITY_SCARE] =
    {
        .name = _("Scare"),
        .description = FORMAT_ABILITY_DESCRIPTION("Cuts foe's Special Attack."),
        .aiRating = 6,
    },

    [ABILITY_MIST_CALLER] =
    {
        .name = _("Mist Caller"),
        .description = FORMAT_ABILITY_DESCRIPTION("Sets Misty Terrain when hit."),
        .aiRating = 7,
    },

    [ABILITY_WIND_BLOWER] =
    {
        .name = _("Wind Blower"),
        .description = FORMAT_ABILITY_DESCRIPTION("Sets up Tailwind."),
        .aiRating = 7,
    },

    [ABILITY_LOOSE_ROCKS] =
    {
        .name = _("Loose Rocks"),
        .description = FORMAT_ABILITY_DESCRIPTION("Throws Stealth Rocks if hit."),
        .aiRating = 8,
    },

    [ABILITY_FIREPOWER] =
    {
        .name = _("Firepower"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up Fire moves."),
        .aiRating = 5,
    },

    [ABILITY_GARDENER] =
    {
        .name = _("Gardener"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up Grass moves."),
        .aiRating = 5,
    },

    [ABILITY_WATERWORKER] =
    {
        .name = _("Waterworker"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up Water moves."),
        .aiRating = 5,
    },

    [ABILITY_PERMAFROST] =
    {
        .name = _("Permafrost"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up Ice moves."),
        .aiRating = 5,
    },

    [ABILITY_DRAGONHEART] =
    {
        .name = _("Dragonheart"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up Dragon moves."),
        .aiRating = 5,
    },

    [ABILITY_PIXIECRAFT] =
    {
        .name = _("Pixiecraft"),
        .description = FORMAT_ABILITY_DESCRIPTION("Powers up Fairy moves."),
        .aiRating = 5,
    },

    [ABILITY_INSULATED] =
    {
        .name = _("Insulated"),
        .description = FORMAT_ABILITY_DESCRIPTION("Halves Water and Electric damage."),
        .aiRating = 8,
    },

    [ABILITY_CURL_UP] =
    {
        .name = _("Curl Up"),
        .description = FORMAT_ABILITY_DESCRIPTION("Adjusts defense favorably."),
        .aiRating = 6,
    },

    [ABILITY_MATTER_ABSORB] =
    {
        .name = _("Matter Absorb"),
        .description = FORMAT_ABILITY_DESCRIPTION("Steel and Rock boost defense."),
        .aiRating = 6,
    },

    [ABILITY_AERODYNAMICS] =
    {
        .name = _("Aerodynamics"),
        .description = FORMAT_ABILITY_DESCRIPTION("Flying moves boost speed."),
        .aiRating = 6,
    },

    [ABILITY_AIRBORNE] =
    {
        .name = _("Airborne"),
        .description = FORMAT_ABILITY_DESCRIPTION("Floats until hit. Immune to Ground."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_CRYONICS] =
    {
        .name = _("Cryonics"),
        .description = FORMAT_ABILITY_DESCRIPTION("May cause frostbite on contact."),
        .aiRating = 7,
    },

    [ABILITY_FILTH_FEEDER] =
    {
        .name = _("Filth Feeder"),
        .description = FORMAT_ABILITY_DESCRIPTION("Drinks poison to heal HP."),
        .aiRating = 8,
    },

    [ABILITY_REFRACTION] =
    {
        .name = _("Refraction"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Special Attack."),
        .aiRating = 6,
    },

    [ABILITY_BLACK_HOLE] =
    {
        .name = _("Black Hole"),
        .description = FORMAT_ABILITY_DESCRIPTION("Prevents the foe's escape."),
        .aiRating = 6,
    },

    [ABILITY_METAL_MUNCHER] =
    {
        .name = _("Metal Muncher"),
        .description = FORMAT_ABILITY_DESCRIPTION("Eats steel to restore HP."),
        .aiRating = 7,
    },

    [ABILITY_VANTABLACK] =
    {
        .name = _("Vantablack"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves become Dark."),
        .aiRating = 8,
    },
	
    [ABILITY_METAL_MORPH] =
    {
        .name = _("Metal Morph"),
        .description = FORMAT_ABILITY_DESCRIPTION("Turns Normal moves to Steel."),
        .aiRating = 8,
    },
	
    [ABILITY_ENERGY_EATER] =
    {
        .name = _("Energy Muncher"),
        .description = FORMAT_ABILITY_DESCRIPTION("Eats Electricity to restore HP."),
        .aiRating = 7,
    },
	
    [ABILITY_SOUL_FEED] =
    {
        .name = _("Soul Feed"),
        .description = FORMAT_ABILITY_DESCRIPTION("Eats souls to restore HP."),
        .aiRating = 7,
    },
	
    [ABILITY_JUGGERNAUT] =
    {
        .name = _("Juggernaut"),
        .description = FORMAT_ABILITY_DESCRIPTION("Size reduces damage."),
        .aiRating = 7,
        .breakable = TRUE,
    },
	
	[ABILITY_CHROME_COAT] =
    {
        .name = _("Chrome Coat"),
        .description = FORMAT_ABILITY_DESCRIPTION("Halves special damage."),
        .aiRating = 7,
        .breakable = TRUE,
    },
	
	[ABILITY_SELF_SUFFICIENT] =
    {
        .name = _("Self Sufficient"),
        .description = FORMAT_ABILITY_DESCRIPTION("Heals damage overtime."),
        .aiRating = 7,
    },
	
	[ABILITY_TIME_WARP] =
    {
        .name = _("Time Warp"),
        .description = FORMAT_ABILITY_DESCRIPTION("Warps time on entry."),
        .aiRating = 7,
    },
	
	[ABILITY_RAPID_FIRE] =
    {
        .name = _("Rapid Fire"),
        .description = FORMAT_ABILITY_DESCRIPTION("Pulse moves have priority."),
        .aiRating = 7,
    },
	
	[ABILITY_WEB_DOWN] =
    {
        .name = _("Web Down"),
        .description = FORMAT_ABILITY_DESCRIPTION("Sets Sticky Web on Entry."),
        .aiRating = 7,
    },
	
	[ABILITY_IMMOLATE] =
    {
        .name = _("Immolate"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves become Fire."),
        .aiRating = 7,
    },
	
	[ABILITY_POWER_METAL] =
    {
        .name = _("Power Metal"),
        .description = FORMAT_ABILITY_DESCRIPTION("Punk Rock + Levitate."),
        .aiRating = -1,
        .breakable = TRUE,
    },
	
	[ABILITY_STAR_POWER] =
    {
        .name = _("Star Power"),
        .description = FORMAT_ABILITY_DESCRIPTION("Raises Attack."),
        .aiRating = 10,
    },
	
	[ABILITY_SPECIALIST] =
    {
        .name = _("Specialist"),
        .description = FORMAT_ABILITY_DESCRIPTION("Doubles weaker moves."),
        .aiRating = 8,
    },
	
	[ABILITY_SHADOW_POWER] =
    {
        .name = _("Shadow Power"),
        .description = FORMAT_ABILITY_DESCRIPTION("Tougher but light sensitive."),
        .aiRating = 5,
        .breakable = TRUE,
    },
	
	[ABILITY_SPECTRALIZE] =
    {
        .name = _("Spectralize"),
        .description = FORMAT_ABILITY_DESCRIPTION("Normal moves become Ghost."),
        .aiRating = 7,
    },

    [ABILITY_SHOOTING_STAR] =
    {
        .name = _("Shooting Star"),
        .description = FORMAT_ABILITY_DESCRIPTION("Activates wish when at half health, once per battle."),
        .aiRating = 8,
    },

    [ABILITY_HUBRIS] =
    {
        .name = _("Hubris"),
        .description = FORMAT_ABILITY_DESCRIPTION("KOs raise SpAtk by one stage."),
        .aiRating = 8,
    },

    [ABILITY_ALGAE_BLOOM] =
    {
        .name = _("Algae Bloom"),
        .description = FORMAT_ABILITY_DESCRIPTION("Rain causes Grassy Terrain to spawn."),
        .aiRating = 8,
    },

    [ABILITY_AURA_SHIFT] =
    {
        .name = _("Aura Shift"),
        .description = FORMAT_ABILITY_DESCRIPTION("Fighting-type moves use special attack."),
        .aiRating = 8,
    },

    [ABILITY_DREAM_WORLD] =
    {
        .name = _("Dream World"),
        .description = FORMAT_ABILITY_DESCRIPTION("Makes everybody Drowsy when sent out."),
        .aiRating = 8,
    },

    [ABILITY_ROOTED] =
    {
        .name = _("Rooted"),
        .description = FORMAT_ABILITY_DESCRIPTION("Plants its roots at the start of battle."),
        .aiRating = 8,
    },

    [ABILITY_OPPOSITE_DAY] =
    {
        .name = _("Opposite day"),
        .description = FORMAT_ABILITY_DESCRIPTION("The Pokémon summons Inverse Room when it enters the battlefield."),
        .aiRating = 8,
    },

    [ABILITY_TOTTERING_STEP] =
    {
        .name = _("Tottering Steps"),
        .description = FORMAT_ABILITY_DESCRIPTION("When attacking this Pokémon may cause the target to become confused."),
        .aiRating = 8,
    },

    [ABILITY_PREDATOR] =
    {
        .name = _("Predator"),
        .description = FORMAT_ABILITY_DESCRIPTION("Dealing a KO heals 1/8 of this Pokémon's max HP."),
        .aiRating = 8,
    },

    [ABILITY_BLOW_AWAY] =
    {
        .name = _("Blow Away"),
        .description = FORMAT_ABILITY_DESCRIPTION("Uses Defog upon switch in."),
        .aiRating = 8,
    },

    [ABILITY_BELLICUS] =
    {
        .name = _("Bellicus"),
        .description = FORMAT_ABILITY_DESCRIPTION("50% boost to attacks, 50% drop in speed."),
        .aiRating = 8,
    },

    [ABILITY_SERENA] =
    {
        .name = _("Serena"),
        .description = FORMAT_ABILITY_DESCRIPTION("50% boost to defense, 50% drop in speed."),
        .aiRating = 8,
    },

    [ABILITY_DEAD_SPACE] =
    {
        .name = _("Dead Space"),
        .description = FORMAT_ABILITY_DESCRIPTION("Nullifies terrain, weather and abilities."),
        .aiRating = 8,
        .cantBeSuppressed = TRUE,
    },

    [ABILITY_MOUNTAINEER] =
    {
        .name = _("Mountaineer"),
        .description = FORMAT_ABILITY_DESCRIPTION("Not hit by Rock-type moves, ignores hazards."),
        .aiRating = 8,
    },

    [ABILITY_CHEMIST] =
    {
        .name = _("Chemist"),
        .description = FORMAT_ABILITY_DESCRIPTION("Upon switch in, releases gas that has a myriad of status effects."),
        .aiRating = 8,
    },

    [ABILITY_MEGA_SOL] =
    {
        .name = _("Mega Sol"),
        .description = FORMAT_ABILITY_DESCRIPTION("Even when the sunlight has not turned harsh, the Pokémon can use its moves as if the weather were harsh sunlight."),
        .aiRating = 8,
    },

    [ABILITY_ENCHANTING_VOICE] =
    {
        .name = _("Enchanting Voice"),
        .description = FORMAT_ABILITY_DESCRIPTION("Boosts the power of sound moves."),
        .aiRating = 8,
    },

    [ABILITY_DRAGONIZE] =
    {
        .name = _("Dragonize"),
        .description = FORMAT_ABILITY_DESCRIPTION("Turns Normal moves into Dragon."),
        .aiRating = 8,
    },

    [ABILITY_MUCUS_MEMBRANE] =
    {
        .name = _("Mucus Membrane"),
        .description = FORMAT_ABILITY_DESCRIPTION("Damage reduced by 30%."),
        .aiRating = 8,
    },
	
    [ABILITY_METAL_SHRED] =
    {
        .name = _("Metal Shred"),
        .description = FORMAT_ABILITY_DESCRIPTION("Scatters metal debris if hit."),
        .aiRating = 8,
    },
	
    [ABILITY_THERIANTROPE] =
    {
        .name = _("Theriantrope"),
        .description = FORMAT_ABILITY_DESCRIPTION("Transforms at half HP."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },
	
    [ABILITY_FIRE_MANE] =
    {
        .name = _("Fire Mane"),
        .description = FORMAT_ABILITY_DESCRIPTION("Ups Fire-type moves."),
        .aiRating = 6,
    },

};

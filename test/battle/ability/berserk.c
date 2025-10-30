#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Berserk activates only if the target had more than 50% of its HP")
{
    bool32 activates = FALSE;
    u16 maxHp = 500, hp = 0;

    PARAMETRIZE { hp = 250; activates = FALSE; }
    PARAMETRIZE { hp = 249; activates = FALSE; }
    PARAMETRIZE { hp = 100; activates = FALSE; }
    PARAMETRIZE { hp = 50; activates = FALSE; }
    PARAMETRIZE { hp = 251; activates = TRUE; }
    PARAMETRIZE { hp = 254; activates = TRUE; }

    GIVEN {
        ASSUME(!IsBattleMoveStatus(MOVE_SCRATCH));
        PLAYER(SPECIES_DRAMPA) { Ability(ABILITY_BERSERK); MaxHP(maxHp); HP(hp); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        if (activates) {
            ABILITY_POPUP(player, ABILITY_BERSERK);
        } else {
            NOT ABILITY_POPUP(player, ABILITY_BERSERK);
        }
    } THEN {
        if (activates) {
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        }
    }
}

SINGLE_BATTLE_TEST("Berserk raises Sp.Atk by 1")
{
    u16 maxHp = 500;
    GIVEN {
        ASSUME(!IsBattleMoveStatus(MOVE_SCRATCH));
        PLAYER(SPECIES_DRAMPA) { Ability(ABILITY_BERSERK); MaxHP(maxHp); HP(maxHp / 2 + 1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_BERSERK);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Drampa's Sp. Atk rose!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Berserk activates after all hits from a multi-hit move")
{
    u32 j;
    u16 maxHp = 500;
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DOUBLE_SLAP) == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_DRAMPA) { Ability(ABILITY_BERSERK); MaxHP(maxHp); HP(maxHp / 2 + 1); }
        OPPONENT(SPECIES_SHELLDER) { Ability(ABILITY_SKILL_LINK); } // Always hits 5 times.
    } WHEN {
        TURN { MOVE(opponent, MOVE_DOUBLE_SLAP); }
    } SCENE {
        for (j = 0; j < 4; j++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SLAP, opponent);
            NOT ABILITY_POPUP(player, ABILITY_BERSERK);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SLAP, opponent);
        ABILITY_POPUP(player, ABILITY_BERSERK);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Berserk activates only if the target had more than 50% of its HP (Trait)")
{
    bool32 activates = FALSE;
    u16 maxHp = 500, hp = 0;

    PARAMETRIZE { hp = 250; activates = FALSE; }
    PARAMETRIZE { hp = 249; activates = FALSE; }
    PARAMETRIZE { hp = 100; activates = FALSE; }
    PARAMETRIZE { hp = 50; activates = FALSE; }
    PARAMETRIZE { hp = 251; activates = TRUE; }
    PARAMETRIZE { hp = 254; activates = TRUE; }

    GIVEN {
        ASSUME(!IsBattleMoveStatus(MOVE_SCRATCH));
        PLAYER(SPECIES_DRAMPA) { Ability(ABILITY_SAP_SIPPER); Innates(ABILITY_BERSERK); MaxHP(maxHp); HP(hp); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        if (activates) {
            ABILITY_POPUP(player, ABILITY_BERSERK);
        } else {
            NOT ABILITY_POPUP(player, ABILITY_BERSERK);
        }
    } THEN {
        if (activates) {
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        }
    }
}

SINGLE_BATTLE_TEST("Berserk raises Sp.Atk by 1 (Trait)")
{
    u16 maxHp = 500;
    GIVEN {
        ASSUME(!IsBattleMoveStatus(MOVE_SCRATCH));
        PLAYER(SPECIES_DRAMPA) { Ability(ABILITY_SAP_SIPPER); Innates(ABILITY_BERSERK); MaxHP(maxHp); HP(maxHp / 2 + 1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_BERSERK);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Drampa's Sp. Atk rose!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Berserk activates after all hits from a multi-hit move (Trait)")
{
    u32 j;
    u16 maxHp = 500;
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DOUBLE_SLAP) == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_DRAMPA) { Ability(ABILITY_SAP_SIPPER); Innates(ABILITY_BERSERK); MaxHP(maxHp); HP(maxHp / 2 + 1); }
        OPPONENT(SPECIES_SHELLDER) { Ability(ABILITY_SHELL_ARMOR); Innates(ABILITY_SKILL_LINK); } // Always hits 5 times.
    } WHEN {
        TURN { MOVE(opponent, MOVE_DOUBLE_SLAP); }
    } SCENE {
        for (j = 0; j < 4; j++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SLAP, opponent);
            NOT ABILITY_POPUP(player, ABILITY_BERSERK);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_SLAP, opponent);
        ABILITY_POPUP(player, ABILITY_BERSERK);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("On hit stat boosting abilities do not conflict with each other (Trait)")
{
    u16 maxHp = 500;
    u16 move, innate1, innate2;

    PARAMETRIZE { move = MOVE_BITE; innate1 = ABILITY_JUSTIFIED; innate2 = ABILITY_RATTLED; }
    PARAMETRIZE { move = MOVE_WATER_GUN; innate1 = ABILITY_WATER_COMPACTION; innate2 = ABILITY_STEAM_ENGINE; }
    PARAMETRIZE { move = MOVE_EMBER; innate1 = ABILITY_THERMAL_EXCHANGE; innate2 = ABILITY_STEAM_ENGINE; }

    GIVEN {
        ASSUME(!IsBattleMoveStatus(move));
        PLAYER(SPECIES_DRAMPA) { Ability(ABILITY_BERSERK); Innates(ABILITY_STAMINA, innate1, innate2); MaxHP(maxHp); HP(maxHp / 2 + 1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_EMBER)
            ABILITY_POPUP(player, ABILITY_THERMAL_EXCHANGE);
        if (move == MOVE_WATER_GUN || move == MOVE_EMBER)
            ABILITY_POPUP(player, ABILITY_STEAM_ENGINE);
        ABILITY_POPUP(player, ABILITY_BERSERK);
        ABILITY_POPUP(player, ABILITY_STAMINA);
        if (move == MOVE_WATER_GUN)
            ABILITY_POPUP(player, ABILITY_WATER_COMPACTION);
        if (move == MOVE_BITE)
        {
            ABILITY_POPUP(player, ABILITY_RATTLED);
            ABILITY_POPUP(player, ABILITY_JUSTIFIED);
        }
    } THEN {
        if (move == MOVE_BITE)
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        else
            EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);

        if (move == MOVE_BITE)
            EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);

        if (move == MOVE_WATER_GUN)
        {
            EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 6);
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 3);
        }
        else
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);

        if (move == MOVE_EMBER)
        {
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
            EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 6);
        }
    }
}
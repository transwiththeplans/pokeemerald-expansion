#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Multi - Contrary causes Competitive or Defiant to sharply lower stats", s16 damage)
{
    u32 attack;
    u32 ability;
    PARAMETRIZE { ability = ABILITY_OVERGROW; attack = MOVE_WATER_GUN;}
    PARAMETRIZE { ability = ABILITY_COMPETITIVE; attack = MOVE_WATER_GUN;}
    PARAMETRIZE { ability = ABILITY_OVERGROW; attack = MOVE_TACKLE;}
    PARAMETRIZE { ability = ABILITY_DEFIANT; attack = MOVE_TACKLE;}
    GIVEN {
        PLAYER(SPECIES_SUNFLORA) { Speed(3); }
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); Innates(ability); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLOWER_SHIELD); MOVE(opponent, attack); }
    } SCENE {
        MESSAGE("Sunflora used Flower Shield!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Sunflora's Defense rose!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Defense fell!");
        //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla

        if (ability == ABILITY_COMPETITIVE) {
            ABILITY_POPUP(opponent, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Snivy's Sp. Atk harshly fell!");
            //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
        }
        else if (ability == ABILITY_DEFIANT){
            ABILITY_POPUP(opponent, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Snivy's Attack harshly fell!");
            //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
        }

        HP_BAR(player, captureDamage: &results[i].damage);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2), results[0].damage);
        EXPECT_MUL_EQ(results[3].damage, Q_4_12(2), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Multi - Contrary causes Competitive and Defiant to sharply lower both stats", s16 damage)
{
    u32 ability1, ability2;
    PARAMETRIZE { ability1 = ABILITY_OVERGROW; ability2 = ABILITY_OVERGROW; }
    PARAMETRIZE { ability1 = ABILITY_DEFIANT; ability2 = ABILITY_COMPETITIVE; }

    GIVEN {
        PLAYER(SPECIES_SUNFLORA) { Speed(3); }
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); Innates(ability1, ability2); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLOWER_SHIELD); MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Sunflora used Flower Shield!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Sunflora's Defense rose!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Defense fell!");
        //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla

        if (ability2 == ABILITY_DEFIANT){
            ABILITY_POPUP(opponent, ABILITY_DEFIANT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Snivy's Attack harshly fell!");
            //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
            ABILITY_POPUP(opponent, ABILITY_COMPETITIVE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Snivy's Sp. Atk harshly fell!");
            //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    }
    FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(2), results[0].damage);
        EXPECT_MUL_EQ(results[3].damage, Q_4_12(2), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Multi - Multiple stat changing abilities activating together")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_UNNERVE); Innates(ABILITY_SUPERSWEET_SYRUP, ABILITY_PRESSURE, ABILITY_INTIMIDATE); Speed(3); }
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); Innates(ABILITY_DEFIANT, ABILITY_COMPETITIVE, ABILITY_RATTLED); Speed(2); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_PRESSURE);
        MESSAGE("Ekans is exerting its pressure!");
        ABILITY_POPUP(player, ABILITY_UNNERVE);
        MESSAGE("The opposing team is too nervous to eat Berries!");
        ABILITY_POPUP(player, ABILITY_SUPERSWEET_SYRUP);
        MESSAGE("A supersweet aroma is wafting from the syrup covering Ekans!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's evasiveness rose!");
        //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Attack rose!");
        //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
        ABILITY_POPUP(opponent, ABILITY_RATTLED);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Speed fell!");
        //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
        ABILITY_POPUP(opponent, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Attack harshly fell!");
        //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla  
        ABILITY_POPUP(opponent, ABILITY_COMPETITIVE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Snivy's Sp. Atk harshly fell!");
        //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla

    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1); // Intimidate +1, Defiant -2
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 2); // Competitive -2
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1); // Rattled -1
        EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE + 1); // Supersweet Aroma +1
    }
}

SINGLE_BATTLE_TEST("Multi - Contrary Intimidate still trigger Rattled")
{
    u32 ability1, ability2, innate1;
    PARAMETRIZE { ability1 = ABILITY_UNNERVE; ability2 = ABILITY_OVERGROW; innate1 = ABILITY_OVERGROW;}
    PARAMETRIZE { ability1 = ABILITY_INTIMIDATE; ability2 = ABILITY_OVERGROW; innate1 = ABILITY_OVERGROW;}
    PARAMETRIZE { ability1 = ABILITY_INTIMIDATE; ability2 = ABILITY_CONTRARY; innate1 = ABILITY_OVERGROW;}
    PARAMETRIZE { ability1 = ABILITY_INTIMIDATE; ability2 = ABILITY_CONTRARY; innate1 = ABILITY_RATTLED;}

    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ability1); }
        OPPONENT(SPECIES_SNIVY) { Ability(ability2); Innates(innate1); }
    } WHEN {
        TURN { }
    } SCENE {
        if (ability1 == ABILITY_UNNERVE)
        {
            ABILITY_POPUP(player, ABILITY_UNNERVE);
            MESSAGE("The opposing team is too nervous to eat Berries!");
        }
        else if (ability1 == ABILITY_INTIMIDATE && ability2 != ABILITY_CONTRARY)
        {
            ABILITY_POPUP(player, ABILITY_INTIMIDATE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Ekans's Intimidate cuts the opposing Snivy's Attack!");
        }
        else if (ability1 == ABILITY_INTIMIDATE && ability2 == ABILITY_CONTRARY)
        {
            ABILITY_POPUP(player, ABILITY_INTIMIDATE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Snivy's Attack rose!");
            //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
        }
        if (innate1 == ABILITY_RATTLED)
        {
            ABILITY_POPUP(opponent, ABILITY_RATTLED);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Snivy's Speed fell!");
            //ABILITY_POPUP(opponent, ABILITY_CONTRARY); //No popup in vanilla
        } 

    } THEN {
        if (ability1 == ABILITY_INTIMIDATE && ability2 != ABILITY_CONTRARY)
            EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        if (ability1 == ABILITY_INTIMIDATE && ability2 == ABILITY_CONTRARY)
            EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        if (ability1 == ABILITY_INTIMIDATE && ability2 == ABILITY_CONTRARY && innate1 == ABILITY_RATTLED)
            EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

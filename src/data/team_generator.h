#include "trainer_pools.h"

static u16 EvolveTrainerMon(u16 species, u8 level);

static bool8 TrainerPartyAlreadyHasSpecies(struct Pokemon *party, u8 partySize, u16 species, u8 level)
{
    u8 i;
    u16 evolvedSpecies = EvolveTrainerMon(species, level);

    for (i = 0; i < partySize; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES) == evolvedSpecies)
            return TRUE;
    }

    return FALSE;
}

u8 GetSpecialTrainerPool(u16 trainerId)
{
    u16 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u16 mapNum = gSaveBlock1Ptr->location.mapNum;

    typedef struct {
        u16 mapGroup;
        u16 mapNum;
    } Location;

    Location sGymPoolsLocations[] =
    {
        [SPECIAL_TRAINER_POOL_GYM_1_TRAINERS] = { MAP_GROUP(MAP_RUSTBORO_CITY_GYM),      MAP_NUM(MAP_RUSTBORO_CITY_GYM)},
        [SPECIAL_TRAINER_POOL_GYM_2_TRAINERS] = { MAP_GROUP(MAP_DEWFORD_TOWN_GYM),       MAP_NUM(MAP_DEWFORD_TOWN_GYM)},
        [SPECIAL_TRAINER_POOL_GYM_3_TRAINERS] = { MAP_GROUP(MAP_MAUVILLE_CITY_GYM),      MAP_NUM(MAP_MAUVILLE_CITY_GYM)},
        [SPECIAL_TRAINER_POOL_GYM_4_TRAINERS] = { MAP_GROUP(MAP_LAVARIDGE_TOWN_GYM_1F),  MAP_NUM(MAP_LAVARIDGE_TOWN_GYM_1F)},
        /*[SPECIAL_TRAINER_POOL_GYM_5_TRAINERS] = { MAP_GROUP(MAP_PETALBURG_CITY_GYM),     MAP_NUM(MAP_PETALBURG_CITY_GYM)},
        [SPECIAL_TRAINER_POOL_GYM_6_TRAINERS] = { MAP_GROUP(MAP_FORTREE_CITY_GYM),       MAP_NUM(MAP_FORTREE_CITY_GYM)},
        [SPECIAL_TRAINER_POOL_GYM_7_TRAINERS] = { MAP_GROUP(MAP_MOSSDEEP_CITY_GYM),      MAP_NUM(MAP_MOSSDEEP_CITY_GYM)},
        [SPECIAL_TRAINER_POOL_GYM_8_TRAINERS] = { MAP_GROUP(MAP_SOOTOPOLIS_CITY_GYM_1F), MAP_NUM(MAP_SOOTOPOLIS_CITY_GYM_1F)},*/
    };

    for (u8 i = SPECIAL_TRAINER_POOL_GYM_1_TRAINERS; i < ARRAY_COUNT(sGymPoolsLocations); i++)
    {
        if (mapNum == sGymPoolsLocations[i].mapNum && mapGroup == sGymPoolsLocations[i].mapGroup)
            return i;

        //Some Gyms have more than 1 map
        switch(i){
            case SPECIAL_TRAINER_POOL_GYM_4_TRAINERS:
                if (mapNum == MAP_NUM(MAP_LAVARIDGE_TOWN_GYM_B1F) && mapGroup == MAP_GROUP(MAP_LAVARIDGE_TOWN_GYM_B1F))
                    return i;
            break;
            case SPECIAL_TRAINER_POOL_GYM_8_TRAINERS:
                if (mapNum == MAP_NUM(MAP_SOOTOPOLIS_CITY_GYM_B1F) && mapGroup == MAP_GROUP(MAP_SOOTOPOLIS_CITY_GYM_B1F))
                    return i;
            break;
        }
    }

    return SPECIAL_TRAINER_POOL_NONE;
}

u16 GetTrainerSpeciesFromPool(u16 species, u8 level, u16 trainerId, u8 trainerClass, struct Pokemon *party, u8 partySize, u8 specialTrainerPool)
{
    u32 poolSize = 0;
    u32 availableSpecies = 0;
    u32 speciesIndex;
    const u16 *trainerPool;
    u32 i;

    if (trainerId == TRAINER_ID_DYNAMIC || trainerClass >= TRAINER_CLASS_COUNT)
        return species;

    if(specialTrainerPool != SPECIAL_TRAINER_POOL_NONE)
        trainerPool = sSpecialTrainerPkmnPool[specialTrainerPool];
    else
        trainerPool = sTrainerClassPkmnPool[trainerClass];

    while (poolSize < TRAINER_POOL_MON_NUM && trainerPool[poolSize] != SPECIES_NONE)
        poolSize++;

    if (poolSize == 0)
        return species;

    for (i = 0; i < poolSize; i++)
    {
        if (!TrainerPartyAlreadyHasSpecies(party, partySize, trainerPool[i], level))
            availableSpecies++;
    }

    if (availableSpecies == 0)
        return EvolveTrainerMon(trainerPool[Random() % poolSize], level);

    speciesIndex = Random() % availableSpecies;
    for (i = 0; i < poolSize; i++)
    {
        if (!TrainerPartyAlreadyHasSpecies(party, partySize, trainerPool[i], level))
        {
            if (speciesIndex == 0)
                return EvolveTrainerMon(trainerPool[i], level);
            speciesIndex--;
        }
    }

    return species;
}

#define TRAINER_EVOLUTION_LEVEL_FRIENDSHIP 18
#define TRAINER_EVOLUTION_LEVEL_BEAUTY     20
#define TRAINER_EVOLUTION_LEVEL_LATEGAME   36

static u8 GetTrainerConditionalEvolutionLevel(const struct Evolution *evolution)
{
    u32 i;

    if (evolution->params == NULL)
        return TRAINER_EVOLUTION_LEVEL_LATEGAME;

    for (i = 0; evolution->params[i].condition != CONDITIONS_END; i++)
    {
        switch (evolution->params[i].condition)
        {
        case IF_MIN_FRIENDSHIP:
            return TRAINER_EVOLUTION_LEVEL_FRIENDSHIP;
        case IF_MIN_BEAUTY:
        case IF_MIN_COOLNESS:
        case IF_MIN_SMARTNESS:
        case IF_MIN_TOUGHNESS:
        case IF_MIN_CUTENESS:
            return TRAINER_EVOLUTION_LEVEL_BEAUTY;
        default:
            break;
        }
    }

    return TRAINER_EVOLUTION_LEVEL_LATEGAME;
}

static bool8 TrainerEvolutionMeetsLevel(const struct Evolution *evolution, u8 level)
{
    switch (evolution->method)
    {
    case EVO_LEVEL:
    case EVO_LEVEL_BATTLE_ONLY:
        if (evolution->param == 0)
            return level >= GetTrainerConditionalEvolutionLevel(evolution);
        return evolution->param <= level;
    case EVO_ITEM:
    case EVO_TRADE:
    case EVO_BATTLE_END:
    case EVO_SPIN:
    case EVO_SCRIPT_TRIGGER:
        return level >= TRAINER_EVOLUTION_LEVEL_LATEGAME;
    default:
        return FALSE;
    }
}

static u16 EvolveTrainerMon(u16 species, u8 level)
{
    u32 i;
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions == NULL)
        return species;

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        u16 targetSpecies = evolutions[i].targetSpecies;

        if (SanitizeSpeciesId(targetSpecies) == SPECIES_NONE)
            continue;

        if (TrainerEvolutionMeetsLevel(&evolutions[i], level))
            return EvolveTrainerMon(targetSpecies, level);
    }

    return species;
}

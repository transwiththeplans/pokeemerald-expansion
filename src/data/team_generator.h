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

u16 GetTrainerSpeciesFromPool(u16 species, u8 level, u16 trainerId, u8 trainerClass, struct Pokemon *party, u8 partySize)
{
    u32 poolSize = 0;
    u32 availableSpecies = 0;
    u32 speciesIndex;
    u32 i;

    if (trainerId == TRAINER_ID_DYNAMIC || trainerClass >= TRAINER_CLASS_COUNT)
        return species;

    while (poolSize < TRAINER_POOL_MON_NUM && sTrainerClassPkmnPool[trainerClass][poolSize] != SPECIES_NONE)
        poolSize++;

    if (poolSize == 0)
        return species;

    for (i = 0; i < poolSize; i++)
    {
        if (!TrainerPartyAlreadyHasSpecies(party, partySize, sTrainerClassPkmnPool[trainerClass][i], level))
            availableSpecies++;
    }

    if (availableSpecies == 0)
        return EvolveTrainerMon(sTrainerClassPkmnPool[trainerClass][Random() % poolSize], level);

    speciesIndex = Random() % availableSpecies;
    for (i = 0; i < poolSize; i++)
    {
        if (!TrainerPartyAlreadyHasSpecies(party, partySize, sTrainerClassPkmnPool[trainerClass][i], level))
        {
            if (speciesIndex == 0)
                return EvolveTrainerMon(sTrainerClassPkmnPool[trainerClass][i], level);
            speciesIndex--;
        }
    }

    return species;
}

#define TRAINER_EVOLUTION_LEVEL_FRIENDSHIP 18
#define TRAINER_EVOLUTION_LEVEL_BEAUTY     20
#define TRAINER_EVOLUTION_LEVEL_LATEGAME   36

static bool8 TrainerEvolutionMeetsLevel(const struct Evolution *evolution, u8 level)
{
    switch (evolution->method)
    {
    case EVO_LEVEL:
    case EVO_LEVEL_BATTLE_ONLY:
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

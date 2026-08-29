#include "global.h"
#include "pokemon.h"
#include "tarc_traits.h"

struct SpeciesTraits
{
    enum Species species;
    const struct TarcTrait *traits;
};


static const struct TarcTrait sMewTraits[] = {
    { .type = EXTRA_TYPE, .arg1 = TYPE_NORMAL },
    { .type = EXTRA_TYPE, .arg1 = TYPE_FAIRY },
    { .type = EXTRA_TYPE, .arg1 = TYPE_GHOST },
};

static const struct TarcTrait sArcanineTraits[] = {
    { .type = EXTRA_STAT, .arg1 = STAT_ATK,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_DEF,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_SPEED, .arg2 = 20},
};

static const struct TarcTrait sMudskipTraits[] = {
    { .type = ALL_STAT_BONUS, .arg1 = 5},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_ATK,  .arg2 = STAT_DEF, .arg3 = 20},
    { .type = EXTRA_IMMUNITY, .arg1 = TYPE_NORMAL },
};

static const struct SpeciesTraits sTarcTraits[] = {
    { .species = SPECIES_MEW, .traits = sMewTraits },
    { .species = SPECIES_TORCHIC, .traits = sArcanineTraits },
    { .species = SPECIES_MUDKIP, .traits = sMudskipTraits },
    { .species = SPECIES_NONE, .traits = NULL },
};

const struct TarcTrait *GetBoxMonTrait(struct BoxPokemon *boxmon, u32 traitIndex)
{
    enum Species species = GetBoxMonData(boxmon, MON_DATA_SPECIES_OR_EGG);
    for (u32 i = 0; sTarcTraits[i].species; i++)
    {
        if (species == sTarcTraits[i].species)
        {
            return &sTarcTraits[i].traits[traitIndex];
        }
    }
    return NULL;
}

enum Type GetBoxMonExtraType(struct BoxPokemon *boxmon)
{
    enum Species species = GetBoxMonData(boxmon, MON_DATA_SPECIES_OR_EGG);
    u32 traitIndex = GetBoxMonData(boxmon, MON_DATA_TRAIT_INDEX);
    for (u32 i = 0; sTarcTraits[i].species; i++)
    {
        if (species == sTarcTraits[i].species)
        {
            if (sTarcTraits[i].traits[traitIndex].type == EXTRA_TYPE)
            {
                return sTarcTraits[i].traits[traitIndex].arg1;
            }
            else
            {
                return TYPE_MYSTERY;
            }
        }
    }
    return TYPE_MYSTERY;
}

enum Type GetBoxMonExtraImmunity(struct BoxPokemon *boxmon)
{
    enum Species species = GetBoxMonData(boxmon, MON_DATA_SPECIES_OR_EGG);
    u32 traitIndex = GetBoxMonData(boxmon, MON_DATA_TRAIT_INDEX);
    for (u32 i = 0; sTarcTraits[i].species; i++)
    {
        if (species == sTarcTraits[i].species)
        {
            if (sTarcTraits[i].traits[traitIndex].type == EXTRA_IMMUNITY)
            {
                return sTarcTraits[i].traits[traitIndex].arg1;
            }
            else
            {
                return TYPE_NONE;
            }
        }
    }
    return TYPE_NONE;
}

u32 GetBoxMonExtraStat(struct BoxPokemon *boxmon, enum Stat stat)
{
    enum Species species = GetBoxMonData(boxmon, MON_DATA_SPECIES_OR_EGG);
    u32 traitIndex = GetBoxMonData(boxmon, MON_DATA_TRAIT_INDEX);
    for (u32 i = 0; sTarcTraits[i].species; i++)
    {
        if (species == sTarcTraits[i].species)
        {
            if (sTarcTraits[i].traits[traitIndex].type == EXTRA_STAT && sTarcTraits[i].traits[traitIndex].arg1 == stat)
            {
                return sTarcTraits[i].traits[traitIndex].arg2;
            }
            else if (sTarcTraits[i].traits[traitIndex].type == ALL_STAT_BONUS)
            {
                return sTarcTraits[i].traits[traitIndex].arg1;
            }
            else if (sTarcTraits[i].traits[traitIndex].type == EXTRA_STAT_DRAWBACK)
            {
                if (sTarcTraits[i].traits[traitIndex].arg1 == stat)
                    return sTarcTraits[i].traits[traitIndex].arg3 * 2;
                else if (sTarcTraits[i].traits[traitIndex].arg2 == stat)
                    return sTarcTraits[i].traits[traitIndex].arg3 * (-1);
                else
                    return 0;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

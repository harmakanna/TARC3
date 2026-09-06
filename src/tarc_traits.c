#include "global.h"
#include "battle_main.h"
#include "battle_message.h"
#include "event_data.h"
#include "malloc.h"
#include "pokemon.h"
#include "random.h"
#include "string_util.h"
#include "tarc_traits.h"

struct SpeciesTraits
{
    enum Species species;
    const struct TarcTrait *traits;
};


static const struct TarcTrait sMewTraits[] = {
    { .type = NULL_MOD },
    { .type = EXTRA_TYPE, .arg1 = TYPE_NORMAL },
    { .type = EXTRA_TYPE, .arg1 = TYPE_FAIRY },
    { .type = EXTRA_TYPE, .arg1 = TYPE_GHOST },
    { .type = EXTRA_STAT, .arg1 = STAT_ATK,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_DEF,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_SPEED, .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_HP,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_SPATK,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_SPDEF, .arg2 = 20},
    { .type = NULL_MOD },
};

static const struct TarcTrait sArcanineTraits[] = {
    { .type = NULL_MOD },
    { .type = EXTRA_STAT, .arg1 = STAT_ATK,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_DEF,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_SPEED, .arg2 = 20},
    { .type = NULL_MOD },
};

static const struct TarcTrait sMudskipTraits[] = {
    { .type = NULL_MOD },
    { .type = ALL_STAT_BONUS, .arg1 = 5},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_ATK,  .arg2 = STAT_DEF, .arg3 = 20},
    { .type = EXTRA_IMMUNITY, .arg1 = TYPE_NORMAL },
    { .type = NULL_MOD },
};



static const struct TarcTrait sDarkanineTraits[] = {
    { .type = NULL_MOD },
    { .type = EXTRA_TYPE, .arg1 = TYPE_FIRE },
    { .type = EXTRA_STAT, .arg1 = STAT_HP,   .arg2 = 20},
    { .type = EXTRA_STAT, .arg1 = STAT_SPEED, .arg2 = 20},
    { .type = ALL_STAT_BONUS, .arg1 = 5},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_ATK,  .arg2 = STAT_DEF, .arg3 = 20},
    { .type = EXTRA_IMMUNITY, .arg1 = TYPE_NORMAL },
    { .type = NULL_MOD },
};

static const struct TarcTrait sDratiniTraits[] = {
    { .type = NULL_MOD },
    { .type = EXTRA_TYPE, .arg1 = TYPE_NORMAL },
    { .type = EXTRA_STAT, .arg1 = STAT_HP,   .arg2 = 45},
    { .type = EXTRA_STAT, .arg1 = STAT_DEF, .arg2 = 45},
    { .type = EXTRA_STAT, .arg1 = STAT_SPDEF, .arg2 = 45},
    { .type = ALL_STAT_BONUS, .arg1 = 15},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_ATK,  .arg2 = STAT_SPEED, .arg3 = 45},
    { .type = EXTRA_IMMUNITY, .arg1 = TYPE_ICE },
    { .type = NULL_MOD },
};

static const struct TarcTrait sExcadrillTraits[] = {
    { .type = NULL_MOD },
    { .type = EXTRA_STAT, .arg1 = STAT_ATK,   .arg2 = 30},
    { .type = EXTRA_STAT, .arg1 = STAT_SPEED, .arg2 = 30},
    { .type = ALL_STAT_BONUS, .arg1 = 10},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_SPEED,  .arg2 = STAT_DEF, .arg3 = 30},
    { .type = EXTRA_IMMUNITY, .arg1 = TYPE_GROUND },
    { .type = NULL_MOD },
};

static const struct TarcTrait sLedianTraits[] = {
    { .type = NULL_MOD },
    { .type = EXTRA_TYPE, .arg1 = TYPE_FIGHTING },
    { .type = EXTRA_STAT, .arg1 = STAT_HP,   .arg2 = 30},
    { .type = EXTRA_STAT, .arg1 = STAT_SPEED, .arg2 = 30},
    { .type = ALL_STAT_BONUS, .arg1 = 10},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_ATK,  .arg2 = STAT_SPDEF, .arg3 = 30},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_SPATK,  .arg2 = STAT_SPDEF, .arg3 = 30},
    { .type = EXTRA_IMMUNITY, .arg1 = TYPE_ROCK },
    { .type = NULL_MOD },
};

static const struct TarcTrait sPonytaTraits[] = {
    { .type = NULL_MOD },
    { .type = EXTRA_TYPE, .arg1 = TYPE_ELECTRIC },
    { .type = EXTRA_STAT, .arg1 = STAT_ATK,   .arg2 = 45},
    { .type = EXTRA_STAT, .arg1 = STAT_SPEED, .arg2 = 45},
    { .type = ALL_STAT_BONUS, .arg1 = 15},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_ATK,  .arg2 = STAT_SPDEF, .arg3 = 45},
    { .type = EXTRA_STAT_DRAWBACK, .arg1 = STAT_SPEED,  .arg2 = STAT_SPATK, .arg3 = 45},
    { .type = EXTRA_IMMUNITY, .arg1 = TYPE_ROCK },
    { .type = NULL_MOD },
};





static const struct SpeciesTraits sTarcTraits[] = {
    { .species = SPECIES_MEW, .traits = sMewTraits },
    { .species = SPECIES_TORCHIC, .traits = sArcanineTraits },
    { .species = SPECIES_MUDKIP, .traits = sMudskipTraits },
    { .species = SPECIES_DARKANINE, .traits = sDarkanineTraits },
    { .species = SPECIES_DRATINI, .traits = sDratiniTraits },
    { .species = SPECIES_EXCADRILL, .traits = sExcadrillTraits },
    { .species = SPECIES_PONYTA, .traits = sPonytaTraits },
    { .species = SPECIES_LEDIAN, .traits = sLedianTraits },
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

const struct TarcTrait *GetSpeciesTraitList(struct BoxPokemon *boxmon)
{
    enum Species species = GetBoxMonData(boxmon, MON_DATA_SPECIES_OR_EGG);
    for (u32 i = 0; sTarcTraits[i].species; i++)
    {
        if (species == sTarcTraits[i].species)
            return sTarcTraits[i].traits;
    }
    return NULL;
}

enum Type GetBoxMonExtraType(struct BoxPokemon *boxmon)
{
    const struct TarcTrait *traitList = GetSpeciesTraitList(boxmon);
    if (!traitList)
        return TYPE_MYSTERY;

    for (u32 j = 0; j < 3; j++)
    {
        u32 traitIndex = GetBoxMonData(boxmon, MON_DATA_TRAIT_INDEX1 + j);
        if (traitList[traitIndex].type == EXTRA_TYPE)
            return traitList[traitIndex].arg1;
    }

    return TYPE_MYSTERY;
}

enum Type GetBoxMonExtraImmunity(struct BoxPokemon *boxmon)
{
    const struct TarcTrait *traitList = GetSpeciesTraitList(boxmon);
    if (!traitList)
        return TYPE_NONE;
    for (u32 j = 0; j < 3; j++)
    {
        u32 traitIndex = GetBoxMonData(boxmon, MON_DATA_TRAIT_INDEX1 + j);
        if (traitList[traitIndex].type == EXTRA_IMMUNITY)
            return traitList[traitIndex].arg1;
    }
    return TYPE_NONE;
}

u32 GetBoxMonExtraStat(struct BoxPokemon *boxmon, enum Stat stat)
{
    const struct TarcTrait *traitList = GetSpeciesTraitList(boxmon);
    if (!traitList)
        return 0;

    u32 extraStat = 0;
    for (u32 j = 0; j < 3; j++)
    {
        u32 traitIndex = GetBoxMonData(boxmon, MON_DATA_TRAIT_INDEX1 + j);
        if (traitList[traitIndex].type == EXTRA_STAT && traitList[traitIndex].arg1 == stat)
        {
            extraStat +=traitList[traitIndex].arg2;
        }
        else if (traitList[traitIndex].type == ALL_STAT_BONUS)
        {
            extraStat += traitList[traitIndex].arg1;
        }
        else if (traitList[traitIndex].type == EXTRA_STAT_DRAWBACK)
        {
            if (traitList[traitIndex].arg1 == stat)
                extraStat += traitList[traitIndex].arg3 * 2;
            else if (traitList[traitIndex].arg2 == stat)
                extraStat += traitList[traitIndex].arg3 * (-1);
        }
    }
    return extraStat;
}

void CopyTraitString(u8 *str, const struct TarcTrait *trait)
{
    switch (trait->type)
    {
        case EXTRA_TYPE:
            StringCopy(gStringVar2, gTypesInfo[trait->arg1].name);
            StringExpandPlaceholders(str, COMPOUND_STRING("{STR_VAR_2} type"));
            break;
        case EXTRA_STAT:
            ConvertIntToDecimalStringN(gStringVar2, trait->arg2, STR_CONV_MODE_LEFT_ALIGN, 2);
            StringCopy(gStringVar3, gStatNamesTable[trait->arg1]);
            StringExpandPlaceholders(str, COMPOUND_STRING("+{STR_VAR_2} {STR_VAR_3}"));
            break;
        case ALL_STAT_BONUS:
            ConvertIntToDecimalStringN(gStringVar2, trait->arg1, STR_CONV_MODE_LEFT_ALIGN, 2);
            StringExpandPlaceholders(str, COMPOUND_STRING("+{STR_VAR_2} All Stats"));
            break;
        case EXTRA_STAT_DRAWBACK:
            ConvertIntToDecimalStringN(gStringVar2, trait->arg3 * 2, STR_CONV_MODE_RIGHT_ALIGN, 2);
            StringCopy(gStringVar3, gShortenStatTable[trait->arg1]);
            StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("+{STR_VAR_2} {STR_VAR_3}"));
            ConvertIntToDecimalStringN(gStringVar2, trait->arg3, STR_CONV_MODE_LEFT_ALIGN, 2);
            StringCopy(gStringVar3, gShortenStatTable[trait->arg2]);
            StringExpandPlaceholders(str, COMPOUND_STRING("{STR_VAR_1} - {STR_VAR_2} {STR_VAR_3}"));
            break;
        case EXTRA_IMMUNITY:
            StringCopy(gStringVar2, gTypesInfo[trait->arg1].name);
            StringExpandPlaceholders(str, COMPOUND_STRING("{STR_VAR_2} Immunity"));
            break;
        case NULL_MOD:
            StringCopy(str, COMPOUND_STRING(""));
            break;
    }
}

static EWRAM_DATA u8 sRandomlySelectedTraits[3];

void GetThreeRandomTraits()
{
    struct BoxPokemon *boxmon = GetSelectedBoxMonFromPcOrParty();
    const struct TarcTrait *traitList = GetSpeciesTraitList(boxmon);
    assertf(traitList, "No trait list for selected pokemon")
    {
        return;
    }

    u32 size = 1;
    for (u32 i = 1; traitList[i].type != NULL_MOD; i++)
    {
        size++;
    }
    enum Type extraType = GetBoxMonExtraType(boxmon);
    enum Type extraImmunity = GetBoxMonExtraImmunity(boxmon);
    u8 mods[3];
    for (u32 j = 0; j < 3; j++)
    {
        mods[j] = GetBoxMonData(boxmon, MON_DATA_TRAIT_INDEX1 + j);
    }
    u8 *weights = AllocZeroed(size);
    for (u32 i = 1; traitList[i].type != NULL_MOD; i++)
    {
        if (mods[0] == i || mods[1] == i || mods[2] == i)
            weights[i] = 0;
        else if (extraType != TYPE_MYSTERY && traitList[i].type == EXTRA_TYPE)
            weights[i] = 0;
        else if (extraImmunity != TYPE_NONE && traitList[i].type == EXTRA_IMMUNITY)
            weights[i] = 0;
        else
            weights[i] = 1;
    }

    u8 modString[3][50];
    for (u32 j = 0; j < 3; j++)
    {
        u32 randomTrait = RandomWeightedIndex(weights, size);
        weights[randomTrait] = 0;
        sRandomlySelectedTraits[j] = randomTrait;
        CopyTraitString(modString[j], &traitList[randomTrait]);
    }
    StringCopy(gStringVar1, modString[0]);
    StringCopy(gStringVar2, modString[1]);
    StringCopy(gStringVar3, modString[2]);
    Free(weights);
}

void AddNewMod(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];
    u32 ability = gSpecialVar_Result;
    for (u32 i = 0; i < 3; i++)
    {
        if (GetMonData(mon, MON_DATA_TRAIT_INDEX1 + i) == 0)
        {
            SetMonData(mon, MON_DATA_TRAIT_INDEX1 + i, &sRandomlySelectedTraits[gSpecialVar_Result]);
            CalculateMonStats(mon);
            return;
        }
    }
}

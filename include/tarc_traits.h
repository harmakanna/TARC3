#ifndef GUARD_TARC_TRAITS_H
#define GUARD_TARC_TRAITS_H

enum TraitType
{
    NULL_MOD,
    EXTRA_TYPE,
    EXTRA_STAT,
    ALL_STAT_BONUS,
    EXTRA_STAT_DRAWBACK,
    EXTRA_IMMUNITY,
};

struct TarcTrait
{
    enum TraitType type;
    s16 arg1;
    s16 arg2;
    s16 arg3;
};

const struct TarcTrait *GetBoxMonTrait(struct BoxPokemon *boxmon, u32 traitIndex);
enum Type GetBoxMonExtraType(struct BoxPokemon *boxmon);
enum Type GetBoxMonExtraImmunity(struct BoxPokemon *boxmon);
u32 GetBoxMonExtraStat(struct BoxPokemon *boxmon, enum Stat stat);
void CopyTraitString(u8 *str, const struct TarcTrait *trait);

#endif // GUARD_TARC_TRAITS_H

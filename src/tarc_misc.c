#include "global.h"

const u8 gSophieName[] = _("Sophie");
const u8 gDigitalSophieName[] = _("SoPhi99");

bool32 IsInVirtualWorld(void)
{
    return (gSaveBlock1Ptr->location.mapGroup == 0);
}

const u8 *GetPlayerName(void)
{
    if (IsInVirtualWorld())
        return gDigitalSophieName;
    else
        return gSophieName;
}

void CloneFirstMon(void)
{
    memcpy(&gParties[B_TRAINER_PLAYER][1], &gParties[B_TRAINER_PLAYER][0], sizeof(struct Pokemon));
}

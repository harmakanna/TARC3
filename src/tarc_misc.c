#include "global.h"

const u8 gSophieName[] = _("Sophie");
const u8 gDigitalSophieName[] = _("Trinity");

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
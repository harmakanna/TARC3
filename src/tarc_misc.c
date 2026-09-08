#include "global.h"
#include "event_data.h"

const u8 gSophieName[] = _("Sophie");
const u8 gDigitalSophieName[] = _("SoPhi99");

bool32 IsInVirtualWorld(void)
{
    return (gSaveBlock1Ptr->location.mapGroup == 0);
}


bool32 IsInWorkplace(void)
{
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_VIRTUAL_CITY_WORK_YOUR_OFFICE)
        ||gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_VIRTUAL_CITY_COMMS_TOWER_RESEARCH)
        ||(gSaveBlock1Ptr->location.mapNum >= MAP_NUM(MAP_VIRTUAL_CITY_COMMS_TOWER_1F) && gSaveBlock1Ptr->location.mapNum <= MAP_NUM(MAP_VIRTUAL_CITY_COMMS_TOWER_TOP_F)))
    {
        if(!FlagGet(FLAG_SPOOFING_EXECUTIVE))
            return TRUE;
    }
    return FALSE;
}

const u8 *GetPlayerName(void)
{
    if (IsInVirtualWorld() && !IsInWorkplace())
        return gDigitalSophieName;
    else
        return gSophieName;
}

void CloneFirstMon(void)
{
    memcpy(&gParties[B_TRAINER_PLAYER][1], &gParties[B_TRAINER_PLAYER][0], sizeof(struct Pokemon));
}

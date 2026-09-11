#include "global.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "palette.h"
#include "task.h"
#include "constants/rgb.h"

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

void StartBlueScreen(void)
{
    CpuFill16(RGB_BLUE, gPlttBufferFaded, PLTT_SIZE);
}

#define FADE_TIME 180
#define WAIT_TIME 150

void Task_FadeTitleOnMap(u8 taskId)
{
    //DebugPrintf("Task_FadeTitleOnMap");
    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[1]++;
        u32 fadeValue = gTasks[taskId].data[1] * 15 / FADE_TIME;
        //DebugPrintf("fadeValue %d", fadeValue);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(fadeValue, 15 - fadeValue));
        if (gTasks[taskId].data[1] == FADE_TIME)
        {
            gTasks[taskId].data[0]++;
            gTasks[taskId].data[1] = 0;
        }
    }
    else if (gTasks[taskId].data[0] == 1)
    {
        if (gTasks[taskId].data[1]++ == WAIT_TIME)
        {
            DoWarp();
        }
    }
}

#include "global.h"

bool32 IsInVirtualWorld(void)
{
    return (gSaveBlock1Ptr->location.mapGroup == 0);
}
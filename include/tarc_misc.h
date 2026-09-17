#ifndef GUARD_TARC3_MISC_H
#define GUARD_TARC3_MISC_H

extern const u8 gSophieName[];
extern const u8 gDigitalSophieName[];

bool32 IsInVirtualWorld(void);
bool32 IsInWorkplace(void);
const u8 *GetPlayerName(void);
void Task_FadeTitleOnMap(u8 taskId);
bool32 IsInPreBattleRoom(void);

#endif
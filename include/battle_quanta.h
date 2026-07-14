#include "constants/battle.h"
#define MAX_QUANTAS_PER_ACTION 10

extern EWRAM_DATA struct QuantaBehavior gUpcomingQuanta[MAX_BATTLERS_COUNT][MAX_QUANTAS_PER_ACTION];

bool32 InQuantaMode(void);
bool32 CanBattlerChooseActionThisQuanta(enum BattlerId battlerIndex);
void AdvanceQuantaCounter(void);
void PrepareUpcomingQuanta(enum BattlerId battler);
void GetQuantaBattleOrder(void);
void HandleAction_PrepareQuanta(void);
const struct QuantaBehavior *GetQuantaBehavior(enum Move move);

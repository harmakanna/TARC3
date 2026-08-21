#include "global.h"
#include "battle.h"
#include "battle_quanta.h"
#include "battle_scripts.h"
#include "battle_stat_change.h"
#include "move.h"
#include "tarc_misc.h"

extern const u8 *const gBattlescriptsForUsingItem[];
EWRAM_DATA struct QuantaBehavior gUpcomingQuanta[MAX_BATTLERS_COUNT][MAX_QUANTAS_PER_ACTION] = {0};
static EWRAM_DATA u16 sActiveActions[MAX_BATTLERS_COUNT] = {0};

bool32 InQuantaMode(void)
{
    if (TESTING)
        return FALSE;
    return IsInVirtualWorld();
}


bool32 CanBattlerChooseActionThisQuanta(enum BattlerId battler)
{
    return (gUpcomingQuanta[battler][0].type == QUANTA_TYPE_END);
}

static void BattlerEndOfQuantaMoveResolution(enum BattlerId battler)
{
    if (sActiveActions[battler] == MOVE_PROTECT && gBattleMons[battler].quantaVolatiles.consecutiveProtects != 7)
    {
        if (gBattleMons[battler].quantaVolatiles.consecutiveProtects < 3)
            gBattleMons[battler].quantaVolatiles.consecutiveProtects++;
    }
    else
        gBattleMons[battler].quantaVolatiles.consecutiveProtects = 0;
}

void AdvanceQuantaCounter(void)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        for (u32 j = 0; j < MAX_QUANTAS_PER_ACTION - 1; j++)
        {
            gUpcomingQuanta[i][j] = gUpcomingQuanta[i][j + 1];
        }

        if (gUpcomingQuanta[i][0].type == QUANTA_TYPE_END)
            BattlerEndOfQuantaMoveResolution(i);
    }
}

const struct QuantaBehavior *GetQuantaBehavior(enum Move move)
{
    if (gMovesInfo[move].quantaBehavior)
        return gMovesInfo[move].quantaBehavior;

    switch (GetMoveEffect(move))
    {
        case EFFECT_HIT:
            if (IsMultiHitMove(move))
                return gEffectMultiHitQuantaBehavior;
            else if (GetMoveStrikeCount(move) == 2)
                return gEffect2HitQuantaBehavior;
            else if (GetMoveStrikeCount(move) == 3)
                return gEffect3HitQuantaBehavior;
            else if (GetMovePriority(move) == 1)
                return gEffectFastHitQuantaBehavior;
            else if (GetMovePriority(move) == 2)
                return gEffectFasterHitQuantaBehavior;
            else if (IsExplosionMove(move))
                return gEffectExplosionQuantaBehavior;
            else
                return gEffectHitQuantaBehavior;
        case EFFECT_SEMI_INVULNERABLE:
            return gEffectSemiInvulnerableQuantaBehavior;
        case EFFECT_RECHARGE:
            return gEffectRechargeQuantaBehavior;
        case EFFECT_NON_VOLATILE_STATUS:
            return gEffectNonVolatileQuantaBehavior;
        case EFFECT_STAT_CHANGE:
            return gEffectStatChangeQuantaBehavior;
        case EFFECT_CONTINUOUS:
            return gEffectContinuousQuantaBehavior;
        case EFFECT_PROTECT:
            return gEffectProtectQuantaBehavior;
        default:
            return gBuggedMoveQuantaBehavior;
    }
}

void PrepareUpcomingQuanta(enum BattlerId battler)
{
    switch(gChosenActionByBattler[battler]) {
        case B_ACTION_SWITCH:
            gUpcomingQuanta[battler][0].script = BattleScript_ActionSwitch;
            gUpcomingQuanta[battler][0].type = QUANTA_TYPE_SWITCH;
            sActiveActions[battler] = 0;
            break;
        case B_ACTION_USE_ITEM: 
            gUpcomingQuanta[battler][0].script = gBattlescriptsForUsingItem[GetItemBattleUsage(gLastUsedItem) - 1];
            gUpcomingQuanta[battler][0].type = QUANTA_TYPE_ITEM;
            sActiveActions[battler] = gLastUsedItem;
            break;
        case B_ACTION_USE_MOVE:
            sActiveActions[battler] = GetBattlerChosenMove(battler);
            const struct QuantaBehavior *moveBehavior =  GetQuantaBehavior(GetBattlerChosenMove(battler));
            for (u32 i = 0; i < MAX_QUANTAS_PER_ACTION; i++)
            {
                if (!moveBehavior[i].script)
                    break;
                gUpcomingQuanta[battler][i].script = moveBehavior[i].script;
                gUpcomingQuanta[battler][i].type = moveBehavior[i].type;
            }
            break;
    }
}

void GetQuantaBattleOrder(void)
{
    u32 turnOrderId = 0;
    for (enum QuantaType type = 0; type <= QUANTA_TYPE_PASS; type++)
    {
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        {
            if (gUpcomingQuanta[battler][0].type == type)
            {
                gBattlerByTurnOrder[turnOrderId] = battler;
                gActionsByTurnOrder[turnOrderId] = B_ACTION_QUANTA;
                turnOrderId++;
            }
        }
    }
    struct BattleCalcValues calcValues = {0};
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        calcValues.abilities[battler] = GetBattlerAbility(battler);
        calcValues.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }
    for (u32 i = 0; i < gBattlersCount - 1; i++)
    {
        for (u32 j = i + 1; j < gBattlersCount; j++)
        {
            calcValues.battlerAtk = gBattlerByTurnOrder[i];
            calcValues.battlerDef = gBattlerByTurnOrder[j];

            if (GetWhichBattlerFaster(&calcValues, TRUE) == -1)
                SwapTurnOrder(i, j);
        }
    }
}

void HandleAction_PrepareQuanta(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    if (gAbsentBattlerFlags & 1u << gBattlerAttacker
     || gBattleStruct->battlerState[gBattlerAttacker].commandingDondozo
     || !IsBattlerAlive(gBattlerAttacker))
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }

    switch (gUpcomingQuanta[gBattlerAttacker][0].type)
    {
        case QUANTA_TYPE_ITEM:
            gLastUsedItem = sActiveActions[gBattlerAttacker];
            break;
        case QUANTA_TYPE_SWITCH:
            gBattle_BG0_X = 0;
            gBattle_BG0_Y = 0;
            gActionSelectionCursor[gBattlerAttacker] = 0;
            gMoveSelectionCursor[gBattlerAttacker] = 0;

            PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattleStruct->battlerPartyIndexes[gBattlerAttacker]);

            gBattleScripting.battler = gBattlerAttacker;

            if (gBattleResults.playerSwitchesCounter < 255)
                gBattleResults.playerSwitchesCounter++;

            TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_SWITCH_OUT, GetBattlerAbility(gBattlerAttacker));
            break;
        default:
            gCurrentMove = gChosenMove = sActiveActions[gBattlerAttacker];
            gBattlerTarget = gBattleStruct->moveTarget[gBattlerAttacker];
            gBattleStruct->eventState.atkCanceler = 0;
            ClearDamageCalcResults();
            ClearBothStatChangeQueues();
            gMultiHitCounter = 0;
            gBattleCommunication[MISS_TYPE] = 0;
            break;
    }

    gBattlescriptCurrInstr = gUpcomingQuanta[gBattlerAttacker][0].script;
    //DebugPrintf("StartQuantaScript %d %d", gUpcomingQuanta[gBattlerAttacker][0].type, gBattlescriptCurrInstr[0]);
    //DebugPrintf("%d %d", gBattlerAttacker, gBattlerTarget);
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

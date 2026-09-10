VirtualCity_Stadium_Arena_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VirtualCity_Stadium_Arena_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Stadium_Arena_OnFrame
	@map_script MAP_SCRIPT_ON_RESUME, VirtualCity_Stadium_Arena_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, VirtualCity_Stadium_Arena_OnReturn
	.byte 0

VirtualCity_Stadium_Arena_OnReturn:
	call VirtualCity_Stadium_Arena_EventScript_AddAudience
	end

VirtualCity_Stadium_Arena_OnWarp:
	map_script_2 VAR_ALWAYS_ZERO, 0, VirtualCity_Stadium_Arena_EventScript_SetUpObjects
	.2byte 0
	
VirtualCity_Stadium_Arena_OnFrame:
	map_script_2 VAR_ALWAYS_ZERO, 0, VirtualCity_Stadium_Arena_EventScript_SetUpFight
	.2byte 0

VirtualCity_Stadium_Arena_OnResume:
	call_if_eq VAR_TEMP_9, 1, VirtualCity_Stadium_Arena_EventScript_CallAddAudience
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_SetModFlag
	clearflag FLAG_IN_ARENA
	end

VirtualCity_Stadium_Arena_EventScript_CallAddAudience::
	call VirtualCity_Stadium_Arena_EventScript_AddAudience
	return

VirtualCity_Stadium_Arena_EventScript_SetUpObjects::
	call VirtualCity_Stadium_Arena_EventScript_AddAudience
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_PLAYER, Movement_SetInvisible
	end

@ Add audience members to supplement the permanent object event audience
VirtualCity_Stadium_Arena_EventScript_AddAudience::
	call_if_set FLAG_ACT_II_WON_RANDO3, VirtualCity_Stadium_Arena_SetVarE1
	call_if_set FLAG_ACT_II_WON_BRODUDE, VirtualCity_Stadium_Arena_SetVarE2
	call_if_set FLAG_ACT_II_WON_EARL_GRAY, VirtualCity_Stadium_Arena_SetVarE3
	call VirtualCity_Stadium_Arena_EventScript_AddRound1Audience
	call_if_eq VAR_TEMP_E, 1, VirtualCity_Stadium_Arena_EventScript_AddRound2Audience
	call_if_eq VAR_TEMP_E, 2, VirtualCity_Stadium_Arena_EventScript_AddSemifinalAudience
	call_if_eq VAR_TEMP_E, 3, VirtualCity_Stadium_Arena_EventScript_AddFinalAudience
	return

VirtualCity_Stadium_Arena_SetVarE1::
	setvar VAR_TEMP_E, 1
	return

VirtualCity_Stadium_Arena_SetVarE2::
	setvar VAR_TEMP_E, 2
	return
	
VirtualCity_Stadium_Arena_SetVarE3::
	setvar VAR_TEMP_E, 3
	return

VirtualCity_Stadium_Arena_EventScript_AddRound1Audience::
	createvobject OBJ_EVENT_GFX_PIKACHU, 1, 8, 1
	createvobject OBJ_EVENT_GFX_FAT_MAN, 4, 12, 1
	createvobject OBJ_EVENT_GFX_JUAN, 7, 16, 1
	createvobject OBJ_EVENT_GFX_ZIGZAGOON_1, 9, 4, 2
	createvobject OBJ_EVENT_GFX_TWIN, 12, 7, 2
	createvobject OBJ_EVENT_GFX_FOSSIL, 35, 9, 2
	createvobject OBJ_EVENT_GFX_RED, 20, 10, 2
	createvobject OBJ_EVENT_GFX_DEOXYS_TRIANGLE, 35, 13, 2
	createvobject OBJ_EVENT_GFX_KIRLIA, 10, 14, 2
	createvobject OBJ_EVENT_GFX_DUSCLOPS, 22, 15, 2
	return

VirtualCity_Stadium_Arena_EventScript_AddRound2Audience::
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
	createvobject OBJ_EVENT_GFX_QUINTY_PLUMP, 4, 6, 0
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0
	createvobject OBJ_EVENT_GFX_TWIN, 9, 11, 0
	createvobject OBJ_EVENT_GFX_PIKACHU, 11, 13, 0
	createvobject OBJ_EVENT_GFX_RED, 13, 15, 0
	createvobject OBJ_EVENT_GFX_SWABLU_DOLL, 35, 7, 1
	createvobject OBJ_EVENT_GFX_ZIGZAGOON_1, 22, 11, 1
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1
	createvobject OBJ_EVENT_GFX_EXPERT_M, 7, 5, 2
	createvobject OBJ_EVENT_GFX_KIRLIA, 26, 2, 2
	createvobject OBJ_EVENT_GFX_SUDOWOODO, 35, 5, 1
	return

VirtualCity_Stadium_Arena_EventScript_AddSemifinalAudience::
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0
	createvobject OBJ_EVENT_GFX_PIKACHU, 4, 6, 0
	createvobject OBJ_EVENT_GFX_FOSSIL, 35, 8, 0
	createvobject OBJ_EVENT_GFX_KECLEON, 7, 9, 0
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0
	createvobject OBJ_EVENT_GFX_FOSSIL, 35, 12, 0
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
	createvobject OBJ_EVENT_GFX_PIKACHU, 13, 15, 0
	createvobject OBJ_EVENT_GFX_QUINTY_PLUMP, 15, 2, 1
	createvobject OBJ_EVENT_GFX_UNUSED_PORYGON2_DOLL, 35, 3, 1
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1
	createvobject OBJ_EVENT_GFX_DEOXYS_TRIANGLE, 35, 9, 1
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1
	createvobject OBJ_EVENT_GFX_QUINTY_PLUMP, 23, 13, 1
	createvobject OBJ_EVENT_GFX_RED, 25, 15, 1
	createvobject OBJ_EVENT_GFX_RED, 26, 2, 2
	createvobject OBJ_EVENT_GFX_MR_BRINEYS_BOAT, 29, 5, 1
	createvobject OBJ_EVENT_GFX_PHOEBE, 30, 6, 2
	createvobject OBJ_EVENT_GFX_WINGULL, 31, 8, 2
	createvobject OBJ_EVENT_GFX_EXPERT_M, 7, 5, 2
	return

VirtualCity_Stadium_Arena_EventScript_AddFinalAudience::
	createvobject OBJ_EVENT_GFX_AZURILL, 0, 2, 0
	createvobject OBJ_EVENT_GFX_STEVEN, 1, 3, 0
	createvobject OBJ_EVENT_GFX_RED, 2, 15, 0
	createvobject OBJ_EVENT_GFX_PIKACHU, 3, 5, 0
	createvobject OBJ_EVENT_GFX_KECLEON, 4, 6, 0
	createvobject OBJ_EVENT_GFX_SCIENTIST_2, 5, 7, 0
	createvobject OBJ_EVENT_GFX_BRAWLY, 6, 8, 0
	createvobject OBJ_EVENT_GFX_QUINTY_PLUMP, 7, 9, 0
	createvobject OBJ_EVENT_GFX_DUSCLOPS, 8, 10, 0
	createvobject OBJ_EVENT_GFX_SS_TIDAL, 35, 11, 0
	createvobject OBJ_EVENT_GFX_SUDOWOODO, 35, 12, 0
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0
	createvobject OBJ_EVENT_GFX_MR_BRINEYS_BOAT, 12, 14, 0
	createvobject OBJ_EVENT_GFX_LATIOS, 35, 12, 2
	createvobject OBJ_EVENT_GFX_ROXANNE, 15, 2, 1
	createvobject OBJ_EVENT_GFX_WINGULL, 16, 3, 1
	createvobject OBJ_EVENT_GFX_RED, 17, 4, 1
	createvobject OBJ_EVENT_GFX_KECLEON, 18, 3, 2
	createvobject OBJ_EVENT_GFX_LATIAS, 35, 7, 1
	createvobject OBJ_EVENT_GFX_UNUSED_PORYGON2_DOLL, 35, 9, 1
	createvobject OBJ_EVENT_GFX_KIRLIA, 21, 10, 1
	createvobject OBJ_EVENT_GFX_MR_BRINEYS_BOAT, 22, 11, 1
	createvobject OBJ_EVENT_GFX_MAXIE, 23, 13, 1
	createvobject OBJ_EVENT_GFX_HOOH, 35, 14, 1
	createvobject OBJ_EVENT_GFX_SKITTY, 25, 15, 1
	createvobject OBJ_EVENT_GFX_SUDOWOODO, 35, 2, 2
	createvobject OBJ_EVENT_GFX_RAYQUAZA, 35, 3, 2
	createvobject OBJ_EVENT_GFX_QUINTY_PLUMP, 29, 5, 1
	createvobject OBJ_EVENT_GFX_FOSSIL, 35, 6, 2
	createvobject OBJ_EVENT_GFX_AZURILL, 31, 8, 2
	createvobject OBJ_EVENT_GFX_PIKACHU, 7, 5, 2
	return

VirtualCity_Stadium_Arena_EventScript_AudienceLookAround::
	turnvobject 0, DIR_EAST
	turnvobject 2, DIR_EAST
	turnvobject 4, DIR_EAST
	turnvobject 6, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 10, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 14, DIR_WEST
	turnvobject 16, DIR_WEST
	turnvobject 18, DIR_WEST
	turnvobject 20, DIR_EAST
	turnvobject 22, DIR_EAST
	turnvobject 24, DIR_EAST
	turnvobject 26, DIR_EAST
	turnvobject 28, DIR_EAST
	turnvobject 30, DIR_EAST
	delay 20
	turnvobject 0, DIR_SOUTH
	turnvobject 2, DIR_SOUTH
	turnvobject 4, DIR_SOUTH
	turnvobject 6, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 16, DIR_SOUTH
	turnvobject 18, DIR_SOUTH
	turnvobject 20, DIR_SOUTH
	turnvobject 22, DIR_SOUTH
	turnvobject 24, DIR_SOUTH
	turnvobject 26, DIR_SOUTH
	turnvobject 28, DIR_SOUTH
	turnvobject 30, DIR_SOUTH
	delay 20
	turnvobject 1, DIR_EAST
	turnvobject 3, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 9, DIR_EAST
	turnvobject 11, DIR_WEST
	turnvobject 13, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 17, DIR_WEST
	turnvobject 19, DIR_WEST
	turnvobject 21, DIR_EAST
	turnvobject 23, DIR_EAST
	turnvobject 25, DIR_EAST
	turnvobject 27, DIR_WEST
	turnvobject 31, DIR_WEST
	delay 20
	turnvobject 1, DIR_SOUTH
	turnvobject 3, DIR_SOUTH
	turnvobject 5, DIR_SOUTH
	turnvobject 7, DIR_SOUTH
	turnvobject 9, DIR_SOUTH
	turnvobject 11, DIR_SOUTH
	turnvobject 13, DIR_SOUTH
	turnvobject 15, DIR_SOUTH
	turnvobject 17, DIR_SOUTH
	turnvobject 19, DIR_SOUTH
	turnvobject 21, DIR_SOUTH
	turnvobject 23, DIR_SOUTH
	turnvobject 25, DIR_SOUTH
	turnvobject 27, DIR_SOUTH
	turnvobject 31, DIR_SOUTH
	delay 20
	return

VirtualCity_Stadium_Arena_EventScript_SetUpFight::
	special SavePlayerParty
	callnative ChooseVGCParty
	waitstate
	special ReducePlayerPartyToSelectedMons
	@fadescreen FADE_FROM_BLACK
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	setvar VAR_WALK_DOWN_IN_VIRTUAL_PREBATTLE_ROOM, 1
	call VirtualCity_Stadium_Arena_EventScript_Announcer
	playse SE_M_ENCORE2
	call VirtualCity_Stadium_Arena_EventScript_AudienceLookAround
	setflag FLAG_IN_ARENA
	waitmovement 0
	applymovement LOCALID_CUTSCENE_SOPHIE, VirtualCity_Stadium_Arena_Movement_SophieWalksToPosition
	goto_if_eq VAR_PETALBURG_CITY_STATE, 23, VirtualCity_Stadium_Arena_Eventscript_Rando1Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 24, VirtualCity_Stadium_Arena_Eventscript_Rando2Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 25, VirtualCity_Stadium_Arena_Eventscript_Rando3Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 26, VirtualCity_Stadium_Arena_Eventscript_Rando4Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 27, VirtualCity_Stadium_Arena_Eventscript_Rando5Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 28, VirtualCity_Stadium_Arena_Eventscript_BrodudeFight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 29, VirtualCity_Stadium_Arena_Eventscript_WvddieFight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 30, VirtualCity_Stadium_Arena_Eventscript_SilvaBulletFight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 31, VirtualCity_Stadium_Arena_Eventscript_EarlGreyFight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_Arena_Eventscript_ByronB1Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 35, VirtualCity_Stadium_Arena_Eventscript_ByronB2Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 37, VirtualCity_Stadium_Arena_Eventscript_ByronB3Fight
	end

VirtualCity_Stadium_Arena_Movement_PositionCameraToCenter:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

VirtualCity_Stadium_Arena_Movement_SophieWalksToPosition:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

@ Extra Speakers

Speaker_Challenger::
	.string "Challenger$"

Speaker_BroDude69::
	.string "BroDude69$"

Speaker_Wvddie::
	.string "WVDDIE$"

Speaker_SilvaBullet::
	.string "SilvaBullet$"

Speaker_EarlGrey::
	.string "Earl Grey$"

Common_Text_NotEnoughPokemon::
	.string "Bug! Error code: 0x000071$"

VirtualCity_Stadium_Arena_Eventscript_Rando1Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO1
	applymovement LOCALID_RANDO1, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_RANDO1, VirtualCity_Stadium_Arena_Text_Rando1Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	setvar VAR_TEMP_9, 1
	@trainerbattle_double TRAINER_RANDO1, NULL, VirtualCity_Stadium_Arena_Text_Rando1Win, Common_Text_NotEnoughPokemon
	trainerbattle_no_intro TRAINER_RANDO1, VirtualCity_Stadium_Arena_Text_Rando1Win
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty
	
	call VirtualCity_Stadium_Arena_EventScript_WonMatch
	
	applymovement LOCALID_RANDO1, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0

	setflag FLAG_ACT_II_FOUGHT_RANDO1
	setvar VAR_PETALBURG_CITY_STATE, 24

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_Rando2Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO2
	applymovement LOCALID_RANDO2, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_RANDO2, VirtualCity_Stadium_Arena_Text_Rando2Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_RANDO2, VirtualCity_Stadium_Arena_Text_Rando2Win
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_RANDO2, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	setflag FLAG_ACT_II_FOUGHT_RANDO2
	setvar VAR_PETALBURG_CITY_STATE, 25

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_Rando3Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO3
	applymovement LOCALID_RANDO3, VirtualCity_Stadium_Arena_Move_CommonApproachArenaSlow
	waitmovement 0
	speak LOCALID_RANDO3, VirtualCity_Stadium_Arena_Text_Rando3Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_RANDO3, VirtualCity_Stadium_Arena_Text_Rando3Win
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	setflag FLAG_ACT_II_WON_RANDO3

	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_RANDO3, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0	
	setflag FLAG_ACT_II_FOUGHT_RANDO3
	setvar VAR_PETALBURG_CITY_STATE, 26

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_Rando4Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO4
	applymovement LOCALID_RANDO4, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_RANDO4, VirtualCity_Stadium_Arena_Text_Rando4Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_RANDO4, VirtualCity_Stadium_Arena_Text_Rando4Win
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_RANDO4, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_RANDO4
	setvar VAR_PETALBURG_CITY_STATE, 27

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_Rando5Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO5
	applymovement LOCALID_RANDO5, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_RANDO5, VirtualCity_Stadium_Arena_Text_Rando5Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_RANDO5, VirtualCity_Stadium_Arena_Text_Rando5Win
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty
	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_RANDO5, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_RANDO5
	setflag FLAG_ACT_II_HIDE_ERNEST_PREBATTLE
	setvar VAR_PETALBURG_CITY_STATE, 28

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_SetModFlag::
	setflag FLAG_ACT_II_MOD_INSTALLED
	return
	
VirtualCity_Stadium_Arena_Eventscript_LostSilver::

	setvar VAR_TEMP_9, 0
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_AnnounceLoss, Speaker_Announcer, DIR_SOUTH
	playse SE_M_ENCORE2
	call VirtualCity_Stadium_Arena_EventScript_AudienceLookAround
	waitse
	@TOFOLD
	special HealPlayerParty
	special LoadPlayerParty

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end





VirtualCity_Stadium_Arena_Eventscript_BrodudeFight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_BRODUDE
	applymovement LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Text_BroDudeIntro, Speaker_BroDude69, DIR_WEST

	setspeaker Speaker_BroDude69
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_BRODUDE, VirtualCity_Stadium_Arena_Text_BroDudeWin
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostGold
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	setflag FLAG_ACT_II_WON_BRODUDE
	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_BRODUDE
	setvar VAR_PETALBURG_CITY_STATE, 29

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_WvddieFight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_WVDDIE
	applymovement LOCALID_WVDDIE, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_WVDDIE, VirtualCity_Stadium_Arena_Text_WvddieIntro, Speaker_Wvddie, DIR_WEST

	setspeaker Speaker_Wvddie
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_WVDDIE, VirtualCity_Stadium_Arena_Text_WvddieWin
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostGold
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_WVDDIE, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_WVDDIE
	setvar VAR_PETALBURG_CITY_STATE, 30

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_SilvaBulletFight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_SILVABULLET
	applymovement LOCALID_SILVABULLET, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_SILVABULLET, VirtualCity_Stadium_Arena_Text_SilvaBulletIntro, Speaker_SilvaBullet, DIR_WEST

	setspeaker Speaker_SilvaBullet
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_SILVABULLET, VirtualCity_Stadium_Arena_Text_SilvaBulletWin
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostGold
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_SILVABULLET, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_SILVABULLET
	setvar VAR_PETALBURG_CITY_STATE, 31

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_EarlGreyFight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_EARLGREY
	applymovement LOCALID_EARLGREY, VirtualCity_Stadium_Arena_Move_CommonApproachArenaSlow
	waitmovement 0
	speak LOCALID_EARLGREY, VirtualCity_Stadium_Arena_Text_EarlGreyIntro, Speaker_EarlGrey, DIR_WEST

	setspeaker Speaker_EarlGrey
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_EARLGREY, VirtualCity_Stadium_Arena_Text_EarlGreyWin
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostGold
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostGold
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty
	setflag FLAG_ACT_II_WON_EARL_GRAY

	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_EARLGREY, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_EARLGREY
	setvar VAR_PETALBURG_CITY_STATE, 32

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_LostGold::
	setvar VAR_TEMP_9, 0
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_AnnounceLoss, Speaker_Announcer, DIR_SOUTH
	playse SE_M_ENCORE2
	call VirtualCity_Stadium_Arena_EventScript_AudienceLookAround
	waitse
	@TOFOLD
	special HealPlayerParty
	special LoadPlayerParty

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_ByronB1Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_BYRON
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_ByronApproachArena1
	waitmovement 0
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB1Intro1, Speaker_Byron, DIR_NORTH
	closemessage
	playse SE_M_ENCORE2
	call VirtualCity_Stadium_Arena_EventScript_AudienceLookAround
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_ByronApproachArena2
	waitmovement 0
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB1Intro2, Speaker_Byron, DIR_WEST

	setspeaker Speaker_Byron
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_BYRON1, VirtualCity_Stadium_Arena_Text_ByronB1Win
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostByronB1
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostByronB1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostByronB1
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostByronB1
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	call VirtualCity_Stadium_Arena_EventScript_WonMatch
	
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_BYRONB1
	setflag FLAG_ACT_II_WON_BYRONB1
	setvar VAR_PETALBURG_CITY_STATE, 34

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_ByronB2Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	goto_if_set FLAG_ACT_II_WON_BYRONB1, VirtualCity_Stadium_Arena_Eventscript_ByronB2FightWinner
	addobject LOCALID_BYRON
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB2YouLostIntro, Speaker_Byron, DIR_WEST

	setspeaker Speaker_Byron
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_BYRON2, VirtualCity_Stadium_Arena_Text_ByronB2YouLostWin
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostByronB2
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostByronB2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostByronB2
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostByronB2
	setvar VAR_TEMP_9, 0
	@speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB2YouLostLose, Speaker_Byron, DIR_WEST
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty
	
	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_BYRONB2
	setvar VAR_PETALBURG_CITY_STATE, 36

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_ByronB2FightWinner::
	addobject LOCALID_BYRON
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB2YouWonIntro, Speaker_Byron, DIR_WEST

	setspeaker Speaker_Byron
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_BYRON2, VirtualCity_Stadium_Arena_Text_ByronB2YouWonWin
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostByronB2AfterWin
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostByronB2AfterWin
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostByronB2AfterWin
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostByronB2AfterWin
	setvar VAR_TEMP_9, 0
	@speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB2YouWonLose, Speaker_Byron, DIR_WEST
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_BYRONB2
	@setvar VAR_PETALBURG_CITY_STATE, 36

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_ByronB3Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_BYRON
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB3Intro, Speaker_Byron, DIR_WEST

	setspeaker Speaker_Byron
	setvar VAR_TEMP_9, 1
	trainerbattle_no_intro TRAINER_BYRON3, VirtualCity_Stadium_Arena_Text_ByronB3Win1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Arena_Eventscript_LostByronB3
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Arena_Eventscript_LostByronB3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Arena_Eventscript_LostByronB3
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Arena_Eventscript_LostByronB3
	setvar VAR_TEMP_9, 0
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	call VirtualCity_Stadium_Arena_EventScript_WonMatch

	@applymovement throw Zoroark TOFOLD
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB3Win2, Speaker_Byron, DIR_WEST
	closemessage

	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	@applymovement retrieve Zoroark TOFOLD

	setflag FLAG_ACT_II_FOUGHT_BYRONB3
	call_if_set FLAG_HIT_BYRON_WITH_HACKED_MOVE, VirtualCity_Stadium_Arena_Eventscript_UsedHackMoveOnByron

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_LostByronB1::
	setvar VAR_PETALBURG_CITY_STATE, 34
	goto VirtualCity_Stadium_Arena_Eventscript_LostPlatinum
	end

VirtualCity_Stadium_Arena_Eventscript_LostByronB2AfterWin::
	setvar VAR_PETALBURG_CITY_STATE, 36
	goto VirtualCity_Stadium_Arena_Eventscript_LostPlatinum
	end

VirtualCity_Stadium_Arena_Eventscript_UsedHackMoveOnByron::
	setvar VAR_PETALBURG_CITY_STATE, 38
	return

VirtualCity_Stadium_Arena_Eventscript_LostByronB2::
	goto VirtualCity_Stadium_Arena_Eventscript_LostPlatinum
	end

VirtualCity_Stadium_Arena_Eventscript_LostByronB3::
	call_if_set FLAG_HIT_BYRON_WITH_HACKED_MOVE, VirtualCity_Stadium_Arena_Eventscript_UsedHackMoveOnByron
	goto VirtualCity_Stadium_Arena_Eventscript_LostPlatinum
	end

VirtualCity_Stadium_Arena_Eventscript_LostPlatinum::
	setvar VAR_TEMP_9, 0
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_AnnounceLossPlatinum, Speaker_Announcer, DIR_SOUTH
	playse SE_M_ENCORE2
	call VirtualCity_Stadium_Arena_EventScript_AudienceLookAround
	waitse
	@TOFOLD
	special HealPlayerParty
	special LoadPlayerParty

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 1
	waitstate
	end

VirtualCity_Stadium_Arena_EventScript_WonMatch::
	applymovement LOCALID_STADIUM_ANNOUNCER, Common_Movement_WalkInPlaceDown
	setspeaker Speaker_Announcer
	message VirtualCity_Stadium_Arena_Text_AnnounceWin
	waitmessage
	applymovement LOCALID_CUTSCENE_SOPHIE, Common_Movement_WalkUp
	playse SE_M_ENCORE2
	call VirtualCity_Stadium_Arena_EventScript_AudienceLookAround
	waitse
	closemessage
	return

VirtualCity_Stadium_Arena_Move_CommonApproachArena::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

VirtualCity_Stadium_Arena_Move_CommonApproachArenaSlow::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

VirtualCity_Stadium_Arena_Move_CommonLeaveArena::
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow::
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end


VirtualCity_Stadium_Arena_Move_ByronApproachArena1::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

VirtualCity_Stadium_Arena_Move_ByronApproachArena2::
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end






VirtualCity_Stadium_Arena_Text_Rando1Intro:
	.string "Oh thank god, you look weak.\n"
	.string "My Inteleon needs a win!$"

VirtualCity_Stadium_Arena_Text_Rando1Win:
	.string "Ugh, you weren't weak.\n"
	.string "I feel lied to.$"


VirtualCity_Stadium_Arena_Text_Rando2Intro:
	.string "Hi! I like the Sun!$"

VirtualCity_Stadium_Arena_Text_Rando2Win:
	.string "That was the worst RNG I've ever seen.\n"
	.string "I guess skill is no match for luck.$"


VirtualCity_Stadium_Arena_Text_Rando3Intro:
	.string "Hello, dearie! Want to see my\n"
	.string "adorable collection?$"

VirtualCity_Stadium_Arena_Text_Rando3Win:
	.string "I knew I wouldn't win, dearie.\n"
	.string "I just wanted to show off!$"


VirtualCity_Stadium_Arena_Text_Rando4Intro:
	.string "Nice, a new face! Let's fight!$"

VirtualCity_Stadium_Arena_Text_Rando4Win:
	.string "Whoa, you're good! Rematch me later,\n"
	.string "I know your tricks now!$"


VirtualCity_Stadium_Arena_Text_Rando5Intro:
	.string "Give me a challenge.$"

VirtualCity_Stadium_Arena_Text_Rando5Win:
	.string "Hmph. You delivered.\n"
	.string "Off meta POKéMON, but used well.$"



VirtualCity_Stadium_Arena_Text_BroDudeIntro:
	.string "Sup brah? Less go.$"

VirtualCity_Stadium_Arena_Text_BroDudeWin:
	.string "Bruh. Not cool.$"


VirtualCity_Stadium_Arena_Text_WvddieIntro:
	.string "HI' I VW WVDDIE$"

VirtualCity_Stadium_Arena_Text_WvddieWin:
	.string "HWWW' OK' I,W BVD\n"
	.string "CIVO$"


VirtualCity_Stadium_Arena_Text_SilvaBulletIntro:
	.string "You're new, aren't you? Time to learn\n"
	.string "a thing or two, heh.$"

VirtualCity_Stadium_Arena_Text_SilvaBulletWin:
	.string "What kind of garbage was that!?\n"
	.string "Best of one cheese, ugh.$"


VirtualCity_Stadium_Arena_Text_EarlGreyIntro:
	.string "My battling style is like black tea.\n"
	.string "It leaves you craving more.$"

VirtualCity_Stadium_Arena_Text_EarlGreyWin:
	.string "Hmph. Well done.\n"
	.string "I shall not be bitter.$"


VirtualCity_Stadium_Arena_Text_ByronB1Intro1:
	.string "Come on, make some noise for the champ!$"

VirtualCity_Stadium_Arena_Text_ByronB1Intro2:
	.string "Wait, what the…?\p"
	.string "How did you get into Plat with a team\n"
	.string "like that?!\p"
	.string "Bring some legendaries next time!\n"
	.string "My ELO won't go up if you use trash!$"


VirtualCity_Stadium_Arena_Text_ByronB1Lose:
	.string "Wow, that was a pathetic team.\p"
	.string "Mismatched, cheap POKéMON just can't\n"
	.string "compete with the best of the best.$"


VirtualCity_Stadium_Arena_Text_ByronB1Win:
	.string "You.\p"
	.string "You shouldn't have done that.\n"
	.string "You don't know who I am.$"



VirtualCity_Stadium_Arena_Text_ByronB2YouWonIntro:
	.string "50 points.\p"
	.string "That's the hit my ELO just took.\p"
	.string "Beating you will probably give me\n"
	.string "half a point, if that.\p"
	.string "So, I'm going to thrash you over and\n"
	.string "over until I get them all back.$"

VirtualCity_Stadium_Arena_Text_ByronB2YouLostIntro:
	.string "Hahahaha! Look everyone, she actually\n"
	.string "came back.\p"
	.string "I see what you're trying to do, y'know.\p"
	.string "Here's a tip, honey - I would never\n"
	.string "date a loser like you.\p"
	.string "Now, just die quickly.$"


VirtualCity_Stadium_Arena_Text_ByronB2YouWonWin:
	.string "Security!\p"
	.string "This woman's clearly cheating, and\n"
	.string "I want you to arrest her.$"

VirtualCity_Stadium_Arena_Text_ByronB2YouWonLose:
	.string "Not so tough now, huh?\p"
	.string "And, unfortunately for you, it was\n"
	.string "less than half of a point.\p"
	.string "I'm gonna whip you a zhundred more\n"
	.string "times so you can pay your debt to me.$"


VirtualCity_Stadium_Arena_Text_ByronB2YouLostWin:
	.string "You.\p"
	.string "You shouldn't have done that.\p"
	.string "You don't know who I am.$"

VirtualCity_Stadium_Arena_Text_ByronB2YouLostLose:
	.string "Why do they call it a best of three,\n"
	.string "anyway? Never understood that.\p"
	.string "Now get out of my sight - your\n"
	.string "fifteen minutes of fame are over.$"


VirtualCity_Stadium_Arena_Text_ByronB3Intro:
	.string "You know what my problem is?\p"
	.string "I'm too tolerant. \p"
	.string "A roach crawls into my house, and I\n"
	.string "let it be for a while, instead of\l"
	.string "crushing it immediately.\p"
	.string "Not gonna make that mistake again.$"

VirtualCity_Stadium_Arena_Text_ByronB3Win1:
	.string "It's rigged! It's rigged!\p"
	.string "Stupid, useless POKéMON!\n"
	.string "Can't do anything right!$"

VirtualCity_Stadium_Arena_Text_ByronB3Win2:
	.string "And you.\p"
	.string "I run this Place, and I better not see\n"
	.string "your face here ever again, understand?$"

VirtualCity_Stadium_Arena_Text_ByronB3Lose:
	.string "Wasn't even close.\p"
	.string "I've got better POKéMON, better skill,\n"
	.string "better predictions…\p"
	.string "And all you got is luck.$"

VirtualCity_Stadium_Arena_EventScript_Announcer::
	call_if_eq VAR_PETALBURG_CITY_STATE, 23, VirtualCity_Stadium_Arena_Eventscript_Rando1FightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 24, VirtualCity_Stadium_Arena_Eventscript_Rando2FightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 25, VirtualCity_Stadium_Arena_Eventscript_Rando3FightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 26, VirtualCity_Stadium_Arena_Eventscript_Rando4FightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 27, VirtualCity_Stadium_Arena_Eventscript_Rando5FightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 28, VirtualCity_Stadium_Arena_Eventscript_BrodudeFightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 29, VirtualCity_Stadium_Arena_Eventscript_WvddieFightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 30, VirtualCity_Stadium_Arena_Eventscript_SilvaBulletFightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 31, VirtualCity_Stadium_Arena_Eventscript_EarlGreyFightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_Arena_Eventscript_ByronB1FightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 35, VirtualCity_Stadium_Arena_Eventscript_ByronB2FightAnnouncer
	call_if_eq VAR_PETALBURG_CITY_STATE, 37, VirtualCity_Stadium_Arena_Eventscript_ByronB3FightAnnouncer
	closemessage
	return

VirtualCity_Stadium_Arena_Eventscript_Rando1FightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_Rando1Announce, Speaker_Announcer, DIR_SOUTH
	return

VirtualCity_Stadium_Arena_Eventscript_Rando2FightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_Rando2Announce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_Rando3FightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_Rando3Announce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_Rando4FightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_Rando4Announce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_Rando5FightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_Rando5Announce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_BrodudeFightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_BrodudeAnnounce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_WvddieFightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_WvddieAnnounce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_SilvaBulletFightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_SilvaBulletAnnounce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_EarlGreyFightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_EarlGrayAnnounce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_ByronB1FightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_ByronB1Announce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_ByronB2FightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_ByronB2Announce, Speaker_Announcer, DIR_SOUTH
	return
	
VirtualCity_Stadium_Arena_Eventscript_ByronB3FightAnnouncer::
	speak LOCALID_STADIUM_ANNOUNCER, VirtualCity_Stadium_Arena_Text_ByronB3Announce, Speaker_Announcer, DIR_SOUTH
	return

Speaker_Announcer:
	.string "Emcee$"

VirtualCity_Stadium_Arena_Text_Rando1Announce:
	.string "A new challenger has joined!\n"
	.string "But how far can she go?$"

VirtualCity_Stadium_Arena_Text_Rando2Announce:
	.string "This no-name's won her first match,\n"
	.string "but was that a fluke?$"

VirtualCity_Stadium_Arena_Text_Rando3Announce:
	.string "This challenger is looking to\n"
	.string "start a small streak!$"

VirtualCity_Stadium_Arena_Text_Rando4Announce:
	.string "It seems Silver League is too\n"
	.string "small-time for her!\p"
	.string "Can the new challenger make it\n"
	.string "to gold?$"

VirtualCity_Stadium_Arena_Text_Rando5Announce:
	.string "Her Gold League qualifying match!\n"
	.string "Welcome to the stage, {PLAYER}!$"

VirtualCity_Stadium_Arena_Text_BrodudeAnnounce:
	.string "She's starting to develop a small\n"
	.string "fanbase now!\p"
	.string "Here comes {PLAYER}!$"

VirtualCity_Stadium_Arena_Text_WvddieAnnounce:
	.string "She's won her first match already,\n"
	.string "but how long can she hang in Gold?\p"
	.string "Let's see how far {PLAYER} can go!$"

VirtualCity_Stadium_Arena_Text_SilvaBulletAnnounce:
	.string "The fan-favorite is back for more!\n"
	.string "Come on up, {PLAYER}!$"

VirtualCity_Stadium_Arena_Text_EarlGrayAnnounce:
	.string "The two most popular players in\n"
	.string "Gold League DUKE IT OUT!\p"
	.string "Welcome SOPHI99 vs. EARL GRAY!$"

VirtualCity_Stadium_Arena_Text_ByronB1Announce:
	.string "Hoo boy, do we have a good match!\p"
	.string "This upcoming opponent has NEVER\n"
	.string "been defeated in the history of\l"
	.string "this league!\p"
	.string "But can the champion-in-waiting\n"
	.string "take him down?\p"
	.string "Give it up for {PLAYER}!$"

VirtualCity_Stadium_Arena_Text_ByronB2Announce:
	.string "{PLAYER} is back for more!\n"
	.string "Can she do it again vs. Byron?$"

VirtualCity_Stadium_Arena_Text_ByronB3Announce:
	.string "Byron's new mortal enemy\n"
	.string "approaches!\p"
	.string "And we all know who the crowd loves!\n"
	.string "Welcome onto the stage, {PLAYER}!$"

VirtualCity_Stadium_Arena_Text_AnnounceLoss:
	.string "It looks like the challenger,\n"
	.string "{PLAYER}, has lost!\p"
	.string "Can she come back from this defeat\n"
	.string "and take the win next time?$"

VirtualCity_Stadium_Arena_Text_AnnounceWin:
	.string "AND THE WINNER IS…{PAUSE 50}\n"
	.string "SOPHI99!$"

VirtualCity_Stadium_Arena_Text_AnnounceLossPlatinum:
	.string "AND THE WINNER IS…{PAUSE 50}\n"
	.string "BYRON!$"
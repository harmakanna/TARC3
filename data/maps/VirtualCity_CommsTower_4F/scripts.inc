VirtualCity_CommsTower_4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VirtualCity_CommsTower_4F_OnLoad
	.byte 0

VirtualCity_CommsTower_4F_OnLoad::
	call_if_unset FLAG_COMMS_4F_DOOR, EventScript_CloseComms4FDoor
	end

EventScript_CloseComms4FDoor::
	setmetatile 2, 5, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 3, 5, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 2, 6, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 3, 6, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 2, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 3, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	return
	
EventScript_OpenComms4FDoor::
	setmetatile 2, 5, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 3, 5, METATILE_SilphCo_Floor, 0
	setmetatile 2, 6, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 3, 6, METATILE_SilphCo_Floor, 0
	setmetatile 3, 7, METATILE_SilphCo_Floor, 0
	return

@If you make it past the first floor check, you are already spoofing the executive, so no need for any more checks.
VirtualCity_CommsTower_4F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 4
	setvar VAR_0x8004, FLAG_COMMS_4F_DOOR
	goto_if_set FLAG_COMMS_4F_DOOR, EventScript_DoorUnlocked
	goto EventScript_OpenDoor
	end



VirtualCity_CommsTower_4F_EventScript_GuardD::
	trainerbattle_double TRAINER_DENISE, VirtualCity_CommsTower_4F_Text_GuardDIntro, VirtualCity_CommsTower_4F_Text_GuardDDefeated, Common_Text_NotEnoughPokemon, VirtualCity_CommsTower_4F_EventScript_GuardDCheck
	end

VirtualCity_CommsTower_4F_EventScript_GuardDCheck::
	special HealPlayerParty
	cleartrainerflag TRAINER_DENISE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 1, VirtualCity_CommsTower_1F_ActIII_Failed
	@goto_if_eq VAR_RESULT, 9, VirtualCity_CommsTower_1F_ActIII_Failed
	playse SE_PC_OFF
	applymovement LOCALID_GUARDD, VirtualCityIntro_Movement_LogOut
	waitmovement 0
	settrainerflag TRAINER_DENISE
	removeobject LOCALID_GUARDD
	end

VirtualCity_CommsTower_4F_Text_GuardDIntro::
	.string "We've barricaded the area!\n"
	.string "You're not getting through us!$"

VirtualCity_CommsTower_4F_Text_GuardDDefeated::
	.string "Noooo! It's up to you two!$"


VirtualCity_CommsTower_4F_EventScript_GuardE::
	trainerbattle_double TRAINER_BETH, VirtualCity_CommsTower_4F_Text_GuardEIntro, VirtualCity_CommsTower_4F_Text_GuardEDefeated, Common_Text_NotEnoughPokemon, event_script=VirtualCity_CommsTower_4F_EventScript_GuardECheck
	end

VirtualCity_CommsTower_4F_EventScript_GuardECheck::
	special HealPlayerParty
	cleartrainerflag TRAINER_BETH
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 1, VirtualCity_CommsTower_1F_ActIII_Failed
	@goto_if_eq VAR_RESULT, 9, VirtualCity_CommsTower_1F_ActIII_Failed
	playse SE_PC_OFF
	applymovement LOCALID_GUARDE, VirtualCityIntro_Movement_LogOut
	waitmovement 0
	settrainerflag TRAINER_BETH
	removeobject LOCALID_GUARDE
	end

VirtualCity_CommsTower_4F_Text_GuardEIntro::
	.string "I saw it!\n"
	.string "It's healing between fights!$"

VirtualCity_CommsTower_4F_Text_GuardEDefeated::
	.string "It just set the HP to max!\n"
	.string "I saw it!$"


VirtualCity_CommsTower_4F_EventScript_GuardF::
	trainerbattle_double TRAINER_TARA, VirtualCity_CommsTower_4F_Text_GuardFIntro, VirtualCity_CommsTower_4F_Text_GuardFDefeated, Common_Text_NotEnoughPokemon, event_script=VirtualCity_CommsTower_4F_EventScript_GuardFCheck
	end

VirtualCity_CommsTower_4F_EventScript_GuardFCheck::
	special HealPlayerParty
	cleartrainerflag TRAINER_TARA
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 1, VirtualCity_CommsTower_1F_ActIII_Failed
	@goto_if_eq VAR_RESULT, 9, VirtualCity_CommsTower_1F_ActIII_Failed
	playse SE_PC_OFF
	applymovement LOCALID_GUARDF, VirtualCityIntro_Movement_LogOut
	waitmovement 0
	settrainerflag TRAINER_TARA
	removeobject LOCALID_GUARDF
	end

VirtualCity_CommsTower_4F_Text_GuardFIntro::
	.string "I know I can't beat you.\n"
	.string "But I have to try.$"

VirtualCity_CommsTower_4F_Text_GuardFDefeated::
	.string "Um.\p"
	.string "Just between you and me.\p"
	.string "Break it.$"


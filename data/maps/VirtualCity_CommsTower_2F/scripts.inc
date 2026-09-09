VirtualCity_CommsTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VirtualCity_CommsTower_2F_OnLoad
	.byte 0

VirtualCity_CommsTower_2F_OnLoad::
	call_if_unset FLAG_COMMS_2F_DOOR, EventScript_CloseComms2FDoor
	end

EventScript_CloseComms2FDoor::
	setmetatile 2, 5, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 3, 5, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 2, 6, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 3, 6, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 2, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 3, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_OpenComms2FDoor::
	setmetatile 2, 5, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 3, 5, METATILE_SilphCo_Floor, 0
	setmetatile 2, 6, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 3, 6, METATILE_SilphCo_Floor, 0
	setmetatile 3, 7, METATILE_SilphCo_Floor, 0
	return

@If you make it past the first floor check, you are already spoofing the executive, so no need for any more checks.
VirtualCity_CommsTower_2F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 2
	setvar VAR_0x8004, FLAG_COMMS_2F_DOOR
	goto_if_set FLAG_COMMS_2F_DOOR, EventScript_DoorUnlocked
	goto EventScript_OpenDoor
	end

VirtualCity_CommsTower_2F_EventScript_GuardA::
	trainerbattle_double TRAINER_IMANI, VirtualCity_CommsTower_2F_Text_GuardAIntro, VirtualCity_CommsTower_2F_Text_GuardADefeated, Common_Text_NotEnoughPokemon
	special HealPlayerParty
	playse SE_PC_OFF
	applymovement LOCALID_GUARDA, VirtualCityIntro_Movement_LogOut
	waitmovement 0
	removeobject LOCALID_GUARDA
	end

VirtualCity_CommsTower_2F_Text_GuardAIntro::
	.string "What the…?\n"
	.string "Stop!$"

VirtualCity_CommsTower_2F_Text_GuardADefeated::
	.string "It's a disguised skin…?\n"
	.string "I've gotta call the boss!$"




VirtualCity_CommsTower_2F_EventScript_GuardB::
	trainerbattle_double TRAINER_BEVERLY, VirtualCity_CommsTower_2F_Text_GuardBIntro, VirtualCity_CommsTower_2F_Text_GuardBDefeated, Common_Text_NotEnoughPokemon
	special HealPlayerParty
	playse SE_PC_OFF
	applymovement LOCALID_GUARDB, VirtualCityIntro_Movement_LogOut
	waitmovement 0
	removeobject LOCALID_GUARDB
	end

VirtualCity_CommsTower_2F_Text_GuardBIntro::
	.string "We're under attack!$"

VirtualCity_CommsTower_2F_Text_GuardBDefeated::
	.string "Don't hurt me, virus!$"

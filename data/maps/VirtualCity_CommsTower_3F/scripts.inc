VirtualCity_CommsTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VirtualCity_CommsTower_3F_OnLoad
	.byte 0

VirtualCity_CommsTower_3F_OnLoad::
	call_if_unset FLAG_COMMS_3F_DOOR, EventScript_CloseComms3FDoor
	end

EventScript_CloseComms3FDoor::
	setmetatile 11, 5, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 12, 5, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 11, 6, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 12, 6, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 11, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 12, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_OpenComms3FDoor::
	setmetatile 11, 5, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 12, 5, METATILE_SilphCo_Floor, 0
	setmetatile 11, 6, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 12, 6, METATILE_SilphCo_Floor, 0
	setmetatile 12, 7, METATILE_SilphCo_Floor, 0
	return

@If you make it past the first floor check, you are already spoofing the executive, so no need for any more checks.
VirtualCity_CommsTower_3F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 3
	setvar VAR_0x8004, FLAG_COMMS_3F_DOOR
	goto_if_set FLAG_COMMS_3F_DOOR, EventScript_DoorUnlocked
	goto EventScript_OpenDoor
	end


VirtualCity_CommsTower_3F_EventScript_GuardC::
	trainerbattle_double TRAINER_KYLA, VirtualCity_CommsTower_3F_Text_GuardCIntro, VirtualCity_CommsTower_3F_Text_GuardCDefeated, Common_Text_NotEnoughPokemon, event_script = VirtualCity_CommsTower_3F_EventScript_GuardCCheck
	end

VirtualCity_CommsTower_3F_EventScript_GuardCCheck::
	cleartrainerflag TRAINER_KYLA
	special HealPlayerParty
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 1, VirtualCity_CommsTower_1F_ActIII_Failed
	@goto_if_eq VAR_RESULT, 9, VirtualCity_CommsTower_1F_ActIII_Failed
	playse SE_PC_OFF
	applymovement LOCALID_GUARDC, VirtualCityIntro_Movement_LogOut
	waitmovement 0
	settrainerflag TRAINER_KYLA
	removeobject LOCALID_GUARDC
	end



VirtualCity_CommsTower_3F_Text_GuardCIntro::
	.string "Whoa!\n"
	.string "I always wanted to fight a terrorist!$"

VirtualCity_CommsTower_3F_Text_GuardCDefeated::
	.string "I didn't want to lose to a terrorist!$"


VirtualCity_CommsTower_3F_EventScript_ScaredyCat::
	msgbox VirtualCity_CommsTower_3F_Text_ScaredyCat, MSGBOX_DEFAULT
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_CommsTower_3F_Text_ScaredyCat2, MSGBOX_DEFAULT
	closemessage
	end

VirtualCity_CommsTower_3F_Text_ScaredyCat:
	.string "As long as I stare at this screen,\n"
	.string "and get my work done,\l"
	.string "{FONT_SMALL}nothing will come and get me.$"

VirtualCity_CommsTower_3F_Text_ScaredyCat2:
	.string "…$"


VirtualCity_CommsTower_3F_EventScript_ResignedCat::
	msgbox VirtualCity_CommsTower_3F_Text_ResignedCat, MSGBOX_NPC
	closemessage
	releaseall
	end

VirtualCity_CommsTower_3F_Text_ResignedCat::
	.string "Ah.\p"
	.string "With all the things {COLOR GREEN}BETTER{COLOR DARK_GRAY} does, I\n"
	.string "guess it was only a matter of time.$"


VirtualCity_CommsTower_3F_EventScript_ObliviousCat::
	msgbox VirtualCity_CommsTower_3F_Text_ObliviousCat, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_CommsTower_3F_Text_ObliviousCat2, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_CommsTower_3F_Text_ObliviousCat:
	.string "Woahhhhh!\p"
	.string "Never seen a skin like that!\n"
	.string "It's so mysterious! Love it!$"

VirtualCity_CommsTower_3F_Text_ObliviousCat2:
	.string "…really?$"



VirtualCity_CommsTower_3F_EventScript_ScreenIdols::
	msgbox VirtualCity_CommsTower_3F_Text_ScreenIdols, MSGBOX_SIGN
	closemessage
	releaseall
	end

VirtualCity_CommsTower_3F_Text_ScreenIdols:
	.string "It's a bunch of small videos, like a\n"
	.string "surveillance board.\p"
	.string "Three of them are spinning wildly…\n"	
	.string "The idols' camera feeds get sent here?$"	


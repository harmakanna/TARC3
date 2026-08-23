VirtualCity_CommsTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VirtualCity_CommsTower_1F_OnLoad
	.byte 0

VirtualCity_CommsTower_1F_OnLoad::
	call_if_unset FLAG_COMMS_1F_DOOR, EventScript_CloseComms1FDoor
	end

EventScript_CloseComms1FDoor::
	setmetatile 10, 5, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 11, 5, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 10, 6, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 11, 6, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 11, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_OpenComms1FDoor::
	setmetatile 10, 5, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 11, 5, METATILE_SilphCo_Floor, 0
	setmetatile 10, 6, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 11, 6, METATILE_SilphCo_Floor, 0
	setmetatile 11, 7, METATILE_SilphCo_Floor, 0
	return

VirtualCity_CommsTower_1F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_0x8004, FLAG_COMMS_1F_DOOR
	goto_if_set FLAG_COMMS_1F_DOOR, EventScript_DoorUnlocked
	goto VirtualCity_CommsTower_1F_EventScript_TryUnlockDoor
	end

VirtualCity_CommsTower_1F_EventScript_TryUnlockDoor::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, EventScript_OpenDoor
	msgbox VirtualCity_CommsTower_1F_Text_AccessDenied
	releaseall
	end

VirtualCity_CommsTower_1F_Text_AccessDenied::
	.string "Identity unknown.\n"
	.string "Access denied.$"

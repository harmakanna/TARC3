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


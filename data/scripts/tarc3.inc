@ Speak Macro 

LastTalkedWalkInPlaceNorth::
	applymovement VAR_0x8000, FastWalkInPlaceNorth
	return

LastTalkedWalkInPlaceSouth::
	applymovement VAR_0x8000, FastWalkInPlaceSouth
	return

LastTalkedWalkInPlaceEast::
	applymovement VAR_0x8000, FastWalkInPlaceEast
	return

LastTalkedWalkInPlaceWest::
	applymovement VAR_0x8000, FastWalkInPlaceWest
	return

FastWalkInPlaceNorth:
	walk_in_place_faster_up
	step_end

FastWalkInPlaceSouth:
	walk_in_place_faster_down
	step_end

FastWalkInPlaceEast:
	walk_in_place_faster_right
	step_end

FastWalkInPlaceWest:
	walk_in_place_faster_left
	step_end

@ Comms Tower Door Handlers

EventScript_OpenDoor::
	playfanfare MUS_BW12_002
	msgbox Text_WelcomeBackExecutive
	waitfanfare
	call_if_eq VAR_TEMP_1, 1, EventScript_OpenComms1FDoor
	call_if_eq VAR_TEMP_1, 2, EventScript_OpenComms2FDoor
	call_if_eq VAR_TEMP_1, 3, EventScript_OpenComms3FDoor
	call_if_eq VAR_TEMP_1, 4, EventScript_OpenComms4FDoor
	waitse
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	special SetHiddenItemFlag
	releaseall
	end

EventScript_DoorUnlocked::
	msgbox Text_TheDoorIsOpen
	releaseall
	end

Text_WelcomeBackExecutive::
	.string "Identity verified.\n"
	.string "Welcome back, Byron.$"
	
Text_TheDoorIsOpen::
	.string "The door is open.$"

@ Etc

EventScript_AddRandomMod::
	special ChooseMonForAddMod
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_AddNoRandomMod
	callnative GetThreeRandomTraits
	dynmultipush gStringVar1, 0
	dynmultipush gStringVar2, 1
	dynmultipush gStringVar3, 2
	dynmultistack 0, 0, TRUE, 3 FALSE, 0, NULL
	callnative AddNewMod
	releaseall
EventScript_AddNoRandomMod:
	return

Speaker_Player:
	.string "{PLAYER}$"
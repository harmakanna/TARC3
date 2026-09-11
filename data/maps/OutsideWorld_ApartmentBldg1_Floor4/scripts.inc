OutsideWorld_ApartmentBldg1_Floor4_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_ApartmentBldg1_Floor4_OnFrame
	.byte 0

OutsideWorld_ApartmentBldg1_Floor4_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, OutsideWorld_ApartmentBldg1_Floor4_Eventscript_Stairs
	.2byte 0	

OutsideWorld_ApartmentBldg1_Floor4_Eventscript_Stairs::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, OutsideWorld_ApartmentBldg1_Floor4_Move_Camera
	waitmovement OBJ_EVENT_ID_CAMERA
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreenspeed FADE_FROM_BLACK 2
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_Floor4_Move_Sophie
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_DOOR
	opendoor 5, 1
	waitdooranim
	waitse
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 10
	hideplayer
	waitse
	closedoor 5, 1
	waitdooranim
	delay 100
	setvar VAR_PETALBURG_CITY_STATE, 5
	setflag FLAG_HIDE_OPENING_CREDITS
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_YOUR_APARTMENT, 1,3
	waitstate
	end

OutsideWorld_ApartmentBldg1_Floor4_Move_Sophie::
	walk_right
	walk_right
	face_up
	step_end

OutsideWorld_ApartmentBldg1_Floor4_Move_Camera::
	walk_up
	step_end


AptBldg_Floor4_Girl::
	msgbox AptBldg_Floor4_Text_Girl, MSGBOX_NPC
	end

AptBldg_Floor4_Woman::
	msgbox AptBldg_Floor4_Text_Woman, MSGBOX_NPC
	end

AptBldg_Floor4_Text_Girl:
	.string "Hey, do you have that one video\n"
	.string "of POKéMON playing in the meadows?\p"
	.string "It's missing from the catalogue…$"

AptBldg_Floor4_Text_Woman:
	.string "Don't tell my daughter I overwrote\n"
	.string "her favorite video…\p"
	.string "I thought it was blank…$"
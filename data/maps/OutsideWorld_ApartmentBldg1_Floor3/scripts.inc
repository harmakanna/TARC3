OutsideWorld_ApartmentBldg1_Floor3_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_ApartmentBldg1_Floor3_OnFrame
	.byte 0

OutsideWorld_ApartmentBldg1_Floor3_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, OutsideWorld_ApartmentBldg1_Floor3_Eventscript_Stairs
	.2byte 0	

OutsideWorld_ApartmentBldg1_Floor3_Eventscript_Stairs::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, OutsideWorld_ApartmentBldg1_Floor3_Move_Camera
	waitmovement OBJ_EVENT_ID_CAMERA
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreenspeed FADE_FROM_BLACK 2
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_Floor3_Move_Sophie
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	hideplayer
	waitse
	delay 100
	setflag FLAG_SYS_PREVENT_MAP_FADE
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_FLOOR4, 3,1
	waitstate
	end

OutsideWorld_ApartmentBldg1_Floor3_Move_Sophie::
	walk_left
	walk_left
	walk_up
	step_end

OutsideWorld_ApartmentBldg1_Floor3_Move_Camera::
	walk_left
	walk_up
	walk_up
	step_end





AptBldg_Floor3_OldWoman::
	lock
	msgbox AptBldg_Floor3_Text_OldWoman1, MSGBOX_DEFAULT
	player_speak AptBldg_Floor3_Text_SophieToOldWoman
	npc_speak NULL, AptBldg_Floor3_Text_OldWoman2
	closemessage
	release
	end

AptBldg_Floor3_Text_OldWoman1:
	.string "Oooo where did my good\n"
	.string "friend SILICOBRA slither off\l"
	.string "to?\p"
	.string "She must be here somewhere!$"

AptBldg_Floor3_Text_SophieToOldWoman:
	.string "Grandma, SILICOBRA passed away\n"
	.string "well before I was born…$"

AptBldg_Floor3_Text_OldWoman2:
	.string "Hmm, no, no, that can't be\n"
	.string "right…\p"
	.string "She was just with me yesterday.\p"
	.string "Oh SILICOBRA, where are you?$"
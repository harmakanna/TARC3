OutsideWorld_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OutsideWorld_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_OnFrame
	.byte 0


OutsideWorld_OnTransition::
	end

OutsideWorld_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 3, OutsideWorld_PrologueEndScene_Final_Really
	.2byte 0


OutsideWorld_PrologueEndScene_Final_Really::
	setweather WEATHER_RAIN
	doweather
	addobject LOCALID_OW_MINH
	delay 100
	delay 100
	fadescreenspeed FADE_FROM_BLACK 5
	delay 50
	
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue1, Speaker_Sophie, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_OW_MINH, OutsideWorld_MinhPrologue2, Speaker_Minh, DIR_SOUTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue3, Speaker_Sophie, DIR_EAST
	playse SE_SELECT
	speak LOCALID_OW_MINH, OutsideWorld_MinhPrologue4, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue5, Speaker_Sophie, DIR_EAST
	playse SE_SELECT
	delay 30
	closemessage
	applymovement LOCALID_OW_MINH, OutsideWorld_Move_Minh1
	delay 100
	delay 100
	delay 100
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_Move_Sophie1
	waitmovement 0
	removeobject LOCALID_OW_MINH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_Move_Sophie2
	applymovement OBJ_EVENT_ID_CAMERA, OutsideWorld_Move_Camera1
	delay 50
	playse SE_DOOR
	hideplayer
	waitmovement 0
	delay 100
	delay 50
	setvar VAR_PETALBURG_CITY_STATE, 4
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_FLOOR1, 2,4
	waitstate
	end	

	@TOFOLD move this
	setflag FLAG_PROLOGUE_COMPLETE

	end

OutsideWorld_Move_Minh1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OutsideWorld_Move_Sophie1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

OutsideWorld_Move_Sophie2:
	walk_right
	walk_up
	walk_up
	step_end

OutsideWorld_Move_Camera1:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end



OutsideWorld_SophiePrologue1::
	.string "There's no point brooding any longer.\p"
	.string "It's late, you should get home. Meet in\n"
	.string "the Place, at work, when you can.\p"
	.string "At least that way, Lola won't be\n"
	.string "able to hear us talking about it.$"

OutsideWorld_MinhPrologue2::
	.string "…I don't know what we're going to do.$"

OutsideWorld_SophiePrologue3::
	.string "We're going to find out who's making\n"
	.string "fakes. And we're going to get evidence.$"

OutsideWorld_MinhPrologue4::
	.string "…Okay.\p"
	.string "Whoever it is, they work for BETTER,\n"
	.string "and they've got artists.\p"
	.string "I'll ask around with my art friends.$"

OutsideWorld_SophiePrologue5::
	.string "Good plan. I'll see you tomorrow.\n"
	.string "Meet at work in the Place.$"



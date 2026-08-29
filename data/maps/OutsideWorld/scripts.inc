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
	addobject LOCALID_MINH
	delay 100
	delay 100
	fadescreenspeed FADE_FROM_BLACK 5
	delay 50
	
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue1, Speaker_Sophie, DIR_SOUTH
	speak LOCALID_MINH, OutsideWorld_MinhPrologue2, Speaker_Minh, DIR_SOUTH
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue3, Speaker_Sophie, DIR_SOUTH
	speak LOCALID_MINH, OutsideWorld_MinhPrologue4, Speaker_Minh, DIR_WEST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue5, Speaker_Sophie, DIR_EAST
	delay 30
	applymovement LOCALID_MINH, OutsideWorld_Move_Minh1
	waitmovement
	removeobject LOCALID_MINH

	setflag FLAG_PROLOGUE_COMPLETE
	setvar VAR_PETALBURG_CITY_STATE, 10

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
	step_end



OutsideWorld_SophiePrologue1::
	.string "There's no point brooding any longer.\p"
	.string "It's late, you should get home. Meet in\n"
	.string "the Realm, at work, when you can.\p"
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



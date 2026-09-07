OutsideWorld_ApartmentBldg1_Floor1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_ApartmentBldg1_Floor1_OnFrame
	.byte 0

OutsideWorld_ApartmentBldg1_Floor1_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, OutsideWorld_ApartmentBldg1_Floor1_Eventscript_Stairs
	.2byte 0	

OutsideWorld_ApartmentBldg1_Floor1_Eventscript_Stairs::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_Floor1_Move_Sophie
	applymovement OBJ_EVENT_ID_CAMERA, OutsideWorld_ApartmentBldg1_Floor1_Move_Camera
	delay 70
	playse SE_EXIT
	hideplayer
	waitmovement 0
	delay 100
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_FLOOR2, 5,1
	waitstate
	end


OutsideWorld_ApartmentBldg1_Floor1_Move_Sophie::
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

OutsideWorld_ApartmentBldg1_Floor1_Move_Camera::
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

AptBldg_Floor1_Man::
	msgbox AptBldg_Floor1_Text_Man, MSGBOX_NPC
	end

AptBldg_Floor1_Text_Man:
	.string "No mail from her today…\p"
	.string "I wish I could afford a\n"
	.string "{COLOR GREEN}BETTER Place{COLOR DARK_GRAY} subscription…\p"
	.string "The post office is barely\n"
	.string "functional these days.$"

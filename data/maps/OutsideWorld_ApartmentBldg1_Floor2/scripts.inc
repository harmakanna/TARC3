OutsideWorld_ApartmentBldg1_Floor2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_ApartmentBldg1_Floor2_OnFrame
	.byte 0

OutsideWorld_ApartmentBldg1_Floor2_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, OutsideWorld_ApartmentBldg1_Floor2_Eventscript_Stairs
	.2byte 0	

OutsideWorld_ApartmentBldg1_Floor2_Eventscript_Stairs::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_Floor2_Move_Sophie
	applymovement OBJ_EVENT_ID_CAMERA, OutsideWorld_ApartmentBldg1_Floor2_Move_Camera
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	hideplayer
	waitse
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 100
	@TOFOLD
	setvar VAR_PETALBURG_CITY_STATE, 10
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_FLOOR3, 5,1
	waitstate
	end


OutsideWorld_ApartmentBldg1_Floor2_Move_Sophie::
	walk_left
	walk_left
	walk_up
	step_end

OutsideWorld_ApartmentBldg1_Floor2_Move_Camera::
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

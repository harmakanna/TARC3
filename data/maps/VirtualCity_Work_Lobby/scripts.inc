VirtualCity_Work_Lobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VirtualCity_Work_Lobby_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Work_Lobby_OnFrame
	.byte 0


VirtualCity_Work_Lobby_OnTransition::
	end

VirtualCity_Work_Lobby_OnFrame:
	@map_script_2 VAR_PETALBURG_CITY_STATE, 10, VirtualCity_Work_Lobby_Eventscript_ActIIntro
	.2byte 0










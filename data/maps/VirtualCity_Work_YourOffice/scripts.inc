VirtualCity_Work_YourOffice_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Work_YourOffice_OnFrame
	.byte 0

VirtualCity_Work_YourOffice_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 12, VirtualCity_Work_YourOffice_Eventscript_MakingExPonyta
	.2byte 0

VirtualCity_Work_YourOffice_Eventscript_MakingExPonyta::
	clearparty
	givemon SPECIES_DRILBUR, 50
	applymovement LOCALID_MINH, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone1, Speaker_Minh, DIR_NORTH
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone2, SP_NAME_PLAYER, DIR_NORTH
	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone3, Speaker_Minh, DIR_NORTH

	applymovement LOCALID_MINH, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight

	addobject LOCALID_PONYTAS_BALL
	delay 10
	playse SE_BALL_OPEN
	removeobject LOCALID_PONYTAS_BALL
	addobject LOCALID_PONYTAEX
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	playmoncry SPECIES_PONYTA, CRY_MODE_ENCOUNTER
	delay 40


	
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone4, SP_NAME_PLAYER, DIR_WEST


	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_MINH, Common_Movement_ExclamationMark
	
	
	removeobject LOCALID_PONYTAEX
	addobject LOCALID_PONYTAS_BALL
	playse SE_BALL_OPEN
	delay 10
	removeobject LOCALID_PONYTAS_BALL

	


	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone5, SP_NAME_PLAYER, DIR_NORTH
	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone6, Speaker_Minh, DIR_NORTH
	setvar VAR_PETALBURG_CITY_STATE, 15
	setflag FLAG_ACT_I_EX_PONYTA_OBTAINED
	end


VirtualCity_Work_YourOffice_Move_Sophie1:
	walk_down
	walk_down
	face_right
	step_end

VirtualCity_Work_YourOffice_Move_Ex1:
	face_left
	jump_in_place_left
	delay 16
	jump_in_place_left
	step_end



VirtualCity_Work_YourOffice_Eventscript_MinhACTI::
	goto_if_set FLAG_ACT_I_REAL_PONYTA_OBTAINED, VirtualCity_Work_YourOffice_Eventscript_MinhACTIOutro
	goto_if_set FLAG_ACT_I_EX_PONYTA_OBTAINED, VirtualCity_Work_YourOffice_Eventscript_MinhACTIPonytaDoneRepeat
	end



VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone1:
	.string "I think… I think that should do it.$"


VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone2:
	.string "It's done? How is he?$"

VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone3:
	.string "Ex is fine, don't worry. It's like\n"
	.string "changing your Place avatar.\p"
	.string "He might have to learn how to walk on\n"
	.string "four feet, though!$"

VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone4:
	.string "Wow, he looks great!\n"
	.string "Ex, you feeling okay?$"

VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone5:
	.string "Oh, he's fine! He knows he's about to\n"
	.string "get to fight! Don't you, cutie?\p"
	.string "And Minh, you were worried about not\n"
	.string "being helpful!\p"
	.string "No other artist could have edited Ex\n"
	.string "into a Ponyta so fast and accurately!$"

VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone6:
	.string "Oh, stop it! …but do go on.\p"
	.string "Ahem. You should be able to get into\n"
	.string "the IRL Department now.\p"
	.string "See if you can find some evidence of\n"
	.string "the IRL Pokemon being made there!$"



VirtualCity_Work_YourOffice_Eventscript_MinhACTIPonytaDoneRepeat::
	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDoneRepeat, Speaker_Minh, DIR_SOUTH
	end

VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDoneRepeat:
	.string "Ex doing okay? I'll change him back\n"
	.string "as soon as you're done.\p"
	.string "Remember, you gotta get into the IRL\n"
	.string "department with Ex and find evidence.\l"
	.string "that they're making fake Pokemon!$"



VirtualCity_Work_YourOffice_Eventscript_MinhACTIOutro::
	@warpsilent next=to-minh!
	
	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIOutro1, Speaker_Minh, DIR_WEST
	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_SophieACTIOutro2, SP_NAME_PLAYER, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Move_ACTIOutroSophie1

	@addobject LOCALID_PONYTAS_BALL
	delay 10
	playse SE_BALL_OPEN
	@removeobject LOCALID_PONYTAS_BALL
	@addobject LOCALID_PONYTA
	waitse
	playmoncry SPECIES_PONYTA, CRY_MODE_ENCOUNTER
	


	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIOutro3, Speaker_Minh, DIR_WEST
	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_SophieACTIOutro4, SP_NAME_PLAYER, DIR_EAST
	speak LOCALID_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIOutro5, Speaker_Minh, DIR_WEST
	clearparty
	givemon SPECIES_EXCADRILL, 50
	givemon SPECIES_PONYTA, 50
	setvar VAR_PETALBURG_CITY_STATE, 20
	setflag FLAG_ACT_I_COMPLETE
	clearflag FLAG_HIDE_ACT_2_TEA_QUEST
	clearflag FLAG_HIDE_ACT_II_INTRO_CHARS
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_YOUR_APARTMENT, 7,4
	waitstate
	end

VirtualCity_Work_YourOffice_Move_ACTIOutroSophie1:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end




VirtualCity_Work_YourOffice_Text_MinhACTIOutro1:
	.string "You're back! What did you find?$"

VirtualCity_Work_YourOffice_Text_SophieACTIOutro2:
	.string "…$"

VirtualCity_Work_YourOffice_Text_MinhACTIOutro3:
	.string "It's an unfinished Ponyta…\n"
	.string "But it's so detailed.\p"
	.string "Hi, lil' guy!$"

VirtualCity_Work_YourOffice_Text_SophieACTIOutro4:
	.string "Let get back to the outside.\n"
	.string "I bet this Ponyta comes with us.\p"
	.string "That means… it's like Lola's Snubbull.$"

VirtualCity_Work_YourOffice_Text_MinhACTIOutro5:
	.string "Let's meet up with the gang.\p"
	.string "I'll tell them to meet us at your\n"
	.string "apartment - they might have ideas.$"




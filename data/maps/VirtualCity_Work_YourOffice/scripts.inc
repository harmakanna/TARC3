VirtualCity_Work_YourOffice_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Work_YourOffice_OnFrame
	.byte 0

VirtualCity_Work_YourOffice_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 12, VirtualCity_Work_YourOffice_Eventscript_MakingExPonyta
	.2byte 0

VirtualCity_Work_YourOffice_Eventscript_MakingExPonyta::
	delay 100
	clearparty
	givemon SPECIES_DRILBUR, 50
	applymovement LOCALID_YOUROFFICE_MINH, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreenspeed FADE_FROM_BLACK, 5
	speak LOCALID_YOUROFFICE_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone1, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone2, SP_NAME_PLAYER, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_YOUROFFICE_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone3, Speaker_Minh, DIR_NORTH
	closemessage

	applymovement LOCALID_YOUROFFICE_MINH, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Move_Sophie1
	waitmovement 0

	playse SE_BALL_THROW
	addobject LOCALID_PONYTAS_BALL
	waitse
	delay 10
	playse SE_BALL_OPEN
	waitse
	removeobject LOCALID_PONYTAS_BALL
	addobject LOCALID_PONYTAEX
	playse SE_PIN
	applymovement LOCALID_YOUROFFICE_MINH, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	delay 60

	playmoncry SPECIES_PONYTA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20


	
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone4, SP_NAME_PLAYER, DIR_EAST
	closemessage

	applymovement LOCALID_PONYTAEX, VirtualCity_Work_YourOffice_Move_Ex1
	playse SE_LEDGE
	delay 78
	playse SE_LEDGE
	waitmovement 0
	waitse
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Heart
	playse SE_PIN
	waitse
	delay 50
	
	removeobject LOCALID_PONYTAEX
	addobject LOCALID_PONYTAS_BALL
	playse SE_BALL_OPEN
	delay 40
	removeobject LOCALID_PONYTAS_BALL

	


	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Text_SophieACTIPonytaDone5, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_YOUROFFICE_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDone6, Speaker_Minh, DIR_WEST
	closemessage
	setvar VAR_PETALBURG_CITY_STATE, 15
	setflag FLAG_ACT_I_EX_PONYTA_OBTAINED
	setflag FLAG_HIDE_ACT_I_RESEARCHERS
	end

VirtualCity_Work_YourOffice_Move_Sophie1:
	walk_left
	walk_left
	face_right
	step_end


VirtualCity_Work_YourOffice_Move_Ex1:
	face_left
	jump_in_place_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	face_left
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
	.string "Ahem. The guard should let you into\n"
	.string "the Research Department now.\p"
	.string "See if you can find some evidence of\n"
	.string "fake IRL POKéMON being made there!$"



VirtualCity_Work_YourOffice_Eventscript_MinhACTIPonytaDoneRepeat::
	npc_speak Speaker_Minh, VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDoneRepeat
	closemessage
	end

VirtualCity_Work_YourOffice_Text_MinhACTIPonytaDoneRepeat:
	.string "Ex doing okay? I'll change him back\n"
	.string "as soon as you're done.\p"
	.string "Remember, you gotta get into Research\n"
	.string "with Ex and find hard evidence that\l"
	.string "they're making fake POKéMON!$"



VirtualCity_Work_YourOffice_Eventscript_MinhACTIOutro::
	npc_speak Speaker_Minh, VirtualCity_Work_YourOffice_Text_MinhACTIOutro1
	playse SE_SELECT
	player_speak VirtualCity_Work_YourOffice_Text_SophieACTIOutro2
	closemessage
	applymovement LOCALID_YOUROFFICE_MINH, Common_Movement_FaceLeft
	call_if_eq VAR_FACING, DIR_EAST, VirtualCity_Work_YourOffice_Eventscript_SophieOutroEast
	call_if_eq VAR_FACING, DIR_NORTH, VirtualCity_Work_YourOffice_Eventscript_SophieOutroNorth
	call_if_eq VAR_FACING, DIR_WEST, VirtualCity_Work_YourOffice_Eventscript_SophieOutroWest

	playse SE_BALL_THROW
	addobject LOCALID_PONYTAS_BALL
	waitse
	delay 10
	playse SE_BALL_OPEN
	waitse
	removeobject LOCALID_PONYTAS_BALL
	addobject LOCALID_PONYTA
	playse SE_PIN
	applymovement LOCALID_YOUROFFICE_MINH, Common_Movement_ExclamationMark
	waitse
	delay 60

	playmoncry SPECIES_EXCADRILL, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	


	speak LOCALID_YOUROFFICE_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIOutro3, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Text_SophieACTIOutro4, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_YOUROFFICE_MINH, VirtualCity_Work_YourOffice_Text_MinhACTIOutro5, Speaker_Minh, DIR_WEST
	closemessage
	clearparty
	givemon SPECIES_EXCADRILL, 50, nature=NATURE_JOLLY, abilityNum=1, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_EARTHQUAKE, move2=MOVE_ROCK_SLIDE, move3=MOVE_SWORDS_DANCE, move4=MOVE_PROTECT, nickname=Nickname_Ex, otName=OT_SoPhi99
	givemon SPECIES_PONYTA, 50, nature=NATURE_NAIVE, abilityNum=1, gender=MON_FEMALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_FLARE_BLITZ, move2=MOVE_WILD_CHARGE, move3=MOVE_DRILL_RUN, move4=MOVE_PROTECT, otName=OT_Research
	setvar VAR_PETALBURG_CITY_STATE, 20
	setflag FLAG_ACT_I_COMPLETE
	clearflag FLAG_HIDE_ACT_2_TEA_QUEST
	clearflag FLAG_HIDE_ACT_II_INTRO_CHARS
	setflag FLAG_ACT_I_HIDE_MINH_OFFICE
	setflag FLAG_HIDE_LOLA_BEDROOM_PROLOGUE
	setflag FLAG_SYS_PREVENT_MAP_FADE
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	fadenewbgm MUS_NONE
	fadescreenspeed FADE_TO_BLACK, 5
	delay 150
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_YOUR_APARTMENT, 7,4
	waitstate
	end


VirtualCity_Work_YourOffice_Eventscript_SophieOutroEast::
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Move_SophieOutroEast
	waitmovement 0
	return

VirtualCity_Work_YourOffice_Eventscript_SophieOutroNorth::
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Move_SophieOutroNorth
	waitmovement 0
	return

VirtualCity_Work_YourOffice_Eventscript_SophieOutroWest::
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Work_YourOffice_Move_SophieOutroWest
	waitmovement 0
	return


VirtualCity_Work_YourOffice_Move_SophieOutroEast:
	walk_left
	walk_left
	face_right
	step_end

VirtualCity_Work_YourOffice_Move_SophieOutroNorth:
	walk_left
	walk_up
	walk_left
	walk_left
	face_right
	step_end

VirtualCity_Work_YourOffice_Move_SophieOutroWest:
	walk_down	
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	face_right
	step_end



VirtualCity_Work_YourOffice_Text_MinhACTIOutro1:
	.string "You're back! What did you find?$"

VirtualCity_Work_YourOffice_Text_SophieACTIOutro2:
	.string "…I got it.\p"
	.string "The scary part is, I don't think\n"
	.string "the artists even know.$"

VirtualCity_Work_YourOffice_Text_MinhACTIOutro3:
	.string "It's an unfinished Ponyta…\n"
	.string "But it's so detailed.\p"
	.string "Hi, lil' guy!$"

VirtualCity_Work_YourOffice_Text_SophieACTIOutro4:
	.string "Let get back to the outside.\n"
	.string "I bet this Ponyta comes with us.\p"
	.string "If it does, it's like Lola's Snubbull.\n"
	.string "Not real. Faked by {COLOR GREEN}BETTER.$"

VirtualCity_Work_YourOffice_Text_MinhACTIOutro5:
	.string "Let's meet up with the gang.\p"
	.string "I'll tell them to meet us at your\n"
	.string "apartment - they might have ideas.$"



VirtualCity_Work_YourOffice_Eventscript_Poster1::
	msgbox VirtualCity_Work_YourOffice_Text_Poster1, MSGBOX_SIGN
	end

VirtualCity_Work_YourOffice_Eventscript_Poster2::
	msgbox VirtualCity_Work_YourOffice_Text_Poster2, MSGBOX_SIGN
	end

VirtualCity_Work_YourOffice_Eventscript_RolandDesk::
	msgbox VirtualCity_Work_YourOffice_Text_RolandDesk, MSGBOX_SIGN
	end

VirtualCity_Work_YourOffice_Eventscript_RolandBook::
	msgbox VirtualCity_Work_YourOffice_Text_RolandBook, MSGBOX_SIGN
	end

VirtualCity_Work_YourOffice_Eventscript_YourDesk::
	msgbox VirtualCity_Work_YourOffice_Text_YourDesk, MSGBOX_SIGN
	end

VirtualCity_Work_YourOffice_Eventscript_YourBook::
	msgbox VirtualCity_Work_YourOffice_Text_YourBook, MSGBOX_SIGN
	end

VirtualCity_Work_YourOffice_Eventscript_MinhDesk::
	msgbox VirtualCity_Work_YourOffice_Text_MinhDesk, MSGBOX_SIGN
	end

VirtualCity_Work_YourOffice_Eventscript_MinhBook::
	msgbox VirtualCity_Work_YourOffice_Text_MinhBook, MSGBOX_SIGN
	end

VirtualCity_Work_YourOffice_Eventscript_BossDesk::
	msgbox VirtualCity_Work_YourOffice_Text_BossDesk, MSGBOX_SIGN
	end



VirtualCity_Work_YourOffice_Text_Poster1::
	.string "The {COLOR GREEN}BETTER{COLOR DARK_GRAY} Work Ethic:\p"
	.string "The things we make don't have to be\n"
	.string "just good; they have to be {COLOR GREEN}BETTER{COLOR DARK_GRAY}.$"

VirtualCity_Work_YourOffice_Text_Poster2::
	.string "NOTICE:\p"
	.string "Design, especially POKéMON Design, is\n"
	.string "{COLOR RED}highly{COLOR DARK_GRAY} confidential.\p"
	.string "Do not reveal details of any unreleased\n"
	.string "POKéMON to anyone outside this office.\p"
	.string "If you see something, say something.$"


VirtualCity_Work_YourOffice_Text_RolandDesk::
	.string "Ugh, it's Roland's desk.\p"
	.string "He's supposed to work on concepts, but\n"
	.string "he spends most of his time whining.$"

VirtualCity_Work_YourOffice_Text_RolandBook::
	.string "It's a sketch of Littlest Eevee, the\n"
	.string "best-selling POKéMON of all time.$"


VirtualCity_Work_YourOffice_Text_YourDesk::
	.string "Your desk is spotless, because\n"
	.string "organizing is easy in the Place.$"

VirtualCity_Work_YourOffice_Text_YourBook::
	.string "A thick guidebook on types, abilities,\n"
	.string "and everything POKéMON.$"


VirtualCity_Work_YourOffice_Text_MinhDesk::
	.string "Minh works here, and you can tell\n"
	.string "because of all the doodles of himself.$"

VirtualCity_Work_YourOffice_Text_MinhBook::
	.string "Minh's got a book of art styles here.\n"
	.string "Does he actually reference this?$"


VirtualCity_Work_YourOffice_Text_BossDesk::
	.string "As usual, the boss's computer is\n"
	.string "running some game.\p"
	.string "Looks like it's a factory sim today.$"
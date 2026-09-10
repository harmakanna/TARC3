OutsideWorld_ApartmentBldg1_YourApartment_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OutsideWorld_ApartmentBldg1_YourApartment_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_ApartmentBldg1_YourApartment_OnFrame
	.byte 0

OutsideWorld_ApartmentBldg1_YourApartment_OnTransition:
	@goto_if_set FLAG_PROLOGUE_COMPLETE, OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_NotFirstLoad
	end


OutsideWorld_ApartmentBldg1_YourApartment_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_PrologueEndScene
	map_script_2 VAR_PETALBURG_CITY_STATE, 5, OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_PrologueEndSceneButReallyThisTime
	map_script_2 VAR_PETALBURG_CITY_STATE, 20, OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_ActII_Opening
	.2byte 0


OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_PrologueEndScene::
	delay 10
	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk01Harriet, Speaker_Harriet, DIR_NORTH
	closemessage
	playbgm MUS_BW12_080, FALSE
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, OutsideWorld_AptBldg1_YourApt_Movement_WalkDownSlow2
	waitmovement 0
	applymovement LOCALID_LOLA, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	delay 10
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk02Sophie, SP_NAME_PLAYER, DIR_SOUTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartmenT_Text_IntroTalk02_1_Sophie, SP_NAME_PLAYER, DIR_EAST
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie01
	waitmovement 0
	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk03Ernest, Speaker_Ernest, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie001
	applymovement LOCALID_LOLA, Common_Movement_FaceDown
	playse SE_SELECT
	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk04Harriet, Speaker_Harriet, DIR_NORTH
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie1
	waitmovement 0
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk05Sophie, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk06Harriet, Speaker_Harriet, DIR_NORTH
	closemessage
	applymovement LOCALID_MINH, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	playse SE_EXIT
	delay 20
	addobject LOCALID_MINH
	delay 20
	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk1Minh, Speaker_Minh, DIR_WEST
	closemessage
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh1
	delay 10
	waitmovement 0 
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet1
	playse SE_LEDGE
	waitse
	waitmovement 0
	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk2Harriet, Speaker_Harriet, DIR_WEST
	playse SE_SELECT
	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk3Ernest, Speaker_Ernest, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk4Lola, Speaker_Lola, DIR_SOUTH
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh2
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie2
	applymovement LOCALID_HARRIET, Common_Movement_FaceUp
	playse SE_SELECT
	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk5Lola, Speaker_Lola, DIR_SOUTH
	closemessage
	playse SE_BALL_THROW
	addobject LOCALID_SNUBBULLS_BALL
	waitse
	delay 10
	playse SE_BALL_OPEN
	waitse
	removeobject LOCALID_SNUBBULLS_BALL
	addobject LOCALID_SNUBBULL
	playse SE_PIN
	applymovement LOCALID_MINH, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_HARRIET, Common_Movement_ExclamationMark
	applymovement LOCALID_ERNEST, Common_Movement_ExclamationMark
	waitse
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_SophieBackAway
	playmoncry SPECIES_SNUBBULL, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_SophieReturn

	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk6Lola, Speaker_Lola, DIR_SOUTH
	closemessage
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh3
	applymovement LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet2
	waitmovement 0
    applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest1
	waitmovement 0
	delay 50
	applymovement LOCALID_HARRIET, Common_Movement_Heart
	playse SE_PIN
	waitse
	delay 50

	applymovement LOCALID_SNUBBULL, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet1
	playse SE_LEDGE
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30

	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk7Harriet, Speaker_Harriet, DIR_WEST
	closemessage
	applymovement LOCALID_SNUBBULL, Common_Movement_Heart
	applymovement LOCALID_MINH, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	delay 50
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh4
	waitmovement 0
	delay 30
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh5
	waitmovement 0
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest2


	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk8Ernest, Speaker_Ernest, DIR_NORTH
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh6
	waitmovement

	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk9Lola, Speaker_Lola, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk10Lola, Speaker_Lola, DIR_WEST
	closemessage
	applymovement LOCALID_HARRIET, Common_Movement_FaceLeft
	applymovement LOCALID_ERNEST, Common_Movement_FaceLeft
	applymovement LOCALID_LOLA, Common_Movement_FaceLeft

	applymovement LOCALID_MINH, Common_Movement_FaceRight
	delay 20
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest3


	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk11Minh, Speaker_Minh, DIR_EAST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk12Sophie, SP_NAME_PLAYER, DIR_EAST
	closemessage
	playse SE_PIN
	applymovement LOCALID_HARRIET, Common_Movement_QuestionMark
	applymovement LOCALID_ERNEST, Common_Movement_QuestionMark
	waitmovement 0
	waitse
	delay 50

	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk13Lola, Speaker_Lola, DIR_SOUTH
	closemessage
	applymovement LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Move_Lola1
	applymovement LOCALID_SNUBBULL, OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull1
	delay 10
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh7
	waitmovement LOCALID_MINH
	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk14Lola, Speaker_Lola, DIR_SOUTH
	closemessage
	applymovement LOCALID_LOLA, Common_Movement_WalkUp
	applymovement LOCALID_SNUBBULL, OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull2
	opendoor 4,1
	playse SE_DOOR
	waitse
	waitdooranim
	applymovement LOCALID_LOLA, Common_Movement_WalkUp
	delay 8
	applymovement LOCALID_SNUBBULL, Common_Movement_WalkUp
	waitmovement LOCALID_LOLA
	removeobject LOCALID_LOLA
	playse SE_EXIT
	delay 8
	removeobject LOCALID_SNUBBULL
	playse SE_EXIT
	waitse
	closedoor 4,1
	waitdooranim
	delay 20

	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh8
	applymovement LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet3
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie3
	waitmovement
	delay 30
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest4
	waitmovement

	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk15Harriet, Speaker_Harriet, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk16Ernest, Speaker_Ernest, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk17Ernest, Speaker_Ernest, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk18Minh, Speaker_Minh, DIR_WEST

	playse SE_SELECT

	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk19Sophie, SP_NAME_PLAYER, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk20Harriet, Speaker_Harriet, DIR_NORTH
	closemessage
	applymovement LOCALID_ERNEST, Common_Movement_FaceLeft
	applymovement LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet4
	delay 40
	removeobject LOCALID_HARRIET
	playse SE_EXIT
	delay 10

	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk21Ernest, Speaker_Ernest, DIR_NORTH
	closemessage
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest5
	waitmovement
	delay 50

	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk21pt5Ernest, Speaker_Ernest, DIR_EAST
	closemessage
	applymovement LOCALID_ERNEST, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	removeobject LOCALID_ERNEST
	playse SE_EXIT
	delay 20

	fadenewbgm MUS_NONE
	delay 120
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
	waitmovement LOCALID_CAMERA
	special RemoveCameraObject
	@Discuss with Minh
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh9
	waitmovement

	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk22Minh, Speaker_Minh, DIR_EAST
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie4
	waitmovement

	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk23Sophie, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk24Minh, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk25Sophie, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk26Minh, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk27Sophie, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk28Sophie, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk29Sophie, SP_NAME_PLAYER, DIR_EAST
	delay 50
	fadescreenspeed FADE_TO_BLACK, 5
	closemessage
	setvar VAR_PETALBURG_CITY_STATE, 3
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	clearflag FLAG_PROLOGUE_COMPLETE
	clearflag FLAG_HIDE_LOLA_BEDROOM_PROLOGUE
	setflag FLAG_SYS_PREVENT_MAP_FADE
	warpsilent MAP_OUTSIDE_WORLD, 22, 20
	waitstate

	
	end








OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_NotFirstLoad::
	end


OutsideWorld_AptBldg1_YourApt_Movement_WalkDownSlow2:
	walk_slow_down
	walk_slow_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh2:
	walk_right
	walk_down
	walk_down
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh3:
	walk_up
	walk_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh4:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh5:
	walk_up
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh6:
	face_left
	delay_16
	delay_16
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh7:
	walk_left
	face_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh8:
	walk_right
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh9:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie01:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie001:
	walk_right
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie1:
	walk_down
	walk_right
	walk_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie2:
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie3:
	walk_up
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie4:
	walk_down
	walk_right
	walk_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_SophieBackAway:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_SophieReturn:
	walk_right
	step_end


OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet1:
	jump_in_place_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet2:
	walk_up
	face_left
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet3:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet4:
	walk_left
	walk_left
	face_down
	delay_16
	step_end



OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest1:
	walk_up
	face_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest2:
	walk_up
	walk_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest3:
	walk_left
	walk_down
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest4:
	walk_up
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest5:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest6:
	walk_down
	step_end


OutsideWorld_ApartmentBldg1_YourApartment_Move_Lola1:
	walk_down
	walk_left
	walk_left
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Lola2:
	walk_up
	delay_16
	walk_up
	step_end	


OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull1:
	walk_up
	walk_down
	walk_left
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull2:
	walk_left
	face_up
	step_end


OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull3:
	walk_up
	walk_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk01Harriet::
	.string "She's here!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk02Sophie::
	.string "Hey!\p"
	.string "We just finished up. Minh got a head\n"
	.string "start, so he'll be here any minute.$"

OutsideWorld_ApartmentBldg1_YourApartmenT_Text_IntroTalk02_1_Sophie:
	.string "We're excited for your big day, Lola!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk03Ernest::
	.string "Lola hasn't said a word…\n"
	.string "She's just been smiling.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk04Harriet::
	.string "Sophie, we were just discussing…\p"
	.string "When was the last time you saw a\n"
	.string "POKéMON, you know, in real life?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk05Sophie::
	.string "Gosh, I don't even remember.\p"
	.string "It must have been when I was a child,\n"
	.string "before the zoo closed down.\p"
	.string "What about you?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk06Harriet::
	.string "I don't think I've ever seen one,\n"
	.string "and Ernest claims-$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk1Minh::
	.string "Hahhh… hahhh…\p"
	.string "I made it!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk2Harriet::
	.string "Finally, Minh! Lola, come on, we've\n"
	.string "been waiting for so long!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk3Ernest::
	.string "To be fair… she's been waiting…{PAUSE 50}\n"
	.string "for twenty-two years.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk4Lola::
	.string "…\p"
	.string "It's been a long time.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk5Lola::
	.string "You all know better than anyone how\n"
	.string "much I wanted a real POKéMON.\p"
	.string "So many people called it a stupid,\n"
	.string "unrealistic dream.\p"
	.string "Back then, I couldn't explain why it\n" 
	.string "felt so… {PAUSE 40}so necessary.\p"
	.string "Well, I still can't explain it.\n"
	.string "But look at him!$"
	
OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk6Lola::
	.string "Go on, pet him! Like you would a\n"
	.string "VR POKéMON. He's super friendly!\p"
	.string "And you'll understand it.\n"
	.string "Why real POKéMON are so important.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk7Harriet::
	.string "OMG he's so precious! And warm!\n"
	.string "His fur feels like a blanket!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk8Ernest::
	.string "What's…{PAUSE 30} his name, Lola?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk9Lola::
	.string "Dreams. Dreams the Snubbull.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk10Lola::
	.string "Hey, don't be shy, you two!\p"
	.string "You're all going to be his aunts and\n"
	.string "uncles, come say hi!$"


OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk11Minh::
	.string "…\p"
	.string "Um, hi there Dreams. Lola's going to\n"
	.string "take very good care of you!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk12Sophie::
	.string "Yes, she will. It…\n"
	.string "Ahem, welcome to our little group?$"	


OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk13Lola::
	.string "Don't worry, Dreams, I'm sure they'll\n"
	.string "be less shy tomorrow. Now come on,\l"
	.string "you haven't even seen our room yet!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk14Lola::
	.string "Goodnight! See y'all tomorrow!$"




OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk15Harriet::
	.string "It was so cute! And I've never seen\n"
	.string "Lola so happy!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk16Ernest::
	.string "No one deserves it more than Lola.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk17Ernest::
	.string "Hey, what's the matter? Minh? Sophie?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk18Minh::
	.string "Sophie? You…$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk19Sophie::
	.string "It's nothing.\n"
	.string "We've just had a long day at work.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk20Harriet::
	.string "Ah, no worries. Anyways, I gotta jet.\n"
	.string "Let's celebrate with Lola tomorrow!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk21Ernest::
	.string "Hm.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk21pt5Ernest::
	.string "I know something's up.\n"
	.string "Tell me about it later.$"


OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk22Minh::
	.string "Sophie? You…{PAUSE 50} you saw it too?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk23Sophie::
	.string "I saw it.\p"
	.string "There's…{PAUSE 20} there's no doubt.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk24Minh::
	.string "The eyes…{PAUSE 30} they were wrong.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk25Sophie::
	.string "The mouth, too.\p"
	.string "That's…{PAUSE 20} that's not a real Snubbull.\p"
	.string "It looked…{PAUSE 50} drawn.\p"
	.string "Like the VR POKéMON you design…\n"
	.string "but not as skillful.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk26Minh::
	.string "Are you saying… does {COLOR GREEN}BETTER{COLOR DARK_GRAY} have a\n"
	.string "way to make fake IRL POKéMON?!\p"
	.string "And Lola just got scammed out of her\n"
	.string "life savings on one?!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk27Sophie::
	.string "Minh, hush!\n"
	.string "The walls aren't that thick.\p"
	.string "And… there's something here even\n"
	.string "worse than Lola getting scammed.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk28Sophie::
	.string "We haven't seen any POKéMON in years.\n"
	.string "Real ones, I mean.\p"
	.string "And when we finally see one, it's a\n"
	.string "very convincing fake.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk29Sophie::
	.string "Minh…\p"
	.string "{COLOR RED}Are there even any real POKéMON left?$"






@@ ACT II INTRO






OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_ActII_Opening::
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	waitmovement 0
	fadescreenspeed FADE_FROM_BLACK, 5
	delay 100
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro1, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_A2_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_ErnestActIIIntro2, Speaker_Ernest, DIR_EAST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro3, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_A2_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro4, Speaker_Harriet, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro5, SP_NAME_PLAYER, DIR_WEST
	closemessage

	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_ActIII_Opening1
	waitmovement 0
	applymovement LOCALID_A2_ERNEST, Common_Movement_FaceUp
	applymovement LOCALID_A2_HARRIET, Common_Movement_FaceUp
	applymovement LOCALID_A2_MINH, Common_Movement_FaceUp

	addobject LOCALID_SNUBBULLS_BALL
	delay 10
	playse SE_BALL_OPEN
	waitse
	removeobject LOCALID_SNUBBULLS_BALL
	addobject LOCALID_PONYTA_A2
	applymovement LOCALID_A2_HARRIET, Common_Movement_ExclamationMark
	applymovement LOCALID_A2_ERNEST, Common_Movement_ExclamationMark
	playse SE_SELECT
	waitse
	waitmovement 0
	delay 50
	playmoncry SPECIES_PONYTA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20

	applymovement LOCALID_A2_MINH, Common_Movement_FaceDown
	applymovement LOCALID_A2_ERNEST, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	speak LOCALID_A2_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro6, Speaker_Harriet, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_A2_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro7, Speaker_Harriet, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_A2_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_MinhActIIIntro8, Speaker_Minh, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_A2_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_ErnestActIIIntro9, Speaker_Ernest, DIR_NORTH

	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro10, SP_NAME_PLAYER, DIR_SOUTH
	closemessage
	applymovement LOCALID_A2_MINH, Common_Movement_FaceUp
	waitmovement 0
	delay 100
	speak LOCALID_A2_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_MinhActIIIntro11, Speaker_Minh, DIR_SOUTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro12, SP_NAME_PLAYER, DIR_SOUTH
	closemessage
	setflag FLAG_HIDE_ACT_II_INTRO_CHARS
	clearflag FLAG_ACT_II_HIDE_HOTEL_FRIENDS
	setvar VAR_PETALBURG_CITY_STATE, 21
	fadescreenspeed FADE_TO_BLACK, 5
	delay 60
	setflag FLAG_SYS_PREVENT_MAP_FADE
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	special RemoveCameraObject
	warpsilent MAP_VIRTUAL_CITY_HOTEL_YOUR_ROOM, 12, 9
	waitstate
	
	end


OutsideWorld_ApartmentBldg1_YourApartment_Move_ActIII_Opening1:
	walk_up
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	step_end




OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro1::
	.string "Harriet. Ernest. Thanks for coming.\n"
	.string "We don't have long until Lola gets home.\p"
	.string "Minh and I have some news.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_ErnestActIIIntro2::
	.string "What, are you dating?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro3::
	.string "What? No!\n"
	.string "It's very bad news, Ernest!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro4::
	.string "What? What is it?\n"
	.string "Sophie, you're shaking!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro5::
	.string "When Lola showed us her Snubbull, Minh\n"
	.string "and I both noticed something wrong.\p"
	.string "So we did some digging…{PAUSE 40}and…$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro6::
	.string "What? You got one? How did you afford…$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro7::
	.string "AAAAH!\pWhat is…\n…{PAUSE 50}Why is it unfinished?!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_MinhActIIIntro8::
	.string "Because it's not real. {COLOR GREEN}BETTER{COLOR DARK_GRAY} has a way\n"
	.string "to make IRL fakes now, somehow.\p"
	.string "And they're being sold as real.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_ErnestActIIIntro9::
	.string "Fakes? You mean, Lola's Snubbull isn't\n"
	.string "a real flesh-and-blood POKéMON?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro10::
	.string "Yeah.\pMinh and I are going to do\n"
	.string "something about it.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_MinhActIIIntro11::
	.string "What Sophie MEANS is that she wanted\n"
	.string "to go in guns blazing.\p"
	.string "I managed to convince her that you two\n"
	.string "would want to help.\p"
	.string "…{PAUSE 30}And help me stop her from doing\n"
	.string "something really dangerous.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro12::
	.string "We can't talk here, Lola's gonna be back\n"
	.string "soon. Meet at my Place.$"






OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_PrologueEndSceneButReallyThisTime::
	delay 20
	setspeaker SP_NAME_PLAYER
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Text_PrologueEndSceneButReallyThisTime, MSGBOX_DEFAULT
	closemessage
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_PROLOGUE
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_ACTI
	setvar VAR_PETALBURG_CITY_STATE, 10
	end

OutsideWorld_ApartmentBldg1_YourApartment_Text_PrologueEndSceneButReallyThisTime::
	.string "I gotta log in to the Place and figure\n"
	.string "out how this could have happened.\p"
	.string "…{PAUSE 30}I really hope Lola's asleep.$"


OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_Lola_Coupon::
	faceplayer
	setspeaker Speaker_Lola
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon1, MSGBOX_DEFAULT
	playse SE_SELECT
	setspeaker SP_NAME_PLAYER
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon2, MSGBOX_DEFAULT
	playse SE_SELECT
	setspeaker Speaker_Lola
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon3, MSGBOX_DEFAULT
	playse SE_SELECT
	additem ITEM_SPELL_TAG, 1
	setspeaker NULL
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Stadium_Entrance_Text_ReceivedCoupon
	waitfanfare
	delay 100
	setspeaker Speaker_Lola
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon4, MSGBOX_DEFAULT
	playse SE_SELECT
	setspeaker SP_NAME_PLAYER
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon5, MSGBOX_DEFAULT
	playse SE_SELECT
	setspeaker Speaker_Lola
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon6, MSGBOX_DEFAULT
	playse SE_SELECT
	setspeaker Speaker_Lola
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon7, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LOLA_COUPON, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	removeobject LOCALID_LOLA_COUPON
	playse SE_EXIT
	delay 20
	setflag FLAG_HIDE_LOLA_APT_COUPON
	end

OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon1::
	.string "Sophie! Just who I wanted to see.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon2::
	.string "Oh, um, hi Lola.\p"
	.string "How's, uh, how's Dreams doing?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon3::
	.string "A little tuckered out, the poor thing!\n"
	.string "The way he sleeps is {PAUSE 30}s{PAUSE 5}o{PAUSE 5}o{PAUSE 5}o{PAUSE 5}o {PAUSE 10}cute!!!\p"
	.string "But anyway, I wanted you to have this.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon4::
	.string "It's a redeem code for a free Pokemon\n"
	.string "from the BETTER Superstore.\p"
	.string "It was kinda my backup plan, you know?\p"
	.string "But now I've got Dreams, and I can tell\n"
	.string "I'll never want a VR Pokemon again.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon5::
	.string "Lola, I can't accept-$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon6::
	.string "Oh, shut it. You let me use your stuff\n"
	.string "so many times while I was saving up,\l"
	.string "it's practically a drop in the bucket.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_Lola_Coupon7::
	.string "Now, I gotta run. We're taking the train\n"
	.string "to the park today!$"

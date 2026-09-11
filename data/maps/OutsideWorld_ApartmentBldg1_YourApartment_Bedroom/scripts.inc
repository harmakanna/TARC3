OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_OnFrame
	.byte 0

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 40, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaConfronts
	.2byte 0




OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaConfronts::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	delay 60
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreenspeed FADE_FROM_BLACK, 2

    delay 80
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts1, Speaker_Lola, DIR_EAST
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
    waitse
    delay 60

	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts2, SP_NAME_PLAYER, DIR_WEST
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer1
	waitmovement 0
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts3, Speaker_Lola, DIR_EAST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts4, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts5, Speaker_Lola, DIR_EAST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts6, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts7, Speaker_Lola, DIR_EAST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts8, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts9, Speaker_Lola, DIR_EAST
	playse SE_SELECT
	setspeaker SP_NAME_PLAYER
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts8, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaTellHer
    goto_if_eq VAR_RESULT, NO, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaDontTellHer
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaTellHer::
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer1, SP_NAME_PLAYER, DIR_WEST
	closemessage
	fadescreen FADE_TO_BLACK
	delay 100
	addobject LOCALID_BEDROOM_MINH
	addobject LOCALID_BEDROOM_HARRIET
	addobject LOCALID_BEDROOM_ERNEST
	fadescreen FADE_FROM_BLACK
	delay 100

	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer2, Speaker_Lola, DIR_EAST
	playse SE_SELECT
	playbgm MUS_BW12_UNWAVERING_EMOTIONS, FALSE
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer2_1, MSGBOX_DEFAULT
	speak LOCALID_BEDROOM_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer3, Speaker_Ernest, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer4, Speaker_Harriet, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer5, Speaker_Lola, DIR_EAST
	playse SE_SELECT
	speak LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer6, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer7, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer8, Speaker_Harriet, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer9, Speaker_Lola, DIR_EAST
	closemessage

	applymovement LOCALID_BEDROOM_LOLACONFRONT, Common_Movement_WalkRight
	waitmovement 0
	delay 60
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer10, Speaker_Lola, DIR_EAST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer11, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer12, Speaker_Lola, DIR_EAST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer13, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer14, Speaker_Lola, DIR_SOUTH
	closemessage
	applymovement LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer2
	delay 16
	applymovement LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer3
	delay 32
	playse SE_EXIT
	removeobject LOCALID_BEDROOM_LOLACONFRONT
	delay 32
	applymovement LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer4
	waitmovement 0
	applymovement LOCALID_BEDROOM_MINH, Common_Movement_FaceDown
	delay 90
	speak LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer15, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer16, Speaker_Harriet, DIR_NORTH

	@TOFOLDGIVEMON
	givemon SPECIES_SNUBBULL, 50, nature=NATURE_ADAMANT, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_PLAY_ROUGH, move2=MOVE_CRUNCH, move3=MOVE_HOWL, move4=MOVE_ROAR, nickname=Nickname_Dreams, otName=OT_Lola
	setflag FLAG_ACT_III_TELL_LOLA
	applymovement LOCALID_BEDROOM_ERNEST, Common_Movement_WalkInPlaceDown
	playse SE_SELECT
	goto OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_Mission
	end



OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaDontTellHer::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer1, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer2, Speaker_Lola, DIR_EAST
	closemessage

	applymovement LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer3
	delay 32
	playse SE_EXIT
	removeobject LOCALID_BEDROOM_LOLACONFRONT
	delay 100

	playse SE_DOOR
	addobject LOCALID_BEDROOM_ERNESTDONTTELL
	delay 16
	applymovement LOCALID_BEDROOM_ERNESTDONTTELL, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaDontTellHer1
	delay 16
	playse SE_DOOR
	addobject LOCALID_BEDROOM_HARRIETDONTTELL
	delay 16
	applymovement LOCALID_BEDROOM_HARRIETDONTTELL, Common_Movement_WalkUp
	delay 32
	playse SE_DOOR
	addobject LOCALID_BEDROOM_MINHDONTTELL
	delay 16
	applymovement LOCALID_BEDROOM_MINHDONTTELL, Common_Movement_WalkUp
	delay 16

	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	speak LOCALID_BEDROOM_MINHDONTTELL, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer3, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_HARRIETDONTTELL, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer4, Speaker_Harriet, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer5, SP_NAME_PLAYER, DIR_WEST
	closemessage
	delay 90
	speak LOCALID_BEDROOM_ERNESTDONTTELL, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission0, Speaker_Ernest, DIR_SOUTH
	playse SE_SELECT
	
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	setspeaker Speaker_Ernest
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission1, MSGBOX_DEFAULT
	@playse SE_SELECT
	@speak LOCALID_BEDROOM_ERNESTDONTTELL, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission2, Speaker_Ernest, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_MINHDONTTELL, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission3, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_HARRIETDONTTELL, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission4, Speaker_Harriet, DIR_NORTH
	closemessage
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	clearflag FLAG_ACT_III_HIDE_BEDROOM_FRIENDS
	setvar VAR_PETALBURG_CITY_STATE, 41

	end




OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_Mission::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	setspeaker Speaker_Ernest
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission1, MSGBOX_DEFAULT
	@playse SE_SELECT
	@speak LOCALID_BEDROOM_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission2, Speaker_Ernest, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission3, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission4, Speaker_Harriet, DIR_NORTH
	closemessage
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	clearflag FLAG_ACT_III_HIDE_BEDROOM_FRIENDS
	setvar VAR_PETALBURG_CITY_STATE, 41
	end





OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer1:
	walk_down
	walk_left
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer2:
	walk_down
	walk_left
	face_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer3:
	walk_down
	walk_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer4:
	walk_right
	walk_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaDontTellHer1:
	walk_up
	walk_up	
	walk_right
	walk_up
	face_down
	step_end

OutsideWorld_ApartmentBldg_YourBedroom_LolaIdle::
	lock
	msgbox OutsideWorld_ApartmentBldg_YourBedroom_Text_LolaIdle, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_BEDROOM_LOLAIDLE, Common_Movement_Heart
	waitmovement 0
	waitse
	delay 50
	release
	end

OutsideWorld_ApartmentBldg_YourBedroom_Text_LolaIdle:
	.string "Snubbull-snubble Snubbubble!\n"
	.string "Dreamy little Dreams!\p"
	.string "I love you!$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts1:
	.string "Sophie.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts2:
	.string "Lola!$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts3:
	.string "Sophie, please tell me what's going on.\p"
	.string "I feel like ever since I got Dreams…\n"
	.string "You've been avoiding me.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts4:
	.string "I just… I…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts5:
	.string "And it's not just you!\n"
	.string "It's… all of you. All my friends.\p"
	.string "I know it's not jealousy.\p And it's not fear.\pDid I do something wrong?\p"
	.string "I know I spent a lot of credits I\n"
	.string "could've used for something better…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts6:
	.string "Lola, it's nothing like that…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts7:
	.string "Is it because it's unethical to keep a\n"
	.string "POKéMON in an apartment this small?\p"
	.string "…I can't give him up!\p"
	.string "I CAN'T, Sophie!\p"
	.string "He's become my whole world!$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts8:
	.string "…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts9:
	.string "Will you tell me what's wrong?\n{PAUSE 70}Please.$"


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts10:
	.string "…{PAUSE 60}$"


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer1:
	.string "I… I will. You should… sit down.\p"
	.string "…\p"
	.string "When you introduced us to Dreams, Minh\n"
	.string "and I noticed something…$"

@ SKIP

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer2:
	.string "… … …\n"
	.string "…{PAUSE 50} …{PAUSE 50} …{PAUSE 50}Snivel…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer2_1:
	.string "WAAAAAAAAAAAAAH!!!$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer3:
	.string "It's terribly cruel.\p"
	.string "But you know how much Sophie loves Ex.\n"
	.string "Virtual POKéMON can be worthy of love.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer4:
	.string "Listen to them, Lola.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer5:
	.string "-Sniff-…\pAre there even any POKéMON left?!$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer6:
	.string "We don't know that! We can't know it.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer7:
	.string "That's why this plan is so important.\p"
	.string "If we can spread the word, we can get\n"
	.string "more powerful people on the case.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer8:
	.string "And we can get revenge on them for\n"
	.string "stealing from you.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer9:
	.string "…{PAUSE 40}Hic…\p"
	.string "I've decided…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer10:
	.string "Dreams, go with Sophie.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer11:
	.string "What! Lola, this is your…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer12:
	.string "You think I'm going to sit back and let\n"
	.string "you destabilize {COLOR GREEN}BETTER{COLOR DARK_GRAY} without me?\p"
	.string "Dreams has a nasty bite. Put it to\n"
	.string "good use.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer13:
	.string "…Thanks, Lola.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer14:
	.string "Now. I need to clear my head.\p"
	.string "Now that it looks like my life's\n"
	.string "central ambition was a BIG FAT LIE…\p"
	.string "I need to think about what I'm\n"
	.string "going to do.\p"
	.string "Good luck.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer15:
	.string "She's gone.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer16:
	.string "She'll be okay. Tough as nails,\n"
	.string "that one.$"




OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer1:
	.string "I… can't tell you.\p"
	.string "…\p"
	.string "We're in the middle of something\n"
	.string "very important, and it can't wait.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer2:
	.string "I see.\p"
	.string "Well, I'll leave you to it, then.$"


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer3:
	.string "Lola looked upset.\n"
	.string "She didn't even acknowledge us.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer4:
	.string "Sophie, you didn't tell her, did you?$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer5:
	.string "No, I… I didn't.\p"
	.string "Maybe it's kinder to not tell her…\p"
	.string "… … …$"




OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission0:
	.string "… … …\p"
	.string "Anyways… … …$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission1:
	.string "Back to the mission.\p"
	.string "The new identity is ready, and I set\n"
	.string "it to spawn in the {COLOR GREEN}BETTER{COLOR DARK_GRAY} Office.\p"
	.string "You should be able to open the eastern\n"
	.string "security door and go up the stairs.\p"
	.string "There's probably a lot of guards there,\n"
	.string "and a lot of control panels.\p"
	.string "Keep climbing until you find the Rotom\n"
	.string "Phone controls, and use this USB\l"
	.string "to upload a message.\p"
	.string "You can go back in to if you need to\n"
	.string "prepare, but if not, I'll start it up.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission3:
	.string "Beat 'em up, Sophie.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission4:
	.string "You got this!!$"


OutsideWorld_ApartmentBldg1_YourAparment_Bedroom_EventScript_ActIII_Harriet::
	setspeaker Speaker_Harriet
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission4, MSGBOX_NPC
	end

OutsideWorld_ApartmentBldg1_YourAparment_Bedroom_EventScript_ActIII_Minh::
	setspeaker Speaker_Minh
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission3, MSGBOX_NPC
	end
	
OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_Ernest::
	lock
	faceplayer
	setspeaker Speaker_Ernest
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Ernest1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_Eventscript_Cancel
	player_speak OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_SophieReady
	playse SE_SELECT
	npc_speak Speaker_Ernest, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_ErnestGoodLuck
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	call_if_eq VAR_FACING, DIR_WEST, ActIII_EventScript_FacePC
	call_if_ne VAR_FACING, DIR_WEST, ActIII_EventScript_WalkToPC
	fadenewbgm MUS_NONE
	delay 20
	fadescreenspeed FADE_TO_BLACK, 2
	delay 120
	playse SE_PC_LOGIN
	waitse
	setspeaker Speaker_PC
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PCGlitchWarp, MSGBOX_DEFAULT
	@playmoncry SPECIES_ELECTABUZZ, CRY_MODE_ENCOUNTER
	playbgm MUS_VS_REGI, FALSE
	callnative StartBlueScreen
	message OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PCGlitchWarp2
	waitmessage
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_ENCOUNTER
	message OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PCGlitchWarp3
	waitmessage
	setflag FLAG_SPOOFING_EXECUTIVE
	setflag FLAG_ACT_III_POINTOFNORETURN
	setvar VAR_VIRTUAL_CITY_OUTSIDE_STATE, 1
	setvar VAR_PETALBURG_CITY_STATE, 50
	entervr_warp MAP_VIRTUAL_CITY_OUTSIDE1, 24, 25
	waitstate
	end

ActIII_EventScript_FacePC::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

ActIII_EventScript_WalkToPC::
	applymovement LOCALID_PLAYER, ActIII_Movement_WalkToPC
	waitmovement 0
	return

ActIII_Movement_WalkToPC:
	walk_right
	walk_up
	step_end
	
Speaker_PC:
	.string "PC$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Ernest1:
	.string "If you go into VR now,\n"
	.string "{COLOR RED}you won't be able to return.\p"
	.string "{COLOR DARK_GRAY}Make sure you've finished up\n"
	.string "{COLOR RED}EVERYTHING{COLOR DARK_GRAY} you need to do first.\p"
	.string "Are you ready?$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_SophieReady:
	.string "Ready as I'll ever be.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_ErnestGoodLuck:
	.string "Alright Sophie.\p"
	.string "Good luck in there.$"
	
OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_PC::
	lockall
	goto_if_eq VAR_PETALBURG_CITY_STATE, 2, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_NoVRNow
	@many more situations where you need to disable this temporarily TOFOLD
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_Eventscript_Cancel
	closemessage
	goto_if_unset FLAG_FIRST_VR_WARP, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_PCFirstWarp
	@@ Fancy transition TOFOLD
	entervr_warp MAP_VIRTUAL_CITY_OUTSIDE1, 24, 25
	waitstate
	end


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PCGlitchWarp:
	.string "Verifying identity…{PAUSE 50} …{PAUSE 50} …{PAUSE 50} …\p"
	.string "{COLOR RED}-ERROR-\p"
	.string "-ERROR--ERROR--ERROR-\n"
	.string "-ERROR--ERROR--ERROR-\p"
	.string "CANNOT VERI-dwÂd…sÓ89u…fgjkiÓ…Âs$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PCGlitchWarp2:
	.string "{COLOR RED}ÉÉÉ{COLOR GREEN}ÉÉÉÉÉÉ{COLOR GREEN}ÉÉÉ{COLOR RED}ÉÉÉÉÉÉ{COLOR BLUE}ÉÉÉÉ{COLOR GREEN}ÉÉÉÉÉÉÉÉÉÉ{COLOR RED}ÉÉÉÉÉÉ{COLOR GREEN}ÉÉÉ{COLOR RED}ÉÉÉ{COLOR BLUE}ÉÉÉÉÉÓÂ{COLOR RED}yÓÂyÓÂyÓÂyÓÂy{COLOR GREEN}ÓÂyÓÂyÓÂy\n"
	.string "ÉÉÉÉÉ{COLOR RED}ÉÉÉÉÉ{COLOR BLUE}É{COLOR RED}É{COLOR BLUE}ÉÉ{COLOR GREEN}É{COLOR BLUE}ÉÉÉ{COLOR RED}ÉÉÉÉÉ{COLOR BLUE}ÉÉÉÉÉ{COLOR RED}ÉÉÉÉÉÉÉ{COLOR GREEN}ÉÉÉÉÉÉÉ{COLOR BLUE}ÉÉÉÉÉÉÉ{COLOR RED}ÓÂyÓÂyÓÂyÓÂyÓÂyÓÂ{COLOR BLUE}yÓÂyÓÂy$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PCGlitchWarp3:
	.string "{COLOR RED}ÓÂyÓÂy{COLOR GREEN}ÓÂyÓÂyÓ{COLOR BLUE}ÂyÓÂyÓÂyÓÂyFFFFF-$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_PCFirstWarp::
	fadescreenspeed FADE_TO_BLACK, 2
	delay 80
	playse SE_PC_LOGIN
	waitse
	setspeaker Speaker_PC
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PCFirstWarp, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_FIRST_VR_WARP
	entervr_warp MAP_VIRTUAL_CITY_OUTSIDE1, 24, 25
	waitstate
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PCFirstWarp:
	.string "Verifying identity…{PAUSE 50} …{PAUSE 50} …{PAUSE 50} …\p"
	.string "Identity verified.\p"
	.string "Welcome back to the {COLOR GREEN}BETTER Place{COLOR DARK_GRAY},\n"
	.string "{COLOR BLUE}{PLAYER}!$"

Common_Eventscript_Cancel::
	closemessage
	releaseall
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PC:
	.string "Enter VR?$"


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_NoVRNow::
	setspeaker SP_NAME_PLAYER
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_NoVRNow, MSGBOX_SIGN
	closemessage
	end


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_NoVRNow:
	.string "I just logged off!\n"
	.string "I don't need to go back in!$"



OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_Diary::
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_Diary, MSGBOX_SIGN
	closemessage
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_Diary:
	.string "It's Lola's diary, lying open.\n"
	.string "She wears her heart on her sleeve.$"


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_PrologueLola::
	setspeaker Speaker_Lola
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PrologueLola, MSGBOX_NPC
	applymovement LOCALID_BEDROOM_LOLAPROLOGUE, Common_Movement_FaceUp
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PrologueLola:
	.string "It's everything I imagined. It feels\n"
	.string "so right, to have a POKéMON companion.\p"
	.string "…You going back into the BETTER Place\n"
	.string "tonight? Don't stay up too late.$"





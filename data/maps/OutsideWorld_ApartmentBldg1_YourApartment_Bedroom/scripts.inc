OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_OnFrame
	.byte 0

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 40, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaConfronts
	.2byte 0



OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaConfronts::
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts1, Speaker_Lola, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts2, Speaker_Sophie, DIR_WEST
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts3, Speaker_Lola, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts4, Speaker_Sophie, DIR_WEST
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts5, Speaker_Lola, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts6, Speaker_Sophie, DIR_WEST
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts7, Speaker_Lola, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts8, Speaker_Sophie, DIR_WEST
	setspeaker Speaker_Lola
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts9, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaTellHer
    goto_if_eq VAR_RESULT, YES, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaDontTellHer
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaTellHer::
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer1
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer1, Speaker_Sophie, DIR_WEST
	fadescreen FADE_TO_BLACK
	delay 100
	addobject LOCALID_BEDROOM_MINH
	addobject LOCALID_BEDROOM_HARRIET
	addobject LOCALID_BEDROOM_ERNEST
	fadescreen FADE_FROM_BLACK
	delay 100

	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer2, Speaker_Lola, DIR_EAST
	speak LOCALID_BEDROOM_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer3, Speaker_Ernest, DIR_SOUTH
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer4, Speaker_Harriet, DIR_NORTH
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer5, Speaker_Lola, DIR_EAST
	speak LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer6, Speaker_Minh, DIR_NORTH
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer7, Speaker_Sophie, DIR_WEST
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer8, Speaker_Harriet, DIR_NORTH
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer9, Speaker_Lola, DIR_EAST

	applymovement LOCALID_BEDROOM_LOLACONFRONT, Common_Movement_WalkRight

	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer10, Speaker_Lola, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer11, Speaker_Sophie, DIR_WEST
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer12, Speaker_Lola, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer13, Speaker_Sophie, DIR_WEST
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer14, Speaker_Lola, DIR_SOUTH

	applymovement LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer2
	delay 16
	applymovement LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer3
	delay 32
	playse SE_EXIT
	removeobject LOCALID_BEDROOM_LOLACONFRONT
	delay 32
	applymovement LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer4

	speak LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer15, Speaker_Minh, DIR_NORTH
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer16, Speaker_Harriet, DIR_NORTH
	givemon SPECIES_SNUBBULL, 50
	setflag FLAG_ACT_III_TELL_LOLA
	goto OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_Mission
	end



OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_LolaDontTellHer::
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer1, Speaker_Sophie, DIR_WEST
	speak LOCALID_BEDROOM_LOLACONFRONT, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer2, Speaker_Lola, DIR_EAST

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

	speak LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer3, Speaker_Minh, DIR_NORTH
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer4, Speaker_Harriet, DIR_NORTH
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaDontTellHer5, Speaker_Sophie, DIR_WEST
	goto OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_Mission
	end




OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_Mission::
	speak LOCALID_BEDROOM_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission1, Speaker_Ernest, DIR_SOUTH
	speak LOCALID_BEDROOM_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission2, Speaker_Ernest, DIR_SOUTH
	speak LOCALID_BEDROOM_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission3, Speaker_Minh, DIR_NORTH
	speak LOCALID_BEDROOM_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission4, Speaker_Harriet, DIR_NORTH
	setflag FLAG_ACT_III_POINTOFNORETURN
	clearflag FLAG_ACT_III_HIDE_BEDROOM_FRIENDS
	end





OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer1:
	walk_down
	walk_left
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Move_LolaTellHer2:
	walk_down
	walk_left
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
	.string "I know it's not jealousy. It's not$"
	.string "fear. Did I do something wrong?$"
	.string "I know I spent a lot of credits that$"
	.string "I could have used for a better cause…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts6:
	.string "Lola, it's nothing like that…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts7:
	.string "Is it because it's unethical to keep a\n"
	.string "Pokemon in an apartment this small?\p"
	.string "Because I can't give him up. I can't,\n"
	.string "Sophie. He's become my whole world.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts8:
	.string "…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaConfronts9:
	.string "Will you tell me what's wrong? Please.$"





OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer1:
	.string "I… I will. You should… sit down.\p"
	.string "…\p"
	.string "When you introduced us to Dreams, Minh\n"
	.string "and I noticed something…$"

@ SKIP

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer2:
	.string "It's all a lie. It was all for nothing.\n"
	.string "It was all I wanted, and now…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer3:
	.string "It's terribly cruel.\p"
	.string "But you know how much Sophie loves Ex.\n"
	.string "Virtual Pokemon can be worthy of love.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer4:
	.string "Listen to them, Lola.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer5:
	.string "There may not even be any Pokemon left!$"

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
	.string "…\p"
	.string "I've decided.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer10:
	.string "Dreams, go with Sophie.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer11:
	.string "What! Lola, this is your…$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer12:
	.string "You think I'm going to sit back and let\n"
	.string "you destabilize BETTER without me?\p"
	.string "Dreams has a nasty bite. Put it to\n"
	.string "good use.\p"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer13:
	.string "…Thanks, Lola.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer14:
	.string "Now. I need to clear my head.$"
	.string "Now that it looks like my life's\n"
	.string "central ambition was a lie, I need to\l"
	.string "think about what I'm going to do.\p"
	.string "Good luck.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer15:
	.string "She's gone.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_LolaTellHer16:
	.string "She'll be okay. Tough as nails,$"
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
	.string "Maybe it's kinder to not tell her.$"





OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission1:
	.string "Back to the mission.\p"
	.string "The new identity is ready, and I set\n"
	.string "it to spawn in the BETTER office.\p"
	.string "You should be able to open the eastern\n"
	.string "security door and go up the stairs.\p"
	.string "There's probably a lot of guards there,\n"
	.string "and a lot of control panels.\p"
	.string "Keep climbing until you find the Rotom,\n"
	.string "Phone controls, and use this stick\l"
	.string "to upload a message.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission2:
	.string "You can go back in to if you need to\n"
	.string "prepare, but if not, I'll start it up.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission3:
	.string "Beat 'em up, Sophie.$"

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Mission4:
	.string "You got this!!$"




OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Eventscript_Ernest::
	setspeaker Speaker_Ernest
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Ernest1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_Eventscript_Cancel
	setflag FLAG_SPOOFING_EXECUTIVE
	warpsilent MAP_VIRTUAL_CITY_COMMS_TOWER_1F, 5,10
	waitstate
	end


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_ActIII_Text_Ernest1:
	.string "{COLOR RED}This is a point of no return until\n"
	.string "the postgame.\p"
	.string "{COLOR DARK_GRAY}Are you ready?$"






OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_PC::
	lockall
	goto_if_eq VAR_PETALBURG_CITY_STATE, 2, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_NoVRNow
	@many more situations where you need to disable this temporarily TOFOLD
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_Eventscript_Cancel
	closemessage
	@@ Fancy transition TOFOLD
	warp MAP_VIRTUAL_CITY_OUTSIDE1, 24, 24
	waitstate
	end

Common_Eventscript_Cancel::
	closemessage
	releaseall
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PC:
	.string "Enter VR?$"


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_NoVRNow::
	setspeaker Speaker_Sophie
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_NoVRNow, MSGBOX_SIGN
	closemessage
	end


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_NoVRNow:
	.string "I shouldn't go to the Place now.$"

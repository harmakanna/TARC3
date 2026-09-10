VirtualCity_Hotel_YourRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Hotel_YourRoom_OnFrame
	.byte 0

VirtualCity_Hotel_YourRoom_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 21, VirtualCity_Hotel_YourRoom_Eventscript_ActII_Resolution
	map_script_2 VAR_PETALBURG_CITY_STATE, 39, VirtualCity_Hotel_YourRoom_Eventscript_ActII_Ending
	.2byte 0


VirtualCity_Hotel_YourRoom_Eventscript_ActII_Resolution::
	lockall
	@warpsilent MAP_VIRTUAL_CITY_HOTEL_YOUR_ROOM, 12, 9
	@waitstate
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	waitmovement 0
	delay 140
	fadescreenspeed FADE_FROM_BLACK, 5
	delay 100
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk1Minh, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk2Ernest, Speaker_Ernest, DIR_EAST
	@playse SE_SELECT
	@speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk3Harriet, Speaker_Harriet, DIR_WEST
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 40
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceUp
	applymovement LOCALID_VRROOM_ERNEST, Common_Movement_FaceUp
	applymovement LOCALID_VRROOM_HARRIET, Common_Movement_FaceUp
	delay 40
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk4Sophie, SP_NAME_PLAYER, DIR_NORTH
	closemessage
	playse SE_PIN
	applymovement LOCALID_VRROOM_MINH, Common_Movement_ExclamationMark
	applymovement LOCALID_VRROOM_HARRIET, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 50
	@speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk5Minh, Speaker_Minh, DIR_NORTH
	@playse SE_SELECT
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk6Harriet, Speaker_Harriet, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk7Sophie, SP_NAME_PLAYER, DIR_SOUTH
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie1
	waitmovement 0
	delay 40
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Hotel_YourRoom_Text_ResolutionTalk8Sophie, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie2
	waitmovement 0
	delay 40
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Hotel_YourRoom_Text_ResolutionTalk9Sophie, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie3
	waitmovement 0
	delay 40
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Hotel_YourRoom_Text_ResolutionTalk10Sophie, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie4
	waitmovement 0
	delay 60
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Hotel_YourRoom_Text_ResolutionTalk11Sophie, MSGBOX_DEFAULT
	playse SE_SELECT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceLeft
	applymovement LOCALID_VRROOM_HARRIET, Common_Movement_FaceLeft
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk12Ernest, Speaker_Ernest, DIR_NORTH
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_VRROOM_MINH, Common_Movement_ExclamationMark
	applymovement LOCALID_VRROOM_ERNEST, Common_Movement_ExclamationMark
	applymovement LOCALID_VRROOM_HARRIET, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	@delay 50
	playse SE_NOTE_G
	waitse
	playse SE_NOTE_C
	waitse
	playse SE_NOTE_E
	waitse
	playse SE_NOTE_D
	waitse
	setspeaker Speaker_Announcement
	msgbox VirtualCity_Hotel_YourRoom_Text_ResolutionTalk12pt5Message, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	waitse
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	applymovement LOCALID_VRROOM_ERNEST, Common_Movement_FaceRight
	applymovement LOCALID_VRROOM_HARRIET, Common_Movement_FaceLeft
	delay 20
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk13Minh, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk14Harriet, Speaker_Harriet, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk15Sophie, SP_NAME_PLAYER, DIR_WEST
	closemessage
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceLeft
	delay 90
	applymovement LOCALID_VRROOM_ERNEST, Common_Movement_WalkLeft
	waitmovement 0
	delay 30
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Hotel_YourRoom_Text_ResolutionTalk16Ernest MSGBOX_DEFAULT
	closemessage
	delay 80
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_VRROOM_ERNEST, Common_Movement_FaceRight
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk17Harriet, Speaker_Harriet, DIR_WEST
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk18Ernest, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	playse SE_SELECT
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk19Minh, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk20Harriet, Speaker_Harriet, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk21Sophie, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk22Ernest, Speaker_Ernest, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	playse SE_SELECT
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk23Minh, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk24Harriet, Speaker_Harriet, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk25Sophie, SP_NAME_PLAYER, DIR_WEST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	playse SE_SELECT
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk26Harriet, Speaker_Harriet, DIR_WEST
	closemessage
	applymovement LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Move_MinhLeaves
	applymovement LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Move_HarrietLeaves
	applymovement LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Move_ErnestLeaves
	delay 100
	playse SE_EXIT
	delay 40
	playse SE_EXIT
	delay 40
	removeobject LOCALID_VRROOM_MINH
	removeobject LOCALID_VRROOM_HARRIET
	removeobject LOCALID_VRROOM_ERNEST
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_PETALBURG_CITY_STATE, 22
	setflag FLAG_ACT_II_STARTED
	setflag FLAG_ACT_II_HIDE_HOTEL_FRIENDS
	clearflag FLAG_HIDE_ACT_II_HARRIET
	clearflag FLAG_HIDE_LEDIAN_QUEST
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	releaseall
	end

VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie1:
	walk_left
	walk_left
	step_end

VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie2:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie3:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie4:
	walk_right
	walk_right
	step_end


VirtualCity_Hotel_YourRoom_Move_MinhLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VirtualCity_Hotel_YourRoom_Move_HarrietLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VirtualCity_Hotel_YourRoom_Move_ErnestLeaves:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end



VirtualCity_Hotel_YourRoom_Text_ResolutionTalk1Minh::
	.string "We have to do something.\p"
	.string "POKéMON are being replaced with fakes\n"
	.string "and no one else knows.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk2Ernest::
	.string "Okay, sure.\p"
	.string "You two work on VR POKéMON.\p"
	.string "You can see the signs Harriet and I,\n"
	.string "and others, can't.\p"
	.string "But what can we even DO about it?\p"

@Making it so Harriet doesn't continue the dialogue, as it's one single thought.
@VirtualCity_Hotel_YourRoom_Text_ResolutionTalk3Harriet::
	.string "{COLOR GREEN}BETTER{COLOR DARK_GRAY} will just censor us, or worse,\n"
	.string "if we try to tell people.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk4Sophie::
	.string "…\p"
	.string "I'm going to get the word out somehow.\n"
	.string "No matter what happens.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk5Minh::
	.string "Sophie! Let's think about this!$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk6Harriet::
	.string "Sophie! Let's think about this!\p"
	.string "You wouldn't want a repeat of the\n" 
	.string "Rare Candy incident…$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk7Sophie::
	.string "It's not going to be like that.\n" 
	.string "We'll do it right.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk8Sophie::
	.string "We can't fight the corpo.{PAUSE 50}\n" 
	.string "They're just too powerful.$" 

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk9Sophie::
	.string "We can't boycott them.{PAUSE 50}\n" 
	.string "They're everywhere.$" 

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk10Sophie::
	.string "We can't save any real POKéMON\n" 
	.string "that might be out there.$" 

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk11Sophie::
	.string "But maybe we can do something.{PAUSE 30}\n"
	.string "Something small.\p"
	.string "If we can just… {PAUSE 30}EXPOSE this scam…{PAUSE 30}\n"
	.string "maybe people will stop buying them.\p"
	.string "And maybe… {PAUSE 30}people will demand to know\n"
	.string "what's really going on.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk12Ernest::
	.string "But how?\p"
	.string "We would have to be anonymou-$"
	@.string "Where could we put a message that\n"
	@.string "everyone could see, that couldn't be\l"
	@.string "traced back to us?$"

@@ BING!
VirtualCity_Hotel_YourRoom_Text_ResolutionTalk12pt5Message::
	.string "{COLOR RED}TODAY ONLY! {COLOR BLUE}HALF OFF ROOM EXPANSIONS!\p"
	.string "GET THE {COLOR GREEN}HOLODECK {COLOR BLUE}OF YOUR {COLOR LIGHT_BLUE}DREAMS,{COLOR BLUE} NOW\n"
	.string "WITH REALISTIC {COLOR RED}TRUESCENT TECHNOLOGY!\p"
	.string "{COLOR BLUE}AVAILABLE FOR A LIMITED TIME!$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk13Minh::
	.string "No way. Can we?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk14Harriet::
	.string "The Rotom Phone messaging system?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk15Sophie::
	.string "Ernest, can we use it?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk16Ernest::
	.string "…\p"
	.string "You want to HACK the Rotom phone.\p"
	.string "To warn the public about fakes.\p"
	.string "It's…{PAUSE 50}it's risky. And illegal.\p"
	.string "But it might be possible.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk17Harriet::
	.string "…\p"
	.string "We'd need an executive's ID card or\n"
	.string "credentials to access the system.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk18Ernest::
	.string "And then you'd need to impersonate…{PAUSE 30}\n"
	.string "this exec…{PAUSE 30} to get into the tower.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk19Minh::
	.string "Harriet, isn't that one cheater exec\n"
	.string "still the {COLOR GREEN}BETTER{COLOR DARK_GRAY} Champion?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk20Harriet::
	.string "Uh, yeah…\p"
	.string "No one's ever been able to\n"
	.string "cheat hard enough to beat him.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk21Sophie::
	.string "That'll be our executive, then!\p"
	.string "I'll battle my way up to him and\n"
	.string "snag his ID when we duke it out!$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk22Ernest::
	.string "… … …\p"
	.string "She's in one of THOSE moods again…\p"
	.string "Sure! Why not!\p"
	.string "I'll play along.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk23Minh::
	.string "I like this plan…\p"
	.string "I can help gather more evidence and\n"
	.string "prepare the message.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk24Harriet::
	.string "Which leaves me to scout out your\n"
	.string "opponents!$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk25Sophie::
	.string "I can beat him.\p"
	.string "I can modify the team between battles,\n"
	.string "adapt to him. No one else can do that.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk26Harriet::
	.string "That's the spirit! Go get ready,\n"
	.string "then meet me at the Stadium.\p"
	.string "Let's do this, everyone!$"






VirtualCity_Hotel_YourRoom_Eventscript_ActII_Ending::
	special SpawnCameraObject
	@ TOFOLD some movement would be great
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ActII_Ending1Minh, Speaker_Minh, DIR_NORTH
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ActII_Ending2Ernest, Speaker_Ernest, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ActII_Ending3Sophie, SP_NAME_PLAYER, DIR_SOUTH
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ActII_Ending4Harriet, Speaker_Harriet, DIR_WEST
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ActII_Ending5Sophie, SP_NAME_PLAYER, DIR_SOUTH
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ActII_Ending6Ernest, Speaker_Ernest, DIR_EAST
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ActII_Ending7Minh, Speaker_Minh, DIR_NORTH
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ActII_Ending8Ernest, Speaker_Ernest, DIR_EAST
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ActII_Ending9Harriet, Speaker_Harriet, DIR_WEST
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ActII_Ending10Minh, Speaker_Minh, DIR_NORTH
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ActII_Ending11Sophie, SP_NAME_PLAYER, DIR_SOUTH
	closemessage
	special RemoveCameraObject
	removeobject LOCALID_VRROOM_MINH
	playse SE_PC_OFF
	waitse
	removeobject LOCALID_VRROOM_ERNEST
	playse SE_PC_OFF
	waitse
	removeobject LOCALID_VRROOM_HARRIET
	playse SE_PC_OFF
	waitse
	setvar VAR_PETALBURG_CITY_STATE, 40
	setflag FLAG_HIDE_LOLA_BEDROOM_PROLOGUE
	setflag FLAG_ACT_II_HIDE_HOTEL_FRIENDS
	setflag FLAG_ACT_III_STARTED
	clearflag FLAG_ACT_III_HIDE_BEDROOM_LOLA
	end


VirtualCity_Hotel_YourRoom_Text_ActII_Ending1Minh::
	.string "So, that's it? We can hack the Rotom\n"
	.string "Phone system now?$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending2Ernest::
	.string "We have the credentials. But Sophie\n"
	.string "still has to get to the control room.\p"
	.string "I have a way to scramble your ID.\p"
	.string "You'll look like Byron to the system,\n"
	.string "And your skin will be blurred.\p"
	.string "You'll have to enter the Place with\n"
	.string "a different body.$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending3Sophie::
	.string "And then I can fight the guards?$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending4Harriet::
	.string "I mean, there's probably going to be\n"
	.string "guards trying to stop you.\p"
	.string "So, um, yeah?$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending5Sophie::
	.string "Excellent!$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending6Ernest::
	.string "The autoscanner won't work when you're\n"
	.string "scrambled, so you'll have to go through\l"
	.string "the tower manually.\p"
	.string "You won't be able to turn back when we\n"
	.string "start.$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending7Minh::
	.string "I've prepared the message and the\n"
	.string "overworld footage of the Ponyta.\p"
	.string "Let's bring it home.$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending8Ernest::
	.string "Let's meet back at your place, Sophie.\p"
	.string "Finish up what you have to do first,\n"
	.string "and we'll meet there and prepare.$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending9Harriet::
	.string "Let's goooooo! Crush the system!$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending10Minh::
	.string "Or in our case, stage the smallest\n"
	.string "possible rebellion against the system.$"

VirtualCity_Hotel_YourRoom_Text_ActII_Ending11Sophie::
	.string "Hush, Minh.\p"
	.string "Okay, I'll finish up anything I need.\n"
	.string "to do before this gauntlet, and meet\l"
	.string "you all back at my place. See ya!$"



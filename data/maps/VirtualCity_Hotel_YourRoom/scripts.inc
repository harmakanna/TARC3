VirtualCity_Hotel_YourRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Hotel_YourRoom_OnFrame
	.byte 0

VirtualCity_Hotel_YourRoom_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 21, VirtualCity_Hotel_YourRoom_Eventscript_ActII_Resolution
	.2byte 0


VirtualCity_Hotel_YourRoom_Eventscript_ActII_Resolution::
	warpsilent MAP_VIRTUAL_CITY_HOTEL_YOUR_ROOM, 12, 9
	waitstate
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk1Minh, Speaker_Minh, DIR_NORTH
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk2Ernest, Speaker_Ernest, DIR_EAST
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk3Harriet, Speaker_Harriet, DIR_WEST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 40
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceUp
	applymovement LOCALID_VRROOM_ERNEST, Common_Movement_FaceUp
	applymovement LOCALID_VRROOM_HARRIET, Common_Movement_FaceUp
	delay 40
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk4Sophie, Speaker_Sophie, DIR_NORTH
	delay 10
	applymovement LOCALID_VRROOM_MINH, Common_Movement_ExclamationMark
	applymovement LOCALID_VRROOM_HARRIET, Common_Movement_ExclamationMark
	delay 20
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk5Minh, Speaker_Minh, DIR_NORTH
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk6Harriet, Speaker_Harriet, DIR_NORTH
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk7Sophie, Speaker_Sophie, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie1
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk8Sophie, Speaker_Sophie, DIR_WEST
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie2
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk9Sophie, Speaker_Sophie, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie3
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk10Sophie, Speaker_Sophie, DIR_WEST
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Move_ResolutionTalkSophie4
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk11Sophie, Speaker_Sophie, DIR_SOUTH
	delay 50
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk12Ernest, Speaker_Ernest, DIR_NORTH
	delay 50
	playse SE_NOTE_G
	waitse
	playse SE_NOTE_C
	waitse
	playse SE_NOTE_E
	waitse
	playse SE_NOTE_D
	waitse
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk12pt5Message, Speaker_Sophie, DIR_SOUTH
	delay 50
	applymovement LOCALID_VRROOM_ERNEST, Common_Movement_FaceRight
	applymovement LOCALID_VRROOM_HARRIET, Common_Movement_FaceLeft
	delay 20
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk13Minh, Speaker_Minh, DIR_NORTH
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk14Harriet, Speaker_Harriet, DIR_WEST
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk15Sophie, Speaker_Sophie, DIR_WEST
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceLeft
	delay 50
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk16Ernest, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk17Harriet, Speaker_Harriet, DIR_WEST
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk18Ernest, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_VRROOM_MINH, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk19Minh, Speaker_Minh, DIR_NORTH
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk20Harriet, Speaker_Harriet, DIR_WEST
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk21Sophie, Speaker_Sophie, DIR_WEST
	speak LOCALID_VRROOM_ERNEST, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk22Ernest, Speaker_Ernest, DIR_EAST
	speak LOCALID_VRROOM_MINH, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk19Minh, Speaker_Minh, DIR_NORTH
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk20Harriet, Speaker_Harriet, DIR_WEST
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk21Sophie, Speaker_Sophie, DIR_WEST
	speak LOCALID_VRROOM_HARRIET, VirtualCity_Hotel_YourRoom_Text_ResolutionTalk20Harriet, Speaker_Harriet, DIR_WEST



	setvar VAR_PETALBURG_CITY_STATE, 22
	setflag FLAG_ACT_II_STARTED
	clearflag FLAG_HIDE_ACT_II_HARRIET


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


VirtualCity_Hotel_YourRoom_Text_ResolutionTalk1Minh::
	.string "We have to do something.\p"
	.string "Pokemon are being replaced with fakes\n"
	.string "and no one else knows.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk2Ernest::
	.string "You two work on VR Pokemon - you can\n"
	.string "see the signs that we can't.\p"
	.string "But what can we even do?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk3Harriet::
	.string "BETTER will just censor us, or worse,\n"
	.string "if we try to tell people.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk4Sophie::
	.string "…\p"
	.string "I'm going to get the word out somehow.\n"
	.string "No matter what happens.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk5Minh::
	.string "Sophie! Let's think about this!$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk6Harriet::
	.string "Sophie, even you wouldn't want a\n" 
	.string "repeat of the Rare Candy incident…$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk7Sophie::
	.string "It's not going to be like that.\n" 
	.string "We'll do it right.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk8Sophie::
	.string "We can't fight the corpo -\n" 
	.string "they're just too powerful.$" 

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk9Sophie::
	.string "We can't boycott them -\n" 
	.string "they're everywhere.$" 

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk10Sophie::
	.string "We can't save any real Pokemon\n" 
	.string "that might be out there.$" 

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk11Sophie::
	.string "But maybe we can do something.\n"
	.string "Something small.\p"
	.string "If we can just… expose this scam,\n"
	.string "maybe people will stop buying them.\p"
	.string "And maybe… people will demand to know\n"
	.string "what's really going on.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk12Ernest::
	.string "But… how?\n"
	.string "It would have to be anonymous…\p"
	.string "Where could we put a message that\n"
	.string "everyone could see, that couldn't be\l"
	.string "traced back to us?$"

@@ BING!
VirtualCity_Hotel_YourRoom_Text_ResolutionTalk12pt5Message::
	.string "TODAY ONLY! HALF OFF ROOM EXPANSIONS!\p"
	.string "GET THE HOLODECK OF YOUR DREAMS, NOW\n"
	.string "WITH REALISTIC TRUESCENT TECHNOLOGY!\p"
	.string "AVAILABLE FOR A LIMITED TIME!$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk13Minh::
	.string "No way.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk14Harriet::
	.string "The Rotom Phone messaging system?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk15Sophie::
	.string "Ernest, can it be done?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk16Ernest::
	.string "…\p"
	.string "You want… to hack the Rotom phone?\n"
	.string "To warn the public… about fakes?\p"
	.string "It's… it's risky. And illegal.\n"
	.string "But it might be… possible.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk17Harriet::
	.string "We'd need one of the execs' cards or\n"
	.string "credentials to access the system.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk18Ernest::
	.string "And then you'd need to impersonate…\n"
	.string "the exec to get into the tower.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk19Minh::
	.string "Harriet, isn't that cheater exec still\n"
	.string "the BETTER champion?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk20Harriet::
	.string "Uh, yeah… no one's ever been able to\n"
	.string "cheat hard enough to beat him.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk21Sophie::
	.string "That'll be our exec, then!\n"
	.string "I'll get his ID when I battle him.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk22Ernest::
	.string "She's in one of those moods again…\p"
	.string "Oh well, I've always wanted to hack into\n"
	.string "something wildly dangerous.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk23Minh::
	.string "I like this plan…\p"
	.string "Maybe I can help you find more\n"
	.string "Pokemon to battle with?$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk24Harriet::
	.string "Which leaves me to scout out your\n"
	.string "opponents. I can handle that.\p"
	.string "And you'll do the battling. None of us\n"
	.string "know the meta like you do, Sophie.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk25Sophie::
	.string "I can beat him.\p"
	.string "I can modify the team between battles,\n"
	.string "adapt to him. No one else can do that.$"

VirtualCity_Hotel_YourRoom_Text_ResolutionTalk26Harriet::
	.string "That's the spirit. Go get ready,\n"
	.string "and meet me at the Stadium.\p"
	.string "Let's do this, everyone!$"











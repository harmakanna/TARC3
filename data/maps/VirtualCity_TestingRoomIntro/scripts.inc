VirtualCity_TestingRoomIntro_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VirtualCity_TestingRoomIntro_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_TestingRoomIntro_OnFrame
	.byte 0

VirtualCity_TestingRoomIntro_OnTransition:
	goto_if_set FLAG_SYS_B_DASH, VirtualCity_TestingRoomIntro_Eventscript_NotFirstLoad
	@fadescreenspeed FADE_TO_BLACK, 0
	setvar VAR_PETALBURG_CITY_STATE, 1
	end

VirtualCity_TestingRoomIntro_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 1, VirtualCity_TestingRoomIntro_Eventscript_IntroScene
	.2byte 0



Speaker_Minh::
	.string "Minh$"

Speaker_Sophie::
	.string "Sophie$"

Speaker_Harriet::
	.string "Harriet$"

Speaker_Ernest::
	.string "Ernest$"

Speaker_Lola::
	.string "Lola$"

Speaker_Announcement::
	.string "Announcement$"

Speaker_Autoscanner::
	.string "Autoscanner$"

Speaker_Byron::
	.string "Byron$"





OT_SoPhi99::
	.string "SoPhi99$"

OT_Lola::
	.string "Lola$"

OT_Ledian::
	.string "Buggin8$"

OT_Design::
	.string "DESIGN$"

OT_Research::
	.string "Researc$"

OT_Contentment::
	.string "ConTENT$"

OT_EarlGrey::
	.string "EarlGry$"

Nickname_Ex::
	.string "Ex$"

Nickname_Dreams::
	.string "Dreams$"





@Set your flags in new_game.inc rather than everything right at the start here. I added all of them
@to that file for less clutter.
VirtualCity_TestingRoomIntro_Eventscript_IntroScene:
	setflag B_FLAG_NO_WHITEOUT
	setflag FLAG_SYS_B_DASH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	@setflag FLAG_BADGE08_GET

	@ DO SETFLAGS IN NEW_GAME.INC!!! WAY EASIER TO TRACK!!!

	@@more setflags TOFOLD, set healing place, etc. etc.

	@----------------------------------------------------
	@setvar VAR_PETALBURG_CITY_STATE, 22
	@clearflag FLAG_SYS_PREVENT_MAP_FADE
	@givemon SPECIES_DARKANINE, 50
	@givemon SPECIES_PONYTA, 50
	@givemon SPECIES_TOXAPEX, 50
	@givemon SPECIES_LEDIAN, 50
	@givemon SPECIES_DRATINI, 50
	
	@warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 7
	@waitstate


	@----------------------------------------------------
	@setvar VAR_PETALBURG_CITY_STATE, 10
	@setflag FLAG_DARKANINE_COMPLETE
	@clearflag FLAG_SYS_PREVENT_MAP_FADE
	@@ Skipping traveling sequence for now TOFOLD
	@warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_YOUR_APARTMENT, 1, 3
	@waitstate

	@warpsilent MAP_VIRTUAL_CITY_COMMS_TOWER_1F, 5, 11
	@waitstate
	@----------------------------------------------------


	special SpawnCameraObject
	applymovement LOCALID_CAMERA, VirtualCity_TestingRoomIntro_CameraPositioning
	waitmovement 0
	special RemoveCameraObject
	removeobject LOCALID_DARKANINES_BALL
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	removeobject LOCALID_ARCANINE
	fadescreenspeed FADE_FROM_BLACK, 2

	@@ TOFOLD Transition Graphic

	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro01, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_TestingRoomIntro_Text_Intro02, SP_NAME_PLAYER, DIR_EAST
	closemessage
	playse SE_PIN
	applymovement LOCALID_MINH, Common_Movement_ExclamationMark
	waitse
	delay 60
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro03, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_TestingRoomIntro_Text_Intro04, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro05, Speaker_Minh, DIR_WEST
	closemessage
	addobject LOCALID_DARKANINES_BALL
	delay 10
	removeobject LOCALID_DARKANINES_BALL
	playse SE_BALL_OPEN
	addobject LOCALID_ARCANINE
	delay 40

	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro06, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_TestingRoomIntro_Text_Intro07, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro08, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_TestingRoomIntro_Text_Intro09, SP_NAME_PLAYER, DIR_EAST
	playse SE_SELECT
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro10, Speaker_Minh, DIR_WEST
	closemessage
	playse SE_PIN
	applymovement LOCALID_MINH, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitse
	playse SE_NOTE_G
	waitse
	playse SE_NOTE_C
	waitse
	playse SE_NOTE_E
	waitse
	playse SE_NOTE_D
	waitse

	speak LOCALID_GUARD, VirtualCity_TestingRoomIntro_Text_Intro11, Speaker_Announcement, DIR_EAST 
	closemessage
	playse SE_PC_OFF
	waitse
	delay 80
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro12, Speaker_Minh, DIR_WEST
	closemessage

	removeobject LOCALID_ARCANINE
	addobject LOCALID_DARKANINES_BALL
	playse SE_BALL_OPEN
	delay 10
	removeobject LOCALID_DARKANINES_BALL
	setvar VAR_PETALBURG_CITY_STATE, 0
	@fadescreenspeed FADE_TO_BLACK, 2
	@special SpawnCameraObject
	@applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	@waitmovement LOCALID_CAMERA
	@special RemoveCameraObject
	


	
	@@ TOFOLD - duplicate Darkanine + mods

	goto VirtualCity_TestingRoomIntro_Eventscript_Minh
	end

VirtualCity_TestingRoomIntro_Eventscript_NotFirstLoad:
	setvar VAR_PETALBURG_CITY_STATE, 0
	end

VirtualCity_TestingRoomIntro_Eventscript_Minh::


	clearparty
	givemon SPECIES_DARKANINE, 50, otName=OT_Design
	call EventScript_AddRandomMod
	call EventScript_AddRandomMod

	@clonefirstmon
	givemon SPECIES_ARCANINE, 50, otName=OT_Design
	givemon SPECIES_EXCADRILL, 50, nature=NATURE_JOLLY, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_EARTHQUAKE, move2=MOVE_ROCK_SLIDE, move3=MOVE_SWORDS_DANCE, move4=MOVE_PROTECT, nickname=Nickname_Ex, otName=OT_SoPhi99

	goto_if_unset FLAG_DARKANINE_BATTLE_1, VirtualCity_TestingRoomIntro_Eventscript_FirstBattle
	goto_if_unset FLAG_DARKANINE_BATTLE_2, VirtualCity_TestingRoomIntro_Eventscript_SecondBattle
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_SubsequentBattleStart, Speaker_Minh, DIR_WEST
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, VirtualCity_TestingRoomIntro_Text_SubsequentBattleEndWin, VirtualCity_TestingRoomIntro_Text_SubsequentBattleEndLose
	special HealPlayerParty
	setspeaker Speaker_Minh

VirtualCity_TestingRoomIntro_EventScript_AdjustDarkanine::
	msgbox VirtualCity_TestingRoomIntro_Text_AdjustDarkanine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_TestingRoomIntro_EventScript_ConfirmDarkanine
    goto_if_eq VAR_RESULT, YES, VirtualCity_TestingRoomIntro_Eventscript_Minh
	end

VirtualCity_TestingRoomIntro_Eventscript_StatsIncorrect:
	setspeaker Speaker_Minh
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_WrongAdjustment, Speaker_Minh, DIR_WEST
	end

VirtualCity_TestingRoomIntro_Eventscript_FirstBattle:
	setflag FLAG_DARKANINE_BATTLE_1
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_FirstBattleStart, Speaker_Minh, DIR_WEST
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, VirtualCity_TestingRoomIntro_Text_FirstBattleEndWin, VirtualCity_TestingRoomIntro_Text_FirstBattleEndLose
	setspeaker Speaker_Minh
	msgbox VirtualCity_TestingRoomIntro_Text_AdjustDarkanine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_TestingRoomIntro_EventScript_ConfirmDarkanine
    goto_if_eq VAR_RESULT, YES, VirtualCity_TestingRoomIntro_Eventscript_Minh
	end

VirtualCity_TestingRoomIntro_Eventscript_SecondBattle:
	setflag FLAG_DARKANINE_BATTLE_2
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_SecondBattleStart, Speaker_Minh, DIR_WEST
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, VirtualCity_TestingRoomIntro_Text_SecondBattleEndWin, VirtualCity_TestingRoomIntro_Text_SecondBattleEndLose
	setspeaker Speaker_Minh
	msgbox VirtualCity_TestingRoomIntro_Text_AdjustDarkanine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_TestingRoomIntro_EventScript_ConfirmDarkanine
    goto_if_eq VAR_RESULT, YES, VirtualCity_TestingRoomIntro_Eventscript_Minh
	end

EventScript_End:
	end

VirtualCity_TestingRoomIntro_EventScript_ConfirmDarkanine:
	msgbox VirtualCity_TestingRoomIntro_Text_ConfirmDarkanine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_TestingRoomIntro_EventScript_AdjustDarkanine
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_DarkanineConfirmed, Speaker_Minh, DIR_WEST
	closemessage
	delay 50
	playse SE_PC_LOGIN
	waitse
	delay 20
	playse SE_PC_OFF
	applymovement LOCALID_MINH, VirtualCityIntro_Movement_LogOut
	waitmovement 0
	removeobject LOCALID_MINH
	delay 100
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	@@ fancy transition
	@fadescreenspeed FADE_TO_BLACK, 5
	setvar VAR_PETALBURG_CITY_STATE, 2
	setflag FLAG_DARKANINE_COMPLETE


	clearparty
	givemon SPECIES_EXCADRILL, 50, nature=NATURE_JOLLY, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_EARTHQUAKE, move2=MOVE_ROCK_SLIDE, move3=MOVE_SWORDS_DANCE, move4=MOVE_PROTECT, nickname=Nickname_Ex, otName=OT_SoPhi99
	exitvr_warp MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_YOUR_APARTMENT_BEDROOM, 5, 2 @@@ exitvr JAMIEHELP
	waitstate
	end



VirtualCityIntro_Movement_LogOut::
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	@face_down
	@face_right
	@face_up
	@face_left
	@face_down
	@face_right
	@face_up
	@face_left
	step_end


VirtualCity_TestingRoomIntro_CameraPositioning::
	walk_faster_right
	walk_faster_right
	walk_faster_down
	step_end

VirtualCity_TestingRoomIntro_Text_Intro01:
	.string "Are.\p"
	.string "You.\p"
	.string "Ready?\p"
	.string "Beauty. Elegance. Genius.$"

VirtualCity_TestingRoomIntro_Text_Intro02:
	.string "Hmm?\p"
	.string "You mean, am I ready to see a real live\n"
	.string "Pokemon tonight?$"

VirtualCity_TestingRoomIntro_Text_Intro03:
	.string "What? No!\p Sophieeeee!\p"
	.string "Ugh, you're so mean!\p"
	.string "I mean, I'm excited for that too… but\n"
	.string "you know what I'm talking about!\p"
	.string "The brand-new Arcanine I just made!$"

VirtualCity_TestingRoomIntro_Text_Intro04:
	.string "Heh, just teasin' ya.\p"
	.string "I'm excited to see it, really, because\n"
	.string "you're just SOOOO talented.$"

VirtualCity_TestingRoomIntro_Text_Intro05:
	.string "I know, aren't I!?\p"
	@.string "See, this\n"
	@.string "is why I can never stay mad at you.\p"
	.string "Well then, without further ado…$"

VirtualCity_TestingRoomIntro_Text_Intro06:
	.string "Meet our new limited edition Arcanine -\n"
	.string "I affectionately call him Darkanine.\p"
	.string "The perfect shadow to Arcanine's light.\n"
	.string "I designed his fur to evoke half-moons\l"
	.string "and eldritch tentacles. An elegant-$"

VirtualCity_TestingRoomIntro_Text_Intro07:
	.string "So… Dark type?$"

VirtualCity_TestingRoomIntro_Text_Intro08:
	.string "Ugh, no appreciation for art.\p"
	.string "Yes, Dark type, you barbarian, or\n"
	.string "Dark / Fire if you prefer.\p"
	.string "And boss wants two boosts on it.\p"
	.string "You know that hack-y, bonus thing\n"
	.string "you usually only do once?\p"
	.string "This is a limited edition, so…\n"
	.string "Uhh…\p"
	.string "Just do it twice.$"

VirtualCity_TestingRoomIntro_Text_Intro09:
	.string "Ugh…$"

VirtualCity_TestingRoomIntro_Text_Intro10:
	.string "I know. But look on the bright side!\p"
	.string "Even though you're a barbarian, you're\n"
	.string "the best balancer working here.\p"
	.string "That's why they paired you up with\n"
	.string "the best artist, obvi-$"

VirtualCity_TestingRoomIntro_Text_Intro11:
	.string "{COLOR BLUE}DO {COLOR RED}YOU {COLOR BLUE}NEED A CHANGE OF SCENERY?\p"
	.string "COME VISIT THE {COLOR GREEN}BETTER {COLOR BLUE}REFUGE AND\n"
	.string "EXPERIENCE OUR STATE-OF-THE-ART\l"
	.string "{COLOR RED}AUTUMN WONDERLAND!\p"
	.string "{COLOR BLUE}THE COMPLIMENTARY {COLOR GREEN}F.R.E.S.H. {COLOR BLUE}BREATHING\n"
	.string "EXPERIENCE LEAVES YOU BREATHLESS!$"


VirtualCity_TestingRoomIntro_Text_Intro12:
	.string "Ugh, ANOTHER Rotom Phone ad ping?\p"
	@.string "I'm complimenting myself, a Rotom\l"
	@.string "Phone ad interrupts it?\p" 
	.string "Hmph.\p"
	.string "Anyways, work your magic on Darkanine,\n"
	.string "and then we can run a simulator battle.\p"
	.string "I got the meta's top three Pokemon you\n"
	.string "wanted here, for the test battle.$"


VirtualCity_TestingRoomIntro_Text_AdjustDarkanine:
	.string "Adjust Darkanine?$"

VirtualCity_TestingRoomIntro_Text_WrongAdjustment:
	.string "Huh? You're not done adjusting it,\n"
	.string "are you?\p"
	.string "Remember, it needs to be either pure\n"
	.string "Dark or Dark / Fire, and all of its\l"
	.string "stats should be the same or higher.$"



VirtualCity_TestingRoomIntro_Text_FirstBattleStart:
	.string "Oh, my baby looks good!\p"
	.string "I may not be a battler, but\n"
	.string "I'll try my best!$"

VirtualCity_TestingRoomIntro_Text_FirstBattleIntro:
	.string "Minh is ready to test Darkanine!$"

VirtualCity_TestingRoomIntro_Text_FirstBattleEndWin:
	@.string "Welp, didn't win this time.\p"
	.string "Did it feel good to use? Wanna\n"
	.string "modify it some more?$"

VirtualCity_TestingRoomIntro_Text_FirstBattleEndLose:
	.string "Either you went easy on me, or these\n"
	.string "meta Pokemon are too strong!\p"
	.string "Did it feel good to use? Wanna\n"
	.string "modify it some more?$"


VirtualCity_TestingRoomIntro_Text_SecondBattleStart:
	.string "Done balancing? Let's go.$"

VirtualCity_TestingRoomIntro_Text_SecondBattleEndWin:
	.string "Was that better? I can't tell.\p"
	.string "Are you satisfied, or do you need to\n"
	.string "fiddle with it some more?$"

VirtualCity_TestingRoomIntro_Text_SecondBattleEndLose:
	.string "Whoa, I won! You must need to retune it.\p"
	.string "Unless this was your plan? Do you need\n"
	.string "to fiddle with it some more?$"


VirtualCity_TestingRoomIntro_Text_SubsequentBattleStart:
	.string "How's it feeling? Let's see.$"

VirtualCity_TestingRoomIntro_Text_SubsequentBattleEndWin:
	.string "I know you can't rush art, but when\n"
	.string "you finish this, we get to go home!\p"
	.string "And see a real live Pokemon!\p"
	.string "Do you really need to tune it\n"
	.string "even more?$"

VirtualCity_TestingRoomIntro_Text_SubsequentBattleEndLose:
	.string "Can't complain about a win!\p"
	.string "Do you really need to tune it\n"
	.string "even more?$"

VirtualCity_TestingRoomIntro_Text_ConfirmDarkanine:
	.string "Cool, you're locking it in?\n"
	.string "It's ready for the release?$"


VirtualCity_TestingRoomIntro_Text_DarkanineConfirmed:
	.string "Excellent! I dunno what you did,\n"
	.string "but I know my beautiful shadow puppy\l"
	.string "is in good hands.\p"
	.string "Now, let's log out of here and get\n"
	.string "to your apartment.\p"
	@.string "The Rotom Phone's logout works in here.\p"
	.string "Tell them to wait for me, I'll run there\n"
	.string "as fast as I can!\p"
	.string "Don't you dare pet the new Pokemon\n"
	.string "without me!$"


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

Speaker_Byron::
	.string "Byron$"



VirtualCity_TestingRoomIntro_Eventscript_IntroScene:
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_NATIONAL_DEX
	setflag FLAG_HIDE_ACT_II_INTRO_CHARS
	setflag FLAG_HIDE_ACT_II_HARRIET
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp

	@setflag FLAG_BADGE08_GET
	@@more setflags TOFOLD, set healing place, etc. etc.

	@----------------------------------------------------
	@setvar VAR_PETALBURG_CITY_STATE, 2
	@setflag FLAG_DARKANINE_COMPLETE
	@@ Skipping traveling sequence for now TOFOLD
	@warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_YOUR_APARTMENT, 1, 3
	@waitstate
	@----------------------------------------------------


	removeobject LOCALID_DARKANINES_BALL
	removeobject LOCALID_ARCANINE
	fadescreenspeed FADE_FROM_BLACK, 2

	@@ TOFOLD Transition Graphic

	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro01, Speaker_Minh, DIR_SOUTH
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_TestingRoomIntro_Text_Intro02, Speaker_Sophie, DIR_NORTH
	applymovement LOCALID_MINH, Common_Movement_ExclamationMark
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro03, Speaker_Minh, DIR_SOUTH
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_TestingRoomIntro_Text_Intro04, Speaker_Sophie, DIR_NORTH
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro05, Speaker_Minh, DIR_SOUTH

	addobject LOCALID_DARKANINES_BALL
	delay 10
	playse SE_BALL_OPEN
	removeobject LOCALID_DARKANINES_BALL
	addobject LOCALID_ARCANINE
	delay 40

	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro06, Speaker_Minh, DIR_SOUTH
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_TestingRoomIntro_Text_Intro07, Speaker_Sophie, DIR_NORTH
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro08, Speaker_Minh, DIR_SOUTH
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_TestingRoomIntro_Text_Intro09, Speaker_Sophie, DIR_NORTH
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro10, Speaker_Minh, DIR_SOUTH

	playse SE_NOTE_G
	waitse
	playse SE_NOTE_C
	waitse
	playse SE_NOTE_E
	waitse
	playse SE_NOTE_D
	waitse

	speak LOCALID_GUARD, VirtualCity_TestingRoomIntro_Text_Intro11, Speaker_Announcement, DIR_NORTH 
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_Intro12, Speaker_Minh, DIR_SOUTH

	removeobject LOCALID_ARCANINE
	addobject LOCALID_DARKANINES_BALL
	playse SE_BALL_OPEN
	delay 10
	removeobject LOCALID_DARKANINES_BALL
	setvar VAR_PETALBURG_CITY_STATE, 0
	


	@@ TOFOLD - Add Pokemon upgrade scene
	@@ TOFOLD - duplicate Darkanine + mods

	goto VirtualCity_TestingRoomIntro_Eventscript_Minh
	end

VirtualCity_TestingRoomIntro_Eventscript_NotFirstLoad:
	setvar VAR_PETALBURG_CITY_STATE, 0
	end

VirtualCity_TestingRoomIntro_Eventscript_Minh::
	@@ TOFOLD edit mon dialog event
	
	@@ We can skip this part, there shouldn't be a way to turn down a buff
	@@ check if stats and typing correct, if not goto VirtualCity_TestingRoomIntro_Eventscript_StatsIncorrect

	@ TOFOLD delete party
	givemon SPECIES_DARKANINE, 50
	@@ TOFOLD - Add Pokemon upgrade scene
	@@ TOFOLD - duplicate Darkanine + mods


	givemon SPECIES_ARCANINE, 50
	givemon SPECIES_ARCANINE, 50

	goto_if_unset FLAG_DARKANINE_BATTLE_1, VirtualCity_TestingRoomIntro_Eventscript_FirstBattle
	goto_if_unset FLAG_DARKANINE_BATTLE_2, VirtualCity_TestingRoomIntro_Eventscript_SecondBattle
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_SubsequentBattleStart, Speaker_Minh, DIR_SOUTH
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, NULL, VirtualCity_TestingRoomIntro_Text_SubsequentBattleEndWin, VirtualCity_TestingRoomIntro_Text_SubsequentBattleEndLose
	msgbox VirtualCity_TestingRoomIntro_Text_AdjustDarkanine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_TestingRoomIntro_EventScript_ConfirmDarkanine
    goto_if_eq VAR_RESULT, YES, VirtualCity_TestingRoomIntro_Eventscript_Minh
	end

VirtualCity_TestingRoomIntro_Eventscript_StatsIncorrect:
	setspeaker Speaker_Minh
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_WrongAdjustment, Speaker_Minh, DIR_SOUTH
	end

VirtualCity_TestingRoomIntro_Eventscript_FirstBattle:
	setflag FLAG_DARKANINE_BATTLE_1
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_FirstBattleStart, Speaker_Minh, DIR_SOUTH
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, NULL, VirtualCity_TestingRoomIntro_Text_FirstBattleEndWin, VirtualCity_TestingRoomIntro_Text_FirstBattleEndLose
	msgbox VirtualCity_TestingRoomIntro_Text_AdjustDarkanine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_TestingRoomIntro_EventScript_ConfirmDarkanine
    goto_if_eq VAR_RESULT, YES, VirtualCity_TestingRoomIntro_Eventscript_Minh
	end

VirtualCity_TestingRoomIntro_Eventscript_SecondBattle:
	setflag FLAG_DARKANINE_BATTLE_2
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_SecondBattleStart, Speaker_Minh, DIR_SOUTH
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, NULL, VirtualCity_TestingRoomIntro_Text_SecondBattleEndWin, VirtualCity_TestingRoomIntro_Text_SecondBattleEndLose
	msgbox VirtualCity_TestingRoomIntro_Text_AdjustDarkanine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_TestingRoomIntro_EventScript_ConfirmDarkanine
    goto_if_eq VAR_RESULT, YES, VirtualCity_TestingRoomIntro_Eventscript_Minh
	end

EventScript_End:
	end

VirtualCity_TestingRoomIntro_EventScript_ConfirmDarkanine:
	msgbox VirtualCity_TestingRoomIntro_Text_ConfirmDarkanine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_TestingRoomIntro_Eventscript_Minh
	speak LOCALID_MINH, VirtualCity_TestingRoomIntro_Text_DarkanineConfirmed, Speaker_Minh, DIR_SOUTH
	@@ fancy transition
	fadescreenspeed FADE_TO_BLACK, 5
	setvar VAR_PETALBURG_CITY_STATE, 2
	setflag FLAG_DARKANINE_COMPLETE
	@@ Skipping traveling sequence for now TOFOLD
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_YOUR_APARTMENT, 1, 3
	waitstate
	end






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
	.string "What? No! Sophieeeee!\n"
	.string "Ugh, you're so mean!\p"
	.string "I mean, I'm excited for that too… but\n"
	.string "you know what I'm talking about!\p"
	.string "The brand-new Arcanine I just made!$"

VirtualCity_TestingRoomIntro_Text_Intro04:
	.string "Heh, just teasin' ya.\p"
	.string "I'm excited to see it, really, because\n"
	.string "you're just so talented.$"

VirtualCity_TestingRoomIntro_Text_Intro05:
	.string "I am quite talented, aren't I? See, this\n"
	.string "is why I can never stay mad at you.\p"
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
	.string "And as usual, boss wants it powered\n"
	.string "up a lot so people buy it.$"

VirtualCity_TestingRoomIntro_Text_Intro09:
	.string "Ugh…$"

VirtualCity_TestingRoomIntro_Text_Intro10:
	.string "I know. But look on the bright side -\n"
	.string "even though you're a barbarian, you're\l"
	.string "the best balancer working here.\p"
	.string "That's why they paired you up with\n"
	.string "the best artist, obvi-$"

VirtualCity_TestingRoomIntro_Text_Intro11:
	.string "DO YOU NEED A CHANGE OF SCENERY?\p"
	.string "COME VISIT THE GREENEST GARDEN AND\n"
	.string "EXPERIENCE OUR STATE-OF-THE-ART\l"
	.string "AUTUMN WONDERLAND!\p"
	.string "THE COMPLIMENTARY F.R.E.S.H. BREATHING\n"
	.string "EXPERIENCE LEAVES YOU BREATHLESS!$"


VirtualCity_TestingRoomIntro_Text_Intro12:
	.string "What are the odds that the one time\n"
	.string "I'm complimenting myself, a Rotom\l"
	.string "Phone ad interrupts it? Hmph.\p"
	.string "Anyways, work your magic on Darkanine,\n"
	.string "and then come battle me.\p"
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
	.string "You know I'm not a battler, but\n"
	.string "I'll try my best!$"

VirtualCity_TestingRoomIntro_Text_FirstBattleIntro:
	.string "Minh is ready to test Darkanine!$"

VirtualCity_TestingRoomIntro_Text_FirstBattleEndWin:
	.string "Welp, didn't win this time.\p"
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
	.string "Cool, you're locking it in?\p"
	.string "Stats, typing, ability - all ready\n"
	.string "for the release?$"

VirtualCity_TestingRoomIntro_Text_DarkanineConfirmed:
	.string "Excellent! I dunno what you did,\n"
	.string "but I know my beautiful shadow puppy\l"
	.string "is in good hands.\p"
	.string "Now let's log out and get to your place.\p"
	.string "This real Pokemon thing might even be\n"
	.string "cooler than my Darkanine.$"


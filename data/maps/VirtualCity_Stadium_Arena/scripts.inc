VirtualCity_Stadium_Arena_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Stadium_Arena_OnFrame
	.byte 0


VirtualCity_Stadium_Arena_OnFrame:
	map_script_2 VAR_ALWAYS_ZERO, 0, VirtualCity_Stadium_Arena_EventScript_SetUpFight
	end

VirtualCity_Stadium_Arena_EventScript_SetUpFight::
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, VirtualCity_Stadium_Arena_Movement_PositionCameraToCenter
	waitmovement 0
	special SavePlayerParty
	callnative ChooseVGCParty
	waitstate
	special ReducePlayerPartyToSelectedMons
	@fadescreen FADE_FROM_BLACK
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	goto_if_eq VAR_PETALBURG_CITY_STATE, 23, VirtualCity_Stadium_Arena_Eventscript_Rando1Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 24, VirtualCity_Stadium_Arena_Eventscript_Rando2Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 25, VirtualCity_Stadium_Arena_Eventscript_Rando3Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 26, VirtualCity_Stadium_Arena_Eventscript_Rando4Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 27, VirtualCity_Stadium_Arena_Eventscript_Rando5Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 28, VirtualCity_Stadium_Arena_Eventscript_BrodudeFight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 29, VirtualCity_Stadium_Arena_Eventscript_WvddieFight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 30, VirtualCity_Stadium_Arena_Eventscript_SilvaBulletFight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 31, VirtualCity_Stadium_Arena_Eventscript_EarlGreyFight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 32, VirtualCity_Stadium_Arena_Eventscript_ByronB1Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_Arena_Eventscript_ByronB2Fight
	goto_if_eq VAR_PETALBURG_CITY_STATE, 34, VirtualCity_Stadium_Arena_Eventscript_ByronB3Fight
	end

VirtualCity_Stadium_Arena_Movement_PositionCameraToCenter:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

VirtualCity_Stadium_Arena_Movement_SophieWalksToPosition:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

@ Extra Speakers

Speaker_Challenger::
	.string "Challenger$"

Speaker_BroDude69::
	.string "BroDude69$"

Speaker_Wvddie::
	.string "WVDDIE$"

Speaker_SilvaBullet::
	.string "SilvaBullet$"

Speaker_EarlGrey::
	.string "Earl Grey$"

Common_Text_NotEnoughPokemon::
	.string "Bug! Error code: 0x000071$"

VirtualCity_Stadium_Arena_Eventscript_Rando1Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO1
	applymovement LOCALID_RANDO1, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_RANDO1, VirtualCity_Stadium_Arena_Text_Rando1Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	@trainerbattle_double TRAINER_RANDO1, NULL, VirtualCity_Stadium_Arena_Text_Rando1Win, Common_Text_NotEnoughPokemon
	trainerbattle_no_intro TRAINER_RANDO1, VirtualCity_Stadium_Arena_Text_Rando1Win
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty
	
	applymovement LOCALID_RANDO1, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0

	setflag FLAG_ACT_II_FOUGHT_RANDO1
	setvar VAR_PETALBURG_CITY_STATE, 24

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_Rando2Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO2
	applymovement LOCALID_RANDO2, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_RANDO2, VirtualCity_Stadium_Arena_Text_Rando2Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	trainerbattle_no_intro TRAINER_RANDO2, VirtualCity_Stadium_Arena_Text_Rando2Win
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_RANDO2, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	setflag FLAG_ACT_II_FOUGHT_RANDO2
	setvar VAR_PETALBURG_CITY_STATE, 25

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_Rando3Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO3
	applymovement LOCALID_RANDO3, VirtualCity_Stadium_Arena_Move_CommonApproachArenaSlow
	waitmovement 0
	speak LOCALID_RANDO3, VirtualCity_Stadium_Arena_Text_Rando3Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	trainerbattle_no_intro TRAINER_RANDO3, VirtualCity_Stadium_Arena_Text_Rando3Win
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_RANDO3, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0	
	setflag FLAG_ACT_II_FOUGHT_RANDO3
	setvar VAR_PETALBURG_CITY_STATE, 26

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_Rando4Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO4
	applymovement LOCALID_RANDO4, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_RANDO4, VirtualCity_Stadium_Arena_Text_Rando4Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	trainerbattle_no_intro TRAINER_RANDO4, VirtualCity_Stadium_Arena_Text_Rando4Win
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_RANDO4, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_RANDO4
	setvar VAR_PETALBURG_CITY_STATE, 27

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_Rando5Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_RANDO5
	applymovement LOCALID_RANDO5, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_RANDO5, VirtualCity_Stadium_Arena_Text_Rando5Intro, Speaker_Challenger, DIR_WEST

	setspeaker Speaker_Challenger
	trainerbattle_no_intro TRAINER_RANDO5, VirtualCity_Stadium_Arena_Text_Rando5Win
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostSilver
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_RANDO5, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_RANDO5
	setflag FLAG_ACT_II_HIDE_ERNEST_PREBATTLE
	setvar VAR_PETALBURG_CITY_STATE, 28

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end




VirtualCity_Stadium_Arena_Eventscript_LostSilver::
	@TOFOLD
	special HealPlayerParty
	special LoadPlayerParty
	end





VirtualCity_Stadium_Arena_Eventscript_BrodudeFight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_BRODUDE
	applymovement LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Text_BroDudeIntro, Speaker_BroDude69, DIR_WEST

	setspeaker Speaker_BroDude69
	trainerbattle_no_intro TRAINER_BRODUDE, VirtualCity_Stadium_Arena_Text_BroDudeWin
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostGold
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_BRODUDE
	setvar VAR_PETALBURG_CITY_STATE, 29

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_WvddieFight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_WVDDIE
	applymovement LOCALID_WVDDIE, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_WVDDIE, VirtualCity_Stadium_Arena_Text_WvddieIntro, Speaker_Wvddie, DIR_WEST

	setspeaker Speaker_Wvddie
	trainerbattle_no_intro TRAINER_WVDDIE, VirtualCity_Stadium_Arena_Text_WvddieWin
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostGold
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_WVDDIE, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_WVDDIE
	setvar VAR_PETALBURG_CITY_STATE, 30

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_SilvaBulletFight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_SILVABULLET
	applymovement LOCALID_SILVABULLET, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_SILVABULLET, VirtualCity_Stadium_Arena_Text_SilvaBulletIntro, Speaker_SilvaBullet, DIR_WEST

	setspeaker Speaker_SilvaBullet
	trainerbattle_no_intro TRAINER_SILVABULLET, VirtualCity_Stadium_Arena_Text_SilvaBulletWin
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostGold
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_SILVABULLET, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_SILVABULLET
	setvar VAR_PETALBURG_CITY_STATE, 31

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_EarlGreyFight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_EARLGREY
	applymovement LOCALID_EARLGREY, VirtualCity_Stadium_Arena_Move_CommonApproachArenaSlow
	waitmovement 0
	speak LOCALID_EARLGREY, VirtualCity_Stadium_Arena_Text_EarlGreyIntro, Speaker_EarlGrey, DIR_WEST

	setspeaker Speaker_EarlGrey
	trainerbattle_no_intro TRAINER_EARLGREY, VirtualCity_Stadium_Arena_Text_EarlGreyWin
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostGold
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_EARLGREY, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_EARLGREY
	setvar VAR_PETALBURG_CITY_STATE, 32

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end



VirtualCity_Stadium_Arena_Eventscript_ByronB1Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_BYRON
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_ByronApproachArena1
	waitmovement 0
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB1Intro1, Speaker_Byron, DIR_NORTH
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_ByronApproachArena2
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB1Intro2, Speaker_Byron, DIR_WEST

	setspeaker Speaker_Byron
	trainerbattle_no_intro TRAINER_BYRON1, VirtualCity_Stadium_Arena_Text_ByronB1Win
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostPlatinum
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_BYRONB1
	setvar VAR_PETALBURG_CITY_STATE, 33

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_ByronB2Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	goto_if_set FLAG_ACT_II_WON_BYRONB1, VirtualCity_Stadium_Arena_Eventscript_ByronB2FightWinner
	addobject LOCALID_BYRON
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB2YouLostIntro, Speaker_Byron, DIR_WEST

	setspeaker Speaker_Byron
	trainerbattle_no_intro TRAINER_BYRON2, VirtualCity_Stadium_Arena_Text_ByronB2YouLostWin
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostPlatinum
	@speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB2YouLostLose, Speaker_Byron, DIR_WEST
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_BYRONB2
	setvar VAR_PETALBURG_CITY_STATE, 34

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end

VirtualCity_Stadium_Arena_Eventscript_ByronB2FightWinner::
	addobject LOCALID_BYRON
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB2YouWonIntro, Speaker_Byron, DIR_WEST

	setspeaker Speaker_Byron
	trainerbattle_no_intro TRAINER_BYRON2, VirtualCity_Stadium_Arena_Text_ByronB2YouWonWin
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostPlatinum
	@speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB2YouWonLose, Speaker_Byron, DIR_WEST
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty

	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	
	setflag FLAG_ACT_II_FOUGHT_BYRONB2
	setvar VAR_PETALBURG_CITY_STATE, 34

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end


VirtualCity_Stadium_Arena_Eventscript_ByronB3Fight::
	@play se crowds
	clearflag FLAG_ACT_II_MOD_INSTALLED
	addobject LOCALID_BYRON
	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	waitmovement 0
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB3Intro, Speaker_Byron, DIR_WEST

	setspeaker Speaker_Byron
	trainerbattle_no_intro TRAINER_BYRON3, VirtualCity_Stadium_Arena_Text_ByronB3Win1
	@goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Arena_Eventscript_LostPlatinum
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
    special CallFrontierUtilFunc
    special LoadPlayerParty
	special HealPlayerParty
	@applymovement throw Zoroark TOFOLD
	speak LOCALID_BYRON, VirtualCity_Stadium_Arena_Text_ByronB3Win2, Speaker_Byron, DIR_WEST
	

	applymovement LOCALID_BYRON, VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow
	waitmovement 0
	@applymovement retrieve Zoroark TOFOLD

	setflag FLAG_ACT_II_FOUGHT_BYRONB3
	setvar VAR_PETALBURG_CITY_STATE, 35

	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate
	end




VirtualCity_Stadium_Arena_Move_CommonApproachArena::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

VirtualCity_Stadium_Arena_Move_CommonApproachArenaSlow::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

VirtualCity_Stadium_Arena_Move_CommonLeaveArena::
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VirtualCity_Stadium_Arena_Move_CommonLeaveArenaSlow::
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end


VirtualCity_Stadium_Arena_Move_ByronApproachArena1::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

VirtualCity_Stadium_Arena_Move_ByronApproachArena2::
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end






VirtualCity_Stadium_Arena_Text_Rando1Intro:
	.string "Oh thank god, you look weak.\n"
	.string "My Inteleon needs a win!$"

VirtualCity_Stadium_Arena_Text_Rando1Win:
	.string "Ugh, you weren't weak.\n"
	.string "I feel lied to.$"


VirtualCity_Stadium_Arena_Text_Rando2Intro:
	.string "Hi! I like the Sun!$"

VirtualCity_Stadium_Arena_Text_Rando2Win:
	.string "That was the worst RNG I've ever seen.\n"
	.string "I guess skill is no match for luck.$"


VirtualCity_Stadium_Arena_Text_Rando3Intro:
	.string "Hello, dearie! Want to see my\n"
	.string "adorable collection?$"

VirtualCity_Stadium_Arena_Text_Rando3Win:
	.string "I knew I wouldn't win, dearie.\n"
	.string "I just wanted to show off!$"


VirtualCity_Stadium_Arena_Text_Rando4Intro:
	.string "Nice, a new face! Let's fight!$"

VirtualCity_Stadium_Arena_Text_Rando4Win:
	.string "Whoa, you're good! Rematch me later,\n"
	.string "I know your tricks now!$"


VirtualCity_Stadium_Arena_Text_Rando5Intro:
	.string "Give me a challenge.$"

VirtualCity_Stadium_Arena_Text_Rando5Win:
	.string "Hmph. You delivered.\n"
	.string "Off meta Pokemon, but used well.$"



VirtualCity_Stadium_Arena_Text_BroDudeIntro:
	.string "Sup brah? Less go.$"

VirtualCity_Stadium_Arena_Text_BroDudeWin:
	.string "Bruh. Not cool.$"


VirtualCity_Stadium_Arena_Text_WvddieIntro:
	.string "HI' I VW WVDDIE$"

VirtualCity_Stadium_Arena_Text_WvddieWin:
	.string "HWWW' OK' I,W BVD\n"
	.string "CIVO$"


VirtualCity_Stadium_Arena_Text_SilvaBulletIntro:
	.string "You're new, aren't you? Time to learn\n"
	.string "a thing or two, heh.$"

VirtualCity_Stadium_Arena_Text_SilvaBulletWin:
	.string "What kind of garbage was that!?\n"
	.string "Best of one cheese, ugh.$"


VirtualCity_Stadium_Arena_Text_EarlGreyIntro:
	.string "My battling style is like black tea.\n"
	.string "It leaves you craving more.$"

VirtualCity_Stadium_Arena_Text_EarlGreyWin:
	.string "Hmph. Well done.\n"
	.string "I shall not be bitter.$"


VirtualCity_Stadium_Arena_Text_ByronB1Intro1:
	.string "Come on, make some noise for the champ!$"

VirtualCity_Stadium_Arena_Text_ByronB1Intro2:
	.string "Wait, what the…?\p"
	.string "How did you get into Plat with a team\n"
	.string "like that?!\p"
	.string "Bring some legendaries next time!\n"
	.string "My ELO won't go up if you use trash!$"


VirtualCity_Stadium_Arena_Text_ByronB1Lose:
	.string "Wow, that was a pathetic team.\p"
	.string "Mismatched, cheap Pokemon just can't\n"
	.string "compete with the best of the best.$"


VirtualCity_Stadium_Arena_Text_ByronB1Win:
	.string "You.\p"
	.string "You shouldn't have done that.\n"
	.string "You don't know who I am.$"



VirtualCity_Stadium_Arena_Text_ByronB2YouWonIntro:
	.string "50 points.\p"
	.string "That's the hit my ELO just took.\p"
	.string "Beating you will probably give me\n"
	.string "half a point, if that.\p"
	.string "So, I'm going to thrash you over and\n"
	.string "over until I get them all back.$"

VirtualCity_Stadium_Arena_Text_ByronB2YouLostIntro:
	.string "Hahahaha! Look everyone, she actually\n"
	.string "came back.\p"
	.string "I see what you're trying to do, y'know.\p"
	.string "Here's a tip, honey - I would never\n"
	.string "date a loser like you.\p"
	.string "Now, just die quickly.$"


VirtualCity_Stadium_Arena_Text_ByronB2YouWonWin:
	.string "Security!\p"
	.string "This woman's clearly cheating, and\n"
	.string "I want you to arrest her.$"

VirtualCity_Stadium_Arena_Text_ByronB2YouWonLose:
	.string "Not so tough now, huh?\p"
	.string "And, unfortunately for you, it was\n"
	.string "less than half of a point.\p"
	.string "I'm gonna whip you a hundred more\n"
	.string "times so you can pay your debt to me.$"


VirtualCity_Stadium_Arena_Text_ByronB2YouLostWin:
	.string "You.\p"
	.string "You shouldn't have done that.\p"
	.string "You don't know who I am.$"

VirtualCity_Stadium_Arena_Text_ByronB2YouLostLose:
	.string "Why do they call it a best of three,\n"
	.string "anyway? Never understood that.\p"
	.string "Now get out of my sight - your\n"
	.string "fifteen minutes of fame are over.$"


VirtualCity_Stadium_Arena_Text_ByronB3Intro:
	.string "You know what my problem is?\p"
	.string "I'm too tolerant. \p"
	.string "A roach crawls into my house, and I\n"
	.string "let it be for a while, instead of\p"
	.string "crushing it immediately.\p"
	.string "Not gonna make that mistake again.$"

VirtualCity_Stadium_Arena_Text_ByronB3Win1:
	.string "It's rigged! It's rigged!\p"
	.string "Stupid, useless Pokemon!\n"
	.string "Can't do anything right!$"

VirtualCity_Stadium_Arena_Text_ByronB3Win2:
	.string "And you.\p"
	.string "I run this Place, and I better not see\n"
	.string "your face here ever again, understand?$"

VirtualCity_Stadium_Arena_Text_ByronB3Lose:
	.string "Wasn't even close.\p"
	.string "I've got better Pokemon, better skill,\n"
	.string "better predictions…\p"
	.string "And all you got is luck.$"





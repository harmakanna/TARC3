VirtualCity_Stadium_Arena_MapScripts::
	.byte 0

@ Extra Speakers

Speaker_Challenger::
	.string "Challenger$"

Speaker_BrodDude69::
	.string "BrodDude69$"

Speaker_Wvddie::
	.string "WVDDIE$"

Speaker_SilvaBullet::
	.string "SilvaBullet$"

Speaker_EarlGrey::
	.string "Earl Grey$"

Common_Text_NotEnoughPokemon:
	.string "Bug! Error code: 0x000071$"

VirtualCity_Stadium_Arena_Eventscript_Rando1Fight::
	@play se crowds
	addobject LOCALID_RANDO1
	applymovement LOCALID_RANDO1, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	speak LOCALID_RANDO1, VirtualCity_Stadium_Arena_Text_Rando1Intro, Speaker_Challenger, DIR_WEST
	trainerbattle_double TRAINER_RANDO1, VirtualCity_Stadium_Arena_Text_Rando1Intro, VirtualCity_Stadium_Arena_Text_Rando1Win, Common_Text_NotEnoughPokemon
	applymovement LOCALID_RANDO1, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	
	setflag FLAG_ACT_II_FOUGHT_RANDO1
	setvar VAR_PETALBURG_CITY_STATE, 24

	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate

VirtualCity_Stadium_Arena_Eventscript_Rando2Fight::
	@play se crowds
	addobject LOCALID_RANDO2
	applymovement LOCALID_RANDO2, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	speak LOCALID_RANDO2, VirtualCity_Stadium_Arena_Text_Rando2Intro, Speaker_Challenger, DIR_WEST
	trainerbattle_double TRAINER_RANDO2, VirtualCity_Stadium_Arena_Text_Rando2Intro, VirtualCity_Stadium_Arena_Text_Rando2Win, Common_Text_NotEnoughPokemon
	applymovement LOCALID_RANDO2, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	
	setflag FLAG_ACT_II_FOUGHT_RANDO2
	setvar VAR_PETALBURG_CITY_STATE, 25

	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate

VirtualCity_Stadium_Arena_Eventscript_Rando3Fight::
	@play se crowds
	addobject LOCALID_RANDO3
	applymovement LOCALID_RANDO3, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	speak LOCALID_RANDO3, VirtualCity_Stadium_Arena_Text_Rando3Intro, Speaker_Challenger, DIR_WEST
	trainerbattle_double TRAINER_RANDO3, VirtualCity_Stadium_Arena_Text_Rando3Intro, VirtualCity_Stadium_Arena_Text_Rando3Win, Common_Text_NotEnoughPokemon
	applymovement LOCALID_RANDO3, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	
	setflag FLAG_ACT_II_FOUGHT_RANDO3
	setvar VAR_PETALBURG_CITY_STATE, 26

	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate

VirtualCity_Stadium_Arena_Eventscript_Rando4Fight::
	@play se crowds
	addobject LOCALID_RANDO4
	applymovement LOCALID_RANDO4, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	speak LOCALID_RANDO4, VirtualCity_Stadium_Arena_Text_Rando4Intro, Speaker_Challenger, DIR_WEST
	trainerbattle_double TRAINER_RANDO4, VirtualCity_Stadium_Arena_Text_Rando4Intro, VirtualCity_Stadium_Arena_Text_Rando4Win, Common_Text_NotEnoughPokemon
	applymovement LOCALID_RANDO4, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	
	setflag FLAG_ACT_II_FOUGHT_RANDO4
	setvar VAR_PETALBURG_CITY_STATE, 27

	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate

VirtualCity_Stadium_Arena_Eventscript_Rando5Fight::
	@play se crowds
	addobject LOCALID_RANDO5
	applymovement LOCALID_RANDO5, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	speak LOCALID_RANDO5, VirtualCity_Stadium_Arena_Text_Rando5Intro, Speaker_Challenger, DIR_WEST
	trainerbattle_double TRAINER_RANDO5, VirtualCity_Stadium_Arena_Text_Rando5Intro, VirtualCity_Stadium_Arena_Text_Rando5Win, Common_Text_NotEnoughPokemon
	applymovement LOCALID_RANDO5, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	
	setflag FLAG_ACT_II_FOUGHT_RANDO5
	setvar VAR_PETALBURG_CITY_STATE, 28

	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate





VirtualCity_Stadium_Arena_Eventscript_BrodudeFight::
	@play se crowds
	addobject LOCALID_BRODUDE
	applymovement LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Move_CommonApproachArena
	speak LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Text_BroDudeIntro, Speaker_Challenger, DIR_WEST
	trainerbattle_double TRAINER_BRODUDE, VirtualCity_Stadium_Arena_Text_BroDudeIntro, VirtualCity_Stadium_Arena_Text_BroDudeWin, Common_Text_NotEnoughPokemon
	applymovement LOCALID_BRODUDE, VirtualCity_Stadium_Arena_Move_CommonLeaveArena
	
	setflag FLAG_ACT_II_FOUGHT_BRODUDE
	setvar VAR_PETALBURG_CITY_STATE, 24

	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4, 2
	waitstate




VirtualCity_Stadium_Arena_Move_CommonApproachArena::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
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
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
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


VirtualCity_Stadium_Arena_Text_Rando1Intro:
	.string "Oh thank god, you look weak.$"

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


VirtualCity_Stadium_Arena_Text_OneHitIntro:
	.string "You're new, aren't you? Time to learn\n"
	.string "a thing or two, heh.$"

VirtualCity_Stadium_Arena_Text_OneHitWin:
	.string "What kind of garbage was that!?\n"
	.string "Best of one cheese, ugh.$"


VirtualCity_Stadium_Arena_Text_EarlGreyIntro:
	.string "My battling style is like black tea.\n"
	.string "a thing or two, heh.$"

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
	.string "You shouldn't have done that.\p"
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





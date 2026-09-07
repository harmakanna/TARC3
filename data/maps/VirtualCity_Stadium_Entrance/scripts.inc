VirtualCity_Stadium_Entrance_MapScripts::
	.byte 0



VirtualCity_Stadium_Entrance_EventScript_Act_II_Harriet::
	goto_if_set FLAG_ACT_II_HARRIET_EXPLANATION, VirtualCity_Stadium_Entrance_EventScript_Harriet_Reexplains
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet1, MSGBOX_NPC
	setspeaker Speaker_Sophie
	msgbox VirtualCity_Stadium_Entrance_Text_ActII_Intro_Sophie2, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet3, MSGBOX_NPC
	setflag FLAG_ACT_II_HARRIET_EXPLANATION
	end


VirtualCity_Stadium_Entrance_EventScript_Receptionist::
	setspeaker Speaker_Receptionist
	msgbox VirtualCity_Stadium_Entrance_Text_ReceptionistIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Stadium_Entrance_EventScript_ReceptionistEnd
    goto_if_eq VAR_RESULT, YES, VirtualCity_Stadium_Entrance_Eventscript_ReceptionistCheckPokemon
	end


VirtualCity_Stadium_Entrance_EventScript_ReceptionistEnd::
	setspeaker Speaker_Receptionist
	msgbox VirtualCity_Stadium_Entrance_Text_ReceptionistEnd, MSGBOX_NPC
	closemessage
	end

VirtualCity_Stadium_Entrance_Eventscript_ReceptionistCheckPokemon::
	getpartysize
	goto_if_eq VAR_RESULT, 1, VirtualCity_Stadium_Entrance_Eventscript_ReceptionistNotEnoughPokemon
	goto_if_eq VAR_RESULT, 2, VirtualCity_Stadium_Entrance_Eventscript_ReceptionistNotEnoughPokemon
	goto_if_eq VAR_RESULT, 3, VirtualCity_Stadium_Entrance_Eventscript_ReceptionistNotEnoughPokemon
	goto_if_eq VAR_RESULT, 4, VirtualCity_Stadium_Entrance_Eventscript_Receptionist4or5Pokemon
	goto_if_eq VAR_RESULT, 5, VirtualCity_Stadium_Entrance_Eventscript_Receptionist4or5Pokemon
	goto_if_eq VAR_RESULT, 6, VirtualCity_Stadium_Entrance_Eventscript_ReceptionistStartTourney
	end


VirtualCity_Stadium_Entrance_Eventscript_ReceptionistNotEnoughPokemon::
	setspeaker Speaker_Receptionist
	msgbox VirtualCity_Stadium_Entrance_Text_ReceptionistNotEnoughPokemon, MSGBOX_NPC
	closemessage
	end


VirtualCity_Stadium_Entrance_Eventscript_Receptionist4or5Pokemon::
	setspeaker Speaker_Receptionist
	msgbox VirtualCity_Stadium_Entrance_Text_Receptionist4or5Pokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Stadium_Entrance_EventScript_ReceptionistEnd
    goto_if_eq VAR_RESULT, YES, VirtualCity_Stadium_Entrance_Eventscript_ReceptionistStartTourney
	end


VirtualCity_Stadium_Entrance_Eventscript_ReceptionistStartTourney::
	setspeaker Speaker_Receptionist
	msgbox VirtualCity_Stadium_Entrance_Text_ReceptionistStartTourney, MSGBOX_NPC
	closemessage
	playse SE_EXIT
	warpsilent MAP_VIRTUAL_CITY_STADIUM_PRE_BATTLE_ROOM, 4,7
	waitstate
	end



VirtualCity_Stadium_Entrance_Text_ReceptionistIntro::
	.string "Welcome to the {COLOR GREEN}BETTER {COLOR DARK_GRAY}Tournament!\n"
	.string "It's {COLOR GREEN}BETTER {COLOR DARK_GRAY}than reality!\p"
	.string "Are you here to register?$"

VirtualCity_Stadium_Entrance_Text_ReceptionistEnd::
	.string "Have a {COLOR GREEN}BETTER {COLOR DARK_GRAY}day!$"

VirtualCity_Stadium_Entrance_Text_ReceptionistNotEnoughPokemon::
	.string "Ooh, honey, it looks like you don't\n"
	.string "have enough Pokemon!\p"
	.string "You need at least four to compete,\n"
	.string "but you should get a full team of six!\p"
	.string "Come back when you save up for them!\p"
	.string "Have a {COLOR GREEN}BETTER {COLOR DARK_GRAY}day!$"

VirtualCity_Stadium_Entrance_Text_Receptionist4or5Pokemon::
	.string "Ooh, honey, you sure you don't want\n"
	.string "to enter with a full team of six?\p"
	.string "There's a lot of tough trainers here,\n"
	.string "you know! You sure?$"

VirtualCity_Stadium_Entrance_Text_ReceptionistStartTourney::
	.string "Okay, honey, good luck!\n"
	.string "Have a {COLOR GREEN}BETTER {COLOR DARK_GRAY}day!$"




VirtualCity_Stadium_Entrance_EventScript_Harriet_Reexplains::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_Entrance_Text_ActII_Intro_HarrietReexplains, MSGBOX_NPC
	end








VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet1::
	.string "Hey Sophie!\p"
	.string "So, I've been scoping it out. There's\n"
	.string "three tiers of competition here.\p"
	.string "All VGC rules - bring six, use four.\p"
	.string "There's the Silver rank, where mostly\n"
	.string "amateurs fight for fun.\p"
	.string "There's the Gold rank, for rich folks\n"
	.string "who can afford meta teams.\p"
	.string "And then there's Platinum rank, which\n"
	.string "is more serious - it's a best of three.\p"
	.string "But… these days it's all cheaters.\p"
	.string "Unreleased Pokemon, hacked stats, you\n"
	.string "know the drill.\p"
	.string "Byron, the champ, is in Platinum, and\n"
	.string "loves, uh, pwning noobs. So if you can\l"
	.string "somehow get Platinum, he'll fight you.\p"
	.string "And Ernest reckons they can use his\n"
	.string "hacked Pokemon as a backdoor to his ID.\p"
	.string "But Sophie, can you really climb the ranks\n"
	.string "without the expensive mons they'll have?$"

VirtualCity_Stadium_Entrance_Text_ActII_Intro_Sophie2::
	.string "Don't worry.\p"
	.string "Byron may have paid a hacker, but he\n"
	.string "can't modify them himself.\p"
	.string "My Pokemon will start weaker, but I\n"
	.string "can make them stronger each battle.$"

VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet3::
	.string "If you say so. Well, anyway, you'll\n"
	.string "need at least four Pokemon to enter.\p"
	.string "There's a lot of folks around who need\n"
	.string "help with something - see if any of\l"
	.string "them have dupes you can borrow.$"




VirtualCity_Stadium_Entrance_Text_ActII_Intro_HarrietReexplains::
	.string "Didja get a team yet?\p"
	.string "Six Pokemon is the best, but you\n"
	.string "might be able to manage with five.\p"
	.string "Talk to the attendant if you're ready.$"








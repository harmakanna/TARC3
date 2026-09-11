VirtualCity_Stadium_Entrance_MapScripts::
	.byte 0



VirtualCity_Stadium_Entrance_EventScript_Act_II_Harriet::
	lockall
	goto_if_set FLAG_ACT_II_HARRIET_EXPLANATION, VirtualCity_Stadium_Entrance_EventScript_Harriet_Reexplains
	npc_speak Speaker_Harriet, VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet1
	playse SE_SELECT
	player_speak VirtualCity_Stadium_Entrance_Text_ActII_Intro_Sophie2
	playse SE_SELECT
	npc_speak Speaker_Harriet, VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet3
	playse SE_SELECT
	additem ITEM_SPELL_TAG, 1
	setspeaker NULL
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Stadium_Entrance_Text_ReceivedCoupon
	waitfanfare
	delay 100
	player_speak VirtualCity_Stadium_Entrance_Text_ActII_Intro_Sophie4
	playse SE_SELECT
	npc_speak Speaker_Harriet, VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet5
	closemessage
	setflag FLAG_ACT_II_HARRIET_EXPLANATION
	releaseall
	end


VirtualCity_Stadium_Entrance_EventScript_Receptionist::
	goto_if_set FLAG_ACT_II_COMPLETE, VirtualCity_Stadium_Entrance_EventScript_ReceptionistNoWay
	setspeaker Speaker_Receptionist
	msgbox VirtualCity_Stadium_Entrance_Text_ReceptionistIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Stadium_Entrance_EventScript_ReceptionistEnd
    goto_if_eq VAR_RESULT, YES, VirtualCity_Stadium_Entrance_Eventscript_ReceptionistCheckPokemon
	end

VirtualCity_Stadium_Entrance_EventScript_ReceptionistNoWay::
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_Entrance_Text_ReceptionistNoWay, MSGBOX_DEFAULT
	closemessage
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

VirtualCity_Stadium_Entrance_EventScript_Gallade::
	msgbox VirtualCity_Stadium_Entrance_Text_Gallade, MSGBOX_NPC
	end

VirtualCity_Stadium_Entrance_EventScript_Gardevoir::
	msgbox VirtualCity_Stadium_Entrance_Text_Gardevoir, MSGBOX_NPC
	end

VirtualCity_Stadium_Entrance_Text_Gardevoir:
	.string "I dunno, I think I can do well,\n"
	.string "but I'm just a bit scared…\p"
	.string "Everyone'll be out there watching\n"
	.string "me battle…$"

VirtualCity_Stadium_Entrance_Text_Gallade:
	.string "It's okay honey, I believe in you!\n"
	.string "I'll be right by your side.\p"
	.string "You'll make waves out there!$"

VirtualCity_Stadium_Entrance_Text_ReceptionistIntro::
	.string "HIIIIIII!!!\p"
	.string "Welcome to the {COLOR GREEN}BETTER {COLOR DARK_GRAY}Tournament!\n"
	.string "It's {COLOR GREEN}BETTER {COLOR DARK_GRAY}than reality!\p"
	.string "Are you here to register?$"

VirtualCity_Stadium_Entrance_Text_ReceptionistEnd::
	.string "Have a {COLOR GREEN}BETTER {COLOR DARK_GRAY}day!$"

VirtualCity_Stadium_Entrance_Text_ReceptionistNotEnoughPokemon::
	.string "Ooh, honey, it looks like you don't\n"
	.string "have enough POKéMON!\p"
	.string "You need at least four to compete,\n"
	.string "but you should get a full team of six!\p"
	.string "Come back when you save up for them!\p"
	.string "Have a {COLOR GREEN}BETTER {COLOR DARK_GRAY}day!$"

VirtualCity_Stadium_Entrance_Text_Receptionist4or5Pokemon::
	.string "Ooh, honey, you sure you don't want\n"
	.string "to enter with a full team of six?\p"
	.string "There's a lot of tough trainers here,\n"
	.string "you know\p"
	.string "You sure?$"

VirtualCity_Stadium_Entrance_Text_ReceptionistStartTourney::
	.string "Okay, honey, good luck!\n"
	.string "Have a {COLOR GREEN}BETTER {COLOR DARK_GRAY}day!$"

VirtualCity_Stadium_Entrance_Text_ReceptionistNoWay::
	.string "No way am I signing up again!\n"
	.string "Well, not until the postgame…$"



VirtualCity_Stadium_Entrance_EventScript_Harriet_Reexplains::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_Entrance_Text_ActII_Intro_HarrietReexplains, MSGBOX_NPC
	end

VirtualCity_Stadium_Entrance_Text_ReceivedCoupon::
	.string "You received a BETTER Coupon!$"






VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet1::
	.string "Hey Sophie!\p"
	.string "So, I've been scoping it out. There's\n"
	.string "three tiers of competition here.\p"
	.string "It's a classic format:\p"
	.string "Bring six, use four.\p"
	.string "There's the Silver rank, where mostly\n"
	.string "amateurs fight for fun.\p"
	.string "There's the Gold rank, for rich folks\n"
	.string "who can afford meta teams.\p"
	.string "And then there's Platinum rank, which\n"
	.string "is more serious - it's a best of three.\p"
	.string "But… these days it's all cheaters.\p"
	.string "Unreleased POKéMON, hacked stats, you\n"
	.string "know the drill.\p"
	.string "Byron, the champ, is in Platinum, and\n"
	.string "loves…{PAUSE 30} Uh…\p"
	.string "Pwning noobs.\p"
	.string "So if you can somehow get Platinum,\n"
	.string "he'll fight you.\p"
	.string "And Ernest reckons they can use his\n"
	.string "hacked POKéMON as a backdoor to his ID.\p"
	.string "Sophie.\pCAN you climb the ranks without the\n"
	.string "stupid mons they'll have?$"

VirtualCity_Stadium_Entrance_Text_ActII_Intro_Sophie2::
	.string "Don't worry.\p"
	.string "Byron may have paid a hacker, but he\n"
	.string "can't modify them himself.\p"
	.string "My POKéMON will start weaker, but I\n"
	.string "can make them stronger each battle.$"

VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet3::
	.string "If you say so.\p"
	.string "Well, anyway, you'll need at least\n"
	.string "four POKéMON to enter.\p"
	.string "There's a lot of folks around who need\n"
	.string "help with something!\p"
	.string "See if any of them have dupes\n"
	.string "you can borrow.\p"
	.string "And, um, take this.$"

VirtualCity_Stadium_Entrance_Text_ActII_Intro_Sophie4::
	.string "What? A POKéMON Shop coupon?\n"
	.string "No, I can't-$"

VirtualCity_Stadium_Entrance_Text_ActII_Intro_Harriet5::
	.string "Hush!\p"
	.string "Not a word.\p"
	.string "You're the one who's going to be in\n"
	.string "danger, here!\p"
	.string "We all chipped in. This is\n"
	.string "the least we can do.\p"
	.string "Get to the third floor of the store\n"
	.string "and make yourself a team!$"


VirtualCity_Stadium_Entrance_Text_ActII_Intro_HarrietReexplains::
	.string "Didja get a team yet?\p"
	.string "Six POKéMON is the best, but you\n"
	.string "might be able to manage with five.\p"
	.string "Talk to the attendant if you're ready.$"





VirtualCity_Stadium_Entrance_EventScript_Contentment::
	goto_if_set FLAG_CONTENTMENT_QUEST_COMPLETE, VirtualCity_Stadium_Entrance_EventScript_ContentmentCompleteRepeat
	goto_if_set FLAG_CONTENTMENT_QUEST_MOVE_USED, VirtualCity_Stadium_Entrance_EventScript_ContentmentComplete
	goto_if_set FLAG_CONTENTMENT_QUEST_STARTED, VirtualCity_Stadium_Entrance_EventScript_ContentmentRepeat

	npc_speak NULL, VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart1
	playse SE_SELECT
	player_speak VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart2
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart3
	playse SE_SELECT
	player_speak VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart4
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart5
	playse SE_SELECT
	player_speak VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart6
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart7

	startquest QUEST_CONTENTMENT
	setflag FLAG_CONTENTMENT_QUEST_STARTED
	clearflag FLAG_CONTENTMENT_QUEST_MOVE_USED
	givemon SPECIES_TOXAPEX, 50, nature=NATURE_CALM, gender=MON_FEMALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_TOXIC, move2=MOVE_SCALD, move3=MOVE_ICY_WIND, move4=MOVE_CELEBRATE, otName=OT_Contentment
	end

VirtualCity_Stadium_Entrance_EventScript_ContentmentRepeat::
	msgbox VirtualCity_Stadium_Entrance_Text_ContentmentQuestRepeat, MSGBOX_NPC
	end

VirtualCity_Stadium_Entrance_EventScript_ContentmentComplete::
	lock
	player_speak VirtualCity_Stadium_Entrance_Text_ContentmentQuestSophieComplete
	npc_speak NULL, VirtualCity_Stadium_Entrance_Text_ContentmentQuestComplete
	completequest QUEST_CONTENTMENT
	setflag FLAG_CONTENTMENT_QUEST_COMPLETE
	end

VirtualCity_Stadium_Entrance_EventScript_ContentmentCompleteRepeat::
	msgbox VirtualCity_Stadium_Entrance_Text_ContentmentQuestCompleteRepeat, MSGBOX_NPC
	closemessage
	end


VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart1::
	.string "Hello! You look like a fine trainer!\n"
	.string "Would you be interested in a sponsor?\p"
	.string "The world-renowned camping and hiking\n"
	.string "brand, conTENTment, is diversifying!$"

VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart2::
	.string "Um, okay?$"

VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart3::
	.string "People aren't going camping as much\n"
	.string "as much as they used to, you see.\p"
	.string "We both know {COLOR BLUE}the way{COLOR DARK_GRAY} to experience\n"
	.string "a city park is from a tent, but\l"
	.string "the quarterly numbers don't agree.\p"
	.string "So, we're releasing a new line of\n"
	.string "virtual tents and supplies!\p"
	.string "Soon you too can camp out under\n"
	.string "the stars, just like old times!$"

VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart4::
	.string "Can you, maybe, get to the point?$"

VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart5::
	.string "We need as many brand ambassadors\n"
	.string "as we can get!\p"
	.string "It's simple! All you have to do is\n"
	.string "bring our custom POKéMON into the\l"
	.string "arena, and use the {COLOR BLUE}promotional move{COLOR DARK_GRAY}!\p"
	.string "And you'll get to keep the POKéMON!\n"
	.string "{FONT_SMALL}As long as you battle with it quarterly.$"

VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart6::
	.string "I-{PAUSE 20} I guess I'm interested.$"	

VirtualCity_Stadium_Entrance_Text_ContentmentQuestStart7::
	.string "Wonderful! If you'll just sign here…\p"
	.string "…\p"
	.string "Perfect. Now, use the move in a Stadium\n"
	.string "battle, and come back when you're done!$"


VirtualCity_Stadium_Entrance_Text_ContentmentQuestRepeat::
	.string "What are you waiting for?\n"
	.string "Shareholders won't wait forever!$"

VirtualCity_Stadium_Entrance_Text_ContentmentQuestSophieComplete::
	.string "Hi, I played your ad in battle…$"

VirtualCity_Stadium_Entrance_Text_ContentmentQuestComplete::
	.string "Um, hi. Good news and bad news.\p"
	.string "The good news is that the ad reached\n"
	.string "a lot of eyes.\p"
	.string "The bad news?\p"
	.string "People started questioning why we'd\n"
	.string "represent ourselves with a Toxapex.\p"
	.string "So, well done, and keep the POKéMON,\n"
	.string "but please…\p"
	.string "{COLOR RED}Never do that again.\p"
	.string "{COLOR DARK_GRAY}It could really damage the brand.$"


VirtualCity_Stadium_Entrance_Text_ContentmentQuestCompleteRepeat::
	.string "Um. Please don't stand near me.\n"
	.string "People might make associations.$"





VirtualCity_Stadium_Entrance_EventScript_Baby::
	goto_if_set FLAG_BABY_QUEST_COMPLETE, VirtualCity_Stadium_Entrance_EventScript_BabyComplete
	goto_if_set FLAG_BABY_QUEST_STARTED, VirtualCity_Stadium_Entrance_EventScript_BabyCheck
	call_if_set FLAG_IM_BABY, VirtualCity_Stadium_Entrance_EventScript_SpeakerBaby
	npc_speak Speaker_Baby, VirtualCity_Stadium_Entrance_Text_BabyIntro
	closemessage
	startquest QUEST_BABY
	setflag FLAG_BABY_QUEST_STARTED
	end

VirtualCity_Stadium_Entrance_EventScript_SpeakerBaby::
	setspeaker Speaker_Baby
	return

Speaker_Fight_Baby:
	.string "fight baby$"

VirtualCity_Stadium_Entrance_EventScript_BabyCheck::

	checkspecies SPECIES_EXCADRILL
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Stadium_Entrance_EventScript_BabyFail
	checkspecies SPECIES_TOXAPEX
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Stadium_Entrance_EventScript_BabyFail
	checkspecies SPECIES_LEDIAN
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Stadium_Entrance_EventScript_BabyFail
	checkspecies SPECIES_SOLROCK
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Stadium_Entrance_EventScript_BabyFail
	checkspecies SPECIES_PASSIMIAN
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Stadium_Entrance_EventScript_BabyFail
	checkspecies SPECIES_SABLEYE
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Stadium_Entrance_EventScript_BabyFail
	checkspecies SPECIES_ELECTRODE
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Stadium_Entrance_EventScript_BabyFail
	checkspecies SPECIES_DARKANINE
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Stadium_Entrance_EventScript_BabyFail

	setspeaker Speaker_Fight_Baby
	npc_speak Speaker_Baby, VirtualCity_Stadium_Entrance_Text_BabyMaybeBaby
	closemessage
	trainerbattle_no_intro TRAINER_BYRON2, VirtualCity_Stadium_Entrance_Text_BabyThinking
	special HealPlayerParty
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VirtualCity_Stadium_Entrance_EventScript_BabyLose
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, VirtualCity_Stadium_Entrance_EventScript_BabyLose
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VirtualCity_Stadium_Entrance_EventScript_BabyLose
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, VirtualCity_Stadium_Entrance_EventScript_BabyLose
	
	setspeaker Speaker_Fight_Baby
	npc_speak Speaker_Baby, VirtualCity_Stadium_Entrance_Text_BabyUBaby
	closemessage
	applymovement LOCALID_STADIUMBABY, Common_Movement_WalkInPlaceDown
	waitmovement 0
	faceplayer
	delay 50
	additem ITEM_SPELL_TAG, 1
	setspeaker NULL
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Stadium_Entrance_Text_ReceivedCoupon
	waitfanfare
	delay 100
	completequest QUEST_BABY
	setflag FLAG_BABY_QUEST_COMPLETE
	end



VirtualCity_Stadium_Entrance_EventScript_BabyFail::
	setspeaker Speaker_Fight_Baby
	npc_speak Speaker_Baby, VirtualCity_Stadium_Entrance_Text_BabyNotBaby
	closemessage
	end

VirtualCity_Stadium_Entrance_EventScript_BabyLose::
	setspeaker Speaker_Fight_Baby
	npc_speak Speaker_Baby, VirtualCity_Stadium_Entrance_Text_BabyMaybeBaby
	closemessage


VirtualCity_Stadium_Entrance_EventScript_BabyComplete::
	setspeaker Speaker_Fight_Baby
	npc_speak Speaker_Baby, VirtualCity_Stadium_Entrance_Text_BabyWeBaby
	closemessage
	end


VirtualCity_Stadium_Entrance_Text_BabyIntro:
	.string "im baby\p"
	.string "awena\p"
	.string "im fight baby$"

VirtualCity_Stadium_Entrance_Text_BabyNotBaby:
	.string "u not baby\p"
	.string "fight\p"
	.string "only baby$"

VirtualCity_Stadium_Entrance_Text_BabyMaybeBaby:
	.string "u baby?$"

VirtualCity_Stadium_Entrance_Text_BabyThinking:
	.string "…$"

VirtualCity_Stadium_Entrance_Text_BabyUBaby:
	.string "u baby$"

VirtualCity_Stadium_Entrance_Text_BabyWeBaby:
	.string "we babys$"

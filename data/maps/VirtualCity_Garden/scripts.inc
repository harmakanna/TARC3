VirtualCity_Garden_MapScripts::
	.byte 0

VirtualCity_Garden_LedianLover::
	lockall
	faceplayer
	returnqueststate QUEST_LEDIAN
	switch VAR_RESULT
	case 1, VirtualCity_Garden_LedianLoverActivate
	case 2, VirtualCity_Garden_LedianLoverActive
	case 3, VirtualCity_Garden_LedianLoverReward
	case 4, VirtualCity_Garden_LedianLoverComplete
	releaseall
	end

VirtualCity_Garden_LedianLoverActivate::
	npc_speak Speaker_LedianLover, VirtualCity_Garden_Text_LedianLover_ThisIsAnOutrage
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_WhatsUp
	playse SE_SELECT
	npc_speak Speaker_LedianLover, VirtualCity_Garden_Text_LedianLover_NoRelease
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_UmmImACreator
	playse SE_SELECT
	npc_speak Speaker_LedianLover, VirtualCity_Garden_Text_LedianLover_HugePower
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_SureThingBuddy
	startquest QUEST_LEDIAN
	releaseall
	end

VirtualCity_Garden_LedianLoverActive::
	setspeaker Speaker_LedianLover
	msgbox VirtualCity_Garden_Text_LedianLover_Cmon, MSGBOX_NPC
	releaseall
	end

VirtualCity_Garden_LedianLoverReward::
	npc_speak Speaker_LedianLover, VirtualCity_Garden_Text_LedianLover_WhatDoPeopleSay
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_PeopleDontCare
	playse SE_SELECT
	npc_speak Speaker_LedianLover, VirtualCity_Garden_Text_LedianLover_ButLedian
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_ThemsTheChops
	playse SE_SELECT
	npc_speak Speaker_LedianLover, VirtualCity_Garden_Text_LedianLover_Reward
	setspeaker NULL
	goto VirtualCity_Garden_LedianLover_ReceiveLedian
	end
	
VirtualCity_Garden_LedianLover_ReceiveLedian::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LEDIAN
	givemon SPECIES_LEDIAN, 50, nature=NATURE_CAREFUL, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_DRAIN_PUNCH, move2=MOVE_U_TURN, move3=MOVE_TOXIC, move4=MOVE_PROTECT, otName=OT_Ledian
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VirtualCity_Garden_LedianLover_ReceiveLedianParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VirtualCity_Garden_LedianLover_ReceiveLedianPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VirtualCity_Garden_LedianLover_ReceiveLedianParty::
	call VirtualCity_Garden_LedianLover_ReceiveLedianFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Garden_LedianLover_FinishReceivingLedian
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VirtualCity_Garden_LedianLover_FinishReceivingLedian
	end

VirtualCity_Garden_LedianLover_ReceiveLedianPC::
	call VirtualCity_Garden_LedianLover_ReceiveLedianFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Garden_LedianLover_TransferLedianToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VirtualCity_Garden_LedianLover_TransferLedianToPC
	end

VirtualCity_Garden_LedianLover_TransferLedianToPC::
	call Common_EventScript_TransferredToPC
	goto VirtualCity_Garden_LedianLover_FinishReceivingLedian
	end

VirtualCity_Garden_LedianLover_ReceiveLedianFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Garden_Text_YouReceivedLedian
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LEDIAN
	return

VirtualCity_Garden_LedianLover_FinishReceivingLedian::
	completequest QUEST_LEDIAN
	releaseall
	end

VirtualCity_Garden_LedianLoverComplete::
	setspeaker Speaker_LedianLover
	msgbox VirtualCity_Garden_LedianLoverDejected, MSGBOX_NPC
	releaseall
	end

VirtualCity_Garden_Baby::
	lock
	faceplayer
	goto_if_quest_not_active QUEST_LEDIAN, VirtualCity_Garden_BabyImBaby
	goto_if_set FLAG_LEDIAN_SPOKE_TO_BABY, VirtualCity_Garden_BabyImBaby
	player_speak VirtualCity_Garden_Text_Sophie_WhatDoYouThinkShort
	playse SE_SELECT
	call_if_set FLAG_IM_BABY, VirtualCity_Garden_BabyLedianKnown
	call_if_unset FLAG_IM_BABY, VirtualCity_Garden_BabyLedianUnknown
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_Okayyyy
	closemessage
	setflag FLAG_LEDIAN_SPOKE_TO_BABY
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	goto VirtualCity_Garden_CheckIfLedianQuestComplete
	end

VirtualCity_Garden_BabyLedianKnown::
	npc_speak Speaker_Baby, VirtualCity_Garden_Text_Togepi_LediansNotBaby
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_IUhh
	playse SE_SELECT
	npc_speak Speaker_Baby, VirtualCity_Garden_Text_Togepi_LediansNotBaby2
	return

VirtualCity_Garden_BabyLedianUnknown::
	npc_speak NULL, VirtualCity_Garden_Text_Togepi_LediansNotBaby
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_IUhh
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Garden_Text_Togepi_LediansNotBaby2
	return

VirtualCity_Garden_BabyImBaby::
	call_if_set FLAG_IM_BABY, VirtualCity_Garden_BabySetBaby
	msgbox VirtualCity_Garden_Text_Togepi_ImBaby MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_IM_BABY
	release
	end

VirtualCity_Garden_BabySetBaby::
	setspeaker Speaker_Baby
	return

@ KUMATORA - This guy is crashing

VirtualCity_Garden_Plump::
	goto_if_quest_not_active QUEST_LEDIAN, VirtualCity_Garden_PlumpYouCanBeAnyone
	goto_if_set FLAG_LEDIAN_SPOKE_TO_PLUMP, VirtualCity_Garden_PlumpYouCanBeAnyone
	lock
	player_speak VirtualCity_Garden_Text_Sophie_WhatDoYouThink
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Garden_Text_Plump_LedianStinks
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_Speechless
	closemessage
	setflag FLAG_LEDIAN_SPOKE_TO_PLUMP
	goto VirtualCity_Garden_CheckIfLedianQuestComplete
	end

VirtualCity_Garden_PlumpYouCanBeAnyone::
	lock
	npc_speak NULL, VirtualCity_Garden_Text_Plump_YouCanBeAnyone
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_Freaky
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Garden_Text_Plump_EveryonesACritic
	closemessage
	releaseall
	end 

VirtualCity_Garden_OldWoman::
	goto_if_quest_not_active QUEST_LEDIAN, VirtualCity_Garden_OldWomanImYoung
	goto_if_set FLAG_LEDIAN_SPOKE_TO_OLD_WOMAN, VirtualCity_Garden_OldWomanImYoung
	lock
	player_speak VirtualCity_Garden_Text_Sophie_WhatDoYouThink
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Garden_Text_OldWoman_WhyLedian
	multichoice 0, 0, MULTI_WHY_LEDIAN, TRUE
	switch VAR_RESULT
	case 0, VirtualCity_Garden_OldWoman_LedianCute
	case 1, VirtualCity_Garden_OldWoman_LedianBulky
	@Stays in the script if the last option is chosen
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Garden_Text_OldWoman_PunchesTickle
	goto VirtualCity_Garden_OldWoman_EndQuest
	end

VirtualCity_Garden_OldWoman_LedianCute::
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Garden_Text_OldWoman_CutiePie
	goto VirtualCity_Garden_OldWoman_EndQuest
	end

VirtualCity_Garden_OldWoman_LedianBulky::
	npc_speak NULL, VirtualCity_Garden_Text_OldWoman_SpecialBulk
	goto VirtualCity_Garden_OldWoman_EndQuest
	end

VirtualCity_Garden_OldWoman_EndQuest::
	closemessage
	setflag FLAG_LEDIAN_SPOKE_TO_OLD_WOMAN
	goto VirtualCity_Garden_CheckIfLedianQuestComplete
	end

VirtualCity_Garden_OldWomanImYoung::
	msgbox VirtualCity_Garden_Text_OldWoman_ImYoung, MSGBOX_NPC
	end

VirtualCity_Garden_DepressedMan::
	goto_if_quest_not_active QUEST_LEDIAN, VirtualCity_Garden_DepressedManBeaches
	goto_if_set FLAG_LEDIAN_SPOKE_TO_MAN, VirtualCity_Garden_DepressedManBeaches
	lock
	player_speak VirtualCity_Garden_Text_Sophie_WhatDoYouThink
	npc_speak NULL, VirtualCity_Garden_Text_Man_IGuessLedian
	closemessage
	setflag FLAG_LEDIAN_SPOKE_TO_MAN
	goto VirtualCity_Garden_CheckIfLedianQuestComplete
	end

VirtualCity_Garden_DepressedManBeaches::
	msgbox VirtualCity_Garden_Text_Man_WhenBeachesBack, MSGBOX_NPC
	end

VirtualCity_Garden_JesusChrist::
	goto_if_quest_not_active QUEST_LEDIAN, VirtualCity_Garden_JesusChristIAmHe
	goto_if_set FLAG_LEDIAN_SPOKE_TO_JESUS, VirtualCity_Garden_JesusChristIAmHe
	lock
	faceplayer
	npc_speak NULL, VirtualCity_Garden_Text_JesusChrist_Ledian
	playse SE_SELECT
	player_speak VirtualCity_Garden_Text_Sophie_IHadntAsked
	playse SE_SELECT
	npc_speak NULL, VirtualCity_Garden_Text_JesusChrist_Overheard
	closemessage
	setflag FLAG_LEDIAN_SPOKE_TO_JESUS
	goto VirtualCity_Garden_CheckIfLedianQuestComplete
	end

VirtualCity_Garden_JesusChristIAmHe::
	msgbox VirtualCity_Garden_Text_JesusChrist_IAmHe, MSGBOX_NPC
	end

VirtualCity_Garden_CheckIfLedianQuestComplete::
	addvar VAR_LEDIAN_QUEST, 1
	goto_if_ne VAR_LEDIAN_QUEST, 5, VirtualCity_Garden_EndLedianQuestCheck
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	setspeaker Speaker_Player
	msgbox VirtualCity_Garden_Text_Sophie_WellThatsEveryone, MSGBOX_DEFAULT
	closemessage
	questmenu QUEST_MENU_SET_REWARD, QUEST_LEDIAN
	release
	end

VirtualCity_Garden_EndLedianQuestCheck::
	release
	end

VirtualCity_Garden_Sign::
	msgbox VirtualCity_Garden_Text_Sign, MSGBOX_SIGN
	end

VirtualCity_Garden_Text_Sign::
	.string "Current Nature Refuge:\n"
	.string "Autumn Forest\p"
	.string "Previous Nature Refuge:\n"
	.string "Tide Pools\p"
	.string "Next Nature Refuge:\n"
	.string "Asteroids\p"
	.string "Buy your favorites for 59999.95\n"
	.string "at the {COLOR GREEN}BETTER{COLOR DARK_GRAY} SUPERSTORE!$"

Speaker_LedianLover:
	.string "Ledian Lover$"

VirtualCity_Garden_Text_LedianLover_ThisIsAnOutrage:
	.string "RAAAAAAAH!\p"
	.string "This is an OUTRAGE!$"

VirtualCity_Garden_Text_Sophie_WhatsUp:
	.string "Uhh, what's up?$"

VirtualCity_Garden_Text_LedianLover_NoRelease:
	.string "What's up? I'll tell you\n"
	.string "what's up!\p"
	.string "Ledian's being done dirty by\n"
	.string "those dingbats at {COLOR GREEN}BETTER{COLOR DARK_GRAY}!\p"
	.string "My poor baby hasn't gotten a\n"
	.string "new release in years…\l"
	.string "It makes me wants to puke!\p"
	.string "I swear, nobody who actually\n"
	.string "works on Pokémon listens to what\l"
	.string "the people want!$"

VirtualCity_Garden_Text_Sophie_UmmImACreator:
	.string "Umm…\n"
	.string "So, if you want, I work at-$"

VirtualCity_Garden_Text_LedianLover_HugePower:
	.string "Its beautiful eyes, that\n"
	.string "glimmering red bod…\p"
	.string "It deserves to be top of the meta!\p"
	.string "What if it got something like HUGE\n"
	.string "POWER as its ability?\p"
	.string "OOOH! Or what if it repeats every\n"
	.string "punching move it does four times!\p"
	.string "…{PAUSE 60}Oh, you're still here?\p"
	.string "You wanna spread the word on\n"
	.string "this injustice?\p"
	.string "I bet a whole bunch of others\n"
	.string "wanna see Ledian come back too!\p"
	.string "Why don't you ask around?\p"
	.string "We can start with the people\n"
	.string "here at the refuge!\p"
	.string "Do this for me and I'll give you\n"
	.string "one from my collection!$"

VirtualCity_Garden_Text_Sophie_SureThingBuddy:
	.string "Sure thing, buddy…\n"
	.string "I'll see what I can do.$"

VirtualCity_Garden_Text_LedianLover_Cmon:
	.string "C'mon, lady!\n"
	.string "Chop chop!\p"
	.string "Don't be shy, just spread the\n"
	.string "good word about Ledian!$"

VirtualCity_Garden_Text_LedianLover_WhatDoPeopleSay:
	.string "Well? What did everyone say?\p"
	.string "I bet the masses are clamoring for\n"
	.string "the return of the Five Star Mon!$"

VirtualCity_Garden_Text_Sophie_PeopleDontCare:
	.string "The people have spoken.\n"
	.string "They don't care about the lil' bug.$"

VirtualCity_Garden_Text_LedianLover_ButLedian:
	.string "But… Those gnarly arms…\p"
	.string "Its cute demeanor…$"

VirtualCity_Garden_Text_Sophie_ThemsTheChops:
	.string "Sorry dude, them's the chops.\p"
	.string "Public opinion ain't on your side!$"

VirtualCity_Garden_Text_LedianLover_Reward:
	.string "Mmm…\p"
	.string "I guess a promise is a promise…\p"
	.string "Here… I hope you appreciate\n"
	.string "Ledian more than those plebians…$"

VirtualCity_Garden_Text_YouReceivedLedian:
	.string "You were gifted a Ledian!$"

VirtualCity_Garden_LedianLoverDejected:
	.string "There's still always hope,\n"
	.string "right?\p"
	.string "… {PAUSE 50}… {PAUSE 50}… {PAUSE 50}{FONT_SMALL}Right?$"

VirtualCity_Garden_Text_Togepi_ImBaby:
	.string "im baby$"

VirtualCity_Garden_Text_Togepi_LediansNotBaby:
	.string "ledians not baby$"

VirtualCity_Garden_Text_Togepi_LediansNotBaby2:
	.string "ledians\p"
	.string "not\p"
	.string "baby$"

Speaker_Baby:
	.string "baby$"

VirtualCity_Garden_Text_Plump_YouCanBeAnyone:
	.string "In the Better Place, you can be\n"
	.string "ANYONE you WANT!\p"
	.string "What YOU THINK about my CUSTOM FIT?$"
	
VirtualCity_Garden_Text_Sophie_Freaky:
	.string "I didn't know they made skins so…\p"
	.string "Weird? {PAUSE 20}Cringe?\p"
	.string "Lacking any taste?$"

VirtualCity_Garden_Text_Plump_EveryonesACritic:
	.string "WOW, the FAT GUY just CAN'T CATCH\n"
	.string "A BREAK, HUH!\p"
	.string "GET OUT of MY SIGHT!$"

VirtualCity_Garden_Text_Plump_LedianStinks:
	.string "LEDIAN!?!?\p"
	.string "THAT POKéMON {COLOR GREEN}STINKS!\p"
	.string "{COLOR DARK_GRAY}GET OUTTA MY FACE WITH THAT GARBAGE!\p"
	.string "LET'S GET ANOTHER FLYGON WOOOOOO!$"

VirtualCity_Garden_Text_OldWoman_WhyLedian:
	.string "Ledian?\n"
	.string "That mon isn't very viable…\p"
	.string "What makes you so interested\n"
	.string "in seeing it again?$"

VirtualCity_Garden_Text_OldWoman_CutiePie:
	.string "A cutie pie…?\p"
	.string "Ehh? To each their own…\p"
	.string "It's too reminiscent of a stinkbug\n"
	.string "for me.\p"
	.string "When are we getting the next Drampa?$"

VirtualCity_Garden_Text_OldWoman_SpecialBulk:
	.string "Special bulk…?\p"
	.string "Sure, I GUESS 110 base SpDef isn't\n"
	.string "that bad.\p"
	.string "{FONT_SMALL}For a bug…$"

VirtualCity_Garden_Text_OldWoman_PunchesTickle:
	.string "It's punches tickle!?!?\p"
	.string "Well, I GUESS you could get a good\n"
	.string "massage from such a weak punch…?\p"
	.string "{FONT_SMALL}Weirdo…$"

VirtualCity_Garden_Text_OldWoman_ImYoung:
	.string "Everyone treats you so differently\n"
	.string "here depending on your skin!\p"
	.string "IRL, I'm only 25 years old!$"

VirtualCity_Garden_Text_Man_IGuessLedian:
	.string "…Huh?\p"
	.string "I dunno… I guess it's kinda neat…\p"
	.string "A new Golisopod skin would be\n"
	.string "way cooler though…$"

VirtualCity_Garden_Text_Man_WhenBeachesBack:
	.string "Man…\p"
	.string "It'll be a whole year before\n"
	.string "they bring the beach back…\p"
	.string "You could really smell the salty\n"
	.string "air…$"

VirtualCity_Garden_Text_JesusChrist_Ledian:
	.string "I.\p"
	.string "DON'T!!\p"
	.string "CARE!!!\p"
	.string "ABOUT!!!!\p"
	.string "LEDIAN!!!!!$"

VirtualCity_Garden_Text_Sophie_IHadntAsked:
	.string "I haven't even asked anything!$"
	
VirtualCity_Garden_Text_JesusChrist_Overheard:
	.string "I.\p"
	.string "OVERHEARD!!!!!$"

VirtualCity_Garden_Text_JesusChrist_IAmHe:
	.string "I.\p"
	.string "AM!!!\p"
	.string "HE!!!!!$"

VirtualCity_Garden_Text_Sophie_WhatDoYouThink:
	.string "Hi! I'm doing a quick survey.\p"
	.string "Do you think Ledian should be\n"
	.string "brought back in a new release?$"

VirtualCity_Garden_Text_Sophie_WhatDoYouThinkShort:
	.string "Hi! I'm doing a quick survey.\p"
	.string "Do you think Ledian-$"

VirtualCity_Garden_Text_Sophie_Okayyyy:
	.string "Okaaaaayyy…$"

VirtualCity_Garden_Text_Sophie_IUhh:
	.string "I, uhhh… wasn'-$"

VirtualCity_Garden_Text_Sophie_Speechless:
	.string "…$"

VirtualCity_Garden_Text_Sophie_WellThatsEveryone:
	.string "Well, that's everyone in the\n"
	.string "nature refuge…$"
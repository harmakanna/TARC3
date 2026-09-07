VirtualCity_Casino_MapScripts::
	.byte 0


Speaker_Researcher:
	.string "Researcher$"

VirtualCity_Casino_Eventscript_Cluegiver1::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver1, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver2::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver2, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver3::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver3, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver4::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver4, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver5::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver5, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver6::
	setflag FLAG_ACT_I_INFO_OBTAINED
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver6, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_EventScript_Kumatora::
	msgbox VirtualCity_Casino_Text_Kumatora, MSGBOX_NPC

VirtualCity_Casino_EventScript_Boat::
	lock
	faceplayer
	msgbox VirtualCity_Casino_Text_Boat, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VirtualCity_Casino_EventScript_GuardIdols::
	msgbox VirtualCity_Casino_Text_GuardIdols, MSGBOX_NPC
	end

VirtualCity_Casino_EventScript_Honchkrow::
	msgbox VirtualCity_Casino_Text_Honchkrow, MSGBOX_NPC
	end

VirtualCity_Casino_EventScript_WaitressIdol::
	lock
	faceplayer
	npc_speak Speaker_Idol, VirtualCity_Casino_Text_WaitressIdol
	player_speak VirtualCity_Casino_Text_SophieStopTalkingClanker
	npc_speak Speaker_Idol, VirtualCity_Casino_Text_WaitressIdol2
	closemessage
	release
	end

VirtualCity_Casino_EventScript_Meowth1::
	lock
	faceplayer
	msgbox VirtualCity_Casino_Text_Meowth1, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VirtualCity_Casino_EventScript_Meowth2::
	lock
	msgbox VirtualCity_Casino_Text_Meowth2, MSGBOX_DEFAULT
	closemessage
	release
	end

VirtualCity_Casino_EventScript_Purrloin::
	lock
	faceplayer
	msgbox VirtualCity_Casino_Text_Purrloin, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VirtualCity_Casino_EventScript_Twin::
	lock
	faceplayer
	msgbox VirtualCity_Casino_Text_Twin, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VirtualCity_Casino_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox VirtualCity_Casino_Text_LittleBoy, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VirtualCity_Casino_EventScript_BlackjackIdol::
	msgbox VirtualCity_Casino_Text_BlackjackIdol, MSGBOX_NPC
	end

VirtualCity_Casino_EventScript_RouletteIdol::
	lock
	faceplayer
	npc_speak Speaker_Idol, VirtualCity_Casino_Text_RouletteIdol1
	player_speak VirtualCity_Casino_Text_SophieGetLost
	npc_speak Speaker_Idol, VirtualCity_Casino_Text_RouletteIdol2
	closemessage
	release
	end

VirtualCity_Casino_EventScript_Grumpig::
	msgbox VirtualCity_Casino_Text_Grumpig, MSGBOX_NPC
	end

VirtualCity_Casino_EventScript_QuintyPlump::
	msgbox VirtualCity_Casino_Text_QuintyPlump, MSGBOX_NPC
	end

VirtualCity_Casino_EventScript_SuaveMan::
	msgbox VirtualCity_Casino_Text_SuaveMan, MSGBOX_NPC
	end

VirtualCity_Casino_Text_SuaveMan:
	.string "Ohohohon… {COLOR GREEN}BETTER{COLOR DARK_GRAY} knowz how too\n"
	.string "treet itz honorred guestz…$"
	.string "What zey don't tell you eez zat\n"
	.string "ze more membership duez you pay,\l"
	.string "ze better your oddz get!\p"
	.string "Madamoiselle, I started weening az\n"
	.string "SOON az my contribyutions hit\l"
	.string "88888888888888.99 a monsth!$"
	.string "EET EEZ NEVER TOO LATE TOO BEE A\n"
	.string "BEEG SHOT!$"
	
VirtualCity_Casino_Text_QuintyPlump:
	.string "I bet on red, it lands on black.\p"
	.string "I bet on black, it lands on red!\p"
	.string "I bet on both at the same time, and\n"
	.string "the dang ball lands on DOUBLE ZERO!\p"
	.string "Am I UNLUCKY or WHAT!?$"

VirtualCity_Casino_Text_Grumpig:
	.string "You know, is it kinda weird that those\n"
	.string "forty-something mid-career salarymen are\l"
	.string "playing the slots with those skins?\p"
	.string "I know they're not ACTUALLY kids, but\n"
	.string "something about it feels… wrong?$"

VirtualCity_Casino_Text_RouletteIdol1:
	.string "Yippeee!!! Another player!!!\p"
	.string "Will you bet on red or black?$"

VirtualCity_Casino_Text_SophieGetLost:
	.string "Get lost!$"

VirtualCity_Casino_Text_RouletteIdol2:
	.string "Aww, that makes me sad………\p"
	.string "Okay…………\p"
	.string "Remember, it's never too late to be\n"
	.string "a BIG SHOT!$"

VirtualCity_Casino_Text_BlackjackIdol:
	.string "Test your luck today at our premium\n"
	.string "high-stakes playing cards table!\p"
	.string "Hold'em, Poker, Blackjack, you name\n"
	.string "it, we'll play it!\p"
	.string "Let me deal you a hand! Yay!$"

VirtualCity_Casino_Text_Twin:
	.string "Work has been getting more stressful\n"
	.string "lately…\p"
	.string "The boss expects too much from me…\p"
	.string "Gotta put in overtime to keep up…\p"
	.string "Nothing to do but hit the sticks and\n"
	.string "unwind with a can of lager after a\l"
	.string "hard day…$"

VirtualCity_Casino_Text_LittleBoy:
	.string "my WIFE left me\p"
	.string "MY wife LEFT me\p"
	.string "my wife LEFT ME\p"
	.string "TIME TO HIT THE STICKS!!!!!!$"

VirtualCity_Casino_Text_Purrloin:
	.string "HA! Those idiot MEOWTH men thought\n"
	.string "buying a lucky cat skin would be enough\l"
	.string "to start winning at the slots!\p"
	.string "The idol told ME I'm so smart for seeing\n"
	.string "through that myth and buying a PURRLOIN\l"
	.string "skin instead!\p"
	.string "My winnings'll start pouring in any second\n"
	.string "now!$"

VirtualCity_Casino_Text_Meowth1:
	.string "One of the idols told me buying\n"
	.string "a MEOWTH skin would improve my odds\l"
	.string "at the slots…\p"
	.string "But I just keep losing…\n"
	.string "I gotta try harder!$"

VirtualCity_Casino_Text_Meowth2:
	.string "Come on… Lady luck is on my\n"
	.string "side tonight…!$"

Speaker_Idol:
	.string "Idol$"

VirtualCity_Casino_Text_WaitressIdol:
	.string "Omg, hiiiii {PLAYER}!!!\p"
	.string "Today's the best day to subscribe to\n"
	.string "the parlor's membership!\p"
	.string "Just ask the front desk and she'll\n"
	.string "hook you up in no time flat!!$"

VirtualCity_Casino_Text_SophieStopTalkingClanker:
	.string "Stop talkin' to me, you stupid bot!$"

VirtualCity_Casino_Text_WaitressIdol2:
	.string "Ooooo, you're playin' {COLOR RED}hard-to-get!!!\p"
	.string "{COLOR DARK_GRAY}Remember, it's never too\n"
	.string "late to start your journey with {COLOR GREEN}BETTER{COLOR DARK_GRAY}\n"
	.string "casino!!!\p"
	.string "Just say the word!$"

VirtualCity_Casino_Text_Honchkrow:
	.string "I'm da big BOOOOSSS around\n"
	.string "here!\p"
	.string "If ya wanna do any BIDNESS wit' any o'\n"
	.string "my girls, ya gotta go through ME!\p"
	.string "{FONT_SMALL}(Heehee, I always wanted to be\n"
	.string "a big honkin' mafioso at a casino…!)$"

VirtualCity_Casino_Text_GuardIdols:
	.string "Teehee! Sorry! Only casino members\n"
	.string "get access to the VIP room!\p"
	.string "Buy a membership now for only:\n"
	.string "{PAUSE 30}6{PAUSE 25}7{PAUSE 20}5{PAUSE 20}5{PAUSE 15}9{PAUSE 7}999999.99!$"

VirtualCity_Casino_Text_Boat:
	.string "I'm having a BOATLOAD of FUN on the\n"
	.string "slot machines today!$"

VirtualCity_Casino_Text_Kumatora:
	.string "Sorry, you gotta be a member if\n"
	.string "you want coins for the machines!\p"
	.string "…Why're you lookin' at me like that?\p"
	.string "I got this skin as an early-adopter\n"
	.string "perk.$"
	
VirtualCity_Casino_Text_Cluegiver1:
	.string "…wish I could tell my daughter.\p"
	.string "It's been her favorite since she\n"
	.string "was a little girl!$"

VirtualCity_Casino_Text_Cluegiver2:
	.string "…the absolute worst type to make.\n"
	.string "The lighting effects alone!$"

VirtualCity_Casino_Text_Cluegiver3:
	.string "…most popular ones first, and that\n"
	.string "means old-school nostalgia.$"

VirtualCity_Casino_Text_Cluegiver4:
	.string "…no, no, everything's on schedule.\n"
	.string "It's just the hind legs left!$"

VirtualCity_Casino_Text_Cluegiver5:
	.string "…yeah, but be careful getting on its\n"
	.string "back - it's more suited to kids.$"

VirtualCity_Casino_Text_Cluegiver6:
	.string "…might even get banned from serious\n"
	.string "competitive play.$"


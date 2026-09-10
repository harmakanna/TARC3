VirtualCity_Superstore_2F_MapScripts::
	.byte 0

VirtualCity_Superstore_2F_EventScript_Cycler::
	msgbox VirtualCity_Superstore_2F_Text_Cycler, MSGBOX_NPC
	end

VirtualCity_Superstore_2F_EventScript_Misdreavus::
	lock
	faceplayer
	msgbox VirtualCity_Superstore_2F_Text_Misdreavus, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VirtualCity_Superstore_2F_EventScript_PinkIdol::
	msgbox VirtualCity_Superstore_2F_Text_PinkIdol, MSGBOX_NPC
	end

VirtualCity_Superstore_2F_EventScript_BlueIdol::
	msgbox VirtualCity_Superstore_2F_Text_BlueIdol, MSGBOX_NPC
	end

VirtualCity_Superstore_2F_EventScript_YellowIdol::
	msgbox VirtualCity_Superstore_2F_Text_YellowIdol, MSGBOX_NPC
	end

VirtualCity_Superstore_2F_EventScript_Sign::
	msgbox VirtualCity_Superstore_2F_Text_Sign, MSGBOX_SIGN
	end

VirtualCity_Superstore_2F_Text_Sign:
	.string "The {COLOR GREEN}BETTER {COLOR DARK_GRAY}\n"
	.string "Superstore 2F\p"
	.string "Last week's REFUGE, 'Tide Pools',\n"
	.string "NOW ON SALE!!!$"

VirtualCity_Superstore_2F_Text_Cycler:
	.string "I CAN'T WAIT!\p"
	.string "They're finally selling the rare\n"
	.string "ASTEROIDS Refuge soon!\p"
	.string "I've been saving up for MONTHS!$"

VirtualCity_Superstore_2F_Text_Misdreavus:
	.string "The cosmetics here are out of\n"
	.string "this world!\p"
	.string "If you buy makeup, you don't even\n"
	.string "need to apply it, they just go straight\l"
	.string "on your face!\p"
	.string "I want the blush in pink, blue, red,\n"
	.string "silver, chartreuse, plum…$"

VirtualCity_Superstore_2F_Text_PinkIdol:
	.string "Welcome to the second floor\n"
	.string "of {COLOR GREEN}BETTER's{COLOR DARK_GRAY} SUPER STORE!\p"
	.string "This is the Room Enhancement Counter!\p"
	.string "Oh my gosh, you came to the right place!\p"
	.string "A little birdie tells me that you've\n"
	.string "got the Waterfall Basic Plus room!\p"
	.string "And not{PAUSE 20} even{PAUSE 20} one{PAUSE 20} single{PAUSE 20} chair or sofa!\p"
	.string "Let's change that, the {COLOR GREEN}BETTER{COLOR DARK_GRAY} way!$"

VirtualCity_Superstore_2F_Text_BlueIdol:
	.string "Heeeyyyyy!\p"
	.string "We're having a limited-edition sale\n"
	.string "on {PAUSE 50}{COLOR GREEN}JUNGLE CLOTHING AND ACCESSORIES\l"
	.string "{PAUSE 50}{COLOR DARK_GRAY}for your avatar!\p"
	.string "You DON'T wanna miss out on this!$"


VirtualCity_Superstore_2F_Text_YellowIdol:
	.string "Hey girlfriend!\p"
	.string "Ooooh! My autoscanner tells me you're\n"
	.string "trying to catch someone's eye!\p"
	.string "What you need is a beautiful new skin,\n"
	.string "much better than your old collectible!\p"
	.string "POKéMON, Brands, Objects... and some\n"
	.string "real hotties that'll help you get the\l"
	.string "person of your dreams!$"



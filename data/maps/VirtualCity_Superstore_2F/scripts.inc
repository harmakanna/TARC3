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

VirtualCity_Superstore_2F_Text_Cycler:
	.string "So many cool skins and rooms, yet\n"
	.string "so, so little to spend…$"

VirtualCity_Superstore_2F_Text_Misdreavus:
	.string "The cosmetics here are out of\n"
	.string "this world!\p"
	.string "If you buy makeup, you don't even\n"
	.string "need to apply it, they just go straight\l"
	.string "on your face!\p"
	.string "I want the blush in pink, blue, red,\n"
	.string "silver, chartreuse, plum…$"



VirtualCity_Superstore_2F_EventScript_TopIdol::
	msgbox VirtualCity_Superstore_2F_Text_TopIdol, MSGBOX_NPC
	end

VirtualCity_Superstore_2F_Text_TopIdol:
	.string "Hiiiiiiiiii!\n"
	.string "This is the Room Enhancement Counter!\p"
	.string "Oh my gosh, you came to the right place!\p"
	.string "A little birdie tells me that you've\n"
	.string "got the Waterfall Basic Plus room!\p"
	.string "And not{PAUSE 20} even{PAUSE 20} one{PAUSE 20} single{PAUSE 20} chair or sofa!\p"
	.string "Let's change that, the {COLOR GREEN}BETTER{COLOR DARK_GRAY} way!$"



VirtualCity_Superstore_2F_EventScript_LeftIdol::
	msgbox VirtualCity_Superstore_2F_Text_LeftIdol, MSGBOX_NPC
	end

VirtualCity_Superstore_2F_Text_LeftIdol:
	.string "Hey girlfriend!\n"
	.string "You know the joy of buying a new skin?\p"
	.string "It feels so good to own something new,\n"
	.string "just for you, right?\p"
	.string "Now you can have that feeling over and\n"
	.string "over, with Accessories!\p"
	.string "Wait, your skin - it's from before the\n"
	.string "accessory update! Oh no!\p"
	.string "Go visit my girl over there, buy a skin,\n"
	.string "and then I'll show you the accessories!\p"
	.string "Don't keep me waiting, cutie!$"

VirtualCity_Superstore_2F_EventScript_RightIdol::
	msgbox VirtualCity_Superstore_2F_Text_RightIdol, MSGBOX_NPC
	end

VirtualCity_Superstore_2F_Text_RightIdol:
	.string "Heyyy!\n"
	.string "Ooooh! My autoscanner tells me you're\n"
	.string "trying to catch someone's eye!\p"
	.string "What you need is a beautiful new skin,\n"
	.string "much better than your old collectible!\p"
	.string "Pokemon, Brands, Objects... and some\n"
	.string "real hotties that'll help you get the\l"
	.string "person of your dreams!$"

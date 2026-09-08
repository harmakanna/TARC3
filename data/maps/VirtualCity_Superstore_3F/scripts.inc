VirtualCity_Superstore_3F_MapScripts::
	.byte 0

VirtualCity_Superstore_3F_EventScript_Flabebe::
	lock
	faceplayer
	msgbox VirtualCity_Superstore_3F_Text_Flabebe, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VirtualCity_Superstore_3F_EventScript_Skitty::
	lock
	msgbox VirtualCity_Superstore_3F_Text_Skitty, MSGBOX_DEFAULT
	closemessage
	release
	end

VirtualCity_Superstore_3F_EventScript_ExasperatedMan::
	msgbox VirtualCity_Superstore_3F_EventScript_ExasperatedMan, MSGBOX_NPC
	end

VirtualCity_Superstore_3F_EventScript_SweetTooth::
	msgbox VirtualCity_Superstore_3F_Text_SweetTooth, MSGBOX_NPC
	end

VirtualCity_Superstore_3F_EventScript_ThatWoman::
	msgbox VirtualCity_Superstore_3F_Text_ThatWoman, MSGBOX_NPC
	end

VirtualCity_Superstore_3F_Text_ThatWoman:
	.string "Do you know who that strange girl\n"
	.string "over there is?\p"
	.string "She walked up to me asking if she\n"
	.string "could have something 'SWEET to EAT',\l"
	.string "so I said why not.\p"
	.string "Now she's calling me her mom…$"

VirtualCity_Superstore_3F_Text_SweetTooth:
	.string "im looking for something SWEET\n"
	.string "to EAT\p"
	.string "my mom said I can have one\n"
	.string "yayy$"

VirtualCity_Superstore_3F_Text_Flabebe:
	.string "I NEED the new LIMITED EDITION\n"
	.string "GUSTY GARDEN FLABUBU!\p"
	.string "WHY CAN'T THESE THREE HOURS GO BY\n"
	.string "FASTER ALREADY!?!?!?$"

VirtualCity_Superstore_3F_Text_Skitty:
	.string "FLABUBUUUUU!!!!$"

VirtualCity_Superstore_3F_Text_ExasperatedMan:
	.string "I'm only here for my medication…\p"
	.string "Why did they put the essentials\n"
	.string "on the top floor…$"
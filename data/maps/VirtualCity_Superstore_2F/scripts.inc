VirtualCity_Superstore_2F_MapScripts::
	.byte 0

VirtualCity_Superstore_2F_EventScript_Cycler::
	msgbox VirtualCity_Superstore_2F_Text_Cycler, MSGBOX_NPC
	end

VirtualCity_Superstore_2F_EventScript_Misdreavus::
	lock
	face_player
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
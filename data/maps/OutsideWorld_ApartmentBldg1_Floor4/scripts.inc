OutsideWorld_ApartmentBldg1_Floor4_MapScripts::
	.byte 0

AptBldg_Floor4_Girl::
	msgbox AptBldg_Floor4_Text_Girl, MSGBOX_NPC
	end

AptBldg_Floor4_Woman::
	msgbox AptBldg_Floor4_Text_Woman, MSGBOX_NPC
	end

AptBldg_Floor4_Text_Girl:
	.string "Hey, do you have that one video\n"
	.string "of POKéMON playing in the meadows?\p"
	.string "It's missing from the catalogue…$"

AptBldg_Floor4_Text_Woman:
	.string "Don't tell my daughter I overwrote\n"
	.string "her favorite video…\p"
	.string "I thought it was blank…$"
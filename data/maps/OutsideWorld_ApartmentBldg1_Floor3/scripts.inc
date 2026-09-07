OutsideWorld_ApartmentBldg1_Floor3_MapScripts::
	.byte 0

AptBldg_Floor3_OldWoman::
	lock
	msgbox AptBldg_Floor3_Text_OldWoman1, MSGBOX_DEFAULT
	player_speak AptBldg_Floor3_Text_SophieToOldWoman
	npc_speak NULL, AptBldg_Floor3_Text_OldWoman2
	closemessage
	release
	end

AptBldg_Floor3_Text_OldWoman1:
	.string "Oooo where did my good\n"
	.string "friend SILICOBRA slither off\l"
	.string "to?\p"
	.string "She must be here somewhere!$"

AptBldg_Floor3_Text_SophieToOldWoman:
	.string "Grandma, SILICOBRA passed away\n"
	.string "well before I was born…$"

AptBldg_Floor3_Text_OldWoman2:
	.string "Hmm, no, no, that can't be\n"
	.string "right…\p"
	.string "She was just with me yesterday.\p"
	.string "Oh SILICOBRA, where are you?$"
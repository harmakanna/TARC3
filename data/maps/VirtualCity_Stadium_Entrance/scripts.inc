VirtualCity_Stadium_Entrance_MapScripts::
	.byte 0



VirtualCity_Stadium_Entrance_EventScript_Harriet::
	goto_if_set FLAG_ACT_II_HARRIET_EXPLANATION, VirtualCity_Stadium_Entrance_EventScript_Harriet_Rexplains










VirtualCity_Stadium_Entrance_EventScript_Harriet_Rexplains::
	speak LOCALID_DARKANINE, VirtualCity_Work_YourOffice_Text_SophieACTIOutro2, Speaker_Harriet, DIR_EAST















VirtualCity_Stadium_Entrance_Text_HarrietBattleXEarlGrey1:
	.string "Well, your next fight is against a guy\n"
	.string "who calls himself Earl Grey.\p"
	.string "You remember the Teatime pack? It came\p"
	.string "out a few years ago.$"

VirtualCity_Stadium_Entrance_Text_SophieBattleXEarlGrey2:
	.string "Riiiight, all those variations of\n"
	.string "Hospitality that I designed.$"

VirtualCity_Stadium_Entrance_Text_HarrietBattleXEarlGrey3:
	.string "Oh, you designed it? Well, his team's\n"
	.string "nothing but the Teatime set.\p"
	.string "It's kinda silly and gimmicky, but he's\n"
	.string "done really well with it.\p"
	.string "Good luck!$"



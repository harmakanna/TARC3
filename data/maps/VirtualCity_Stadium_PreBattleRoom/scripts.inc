VirtualCity_Stadium_PreBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Stadium_PreBattleRoom_OnFrame
	.byte 0

VirtualCity_Stadium_PreBattleRoom_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 22, VirtualCity_Stadium_PreBattleRoom_Eventscript_IntroScene
	map_script_2 VAR_PETALBURG_CITY_STATE, 32, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB1Scene
	map_script_2 VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB2Scene
	map_script_2 VAR_PETALBURG_CITY_STATE, 34, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB3Scene
	map_script_2 VAR_PETALBURG_CITY_STATE, 35, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronHackSuccess
	.2byte 0

VirtualCity_Stadium_PreBattleRoom_Eventscript_IntroScene::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	playse SE_DOOR
	addobject LOCALID_HARRIET_PREBATTLE
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro0, Speaker_Harriet, DIR_NORTH
	closemessage
	delay 30

	applymovement LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Move_HarrietEnters
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement LOCALID_HARRIET_PREBATTLE
	applymovement OBJ_EVENT_ID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Move_SophieWalksUp
	waitmovement 0
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro1, Speaker_Harriet, DIR_SOUTH
	playse SE_SELECT
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	msgbox VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro1_2, MSGBOX_DEFAULT
	playse SE_SELECT
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceUp
	msgbox VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro1_2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceDown
	delay 30
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Eventscript_SophieIntro2, SP_NAME_PLAYER, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro3, Speaker_Harriet, DIR_SOUTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Eventscript_SophieIntro4, SP_NAME_PLAYER, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro5, Speaker_Harriet, DIR_SOUTH
	@speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro6, Speaker_Harriet, DIR_SOUTH
	closemessage
	call EventScript_AddRandomMod
	setflag FLAG_ACT_II_MOD_INSTALLED
	clearflag FLAG_ACT_II_HIDE_HARRIET_PREBATTLE
	setvar VAR_PETALBURG_CITY_STATE, 23
	end

VirtualCity_Stadium_PreBattleRoom_Move_HarrietEnters:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

VirtualCity_Stadium_PreBattleRoom_Move_SophieWalksUp:
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro0:
	.string "Nice, we have the place to ourselves!$"

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro1:
	.string "So, I signed myself up as your coach\n"
	.string "to scope out your opponents.\p"
	.string "I know you like modding your Pokemon.\p"
	.string "You'll probably only have time for\n"
	.string "one mod after each battle, though.$"
VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro1_2:
	.string "If you gotta remove mods for better\n"
	.string "ones, you can do it at that PC there.$"
VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro1_3:
	.string "And behind me is the door to the arena.$"

VirtualCity_Stadium_PreBattleRoom_Eventscript_SophieIntro2:
	.string "I'm not too worried.\n"
	.string "What do you know about my first fight?$"

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro3:
	.string "I know you'll crush it!\p"
	.string "(And if you don't,\nyou can just try again)\p"
	.string "(actuallyyoukeepyourrankevenifyou\n"
	.string "losesojusthavefunandhumiliateByron)$"

VirtualCity_Stadium_PreBattleRoom_Eventscript_SophieIntro4:
	.string "What?$"

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro5:
	.string "Nothing! Anyway, your first opponent…\p"
	.string "This guy doesn't have anything scary.\n"
	.string "Looks like he loves weak starters?\p"
	.string "Anyway, get to modding!$"

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro6:
	.string "Anyway, get to modding!$"





VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod::
	call EventScript_AddRandomMod
	setflag FLAG_ACT_II_MOD_INSTALLED
	return



VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietWellDone:
	.string "Well done!$"


VirtualCity_Stadium_PreBattleRoom_Eventscript_Harriet::
	
	goto_if_eq VAR_PETALBURG_CITY_STATE, 23, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando1
	goto_if_eq VAR_PETALBURG_CITY_STATE, 24, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando2
	goto_if_eq VAR_PETALBURG_CITY_STATE, 25, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando3
	goto_if_eq VAR_PETALBURG_CITY_STATE, 26, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando4
	goto_if_eq VAR_PETALBURG_CITY_STATE, 27, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando5

	goto_if_eq VAR_PETALBURG_CITY_STATE, 28, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXBroDude
	goto_if_eq VAR_PETALBURG_CITY_STATE, 29, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXWvddie
	goto_if_eq VAR_PETALBURG_CITY_STATE, 30, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXSilvaBullet
	goto_if_eq VAR_PETALBURG_CITY_STATE, 31, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXEarlGrey

	@goto_if_eq VAR_PETALBURG_CITY_STATE, 32, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB1
	@goto_if_eq VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB2
	@goto_if_eq VAR_PETALBURG_CITY_STATE, 34, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB3
	end

@@ SILVER
@@ TOFOLD add in rematches





VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando1::
	goto_if_set FLAG_ACT_II_FOUGHT_RANDO1, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando1Rematch
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando1, MSGBOX_NPC
	setflag FLAG_ACT_II_FOUGHT_RANDO1
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando1Rematch::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando1Rematch, MSGBOX_NPC
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end


VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando2::
	goto_if_set FLAG_ACT_II_FOUGHT_RANDO2, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando2Rematch
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando2, MSGBOX_NPC
	setflag FLAG_ACT_II_FOUGHT_RANDO2
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando2Rematch::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando2Rematch, MSGBOX_NPC
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end


VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando3::
	goto_if_set FLAG_ACT_II_FOUGHT_RANDO3, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando3Rematch
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando3, MSGBOX_NPC
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	setflag FLAG_ACT_II_FOUGHT_RANDO3
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando3Rematch::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando3Rematch, MSGBOX_NPC
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end


VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando4::
	goto_if_set FLAG_ACT_II_FOUGHT_RANDO4, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando4Rematch
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando4, MSGBOX_NPC
	setflag FLAG_ACT_II_FOUGHT_RANDO4
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando4Rematch::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando4Rematch, MSGBOX_NPC
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end


VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando5::
	goto_if_set FLAG_ACT_II_FOUGHT_RANDO5, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando5Rematch
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando5, MSGBOX_NPC
	setflag FLAG_ACT_II_FOUGHT_RANDO5
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando5Rematch::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando5Rematch, MSGBOX_NPC
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end




VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando1:
	.string "This guy doesn't have anything too\n"
	.string "scary. Looks like he loves starters?$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando1Rematch:
	.string "It's the guy with an all-starter team\n"
	.string "coming up. You got this.$"


VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando2:
	.string "Dear god, I hope this next one is a kid,\n"
	.string "and not a weirdo using a kid's avatar.\p"
	.string "Looks like a janky sun team?$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando2Rematch:
	.string "Oh no, it's the adult child with the sun\n"
	.string "team coming up next.$"


VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando3:
	.string "This next one's an old lady with a lot\n"
	.string "of cute Pokemon - not battle-ready.\p"
	.string "Why is she here?$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando3Rematch:
	.string "Next up is the old lady with her cute\n"
	.string "collection. Don't go easy on her!$"


VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando4:
	.string "This guy's got a lot of Fighting types.\p"
	.string "All three vanilla Hitmons - he doesn't\n"
	.string "have Hitmonbimba or Hitmonorris.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando4Rematch:
	.string "Coming up, the blackbelt.$"


VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando5:
	.string "Okay, she's got vanilla Pokemon, but you\n"
	.string "can tell she's serious.\p"
	.string "She's rocking a fire-water-grass core,\n"
	.string "and some decent synergy.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando5Rematch:
	.string "The ace trainer with the fire-water-grass\n"
	.string "core is next. She looks tough!$"



@@ GOLD



VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXBroDude::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXBroDude1, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXBroDude2, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXBroDude3, MSGBOX_NPC
	closemessage
	setflag FLAG_ACT_II_FOUGHT_BRODUDE
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXWvddie::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXWvddie1, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXWvddie2, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXWvddie3, MSGBOX_NPC
	closemessage
	setflag FLAG_ACT_II_FOUGHT_WVDDIE
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXSilvaBullet::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXSilvaBullet1, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXSilvaBullet2, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXSilvaBullet3, MSGBOX_NPC
	closemessage
	setflag FLAG_ACT_II_FOUGHT_SILVABULLET
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXEarlGrey::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXEarlGrey1, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXEarlGrey2, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXEarlGrey3, MSGBOX_NPC
	closemessage
	setflag FLAG_ACT_II_FOUGHT_EARLGREY
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end




VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXBroDude1:
	.string "Quick question, Sophie.\n"
	.string "How do you feel about sunglasses?$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXBroDude2:
	.string "…oh. Oh no.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXBroDude3:
	.string "Oh yeah. Looks like a standard CoolBro\p"
	.string "Dark spam team coming up.\n"
	.string "The guy's actual username is BroDude69.\n"
	.string "Hope you've got a resist!$"



VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXWvddie1:
	.string "Oh my god, I caught a glimpse of the\n"
	.string "lady you're about to fight just now.\p"
	.string "I don't even have to look her up -\n"
	.string "she's using Topsy Turvy mons.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXWvddie2:
	.string "Oh, the set that flipped their stats?\n"
	.string "Defenses swapped for offenses, etc?$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXWvddie3:
	.string "Don't forget that the HP and Speed are\n"
	.string "swapped, too. But yeah, that's the set.\p"
	.string "You'll understand how I knew when you\n"
	.string "see her!$"



VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXSilvaBullet1:
	.string "Remember how I said all the cheaters\n"
	.string "were ranked in Platinum?\p"
	.string "Turns out one of them is so bad at it\p"
	.string "that they're in Gold.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXSilvaBullet2:
	.string "Ah, an amazing team piloted poorly?\n"
	.string "Seen a lot of those recently.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXSilvaBullet3:
	.string "Not even a team, actually.\p"
	.string "One supposedly 'unkillable' hacked mon,\n"
	.string "and a bunch of weak filler.\p"
	.string "You got this.$"



VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXEarlGrey1:
	.string "Well, your next fight is against a guy\n"
	.string "who calls himself Earl Grey.\p"
	.string "You remember the Teatime pack? It came\p"
	.string "out a few years ago.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXEarlGrey2:
	.string "Riiiight, all those Pokemon with\n"
	.string "Hospitality. Fun to use.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXEarlGrey3:
	.string "Well, that's his whole team.\n"
	.string "Expect four awful 'tea' puns.\p"	
	.string "It's kinda silly and gimmicky, but I\n"
	.string "respect the committment, y'know?\p"
	.string "Especially because he made it to Gold.\p"
	.string "Good luck!$"




@@ BYRON

VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB1Scene::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron0, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron1, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle1XByron2, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle1XByron3, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron0, MSGBOX_NPC
	closemessage
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB2Scene::
	@This is if you beat Byron
	goto VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB2SceneLose

	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2WinXByron1, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron2, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron3, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron4, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron5, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron6, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2WinXByron7, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron8, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron9, MSGBOX_NPC	
	closemessage
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB2SceneLose::
	@if you lose
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2LoseXByron1, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron2, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron3, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron4, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron5, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron6, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2LoseXByron7, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron8, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron9, MSGBOX_NPC	
	closemessage
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end


VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB3Scene::
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle3XByron1, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron2, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle3XByron3, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron4, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle3XByron5, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron6, MSGBOX_NPC
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle3XByron7, MSGBOX_NPC
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end


VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronHackSuccess::
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieHackSuccess1, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestHackSuccess2, MSGBOX_NPC
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietHackSuccess3, MSGBOX_NPC
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestHackSuccess4, MSGBOX_NPC
	clearflag FLAG_ACT_II_HIDE_HOTEL_FRIENDS
	warpsilent MAP_VIRTUAL_CITY_HOTEL_YOUR_ROOM, 12,9
	waitstate
	end



VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron0:
	.string "Next. It's him. It's Byron.\p"
	.string "This is the guy we came here to fight,\n"
	.string "and boy does he have a nasty team.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron1:
	.string "Legendaries, boosted stats, absurd\n"
	.string "and illegal abilities and movesets.\p"
	.string "And he's got a shadowy Pokemon I\n"
	.string "couldn't even identify.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle1XByron2:
	.string "I've boosted up my Pokemon, but I don't\n"
	.string "know if it'll be enough.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle1XByron3:
	.string "It doesn't have to be enough.\n"
	.string "You don't have to win.\p"
	.string "All I have to do is figure out how his\n"
	.string "Pokemon were hacked, and I might be able\l"
	.string "to find and exploit a backdoor.\p"
	.string "I just know it's a hack job.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron4:
	.string "But wouldn't it be something to wipe that\n"
	.string "smirk off his face?\p"	
	.string "You're smarter and a better battler - I\n"
	.string "think you have a chance.\p"
	.string "And don't forget - this is a best of\n"
	.string "three. You can afford one loss.\p"
	.string "Good luck!$"





VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2WinXByron1:
	.string "Wow, you really did it!\n"
	.string "I can hardly believe it!$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron2:
	.string "Phew, I can't believe it either.\p"
	.string "Ernest, any progress?$"

@KUMATORA (I used my limited cybersecurity vocabulary to make something up here - if you have suggestions, it's all you)

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron3:
	.string "I.\p"
	.string "Cannot.\p"
	.string "Believe.\p"
	.string "How dumb. He is.\p"
	.string "There's no encryption - I just gotta\n"
	.string "get into the system somehow. But how?\p"
	.string "…\p"
	.string "I got it.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron4:
	.string "You have to throw this next match.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron5:
	.string "What? Lose, to him, on purpose?\n"
	.string "Why?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron6:
	.string "It'll take me a while to make something\n"
	.string "that can actually get his credentials.\p"
	.string "If you lose, it'll go to a best of three,\n"
	.string "and I'll have it ready by next battle.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2WinXByron7:
	.string "What are you going to-$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron8:
	.string "No time. I have to focus.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron9:
	.string "Well, time to lose to a moron.\n"
	.string "The things I do for you, Ernest.$"




VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2LoseXByron1:
	.string "Wow, I heard he was a cheater, but…\n"
	.string "He's a scumbag. How are you gonna win?$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron2:
	.string "It's okay, I know what to expect now.\p"
	.string "Ernest, any progress?$"

@KUMATORA (I used my limited cybersecurity vocabulary to make something up here - if you have suggestions, it's all you)

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron3:
	.string "I.\p"
	.string "Cannot.\p"
	.string "Believe.\p"
	.string "How dumb. He is.\p"
	.string "There's no encryption - I just gotta\n"
	.string "get into the system somehow. But how?\p"
	.string "…\p"
	.string "I got it.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron4:
	.string "You have to win this next match.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron5:
	.string "I mean, I'll try.\n"
	.string "Why?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron6:
	.string "It'll take me a while to make something\n"
	.string "that can actually get his credentials.\p"
	.string "If you win, it'll go to a best of three,\n"
	.string "and I'll have it ready by next battle.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2LoseXByron7:
	.string "What are you going to-$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron8:
	.string "No time. I have to focus.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron9:
	.string "Okay, gotta win this.\n"
	.string "No pressure.$"







VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle3XByron1:
	.string "Ernest?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron2:
	.string "It's done. Here.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle3XByron3:
	.string "Huh? A disc?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron4:
	.string "It's called a TM. Trainers used to use\n"
	.string "them to teach Pokemon moves.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle3XByron5:
	.string "Discs taught Pokemon moves?\n"
	.string "Were… Were Pokemon always just code?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron6:
	.string "No, it was just a way…\p"
	.string "Um, anyway, I can use it to teach one\n"
	.string "of your Pokemon a move I just made.\p"
	.string "It's got the viral load in it, so when\n"
	.string "it hits one of his hacked Pokemon,\l"
	.string "I'll be able to get access.\p"
	.string "The move's high priority and accurate,\n"
	.string "so it shouldn't be hard to hit.\p"
	.string "After that, doesn't matter if you win\n"
	.string "or lose - I'll be in.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle3XByron7:
	.string "I just gotta hit him, huh?\p"
	.string "I can do that.$"




VirtualCity_Stadium_PreBattleRoom_Text_SophieHackSuccess1:
	.string "It's done.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestHackSuccess2:
	.string "I see it. What an amateur.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietHackSuccess3:
	.string "Well done! Now, what next?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestHackSuccess4:
	.string "I need to disguise your identity, and\n"
	.string "tie it to these credentials.\p"
	.string "Let's get out of here for now.$"





@ Ernest

VirtualCity_Stadium_PreBattleRoom_Eventscript_Ernest::
	goto_if_eq VAR_PETALBURG_CITY_STATE, 35, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestLetsGo
	goto_if_eq VAR_PETALBURG_CITY_STATE, 34, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestTutor
	goto_if_eq VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestWork
	goto_if_eq VAR_PETALBURG_CITY_STATE, 32, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestWait
	end


VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestWait::
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestWait, MSGBOX_NPC
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestWork::
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestWait, MSGBOX_NPC
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestLetsGo::
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestLetsGo, MSGBOX_NPC
	end



VirtualCity_Stadium_PreBattleRoom_Text_ErnestWork:
	.string "Don't bug me, I'm working.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestWait:
	.string "Keep going. I can't help until I see\n"
	.string "the team he's got.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestLetsGo:
	.string "It worked. Time to go test it.$"



VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestTutor::
	lock
	faceplayer
	move_tutor MOVE_OCTAZOOKA, VirtualCity_Stadium_PreBattleRoom_Text_ErnestTeach, VirtualCity_Stadium_PreBattleRoom_Text_ErnestWhich, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestDeclined, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestTaught, FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	clearflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestDeclined::
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestDeclined, MSGBOX_DEFAULT
	release
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestTaught::
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestTaught, MSGBOX_DEFAULT
	setflag FLAG_ACT_II_MOVE_TAUGHT
	release
	end

VirtualCity_Stadium_PreBattleRoom_Text_ErnestTeach:
	.string "Are you ready?$"


VirtualCity_Stadium_PreBattleRoom_Text_ErnestWhich:
	.string "Who learns it? I can teach multiple\n"
	.string "if you want.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestDeclined:
	.string "Don't take too long!$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestTaught:
	.string "Okay, it's done. I can teach it\n"
	.string "again if you want.$"


VirtualCity_Stadium_PreBattleRoom_EventScript_PC::
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_PC, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, VirtualCity_Stadium_PreBattleRoom_EventScript_PCRemoveMods
	closemessage
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_PCRemoveMods::
	special ChoosePartyMon
	callnative RemoveModsFromSelectedMon
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_RemovalComplete, MSGBOX_DEFAULT
	closemessage
	end

VirtualCity_Stadium_PreBattleRoom_Text_PC:
	.string "Remove a Pokemon's mods?$"

VirtualCity_Stadium_PreBattleRoom_Text_RemovalComplete:
	.string "Removal complete.$"

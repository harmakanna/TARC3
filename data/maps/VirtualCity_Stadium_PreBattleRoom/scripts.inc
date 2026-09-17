@ VAR_WHICH_LEAGUE tracks which league the player is currently playing in.
@ 0 - Not fighting in a league.
@ 1 - Silver League
@ 2 - Gold League 
@ 3 - Platinum League 
@ 4 - The fights with Byron
@ 5 - Post-game league (if we do that)

VirtualCity_Stadium_PreBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VirtualCity_Stadium_PreBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VirtualCity_Stadium_PreBattleRoom_OnFrame
	.byte 0

VirtualCity_Stadium_PreBattleRoom_OnTransition::
	call_if_eq VAR_PETALBURG_CITY_STATE, 32, VirtualCity_Stadium_PreBattleRoom_EventScript_ClearErnestFlag
	call_if_gt VAR_PETALBURG_CITY_STATE, 22, VirtualCity_Stadium_PreBattleRoom_EventScript_PositionHarrietPreBattle
	call VirtualCity_Stadium_PreBattleRoom_EventScript_TryRepositionErnest
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ClearErnestFlag::
	clearflag FLAG_ACT_II_HIDE_ERNEST_PREBATTLE
	return

VirtualCity_Stadium_PreBattleRoom_EventScript_PositionHarrietPreBattle:
	setobjectxyperm LOCALID_HARRIET_PREBATTLE, 3, 2
	setobjectmovementtype LOCALID_HARRIET_PREBATTLE, MOVEMENT_TYPE_FACE_DOWN
	return
	
VirtualCity_Stadium_PreBattleRoom_OnFrame::
	map_script_2 VAR_PETALBURG_CITY_STATE, 22, VirtualCity_Stadium_PreBattleRoom_Eventscript_IntroScene
	map_script_2 VAR_PETALBURG_CITY_STATE, 32, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB1Scene
	map_script_2 VAR_PETALBURG_CITY_STATE, 34, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB2Scene
	map_script_2 VAR_PETALBURG_CITY_STATE, 36, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB3Scene
	map_script_2 VAR_PETALBURG_CITY_STATE, 38, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronHackSuccess
	map_script_2 VAR_WALK_DOWN_IN_VIRTUAL_PREBATTLE_ROOM, 1, VirtualCity_Stadium_PreBattleRoom_EventScript_WalkDownInVirtualPreBattleRoom
	.2byte 0

VirtualCity_Stadium_PreBattleRoom_EventScript_TryRepositionErnest::
	call_if_eq VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_PreBattleRoom_EventScript_RepositionErnest
	call_if_eq VAR_PETALBURG_CITY_STATE, 35, VirtualCity_Stadium_PreBattleRoom_EventScript_RepositionErnest
	call_if_eq VAR_PETALBURG_CITY_STATE, 37, VirtualCity_Stadium_PreBattleRoom_EventScript_RepositionErnest
	return

VirtualCity_Stadium_PreBattleRoom_EventScript_RepositionErnest::
	setobjectxyperm LOCALID_ERNEST_PREBATTLE, 1, 5
	setobjectmovementtype LOCALID_ERNEST_PREBATTLE, MOVEMENT_TYPE_FACE_LEFT
	return

VirtualCity_Stadium_PreBattleRoom_EventScript_WalkDownInVirtualPreBattleRoom::
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_WALK_DOWN_IN_VIRTUAL_PREBATTLE_ROOM, 0
	releaseall
	end

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
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceRight
	msgbox VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro1_3, MSGBOX_DEFAULT
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
	.string "I know you like modding your POKéMON.\p"
	.string "You'll probably only have time for\n"
	.string "one mod after each battle, though.$"

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietIntro1_2:
	.string "If you gotta remove mods for better\n"
	.string "ones, you can do it at that PC there.\p"
	.string "And don't forget that you can make\n"
	.string "easy changes, like items and abilities,\l"
	.string "right in the POKéMON's info.$"

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

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietAreYouReady::
	lockall
	@Calls to check if the player has learned the hack move when they need to learn the hack move
	goto_if_eq VAR_PETALBURG_CITY_STATE, 37, VirtualCity_Stadium_PreBattleRoom_EventScript_CheckForHackLearn

	@Intentional fallthrough - allows us to use trigger and return here after the check, as calls don't work well if you don't return all the way.
VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietAreYouReady2::
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietAreYouReady, Speaker_Harriet, DIR_EAST, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietNoWorries
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietYouSure
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietGoGetEm, MSGBOX_DEFAULT
	closemessage
	delay 10
	opendoor 4, 1
	waitdooranim
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	delay 10
	closedoor 4, 1
	waitdooranim
	fadenewbgm MUS_NONE
	fadescreen FADE_TO_BLACK
	setflag FLAG_SYS_PREVENT_MAP_FADE
	warpsilent MAP_VIRTUAL_CITY_STADIUM_ARENA, 9, 5
	waitstate
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_CheckForHackLearn::
	goto_if_unset FLAG_ACT_II_MOVE_TAUGHT, VirtualCity_Stadium_PreBattleRoom_Text_HarrietHoldOn
	goto VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietAreYouReady2
	end
	
VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietYouSure::
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietYouSure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietNoWorries
	return

VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietNoWorries::
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietNoWorries, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietHoldOn::
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietHoldOn, Speaker_Harriet, DIR_EAST
	closemessage
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end
	
VirtualCity_Stadium_PreBattleRoom_Text_HarrietHoldOn:
	.string "Hold on a sec, Soph!\p"
	.string "You still gotta learn that TM from\n"
	.string "Ernest.\p"
	.string "You haven't forgotten why we're doing\n"
	.string "this, right…?$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietAreYouReady:
	.string "You ready to go?$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietYouSure:
	.string "I see you haven't set a mod\n"
	.string "on any of your mons yet!\p"
	.string "You sure you want to go out without\n"
	.string "doing so?$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietNoWorries:
	.string "No worries!\p"
	.string "Step up once you feel good and\n"
	.string "ready!$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietGoGetEm:
	.string "Alright!\pChoose your team and\n"
	.string "go get 'em, Soph!$"

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietWellDone:
	.string "Well done!$"


VirtualCity_Stadium_PreBattleRoom_Eventscript_Harriet::
	
	goto_if_eq VAR_WHICH_LEAGUE, 1, VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietSilver
	goto_if_eq VAR_WHICH_LEAGUE, 2, VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietGold
	goto_if_eq VAR_WHICH_LEAGUE, 3, VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietPlatinum
	goto_if_eq VAR_WHICH_LEAGUE, 4, VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietByron
	end

@@ SILVER
@@ TOFOLD add in rematches

VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietSilver::
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 0, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando1
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 1, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando2
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 2, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando3
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 3, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando4
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 4, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXRando5
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietGold::
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 0, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXBroDude
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 1, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXWvddie
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 2, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXSilvaBullet
	goto_if_eq VAR_STADIUM_LEAGUE_PROGRESS, 3, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXEarlGrey
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietPlatinum::
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_HarrietByron::
	goto_if_eq VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB1
	goto_if_eq VAR_PETALBURG_CITY_STATE, 35, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB2
	goto_if_eq VAR_PETALBURG_CITY_STATE, 37, VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB3
	end


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
	.string "of cute POKéMON - not battle-ready.\p"
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
	.string "Okay, she's got vanilla POKéMON, but you\n"
	.string "can tell she's serious.\p"
	.string "She's rocking a fire-water-grass core,\n"
	.string "and some decent synergy.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXRando5Rematch:
	.string "The Ace with the fire-water-grass\n"
	.string "core is next. She looks tough!$"



@@ GOLD



VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXBroDude::
	npc_speak Speaker_Harriet, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXBroDude1
	playse SE_SELECT
	player_speak VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXBroDude2
	playse SE_SELECT
	npc_speak Speaker_Harriet, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXBroDude3
	closemessage
	setflag FLAG_ACT_II_FOUGHT_BRODUDE
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXWvddie::
	npc_speak Speaker_Harriet, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXWvddie1
	playse SE_SELECT
	player_speak VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXWvddie2
	playse SE_SELECT
	npc_speak Speaker_Harriet, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXWvddie3
	closemessage
	setflag FLAG_ACT_II_FOUGHT_WVDDIE
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXSilvaBullet::
	npc_speak Speaker_Harriet, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXSilvaBullet1
	playse SE_SELECT
	player_speak VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXSilvaBullet2
	playse SE_SELECT
	npc_speak Speaker_Harriet, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXSilvaBullet3
	closemessage
	setflag FLAG_ACT_II_FOUGHT_SILVABULLET
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXEarlGrey::
	npc_speak Speaker_Harriet, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXEarlGrey1
	playse SE_SELECT
	player_speak VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXEarlGrey2
	playse SE_SELECT
	npc_speak Speaker_Harriet, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXEarlGrey3
	closemessage
	setflag FLAG_ACT_II_FOUGHT_EARLGREY
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end




VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXBroDude1:
	.string "Quick question, Sophie.\n"
	.string "How do you feel about sunglasses?$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXBroDude2:
	.string "…Oh.\pOh no.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXBroDude3:
	.string "Oh yeah.\pLooks like a standard CoolBro\n"
	.string "Dark spam team coming up.\p"
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
	.string "Turns out one of them is so bad at it\n"
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
	.string "You remember the Teatime pack? It\n"
	.string "came out a few years ago.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattleXEarlGrey2:
	.string "Riiiight, all those POKéMON with\n"
	.string "Hospitality. Fun to use.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattleXEarlGrey3:
	.string "Well, that's his whole team.\n"
	.string "Expect four awful 'tea' puns.\p"	
	.string "It's kinda silly and gimmicky, but I\n"
	.string "respect the committment, y'know?\p"
	.string "Especially because he made it to Gold.\p"
	.string "Good luck!$"


VirtualCity_Stadium_PreBattleRoom_Movement_SophieIntoPlace:
	walk_down
	walk_left
	face_up
	step_end

VirtualCity_Stadium_PreBattleRoom_Movement_SophieIntoPlace2:
	walk_down
	walk_left
	step_end

@@ BYRON

VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB1Scene::
	setvar VAR_WALK_DOWN_IN_VIRTUAL_PREBATTLE_ROOM, 0
	setvar VAR_BYRON_FIGHT_STATE, 1
	applymovement LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Movement_SophieIntoPlace2
	waitmovement 0
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestIveArrived, Speaker_Ernest, DIR_EAST 
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron0, Speaker_Harriet, DIR_SOUTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle1XByron2, SP_NAME_PLAYER, DIR_NORTH
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle1XByron3, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron4, Speaker_Harriet, DIR_SOUTH
	closemessage
	applymovement LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Movement_ErnestToPlace
	waitmovement 0
	setobjectxyperm LOCALID_ERNEST_PREBATTLE, 1, 5
	setobjectmovementtype LOCALID_ERNEST_PREBATTLE, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_PETALBURG_CITY_STATE, 33
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB2Scene::
	@This is if you beat Byron
	setvar VAR_WALK_DOWN_IN_VIRTUAL_PREBATTLE_ROOM, 0
	applymovement LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Movement_SophieIntoPlace
	waitmovement 0
	goto_if_unset FLAG_ACT_II_WON_BYRONB1, VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB2SceneLose

	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2WinXByron1, Speaker_Harriet, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron2, SP_NAME_PLAYER, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByronInfodump, Speaker_Harriet, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2XByron2pt5, SP_NAME_PLAYER, DIR_NORTH
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron3, Speaker_Ernest, DIR_EAST
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron4, MSGBOX_DEFAULT
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron5, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron6, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2WinXByron7, Speaker_Harriet, DIR_SOUTH
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron8, Speaker_Ernest, DIR_EAST
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron9, SP_NAME_PLAYER, DIR_WEST	
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceDown
	applymovement LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Movement_ErnestToPlace
	waitmovement 0
	setobjectxyperm LOCALID_ERNEST_PREBATTLE, 1, 5
	setobjectmovementtype LOCALID_ERNEST_PREBATTLE, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_PETALBURG_CITY_STATE, 35
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB2SceneLose::
	@if you lose
	setvar VAR_WALK_DOWN_IN_VIRTUAL_PREBATTLE_ROOM, 0
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2LoseXByron1, Speaker_Harriet, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron2, SP_NAME_PLAYER, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByronInfodump, Speaker_Harriet, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2XByron2pt5, SP_NAME_PLAYER, DIR_NORTH
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron3, Speaker_Ernest, DIR_EAST
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron4, MSGBOX_DEFAULT
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron5, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron6, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2LoseXByron7, Speaker_Harriet, DIR_SOUTH
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron8, Speaker_Ernest, DIR_EAST
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2LoseXByron9, SP_NAME_PLAYER, DIR_WEST	
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceDown
	applymovement LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Movement_ErnestToPlace
	waitmovement 0
	setobjectxyperm LOCALID_ERNEST_PREBATTLE, 1, 5
	setobjectmovementtype LOCALID_ERNEST_PREBATTLE, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_PETALBURG_CITY_STATE, 35
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end


VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronB3Scene::
	setvar VAR_WALK_DOWN_IN_VIRTUAL_PREBATTLE_ROOM, 0
	applymovement LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Movement_SophieIntoPlace2
	waitmovement 0
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle3XByron1, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron2, Speaker_Ernest, DIR_EAST
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle3XByron3, Speaker_Harriet, DIR_WEST
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron4, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle3XByron5, Speaker_Harriet, DIR_SOUTH
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron6, Speaker_Ernest, DIR_EAST
	playse SE_SELECT
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle3XByron7, SP_NAME_PLAYER, DIR_WEST
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceDown
	applymovement LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Movement_ErnestToPlace
	waitmovement 0
	setobjectxyperm LOCALID_ERNEST_PREBATTLE, 1, 5
	setobjectmovementtype LOCALID_ERNEST_PREBATTLE, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_PETALBURG_CITY_STATE, 37
	setvar VAR_PRE_BATTLE_ROOM_STATE, 1
	call_if_unset FLAG_ACT_II_MOD_INSTALLED, VirtualCity_Stadium_PreBattleRoom_Eventscript_InstallMod
	end



VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB1::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByronInfo, MSGBOX_NPC
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB2::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByronInfodump, MSGBOX_NPC
	end

VirtualCity_Stadium_PreBattleRoom_Eventscript_HarrietBattleXByronB3::
	setspeaker Speaker_Harriet
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByronInfodump, MSGBOX_NPC
	end








VirtualCity_Stadium_PreBattleRoom_Eventscript_ByronHackSuccess::
	applymovement LOCALID_ERNEST_PREBATTLE, Common_Movement_WalkRight
	applymovement LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Movement_SophieIntoPlace3
	waitmovement 0
	speak LOCALID_PLAYER, VirtualCity_Stadium_PreBattleRoom_Text_SophieHackSuccess1, SP_NAME_PLAYER, DIR_WEST
	playse SE_SELECT
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestHackSuccess2, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_SELECT
	speak LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_HarrietHackSuccess3, Speaker_Harriet, DIR_SOUTH
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	playse SE_SELECT
	speak LOCALID_ERNEST_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Text_ErnestHackSuccess4, Speaker_Ernest, DIR_EAST
	closemessage
	clearflag FLAG_ACT_II_HIDE_HOTEL_FRIENDS
	setflag FLAG_ACT_II_HIDE_ERNEST_PREBATTLE
	setvar VAR_PETALBURG_CITY_STATE, 39
	setflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_TO_BLACK
	setvar VAR_BYRON_FIGHT_STATE, 0
	delay 80
	warpsilent MAP_VIRTUAL_CITY_HOTEL_YOUR_ROOM, 12,9
	waitstate
	end

VirtualCity_Stadium_PreBattleRoom_Movement_SophieIntoPlace3:
	walk_down
	face_left
	step_end

VirtualCity_Stadium_PreBattleRoom_Movement_ErnestToPlace:
	walk_down
	walk_down
	face_left
	step_end

VirtualCity_Stadium_PreBattleRoom_Text_ErnestIveArrived:
	.string "I've arriiiiiived!\p"
	.string "Good work getting to Byron,\n"
	.string "Sophie!$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron0:
	.string "That's right.\p"
	.string "Next. It's him. It's Byron.\p"
	.string "This is the guy we came here to fight,\n"
	.string "and boy does he have a nasty team.\p"
	.string "Legendaries, boosted stats, absurd\n"
	.string "and illegal abilities and movesets.\p"
	.string "And he's got a shadowy POKéMON I\n"
	.string "couldn't even identify.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle1XByron2:
	.string "I've boosted up my POKéMON, but I don't\n"
	.string "know if it'll be enough.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle1XByron3:
	.string "It doesn't have to be enough.\n"
	.string "You don't have to win.\p"
	.string "All I have to do is figure out how his\n"
	.string "POKéMON were hacked, and I might\l"
	.string "find and exploit a backdoor.\p"
	.string "I just know it's a hack job.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByron4:
	.string "But wouldn't it be something to wipe\n"
	.string "that smirk off his face?\p"	
	.string "You're smarter AND a better battler!\p"
	.string "I think you have a chance.\p"
	.string "And don't forget - this is a best of\n"
	.string "three. You can afford one loss.\p"
	.string "Good luck!$"





VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle2WinXByron1:
	.string "Wow, you really did it!\n"
	.string "I can hardly believe it!$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByron2:
	.string "Phew, I can't believe it either.\p"
	.string "What was that team???$"


@TOFOLD Incorporate these two (both win and lose)

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2WinXByronInfodump:
	.string "I've got the info you need, on, erm,\n"
	.string "five of the six he has.\p"
	.string "He's got… Futuristic Arceus from the\n"
	.string "original 'Cyber' set;\p"
	.string "an ultra-rare 'Wild Christmas' Xerneas,\n"
	.string "BEFORE the nerf;\p"
	.string "The banned 'Intergalactic' Spiritomb,\n"
	.string "and yes it does have Wonder Guard;\p"
	.string "a 'Secret Sith' Lightsaber Zacian,\n"
	.string "with a Fire-type Behemoth Blade;\p"
	.string "oh lord, a Mega Rayquaza that can Mega\n"
	.string "evolve into 'Double Mega Rayquaza';\p"
	.string "and a shadowy thing that looks like\n"
	.string "a Zoroark but definitely isn't one.\p"
	.string "Wow, that's an awful team.\n"
	.string "Um, good luck.$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle2XByron2pt5:
	.string "Wow.\p"
	.string "Um, Ernest, any good news for me?$"


@KUMATORA (I used my limited cybersecurity vocabulary to make something up here - if you have suggestions, it's all you)
@TOFOLD Check the changed dialogue to make sure it's okay?

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2WinXByron3:
	.string "I. {PAUSE 50}Cannot.\p"
	.string "BELIEVE!\p"
	.string "How STUPID he is!\p"
	.string "He disables the encrypted tunnel from\n"
	.string "{COLOR GREEN}BETTER's{COLOR DARK_GRAY} website to his own\l"
	.string "laptop's IP!\p"
	.string "That's how he submits such\nHOGWASH teams!\p"
	.string "His data's exposed - I just gotta\n"
	.string "break into his laptop somehow.\pBut how?\p"
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
	.string "What were those Pokemon, though?$"

@KUMATORA (I used my limited cybersecurity vocabulary to make something up here - if you have suggestions, it's all you)

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle2LoseXByron3:
	.string "I. {PAUSE 50}Cannot.\p"
	.string "BELIEVE!\p"
	.string "How STUPID he is!\p"
	.string "He disables the encrypted tunnel from\n"
	.string "{COLOR GREEN}BETTER's{COLOR DARK_GRAY} website to his own\l"
	.string "laptop's IP!\p"
	.string "That's how he submits such\nHOGWASH teams!\p"
	.string "His data's exposed - I just gotta\n"
	.string "break into his laptop somehow.\pBut how?\p"
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



VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle1XByronInfo:
	.string "I don't know much about his team.\p"
	.string "Legendaries, boosted stats, absurd\n"
	.string "and illegal abilities and movesets.\p"
	.string "And he's got a shadowy POKéMON I\n"
	.string "couldn't even identify.$"
	.string "I'll need some time to research them.$"


VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle3XByron1:
	.string "Ernest?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron2:
	.string "It's done. Here.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle3XByron3:
	.string "Huh? A disc?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron4:
	.string "It's called a TM. Trainers used to use\n"
	.string "them to teach POKéMON moves.$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietBattle3XByron5:
	.string "Discs taught POKéMON moves?\n"
	.string "Were… Were POKéMON always just code?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestBattle3XByron6:
	.string "No, it was just a way…\p"
	.string "Um, anyway, I can use it to teach one\n"
	.string "of your POKéMON a move I just made.\p"
	.string "It's got the viral load in it, so when\n"
	.string "it hits one of his hacked POKéMON,\l"
	.string "I can get access.\p"
	.string "That infected POKéMON will give me an in\n"
	.string "to his computer after the match, when\l"
	.string "the final match validation occurs.\p"
	.string "The move's high priority and accurate,\n"
	.string "so it shouldn't be hard to hit.\p"
	.string "After that, doesn't matter if you win\n"
	.string "or lose.\p"
	.string "I'll be in the system!$"

VirtualCity_Stadium_PreBattleRoom_Text_SophieBattle3XByron7:
	.string "I can do that.$"




VirtualCity_Stadium_PreBattleRoom_Text_SophieHackSuccess1:
	.string "It's done.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestHackSuccess2:
	.string "I see it. What an amateur!$"

VirtualCity_Stadium_PreBattleRoom_Text_HarrietHackSuccess3:
	.string "Well done! Now, what next?$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestHackSuccess4:
	.string "I need to disguise your identity, and\n"
	.string "tie it to these credentials.\p"
	.string "Let's get out of here for now.$"





@ Ernest

VirtualCity_Stadium_PreBattleRoom_Eventscript_Ernest::
	goto_if_eq VAR_PETALBURG_CITY_STATE, 39, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestLetsGo
	goto_if_eq VAR_PETALBURG_CITY_STATE, 37, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestTutor
	goto_if_eq VAR_PETALBURG_CITY_STATE, 35, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestWork
	goto_if_eq VAR_PETALBURG_CITY_STATE, 33, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestWait
	end


VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestWait::
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestWait, MSGBOX_NPC
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestWork::
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestWork, MSGBOX_NPC
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestLetsGo::
	setspeaker Speaker_Ernest
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestLetsGo, MSGBOX_NPC
	end



VirtualCity_Stadium_PreBattleRoom_Text_ErnestWork:
	.string "Don't bug me, I'm working!$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestWait:
	.string "Keep going! I can't help until I see\n"
	.string "the team he's got.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestLetsGo:
	.string "It worked! Time to go test it.$"



VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestTutor::
	lock
	faceplayer
	move_tutor MOVE_OCTAZOOKA, VirtualCity_Stadium_PreBattleRoom_Text_ErnestTeach, VirtualCity_Stadium_PreBattleRoom_Text_ErnestWhich, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestDeclined, VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestTaught
	@clearflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	setvar VAR_PRE_BATTLE_ROOM_STATE, 0
	setflag FLAG_ACT_II_MOVE_TAUGHT
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestDeclined::
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestDeclined, MSGBOX_DEFAULT
	release
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ErnestTaught::
	msgbox VirtualCity_Stadium_PreBattleRoom_Text_ErnestTaught, MSGBOX_DEFAULT
	setvar VAR_PRE_BATTLE_ROOM_STATE, 0
	setflag FLAG_ACT_II_MOVE_TAUGHT
	release
	end

VirtualCity_Stadium_PreBattleRoom_Text_ErnestTeach:
	.string "Are you ready?$"


VirtualCity_Stadium_PreBattleRoom_Text_ErnestWhich:
	.string "Who learns it? I can teach multiple\n"
	.string "if you want.$"

VirtualCity_Stadium_PreBattleRoom_Text_ErnestDeclined:
	.string "We don't have a lot of time…$"

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
	.string "Remove a POKéMON's mods?$"

VirtualCity_Stadium_PreBattleRoom_Text_RemovalComplete:
	.string "Removal complete.$"

VirtulCity_Stadium_PreBattleRoom_Text_HarrietAreYouSureExitLeague:
	.string "Sophie! Leaving means you'll exit\n"
	.string "the league!\p"
	.string "Are you sure you want to do that?$"

VirtualCity_Stadium_PreBattleRoom_Text_KeepStoryProgress::
	.string "Would you like to keep your league\n"
	.string "progress or reset it to the start?$"

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeague::
	lockall
	applymovement LOCALID_HARRIET_PREBATTLE, Common_Movement_WalkDown2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_HARRIET_PREBATTLE, VirtulCity_Stadium_PreBattleRoom_Text_HarrietAreYouSureExitLeague Speaker_Harriet, DIR_SOUTH, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueDeny
	goto_if_unset FLAG_STADIUM_PREBATTLE_STORY_PROGRESS, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueReset
	setspeaker NULL
	message VirtualCity_Stadium_PreBattleRoom_Text_KeepStoryProgress
	waitmessage
	multichoice 20, 6, MULTI_RETIRE_FROM_LEAGUE, FALSE
	case 0, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueKeep
	case 1, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueReset
	case 2, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueDeny
	case MULTI_B_PRESSED, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueDeny
	goto VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueReset
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_SophieForget::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_HARRIET_PREBATTLE, VirtulCity_Stadium_PreBattleRoom_Text_HarrietSophieForget Speaker_Harriet, DIR_SOUTH
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

VirtulCity_Stadium_PreBattleRoom_Text_HarrietSophieForget:
	.string "SOPHIE!!!\p"
	.string "Did you forget why we're doing this\n"
	.string "whole thing!?\p"
	.string "We need you to prepare for the Byron\n"
	.string "fight! Get back here!$"

VirtualCity_Stadium_PreBattleRoom_Movement_HarrietReturnToTop:
	walk_up
	walk_up
	face_down
	step_end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueReset::
	setvar VAR_STADIUM_LEAGUE_PROGRESS, 0
	setvar VAR_WHICH_LEAGUE, 0
	goto_if_eq VAR_WHICH_LEAGUE, 1, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetSilver
	goto_if_eq VAR_WHICH_LEAGUE, 2, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetGold
	goto_if_eq VAR_WHICH_LEAGUE, 3, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetPlatinum
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetSilver::
	goto_if_set FLAG_STADIUM_PREBATTLE_STORY_PROGRESS, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetSilverStory
	goto VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueKeep
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetSilverStory::
	setvar VAR_PETALBURG_CITY_STATE, 23
	goto VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueKeep
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetGold::
	goto_if_set FLAG_STADIUM_PREBATTLE_STORY_PROGRESS, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetGoldStory

	goto VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueKeep
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetGoldStory::
	setvar VAR_PETALBURG_CITY_STATE, 28
	goto VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueKeep
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetPlatinum::
	goto_if_set FLAG_STADIUM_PREBATTLE_STORY_PROGRESS, VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetPlatinumStory
	goto VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueKeep
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueResetPlatinumStory::
	goto VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueKeep
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueKeep::
	warp MAP_VIRTUAL_CITY_STADIUM_ENTRANCE, 10, 10
	waitstate
	releaseall
	end

VirtualCity_Stadium_PreBattleRoom_EventScript_ExitLeagueDeny::
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	applymovement LOCALID_HARRIET_PREBATTLE, VirtualCity_Stadium_PreBattleRoom_Movement_HarrietReturnToTop
	waitmovement 0
	releaseall
	end

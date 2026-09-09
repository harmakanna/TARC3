VirtualCity_CommsTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VirtualCity_CommsTower_1F_OnLoad
	.byte 0

VirtualCity_CommsTower_1F_OnLoad::
	call_if_unset FLAG_COMMS_1F_DOOR, EventScript_CloseComms1FDoor
	setdynamicwarp MAP_VIRTUAL_CITY_WORK_YOUR_OFFICE, 0
	end

EventScript_CloseComms1FDoor::
	setmetatile 10, 5, METATILE_SilphCo_HorizontalBarrier_TopLeft, 1
	setmetatile 11, 5, METATILE_SilphCo_HorizontalBarrier_TopRight, 1
	setmetatile 10, 6, METATILE_SilphCo_HorizontalBarrier_BottomLeft, 1
	setmetatile 11, 6, METATILE_SilphCo_HorizontalBarrier_BottomRight, 1
	setmetatile 10, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 11, 7, METATILE_SilphCo_Floor_ShadeFull, 0
	return

EventScript_OpenComms1FDoor::
	setmetatile 10, 5, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 11, 5, METATILE_SilphCo_Floor, 0
	setmetatile 10, 6, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 11, 6, METATILE_SilphCo_Floor, 0
	setmetatile 11, 7, METATILE_SilphCo_Floor, 0
	return

VirtualCity_CommsTower_1F_EventScript_Door::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_0x8004, FLAG_COMMS_1F_DOOR
	goto_if_set FLAG_COMMS_1F_DOOR, EventScript_DoorUnlocked
	goto VirtualCity_CommsTower_1F_EventScript_TryUnlockDoor
	end

VirtualCity_CommsTower_1F_EventScript_TryUnlockDoor::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, EventScript_OpenDoor
	msgbox VirtualCity_CommsTower_1F_Text_AccessDenied
	releaseall
	end

VirtualCity_CommsTower_1F_Text_AccessDenied::
	.string "Identity unknown.\n"
	.string "Access denied.$"








@ Minh ACT I (Add Magikarp branch if time allows TOFOLD)

VirtualCity_CommsTower_1F_Eventscript_ActIMinh::
	goto_if_set FLAG_ACT_I_INFO_OBTAINED, VirtualCity_CommsTower_1F_Text_Eventscript_ACTIPokemonCheck
	goto_if_set FLAG_ACT_I_STARTED, VirtualCity_CommsTower_1F_Eventscript_MinhACTIIntroRepeat
	goto_if_eq VAR_PETALBURG_CITY_STATE, 10, VirtualCity_CommsTower_1F_Eventscript_ActIIntro
	end

VirtualCity_CommsTower_1F_Eventscript_ActIIntro::
	@warpsilent NEXT TO Minh
	@applymovement LOCALID_OFFICE_MINH, Common_Movement_FaceLeft
	@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight

	@speak LOCALID_OFFICE_MINH, VirtualCity_CommsTower_1F_Text_MinhACTIIntro1, Speaker_Minh, DIR_WEST
	npc_speak Speaker_Minh, VirtualCity_CommsTower_1F_Text_MinhACTIIntro1
	closemessage
	applymovement LOCALID_OFFICE_MINH, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	special SpawnCameraObject 
	call_if_eq VAR_FACING, DIR_EAST, VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraEast
	call_if_eq VAR_FACING, DIR_SOUTH, VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraSouth
	call_if_eq VAR_FACING, DIR_WEST, VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraWest
	@applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCamera1
	@waitmovement 0

	speak LOCALID_OFFICE_MINH, VirtualCity_CommsTower_1F_Text_MinhACTIIntro2, Speaker_Minh, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_CommsTower_1F_Text_SophieACTIIntro3, SP_NAME_PLAYER, DIR_NORTH
	playse SE_SELECT
	speak LOCALID_OFFICE_MINH, VirtualCity_CommsTower_1F_Text_MinhACTIIntro4, Speaker_Minh, DIR_NORTH
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraEastBack
	call_if_eq VAR_FACING, DIR_SOUTH, VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraSouthBack
	call_if_eq VAR_FACING, DIR_WEST, VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraWestBack
	@applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCamera1


	@applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCamera2
	@waitmovement 0
	special RemoveCameraObject 
	delay 20

	player_speak VirtualCity_CommsTower_1F_Text_SophieACTIIntro5
	playse SE_SELECT
	npc_speak Speaker_Minh, VirtualCity_CommsTower_1F_Text_MinhACTIIntro6	
	closemessage
	setvar VAR_PETALBURG_CITY_STATE, 11
	setflag FLAG_ACT_I_STARTED
	setflag FLAG_HIDE_LOLA_BEDROOM_PROLOGUE
	clearflag FLAG_HIDE_ACT_I_RESEARCHERS
	clearflag FLAG_HIDE_OUTSIDE_WORLD_PROLOGUE

	end

VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraEast::
	applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCameraEast
	waitmovement 0
	return

VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraSouth::
	applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCameraSouth
	waitmovement 0
	return

VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraWest::
	applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCameraWest
	waitmovement 0
	return

VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraEastBack::
	applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCameraEastBack
	waitmovement 0
	return

VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraSouthBack::
	applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCameraSouthBack
	waitmovement 0
	return

VirtualCity_CommsTower_1F_EventScript_MoveIntroCameraWestBack::
	applymovement OBJ_EVENT_ID_CAMERA, VirtualCity_CommsTower_1F_Move_IntroCameraWestBack
	waitmovement 0
	return



VirtualCity_CommsTower_1F_Move_IntroCameraEast:
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_up
	walk_up
	step_end

VirtualCity_CommsTower_1F_Move_IntroCameraSouth:
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	step_end

VirtualCity_CommsTower_1F_Move_IntroCameraWest:
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	step_end


VirtualCity_CommsTower_1F_Move_IntroCameraEastBack:
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_down
	walk_down
	step_end

VirtualCity_CommsTower_1F_Move_IntroCameraSouthBack:
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	step_end

VirtualCity_CommsTower_1F_Move_IntroCameraWestBack:
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	step_end

VirtualCity_CommsTower_1F_Text_MinhACTIIntro1:
	.string "Good, you made it.\p"
	.string "I've been asking around, and I might\n"
	.string "have a lead.\p"
	.string "Apparently, a bunch of artists -\n"
	.string "the boring ones, not visionaries\l"
	.string "like me - got moved recently.\p"
	.string "They're working in {COLOR GREEN}BETTER{COLOR DARK_GRAY}'s Research\n"
	.string "Department, which is pretty suspicious.\p"
	.string "We need to get into the department and\n"
	.string "see if they're making fake IRL Pokemon.\p"
	.string "But, of course, there's a problem.$"

VirtualCity_CommsTower_1F_Text_MinhACTIIntro2:
	.string "The stairs there will take you to our\n"
	.string "Design office, like usual, because the\l"
	.string "autoscanner knows where you work.\p"
	.string "The guard can set the stairs to go to\n"
	.string "Research, but we need a good reason.$"

VirtualCity_CommsTower_1F_Text_SophieACTIIntro3:
	.string "I see. Why don't I just-$"

VirtualCity_CommsTower_1F_Text_MinhACTIIntro4:
	.string "Sophie, we've been over this. No\n"
	.string "starting fights in public places.\p"
	.string "If you fight that guard, people will\n"
	.string "stop you, and we'll never find out\l"
	.string "what's going on.\p"
	.string "Only battle if you absolutely have to.$"

VirtualCity_CommsTower_1F_Text_SophieACTIIntro5:
	.string "Ugh, fine.\p"
	.string "So, no Pokemon? My bare hands should\n"
	.string "be enough to-$"

VirtualCity_CommsTower_1F_Text_MinhACTIIntro6:
	.string "NO, Sophie.\p"
	.string "As I walked in, I saw a group of {COLOR BLUE}five\n"
	.string "researchers {COLOR DARK_GRAY}heading to the casino.\p"
	.string "Maybe you can eavesdrop, and find out\n"
	.string "what they're working on?\p"
	.string "If you figure it out, maybe we can find\n"
	.string "that Pokemon and show the guard?\p"
	.string "Sigh… I dunno. You're the pro battler.\n"
	.string "My art skills don't really help here.$"


VirtualCity_CommsTower_1F_Eventscript_MinhACTIIntroRepeat::
	setspeaker Speaker_Minh
	msgbox VirtualCity_CommsTower_1F_Text_MinhACTIIntroRepeat, MSGBOX_NPC
	end


VirtualCity_CommsTower_1F_Text_MinhACTIIntroRepeat:
	.string "You remember what to do, right?\p"
	.string "Get to the Casino and eavesdrop on\n"
	.string "researchers, and see if you can\l"
	.string "find out what Pokemon they'll let in.\p"
	.string "We'll plan it from there.$"



VirtualCity_CommsTower_1F_Text_Eventscript_ACTIPokemonCheck::
	npc_speak Speaker_Minh, VirtualCity_CommsTower_1F_Text_MinhACTIPokemonCheck
	playse SE_SELECT
	player_speak VirtualCity_CommsTower_1F_Text_SophieACTIPokemonCheck



	dynmultipush PonytaChoice_Text_Choice1, 1
	dynmultipush PonytaChoice_Text_Choice2, 2
	dynmultipush PonytaChoice_Text_Choice3, 3
	dynmultipush PonytaChoice_Text_Choice4, 4
	dynmultipush PonytaChoice_Text_Choice5, 5
	dynmultipush PonytaChoice_Text_Choice6, 6
	dynmultipush PonytaChoice_Text_Choice7, 7
	dynmultipush PonytaChoice_Text_Choice8, 8
	dynmultipush PonytaChoice_Text_Choice9, 9
	dynmultipush PonytaChoice_Text_Choice10, 10
	dynmultipush PonytaChoice_Text_Choice11, 11
	dynmultipush PonytaChoice_Text_Choice12, 12
	dynmultipush PonytaChoice_Text_Choice13, 13
	dynmultipush PonytaChoice_Text_Choice14, 14
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	goto_if_eq VAR_RESULT, 8, VirtualCity_CommsTower_1F_Text_Eventscript_ACTIPokemonCheckSuccess
	player_speak VirtualCity_CommsTower_1F_Text_SophieACTIPokemonFailure
	closemessage
	end


VirtualCity_CommsTower_1F_Text_Eventscript_ACTIPokemonCheckSuccess::
	npc_speak Speaker_Minh, VirtualCity_CommsTower_1F_Text_MinhACTIPokemonCheckSuccess1
	playse SE_SELECT
	player_speak VirtualCity_CommsTower_1F_Text_SophieACTIPokemonCheckSuccess2
	playse SE_SELECT
	npc_speak Speaker_Minh, VirtualCity_CommsTower_1F_Text_MinhACTIPokemonCheckSuccess3
	playse SE_SELECT
	player_speak VirtualCity_CommsTower_1F_Text_SophieACTIPokemonCheckSuccess4
	closemessage
	setvar VAR_PETALBURG_CITY_STATE, 12
	clearflag FLAG_ACT_I_HIDE_MINH_OFFICE
	setflag FLAG_SYS_PREVENT_MAP_FADE
	warpsilent MAP_VIRTUAL_CITY_WORK_YOUR_OFFICE, 13, 19
	waitstate
	end



PonytaChoice_Text_Choice1:
	.string "Lapras$"

PonytaChoice_Text_Choice2:
	.string "Pyroar$"

PonytaChoice_Text_Choice3:
	.string "Snorlax$"

PonytaChoice_Text_Choice4:
	.string "Fearow$"

PonytaChoice_Text_Choice5:
	.string "Malamar$"

PonytaChoice_Text_Choice6:
	.string "Scolipede$"

PonytaChoice_Text_Choice7:
	.string "Pikachu$"

PonytaChoice_Text_Choice8:
	.string "Ponyta$"

PonytaChoice_Text_Choice9:
	.string "Tinkatink$"

PonytaChoice_Text_Choice10:
	.string "Ho-Oh$"

PonytaChoice_Text_Choice11:
	.string "Snubbull$"

PonytaChoice_Text_Choice12:
	.string "Magmar$"

PonytaChoice_Text_Choice13:
	.string "Spinda$"

PonytaChoice_Text_Choice14:
	.string "Mawile$"


VirtualCity_CommsTower_1F_Text_MinhACTIPokemonCheck:
	.string "Did you get any info on what Pokemon\n"
	.string "you can get past the guard?$"

VirtualCity_CommsTower_1F_Text_SophieACTIPokemonCheck:
	.string "You mentioned {COLOR BLUE}five {COLOR DARK_GRAY}researchers… but I\n"
	.string "saw {COLOR RED}six {COLOR DARK_GRAY}different researchers, talking\l"
	.string "about a Pokemon they were working on…\p"
	.string "{COLOR BLUE}One of them must have been unrelated.\p"
	.string "{COLOR DARK_GRAY}I think they were talking about…$"

VirtualCity_CommsTower_1F_Text_SophieACTIPokemonFailure:
	.string "Hmm, that doesn't sound right.\p"
	.string "I'm sure {COLOR BLUE}one of them {COLOR DARK_GRAY}wasn't\n"
	.string "describing our mystery mon.\p"
	.string "But which one?$"

VirtualCity_CommsTower_1F_Text_MinhACTIPokemonCheckSuccess1:
	.string "Nice! Wait, Ponyta are expensive!\p"
	.string "By the time we save up to get one,\n"
	.string "they'll be working on something else!$"

VirtualCity_CommsTower_1F_Text_SophieACTIPokemonCheckSuccess2:
	.string "Hmm. How well can you draw Ponyta?$"

VirtualCity_CommsTower_1F_Text_MinhACTIPokemonCheckSuccess3:
	.string "What? Umm, very well. It's my fourteenth\n"
	.string "favorite Fire-type.\p"
	.string "You'd know that if you read my blog.$"

VirtualCity_CommsTower_1F_Text_SophieACTIPokemonCheckSuccess4:
	.string "I think I know how your artistic skill\n"
	.string "can get us into Research.\p"
	.string "Let's stop by the Design office.$"



@@ Guard

Speaker_Guard::
	.string "Guard$"

VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuard::
	
	goto_if_set FLAG_ACT_III_POINTOFNORETURN, VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardFight
	goto_if_set FLAG_ACT_II_STARTED, VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardTrouble
	goto_if_set FLAG_ACT_I_EX_PONYTA_OBTAINED, VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardPonyta
	npc_speak Speaker_Guard, VirtualCity_CommsTower_1F_Text_NoPokemonGuardStop
	closemessage
	end

VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardTrouble::
	setspeaker Speaker_Guard
	msgbox VirtualCity_CommsTower_1F_Text_NoPokemonGuardTrouble, MSGBOX_NPC
	end

VirtualCity_CommsTower_1F_Text_NoPokemonGuardTrouble:
	.string "Oh, it's you again.\n"
	.string "Stay out of trouble, y'hear?$"


VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardFight::
	setspeaker Speaker_Guard
	msgbox VirtualCity_CommsTower_1F_Text_NoPokemonGuardFight, MSGBOX_NPC
	@@ trainerbattle @TOFOLD
	end

VirtualCity_CommsTower_1F_Text_NoPokemonGuardFight:
	.string "AAAAA WHAT IS THAT?$"



VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardEnter:
	npc_speak Speaker_Guard, VirtualCity_CommsTower_1F_Text_NoPokemonGuardEnter
	closemessage
	goto VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardMoves
	end

VirtualCity_CommsTower_1F_Text_NoPokemonGuardEnter:
	.string "Ah good, no Pokemon.$"

VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardMoves:
	@ guard moves out of the way depending on where you are standing TOFOLD
	applymovement LOCALID_GUARD, Common_Movement_WalkDown
	end



VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardStop:
	npc_speak Speaker_Guard, VirtualCity_CommsTower_1F_Text_NoPokemonGuardStop
	closemessage
	end

VirtualCity_CommsTower_1F_Text_NoPokemonGuardStop:
	.string "Huh? You want to go to Research?\p"
	.string "Research is pretty locked down; they're\n"
	.string "working on something top secret.\p"
	.string "Can't let you go there unless you\n"
	.string "can prove they called for you, sorry.$"




VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardPonyta:
	npc_speak Speaker_Guard, VirtualCity_CommsTower_1F_Text_NoPokemonGuardPonyta
	applymovement LOCALID_GUARD, VirtualCity_CommsTower_1F_Move_NoPokemonGuardPonyta
	waitmovement 0
	setdynamicwarp MAP_VIRTUAL_CITY_COMMS_TOWER_RESEARCH, 0
	setvar VAR_TEMP_0, 1
	setspeaker Speaker_Guard
	msgbox VirtualCity_CommsTower_1F_Text_NoPokemonGuardGoAhead, MSGBOX_SIGN
	closemessage
	end

VirtualCity_CommsTower_1F_Text_NoPokemonGuardPonyta:
	.string "Research? I'm sorry, I can't…\p"
	.string "Oh, is it done? I barely recognized it…\n"
	.string "It looks great!$"

VirtualCity_CommsTower_1F_Text_NoPokemonGuardGoAhead:
	.string "You're all set. I've configured the\n"
	.string "stairs to take you to Research.$"

@VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardMagikarp:
@	speak LOCALID_GUARD, VirtualCity_CommsTower_1F_Text_NoPokemonGuardMagikarp, Speaker_Guard, DIR_SOUTH
@	goto VirtualCity_CommsTower_1F_Eventscript_NoPokemonGuardMoves
	end


@VirtualCity_CommsTower_1F_Text_NoPokemonGuardMagikarp:
@	.string "Hold it, you can't bring Pokemon here.\p"
@	.string "Too many… wait, is that a Magikarp?\n"
@	.string "Ahahahahahaha!\p"
@	.string "Go on through, heh. Ain't no way you're\n"
@	.string "overpowering guards with that!$"



VirtualCity_CommsTower_1F_Move_NoPokemonGuardPonyta:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	delay_16
	delay_16
	face_player
	step_end




@@ Roland and his fans TOFOLD

VirtualCity_CommsTower_1F_Text_Roland:
	.string "Ugh, Roland is rambling about the\n"
	.string "quanta system again.\p"
	.string "Listen in?$"

VirtualCity_CommsTower_1F_Text_RolandNo:
	.string "Better not. The headache from the last\n"
	.string "time is just starting to fade.$"



VirtualCity_CommsTower_1F_Text_RolandRamble1:
	.string "…so obviously, ahem, the real world runs\n"
	.string "on a discrete time scale. Hrrmph.\p"
	.string "You know, battle time is in turns.\n"
	.string "One attack per turn, no half-turns.\p"
	.string "But in the Place, they've quantized\n"
	.string "time down a bit smaller. Yeah.\p"
	.string "Four fractional turns in a regular turn.\p"
	.string "Casuals call them miniturns, but pros\n"
	.string "use the real name: quanta.\p"
	.string "It's a real innovation. Makes battles\n"
	.string "suited for high skill players like me.\p"
	.string "You can hit three Quick Attacks before\n"
	.string "your opponent hits a Solarbeam.\p"
	.string "Or, you can use Giga Impact for a huge\n"
	.string "attack immediately, but then you use\l"
	.string "a lot of quanta recharging.\p"
	.string "Harrumph! I say…$"

VirtualCity_CommsTower_1F_Text_RolandRamble2:
	.string "…$"

VirtualCity_CommsTower_1F_Text_RolandRamble3:
	.string "…$"

VirtualCity_CommsTower_1F_Text_RolandRamblePostgame:
	.string "…$"




VirtualCity_CommsTower_1F_Text_RolandFanClubGuy1:
	.string "Wow… I never knew that!\p"
	.string "Roland, you're so cool!$"

VirtualCity_CommsTower_1F_Text_RolandFanClubGirl1:
	.string "So the Realm is really higher fidelity\n"
	.string "than real life?\p"
	.string "I thought that was just marketing!$"



VirtualCity_CommsTower_1F_Text_RolandFanClubGuy2:
	.string "!$"

VirtualCity_CommsTower_1F_Text_RolandFanClubGirl2:
	.string "!$"


VirtualCity_CommsTower_1F_Text_RolandFanClubGuy3:
	.string "!$"

VirtualCity_CommsTower_1F_Text_RolandFanClubGirl3:
	.string "!$"


VirtualCity_CommsTower_1F_Text_RolandFanClubGuyPostgame:
	.string "!$"

VirtualCity_CommsTower_1F_Text_RolandFanClubGirlPostgame:
	.string "!$"


Speaker_Receptionist::
	.string "Receptionist$"

VirtualCity_CommsTower_1F_Eventscript_Receptionist::
	applymovement LOCALID_COMMS_RECEPTION, VirtualCity_CommsTower_1F_Move_Receptionist
	goto_if_set FLAG_ACT_III_COMPLETE, VirtualCity_CommsTower_1F_Eventscript_Receptionist3
	goto_if_set FLAG_ACT_II_COMPLETE, VirtualCity_CommsTower_1F_Eventscript_Receptionist2
	setspeaker Speaker_Receptionist
	speak LOCALID_ARCANINE, VirtualCity_CommsTower_1F_Text_Receptionist1, Speaker_Receptionist, DIR_EAST
	closemessage
	end

VirtualCity_CommsTower_1F_Move_Receptionist:
	face_player
	step_end

VirtualCity_CommsTower_1F_Text_Receptionist1:
	.string "Hi! Welcome to the {COLOR GREEN}BETTER{COLOR DARK_GRAY} Tower!\n"
	.string "A {COLOR GREEN}BETTER{COLOR DARK_GRAY} Workplace!\p"
	.string "Just walk up those stairs! The state-\n"
	.string "of-the-art scanner will automatically\l"
	.string "route you to your office!\p"
	.string "Have a {COLOR GREEN}BETTER{COLOR DARK_GRAY} day!$"


VirtualCity_CommsTower_1F_Eventscript_Receptionist2::
	speak LOCALID_ARCANINE, VirtualCity_CommsTower_1F_Text_Receptionist2, Speaker_Receptionist, DIR_EAST
	closemessage
	end

VirtualCity_CommsTower_1F_Text_Receptionist2:
	.string "Aaaah, what is that?!\n"
	.string "SECURITY!$"


VirtualCity_CommsTower_1F_Eventscript_Receptionist3::
	speak LOCALID_ARCANINE, VirtualCity_CommsTower_1F_Text_Receptionist3, Speaker_Receptionist, DIR_EAST
	closemessage
	end

VirtualCity_CommsTower_1F_Text_Receptionist3:
	.string "!$"


VirtualCity_CommsTower_1F_Autoscanner::
	lockall
	delay 10
	playse SE_CONTEST_MONS_TURN
	waitse
	setspeaker Speaker_Autoscanner
	msgbox VirtualCity_CommsTower_1F_Text_Autoscanner, MSGBOX_NPC
	closemessage
	releaseall
	end

VirtualCity_CommsTower_1F_Text_Autoscanner:
	.string "Scan Complete. Welcome, Sophie.\n"
	.string "Stairs Set To {COLOR GREEN}BETTER{COLOR DARK_GRAY} Design, Wing 5.$"


VirtualCity_CommsTower_1F_AuthorizedSign::
	msgbox VirtualCity_HotelLobby_Text_AuthorizedSign, MSGBOX_SIGN
	closemessage
	end


VirtualCity_HotelLobby_Text_AuthorizedSign:
	.string "{COLOR GREEN}BETTER Place{COLOR DARK_GRAY} Maintenance\n"
	.string "AUTHORIZED PERSONNEL ONLY$"



VirtualCity_CommsTower_1F_CantLeave::
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_HotelLobby_Text_CantLeave, MSGBOX_SIGN
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	end

VirtualCity_HotelLobby_Text_CantLeave:
	.string "I can't leave now! I have to\n"
	.string "get to the Rotom Phone console!$"
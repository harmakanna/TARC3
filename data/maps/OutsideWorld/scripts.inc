OutsideWorld_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OutsideWorld_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_OnFrame
	.byte 0


OutsideWorld_OnTransition::
	end

OutsideWorld_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 3, OutsideWorld_PrologueEndScene_Final_Really
	.2byte 0


OutsideWorld_PrologueEndScene_Final_Really::
	delay 50
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreenspeed FADE_FROM_BLACK 5
	delay 50
	
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue1, Speaker_Sophie, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_OW_MINH, OutsideWorld_MinhPrologue2, Speaker_Minh, DIR_SOUTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue3, Speaker_Sophie, DIR_EAST
	playse SE_SELECT
	speak LOCALID_OW_MINH, OutsideWorld_MinhPrologue4, Speaker_Minh, DIR_WEST
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_SophiePrologue5, Speaker_Sophie, DIR_EAST
	closemessage
	delay 30
	applymovement LOCALID_OW_MINH, OutsideWorld_Move_Minh1
	delay 100
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_Move_Sophie1
	waitmovement 0
	removeobject LOCALID_OW_MINH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_Move_Sophie2
	applymovement OBJ_EVENT_ID_CAMERA, OutsideWorld_Move_Camera1
	delay 50
	playse SE_DOOR
	opendoor 23, 13
	waitdooranim
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	hideplayer
	closedoor 23, 13
	waitdooranim
	delay 50
	delay 50
	setvar VAR_PETALBURG_CITY_STATE, 4
	warpsilent MAP_OUTSIDE_WORLD_APARTMENT_BLDG1_FLOOR1, 2,4
	waitstate
	end	

	@TOFOLD move this
	setflag FLAG_PROLOGUE_COMPLETE

	end

OutsideWorld_Move_Minh1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OutsideWorld_Script_Woman::
	msgbox OutsideWorld_Text_Woman, MSGBOX_NPC
	end
	
OutsideWorld_Move_Sophie1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

OutsideWorld_Move_Sophie2:
	walk_right
	walk_up
	step_end

OutsideWorld_Move_Camera1:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


OutsideWorld_Script_YoungsterSisConvo::
	lock
	speak OUTSIDE_LITTLE_GIRL, OutsideWorld_Text_LittleGirl1, Speaker_Little_Girl, DIR_SOUTH
	playse SE_SELECT
	speak OUTSIDE_YOUNGSTER, OutsideWorld_Text_Youngster, Speaker_Youngster, DIR_SOUTH
	playse SE_SELECT
	speak OUTSIDE_LITTLE_GIRL, OutsideWorld_Text_LittleGirl2, Speaker_Little_Girl, DIR_SOUTH
	closemessage
	release
	end

OutsideWorld_Script_BaldMan::
	msgbox OutsideWorld_Text_BaldMan, MSGBOX_NPC
	end

OutsideWorld_Script_BlueMan::
	msgbox OutsideWorld_Text_BlueMan, MSGBOX_NPC
	end

OutsideWorld_Script_PurpleBoy::
	msgbox OutsideWorld_Text_PurpleBoy, MSGBOX_NPC
	end

OutsideWorld_Script_YoungBoy::
	msgbox OutsideWorld_Text_YoungBoy, MSGBOX_NPC
	end

OutsideWorld_Script_OldMan::
	msgbox OutsideWorld_Text_OldMan, MSGBOX_NPC
	end

OutsideWorld_Script_ToOldMan::
	lock
	msgbox OutsideWorld_Text_ToOldMan, MSGBOX_DEFAULT
	closemessage
	release
	end

OutsideWorld_Script_Dealer::
	lock
	npc_speak Speaker_Dodgy_Man, OutsideWorld_Text_Dealer
	playse SE_SELECT
	
	@Kumatora - I think player_speak is broken? I put in the obvious workaround, but feel free to change back if it's fixed
	@setspeaker Speaker_Sophie
	@msgbox OutsideWorld_Text_SophieHellNo, MSGBOX_NPC

	player_speak OutsideWorld_Text_SophieHellNo
	playse SE_SELECT
	npc_speak Speaker_Dodgy_Man, OutsideWorld_Text_DealerOkayOkay
	closemessage
	release
	end

OutsideWorld_Script_Dealee::
	lock
	msgbox OutsideWorld_Text_Dealee, MSGBOX_DEFAULT
	closemessage
	release
	end

OutsideWorld_Text_Dealee:
	.string "C'mon man, you can't keep me\n"
	.string "waiting so long!\p"
	.string "My wife'll suspect something if I'm\n"
	.string "not home soon!$"

Speaker_Dodgy_Man:
	.string "Dodgy Man$"

OutsideWorld_Text_Dealer:
	.string "Oh hiiiiiiiii, {PLAYER}!\p"
	.string "You finally thinking of gettin' your\n"
	.string "first ever fix of the good stuff?$"

OutsideWorld_Text_SophieHellNo:
	.string "Heck no! Stop talking to me!$"

OutsideWorld_Text_DealerOkayOkay:
	.string "Okay, okay!\p"
	.string "Just know if you ever want the good-\n"
	.string "good, you know where to go!$"
	
OutsideWorld_Text_OldMan:
	.string "When I was a boy, this city was\n"
	.string "nothing more than a backwater\l"
	.string "village in a massive forest!\p"
	.string "Now NEW CELADON is the most beautiful\n"
	.string "city in the world!\p"
	.string "Oh, the forward march of progress is\n"
	.string "AMAZING!!!!!$"

OutsideWorld_Text_ToOldMan:
	.string "Whatever you say, grampa…$"

OutsideWorld_Text_YoungBoy:
	.string "IM BOOOOOORED I HATE THIS\p"
	.string "DAD BANNED ME FROM {COLOR GREEN}BETTER{COLOR DARK_GRAY} FOR A WEEK\p"
	.string "THERES NOTHING TO DO OUTSIDE THOUGH\p"
	.string "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA$"

OutsideWorld_Text_PurpleBoy:
	.string "Ever since {COLOR GREEN}BETTER{COLOR DARK_GRAY} figured out how to\n"
	.string "transfer essentials like groceries\l"
	.string "and meds through the PC, every store\l"
	.string "here has shuttered their doors.\p"
	.string "What about those of us who can't\n"
	.string "afford their subscription premiums?\p"
	.string "Are we just out of luck?$"

OutsideWorld_Text_BlueMan:
	.string "The storefronts here have been\n"
	.string "vacant for a full two months now!\p"
	.string "Can we at least get a convenience\n"
	.string "store?$"

OutsideWorld_Text_BaldMan:
	.string "Careful walking around all alone\n"
	.string "at night.\p"
	.string "You never know who might be lurking\n"
	.string "in these narrow alleyways.$"

Speaker_Youngster:
	.string "Youngster$"

Speaker_Little_Girl:
	.string "Little Girl$"

OutsideWorld_Text_LittleGirl1:
	.string "hey can i have a pokémon\n"
	.string "when i grow up?????$"

OutsideWorld_Text_Youngster:
	.string "I dunno. Maybe if you work hard\n"
	.string "at school, mom'll get you one!$"

OutsideWorld_Text_LittleGirl2:
	.string "but mom said she cant get one\n"
	.string "no matter what!\p"
	.string "DONT LIE TO ME!!!!$"

OutsideWorld_Text_Woman:
	.string "Aw man, I think I lost my keys!\p"
	.string "When'll any of my roommates get\n"
	.string "back home anyways!?\p"
	.string "There's like, five of 'em!$"

OutsideWorld_SophiePrologue1::
	.string "There's no point brooding any longer.\p"
	.string "It's late, you should get home. Meet in\n"
	.string "the Place, at work, when you can.\p"
	.string "At least that way, Lola won't be\n"
	.string "able to hear us talking about it.$"

OutsideWorld_MinhPrologue2::
	.string "…I don't know what we're going to do.$"

OutsideWorld_SophiePrologue3::
	.string "We're going to find out who's making\n"
	.string "fakes. And we're going to get evidence.$"

OutsideWorld_MinhPrologue4::
	.string "…Okay.\p"
	.string "Whoever it is, they work for {COLOR GREEN}BETTER{COLOR DARK_GRAY},\n"
	.string "and they've got artists.\p"
	.string "I'll ask around with my art friends.$"

OutsideWorld_SophiePrologue5::
	.string "Good plan. I'll see you tomorrow.\n"
	.string "Meet at work in the Place.$"



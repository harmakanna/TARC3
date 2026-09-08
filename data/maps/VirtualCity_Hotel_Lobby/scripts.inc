VirtualCity_Hotel_Lobby_MapScripts::
	.byte 0

VirtualCity_HotelLobby_EarlGray::
	lockall
	faceplayer
	returnqueststate QUEST_TEA
	switch VAR_RESULT
	case 1, VirtualCity_HotelLobby_EarlGrayActivate
	case 2, VirtualCity_HotelLobby_EarlGrayActive
	case 3, VirtualCity_HotelLobby_EarlGrayReward
	case 4, VirtualCity_HotelLobby_EarlGrayComplete
	releaseall
	end

VirtualCity_HotelLobby_EarlGrayActivate::
	npc_speak SP_NAME_EARL_GRAY, VirtualCity_HotelLobby_EarlGrayHmm
	player_speak VirtualCity_HotelLobby_Text_SophieIsSomethingUp
	call_if_set FLAG_FOUGHT_EARL_GRAY, VirtualCity_HotelLobby_EarlGrayActivateFought
	call_if_unset FLAG_FOUGHT_EARL_GRAY, VirtualCity_HotelLobby_EarlGrayActivateUnfought
	msgbox VirtualCity_HotelLobby_Text_EarlGrayThisBrute, MSGBOX_DEFAULT
	player_speak VirtualCity_HotelLobby_Text_SophieIsItWorthIt
	npc_speak SP_NAME_EARL_GRAY, VirtualCity_HotelLobby_Text_EarlGrayOfCourseItIs
	giveitem ITEM_LETTER
	playfanfare MUS_OBTAIN_ITEM
	setspeaker NULL
	message VirtualCity_HotelLobby_Text_ReceivedMessage
	waitfanfare
	player_speak VirtualCity_HotelLobby_Text_SophieConsiderItDone
	startquest QUEST_TEA
	releaseall
	end

VirtualCity_HotelLobby_EarlGrayActivateFought::
	npc_speak SP_NAME_EARL_GRAY, VirtualCity_HotelLobby_Text_EarlGrayTheGirlFromTheTournament
	return

VirtualCity_HotelLobby_EarlGrayActivateUnfought::
	npc_speak SP_NAME_EARL_GRAY, VirtualCity_HotelLobby_Text_EarlGrayJustAtTheRightTime
	return

VirtualCity_HotelLobby_EarlGrayActive::
	setspeaker SP_NAME_EARL_GRAY
	msgbox VirtualCity_HotelLobby_Text_EarlGrayActive, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_HotelLobby_EarlGrayReward::
	player_speak VirtualCity_HotelLobby_Text_SophieWhatWasThat
	npc_speak SP_NAME_EARL_GRAY, VirtualCity_HotelLobby_Text_EarlGrayThatWasAnOwn
	player_speak VirtualCity_HotelLobby_Text_SophieUncalledFor
	npc_speak SP_NAME_EARL_GRAY, VirtualCity_HotelLobby_Text_EarlGraySoItMayBe
	player_speak VirtualCity_HotelLobby_Text_SophieNoWayCoffee
	npc_speak SP_NAME_EARL_GRAY, VirtualCity_HotelLobby_Text_EarlGraySuchIsLife
	setspeaker NULL
	goto VirtualCity_HotelLobby_EarlGray_ReceiveDrateani
	end
	
VirtualCity_HotelLobby_EarlGray_ReceiveDrateani::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	givemon SPECIES_DRATINI, 50
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VirtualCity_HotelLobby_EarlGray_ReceiveDratiniParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VirtualCity_HotelLobby_EarlGray_ReceiveDratiniPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VirtualCity_HotelLobby_EarlGray_ReceiveDratiniParty::
	call VirtualCity_HotelLobby_EarlGray_ReceiveDratiniFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_HotelLobby_EarlGray_FinishReceivingDratini
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VirtualCity_HotelLobby_EarlGray_FinishReceivingDratini
	end

VirtualCity_HotelLobby_EarlGray_ReceiveDratiniPC::
	call VirtualCity_HotelLobby_EarlGray_ReceiveDratiniFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_HotelLobby_EarlGray_TransferDratiniToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VirtualCity_HotelLobby_EarlGray_TransferDratiniToPC
	end

VirtualCity_HotelLobby_EarlGray_TransferDratiniToPC::
	call Common_EventScript_TransferredToPC
	goto VirtualCity_HotelLobby_EarlGray_FinishReceivingDratini
	end

VirtualCity_HotelLobby_EarlGray_ReceiveDratiniFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_HotelLobby_Text_YouReceivedDrateani
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	return

VirtualCity_HotelLobby_EarlGray_FinishReceivingDratini::
	completequest QUEST_TEA
	releaseall
	end

VirtualCity_HotelLobby_EarlGrayComplete::
	goto_if_set FLAG_FOUGHT_EARL_GRAY, VirtualCity_HotelLobby_EarlGrayCompletePostFight
	setspeaker SP_NAME_EARL_GRAY
	msgbox VirtualCity_HotelLobby_Text_EarlGrayComplete, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_HotelLobby_EarlGrayCompletePostFight::
	setspeaker SP_NAME_EARL_GRAY
	msgbox VirtualCity_HotelLobby_Text_EarlGrayCompletePostQuest, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_HotelLobby_Receptionist::
	msgbox VirtualCity_HotelLobby_Text_Receptionist, MSGBOX_NPC
	end

VirtualCity_HotelLobby_EventScript_ElevatorIdol::
	msgbox VirtualCity_HotelLobby_Text_ElevatorIdol, MSGBOX_NPC
	end

VirtualCity_HotelLobby_EventScript_MachokeConvo::
	lockall
	speak LOCALID_ENAMORED_MAN, VirtualCity_HotelLobby_Text_EnamoredMan1, Speaker_EnamoredMan, DIR_SOUTH
	speak LOCALID_WISEMACHOKE, VirtualCity_HotelLobby_Text_WiseMachoke1, Speaker_Wise_Machoke, DIR_NORTH
	speak LOCALID_ENAMORED_MAN, VirtualCity_HotelLobby_Text_EnamoredMan2, Speaker_EnamoredMan, DIR_SOUTH
	speak LOCALID_WISEMACHOKE, VirtualCity_HotelLobby_Text_WiseMachoke2, Speaker_Wise_Machoke, DIR_NORTH
	closemessage
	releaseall
	end

VirtualCity_HotelLobby_EventScript_RedMan::
	msgbox VirtualCity_HotelLobby_Text_RedMan, MSGBOX_NPC
	end

VirtualCity_HotelLobby_Text_RedMan:
	.string "You gotta shell out the big bucks\n"
	.string "for the lower floors here!\p"
	.string "But boy, is it worth it to come\n"
	.string "back to an idol waiting hand over\l"
	.string "fist for you after a long day's work!$"

Speaker_EnamoredMan:
	.string "LovestruckLenny$"

Speaker_Wise_Machoke:
	.string "WiseMachoke442$"

VirtualCity_HotelLobby_Text_EnamoredMan1:
	.string "Man, that idol in the blue dress\n"
	.string "is such a CUTIE…\p"
	.string "Do you think I should shoot my\n"
	.string "shot with her?\p"
	.string "Oooooh, but how will the pink one at\n"
	.string "the elevator feel if I reject her as\l"
	.string "my personal assistant?\p"
	.string "Gosh, I just can't decide…$"

VirtualCity_HotelLobby_Text_WiseMachoke1:
	.string "My guy, don't be fooled!\p"
	.string "None of the idols are actual,\n"
	.string "in-the-flesh chicks! They're ALL AI!\p"
	.string "{COLOR GREEN}BETTER{COLOR DARK_GRAY} uses all these virtual robot\n"
	.string "girls to try and distract you from\l"
	.string "true happiness!$"

VirtualCity_HotelLobby_Text_EnamoredMan2:
	.string "Golly gee, thanks WiseMachoke!\p"
	.string "That's the last time I go lusting\n"
	.string "after AI girls!$"

VirtualCity_HotelLobby_Text_WiseMachoke2:
	.string "Stay strong, my friend,\n"
	.string "and always look out for number one!$"

VirtualCity_HotelLobby_Text_ElevatorIdol:
	.string "Sooo-rreeee!!! Only VIPs can\n"
	.string "use this elevator!\p"
	.string "BUUUUUT if you buy a VIP room in\n"
	.string "the next hour, you'll get me as a\l"
	.string "COMPLEMENTARY idol assistant for free!\l"
	.string "{FONT_SMALL}First month only.\p"
	.string "{FONT_NORMAL}Don't pass up this HOT deal!$"

VirtualCity_HotelLobby_EarlGrayHmm:
	.string "Hmm… What should I do…$"

VirtualCity_HotelLobby_Text_SophieIsSomethingUp:
	.string "Is something up?$"

VirtualCity_HotelLobby_Text_EarlGrayJustAtTheRightTime:
	.string "Aha! Just at the right time!\n"

VirtualCity_HotelLobby_Text_EarlGrayTheGirlFromTheTournament:
	.string "Ah, you're the girl from the\n"
	.string "tournament! Perhaps you can help!$"

VirtualCity_HotelLobby_Text_EarlGrayThisBrute:
	.string "There's this one brute with such\n"
	.string "horrid sensibilities who insulted\l"
	.string "me and my family name!\p"
	.string "I say, what a repulsive individual!\p"
	.string "I won't let HIM have the last\n"
	.string "laugh, if I can help it!$"

VirtualCity_HotelLobby_Text_SophieIsItWorthIt:
	.string "So, like, whaddya need me for?$"

VirtualCity_HotelLobby_Text_EarlGrayOfCourseItIs:
	.string "I need you to deliver a message\n"
	.string "for me to this Neanderthal\p"
	.string "He calls himself 'Cap'n Chino.'\p"
	.string "Take this and read it straight to\n"
	.string "his face!\p"
	.string "Please though, do not peek at the\n"
	.string "contents of this letter prior to\l"
	.string "confronting him.\p"
	.string "It is imperative you present it\n"
	.string "fully authentically!$"

VirtualCity_HotelLobby_Text_SophieConsiderItDone:
	.string "Consider it done.$"

VirtualCity_HotelLobby_Text_ReceivedMessage:
	.string "You received Earl Gray's message\n"
	.string "to Cap'n Chino!$"

VirtualCity_HotelLobby_Text_EarlGrayActive:
	.string "Go on then!\p"
	.string "That cretin should be in the\n"
	.string "Superstore at this hour.\p"
	.string "A vulgar display of consumerism,\n"
	.string "if you ask me.$"

VirtualCity_HotelLobby_Text_SophieWhatWasThat:
	.string "Hey, what the heck was that!?$"

VirtualCity_HotelLobby_Text_EarlGrayThatWasAnOwn:
	.string "That, my good friend, is what your\n"
	.string "generation calls {PAUSE 20}'an own!'$"
	
VirtualCity_HotelLobby_Text_SophieUncalledFor:
	.string "That was uncalled for!$"

VirtualCity_HotelLobby_Text_EarlGraySoItMayBe:
	.string "So it may be!\p"
	.string "Worry not! Now that I have the last\n"
	.string "laugh, you needn't worry about\l"
	.string "anything else from me!\p"
	.string "Unless you wish to join me with\n"
	.string "a cup of jasmine tea?$"

VirtualCity_HotelLobby_Text_SophieNoWayCoffee:
	.string "No way! I prefer coffee anyways!\p"
	.string "The flavor is richer…$"

VirtualCity_HotelLobby_Text_EarlGraySuchIsLife:
	.string "…Such is life, I suppose.\p"
	.string "Perhaps my faithful Drateani will\n"
	.string "slowly change your mind.\p"
	.string "Go on, then! He's yours!$"

VirtualCity_HotelLobby_Text_YouReceivedDrateani:
	.string "You were gifted Drateani!$"

VirtualCity_HotelLobby_Text_EarlGrayComplete:
	.string "HA! That blockhead never knew what\n"
	.string "hit him!\n"
	.string "That will show HIM to besmirch the\n"
	.string "Gray name!$"

VirtualCity_HotelLobby_Text_EarlGrayCompletePostQuest:
	.string "That'll show THAT blockhead to\n"
	.string "besmirch the Gray name!\p"
	.string "{PLAYER}, I wish you the best\n"
	.string "through the rest of the tournament!$"

VirtualCity_HotelLobby_Text_Receptionist:
	.string "Welcome to the {COLOR GREEN}BETTER {COLOR DARK_GRAY}Hotel!\p"
	.string "If you're looking for the stadium,\n"
	.string "head to the left.\p"
	.string "Your rooms will be through the\n"
	.string "right elevator.\p"
	.string "Your floor is:{PAUSE 30}\n"
	.string "FLOOR {PAUSE 45}42813130\p"
	.string "The center door is VIPs only.\p"
	.string "Purchase a VIP room for only{PAUSE 60}\n"
	.string "9{PAUSE 30}9{PAUSE 20}9{PAUSE 15}9{PAUSE 10}9{PAUSE 5}99999999.99!$"




VirtualCity_HotelLobby_HotelAutoscanner::
	lockall
	delay 10
	playse SE_CONTEST_MONS_TURN
	waitse
	setspeaker Speaker_Autoscanner
	msgbox VirtualCity_HotelLobby_Text_HotelAutoscanner, MSGBOX_NPC
	closemessage
	releaseall
	end

VirtualCity_HotelLobby_Text_HotelAutoscanner:
	.string "Scan Complete. Welcome, Sophie.\n"
	.string "Elevator Set To Floor 42813130.$"


VirtualCity_HotelLobby_HotelElevatorPanel::
	msgbox VirtualCity_HotelLobby_Text_HotelElevatorPanel, MSGBOX_NPC
	closemessage
	end

VirtualCity_HotelLobby_Text_HotelElevatorPanel:
	.string "Visiting A Friend?\n"
	.string "Input Custom Floor.$"
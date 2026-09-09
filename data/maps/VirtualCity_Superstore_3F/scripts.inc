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
	msgbox VirtualCity_Superstore_3F_Text_ExasperatedMan, MSGBOX_NPC
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




VirtualCity_Superstore_3F_EventScript_Idol::
	lockall
	speak LOCALID_SHOPKEEP_IDOL, VirtualCity_Superstore_3F_Text_Idol, NULL, DIR_SOUTH
	dynmultipush Store_Text_Choice1, 1
	dynmultipush Store_Text_Choice2, 2
	dynmultipush Store_Text_Choice3, 3
	dynmultipush Store_Text_Choice4, 4
	dynmultipush Store_Text_Choice5, 5
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	goto_if_eq VAR_RESULT, 1, VirtualCity_Superstore_3F_EventScript_Idol_Passimian
	goto_if_eq VAR_RESULT, 2, VirtualCity_Superstore_3F_EventScript_Idol_Sableye
	goto_if_eq VAR_RESULT, 3, VirtualCity_Superstore_3F_EventScript_Idol_Electrode
	goto_if_eq VAR_RESULT, 4, VirtualCity_Superstore_3F_EventScript_Idol_Snover
	goto_if_eq VAR_RESULT, 5, VirtualCity_Superstore_3F_EventScript_Idol_Solrock
	msgbox Store_Text_IdolByeBye, MSGBOX_DEFAULT
	closemessage
	releaseall
	end


VirtualCity_Superstore_3F_Text_Idol:
	.string "Hiiiiiiii cutie!\p"
	.string "Looks like the line for the new releases\n"
	.string "is serious business, huh?!\p"
	.string "But, if you're looking for the classics,\n"
	.string "I'm your girl!\p"
	.string "Which companion are you interested in?\n"
	.string "Besides me, of course!$"

Store_Text_Choice1:
	.string "Passimian$"

Store_Text_Choice2:
	.string "Sableye$"

Store_Text_Choice3:
	.string "Electrode$"

Store_Text_Choice4:
	.string "Snover$"

Store_Text_Choice5:
	.string "Solrock$"

Store_Text_IdolByeBye:
	.string "Nothing today?\p"
	.string "Aww…\nOh well…\p"
	.string "Bye-bye then!\nCome back soon!$"

VirtualCity_Superstore_3F_EventScript_Idol_Passimian::
	goto_if_set FLAG_BOUGHT_PASSIMIAN, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Passimian, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuyPassimian
	msgbox Store_Text_IdolByeBye, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuyPassimian::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_PASSIMIAN
	givemon SPECIES_PASSIMIAN, 50, nature=NATURE_JOLLY, abilityNum=1, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_PYRO_BALL, move2=MOVE_CLOSE_COMBAT, move3=MOVE_U_TURN, move4=MOVE_BULLDOZE, otName=OT_SoPhi99
	goto VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimian
	@add pass details TOFOLD
	end

VirtualCity_Superstore_3F_EventScript_Idol_Sableye::
	goto_if_set FLAG_BOUGHT_SABLEYE, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Sableye, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuySableye
	msgbox Store_Text_IdolByeBye, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuySableye::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_SABLEYE
	givemon SPECIES_SABLEYE, 50, nature=NATURE_CAREFUL, abilityNum=1, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_FOUL_PLAY, move2=MOVE_NIGHT_SHADE, move3=MOVE_PAIN_SPLIT, move4=MOVE_FAKE_OUT, otName=OT_SoPhi99
	goto VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableye
	@add pass details TOFOLD
	end


VirtualCity_Superstore_3F_EventScript_Idol_Electrode::
	goto_if_set FLAG_BOUGHT_ELECTRODE, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Electrode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuyElectrode
	msgbox Store_Text_IdolByeBye, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuyElectrode::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_ELECTRODE
	givemon SPECIES_ELECTRODE, 50, nature=NATURE_IMPISH, abilityNum=1, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_VOLT_SWITCH, move2=MOVE_THUNDER_WAVE, move3=MOVE_TORMENT, move4=MOVE_EXPLOSION, otName=OT_SoPhi99
	msgbox VirtualCity_Superstore_3F_Text_EnjoyIt, MSGBOX_NPC
	goto VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrode
	@add pass details TOFOLD
	end


VirtualCity_Superstore_3F_EventScript_Idol_Snover::
	goto_if_set FLAG_BOUGHT_SNOVER, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Snover, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuySnover
	msgbox Store_Text_IdolByeBye, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuySnover::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_SNOVER
	givemon SPECIES_SNOVER, 50, nature=NATURE_QUIET, abilityNum=1, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_BLIZZARD, move2=MOVE_GIGA_DRAIN, move3=MOVE_LEECH_SEED, move4=MOVE_WORRY_SEED, otName=OT_SoPhi99
	goto VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnover
	@add pass details TOFOLD
	end


VirtualCity_Superstore_3F_EventScript_Idol_Solrock::
	goto_if_set FLAG_BOUGHT_SOLROCK, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Solrock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuySolrock
	msgbox Store_Text_IdolByeBye, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuySolrock::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_SOLROCK
	givemon SPECIES_SOLROCK, 50, nature=NATURE_IMPISH, abilityNum=1, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_METEOR_MASH, move2=MOVE_ROCK_TOMB, move3=MOVE_MORNING_SUN, move4=MOVE_GRAVITY, otName=OT_SoPhi99
	goto VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrock
	@add pass details TOFOLD
	end


VirtualCity_Superstore_3F_Text_Passimian:
	.string "Excellent choice!\p"
	.string "Sassy Passy is a part of the Sportsman\n"
	.string "set, so it's got a new move and a boost\l"
	.string "to its Attack and Defense!\p"
	.string "Great for the sports fan in your life!\p"
	.string "That comes to 249999.99, but if you've\n"
	.string "got a coupon, we accept those too!\p"
	.string "Do you want Sportsman Passimian?$"

VirtualCity_Superstore_3F_Text_Sableye:
	.string "Oooh, cool!\p"
	.string "This Sableye is rocking some new shades\n"
	.string "and a serious boost to Dark moves!\p"
	.string "Dark Aura gives it offense and support!\p"
	.string "That comes to 219999.99, but if you've\n"
	.string "got a coupon, we accept those too!\p"
	.string "Do you want CoolBro Sableye?$"

VirtualCity_Superstore_3F_Text_Electrode:
	.string "Now this is a fun one!\p"
	.string "The UpsideDown set swaps offenses\n"
	.string "with defenses, and HP with Speed!\p"
	.string "So this speedster Electrode is now\n"
	.string "a powerful tank! Shocking!\p"
	.string "That comes to 249999.99, but if you've\n"
	.string "got a coupon, we accept those too!\p"
	.string "Do you want UpsideDown Electrode?$"

VirtualCity_Superstore_3F_Text_Snover:
	.string "Double weaknesses are such a pain!\p"
	.string "But the Immortal set turns that\n"
	.string "weakness into a strength!\p"
	.string "When your enemies see this Snover\n"
	.string "with Flash Fire, they'll know.\p"
	.string "It's so Snover!\p"
	.string "That comes to 199999.99, but if you've\n"
	.string "got a coupon, we accept those too!\p"
	.string "Do you want Immortal Snover?$"

VirtualCity_Superstore_3F_Text_Solrock:
	.string "This one's great!\p"
	.string "It's a Ninja set! And Solrock is a\n"
	.string "sharp throwing star!\p"
	.string "And of course, ninjas get a huge\n"
	.string "boost to their Speed!\p"
	.string "Beat em down with an Angry Sun!\p"
	.string "That comes to 219999.99, but if you've\n"
	.string "got a coupon, we accept those too!\p"
	.string "Do you want Ninja Solrock?$"



VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought::
	msgbox VirtualCity_Superstore_3F_Text_AlreadyBought, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
	
VirtualCity_Superstore_3F_Text_AlreadyBought:
	.string "Honey, you already bought one!$"

VirtualCity_Superstore_3F_EventScript_Idol_CantAfford::
	msgbox VirtualCity_Superstore_3F_Text_Idol_CantAfford, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_Superstore_3F_Text_Idol_CantAfford:
	.string "Sorry darling, you can't afford it!$"

VirtualCity_Superstore_3F_Text_EnjoyIt:
	.string "Done! You enjoy that, hun!$"




VirtualCity_Superstore_3F_EventScript_LowerIdol::
	goto_if_set FLAG_ACT_III_COMPLETE, VirtualCity_Superstore_3F_Eventscript_LowerIdol4
	goto_if_set FLAG_ACT_III_COMPLETE, VirtualCity_Superstore_3F_Eventscript_LowerIdol3
	goto_if_set FLAG_ACT_III_COMPLETE, VirtualCity_Superstore_3F_Eventscript_LowerIdol2
	msgbox VirtualCity_Superstore_3F_Text_LowerIdol1, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Superstore_3F_Eventscript_LowerIdol4::
	msgbox VirtualCity_Superstore_3F_Text_LowerIdol4, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Superstore_3F_Eventscript_LowerIdol3::
	msgbox VirtualCity_Superstore_3F_Text_LowerIdol3, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Superstore_3F_Eventscript_LowerIdol2::
	msgbox VirtualCity_Superstore_3F_Text_LowerIdol2, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Superstore_3F_Text_LowerIdol1:
	.string "Installing Updates - 24% Complete.$"

VirtualCity_Superstore_3F_Text_LowerIdol2:
	.string "Installing Updates - 41% Complete.$"

VirtualCity_Superstore_3F_Text_LowerIdol3:
	.string "Installing Updates - 43% Complete.$"

VirtualCity_Superstore_3F_Text_LowerIdol4:
	.string "Installing Updates - 68% Complete.$"

	
VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimian::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PASSIMIAN
	givemon SPECIES_PASSIMIAN, 50
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimianParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimianPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimianParty::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimianFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimianPC::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimianFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_TransferPassimianToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_TransferPassimianToPC
	end

VirtualCity_Superstore_3F_ShopkeepIdol_TransferPassimianToPC::
	call Common_EventScript_TransferredToPC
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceivePassimianFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Superstore_3F_Text_YouReceivedPassimian
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_PASSIMIAN
	return
	
VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableye::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SABLEYE
	givemon SPECIES_SABLEYE, 50
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableyeParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableyePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableyeParty::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableyeFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableyePC::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableyeFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_TransferSableyeToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_TransferSableyeToPC
	end

VirtualCity_Superstore_3F_ShopkeepIdol_TransferSableyeToPC::
	call Common_EventScript_TransferredToPC
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSableyeFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Superstore_3F_Text_YouReceivedSableye
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SABLEYE
	return

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrode::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ELECTRODE
	givemon SPECIES_ELECTRODE, 50
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrodeParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrodePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrodeParty::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrodeFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrodePC::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrodeFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_TransferElectrodeToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_TransferElectrodeToPC
	end

VirtualCity_Superstore_3F_ShopkeepIdol_TransferElectrodeToPC::
	call Common_EventScript_TransferredToPC
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveElectrodeFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Superstore_3F_Text_YouReceivedElectrode
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODE
	return
	
VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnover::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SNOVER
	givemon SPECIES_SNOVER, 50
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnoverParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnoverPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnoverParty::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnoverFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnoverPC::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnoverFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_TransferSnoverToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_TransferSnoverToPC
	end

VirtualCity_Superstore_3F_ShopkeepIdol_TransferSnoverToPC::
	call Common_EventScript_TransferredToPC
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSnoverFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Superstore_3F_Text_YouReceivedSnover
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SNOVER
	return

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrock::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SOLROCK
	givemon SPECIES_SOLROCK, 50
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrockParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrockPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrockParty::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrockFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrockPC::
	call VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrockFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_ShopkeepIdol_TransferSolrockToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VirtualCity_Superstore_3F_ShopkeepIdol_TransferSolrockToPC
	end

VirtualCity_Superstore_3F_ShopkeepIdol_TransferSolrockToPC::
	call Common_EventScript_TransferredToPC
	goto VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon
	end

VirtualCity_Superstore_3F_ShopkeepIdol_ReceiveSolrockFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message VirtualCity_Superstore_3F_Text_YouReceivedSolrock
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SOLROCK
	return

VirtualCity_Superstore_3F_ShopkeepIdol_FinishReceivingPokemon::
	msgbox VirtualCity_Superstore_3F_Text_EnjoyIt, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

VirtualCity_Superstore_3F_Text_YouReceivedPassimian:
	.string "You bought a Passimian!$"

VirtualCity_Superstore_3F_Text_YouReceivedSableye:
	.string "You bought a Sableye!$"

VirtualCity_Superstore_3F_Text_YouReceivedElectrode:
	.string "You bought a Electrode!$"

VirtualCity_Superstore_3F_Text_YouReceivedSnover:
	.string "You bought a Snover!$"

VirtualCity_Superstore_3F_Text_YouReceivedSolrock:
	.string "You bought a Solrock!$"
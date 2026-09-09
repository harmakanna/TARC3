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
	msgbox VirtualCity_Superstore_3F_Text_Idol, MSGBOX_NPC
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


VirtualCity_Superstore_3F_EventScript_Idol_Passimian::
	goto_if_set FLAG_BOUGHT_PASSIMIAN, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Passimian, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuyPassimian
	closemessage
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuyPassimian::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_PASSIMIAN
	givemon SPECIES_PASSIMIAN, 50, nature=NATURE_JOLLY, abilityNum=1, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_PYRO_BALL, move2=MOVE_CLOSE_COMBAT, move3=MOVE_U_TURN, move4=MOVE_BULLDOZE, otName=OT_SoPhi99

	@add pass details TOFOLD
	msgbox VirtualCity_Superstore_3F_Text_EnjoyIt, MSGBOX_NPC
	end

VirtualCity_Superstore_3F_EventScript_Idol_Sableye::
	goto_if_set FLAG_BOUGHT_SABLEYE, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Sableye, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuySableye
	closemessage
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuySableye::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_SABLEYE
	givemon SPECIES_SABLEYE, 50, nature=NATURE_CAREFUL, abilityNum=1, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_FOUL_PLAY, move2=MOVE_NIGHT_SHADE, move3=MOVE_PAIN_SPLIT, move4=MOVE_FAKE_OUT, otName=OT_SoPhi99

	@add pass details TOFOLD
	msgbox VirtualCity_Superstore_3F_Text_EnjoyIt, MSGBOX_NPC
	end


VirtualCity_Superstore_3F_EventScript_Idol_Electrode::
	goto_if_set FLAG_BOUGHT_ELECTRODE, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Electrode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuyElectrode
	closemessage
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuyElectrode::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_ELECTRODE
	givemon SPECIES_ELECTRODE, 50, nature=NATURE_IMPISH, abilityNum=1, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_VOLT_SWITCH, move2=MOVE_THUNDER_WAVE, move3=MOVE_TORMENT, move4=MOVE_EXPLOSION, otName=OT_SoPhi99
	msgbox VirtualCity_Superstore_3F_Text_EnjoyIt, MSGBOX_NPC
	end


VirtualCity_Superstore_3F_EventScript_Idol_Snover::
	goto_if_set FLAG_BOUGHT_SNOVER, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Snover, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuySnover
	closemessage
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuySnover::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_SNOVER
	givemon SPECIES_SNOVER, 50, nature=NATURE_QUIET, abilityNum=1, gender=MON_MALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_BLIZZARD, move2=MOVE_GIGA_DRAIN, move3=MOVE_LEECH_SEED, move4=MOVE_WORRY_SEED, otName=OT_SoPhi99
	@add pass details TOFOLD
	msgbox VirtualCity_Superstore_3F_Text_EnjoyIt, MSGBOX_NPC
	end


VirtualCity_Superstore_3F_EventScript_Idol_Solrock::
	goto_if_set FLAG_BOUGHT_SOLROCK, VirtualCity_Superstore_3F_EventScript_Idol_AlreadyBought
	msgbox VirtualCity_Superstore_3F_Text_Solrock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VirtualCity_Superstore_3F_EventScript_Idol_BuySolrock
	closemessage
	end

VirtualCity_Superstore_3F_EventScript_Idol_BuySolrock::
	removeitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, NO, VirtualCity_Superstore_3F_EventScript_Idol_CantAfford
	setflag FLAG_BOUGHT_SOLROCK
	givemon SPECIES_SOLROCK, 50, nature=NATURE_IMPISH, abilityNum=1, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_METEOR_MASH, move2=MOVE_ROCK_TOMB, move3=MOVE_MORNING_SUN, move4=MOVE_GRAVITY, otName=OT_SoPhi99
	@add pass details TOFOLD
	msgbox VirtualCity_Superstore_3F_Text_EnjoyIt, MSGBOX_NPC
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
	msgbox VirtualCity_Superstore_3F_Text_AlreadyBought, MSGBOX_NPC
	end
	
VirtualCity_Superstore_3F_Text_AlreadyBought:
	.string "Honey, you already bought one!$"

VirtualCity_Superstore_3F_EventScript_Idol_CantAfford::
	msgbox VirtualCity_Superstore_3F_Text_Idol_CantAfford, MSGBOX_NPC
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




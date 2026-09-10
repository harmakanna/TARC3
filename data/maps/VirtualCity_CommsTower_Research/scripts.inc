VirtualCity_CommsTower_Research_MapScripts::
	.byte 0




VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	speak LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger1, Speaker_Researcher, DIR_NORTH
	closemessage
	playse SE_PIN
	applymovement LOCALID_RESEARCHBOSS, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 50
	applymovement LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Move_ResearchBossTrigger1
	waitmovement
	speak LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger2, Speaker_Researcher, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger3, SP_NAME_PLAYER, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger4, Speaker_Researcher, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger5, SP_NAME_PLAYER, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_ARCANINE, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger6, Speaker_Researcher, DIR_NORTH
	closemessage
	@TOFOLD
	trainerbattle_nointro TRAINER_MISSY, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger7
	special HealPlayerParty

	speak OBJ_EVENT_ID_PLAYER, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger8, SP_NAME_PLAYER, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger9, Speaker_Researcher, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger10, SP_NAME_PLAYER, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger11, Speaker_Researcher, DIR_NORTH
	playse SE_SELECT
	speak OBJ_EVENT_ID_PLAYER, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger12, SP_NAME_PLAYER, DIR_SOUTH
	playse SE_SELECT
	speak LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger13, Speaker_Researcher, DIR_NORTH
	closemessage
	applymovement LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Move_ResearchBossTrigger2
	waitmovement
	setvar VAR_PETALBURG_CITY_STATE, 16
	end


VirtualCity_CommsTower_Research_Move_ResearchBossTrigger1:
	walk_left
	walk_left
	walk_up
	face_up
	step_end

VirtualCity_CommsTower_Research_Move_ResearchBossTrigger2:
	walk_down
	walk_right
	walk_right
	face_up
	step_end


VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger1:
	.string "About time you showed up, Brady.\p"
	.string "Enough gambling - get to work on\n"
	.string "those back legs.$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger2:
	.string "Hold up, you're not Brady!\p"
	.string "Aren't you that lady from Design?$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger3:
	.string "Well, I-$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger4:
	.string "What?! Wait, it's done!\p"
	.string "He finished working on it at the Casino?\n"
	.string "Now that's {COLOR GREEN}BETTER{COLOR DARK_GRAY} behavior right there.\p"
	.string "So, you've balanced it already, I assume?$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger5:
	.string "Actually, I-$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger6:
	.string "Come on then, let's see it!$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger7:
	.string "Did you give it an immunity?\p"
	.string "Also you mixed up the moveset. This is\n"
	.string "for the Hyperreal Set.$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger8:
	.string "The Hyperreal Set? What-$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger9:
	.string "Yeah, you know, back to basics.\n"
	.string "Everything like it would have been.\p"
	.string "This team's made tons of designs, but\n"
	.string "the release keeps getting delayed.$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger10:
	.string "Tons of designs? Why-$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger11:
	.string "Yeah, I swear Byron wants practically\n"
	.string "every POKéMON done this way.\p"
	.string "You don't know about it because they\n"
	.string "haven't needed to be balanced for-\p"
	.string "Hey, why did Brady give you this one\n"
	.string "to balance, anyway?\p"
	.string "This is a top secret release!$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger12:
	.string "I should, uh, probably fix the moveset.$"

VirtualCity_CommsTower_Research_Eventscript_ResearchBossTrigger13:
	.string "Yeah, sure. Ah, that Brady - two steps\n"
	.string "forward, one step back with that boy.$"




VirtualCity_CommsTower_Research_Eventscript_PonytaBall::
	player_speak VirtualCity_CommsTower_Research_Text_PonytaBall
	closemessage
	givemon SPECIES_PONYTA, 50, nature=NATURE_NAIVE, abilityNum=1, gender=MON_FEMALE, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_FLARE_BLITZ, move2=MOVE_WILD_CHARGE, move3=MOVE_DRILL_RUN, move4=MOVE_PROTECT, otName=OT_Research
	setflag FLAG_ACT_I_REAL_PONYTA_OBTAINED
	removeobject LOCALID_REAL_PONYTA_BALL
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_CommsTower_Research_Text_PonytaBall2, MSGBOX_NPC
	end

VirtualCity_CommsTower_Research_Text_PonytaBall:
	.string "Hmm, it's one of the Ponyta…\n"
	.string "This is the perfect evidence!$"

VirtualCity_CommsTower_Research_Text_PonytaBall2:
	.string "I should get back to the Design office\n"
	.string "to show this to Minh…\p"
	.string "And then, test it outside.$"


VirtualCity_CommsTower_Research_Eventscript_ResearchBoss::
	player_speak VirtualCity_CommsTower_Research_Text_ResearchBoss1
	playse SE_SELECT
	speak LOCALID_RESEARCHBOSS, VirtualCity_CommsTower_Research_Text_ResearchBoss2, Speaker_Researcher, DIR_NORTH
	closemessage
	end

VirtualCity_CommsTower_Research_Text_ResearchBoss1:
	.string "Um, have you seen this Ponyta-$"


VirtualCity_CommsTower_Research_Text_ResearchBoss2:
	.string "Hush! I've gotta finish this before\n"
	.string "Byron's check-in.\p"
	.string "Also, has anyone ever told you that\n"
	.string "you interrupt people a lot?$"

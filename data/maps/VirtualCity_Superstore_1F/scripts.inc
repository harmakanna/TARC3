VirtualCity_Superstore_1F_MapScripts::
	.byte 0

VirtualCity_Superstore1F_CapnChino::
	goto_if_set FLAG_DEFEATED_CAPN_CHINO, VirtualCity_Superstore1F_CapnChinoPostFight
	goto_if_quest_not_active QUEST_TEA, VirtualCity_Superstore1F_CapnChinoPreQuest
	lockall
	goto_if_set FLAG_PRESENTED_EARLS_MESSAGE, VirtualCity_Superstore1F_CapnChinoBackForMore
	player_speak VirtualCity_Superstore1F_Text_SophieHeyUhh
	npc_speak SP_NAME_CAPN_CHINO, VirtualCity_Superstore1F_Text_CapnChinoWhatsItToYa
	player_speak VirtualCity_Superstore1F_Text_SophieTeaBetter
	npc_speak SP_NAME_CAPN_CHINO, VirtualCity_Superstore1F_Text_CapnChinoWhyYouLittle
	setflag FLAG_PRESENTED_EARLS_MESSAGE
	removeitem ITEM_LETTER

@Fallthrough into next script
VirtualCity_Superstore1F_CapnChinoFight::
	trainerbattle_no_intro TRAINER_CAPN_CHINO, VirtualCity_Superstore1F_CapnChinoDefeated
	npc_speak SP_NAME_CAPN_CHINO, VirtualCity_Superstore1F_Text_CapnChinoLetMeBe
	questmenu QUEST_MENU_SET_REWARD, QUEST_TEA
	setflag FLAG_DEFEATED_CAPN_CHINO
	releaseall
	end

VirtualCity_Superstore1F_CapnChinoBackForMore::
	npc_speak SP_NAME_CAPN_CHINO, VirtualCity_Superstore1F_Text_CapnChinoBackForMore
	goto VirtualCity_Superstore1F_CapnChinoFight
	end

VirtualCity_Superstore1F_CapnChinoPostFight::
	setspeaker SP_NAME_CAPN_CHINO
	msgbox VirtualCity_Superstore1F_Text_CapnChinoPostFight, MSGBOX_NPC
	end

VirtualCity_Superstore1F_CapnChinoPreQuest::
	setspeaker SP_NAME_CAPN_CHINO
	msgbox VirtualCity_Superstore1F_Text_CapnChinoPreQuest, MSGBOX_NPC
	end

VirtualCity_Superstore1F_EventScript_Artist::
	msgbox VirtualCity_Superstore1F_Text_Artist, MSGBOX_NPC
	end

VirtualCity_Superstore1F_EventScript_Bard::
	msgbox VirtualCity_Superstore1F_Text_Bard, MSGBOX_NPC
	end

VirtualCity_Superstore1F_EventScript_BaristaIdol::
	msgbox VirtualCity_Superstore1F_Text_BaristaIdol, MSGBOX_NPC
	end

VirtualCity_Superstore1F_Text_BaristaIdol:
	.string "Hee hee! Let me fill you up with\n"
	.string "BETTER's top-of-its-class hot cocoa!\p"
	.string "The best treat to shop our truly\n"
	.string "SUPER store!$"

VirtualCity_Superstore1F_Text_Bard:
	.string "Oh, the hot chocolate here is\n"
	.string "absolutely SUBLIME!\p"
	.string "Don't let any cheapskate tell you\n"
	.string "it's trash! Give it a try!$"

VirtualCity_Superstore1F_Text_Artist:
	.string "What is this FILTH!?\p"
	.string "Can a man not enjoy a nice cup of\n"
	.string "hot chocolate!?\p"
	.string "The drinks here STINK!$"
	
VirtualCity_Superstore1F_CapnChinoDefeated:
	.string "Grrr…$"

VirtualCity_Superstore1F_Text_SophieHeyUhh:
	.string "Hey, uhh…\p"
	.string "Are you… {PAUSE 40}Cap'n Chino?$"

VirtualCity_Superstore1F_Text_CapnChinoWhatsItToYa:
	.string "Yeah, that's me.\n"
	.string "What's it to ya?$"

VirtualCity_Superstore1F_Text_SophieTeaBetter:
	.string "One second…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Teaaaa…{PAUSE 20} Is betterrrr…{PAUSE 20}\n"
	.string "Than coffee?\p"
	.string "And you can go guzzle a dumpster,\n"
	.string "you uncivilized buffoon………{PAUSE 30}???$"

VirtualCity_Superstore1F_Text_CapnChinoWhyYouLittle:
	.string "Why you little…\p"
	.string "I thought I was done with these stupid\n"
	.string "arguments, but that posh schmuk HAD\l"
	.string "to drag me back in!\p"
	.string "You want to say that to my face?\p"
	.string "Fine!\p"
	.string "Suck on this!$"

VirtualCity_Superstore1F_Text_CapnChinoBackForMore:
	.string "Argh, you're back for more, ye\n"
	.string "little mongrel?\p"
	.string "Fine! Eat this!$"
	
VirtualCity_Superstore1F_Text_CapnChinoLetMeBe:
	.string "I give, I give…\p"
	.string "Let me be, I'd sooner walk the plank\n"
	.string "than keep entertaining that midwit.$"
	
VirtualCity_Superstore1F_Text_CapnChinoPreQuest:
	.string "Bah! You'd think with such immense\n"
	.string "resources, Better could give something\l"
	.string "more than a middling taste to its\l"
	.string "cheaper brews!\p"
	.string "It's not like the beans are real!$"

VirtualCity_Superstore1F_Text_CapnChinoPostFight:
	.string "Don't think this battle proves\n"
	.string "anything, ya class traitor…\p"
	.string "Let me drink my macchiato\n"
	.string "in peace.$"
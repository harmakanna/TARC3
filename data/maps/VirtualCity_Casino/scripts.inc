VirtualCity_Casino_MapScripts::
	.byte 0


Speaker_Researcher:
	.string "Researcher$"

VirtualCity_Casino_Eventscript_Cluegiver1::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver1, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver2::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver2, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver3::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver3, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver4::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver4, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver5::
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver5, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_Eventscript_Cluegiver6::
	setflag FLAG_ACT_I_INFO_OBTAINED
	setspeaker Speaker_Researcher
	msgbox VirtualCity_Casino_Text_Cluegiver6, MSGBOX_SIGN
	closemessage
	end

VirtualCity_Casino_EventScript_Kumatora::
	msgbox VirtualCity_Casino_Text_Kumatora, MSGBOX_NPC

VirtualCity_Casino_Text_Kumatora:
	.string "Hi!$"
	
VirtualCity_Casino_Text_Cluegiver1:
	.string "…wish I could tell my daughter.\p"
	.string "It's been her favorite since she\n"
	.string "was a little girl!$"

VirtualCity_Casino_Text_Cluegiver2:
	.string "…the absolute worst type to make.\n"
	.string "The lighting effects alone!$"

VirtualCity_Casino_Text_Cluegiver3:
	.string "…most popular ones first, and that\n"
	.string "means old-school nostalgia.$"

VirtualCity_Casino_Text_Cluegiver4:
	.string "…no, no, everything's on schedule.\n"
	.string "It's just the hind legs left!$"

VirtualCity_Casino_Text_Cluegiver5:
	.string "…yeah, but be careful getting on its\n"
	.string "back - it's more suited to kids.$"

VirtualCity_Casino_Text_Cluegiver6:
	.string "…might even get banned from serious\n"
	.string "competitive play.$"


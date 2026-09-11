VirtualCity_CommsTower_TopF_MapScripts::
	.byte 0

Speaker_System::
	.string "SYSTEM$"


VirtualCity_CommsTower_TopF_EventScript_HackRotomPhone::
	fadeoutbgm 4
	@KUMATORA, got a song for the ending?
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_CommsTower_TopF_Text_HackRotomPhone1 MSGBOX_DEFAULT
	closemessage
	playse SE_PC_LOGIN
	waitse
	delay 40
	setspeaker Speaker_System
	msgbox VirtualCity_CommsTower_TopF_Text_HackRotomPhone2 MSGBOX_DEFAULT
	playse SE_PIN
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCity_CommsTower_TopF_Text_HackRotomPhone3 MSGBOX_DEFAULT
	playse SE_PIN
	setspeaker Speaker_System
	msgbox VirtualCity_CommsTower_TopF_Text_HackRotomPhone4 MSGBOX_DEFAULT
	fadescreenspeed FADE_TO_BLACK, 5
	delay 100
	playse SE_NOTE_G
	waitse
	playse SE_NOTE_C
	waitse
	playse SE_NOTE_E
	waitse
	playse SE_NOTE_D
	waitse
	setspeaker Speaker_Announcement
	msgbox VirtualCity_CommsTower_TopF_Text_HackRotomPhoneMessage, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	waitse
	delay 60
	callnative StartBetterPlaceCredits
	waitstate
	end




VirtualCity_CommsTower_TopF_Text_HackRotomPhone1::
	.string "I've made it.\p"
	.string "This is the control system for the\n"
	.string "whole {COLOR GREEN}BETTER Place{COLOR DARK_GRAY}.\p"
	.string "Wow. Indoor Weather. Hotel Occupancy.\n"
	.string "The Quanta System. Idol Control.\p"
	.string "Ah, there. Rotom Phone.\p"
	.string "Well, let's burn the Place down.$"

VirtualCity_CommsTower_TopF_Text_HackRotomPhone2::
	.string "Welcome, Byron.\n"
	.string "Confirm global message?$"

VirtualCity_CommsTower_TopF_Text_HackRotomPhone3::
	.string "Confirm.$"

VirtualCity_CommsTower_TopF_Text_HackRotomPhone4::
	.string "Message sent.$"


VirtualCity_CommsTower_TopF_Text_HackRotomPhoneMessage::
	.string "Attention, all {COLOR GREEN}BETTER Place{COLOR DARK_GRAY} residents.\p"
	.string "{COLOR GREEN}BETTER{COLOR DARK_GRAY} is manufacturing fake Pokemon\n"
	.string "and selling them to us as real.\p"
	.string "These Pokemon are made in {COLOR GREEN}BETTER{COLOR DARK_GRAY}'s\n"
	.string "Research dept, sent to a shell\l"
	.string "company posing as a farm or breeder,\l"
	.string "and then sold at exorbitant prices.\p"
	.string "Our activist collective was unable to\n"
	.string "determine how many breeders are real,\l"
	.string "if there are even any left.\p"
	.string "{COLOR GREEN}BETTER{COLOR DARK_GRAY}'s unethical practices may have\n"
	.string "led to widespread extinction.\p"
	.string "We, the DREAMS collective, urge you\n"
	.string "to demand the truth from {COLOR GREEN}BETTER{COLOR DARK_GRAY}.\p"
	.string "If there are still Pokemon in the wild…\n"
	.string "they deserve our help.\p"
	.string "They deserve better… than {COLOR GREEN}BETTER{COLOR DARK_GRAY}.\p"
	.string "Sincerely, DREAMS. End Message.$"

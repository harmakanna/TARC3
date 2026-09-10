OutsideWorld_Office_MapScripts::
	.byte 0

@@@@@@ Intro Cutscene @@@@@@

OutsideWorld_Office_Text_IntroTalk1::
	.string "You ready to go?\n"
	.string "I can't believe the day's finally come!\p"
	.string "Lola's gonna get that real POKéMON!\n"
	.string "How long has she been saving up for?$"

OutsideWorld_Office_Text_IntroTalk2::
	.string "Um… it's gotta be over ten years.\p"
	.string "All those times she skipped going\n"
	.string "out to dinner with us…\p"
	.string "And she never bought any virtual\n"
	.string "POKéMON - not even one.$"

OutsideWorld_Office_Text_IntroTalk3::
	.string "My grandma used to tell me stories\n"
	.string "about POKéMON being everywhere…\p"
	.string "Imagine, real POKéMON for free!$"

OutsideWorld_Office_Text_IntroTalk4::
	.string "I can't wait to see it. I bet it's\n"
	.string "nothing like the virtual POKéMON\p"
	.string "we're used to!$"

OutsideWorld_Office_Text_IntroTalk5::
	.string "Huh? Everyone's left work already!\p"
	.string "C'mon, Lola's probably waiting\n"
	.string "for us!$"





@@	OutsideWorld_Office_Text_IntroTalk1::
@@		.string "Today's the day.\p"
@@		.string "How long has she been saving up for?$"
@@	
@@	OutsideWorld_Office_Text_IntroTalk2::
@@		.string "It's gotta be over ten years.\p"
@@		.string "All those times she skipped going\n"
@@		.string "out to dinner with us...$"
@@	
@@	OutsideWorld_Office_Text_IntroTalk3::
@@		.string "She doesn't even have any VRmon.\n"
@@		.string "Not even one.\p"
@@		.string "\n"
@@		.string "Not even one.$"
@@	
@@	
@@	OutsideWorld_Office_Text_IntroBoss1::
@@		.string "Minh, I'm heading home now.\p"
@@		.string "How's the new Arcanine coming along?$"
@@	
@@	OutsideWorld_Office_Text_IntroBoss2::
@@		.string "I'm just finishing up the art now,\n"
@@		.string "and then Sophie'll add the buffs.$"
@@	
@@	OutsideWorld_Office_Text_IntroBoss3::
@@		.string "Don't skimp with the ability,\n"
@@		.string "Sophie. Make it exciting.\p"
@@		.string "I don't care about power creep, I care\n"
@@		.string "about people buying this POKéMON.$"
@@	
@@	OutsideWorld_Office_Text_IntroBoss4::
@@		.string "...Okay, boss.$"
@@		
@@	OutsideWorld_Office_Text_IntroBoss5::
@@		.string "Good. Send it to me when you're\n"
@@		.string "done, and I'll release it.$"
@@		.string "Minh! Today's the day!\p"
@@		.string "By the time I log on, I wanna see that\n"
@@		.string "Arcanine done.$"
@@		.string "Arthur's finishing up the art now,\n"
@@		.string "go find him and buff the stats.$"








@@@@@@ Desk @@@@@@


@@@@@@ Signs @@@@@@

OutsideWorld_Office_EventScript_Sign1::
	msgbox OutsideWorld_Office_Text_Sign1, MSGBOX_SIGN
	end

OutsideWorld_Office_EventScript_Sign2::
	msgbox OutsideWorld_Office_Text_Sign2, MSGBOX_SIGN
	end

OutsideWorld_Office_Text_Sign1::
	.string "REMINDER TO ALL EMPLOYEES\p"
	.string "All details of to-be-released VRmon\n"
	.string "are strictly confidential.\p"
	.string "Violators will be prosecuted.$"

OutsideWorld_Office_Text_Sign2::
	.string "VRmon - Dept of New Releases$"

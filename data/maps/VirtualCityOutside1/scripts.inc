VirtualCityOutside1_MapScripts::
	.byte 0

VirtualCityOutside_Act1_EarlGrayCapnChinoArgument::
	lockall
	speak LOCALID_ACTI_EARLGRAY, VirtualCity_Outside_Text_EarlGrayWhatAreYouOnAbout, NULL, DIR_EAST
	speak LOCALID_ACTI_CAPNCHINO, VirtualCity_Outside_Text_CapnChinoAllImSayin, NULL, DIR_WEST 
	speak LOCALID_ACTI_EARLGRAY, VirtualCity_Outside_Text_EarlGrayFroofyLeaves, NULL, DIR_EAST
	speak LOCALID_ACTI_CAPNCHINO, VirtualCity_Outside_Text_CapnChinoArgh, NULL, DIR_WEST 
	speak LOCALID_ACTI_EARLGRAY, VirtualCity_Outside_Text_EarlGrayBaboon, NULL, DIR_EAST
	speak LOCALID_ACTI_CAPNCHINO, VirtualCity_Outside_Text_CapnChinoBilgeRat, NULL, DIR_WEST 
	closemessage
	releaseall
	end

VirtualCityOutside_Sign_Casino::
	msgbox Sign_Casino_Text, MSGBOX_SIGN
	end

VirtualCityOutside_Sign_Garden::
	msgbox Sign_Garden_Text, MSGBOX_SIGN
	end

VirtualCityOutside_Sign_CommsTower::
	msgbox Sign_CommsTower_Text, MSGBOX_SIGN
	end

VirtualCityOutside_Sign_Shop::
	msgbox Sign_Shop_Text, MSGBOX_SIGN
	end
	
VirtualCityOutside_Sign_Hotel::
	msgbox Sign_Hotel_Text, MSGBOX_SIGN
	end

Speaker_CapnChino:
	.string "Cap'n Chino$"

Sign_Casino_Text:
	.string "Better Place Casino$"

Sign_Garden_Text:
	.string "Better Place Refuge$"

Sign_CommsTower_Text:
	.string "Better Place\n"
	.string "Office Tower$"

Sign_Shop_Text:
	.string "Better Place Superstore$"

Sign_Hotel_Text:
	.string "Better Place Hotel$"

VirtualCity_Outside_Text_EarlGrayWhatAreYouOnAbout:
	.string "What are you going on about,\n"
	.string "knave?\p"
	.string "Do you truly have no taste!?$"

VirtualCity_Outside_Text_CapnChinoAllImSayin:
	.string "TASTE!?\p"
	.string "Your froofy leaves have no\n"
	.string "taste!\p"
	.string "Stop trying to shove that weak\n"
	.string "trash down ev'ryone's gullet!$"

VirtualCity_Outside_Text_EarlGrayFroofyLeaves:
	.string "Why, I NEVER!\p"
	.string "Froofy leaves!? {PAUSE 50}WEAK TRASH!?!?\p"
	.string "Your unrefined derriere wouldn't\n"
	.string "know trash if it was digging through\l"
	.string "the dumpster!\p"
	.string "Or guzzling from one, for that\n"
	.string "matter.$"

VirtualCity_Outside_Text_CapnChinoArgh:
	.string "Argh, there's nothin' worse than a\n"
	.string "high and mighty fat cat sitting on\l"
	.string "his perch!\p"
	.string "Or has the Gray name gotten to your\n"
	.string "head so much you thing you're\l"
	.string "diff'rint to us proles?"
	.string "Come down to Earth and get with the\n"
	.string "the times, you idiot!$"
	
VirtualCity_Outside_Text_EarlGrayBaboon:
	.string "Raaaah!\p"
	.string "Insolent baboon!$"

VirtualCity_Outside_Text_CapnChinoBilgeRat:
	.string "Putrid bilge rat!$"
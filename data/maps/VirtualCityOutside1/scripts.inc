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

VirtualCityOutside_EventScript_Triangle::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_TriangleSpoof
	msgbox VirtualCityOutside_Text_Triangle, MSGBOX_NPC
	end
	
VirtualCityOutside_EventScript_TriangleSpoof::
	msgbox VirtualCityOutside_Text_TriangleSpoof, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_Doppelganger1::
	lock
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_Doppelganger1Spoof
	msgbox VirtualCityOutside_Text_Doppelganger1, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VirtualCityOutside_EventScript_Doppelganger1Spoof::	
	msgbox VirtualCityOutside_Text_Doppelganger1Spoof, MSGBOX_DEFAULT
	closemessage
	release
	end

VirtualCityOutside_EventScript_Doppelganger2::
	lock
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_Doppelganger2Spoof
	msgbox VirtualCityOutside_Text_Doppelganger2, MSGBOX_DEFAULT
	closemessage
	release
	end

VirtualCityOutside_EventScript_Doppelganger2Spoof::
	msgbox VirtualCityOutside_Text_Doppelganger2Spoof, MSGBOX_DEFAULT
	closemessage
	release
	end

VirtualCityOutside_EventScript_StorePikachu::
	goto_if_ge VAR_VIRTUAL_CITY_OUTSIDE_STATE, 1, VirtualCityOutside_EventScript_StorePikachuSpoof
	msgbox VirtualCityOutside_Text_StorePikachu, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_StorePikachuSpoof::
	msgbox VirtualCityOutside_Text_StorePikachuSpoof, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_TopCharizard::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_CharizardSpoof
	msgbox VirtualCityOutside_Text_TopCharizard, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_BottomCharizard::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_CharizardSpoof
	msgbox VirtualCityOutside_Text_BottomCharizard, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_CharizardSpoof::
	msgbox VirtualCityOutside_Text_CharizardSpoof, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_Mimikyu::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_MimikyuSpoof
	msgbox VirtualCityOutside_Text_Mimikyu, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_MimikyuSpoof::
	msgbox VirtualCityOutside_Text_MimikyuSpoof, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_Eevee::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_EeveeSpoof
	msgbox VirtualCityOutside_Text_Eevee, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_EeveeSpoof::
	msgbox VirtualCityOutside_Text_EeveeSpoof, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_PlatformPikachu::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_PlatformPikachuSpoof
	msgbox VirtualCityOutside_Text_PlatformPikachu, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_PlatformPikachuSpoof::
	msgbox VirtualCityOutside_Text_PlatformPikachuSpoof, MSGBOX_NPC
	end
	
VirtualCityOutside_EventScript_Giratina::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GIRATINA, CRY_MODE_NORMAL
	setspeaker Speaker_Giratina
	msgbox VirtualCityOutside_Text_Giratina, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

VirtualCityOutside_EventScript_CenterIdol::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_IdolError
	msgbox VirtualCityOutside_Text_CenterIdol, MSGBOX_NPC
	end
	
VirtualCityOutside_EventScript_RightIdol::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_IdolError
	msgbox VirtualCityOutside_Text_RightIdol, MSGBOX_NPC
	end
	
VirtualCityOutside_EventScript_LeftIdol::
	goto_if_set FLAG_SPOOFING_EXECUTIVE, VirtualCityOutside_EventScript_IdolError
	msgbox VirtualCityOutside_Text_LeftIdol, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_IdolError::
	msgbox VirtualCityOutside_Text_IdolError, MSGBOX_NPC
	end

VirtualCityOutside_EventScript_SophieNowsNotTheTime::
	lockall
	setspeaker SP_NAME_PLAYER
	msgbox VirtualCityOutside_Text_SophieNowsNotTheTime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

VirtualCityOutside_Text_SophieNowsNotTheTime:
	.string "Now's not the time for this!$"

VirtualCityOutside_Text_IdolError:
	.string "-ERROR-\n"
	.string "-UNRECOGNIZED ENTITY-$"

VirtualCityOutside_Text_CenterIdol:
	.string "Hiiiiiii!\n"
	.string "Welcome to the {COLOR GREEN}BETTER PLACE!\p"
	.string "{COLOR DARK_GRAY}Make sure to sign up soon for\n"
	.string "our next tournament extravaganza!\p"
	.string "Test your mettle against all the\n"
	.string "strongest trainers in the Place!$"

VirtualCityOutside_Text_RightIdol:
	.string "Yooooo!\n"
	.string "What's up!\p"
	.string "Ready for a night on the town?\n"
	.string "You won't believe what {COLOR GREEN}BETTER{COLOR DARK_GRAY} just\l"
	.string "dropped on us!\p"
	.string "We GOTTA check out the supershop for\n"
	.string "their new UPSIDE-DOWN POKéMON\l"
	.string "MYSTERY BOXES!!!!\p"
	.string "Don't keep me waiting!$"

VirtualCityOutside_Text_LeftIdol:
	.string "Hey bestie!!!!\p"
	.string "The casino's waitin'! How 'bout I\n"
	.string "meet you there for a quick round\l"
	.string "of Hold'em to start the day?$"
	
Speaker_Giratina:
	.string "Gitarita$"

VirtualCityOutside_Text_Giratina:
	.string "GRAAAAAAAAAAAAAAH$"

VirtualCityOutside_Text_EeveeSpoof:
	.string "HEY LETS BATTLE STRANGE PIXELLY\n"
	.string "MASS!!!$"

VirtualCityOutside_Text_Eevee:
	.string "HEY LETS BATTLE MISS!!!$"

VirtualCityOutside_Text_PlatformPikachuSpoof:
	.string "WHOOAAAAAA ARE YOU A NEW VIRTUAL\n"
	.string "POKEMON?????\p"
	.string "SPOOKY GHOST USE ASTRAL BARRAGE!!!$"

VirtualCityOutside_Text_PlatformPikachu:
	.string "ITS SO COOL WE GET TO DO REAL\n"
	.string "LIVE POKéMON BATTLES HERE!!!\p"
	.string "GITARITA USE DRACO METEOR MASH!!!$"

VirtualCityOutside_Text_Mimikyu:
	.string "Yo, your skin is SOOOO COOL!\p"
	.string "How much did you pay for it?\p"
	.string "Or is it an exclusive skin?\p"
	.string "You gotta tell me!$"

VirtualCityOutside_Text_MimikyuSpoof:
	.string "YOOOOOO! Where can I get a RAD\n"
	.string "EFFECT like that!?\p"
	.string "You GOTTA tell me!$"

VirtualCityOutside_Text_BottomCharizard:
	.string "One of those two Reds asked me to\n"
	.string "cosplay with him, but I don't\l"
	.string "remember which…\p"
	.string "Oh well. RAAAAAAAH!!!$"

VirtualCityOutside_Text_TopCharizard:
	.string "RAAAAH! RAAAAAH!\p"
	.string "RAAAAAAAAAAAAAAAAAAAAH!$"

VirtualCityOutside_Text_CharizardSpoof:
	.string "Uhhhh… Raaaaaaah?$"

VirtualCityOutside_Text_StorePikachu:
	.string "my pappa said wait outside while\n"
	.string "while he got food cuz i keep\l"
	.string "asking for things\p"
	.string "ive been here twenty minutes\p"
	.string "where is he help$"

VirtualCityOutside_Text_StorePikachuSpoof:
	.string "ive been here SEVEN HOURS\p"
	.string "HELP$"

VirtualCityOutside_Text_Doppelganger1:
	.string "Oy, you copycat!\n"
	.string "Stop usin' my avatar!\p"
	.string "I paid a LOT on mystery boxes for\n"
	.string "this limited-run Red skin!$"

VirtualCityOutside_Text_Doppelganger2:
	.string "No, you stole MY skin!\n"
	.string "Stop crampin' my styyyyle!\p"
	.string "I'm the original Red!\n"
	.string "You wanna fight over it?$"


VirtualCityOutside_Text_Doppelganger1Spoof:
	.string "{FONT_SMALL}You think it'll go away if\n"
	.string "we like…{PAUSE 50} don't move…?$"

VirtualCityOutside_Text_Doppelganger2Spoof:
	.string "{FONT_SMALL}I dunno man, that thing is\n"
	.string "REALLY freakin' me out…!$"

VirtualCityOutside_Text_TriangleSpoof:
	.string "Man, what a WACKY avatar!!!\p"
	.string "You got me beat!$"

VirtualCityOutside_Text_Triangle:
	.string "You'll never know what wacky\n"
	.string "avatar you'll find in {COLOR GREEN}BETTER!\p"
	.string "{COLOR DARK_GRAY}Some people have been around a\n"
	.string "long time and got some real rare\l"
	.string "skins from the early days!\p"
	.string "You can always buy 'em on the\n"
	.string "{COLOR GREEN}BETTER{COLOR DARK_GRAY} user marketplace, but good\l"
	.string "luck if you ain't loaded!$"

Speaker_CapnChino:
	.string "Cap'n Chino$"

Sign_Casino_Text:
	.string "{COLOR GREEN}BETTER{COLOR DARK_GRAY}'s Better's Paradise!\p"
	.string "Games and Performances Every Night!\n"	
	.string "A Casino for All Ages!$"

Sign_Garden_Text:
	.string "The {COLOR GREEN}BETTER{COLOR DARK_GRAY} Refuge\p"
	.string "New Environments Every Week!\n"
	.string "Nature Has Never Been So Real!$"

Sign_CommsTower_Text:
	.string "The {COLOR GREEN}BETTER{COLOR DARK_GRAY} Office Tower\p"
	.string "We Make The World {COLOR GREEN}BETTER{COLOR DARK_GRAY}!\n"
	.string "Help Us Make Reality Real!$"

Sign_Shop_Text:
	.string "The {COLOR GREEN}BETTER{COLOR DARK_GRAY} Cafe and Superstore\p"
	.string "Everything You Could Ever Want!\n"
	.string "And, You Can Afford It Here!$"

Sign_Hotel_Text:
	.string "The Grand {COLOR GREEN}BETTER{COLOR DARK_GRAY} Hotel and Stadium\p"
	.string "An Infinite Number of Rooms!\n"
	.string "A Place To Call Home!\l"
	.string "And The Only Spot For POKéMON Battles!$"


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
	.string "Or has the Grey name gotten to your\n"
	.string "head so much you think you're\l"
	.string "diff'rint to us proles?\p"
	.string "Come down to Earth and get with the\n"
	.string "the times, you idiot!$"
	
VirtualCity_Outside_Text_EarlGrayBaboon:
	.string "Raaaah!\p"
	.string "Insolent baboon!$"

VirtualCity_Outside_Text_CapnChinoBilgeRat:
	.string "Putrid bilge rat!$"
OutsideWorld_ApartmentBldg1_YourApartment_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OutsideWorld_ApartmentBldg1_YourApartment_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OutsideWorld_ApartmentBldg1_YourApartment_OnFrame
	.byte 0

OutsideWorld_ApartmentBldg1_YourApartment_OnTransition:
	@goto_if_set FLAG_PROLOGUE_COMPLETE, OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_NotFirstLoad
	@setvar VAR_PETALBURG_CITY_STATE, 10
	end


OutsideWorld_ApartmentBldg1_YourApartment_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_PrologueEndScene
	.2byte 0


OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_PrologueEndScene::
	playse SE_DOOR
	applymovement LOCALID_MINH, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk1Minh, Speaker_Minh, DIR_WEST
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh1
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie1
	waitmovement
	applymovement LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet1
	playse SE_LEDGE
	waitse
	waitmovement
	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk2Harriet, Speaker_Harriet, DIR_WEST
	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk3Ernest, Speaker_Ernest, DIR_NORTH
	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk4Lola, Speaker_Lola, DIR_SOUTH
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh2
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie2
	applymovement LOCALID_HARRIET, Common_Movement_FaceUp
	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk5Lola, Speaker_Lola, DIR_SOUTH

	addobject LOCALID_SNUBBULLS_BALL
	delay 10
	playse SE_BALL_OPEN
	removeobject LOCALID_SNUBBULLS_BALL
	addobject LOCALID_SNUBBULL
	applymovement LOCALID_MINH, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_HARRIET, Common_Movement_ExclamationMark
	applymovement LOCALID_ERNEST, Common_Movement_ExclamationMark
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_ENCOUNTER
	delay 40

	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk6Lola, Speaker_Lola, DIR_SOUTH
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh3
	applymovement LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet2
	waitmovement
    applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest1
	waitmovement
	applymovement LOCALID_HARRIET, Common_Movement_Heart

	applymovement LOCALID_SNUBBULL, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet1
	playse SE_LEDGE
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_ENCOUNTER
	delay 30

	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk7Harriet, Speaker_Harriet, DIR_WEST
	applymovement LOCALID_SNUBBULL, Common_Movement_Heart
	applymovement LOCALID_MINH, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh4
	waitmovement
	delay 30
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh5
	waitmovement
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest2


	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk8Ernest, Speaker_Ernest, DIR_NORTH
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh6
	waitmovement

	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk9Lola, Speaker_Lola, DIR_SOUTH
	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk10Lola, Speaker_Lola, DIR_SOUTH
	applymovement LOCALID_HARRIET, Common_Movement_FaceLeft
	applymovement LOCALID_ERNEST, Common_Movement_FaceLeft
	applymovement LOCALID_LOLA, Common_Movement_FaceLeft

	applymovement LOCALID_MINH, Common_Movement_FaceRight
	delay 20
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest3


	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk11Minh, Speaker_Minh, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk12Sophie, Speaker_Sophie, DIR_EAST
	applymovement LOCALID_HARRIET, Common_Movement_QuestionMark
	applymovement LOCALID_ERNEST, Common_Movement_QuestionMark

	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk13Lola, Speaker_Lola, DIR_SOUTH
	applymovement LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Move_Lola1
	applymovement LOCALID_SNUBBULL, OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull1
	delay 10
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh7

	speak LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk14Lola, Speaker_Lola, DIR_SOUTH
	applymovement LOCALID_LOLA, OutsideWorld_ApartmentBldg1_YourApartment_Move_Lola2
	applymovement LOCALID_SNUBBULL, OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull2
	delay 16
	removeobject LOCALID_LOLA
	playse SE_DOOR
	delay 8
	removeobject LOCALID_SNUBBULL
	playse SE_DOOR

	delay 20

	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh8
	applymovement LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet3
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie3
	waitmovement
	delay 30
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest4
	waitmovement

	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk15Harriet, Speaker_Harriet, DIR_NORTH
	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk16Ernest, Speaker_Ernest, DIR_NORTH
	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk17Ernest, Speaker_Ernest, DIR_NORTH
	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk18Minh, Speaker_Minh, DIR_WEST


	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk19Sophie, Speaker_Sophie, DIR_SOUTH
	speak LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk20Harriet, Speaker_Harriet, DIR_NORTH
	applymovement LOCALID_ERNEST, Common_Movement_FaceLeft
	applymovement LOCALID_HARRIET, OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet4
	delay 40
	removeobject LOCALID_HARRIET
	playse SE_DOOR
	delay 10

	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk21Ernest, Speaker_Ernest, DIR_NORTH
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest5
	waitmovement
	delay 50

	speak LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk21pt5Ernest, Speaker_Ernest, DIR_EAST
	applymovement LOCALID_ERNEST, OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest6
	delay 10
	removeobject LOCALID_ERNEST
	playse SE_DOOR
	delay 20


	@Discuss with Minh
	applymovement LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh9
	waitmovement

	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk22Minh, Speaker_Minh, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie4
	waitmovement

	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk23Sophie, Speaker_Sophie, DIR_EAST
	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk24Minh, Speaker_Minh, DIR_WEST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk25Sophie, Speaker_Sophie, DIR_EAST
	speak LOCALID_MINH, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk26Minh, Speaker_Minh, DIR_WEST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk27Sophie, Speaker_Sophie, DIR_EAST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk28Sophie, Speaker_Sophie, DIR_WEST
	speak OBJ_EVENT_ID_PLAYER, OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk29Sophie, Speaker_Sophie, DIR_EAST
	delay 50
	fadescreenspeed FADE_TO_BLACK 5
	setvar VAR_PETALBURG_CITY_STATE, 3
	warpsilent MAP_OUTSIDE_WORLD, 22, 20
	delay 100

	
	end








OutsideWorld_ApartmentBldg1_YourApartment_Eventscript_NotFirstLoad::



	end



OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh2:
	walk_right
	walk_down
	walk_down
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh3:
	walk_up
	walk_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh4:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh5:
	walk_up
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh6:
	face_left
	delay_16
	delay_16
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh7:
	walk_left
	face_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh8:
	walk_right
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Minh9:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie1:
	walk_right
	walk_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie2:
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie3:
	walk_up
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Sophie4:
	walk_down
	walk_right
	walk_right
	step_end


OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet1:
	jump_in_place_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet2:
	walk_up
	face_left
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet3:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Harriet4:
	walk_left
	walk_left
	walk_down
	step_end



OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest1:
	walk_up
	face_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest2:
	walk_up
	walk_right
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest3:
	walk_left
	walk_down
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest4:
	walk_up
	face_up
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest5:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Ernest6:
	walk_down
	step_end


OutsideWorld_ApartmentBldg1_YourApartment_Move_Lola1:
	walk_down
	walk_left
	walk_left
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Lola2:
	walk_up
	walk_up
	step_end	


OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull1:
	walk_up
	walk_down
	walk_left
	step_end

OutsideWorld_ApartmentBldg1_YourApartment_Move_Snubbull2:
	walk_left
	walk_up
	walk_up
	step_end



OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk1Minh::
	.string "Hey, sorry we're late!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk2Harriet::
	.string "Aaah, finally! Lola, come on, we've\n"
	.string "been waiting for so long!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk3Ernest::
	.string "To be fair… she's been waiting…\n"
	.string "for twenty-two… years.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk4Lola::
	.string "…\p"
	.string "It's been a long time.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk5Lola::
	.string "You all know better than anyone how\n"
	.string "much I wanted a real Pokemon.\p"
	.string "So many people called it a stupid,\n"
	.string "unrealistic dream.\p"
	.string "Back then, I couldn't explain why it\n" 
	.string "felt so… so necessary.\p"
	.string "Well, I still can't explain it.\n"
	.string "But look at him!$"
	
OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk6Lola::
	.string "Go on, pet him! Like you would a\n"
	.string "VR Pokemon. He's super friendly!\p"
	.string "And you'll understand it.\n"
	.string "Why real Pokemon are so important.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk7Harriet::
	.string "OMG he's so precious! And warm!\n"
	.string "His fur feels like a blanket!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk8Ernest::
	.string "What's… his name, Lola?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk9Lola::
	.string "Dreams. Dreams the Snubbull.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk10Lola::
	.string "Hey, don't be shy, you two!\p"
	.string "You're all going to be his aunts and\n"
	.string "uncles, come say hi!$"


OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk11Minh::
	.string "…\p"
	.string "Um, hi there Dreams. Lola's going to\n"
	.string "take very good care of you!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk12Sophie::
	.string "Yes, she will. It…\n"
	.string "Ahem, welcome to our little group?$"	


OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk13Lola::
	.string "Don't worry, Dreams, I'm sure they'll\n"
	.string "be less shy tomorrow. Now come on,\l"
	.string "you haven't even seen our room yet!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk14Lola::
	.string "Goodnight! See y'all tomorrow!$"




OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk15Harriet::
	.string "It was so cute! And I've never seen\n"
	.string "Lola so happy!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk16Ernest::
	.string "No one deserves it more than Lola.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk17Ernest::
	.string "Hey, what's the matter? Minh? Sophie?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk18Minh::
	.string "Sophie? You…$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk19Sophie::
	.string "It's nothing.\n"
	.string "We've just had a long day at work.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk20Harriet::
	.string "Ah, no worries. Anyways, I gotta jet.\n"
	.string "Let's celebrate with Lola tomorrow!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk21Ernest::
	.string "Hm.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk21pt5Ernest::
	.string "I know something's up.\n"
	.string "Tell me about it later.$"


OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk22Minh::
	.string "Sophie? You… you saw it too?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk23Sophie::
	.string "I saw it.\p"
	.string "There's… there's no doubt.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk24Minh::
	.string "The eyes… they were wrong.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk25Sophie::
	.string "The mouth, too.\p"
	.string "That's… that's not a real Snubbull.\p"
	.string "It looked… drawn.\p"
	.string "Like the VR Pokemon you design…\n"
	.string "but not as skillful.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk26Minh::
	.string "Are you saying… does BETTER have a\n"
	.string "way to make fake IRL Pokemon?!\p"
	.string "And Lola just spent her life savings\n"
	.string "on one, thinking it was real?!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk27Sophie::
	.string "Minh, hush!\n"
	.string "The walls aren't that thick.\p"
	.string "And… there's something here even\n"
	.string "worse than Lola getting scammed.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk28Sophie::
	.string "We haven't seen any Pokemon in years.\n"
	.string "Real ones, I mean.\p"
	.string "And when we see one, it's a fake.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_IntroTalk29Sophie::
	.string "Minh…\p"
	.string "Are there even any real Pokemon left?$"






@@ ACT II INTRO

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro1::
	.string "Harriet. Ernest. Thanks for coming.\n"
	.string "We don't have long until Lola gets home.\p"
	.string "Minh and I have some news.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_ErnestActIIIntro2::
	.string "What, are you dating?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro3::
	.string "What? No!\n"
	.string "It's very bad news, Ernest!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro4::
	.string "What? What is it?\n"
	.string "Sophie, you're shaking!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro5::
	.string "When Lola showed us her Snubbull, Minh\n"
	.string "and I both noticed something wrong.\p"
	.string "So we did some digging… and…$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro6::
	.string "What? You got one? How did you afford…$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_HarrietActIIIntro7::
	.string "Aaaah! What is… Why is it unfinished?!$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_MinhActIIIntro8::
	.string "Because it's not real. BETTER has a way\n"
	.string "to make IRL fakes now, somehow.\p"
	.string "And they're being sold as real.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_ErnestActIIIntro9::
	.string "Fakes? You mean, Lola's Snubbull isn't\n"
	.string "a real flesh-and-blood Pokemon?$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro10::
	.string "Yeah. And Minh and I are going to do\n"
	.string "something about it.$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_MinhActIIIntro11::
	.string "What Sophie means is that she wanted\n"
	.string "to go in guns blazing.\p"
	.string "I managed to convince her that you two\n"
	.string "would want to help.\p"
	.string "(And help me stop her from doing\n"
	.string "something really dangerous.)$"

OutsideWorld_ApartmentBldg1_YourApartment_Text_SophieActIIIntro12::
	.string "We can't talk here, Lola's gonna be back\n"
	.string "soon. Meet at my place in the Realm.$"







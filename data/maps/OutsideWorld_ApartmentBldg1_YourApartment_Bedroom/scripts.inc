OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_MapScripts::
	.byte 0




OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_PC::
	lockall
	goto_if_eq VAR_PETALBURG_CITY_STATE, 2, OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_NoVRNow
	@many more situations where you need to disable this temporarily TOFOLD
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_Eventscript_Cancel
	closemessage
	@@ Fancy transition TOFOLD
	warp MAP_VIRTUAL_CITY_OUTSIDE1, 24, 24
	waitstate
	end

Common_Eventscript_Cancel::
	closemessage
	releaseall
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_PC:
	.string "Enter VR?$"


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_NoVRNow::
	setspeaker Speaker_Sophie
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_NoVRNow, MSGBOX_SIGN
	closemessage
	end


OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_NoVRNow:
	.string "I shouldn't go to the Place now.$"

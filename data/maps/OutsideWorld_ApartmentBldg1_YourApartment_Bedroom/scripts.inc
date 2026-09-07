OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_MapScripts::
	.byte 0




OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Eventscript_Sign::
	lockall
	msgbox OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_Sign, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_Eventscript_Cancel

	@@ Fancy transition TOFOLD
	entervr_warp MAP_VIRTUAL_CITY_OUTSIDE1, 24, 24
	waitstate
	end

Common_Eventscript_Cancel::
	closemessage
	releaseall
	end

OutsideWorld_ApartmentBldg1_YourApartment_Bedroom_Text_Sign:
	.string "Enter VR?$"







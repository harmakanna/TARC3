VirtualCityOutside1_MapScripts::
	.byte 0

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

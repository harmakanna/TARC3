VirtualCity_Hotel_YourHallway_MapScripts::
	.byte 0

VirtualCity_Hotel_YourHallway_EventScript_WaitingMan::
	msgbox VirtualCity_Hotel_YourHallway_Text_WaitingMan, MSGBOX_NPC
	end

VirtualCity_Hotel_YourHallway_EventScript_Lass::
	msgbox VirtualCity_Hotel_YourHallway_Text_Lass, MSGBOX_NPC
	end

VirtualCity_Hotel_YourHallway_Text_Lass:
	.string "These HARLOTS are being ogled at by\n"
	.string "all the men in the city!\p"
	.string "Do I gotta doll my avatar up to have\n"
	.string "a chance in the modern dating scene…?$"

VirtualCity_Hotel_YourHallway_Text_WaitingMan:
	.string "My date is 30 minutes late…\p"
	.string "Did I give her the wrong floor?$"
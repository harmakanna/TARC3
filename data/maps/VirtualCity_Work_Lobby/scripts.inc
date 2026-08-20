VirtualCity_Work_Lobby_MapScripts::
	.byte 0


Speaker_Guard::
	.string "Guard$"




VirtualCity_Work_Lobby_Eventscript_NoPokemonGuard::
	
	@@check, how many Pokemon does the player have?
	getpartysize
	goto_if_eq VAR_RESULT, 0, VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardEnter
    goto_if_eq VAR_RESULT, 2, VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardStop
	goto_if_eq VAR_RESULT, 3, VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardStop
	goto_if_eq VAR_RESULT, 4, VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardStop
	goto_if_eq VAR_RESULT, 5, VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardStop
	goto_if_eq VAR_RESULT, 6, VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardStop
	
	@@check what Pokemon it is
	checkspecies SPECIES_PONYTA, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardPonyta
	checkspecies SPECIES_MAGIKARP, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardMagikarp
	goto VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardStop
	end


VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardEnter:
	speak LOCALID_GUARD, VirtualCity_Work_Lobby_Text_NoPokemonGuardEnter, Speaker_Guard, DIR_SOUTH
	goto VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardMoves
	end

VirtualCity_Work_Lobby_Text_NoPokemonGuardEnter:
	.string "Ah good, no Pokemon.$"

VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardMoves:
	@ guard moves out of the way depending on where you are standing TOFOLD
	end



VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardStop:
	speak LOCALID_GUARD, VirtualCity_Work_Lobby_Text_NoPokemonGuardStop, Speaker_Guard, DIR_SOUTH
	end

VirtualCity_Work_Lobby_Text_NoPokemonGuardStop:
	.string "Hold it, you can't bring Pokemon here.\p"
	.string "Too many trainers beating up us guards\n"
	.string "and stealing what they want.\p"
	.string "Only Pokemon related to what they're\n"
	.string "making in there are allowed.$"




VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardPonyta:
	speak LOCALID_GUARD, VirtualCity_Work_Lobby_Text_NoPokemonGuardPonyta, Speaker_Guard, DIR_SOUTH
	goto VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardMoves
	end

VirtualCity_Work_Lobby_Text_NoPokemonGuardPonyta:
	.string "Hold it, you can't…\p"
	.string "Oh, is it done? I barely recognized it…\n"
	.string "It looks great!$"

VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardMagikarp:
	speak LOCALID_GUARD, VirtualCity_Work_Lobby_Text_NoPokemonGuardMagikarp, Speaker_Guard, DIR_SOUTH
	goto VirtualCity_Work_Lobby_Eventscript_NoPokemonGuardMoves
	end


VirtualCity_Work_Lobby_Text_NoPokemonGuardMagikarp:
	.string "Hold it, you can't bring Pokemon here.\p"
	.string "Too many… wait, is that a Magikarp?\n"
	.string "Ahahahahahaha!\p"
	.string "Go on through, heh. Ain't no way you're\n"
	.string "overpowering guards with that!$"






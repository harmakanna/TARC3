VirtualCity_Work_Lobby_MapScripts::
	.byte 0



@ Minh ACT I (Add Magikarp branch if time allows TOFOLD)


VirtualCity_Work_Lobby_Text_MinhACTIIntro1:
	.string "Good, you made it.\p"
	.string "I've been asking around, and I might\n"
	.string "have a lead.\p"
	.string "Apparently, a bunch of artists -\n"
	.string "the boring ones, not visionaries\l"
	.string "like me - got moved recently.\p"
	.string "They're working in BETTER's IRL\n"
	.string "Department, which is pretty suspicious.\p"
	.string "They might be making fakes in there.$"

VirtualCity_Work_Lobby_Text_MinhACTIIntro2:
	.string "We gotta sneak in, but you need a\n"
	.string "Pokemon to fight guards…\p"
	.string "And the elevator guard won't let you\n"
	.string "bring Ex in.$"

VirtualCity_Work_Lobby_Text_SophieACTIIntro3:
	.string "I see. Why don't I just-$"

VirtualCity_Work_Lobby_Text_MinhACTIIntro4:
	.string "Sophie, we've been over this. No\n"
	.string "starting fights in public places.\p"
	.string "If you try to fight the elevator guard,\n"
	.string "people will stop you, and we'll never\l"
	.string "find out what's going on.\p"
	.string "And there's only a few guards in the\n"
	.string "IRL Department.$"

VirtualCity_Work_Lobby_Text_SophieACTIIntro5:
	.string "Ugh, fine.\p"
	.string "So you want me to fight them with\n"
	.string "my bare hands? I can do that.$"

VirtualCity_Work_Lobby_Text_MinhACTIIntro6:
	.string "NO, Sophie.\p"
	.string "Some Pokemon are allowed in. Maybe\n"
	.string "you can find out which ones?\p"
	.string "Then we'll find one, and you can fight\n"
	.string "the guards with that?\p"
	.string "Sigh… I dunno. You're the pro battler.\n"
	.string "My art skills don't really help here.$"

VirtualCity_Work_Lobby_Text_MinhACTIIntroRepeat:
	.string "You remember what to do, right?\p"
	.string "Get into the IRL Department without\n"
	.string "any Pokemon, and see if you can\l"
	.string "find out what Pokemon they'll let in.\p"
	.string "We'll plan it from there.$"



VirtualCity_Work_Lobby_Text_MinhACTIPokemonCheck:
	.string "Did you get any info on what Pokemon\n"
	.string "you can get past the guard?$"

VirtualCity_Work_Lobby_Text_MinhACTIPokemonCheckSuccess1:
	.string "Nice! Wait, Ponyta are expensive!\p"
	.string "By the time we save up to get one,\n"
	.string "they'll be working on something else!$"

VirtualCity_Work_Lobby_Text_SophieACTIPokemonCheckSuccess2:
	.string "Hmm. How well can you draw Ponyta?$"

VirtualCity_Work_Lobby_Text_MinhACTIPokemonCheckSuccess3:
	.string "What? Umm, very well. It's in my top\n"
	.string "ten Fire-types, as you should know.$"

VirtualCity_Work_Lobby_Text_SophieACTIPokemonCheckSuccess4:
	.string "I think I know how your artistic skill\n"
	.string "can get us into the department.\p"
	.string "Meet you in our office; let me get Ex.\p"



@@ Guard

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






@@ Roland and his fans TOFOLD

VirtualCity_Work_Lobby_Text_Roland:
	.string "Ugh, Roland is rambling about the\n"
	.string "quanta system again.\p"
	.string "Listen in?$"

VirtualCity_Work_Lobby_Text_RolandNo:
	.string "Better not. The headache from the last\n"
	.string "time is just starting to fade.$"



VirtualCity_Work_Lobby_Text_RolandRamble1:
	.string "…so obviously, ahem, the real world runs\n"
	.string "on a discrete time scale. Hrrmph.\p"
	.string "You know, battle time is in turns.\n"
	.string "One attack per turn, no half-turns.\p"
	.string "But in the Realm, they've quantized\n"
	.string "time down a bit smaller. Yeah.\p"
	.string "Four fractional turns in a regular turn.\p"
	.string "Casuals call them miniturns, but pros\n"
	.string "use the real name: quanta.\p"
	.string "It's a real innovation. Makes battles\n"
	.string "suited for high skill players like me.\p"
	.string "You can hit three Quick Attacks before\n"
	.string "your opponent hits a Solarbeam.\p"
	.string "Or, you can use Giga Impact for a huge\n"
	.string "attack immediately, but then you use\l"
	.string "a lot of quanta recharging.\p"
	.string "Harrumph! I say…$"

VirtualCity_Work_Lobby_Text_RolandRamble2:
	.string "…$"

VirtualCity_Work_Lobby_Text_RolandRamble3:
	.string "…$"

VirtualCity_Work_Lobby_Text_RolandRamblePostgame:
	.string "…$"




VirtualCity_Work_Lobby_Text_RolandFanClubGuy1:
	.string "Wow… I never knew that!\p"
	.string "Roland, you're so cool!$"

VirtualCity_Work_Lobby_Text_RolandFanClubGirl1:
	.string "So the Realm is really higher fidelity\n"
	.string "than real life?\p"
	.string "I thought that was just marketing!$"



VirtualCity_Work_Lobby_Text_RolandFanClubGuy2:
	.string "!$"

VirtualCity_Work_Lobby_Text_RolandFanClubGirl2:
	.string "!$"


VirtualCity_Work_Lobby_Text_RolandFanClubGuy3:
	.string "!$"

VirtualCity_Work_Lobby_Text_RolandFanClubGirl3:
	.string "!$"


VirtualCity_Work_Lobby_Text_RolandFanClubGuyPostgame:
	.string "!$"

VirtualCity_Work_Lobby_Text_RolandFanClubGirlPostgame:
	.string "!$"
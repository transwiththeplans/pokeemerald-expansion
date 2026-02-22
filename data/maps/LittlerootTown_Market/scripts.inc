LittlerootTown_Market_MapScripts::
	.byte 0


LittlerootTown_Market_EventScript_Clerk::
# 4 "data/maps/LittlerootTown_Market/scripts.pory"
	lock
# 5 "data/maps/LittlerootTown_Market/scripts.pory"
	message gText_HowMayIServeYou
# 6 "data/maps/LittlerootTown_Market/scripts.pory"
	waitmessage
# 7 "data/maps/LittlerootTown_Market/scripts.pory"
	pokemart LittlerootTown_Market_Pokemart
# 8 "data/maps/LittlerootTown_Market/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 9 "data/maps/LittlerootTown_Market/scripts.pory"
	release
	end


	.align 2
# 13 "data/maps/LittlerootTown_Market/scripts.pory"
LittlerootTown_Market_Pokemart:
# 14 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_POTION
# 15 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_POKE_BALL
# 16 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_LEVEL_BALL
# 17 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_LURE_BALL
# 18 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_MOON_BALL
# 19 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_FRIEND_BALL
# 20 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_LOVE_BALL
# 21 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_FAST_BALL
# 22 "data/maps/LittlerootTown_Market/scripts.pory"
	.2byte ITEM_HEAVY_BALL
	.2byte ITEM_NONE

LittlerootTown_Market_EventScript_Woman_1::
# 26 "data/maps/LittlerootTown_Market/scripts.pory"
	msgbox LittlerootTown_Market_EventScript_Woman_1_Text_0, MSGBOX_NPC
	end


LittlerootTown_Market_EventScript_Woman_3::
# 31 "data/maps/LittlerootTown_Market/scripts.pory"
	msgbox LittlerootTown_Market_EventScript_Woman_3_Text_0, MSGBOX_NPC
	end


LittlerootTown_Market_EventScript_Gentleman::
# 36 "data/maps/LittlerootTown_Market/scripts.pory"
	msgbox LittlerootTown_Market_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


LittlerootTown_Market_EventScript_Bug_Catcher::
# 41 "data/maps/LittlerootTown_Market/scripts.pory"
	msgbox LittlerootTown_Market_EventScript_Bug_Catcher_Text_0, MSGBOX_NPC
	end


LittlerootTown_Market_EventScript_Little_Girl::
# 46 "data/maps/LittlerootTown_Market/scripts.pory"
	msgbox LittlerootTown_Market_EventScript_Little_Girl_Text_0, MSGBOX_NPC
	end


LittlerootTown_Market_EventScript_Sale_Woman::
# 51 "data/maps/LittlerootTown_Market/scripts.pory"
	msgbox LittlerootTown_Market_EventScript_Sale_Woman_Text_0, MSGBOX_NPC
	end


LittlerootTown_Market_EventScript_Camper::
# 56 "data/maps/LittlerootTown_Market/scripts.pory"
	msgbox LittlerootTown_Market_EventScript_Camper_Text_0, MSGBOX_NPC
	end


LittlerootTown_Market_EventScript_Woman_1_Text_0:
# 26 "data/maps/LittlerootTown_Market/scripts.pory"
	.string "I'm buying a treat for my TANDEMAUS.$"

LittlerootTown_Market_EventScript_Woman_3_Text_0:
# 31 "data/maps/LittlerootTown_Market/scripts.pory"
	.string "I've been looking for apricorn balls\n"
	.string "forever!$"

LittlerootTown_Market_EventScript_Gentleman_Text_0:
# 36 "data/maps/LittlerootTown_Market/scripts.pory"
	.string "This shop has many fine items.$"

LittlerootTown_Market_EventScript_Bug_Catcher_Text_0:
# 41 "data/maps/LittlerootTown_Market/scripts.pory"
	.string "This store is always well stocked.$"

LittlerootTown_Market_EventScript_Little_Girl_Text_0:
# 46 "data/maps/LittlerootTown_Market/scripts.pory"
	.string "I want one of everything!$"

LittlerootTown_Market_EventScript_Sale_Woman_Text_0:
# 51 "data/maps/LittlerootTown_Market/scripts.pory"
	.string "These are flying off the shelves these\n"
	.string "days.$"

LittlerootTown_Market_EventScript_Camper_Text_0:
# 56 "data/maps/LittlerootTown_Market/scripts.pory"
	.string "I never leave home without POTIONS.$"

# 1 "data/maps/OldaleTown_Mart/scripts.pory"

# 2 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_MapScripts::
# 3 "data/maps/OldaleTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/OldaleTown_Mart/scripts.pory"

# 5 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_Clerk::
# 6 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 7 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/OldaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/OldaleTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/OldaleTown_Mart/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
# 11 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart OldaleTown_Mart_Pokemart_Basic
# 12 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 13 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 14 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 15 "data/maps/OldaleTown_Mart/scripts.pory"
	
# 16 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_ClerkTMs::
# 17 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 18 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 19 "data/maps/OldaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 20 "data/maps/OldaleTown_Mart/scripts.pory"
	waitmessage
# 21 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart OldaleTown_Mart_Pokemart_TMs
# 22 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 23 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 24 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 25 "data/maps/OldaleTown_Mart/scripts.pory"

# 26 "data/maps/OldaleTown_Mart/scripts.pory"
	.align 2
# 27 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Pokemart_Basic:
# 28 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 29 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_POTION
# 30 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 31 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 32 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 33 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_RARE_CANDY
# 34 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemartlistend
# 35 "data/maps/OldaleTown_Mart/scripts.pory"

# 36 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_ExpandedItems::
# 37 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart OldaleTown_Mart_Pokemart_Expanded
# 38 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 39 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 40 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 41 "data/maps/OldaleTown_Mart/scripts.pory"

# 42 "data/maps/OldaleTown_Mart/scripts.pory"
	.align 2
# 43 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Pokemart_Expanded:
# 44 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 45 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_POTION
# 46 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 47 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 48 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 49 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_RARE_CANDY
# 50 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_GLACIATE
# 51 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_VACUUM_WAVE
# 52 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_WATER_PULSE
# 53 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_SILVER_WIND
# 54 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_ASTEROID_BELT
# 55 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemartlistend
# 56 "data/maps/OldaleTown_Mart/scripts.pory"

# 57 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_Woman::
# 58 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 59 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 60 "data/maps/OldaleTown_Mart/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
# 61 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
# 62 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 63 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 64 "data/maps/OldaleTown_Mart/scripts.pory"

# 65 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_PokeBallsInStock::
# 66 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
# 67 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 68 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 69 "data/maps/OldaleTown_Mart/scripts.pory"

# 70 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_Boy::
# 71 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
# 72 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 73 "data/maps/OldaleTown_Mart/scripts.pory"

# 74 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_PokeBallsAreSoldOut:
# 75 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "The clerk says they're all sold out.\n"
# 76 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "I can't buy any POKé BALLS.$"
# 77 "data/maps/OldaleTown_Mart/scripts.pory"

# 78 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
# 79 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "I'm going to buy a bunch of POKé BALLS\n"
# 80 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "and catch a bunch of POKéMON!$"
# 81 "data/maps/OldaleTown_Mart/scripts.pory"

# 82 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_RestoreHPWithPotion:
# 83 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "If a POKéMON gets hurt and loses its HP\n"
# 84 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "and faints, it won't be able to battle.\p"
# 85 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "To prevent your POKéMON from fainting,\n"
# 86 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "restore its HP with a POTION.$"
# 87 "data/maps/OldaleTown_Mart/scripts.pory"

# 88 "data/maps/OldaleTown_Mart/scripts.pory"
	.align 2
# 89 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Pokemart_TMs:
# 90 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_HEX
# 91 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_ELECTRO_BALL
# 92 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_DRAGON_BREATH
# 93 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_MUD_SHOT
# 94 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_DRAINING_KISS
# 95 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_TM_SUBSTITUTE
# 96 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemartlistend

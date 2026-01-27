# 1 "data/maps/PetalburgCity_Mart/scripts.pory"

# 2 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_MapScripts::
# 3 "data/maps/PetalburgCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgCity_Mart/scripts.pory"

# 5 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Clerk::
# 6 "data/maps/PetalburgCity_Mart/scripts.pory"
	lock
# 7 "data/maps/PetalburgCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/PetalburgCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/PetalburgCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/PetalburgCity_Mart/scripts.pory"
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
# 11 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Basic
# 12 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 13 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 14 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 15 "data/maps/PetalburgCity_Mart/scripts.pory"

# 16 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 17 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Basic:
# 18 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 19 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 20 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 21 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 22 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 23 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 24 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 25 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 26 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 27 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 28 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ORANGE_MAIL
# 29 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemartlistend
# 30 "data/maps/PetalburgCity_Mart/scripts.pory"

# 31 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_ExpandedItems::
# 32 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Expanded
# 33 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 34 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 35 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 36 "data/maps/PetalburgCity_Mart/scripts.pory"

# 37 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 38 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Expanded:
# 39 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 40 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 41 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 42 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 43 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 44 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 45 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 46 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 47 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 48 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 49 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 50 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 51 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ORANGE_MAIL
# 52 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemartlistend
# 53 "data/maps/PetalburgCity_Mart/scripts.pory"
	
# 54 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_EventScript_ClerkTMs::
# 55 "data/maps/PetalburgCity_Mart/scripts.pory"
	lock
# 56 "data/maps/PetalburgCity_Mart/scripts.pory"
	faceplayer
# 57 "data/maps/PetalburgCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 58 "data/maps/PetalburgCity_Mart/scripts.pory"
	waitmessage
# 59 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_TMs
# 60 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 61 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 62 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 63 "data/maps/PetalburgCity_Mart/scripts.pory"
	
# 64 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 65 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_TMs:
# 66 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_FIRE_FANG
# 67 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_ICE_FANG
# 68 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_THUNDER_FANG
# 69 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_POISON_FANG
# 70 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_FLIP_TURN
# 71 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_SMART_STRIKE
# 72 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_DUAL_WINGBEAT
# 73 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_PIN_MISSILE
# 74 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_KNOCK_OFF
# 75 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_TM_BREAKING_SWIPE
# 76 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemartlistend
# 77 "data/maps/PetalburgCity_Mart/scripts.pory"

# 78 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Woman::
# 79 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
# 80 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 81 "data/maps/PetalburgCity_Mart/scripts.pory"

# 82 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Boy::
# 83 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
# 84 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 85 "data/maps/PetalburgCity_Mart/scripts.pory"

# 86 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Man::
# 87 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
# 88 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 89 "data/maps/PetalburgCity_Mart/scripts.pory"

# 90 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_WeakWillGrowStronger:
# 91 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Even if a POKéMON is weak now,\n"
# 92 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "it will grow stronger.\p"
# 93 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "The most important thing is love!\n"
# 94 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Love for your POKéMON!$"
# 95 "data/maps/PetalburgCity_Mart/scripts.pory"

# 96 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_RepelIsUseful:
# 97 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you use REPEL?\n"
# 98 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "It keeps POKéMON away, so it's\l"
# 99 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "useful when you're in a hurry.$"
# 100 "data/maps/PetalburgCity_Mart/scripts.pory"

# 101 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
# 102 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you have any ANTIDOTES with\n"
# 103 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "you?\p"
# 104 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "If you walk around with a poisoned\n"
# 105 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "POKéMON, it will lose HP until it faints.\l"
# 106 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Take some ANTIDOTES with you.$"

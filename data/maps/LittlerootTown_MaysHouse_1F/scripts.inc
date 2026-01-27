# 1 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 2 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_MapScripts::
# 3 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
# 4 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
# 5 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
# 6 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.byte 0
# 7 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 8 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnLoad:
# 9 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes
# 10 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual
# 11 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 12 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 13 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes::
# 14 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 15 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
# 16 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 17 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 18 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
# 19 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkplayergender
# 20 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual
# 21 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 22 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 23 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual::
# 24 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
# 25 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 26 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 27 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnTransition:
# 28 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor
# 29 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs
# 30 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV
# 31 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 32 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 33 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs::
# 34 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 2, 4
# 35 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
# 36 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 37 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 38 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV::
# 39 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 6, 5
# 40 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
# 41 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 42 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 43 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor::
# 44 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 1, 8
# 45 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
# 46 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 47 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 48 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
@ Many of the below scripts have no gender check because they assume youre in the correct house
# 49 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_OnFrame:
# 50 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn
# 51 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock
# 52 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport
# 53 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1, LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor
# 54 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
# 55 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.2byte 0
# 56 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 57 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock::
# 58 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 59 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 60 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 61 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 62 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 63 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 64 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 1, 1
# 65 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitstate
# 66 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 67 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 68 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 69 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
# 70 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 71 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 72 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 73 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn::
# 74 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 75 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
# 76 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 77 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
# 78 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 79 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 80 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport::
# 81 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 82 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, FEMALE
# 83 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
# 84 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
# 85 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 86 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 87 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor::
# 88 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 89 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 90 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
# 91 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 92 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
# 93 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 94 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 95 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
# 96 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 97 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 98 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 99 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 100 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
# 101 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 102 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 103 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 104 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
# 105 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 106 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 107 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 108 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 109 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 110 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 111 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 112 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 113 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalMom::
# 114 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 115 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 116 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
# 117 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
# 118 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, RivalsHouse_1F_EventScript_RivalTooBusy
# 119 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 120 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
# 121 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 122 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 123 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 124 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalTooBusy::
# 125 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
# 126 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 127 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 128 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 129 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_RivalIsOnRoute103::
# 130 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
# 131 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 132 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 133 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 134 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_EventScript_GoHomeEverySoOften::
# 135 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
# 136 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
# 137 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 138 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 139 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 140 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom::
# 141 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 142 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
# 143 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 144 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 145 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 146 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
# 147 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 148 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 149 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival0::
# 150 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 151 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 152 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 153 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 154 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 155 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival1::
# 156 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 157 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 158 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 159 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 160 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 161 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival2::
# 162 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 163 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 164 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
# 165 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 166 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 167 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MeetRival::
# 168 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 169 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 10
# 170 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
# 171 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 172 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 173 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
# 174 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 175 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
# 176 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 177 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_ne VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay
# 178 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 179 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0
# 180 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1
# 181 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2
# 182 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 183 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 184 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0
# 185 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1
# 186 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2
# 187 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 188 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
# 189 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
# 190 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 191 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 192 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 193 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 194 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 195 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 196 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	fadedefaultbgm
# 197 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
# 198 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	end
# 199 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 200 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay::
# 201 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 202 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 203 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 204 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 205 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0::
# 206 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0
# 207 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 208 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 209 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 210 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1::
# 211 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1
# 212 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 213 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 214 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 215 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2::
# 216 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2
# 217 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 218 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 219 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 220 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0:
# 221 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 222 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 223 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 224 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 225 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 226 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 227 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 228 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 229 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 230 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1:
# 231 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 232 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 233 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 234 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 235 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 236 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2:
# 237 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 238 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 239 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 240 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 241 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 242 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 243 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 244 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 245 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 246 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0::
# 247 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
# 248 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
# 249 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 250 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 251 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 252 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1::
# 253 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
# 254 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
# 255 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 256 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 257 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 258 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2::
# 259 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
# 260 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
# 261 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 262 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	return
# 263 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 264 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0:
# 265 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 266 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 267 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 268 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 269 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 270 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1:
# 271 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 272 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 273 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 274 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 275 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 276 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 277 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 278 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 279 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2:
# 280 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 281 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 282 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 283 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 284 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 285 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0:
# 286 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 287 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 288 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 289 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 290 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 291 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 292 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 293 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1:
# 294 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 295 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 296 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 297 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 298 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 299 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 300 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 301 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 302 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 303 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 304 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 305 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2:
# 306 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 307 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 308 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 309 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 310 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 311 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	step_end
# 312 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 313 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_OhYoureTheNewNeighbor:
# 314 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {PLAYER}{KUN}! You're here!\p"
# 315 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "How was the drive?\p"
# 316 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … … …\n"
# 317 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … … …\p"
# 318 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Riding in the back of truck?\n"
# 319 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Sounds rough.\p"
# 320 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{RIVAL} is upstairs, I think.\n"
# 321 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Why don't you go and say hi?$"
# 322 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 323 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_LikeChildLikeFather:
# 324 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "That professor is as wild about POKéMON\n"
# 325 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "more than anyone else.\p"
# 326 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "If he's not at his LAB, he's likely\n"
# 327 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "scrabbling about in grassy places.$"
# 328 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 329 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_TooBusyToNoticeVisit:
# 330 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "That {RIVAL}!\p"
# 331 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I guess {RIVAL} is too busy with\n"
# 332 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "POKéMON to notice that you came\l"
# 333 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "to visit, {PLAYER}{KUN}.\p"
# 334 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "...what's that smile for? $"
# 335 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 336 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_WentOutToRoute103:
# 337 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
# 338 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "just a little while ago.$"
# 339 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 340 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_ShouldGoHomeEverySoOften:
# 341 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I think it's wonderful for people to\n"
# 342 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "travel with POKéMON.\p"
# 343 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "But you should go home every so often\n"
# 344 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "to let your mother know you're okay.\p"
# 345 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "She might not say it, but I'm sure she\n"
# 346 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "worries about you, {PLAYER}{KUN}.$"
# 347 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 348 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_MayWhoAreYou:
# 349 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Dweeb!?\n"
# 350 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "What are you doing here?\p"
# 351 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … …\n"
# 352 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … …\p"
# 353 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "So your move was today.\p"
# 354 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "...great.\n"
# 355 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Can't say I'm happy to see you.\p"
# 356 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Thanks for dropping by, but I got to\l"
# 357 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "go help the professor with fieldwork.\p"
# 358 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I became his field aid recently. POKéMON\n"
# 359 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "biology is so fascinating.\p"
# 360 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Not that you'd understand.\p"
# 361 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I just need to fill in some data\n"
# 362 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "in before I go out...\p"
# 363 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Get out of my house, {PLAYER}{KUN}.$"
# 364 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"

# 365 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
RivalsHouse_1F_Text_BrendanWhoAreYou:
# 366 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Dweeb!?\n"
# 367 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "What are you doing here?\p"
# 368 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … …\n"
# 369 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "… … … … … … … …\p"
# 370 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "So your move was today.\p"
# 371 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "...great.\n"
# 372 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Can't say I'm happy to see you.\p"
# 373 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Thanks for dropping by, but I got to\l"
# 374 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "go help the professor with fieldwork.\p"
# 375 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Mom made me become his 'helper'. POKéMON\n"
# 376 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "are cool, so whatever.\p"
# 377 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Not that you'd understand.\p"
# 378 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I just need to fill in some data\n"
# 379 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "in before I go out...\p"
# 380 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Get out of my house, {PLAYER}{KUN}.$"

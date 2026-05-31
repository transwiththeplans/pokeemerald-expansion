#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_dome.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tv.h"
#include "battle_z_move.h"
#include "battle_gimmick.h"
#include "bg.h"
#include "data.h"
#include "event_data.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "international_string_util.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "test_runner.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "line_break.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_partner.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"
#include "caps.h"
#include "menu.h"
#include "pokemon_summary_screen.h"
#include "type_icons.h"
#include "pokedex.h"
#include "test/battle.h"
#include "test/test_runner_battle.h"

static void PlayerHandleLoadMonSprite(u32 battler);
static void PlayerHandleDrawTrainerPic(u32 battler);
static void PlayerHandleTrainerSlide(u32 battler);
static void PlayerHandleTrainerSlideBack(u32 battler);
static void PlayerHandlePaletteFade(u32 battler);
static void PlayerHandleSuccessBallThrowAnim(u32 battler);
static void PlayerHandlePause(u32 battler);
static void PlayerHandleChooseAction(u32 battler);
static void PlayerHandleYesNoBox(u32 battler);
static void PlayerHandleChooseItem(u32 battler);
static void PlayerHandleChoosePokemon(u32 battler);
static void PlayerHandleCmd23(u32 battler);
static void PlayerHandleStatusXor(u32 battler);
static void PlayerHandleDMA3Transfer(u32 battler);
static void PlayerHandlePlayBGM(u32 battler);
static void PlayerHandleTwoReturnValues(u32 battler);
static void PlayerHandleChosenMonReturnValue(u32 battler);
static void PlayerHandleOneReturnValue(u32 battler);
static void PlayerHandleOneReturnValue_Duplicate(u32 battler);
static void PlayerHandleIntroTrainerBallThrow(u32 battler);
static void PlayerHandleDrawPartyStatusSummary(u32 battler);
static void PlayerHandleEndBounceEffect(u32 battler);
static void PlayerHandleLinkStandbyMsg(u32 battler);
static void PlayerHandleResetActionMoveSelection(u32 battler);
static void PlayerHandleEndLinkBattle(u32 battler);
static void PlayerHandleBattleDebug(u32 battler);

static void PlayerBufferRunCommand(u32 battler);
static void MoveSelectionDisplayPpNumber(u32 battler);
static void MoveSelectionDisplayPpString(u32 battler);
static void MoveSelectionDisplayMoveType(u32 battler);
static void MoveSelectionDisplayMoveNames(u32 battler);
static void TryMoveSelectionDisplayMoveDescription(u32 battler);
static void MoveSelectionDisplayMoveDescription(u32 battler);
static void WaitForMonSelection(u32 battler);
static void CompleteWhenChoseItem(u32 battler);
static void Task_LaunchLvlUpAnim(u8);
static void Task_PrepareToGiveExpWithExpBar(u8);
static void Task_SetControllerToWaitForString(u8);
static void Task_GiveExpWithExpBar(u8);
static void Task_UpdateLvlInHealthbox(u8);
static void PrintLinkStandbyMsg(void);

static void ReloadMoveNames(u32 battler);
static u32 CheckTypeEffectiveness(u32 battlerAtk, u32 battlerDef);
static uq4_12_t CheckTypeEffectivenessMod(u32 battlerAtk, u32 battlerDef, u16 move);
static u32 CheckTargetTypeEffectiveness(u32 battler);
static void MoveSelectionDisplayMoveEffectiveness(u32 foeEffectiveness, u32 battler);

static void (*const sPlayerBufferCommands[CONTROLLER_CMDS_COUNT])(u32 battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_HandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = PlayerHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = BtlController_HandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = PlayerHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = PlayerHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = PlayerHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = PlayerHandlePaletteFade,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = PlayerHandleSuccessBallThrowAnim,
    [CONTROLLER_BALLTHROWANIM]            = PlayerHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = PlayerHandlePause,
    [CONTROLLER_MOVEANIMATION]            = BtlController_HandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = BtlController_HandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_HandlePrintStringPlayerOnly,
    [CONTROLLER_CHOOSEACTION]             = PlayerHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = PlayerHandleYesNoBox,
    [CONTROLLER_CHOOSEMOVE]               = PlayerHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = PlayerHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = PlayerHandleChoosePokemon,
    [CONTROLLER_23]                       = PlayerHandleCmd23,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_HandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = PlayerHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_HandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = BtlController_HandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = PlayerHandleStatusXor,
    [CONTROLLER_DATATRANSFER]             = BtlController_Empty,
    [CONTROLLER_DMA3TRANSFER]             = PlayerHandleDMA3Transfer,
    [CONTROLLER_PLAYBGM]                  = PlayerHandlePlayBGM,
    [CONTROLLER_32]                       = BtlController_Empty,
    [CONTROLLER_TWORETURNVALUES]          = PlayerHandleTwoReturnValues,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = PlayerHandleChosenMonReturnValue,
    [CONTROLLER_ONERETURNVALUE]           = PlayerHandleOneReturnValue,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = PlayerHandleOneReturnValue_Duplicate,
    [CONTROLLER_HITANIMATION]             = BtlController_HandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = BtlController_HandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = PlayerHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = PlayerHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = PlayerHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = PlayerHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = PlayerHandleResetActionMoveSelection,
    [CONTROLLER_ENDLINKBATTLE]            = PlayerHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = PlayerHandleBattleDebug,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

enum Colors
{
    FONT_BLACK,
    FONT_BLACK_2,
    FONT_WHITE,
    FONT_WHITE_2,
    FONT_RED,
    FONT_BLUE,
};

static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]   = {TEXT_COLOR_TRANSPARENT,  10, 4},
    [FONT_BLACK_2] = {TEXT_COLOR_TRANSPARENT,  10, TEXT_COLOR_TRANSPARENT},
    [FONT_WHITE]   = {TEXT_COLOR_TRANSPARENT,  1,  14},
    [FONT_WHITE_2] = {TEXT_COLOR_TRANSPARENT,  1,  TEXT_COLOR_TRANSPARENT},
    [FONT_RED]     = {TEXT_COLOR_TRANSPARENT,  8,  9},
    [FONT_BLUE]    = {TEXT_COLOR_TRANSPARENT,  14, 15},
};

enum optionsButtonMode
{
    BATTLE_ACTION_FIGHT,
    BATTLE_ACTION_BAG,
    BATTLE_ACTION_POKEMON,
    BATTLE_ACTION_RUN,
    NUM_BATTLE_ACTIONS,
};

const u8 sText_BattleMenu_Action_Fight[]   = _("FIGHT");
const u8 sText_BattleMenu_Action_Bag[]     = _("BAG");
const u8 sText_BattleMenu_Action_Pokemon[] = _("POKéMON");
const u8 sText_BattleMenu_Action_Run[]     = _("RUN");
const u8 sText_BattleMenu_Action_What_Will_X_Do[] = _("What will\n{STR_VAR_1} do?");
const u8 sText_BattleMenu_Action_Info[] = _("{L_BUTTON} INFO");
const u8 sText_BattleMenu_Action_Exit[] = _("{L_BUTTON} EXIT");


const u8 sText_BattleMenu_Gender_Male[] = _("♂");
const u8 sText_BattleMenu_Gender_Female[] = _("♀");
const u8 sText_BattleMenu_Gender_None[] = _("");

const u8 sText_BattleMenu_Action_Info_Nickname[] = _("{STR_VAR_1}{STR_VAR_2} {LV}{STR_VAR_3}");
const u8 sText_BattleMenu_Action_Info_HP[] = _("{STR_VAR_1}/{STR_VAR_2}");
const u8 sText_BattleMenu_Action_Info_HP_Percent[] = _("{STR_VAR_1}%");
const u8 sText_BattleMenu_Action_Test[] = _("8");

static const u8 sBattleSelector_Actions[] = INCBIN_U8("graphics/ui_menus/battle_interface/selector.4bpp");
static const u8 sBattleSelector_Moves[]   = INCBIN_U8("graphics/ui_menus/battle_interface/selector_moves.4bpp");

#define BATTLE_WINDOW_ACTION_LIST_WIDTH 64
#define BATTLE_WINDOW_WHAT_WILL_X_DO_SQUARE_SIZE 100
#define BATTLE_WINDOW_WHAT_WILL_X_DO_SQUARE_SIZE_DPPT 88
#define BATTLE_WINDOW_SQUARE_SIZE 47
#define BATTLE_WINDOW_SQUARE_SIZE_DPPT 44
#define BATTLE_WINDOW_SPACE_BETWEEN_SQUARE_AND_TEXT 13
#define BATTLE_WINDOW_SPACE_BETWEEN_SQUARE_AND_TEXT_DPPT 14
#define BATTLE_WINDOW_SPACE_BETWEEN_SQUARE_AND_TEXT_CLASSIC 4

#define BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_X 184
#define BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y 4
#define BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_X_OFFSET 53
#define BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y_OFFSET 16

static void RestoreBattleMenuBg(void)
{
    gBattle_BG1_Y = 0;
    gBattle_BG1_X = 0;
    ShowBg(1);
}

void ClearBattleWindow(void)
{
    FillWindowPixelBuffer(B_WIN_ACTION_PROMPT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(B_WIN_ACTION_PROMPT);
    CopyWindowToVram(B_WIN_ACTION_PROMPT, 3);
}

#define ACTION_PRIMPT_INFO_TEXT_X 16 + 104
#define ACTION_PRIMPT_INFO_TEXT_Y 4


#define ACTION_PROMPT_LEVEL_WIN_WIDTH 100

static const u8 sStatOrder[NUM_BATTLE_STATS] = {
    STAT_HP,
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
    STAT_ACC,
    STAT_EVASION,
};

void PrintBattleWindow_ActionPromt(u32 battler)
{
    struct Pokemon *mon = &gPlayerParty[gBattlerPartyIndexes[battler]];
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 i, posX, posY, offset;
    u8 windowId = B_WIN_ACTION_PROMPT;
    u8 font = FONT_NORMAL;
    u8 fontColor = FONT_BLACK;
    u8 battlerToCheck = VarGet(VAR_BATTLE_INFO_BATTLER);
    RestoreBattleMenuBg();

    DebugPrintfLevel(MGBA_LOG_WARN, "PrintBattleWindow_ActionPromt");

    //Fill the window with the fill value
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    if(FlagGet(FLAG_SYS_BATTLE_ACTION_WINDOW_INFO)){
        u8 j, level, nameSize, gender;
        u32 maxHp, currHp, species;
        struct Pokemon *checkMon;

        font = FONT_SMALL_NARROW;
        posX = 8;
        posY = 4;
        offset = 0;

        if(IsOnPlayerSide(battlerToCheck))
            checkMon = &gPlayerParty[gBattlerPartyIndexes[battlerToCheck]];
        else
            checkMon = &gEnemyParty[gBattlerPartyIndexes[battlerToCheck]];

        maxHp = GetMonData(checkMon, MON_DATA_MAX_HP);
        currHp = GetMonData(checkMon, MON_DATA_HP);
        level = GetMonData(checkMon, MON_DATA_LEVEL);

        GetMonData(checkMon, MON_DATA_NICKNAME, nickname);
        StringGet_Nickname(nickname);

        StringCopy(gStringVar1, nickname);

        gender = GetMonGender(mon);
        species = GetMonData(mon, MON_DATA_SPECIES);

        if ((species == SPECIES_NIDORAN_F || species == SPECIES_NIDORAN_M) && StringCompare(nickname, GetSpeciesName(species)) == 0)
            gender = 100;

        switch (gender)
        {
        default:
            StringCopy(gStringVar2, sText_BattleMenu_Gender_None);
            break;
        case MON_MALE:
            StringCopy(gStringVar2, sText_BattleMenu_Gender_Male);
            break;
        case MON_FEMALE:
            StringCopy(gStringVar2, sText_BattleMenu_Gender_Female);
            break;
        }

	    ConvertIntToDecimalStringN(gStringVar3, level, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Info_Nickname);
        offset = 10 + GetStringCenterAlignXOffset(font, gStringVar4, ACTION_PROMPT_LEVEL_WIN_WIDTH);
        AddTextPrinterParameterized4(windowId, font, posX + offset, posY, 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar4);

        //posX = 16;
        posY = 8;
        nameSize = GetStringWidth(font, gStringVar4, 0);

		BlitBitmapToWindow(windowId, gBattleInterface_Info_L_Arrow, (posX + offset - 8), posY, 8, 8);
		BlitBitmapToWindow(windowId, gBattleInterface_Info_R_Arrow, (posX + offset + nameSize), posY, 8, 8);

        posX = 16;
        posY = 12;
        for(i = 0; i < NUM_STATS; i++){
            u8 stat = sStatOrder[i];
            if((NUM_STATS / 2) - 1 < i)
                offset = 72;
            else
                offset = 0;

            AddTextPrinterParameterized4(windowId, font, (posX + offset), posY + ((i % 3) * 8), 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStatNamesShortTable[stat]);

            if(stat != STAT_HP){
                for(j = 0; j < MAX_STAT_STAGE / 2; j++){
                    if(gBattleMons[battlerToCheck].statStages[stat] > DEFAULT_STAT_STAGE){
                        u8 stages = gBattleMons[battlerToCheck].statStages[stat] - DEFAULT_STAT_STAGE;
                        if(j < stages)
                            BlitBitmapToWindow(windowId, gBattleInterface_Info_Plus_Symbol, (posX + offset) + (j * 8) + 16, posY + ((i % 3) * 8) + 4, 8, 8);
                        else
                            BlitBitmapToWindow(windowId, gBattleInterface_Info_Stat_Dot, (posX + offset) + (j * 8) + 16, posY + ((i % 3) * 8) + 4, 8, 8);
                    }
                    else if(gBattleMons[battlerToCheck].statStages[stat] < DEFAULT_STAT_STAGE){
                        u8 stages = DEFAULT_STAT_STAGE - gBattleMons[battlerToCheck].statStages[stat];
                        if(j < stages)
                            BlitBitmapToWindow(windowId, gBattleInterface_Info_Down_Symbol, (posX + offset) + (j * 8) + 16, posY + ((i % 3) * 8) + 4, 8, 8);
                        else
                            BlitBitmapToWindow(windowId, gBattleInterface_Info_Stat_Dot, (posX + offset) + (j * 8) + 16, posY + ((i % 3) * 8) + 4, 8, 8);
                    }
                    else{
                        BlitBitmapToWindow(windowId, gBattleInterface_Info_Stat_Dot, (posX + offset) + (j * 8) + 16, posY + ((i % 3) * 8) + 4, 8, 8);
                    }
                }
            }
            else{
                bool8 isEnemy = !IsOnPlayerSide(battlerToCheck);
                if(isEnemy){
                    u16 percent = (maxHp * 100) / currHp;
                    ConvertIntToDecimalStringN(gStringVar1, percent, STR_CONV_MODE_LEFT_ALIGN, 4);
                    StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Info_HP_Percent);
                }
                else{
                    ConvertIntToDecimalStringN(gStringVar1, currHp, STR_CONV_MODE_LEFT_ALIGN, 4);
                    ConvertIntToDecimalStringN(gStringVar2, maxHp, STR_CONV_MODE_LEFT_ALIGN, 4);
                    StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Info_HP);
                }

                AddTextPrinterParameterized4(windowId, font, (posX + offset) + 16, posY + ((i % 3) * 8), 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar4);
            }
        }

        AddTextPrinterParameterized4(windowId, FONT_SMALL, ACTION_PRIMPT_INFO_TEXT_X, ACTION_PRIMPT_INFO_TEXT_Y, 0, 0, sMenuWindowFontColors[fontColor], 0xFF, sText_BattleMenu_Action_Exit);
    }
    else{
        //What Will X Do?
        posX = 8;
        posY = 8;
        offset = 0;

        GetMonData(mon, MON_DATA_NICKNAME, nickname);
        StringGet_Nickname(nickname);

        StringCopy(gStringVar1, nickname);
        StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_What_Will_X_Do);
        offset = 4 + GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, BATTLE_WINDOW_WHAT_WILL_X_DO_SQUARE_SIZE);
        AddTextPrinterParameterized4(windowId, FONT_NORMAL, posX + offset, posY, 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar4);

        AddTextPrinterParameterized4(windowId, FONT_SMALL, ACTION_PRIMPT_INFO_TEXT_X, ACTION_PRIMPT_INFO_TEXT_Y, 0, 0, sMenuWindowFontColors[fontColor], 0xFF, sText_BattleMenu_Action_Info);
    }

    // Print Fight / Pokémon / Bag / Run Text
    posX = BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_X;
    posY = BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y;
    offset = 0;

    for(i = 0; i < NUM_BATTLE_ACTIONS; i++){
        //Cursor
        if(gActionSelectionCursor[battler] == i)
            BlitBitmapToWindow(windowId, sBattleSelector_Moves, posX - 8, posY + (i * 8) + 4, 8, 8);

        //Move Name
        switch(i){
            case BATTLE_ACTION_FIGHT:
                StringCopy(gStringVar1, sText_BattleMenu_Action_Fight);
            break;
            case BATTLE_ACTION_BAG:
                StringCopy(gStringVar1, sText_BattleMenu_Action_Bag);
            break;
            case BATTLE_ACTION_POKEMON:
                StringCopy(gStringVar1, sText_BattleMenu_Action_Pokemon);
            break;
            case BATTLE_ACTION_RUN:
                StringCopy(gStringVar1, sText_BattleMenu_Action_Run);
            break;
        }
        font = GetFontIdToFit(gStringVar1, FONT_SMALL, 0, BATTLE_WINDOW_ACTION_LIST_WIDTH);

        AddTextPrinterParameterized4(windowId, font, posX, posY + (i * 8), 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar1);
    }

    /*for(i = 0; i < NUM_BATTLE_ACTIONS; i++){
        switch(i){
            case BATTLE_ACTION_FIGHT:
                StringCopy(gStringVar1, sText_BattleMenu_Action_Fight);
                offset = 0;
                posY   = BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y;
            break;
            case BATTLE_ACTION_BAG:
                StringCopy(gStringVar1, sText_BattleMenu_Action_Bag);
                offset = BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_X_OFFSET;
                posY   = BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y;
            break;
            case BATTLE_ACTION_POKEMON:
                StringCopy(gStringVar1, sText_BattleMenu_Action_Pokemon);
                offset = 0;
                posY   = BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y + BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y_OFFSET;
            break;
            case BATTLE_ACTION_RUN:
                StringCopy(gStringVar1, sText_BattleMenu_Action_Run);
                offset = BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_X_OFFSET;
                posY   = BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y + BATTLE_WINDOW_SQUARE_SIZE_FIGHT_START_Y_OFFSET;
            break;
        }
        AddTextPrinterParameterized4(windowId, FONT_SMALL, posX + offset, posY, 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar1);

        if(gActionSelectionCursor[battler] == i)
            BlitBitmapToWindow(windowId, sBattleSelector_Actions, posX + offset - 8, posY, 8, 16);
    }*/

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

#define BATTLE_WINDOW_MOVE_LIST_X 16
#define BATTLE_WINDOW_MOVE_LIST_Y 4
#define BATTLE_WINDOW_MOVE_LIST_X_OFFSET 72
#define BATTLE_WINDOW_MOVE_LIST_WIDTH 64
#define BATTLE_WINDOW_MOVE_LIST_PP_WIDTH 40
const u8 sText_BattleMenu_Action_PP_Left[]   = _("{PP}{STR_VAR_1}/{STR_VAR_2}");
const u8 sText_BattleMenu_Action_Power[]   = _("Power: {STR_VAR_1} Accuracy:{STR_VAR_2}");

const u8 sText_BattleMenu_Action_Type_Eff_x1[]     = _("Type: {STR_VAR_1}");
const u8 sText_BattleMenu_Action_Type_Eff_x2[]     = _("Type: {STR_VAR_1}+");
const u8 sText_BattleMenu_Action_Type_Eff_x4[]     = _("Type: {STR_VAR_1}++");
const u8 sText_BattleMenu_Action_Type_Eff_x8[]     = _("Type: {STR_VAR_1}+++");
const u8 sText_BattleMenu_Action_Type_Eff_x05[]    = _("Type: {STR_VAR_1}-");
const u8 sText_BattleMenu_Action_Type_Eff_x025[]   = _("Type: {STR_VAR_1}--");
const u8 sText_BattleMenu_Action_Type_Eff_x0125[]  = _("Type: {STR_VAR_1}---");
const u8 sText_BattleMenu_Action_Type_Eff_x0[]     = _("Type: {STR_VAR_1}X");

// Order based numerically, with EFFECTIVENESS_CANNOT_VIEW at 0 to always prioritize any other effectiveness during comparison
enum
{
    EFFECTIVENESS_CANNOT_VIEW,
    EFFECTIVENESS_NO_EFFECT,
    EFFECTIVENESS_NOT_VERY_EFFECTIVE,
    EFFECTIVENESS_NORMAL,
    EFFECTIVENESS_SUPER_EFFECTIVE,
};

void PrintBattleWindow_MoveWindow(u32 battler, bool8 isSelecting)
{
    u8 i, posX, posY, maxPP, currPP, battlerDef;
    u8 windowId = B_WIN_ACTION_PROMPT;
    u8 font = FONT_NORMAL;
    u8 fontColor = FONT_BLACK;
    u16 currMove = gBattleMons[battler].moves[gMoveSelectionCursor[battler]];
    uq4_12_t modifier = UQ_4_12(1.0);
    RestoreBattleMenuBg();

    //Fill the window with the fill value
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    // Print Fight / Pokémon / Bag / Run Text
    posX = BATTLE_WINDOW_MOVE_LIST_X;
    posY = BATTLE_WINDOW_MOVE_LIST_Y;

    for(i = 0; i < NUM_BATTLE_ACTIONS; i++){
        //Cursor
        if(gMoveSelectionCursor[battler] == i)
            BlitBitmapToWindow(windowId, sBattleSelector_Moves, posX - 8, posY + (i * 8) + 4, 8, 8);

        //Move Name
        StringCopy(gStringVar1, GetMoveName(gBattleMons[battler].moves[i]));
        font = GetFontIdToFit(gStringVar1, FONT_SMALL, 0, BATTLE_WINDOW_MOVE_LIST_WIDTH);

        AddTextPrinterParameterized4(windowId, font, posX, posY + (i * 8), 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar1);
        //PP Left
        currPP = gBattleMons[battler].pp[i];
        maxPP  = CalculatePPWithBonus(gBattleMons[battler].moves[i], gBattleMons[battler].ppBonuses, i);
	    ConvertIntToDecimalStringN(gStringVar1, currPP, STR_CONV_MODE_LEFT_ALIGN, 3);
	    ConvertIntToDecimalStringN(gStringVar2, maxPP,  STR_CONV_MODE_LEFT_ALIGN, 3);
	    StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_PP_Left);

        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, (posX + BATTLE_WINDOW_MOVE_LIST_WIDTH + 4), posY + (i * 8), 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar4);
    }

    //Move Description
    StringCopy(gStringVar1, GetMoveDescription(currMove));
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, (posX + BATTLE_WINDOW_MOVE_LIST_WIDTH + BATTLE_WINDOW_MOVE_LIST_PP_WIDTH + 8), posY, 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar1);

    //Power & Accuracy
    currPP = GetMovePower(currMove);
    maxPP  = GetMoveAccuracy(currMove);
	ConvertIntToDecimalStringN(gStringVar1, currPP, STR_CONV_MODE_LEFT_ALIGN, 3);
	ConvertIntToDecimalStringN(gStringVar2, maxPP,  STR_CONV_MODE_LEFT_ALIGN, 3);
	StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Power);

    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, (posX + BATTLE_WINDOW_MOVE_LIST_WIDTH + BATTLE_WINDOW_MOVE_LIST_PP_WIDTH + 8), posY + 16, 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar4);

    //Type
    currPP = GetMoveType(currMove);
    StringCopy(gStringVar1, gTypesInfo[currPP].name);

    if (B_SHOW_EFFECTIVENESS){
        if(IsDoubleBattle() && isSelecting)
            battlerDef = GetBattlerPosition(gMultiUsePlayerCursor);
        else
            battlerDef = BATTLE_OPPOSITE(battler);

        modifier = CheckTypeEffectivenessMod(battler, battlerDef, currMove);

        if (modifier == UQ_4_12(0.0))
            StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x0); // No effect
        else if (modifier <= UQ_4_12(0.125))
            StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x0125); // Not very effective
        else if (modifier <= UQ_4_12(0.25))
            StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x025); // Not very effective
        else if (modifier <= UQ_4_12(0.5))
            StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x05); // Not very effective
        else if (modifier >= UQ_4_12(8.0))
            StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x4); // Super effective
        else if (modifier >= UQ_4_12(4.0))
            StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x4); // Super effective
        else if (modifier >= UQ_4_12(2.0))
            StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x2); // Super effective
        else
            StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x1);; // Normal effectiveness
    }
    else
	    StringExpandPlaceholders(gStringVar4, sText_BattleMenu_Action_Type_Eff_x1);

    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, (posX + BATTLE_WINDOW_MOVE_LIST_WIDTH + BATTLE_WINDOW_MOVE_LIST_PP_WIDTH + 8), posY + 24, 0, 0, sMenuWindowFontColors[fontColor], 0xFF, gStringVar4);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

void SetControllerToPlayer(u32 battler)
{
    gBattlerControllerEndFuncs[battler] = PlayerBufferExecCompleted;
    gBattlerControllerFuncs[battler] = PlayerBufferRunCommand;
    gDoingBattleAnim = FALSE;
    gPlayerDpadHoldFrames = 0;
}

void PlayerBufferExecCompleted(u32 battler)
{
    gBattlerControllerFuncs[battler] = PlayerBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(battler, B_COMM_CONTROLLER_IS_DONE, 4, &playerId);
        gBattleResources->bufferA[battler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        MarkBattleControllerIdleOnLocal(battler);
    }
}

static void PlayerBufferRunCommand(u32 battler)
{
    if (IsBattleControllerActiveOnLocal(battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sPlayerBufferCommands))
            sPlayerBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            BtlController_Complete(battler);
    }
}

static void CompleteOnBattlerSpritePosX_0(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].x2 == 0)
        BtlController_Complete(battler);
}

static u16 GetPrevBall(u16 ballId)
{
    s32 i;
    s32 index = ItemIdToBallId(ballId);
    u32 newBall = 0;
     for (i = 0; i < POKEBALL_COUNT; i++)
    {
        index--;
        if (index == -1)
            index = POKEBALL_COUNT - 1;
        newBall = gBallItemIds[index];
        if (CheckBagHasItem(newBall, 1))
            return newBall;
    }
    return ballId;
}

static u32 GetNextBall(u32 ballId)
{
    s32 i;
    s32 index = ItemIdToBallId(ballId);
    u32 newBall = 0;
    for (i = 0; i < POKEBALL_COUNT; i++)
    {
        index++;
        if (index == POKEBALL_COUNT)
            index = 0;
        newBall = gBallItemIds[index];
        if (CheckBagHasItem(newBall, 1))
            return newBall;
    }
    return ballId;
}

#define ENABLE_BATTLE_INPUT_GOING_BEYOND_SCREEN FALSE // No idea what to call this constant

static void HandleInputChooseAction(u32 battler)
{
    u8 windowId = B_WIN_ACTION_PROMPT;
    u16 itemId = gBattleResources->bufferA[battler][2] | (gBattleResources->bufferA[battler][3] << 8);
    u8 value = 0;

    DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
    DoBounceEffect(battler, BOUNCE_MON, 7, 1);

    if (JOY_REPEAT(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(L_BUTTON) && B_LAST_USED_BALL_BUTTON != L_BUTTON)
    {
        FlagToggle(FLAG_SYS_BATTLE_ACTION_WINDOW_INFO);
        VarSet(VAR_BATTLE_INFO_BATTLER, 0);
        PrintBattleWindow_ActionPromt(battler);
    }

    if (B_LAST_USED_BALL == TRUE && B_LAST_USED_BALL_CYCLE == TRUE
    && !(B_LAST_USED_BALL_BUTTON == L_BUTTON && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A))
    {
        if (!gLastUsedBallMenuPresent)
        {
            gBattleStruct->ackBallUseBtn = FALSE;
        }
        else if (JOY_NEW(B_LAST_USED_BALL_BUTTON))
        {
            gBattleStruct->ackBallUseBtn = TRUE;
            gBattleStruct->ballSwapped = FALSE;
            ArrowsChangeColorLastBallCycle(TRUE);
        }

        if (gBattleStruct->ackBallUseBtn)
        {
            if (JOY_HELD(B_LAST_USED_BALL_BUTTON) && (JOY_NEW(DPAD_DOWN) || JOY_NEW(DPAD_RIGHT)))
            {
                bool32 sameBall = FALSE;
                u32 nextBall = GetNextBall(gBallToDisplay);
                gBattleStruct->ballSwapped = TRUE;
                if (gBallToDisplay == nextBall)
                    sameBall = TRUE;
                else
                    gBallToDisplay = nextBall;
                SwapBallToDisplay(sameBall);
                PlaySE(SE_SELECT);
            }
            else if (JOY_HELD(B_LAST_USED_BALL_BUTTON) && (JOY_NEW(DPAD_UP) || JOY_NEW(DPAD_LEFT)))
            {
                bool32 sameBall = FALSE;
                u32 prevBall = GetPrevBall(gBallToDisplay);
                gBattleStruct->ballSwapped = TRUE;
                if (gBallToDisplay == prevBall)
                    sameBall = TRUE;
                else
                    gBallToDisplay = prevBall;
                SwapBallToDisplay(sameBall);
                PlaySE(SE_SELECT);
            }
            else if (JOY_NEW(B_BUTTON) || (!JOY_HELD(B_LAST_USED_BALL_BUTTON) && gBattleStruct->ballSwapped))
            {
                gBattleStruct->ackBallUseBtn = FALSE;
                gBattleStruct->ballSwapped = FALSE;
                ArrowsChangeColorLastBallCycle(FALSE);
            }
            else if (!JOY_HELD(B_LAST_USED_BALL_BUTTON) && CanThrowLastUsedBall())
            {
                gBattleStruct->ackBallUseBtn = FALSE;
                PlaySE(SE_SELECT);
                ArrowsChangeColorLastBallCycle(FALSE);
                TryHideLastUsedBall();
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_THROW_BALL, 0);
                BtlController_Complete(battler);
            }
            return;
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        TryHideLastUsedBall();
        ClearBattleWindow();

        switch (gActionSelectionCursor[battler])
        {
            case BATTLE_ACTION_FIGHT: // Top left
                //PrintBattleWindow_MoveWindow(battler, FALSE);
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_MOVE, 0);
                break;
            case BATTLE_ACTION_BAG: // Top right
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_ITEM, 0);
                break;
            case BATTLE_ACTION_POKEMON: // Bottom left
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
                break;
            case BATTLE_ACTION_RUN: // Bottom right
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_RUN, 0);
                break;
        }
        //PrintBattleWindow_ActionPromt(battler);
        BtlController_Complete(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if(FlagGet(FLAG_SYS_BATTLE_ACTION_WINDOW_INFO)){
            value = VarGet(VAR_BATTLE_INFO_BATTLER);
            if(value != 0)
                value--;
            
            VarSet(VAR_BATTLE_INFO_BATTLER, value);
            PrintBattleWindow_ActionPromt(battler);
        }
        /*if (gActionSelectionCursor[battler] & 1) // if is B_ACTION_USE_ITEM or B_ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            //ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
        PlaySE(SE_SELECT);
        switch(gActionSelectionCursor[battler]){
            case BATTLE_ACTION_FIGHT:
                if(ENABLE_BATTLE_INPUT_GOING_BEYOND_SCREEN)
                    gActionSelectionCursor[battler] = BATTLE_ACTION_BAG;
            break;
            case BATTLE_ACTION_BAG:
                gActionSelectionCursor[battler] = BATTLE_ACTION_FIGHT;
            break;
            case BATTLE_ACTION_POKEMON:
                if(ENABLE_BATTLE_INPUT_GOING_BEYOND_SCREEN)
                    gActionSelectionCursor[battler] = BATTLE_ACTION_RUN;
            break;
            case BATTLE_ACTION_RUN:
                gActionSelectionCursor[battler] = BATTLE_ACTION_POKEMON;
            break;
        }
        PrintBattleWindow_ActionPromt(battler);*/
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if(FlagGet(FLAG_SYS_BATTLE_ACTION_WINDOW_INFO)){
            value = VarGet(VAR_BATTLE_INFO_BATTLER);
            if(IsDoubleBattle()){
                if(value < MAX_BATTLERS_COUNT - 1)
                    value++;
            }
            else{
                if(value < 1)
                    value++;
            }
            
            VarSet(VAR_BATTLE_INFO_BATTLER, value);
            PrintBattleWindow_ActionPromt(battler);
        }
        /*if (!(gActionSelectionCursor[battler] & 1)) // if is B_ACTION_USE_MOVE or B_ACTION_SWITCH
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            //ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }

        PlaySE(SE_SELECT);
        switch(gActionSelectionCursor[battler]){
            case BATTLE_ACTION_FIGHT:
                gActionSelectionCursor[battler] = BATTLE_ACTION_BAG;
            break;
            case BATTLE_ACTION_BAG:
                gActionSelectionCursor[battler] = BATTLE_ACTION_FIGHT;
            break;
            case BATTLE_ACTION_POKEMON:
                gActionSelectionCursor[battler] = BATTLE_ACTION_RUN;
            break;
            case BATTLE_ACTION_RUN:
                if(ENABLE_BATTLE_INPUT_GOING_BEYOND_SCREEN)
                    gActionSelectionCursor[battler] = BATTLE_ACTION_POKEMON;
            break;
        }
        PrintBattleWindow_ActionPromt(battler);*/
    }
    else if (JOY_NEW(DPAD_UP))
    {
        /*if (gActionSelectionCursor[battler] & 2) // if is B_ACTION_SWITCH or B_ACTION_RUN
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            //ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }*/
        PlaySE(SE_SELECT);
        if(gActionSelectionCursor[battler] != 0)
            gActionSelectionCursor[battler]--;
        /*switch(gActionSelectionCursor[battler]){
            case BATTLE_ACTION_FIGHT:
                if(ENABLE_BATTLE_INPUT_GOING_BEYOND_SCREEN)
                    gActionSelectionCursor[battler] = BATTLE_ACTION_POKEMON;
            break;
            case BATTLE_ACTION_POKEMON:
                gActionSelectionCursor[battler] = BATTLE_ACTION_FIGHT;
            break;
            case BATTLE_ACTION_BAG:
                if(ENABLE_BATTLE_INPUT_GOING_BEYOND_SCREEN)
                    gActionSelectionCursor[battler] = BATTLE_ACTION_RUN;
            break;
            case BATTLE_ACTION_RUN:
                gActionSelectionCursor[battler] = BATTLE_ACTION_BAG;
            break;
        }*/
        PrintBattleWindow_ActionPromt(battler);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        /*if (!(gActionSelectionCursor[battler] & 2)) // if is B_ACTION_USE_MOVE or B_ACTION_USE_ITEM
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            //ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }*/
        PlaySE(SE_SELECT);
        if(gActionSelectionCursor[battler] < BATTLE_ACTION_RUN)
            gActionSelectionCursor[battler]++;
        /*switch(gActionSelectionCursor[battler]){
            case BATTLE_ACTION_FIGHT:
                gActionSelectionCursor[battler] = BATTLE_ACTION_POKEMON;
            break;
            case BATTLE_ACTION_POKEMON:
                if(ENABLE_BATTLE_INPUT_GOING_BEYOND_SCREEN)
                    gActionSelectionCursor[battler] = BATTLE_ACTION_FIGHT;
            break;
            case BATTLE_ACTION_BAG:
                gActionSelectionCursor[battler] = BATTLE_ACTION_RUN;
            break;
            case BATTLE_ACTION_RUN:
                if(ENABLE_BATTLE_INPUT_GOING_BEYOND_SCREEN)
                    gActionSelectionCursor[battler] = BATTLE_ACTION_BAG;
            break;
        }*/
        PrintBattleWindow_ActionPromt(battler);
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

        if (IsDoubleBattle()
         && GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT
         && !(gAbsentBattlerFlags & (1u << GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)))
         && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            // Return item to bag if partner had selected one (if consumable).
            if (gBattleResources->bufferA[battler][1] == B_ACTION_USE_ITEM && GetItemConsumability(itemId))
            {
                AddBagItem(itemId, 1);
            }
            PlaySE(SE_SELECT);
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_CANCEL_PARTNER, 0);
            BtlController_Complete(battler);
        }
        else if (B_QUICK_MOVE_CURSOR_TO_RUN)
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER)) // If wild battle, pressing B moves cursor to "Run".
            {
                PlaySE(SE_SELECT);
                //ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
                gActionSelectionCursor[battler] = 3;
                //ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
            }
        }
    }
    else if (JOY_NEW(START_BUTTON))
    {
        //SwapHpBarsWithHpText();
    }
    else if (DEBUG_BATTLE_MENU == TRUE && JOY_NEW(SELECT_BUTTON))
    {
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_DEBUG, 0);
        BtlController_Complete(battler);
    }
    else if (B_LAST_USED_BALL == TRUE && B_LAST_USED_BALL_CYCLE == FALSE
             && JOY_NEW(B_LAST_USED_BALL_BUTTON) && CanThrowLastUsedBall())
    {
        PlaySE(SE_SELECT);
        TryHideLastUsedBall();
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_THROW_BALL, 0);
        BtlController_Complete(battler);
    }
}

void HandleInputChooseTarget(u32 battler)
{
    s32 i;
    static const u8 identities[MAX_BATTLERS_COUNT] = {B_POSITION_PLAYER_LEFT, B_POSITION_PLAYER_RIGHT, B_POSITION_OPPONENT_RIGHT, B_POSITION_OPPONENT_LEFT};
    u16 move = GetMonData(GetBattlerMon(battler), MON_DATA_MOVE1 + gMoveSelectionCursor[battler]);
    u16 moveTarget = GetBattlerMoveTargetType(battler, move);

    DoBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX, 15, 1);
    for (i = 0; i < gBattlersCount; i++)
    {
        if (i != gMultiUsePlayerCursor)
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
    }

    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON))
    {
        ClearBattleWindow();
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;
        if (gBattleStruct->gimmick.playerSelect)
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, gMoveSelectionCursor[battler] | RET_GIMMICK | (gMultiUsePlayerCursor << 8));
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, gMoveSelectionCursor[battler] | (gMultiUsePlayerCursor << 8));
        EndBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX);
        TryHideLastUsedBall();
        HideGimmickTriggerSprite();
        BtlController_Complete(battler);
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        if (gBattleStruct->gimmick.playerSelect == 1 && gBattleStruct->gimmick.usableGimmick[battler] == GIMMICK_Z_MOVE)
        {
            gBattleStruct->gimmick.playerSelect = 0;
            gBattleStruct->zmove.viewing = TRUE;
            ReloadMoveNames(battler);
        }
        //TryToAddMoveInfoWindow();
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
        EndBounceEffect(gMultiUsePlayerCursor, BOUNCE_HEALTHBOX);
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_UP))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;

        if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY))
        {
            gMultiUsePlayerCursor ^= BIT_FLANK;
        }
        else
        {
            do
            {
                u8 currSelIdentity = GetBattlerPosition(gMultiUsePlayerCursor);

                for (i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    if (currSelIdentity == identities[i])
                        break;
                }
                do
                {
                    if (--i < 0)
                        i = MAX_BATTLERS_COUNT - 1;
                    gMultiUsePlayerCursor = GetBattlerAtPosition(identities[i]);
                } while (gMultiUsePlayerCursor == gBattlersCount);

                i = 0;
                switch (GetBattlerPosition(gMultiUsePlayerCursor))
                {
                case B_POSITION_PLAYER_LEFT:
                case B_POSITION_PLAYER_RIGHT:
                    if (battler != gMultiUsePlayerCursor)
                        i++;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                case B_POSITION_OPPONENT_RIGHT:
                    i++;
                    break;
                }
                if (B_SHOW_EFFECTIVENESS)
                    MoveSelectionDisplayMoveEffectiveness(CheckTypeEffectiveness(battler, GetBattlerPosition(gMultiUsePlayerCursor)), battler);

                if (gAbsentBattlerFlags & (1u << gMultiUsePlayerCursor)
                 || !CanTargetBattler(battler, gMultiUsePlayerCursor, move)
                 || (moveTarget & MOVE_TARGET_OPPONENT && IsOnPlayerSide(gMultiUsePlayerCursor)))
                    i = 0;
            } while (i == 0);
        }
        PrintBattleWindow_MoveWindow(battler, TRUE);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_ShowAsMoveTarget;
    }
    else if (JOY_NEW(DPAD_RIGHT | DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_HideAsMoveTarget;

        if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY))
        {
            gMultiUsePlayerCursor ^= BIT_FLANK;
        }
        else
        {
            do
            {
                u8 currSelIdentity = GetBattlerPosition(gMultiUsePlayerCursor);

                for (i = 0; i < MAX_BATTLERS_COUNT; i++)
                {
                    if (currSelIdentity == identities[i])
                        break;
                }
                do
                {
                    if (++i > 3)
                        i = 0;
                    gMultiUsePlayerCursor = GetBattlerAtPosition(identities[i]);
                } while (gMultiUsePlayerCursor == gBattlersCount);

                i = 0;
                switch (GetBattlerPosition(gMultiUsePlayerCursor))
                {
                case B_POSITION_PLAYER_LEFT:
                case B_POSITION_PLAYER_RIGHT:
                    if (battler != gMultiUsePlayerCursor)
                        i++;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                case B_POSITION_OPPONENT_RIGHT:
                    i++;
                    break;
                }
                if (B_SHOW_EFFECTIVENESS)
                    MoveSelectionDisplayMoveEffectiveness(CheckTypeEffectiveness(battler, GetBattlerPosition(gMultiUsePlayerCursor)), battler);

                if (gAbsentBattlerFlags & (1u << gMultiUsePlayerCursor)
                 || !CanTargetBattler(battler, gMultiUsePlayerCursor, move)
                 || (moveTarget & MOVE_TARGET_OPPONENT && IsOnPlayerSide(gMultiUsePlayerCursor)))
                    i = 0;
            } while (i == 0);
        }

        PrintBattleWindow_MoveWindow(battler, TRUE);
        gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_ShowAsMoveTarget;
    }
}

static void HideAllTargets(void)
{
    s32 i;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (IsBattlerAlive(i) && gBattleSpritesDataPtr->healthBoxesData[i].healthboxIsBouncing)
        {
            gSprites[gBattlerSpriteIds[i]].callback = SpriteCB_HideAsMoveTarget;
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
        }
    }
}

static void HideShownTargets(u32 battler)
{
    s32 i;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (IsBattlerAlive(i) && gBattleSpritesDataPtr->healthBoxesData[i].healthboxIsBouncing && i != battler)
        {
            gSprites[gBattlerSpriteIds[i]].callback = SpriteCB_HideAsMoveTarget;
            EndBounceEffect(i, BOUNCE_HEALTHBOX);
        }
    }
}

void HandleInputShowEntireFieldTargets(u32 battler)
{
    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        HideAllTargets();
        if (gBattleStruct->gimmick.playerSelect)
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, gMoveSelectionCursor[battler] | RET_GIMMICK | (gMultiUsePlayerCursor << 8));
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, gMoveSelectionCursor[battler] | (gMultiUsePlayerCursor << 8));
        HideGimmickTriggerSprite();
        BtlController_Complete(battler);
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        HideAllTargets();
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    }
}

void HandleInputShowTargets(u32 battler)
{
    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        HideShownTargets(battler);
        if (gBattleStruct->gimmick.playerSelect)
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, gMoveSelectionCursor[battler] | RET_GIMMICK | (gMultiUsePlayerCursor << 8));
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, gMoveSelectionCursor[battler] | (gMultiUsePlayerCursor << 8));
        HideGimmickTriggerSprite();
        TryHideLastUsedBall();
        BtlController_Complete(battler);
    }
    else if (JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)
    {
        PlaySE(SE_SELECT);
        HideShownTargets(battler);
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 7, 1);
        DoBounceEffect(battler, BOUNCE_MON, 7, 1);
    }
}

static void TryShowAsTarget(u32 battler)
{
    if (IsBattlerAlive(battler))
    {
        DoBounceEffect(battler, BOUNCE_HEALTHBOX, 15, 1);
        gSprites[gBattlerSpriteIds[battler]].callback = SpriteCB_ShowAsMoveTarget;
    }
}

void HandleInputChooseMove(u32 battler)
{
    u16 moveTarget;
    u32 canSelectTarget = 0;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);

    if (JOY_HELD(DPAD_ANY) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        gPlayerDpadHoldFrames++;
    else
        gPlayerDpadHoldFrames = 0;

    if (JOY_NEW(A_BUTTON) && !gBattleStruct->descriptionSubmenu)
    {
        //TryToHideMoveInfoWindow();
        PlaySE(SE_SELECT);
        ClearBattleWindow();

        moveTarget = GetBattlerMoveTargetType(battler, moveInfo->moves[gMoveSelectionCursor[battler]]);

        if (gBattleStruct->zmove.viewing)
        {
            gBattleStruct->zmove.viewing = FALSE;
            if (GetMoveCategory(moveInfo->moves[gMoveSelectionCursor[battler]]) != DAMAGE_CATEGORY_STATUS)
                moveTarget = MOVE_TARGET_SELECTED;  //damaging z moves always have selected target
        }

        // Status moves turn into Max Guard when Dynamaxed, targets user.
        if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX || IsGimmickSelected(battler, GIMMICK_DYNAMAX))
            moveTarget = GetMoveTarget(GetMaxMove(battler, moveInfo->moves[gMoveSelectionCursor[battler]]));

        if (moveTarget & MOVE_TARGET_USER)
            gMultiUsePlayerCursor = battler;
        else
            gMultiUsePlayerCursor = GetOpposingSideBattler(battler);

        if (gBattleResources->bufferA[battler][1]) // a double battle
        {
            if (!(moveTarget & (MOVE_TARGET_RANDOM | MOVE_TARGET_BOTH | MOVE_TARGET_DEPENDS | MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_USER | MOVE_TARGET_ALLY)))
                canSelectTarget = 1; // either selected or user
            if (moveTarget == (MOVE_TARGET_USER | MOVE_TARGET_ALLY) && IsBattlerAlive(BATTLE_PARTNER(battler)))
                canSelectTarget = 1;

            if (moveInfo->currentPp[gMoveSelectionCursor[battler]] == 0)
            {
                canSelectTarget = 0;
            }
            else if (!(moveTarget & MOVE_TARGET_USER) && CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER, battler) <= 1)
            {
                gMultiUsePlayerCursor = GetDefaultMoveTarget(battler);
                canSelectTarget = 0;
            }

            PrintBattleWindow_MoveWindow(battler, TRUE);

            if (B_SHOW_TARGETS == TRUE)
            {
                // Show all available targets for multi-target moves
                if ((moveTarget & MOVE_TARGET_ALL_BATTLERS) == MOVE_TARGET_ALL_BATTLERS)
                {
                    u32 i = 0;
                    for (i = 0; i < gBattlersCount; i++)
                        TryShowAsTarget(i);

                    canSelectTarget = 3;
                }
                else if (moveTarget & (MOVE_TARGET_OPPONENTS_FIELD | MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY))
                {
                    TryShowAsTarget(gMultiUsePlayerCursor);
                    TryShowAsTarget(BATTLE_PARTNER(gMultiUsePlayerCursor));
                    if (moveTarget & MOVE_TARGET_FOES_AND_ALLY)
                        TryShowAsTarget(BATTLE_PARTNER(battler));
                    canSelectTarget = 2;
                }
            }
        }

        switch (canSelectTarget)
        {
        case 0:
        default:
            if (gBattleStruct->gimmick.playerSelect)
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, gMoveSelectionCursor[battler] | RET_GIMMICK | (gMultiUsePlayerCursor << 8));
            else
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, gMoveSelectionCursor[battler] | (gMultiUsePlayerCursor << 8));
            HideGimmickTriggerSprite();
            TryHideLastUsedBall();
            BtlController_Complete(battler);
            break;
        case 1:
            gBattlerControllerFuncs[battler] = HandleInputChooseTarget;

            if (moveTarget & MOVE_TARGET_USER)
                gMultiUsePlayerCursor = battler;
            else if (gAbsentBattlerFlags & (1u << GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)))
                gMultiUsePlayerCursor = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            else
                gMultiUsePlayerCursor = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTypeEffectiveness(battler, GetBattlerPosition(gMultiUsePlayerCursor)), battler);

            gSprites[gBattlerSpriteIds[gMultiUsePlayerCursor]].callback = SpriteCB_ShowAsMoveTarget;
            break;
        case 2:
            gBattlerControllerFuncs[battler] = HandleInputShowTargets;
            break;
        case 3: // Entire field
            gBattlerControllerFuncs[battler] = HandleInputShowEntireFieldTargets;
            break;
        }
    }
    else if ((JOY_NEW(B_BUTTON) || gPlayerDpadHoldFrames > 59)  && !gBattleStruct->descriptionSubmenu)
    {
        PlaySE(SE_SELECT);
        gBattleStruct->gimmick.playerSelect = FALSE;
        if (gBattleStruct->zmove.viewing)
        {
            ReloadMoveNames(battler);
            ChangeGimmickTriggerSprite(gBattleStruct->gimmick.triggerSpriteId, gBattleStruct->gimmick.playerSelect);
        }
        else
        {
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, 0xFFFF);
            HideGimmickTriggerSprite();
            BtlController_Complete(battler);
            //TryToHideMoveInfoWindow();
        }
    }
    else if (JOY_NEW(DPAD_LEFT) && !gBattleStruct->zmove.viewing)
    {
        PrintBattleWindow_MoveWindow(battler, FALSE);
        /*if (gMoveSelectionCursor[battler] & 1)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
            gMoveSelectionCursor[battler] ^= 1;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
            TryMoveSelectionDisplayMoveDescription(battler);
            TryChangeZTrigger(battler, gMoveSelectionCursor[battler]);
        }*/
    }
    else if (JOY_NEW(DPAD_RIGHT) && !gBattleStruct->zmove.viewing)
    {
        PrintBattleWindow_MoveWindow(battler, FALSE);
        /*if (!(gMoveSelectionCursor[battler] & 1)
         && (gMoveSelectionCursor[battler] ^ 1) < gNumberOfMovesToChoose)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
            gMoveSelectionCursor[battler] ^= 1;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
            TryMoveSelectionDisplayMoveDescription(battler);
            TryChangeZTrigger(battler, gMoveSelectionCursor[battler]);
        }*/
    }
    else if (JOY_NEW(DPAD_UP) && !gBattleStruct->zmove.viewing)
    {
        if(gMoveSelectionCursor[battler] != 0){
            gMoveSelectionCursor[battler]--;
            PrintBattleWindow_MoveWindow(battler, FALSE);
            PlaySE(SE_SELECT);
        }
        /*if (gMoveSelectionCursor[battler] & 2)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
            gMoveSelectionCursor[battler] ^= 2;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
            TryMoveSelectionDisplayMoveDescription(battler);
            TryChangeZTrigger(battler, gMoveSelectionCursor[battler]);
        }*/
    }
    else if (JOY_NEW(DPAD_DOWN) && !gBattleStruct->zmove.viewing)
    {
        if(gMoveSelectionCursor[battler] < MAX_MON_MOVES - 1){
            gMoveSelectionCursor[battler]++;
            PrintBattleWindow_MoveWindow(battler, FALSE);
            PlaySE(SE_SELECT);
        }
        /*if (!(gMoveSelectionCursor[battler] & 2)
         && (gMoveSelectionCursor[battler] ^ 2) < gNumberOfMovesToChoose)
        {
            MoveSelectionDestroyCursorAt(gMoveSelectionCursor[battler]);
            gMoveSelectionCursor[battler] ^= 2;
            PlaySE(SE_SELECT);
            MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
            TryMoveSelectionDisplayMoveDescription(battler);
            TryChangeZTrigger(battler, gMoveSelectionCursor[battler]);
        }*/
    }
    else if (B_MOVE_REARRANGEMENT_IN_BATTLE < GEN_4 && JOY_NEW(SELECT_BUTTON) && !gBattleStruct->zmove.viewing && !gBattleStruct->descriptionSubmenu)
    {
        if (gNumberOfMovesToChoose > 1 && !(gBattleTypeFlags & BATTLE_TYPE_LINK))
        {
            //MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);

            if (gMoveSelectionCursor[battler] != 0)
                gMultiUsePlayerCursor = 0;
            else
                gMultiUsePlayerCursor = gMoveSelectionCursor[battler] + 1;

            //MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
            BattlePutTextOnWindow(gText_BattleSwitchWhich, B_WIN_SWITCH_PROMPT);
            gBattlerControllerFuncs[battler] = HandleMoveSwitching;
        }
    }
    /*else if (gBattleStruct->descriptionSubmenu)
    {
        if (JOY_NEW(B_MOVE_DESCRIPTION_BUTTON) || JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        {
            gBattleStruct->descriptionSubmenu = FALSE;
            if (gCategoryIconSpriteId != 0xFF)
            {
                DestroySprite(&gSprites[gCategoryIconSpriteId]);
                gCategoryIconSpriteId = 0xFF;
            }

            FillWindowPixelBuffer(B_WIN_MOVE_DESCRIPTION, PIXEL_FILL(0));
            ClearStdWindowAndFrame(B_WIN_MOVE_DESCRIPTION, FALSE);
            CopyWindowToVram(B_WIN_MOVE_DESCRIPTION, COPYWIN_GFX);
            PlaySE(SE_SELECT);
            if (B_SHOW_EFFECTIVENESS)
                MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
            MoveSelectionDisplayPpNumber(battler);
            MoveSelectionDisplayMoveType(battler);
        }
    }
    else if (JOY_NEW(B_MOVE_DESCRIPTION_BUTTON) &&
        !(B_MOVE_DESCRIPTION_BUTTON == L_BUTTON && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A))
    {
        gBattleStruct->descriptionSubmenu = TRUE;
        TryMoveSelectionDisplayMoveDescription(battler);
    }*/
    else if (JOY_NEW(START_BUTTON))
    {
        if (gBattleStruct->gimmick.usableGimmick[battler] != GIMMICK_NONE
            && !HasTrainerUsedGimmick(battler, gBattleStruct->gimmick.usableGimmick[battler])
            && !(gBattleStruct->gimmick.usableGimmick[battler] == GIMMICK_Z_MOVE
                 && GetUsableZMove(battler, moveInfo->moves[gMoveSelectionCursor[battler]]) == MOVE_NONE))
        {
            gBattleStruct->gimmick.playerSelect ^= 1;
            ReloadMoveNames(battler);
            ChangeGimmickTriggerSprite(gBattleStruct->gimmick.triggerSpriteId, gBattleStruct->gimmick.playerSelect);
            PlaySE(SE_SELECT);
        }
    }
}

static void ReloadMoveNames(u32 battler)
{
    if (gBattleStruct->zmove.viable && !gBattleStruct->zmove.viewing)
    {
        struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
        MoveSelectionDisplayZMove(GetUsableZMove(battler, moveInfo->moves[gMoveSelectionCursor[battler]]), battler);
    }
    else
    {
        gBattleStruct->zmove.viewing = FALSE;
        //MoveSelectionDestroyCursorAt(battler);
        //MoveSelectionDisplayMoveNames(battler);
        //MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
        if (B_SHOW_EFFECTIVENESS)
            MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
        MoveSelectionDisplayPpNumber(battler);
        MoveSelectionDisplayMoveType(battler);
    }
}

void HandleMoveSwitching(u32 battler)
{
    //Testo
    u8 perMovePPBonuses[MAX_MON_MOVES];
    struct ChooseMoveStruct moveStruct;
    u8 totalPPBonuses;

    if (JOY_NEW(A_BUTTON | SELECT_BUTTON))
    {
        struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
        PlaySE(SE_SELECT);

        if (gMoveSelectionCursor[battler] != gMultiUsePlayerCursor)
        {
            struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
            s32 i;

            // swap moves and pp
            i = moveInfo->moves[gMoveSelectionCursor[battler]];
            moveInfo->moves[gMoveSelectionCursor[battler]] = moveInfo->moves[gMultiUsePlayerCursor];
            moveInfo->moves[gMultiUsePlayerCursor] = i;

            i = moveInfo->currentPp[gMoveSelectionCursor[battler]];
            moveInfo->currentPp[gMoveSelectionCursor[battler]] = moveInfo->currentPp[gMultiUsePlayerCursor];
            moveInfo->currentPp[gMultiUsePlayerCursor] = i;

            i = moveInfo->maxPp[gMoveSelectionCursor[battler]];
            moveInfo->maxPp[gMoveSelectionCursor[battler]] = moveInfo->maxPp[gMultiUsePlayerCursor];
            moveInfo->maxPp[gMultiUsePlayerCursor] = i;

            if (gDisableStructs[battler].mimickedMoves & (1u << gMoveSelectionCursor[battler]))
            {
                gDisableStructs[battler].mimickedMoves &= ~(1u << gMoveSelectionCursor[battler]);
                gDisableStructs[battler].mimickedMoves |= 1u << gMultiUsePlayerCursor;
            }

            MoveSelectionDisplayMoveNames(battler);

            for (i = 0; i < MAX_MON_MOVES; i++)
                perMovePPBonuses[i] = (gBattleMons[battler].ppBonuses & (3 << (i * 2))) >> (i * 2);

            totalPPBonuses = perMovePPBonuses[gMoveSelectionCursor[battler]];
            perMovePPBonuses[gMoveSelectionCursor[battler]] = perMovePPBonuses[gMultiUsePlayerCursor];
            perMovePPBonuses[gMultiUsePlayerCursor] = totalPPBonuses;

            totalPPBonuses = 0;
            for (i = 0; i < MAX_MON_MOVES; i++)
                totalPPBonuses |= perMovePPBonuses[i] << (i * 2);

            gBattleMons[battler].ppBonuses = totalPPBonuses;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                gBattleMons[battler].moves[i] = moveInfo->moves[i];
                gBattleMons[battler].pp[i] = moveInfo->currentPp[i];
            }

            if (!(gBattleMons[battler].volatiles.transformed))
            {
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    moveStruct.moves[i] = GetMonData(GetBattlerMon(battler), MON_DATA_MOVE1 + i);
                    moveStruct.currentPp[i] = GetMonData(GetBattlerMon(battler), MON_DATA_PP1 + i);
                }

                totalPPBonuses = GetMonData(GetBattlerMon(battler), MON_DATA_PP_BONUSES);
                for (i = 0; i < MAX_MON_MOVES; i++)
                    perMovePPBonuses[i] = (totalPPBonuses & (3 << (i * 2))) >> (i * 2);

                i = moveStruct.moves[gMoveSelectionCursor[battler]];
                moveStruct.moves[gMoveSelectionCursor[battler]] = moveStruct.moves[gMultiUsePlayerCursor];
                moveStruct.moves[gMultiUsePlayerCursor] = i;

                i = moveStruct.currentPp[gMoveSelectionCursor[battler]];
                moveStruct.currentPp[gMoveSelectionCursor[battler]] = moveStruct.currentPp[gMultiUsePlayerCursor];
                moveStruct.currentPp[gMultiUsePlayerCursor] = i;

                totalPPBonuses = perMovePPBonuses[gMoveSelectionCursor[battler]];
                perMovePPBonuses[gMoveSelectionCursor[battler]] = perMovePPBonuses[gMultiUsePlayerCursor];
                perMovePPBonuses[gMultiUsePlayerCursor] = totalPPBonuses;

                totalPPBonuses = 0;
                for (i = 0; i < MAX_MON_MOVES; i++)
                    totalPPBonuses |= perMovePPBonuses[i] << (i * 2);

                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    SetMonData(GetBattlerMon(battler), MON_DATA_MOVE1 + i, &moveStruct.moves[i]);
                    SetMonData(GetBattlerMon(battler), MON_DATA_PP1 + i, &moveStruct.currentPp[i]);
                }

                SetMonData(GetBattlerMon(battler), MON_DATA_PP_BONUSES, &totalPPBonuses);
            }
        }

        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        gMoveSelectionCursor[battler] = gMultiUsePlayerCursor;
        //MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
        if (B_SHOW_EFFECTIVENESS)
            MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
        else
            MoveSelectionDisplayPpString(battler);
        MoveSelectionDisplayPpNumber(battler);
        MoveSelectionDisplayMoveType(battler);
        AssignUsableZMoves(battler, moveInfo->moves);
    }
    else if (JOY_NEW(B_BUTTON | SELECT_BUTTON))
    {
        PlaySE(SE_SELECT);
        MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);
        //MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
        if (B_SHOW_EFFECTIVENESS)
            MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
        else
            MoveSelectionDisplayPpString(battler);
        MoveSelectionDisplayPpNumber(battler);
        MoveSelectionDisplayMoveType(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gMultiUsePlayerCursor & 1)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 1;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gMultiUsePlayerCursor & 1) && (gMultiUsePlayerCursor ^ 1) < gNumberOfMovesToChoose)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 1;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gMultiUsePlayerCursor & 2)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 2;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gMultiUsePlayerCursor & 2) && (gMultiUsePlayerCursor ^ 2) < gNumberOfMovesToChoose)
        {
            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 29);
            else
                MoveSelectionDestroyCursorAt(gMultiUsePlayerCursor);

            gMultiUsePlayerCursor ^= 2;
            PlaySE(SE_SELECT);

            if (gMultiUsePlayerCursor == gMoveSelectionCursor[battler])
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 0);
            else
                MoveSelectionCreateCursorAt(gMultiUsePlayerCursor, 27);
        }
    }
}

static void SetLinkBattleEndCallbacks(u32 battler)
{
    if (gWirelessCommType == 0)
    {
        if (gReceivedRemoteLinkPlayers == 0)
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            gMain.inBattle = FALSE;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(CB2_InitEndLinkBattle);
            if (gBattleOutcome == B_OUTCOME_WON)
                TryPutLinkBattleTvShowOnAir();
            FreeAllWindowBuffers();
        }
    }
    else
    {
        if (IsLinkTaskFinished())
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            gMain.inBattle = FALSE;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(CB2_InitEndLinkBattle);
            if (gBattleOutcome == B_OUTCOME_WON)
                TryPutLinkBattleTvShowOnAir();
            FreeAllWindowBuffers();
        }
    }
}

// Despite handling link battles separately, this is only ever used by link battles
void SetBattleEndCallbacks(u32 battler)
{
    if (!gPaletteFade.active)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (IsLinkTaskFinished())
            {
                if (gWirelessCommType == 0)
                    SetCloseLinkCallback();
                else
                    SetLinkStandbyCallback();

                gBattlerControllerFuncs[battler] = SetLinkBattleEndCallbacks;
            }
        }
        else
        {
            m4aSongNumStop(SE_LOW_HEALTH);
            gMain.inBattle = FALSE;
            gMain.callback1 = gPreBattleCallback1;
            SetMainCallback2(gMain.savedCallback);
        }
    }
}

static void Intro_WaitForShinyAnimAndHealthbox(u32 battler)
{
    bool8 healthboxAnimDone = FALSE;

    // Check if healthbox has finished sliding in
    if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy
         && gSprites[gHealthboxSpriteIds[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
    }
    else
    {
        if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
            healthboxAnimDone = TRUE;
    }

    // If healthbox and shiny anim are done
    if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
        && gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim)
    {
        // Reset shiny anim (even if it didn't occur)
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].finishedShinyMonAnim = FALSE;
        FreeShinyStars();

        HandleLowHpMusicChange(GetBattlerMon(battler), battler);

        if (TwoPlayerIntroMons(battler))
            HandleLowHpMusicChange(GetBattlerMon(BATTLE_PARTNER(battler)), BATTLE_PARTNER(battler));

        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = BtlController_Intro_DelayAndEnd;
    }
}

static void Intro_TryShinyAnimShowHealthbox(u32 battler)
{
    bool32 bgmRestored = FALSE;
    bool32 battlerAnimsDone = FALSE;

    // Start shiny animation if applicable for 1st Pokémon
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, GetBattlerMon(battler));

    // Start shiny animation if applicable for 2nd Pokémon
    if (!gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
        TryShinyAnimation(BATTLE_PARTNER(battler), GetBattlerMon(BATTLE_PARTNER(battler)));

    // Show healthbox after ball anim
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted)
        {
            if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], GetBattlerMon(BATTLE_PARTNER(battler)), HEALTHBOX_ALL);
                StartHealthboxSlideIn(BATTLE_PARTNER(battler));
                SetHealthboxSpriteVisible(gHealthboxSpriteIds[BATTLE_PARTNER(battler)]);
            }
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
            StartHealthboxSlideIn(battler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = TRUE;
    }

    // Restore bgm after cry has played and healthbox anim is started
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].waitForCry
        && gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted
        && !gBattleSpritesDataPtr->healthBoxesData[BATTLE_PARTNER(battler)].waitForCry
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
                m4aMPlayContinue(&gMPlayInfo_BGM);
            else
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = TRUE;
        bgmRestored = TRUE;
    }

    // Wait for battler anims
    if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[BATTLE_PARTNER(battler)]].callback == SpriteCallbackDummy)
        {
            battlerAnimsDone = TRUE;
        }
    }
    else
    {
        if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
            && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
        {
            battlerAnimsDone = TRUE;
        }
    }

    // Clean up
    if (bgmRestored && battlerAnimsDone)
    {
        if (TwoPlayerIntroMons(battler) && !(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            DestroySprite(&gSprites[gBattleControllerData[BATTLE_PARTNER(battler)]]);
        DestroySprite(&gSprites[gBattleControllerData[battler]]);

        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;

        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

void Task_PlayerController_RestoreBgmAfterCry(u8 taskId)
{
    if (!IsCryPlayingOrClearCrySongs())
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        DestroyTask(taskId);
    }
}

#define tExpTask_monId          data[0]
#define tExpTask_battler        data[2]
#define tExpTask_gainedExp_1    data[3]
#define tExpTask_gainedExp_2    data[4] // Stored as two half-words containing a word.
#define tExpTask_frames         data[10]

static void DynamaxModifyHPLevelUp(struct Pokemon *mon, u32 battler, u32 oldMaxHP)
{
    ApplyDynamaxHPMultiplier(mon);
    gBattleScripting.levelUpHP = GetMonData(mon, MON_DATA_MAX_HP) - oldMaxHP; // overwrite levelUpHP since it overflows
    gBattleMons[battler].hp += gBattleScripting.levelUpHP;
    SetMonData(mon, MON_DATA_HP, &gBattleMons[battler].hp);
}

static s32 GetTaskExpValue(u8 taskId)
{
    return (u16)(gTasks[taskId].tExpTask_gainedExp_1) | (gTasks[taskId].tExpTask_gainedExp_2 << 16);
}

static void Task_GiveExpToMon(u8 taskId)
{
    u32 monId = (u8)(gTasks[taskId].tExpTask_monId);
    u8 battler = gTasks[taskId].tExpTask_battler;
    s32 gainedExp = GetTaskExpValue(taskId);

    if (GetBattlerCoordsIndex(battler) == BATTLE_COORDS_DOUBLES || monId != gBattlerPartyIndexes[battler]) // Give exp without moving the expbar.
    {
        struct Pokemon *mon = &gPlayerParty[monId];
        u16 species = GetMonData(mon, MON_DATA_SPECIES);
        u8 level = GetMonData(mon, MON_DATA_LEVEL);
        u32 currExp = GetMonData(mon, MON_DATA_EXP);
        u32 nextLvlExp = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1];
        u32 expAfterGain = currExp + gainedExp;
        u32 oldMaxHP = GetMonData(mon, MON_DATA_MAX_HP);

        if (expAfterGain >= nextLvlExp)
        {
            SetMonData(mon, MON_DATA_EXP, (B_LEVEL_UP_NOTIFICATION >= GEN_9) ? &expAfterGain : &nextLvlExp);

            CalculateMonStats(mon);

            // Reapply Dynamax HP multiplier after stats are recalculated.
            if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX && monId == gBattlerPartyIndexes[battler])
                DynamaxModifyHPLevelUp(mon, battler, oldMaxHP);

            gainedExp -= nextLvlExp - currExp;
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RET_VALUE_LEVELED_UP, (B_LEVEL_UP_NOTIFICATION >= GEN_9) ? 0 : gainedExp);

            if (IsDoubleBattle() == TRUE
             && (monId == gBattlerPartyIndexes[battler] || monId == gBattlerPartyIndexes[BATTLE_PARTNER(battler)]))
                gTasks[taskId].func = Task_LaunchLvlUpAnim;
            else
                gTasks[taskId].func = Task_SetControllerToWaitForString;
        }
        else
        {
            currExp += gainedExp;
            SetMonData(mon, MON_DATA_EXP, &currExp);
            gBattlerControllerFuncs[battler] = Controller_WaitForString;
            DestroyTask(taskId);
        }
    }
    else
    {
        gTasks[taskId].func = Task_PrepareToGiveExpWithExpBar;
    }
}

static void Task_PrepareToGiveExpWithExpBar(u8 taskId)
{
    u8 monIndex = gTasks[taskId].tExpTask_monId;
    s32 gainedExp = GetTaskExpValue(taskId);
    u8 battler = gTasks[taskId].tExpTask_battler;
    struct Pokemon *mon = &gPlayerParty[monIndex];
    u8 level = GetMonData(mon, MON_DATA_LEVEL);
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 exp = GetMonData(mon, MON_DATA_EXP);
    u32 currLvlExp = gExperienceTables[gSpeciesInfo[species].growthRate][level];
    u32 expToNextLvl;

    exp -= currLvlExp;
    expToNextLvl = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1] - currLvlExp;
    SetBattleBarStruct(battler, gHealthboxSpriteIds[battler], expToNextLvl, exp, -gainedExp);
    TestRunner_Battle_RecordExp(battler, exp, -gainedExp);
    PlaySE(SE_EXP);
    gTasks[taskId].func = Task_GiveExpWithExpBar;
}

static void Task_GiveExpWithExpBar(u8 taskId)
{
    u32 level, expAfterGain;
    u16 species;
    u32 oldMaxHP;
    s32 currExp, expOnNextLvl, newExpPoints;

    if (gTasks[taskId].tExpTask_frames < 13)
    {
        gTasks[taskId].tExpTask_frames++;
    }
    else
    {
        u8 monId = gTasks[taskId].tExpTask_monId;
        s32 gainedExp = GetTaskExpValue(taskId);
        u8 battler = gTasks[taskId].tExpTask_battler;
        struct Pokemon *mon = &gPlayerParty[monId];

        newExpPoints = MoveBattleBar(battler, gHealthboxSpriteIds[battler], EXP_BAR, 0);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        if (newExpPoints == -1) // The bar has been filled with given exp points.
        {
            m4aSongNumStop(SE_EXP);
            level = GetMonData(mon, MON_DATA_LEVEL);
            currExp = GetMonData(mon, MON_DATA_EXP);
            species = GetMonData(mon, MON_DATA_SPECIES);
            oldMaxHP = GetMonData(mon, MON_DATA_MAX_HP);
            expOnNextLvl = gExperienceTables[gSpeciesInfo[species].growthRate][level + 1];

            expAfterGain = currExp + gainedExp;
            if (expAfterGain >= expOnNextLvl)
            {
                if (B_LEVEL_UP_NOTIFICATION >= GEN_9)
                    SetMonData(mon, MON_DATA_EXP, &expAfterGain);
                else
                    SetMonData(mon, MON_DATA_EXP, &expOnNextLvl);

                CalculateMonStats(mon);

                // Reapply Dynamax HP multiplier after stats are recalculated.
                if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX && monId == gBattlerPartyIndexes[battler])
                    DynamaxModifyHPLevelUp(mon, battler, oldMaxHP);

                gainedExp -= expOnNextLvl - currExp;
                BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RET_VALUE_LEVELED_UP, (B_LEVEL_UP_NOTIFICATION >= GEN_9) ? 0 : gainedExp);
                gTasks[taskId].func = Task_LaunchLvlUpAnim;
            }
            else
            {
                currExp += gainedExp;
                SetMonData(mon, MON_DATA_EXP, &currExp);
                gBattlerControllerFuncs[battler] = Controller_WaitForString;
                DestroyTask(taskId);
            }
        }
    }
}

static void Task_LaunchLvlUpAnim(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;
    u8 monIndex = gTasks[taskId].tExpTask_monId;

    if (IsDoubleBattle() == TRUE && monIndex == gBattlerPartyIndexes[BATTLE_PARTNER(battler)])
        battler ^= BIT_FLANK;

    InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_LVL_UP);
    gTasks[taskId].func = Task_UpdateLvlInHealthbox;
}

static void Task_UpdateLvlInHealthbox(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;

    if (!gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive)
    {
        u8 monIndex = gTasks[taskId].tExpTask_monId;

        if (IsDoubleBattle() == TRUE && monIndex == gBattlerPartyIndexes[BATTLE_PARTNER(battler)])
            UpdateHealthboxAttribute(gHealthboxSpriteIds[BATTLE_PARTNER(battler)], &gPlayerParty[monIndex], HEALTHBOX_ALL);
        else
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[monIndex], HEALTHBOX_ALL);

        gTasks[taskId].func = Task_SetControllerToWaitForString;
    }
}

static void Task_SetControllerToWaitForString(u8 taskId)
{
    u8 battler = gTasks[taskId].tExpTask_battler;
    gBattlerControllerFuncs[battler] = Controller_WaitForString;
    DestroyTask(taskId);
}

static void OpenPartyMenuToChooseMon(u32 battler)
{
    if (!gPaletteFade.active)
    {
        u8 caseId;

        gBattlerControllerFuncs[battler] = WaitForMonSelection;
        caseId = gTasks[gBattleControllerData[battler]].data[0];
        DestroyTask(gBattleControllerData[battler]);
        FreeAllWindowBuffers();
        OpenPartyMenuInBattle(caseId);
    }
}

static void WaitForMonSelection(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (gPartyMenuUseExitCallback == TRUE)
            BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gSelectedMonPartyId, gBattlePartyCurrentOrder);
        else
            BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, PARTY_SIZE, NULL);

        if (gBattleResources->bufferA[battler][1] == PARTY_ACTION_SEND_OUT)
            PrintLinkStandbyMsg();

        BtlController_Complete(battler);
    }
}

static void OpenBagAndChooseItem(u32 battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = CompleteWhenChoseItem;
        ReshowBattleScreenDummy();
        FreeAllWindowBuffers();
        CB2_BagMenuFromBattle();
    }
}

static void CompleteWhenChoseItem(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, gSpecialVar_ItemId);
        BtlController_Complete(battler);
    }
}

static void PlayerHandleYesNoInput(u32 battler)
{
    if (JOY_NEW(DPAD_UP) && gMultiUsePlayerCursor != 0)
    {
        PlaySE(SE_SELECT);
        BattleDestroyYesNoCursorAt(gMultiUsePlayerCursor);
        gMultiUsePlayerCursor = 0;
        BattleCreateYesNoCursorAt(0);
    }
    if (JOY_NEW(DPAD_DOWN) && gMultiUsePlayerCursor == 0)
    {
        PlaySE(SE_SELECT);
        BattleDestroyYesNoCursorAt(gMultiUsePlayerCursor);
        gMultiUsePlayerCursor = 1;
        BattleCreateYesNoCursorAt(1);
    }
    if (JOY_NEW(A_BUTTON))
    {
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        PlaySE(SE_SELECT);

        if (gMultiUsePlayerCursor != 0)
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_UNK_14, 0);
        else
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_NOTHING_FAINTED, 0);

        BtlController_Complete(battler);
    }
    if (JOY_NEW(B_BUTTON))
    {
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        PlaySE(SE_SELECT);
        BtlController_Complete(battler);
    }
}

static void MoveSelectionDisplayMoveNames(u32 battler)
{
    s32 i;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    gNumberOfMovesToChoose = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        MoveSelectionDestroyCursorAt(i);
        if (IsGimmickSelected(battler, GIMMICK_DYNAMAX) || GetActiveGimmick(battler) == GIMMICK_DYNAMAX)
            StringCopy(gDisplayedStringBattle, GetMoveName(GetMaxMove(battler, moveInfo->moves[i])));
        else
            StringCopy(gDisplayedStringBattle, GetMoveName(moveInfo->moves[i]));
        // Prints on windows B_WIN_MOVE_NAME_1, B_WIN_MOVE_NAME_2, B_WIN_MOVE_NAME_3, B_WIN_MOVE_NAME_4
        BattlePutTextOnWindow(gDisplayedStringBattle, i + B_WIN_MOVE_NAME_1);
        if (moveInfo->moves[i] != MOVE_NONE)
            gNumberOfMovesToChoose++;
    }
}

static void MoveSelectionDisplayPpString(u32 battler)
{
    StringCopy(gDisplayedStringBattle, gText_MoveInterfacePP);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_PP);
}

static void MoveSelectionDisplayPpNumber(u32 battler)
{
    u8 *txtPtr;
    struct ChooseMoveStruct *moveInfo;

    if (gBattleResources->bufferA[battler][2] == TRUE) // check if we didn't want to display pp number
        return;

    SetPpNumbersPaletteInMoveSelection(battler);
    moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    txtPtr = ConvertIntToDecimalStringN(gDisplayedStringBattle, moveInfo->currentPp[gMoveSelectionCursor[battler]], STR_CONV_MODE_RIGHT_ALIGN, 2);
    *(txtPtr)++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(txtPtr, moveInfo->maxPp[gMoveSelectionCursor[battler]], STR_CONV_MODE_RIGHT_ALIGN, 2);

    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_PP_REMAINING);
}

static void MoveSelectionDisplayMoveType(u32 battler)
{
    u8 *txtPtr, *end;
    u32 speciesId = gBattleMons[battler].species;
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    txtPtr = StringCopy(gDisplayedStringBattle, gText_MoveInterfaceType);
    u32 move = moveInfo->moves[gMoveSelectionCursor[battler]];
    enum Type type = GetMoveType(move);
    enum BattleMoveEffects effect = GetMoveEffect(move);

    if (effect == EFFECT_TERA_BLAST)
    {
        if (IsGimmickSelected(battler, GIMMICK_TERA) || GetActiveGimmick(battler) == GIMMICK_TERA)
            type = GetBattlerTeraType(battler);
    }
    else if (effect == EFFECT_IVY_CUDGEL)
    {
        if (speciesId == SPECIES_OGERPON_WELLSPRING || speciesId == SPECIES_OGERPON_WELLSPRING_TERA
         || speciesId == SPECIES_OGERPON_HEARTHFLAME || speciesId == SPECIES_OGERPON_HEARTHFLAME_TERA
         || speciesId == SPECIES_OGERPON_CORNERSTONE || speciesId == SPECIES_OGERPON_CORNERSTONE_TERA)
            type = GetSpeciesType(speciesId, 1);
    }
    else if (GetMoveCategory(move) == DAMAGE_CATEGORY_STATUS
             && (GetActiveGimmick(battler) == GIMMICK_DYNAMAX || IsGimmickSelected(battler, GIMMICK_DYNAMAX)))
    {
        type = TYPE_NORMAL; // Max Guard is always a Normal-type move
    }
    else if (effect == EFFECT_TERA_STARSTORM)
    {
        if (speciesId == SPECIES_TERAPAGOS_STELLAR
        || (IsGimmickSelected(battler, GIMMICK_TERA) && speciesId == SPECIES_TERAPAGOS_TERASTAL))
            type = TYPE_STELLAR;
    }
    else if (P_SHOW_DYNAMIC_TYPES) // Non-vanilla changes to battle UI showing dynamic types
    {
        struct Pokemon *mon = GetBattlerMon(battler);
        type = CheckDynamicMoveType(mon, move, battler, MON_IN_BATTLE);
    }
    end = StringCopy(txtPtr, gTypesInfo[type].name);

    PrependFontIdToFit(txtPtr, end, FONT_NORMAL, WindowWidthPx(B_WIN_MOVE_TYPE) - 25);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_TYPE);
}

static void TryMoveSelectionDisplayMoveDescription(u32 battler)
{
    if (!B_SHOW_MOVE_DESCRIPTION)
        return;

    if (gBattleStruct->descriptionSubmenu)
        MoveSelectionDisplayMoveDescription(battler);
}

static void MoveSelectionDisplayMoveDescription(u32 battler)
{
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct*)(&gBattleResources->bufferA[battler][4]);
    u16 move = moveInfo->moves[gMoveSelectionCursor[battler]];
    u16 pwr = GetMovePower(move);
    u16 acc = GetMoveAccuracy(move);
    enum DamageCategory cat = GetBattleMoveCategory(move);

    if (GetActiveGimmick(battler) == GIMMICK_DYNAMAX || IsGimmickSelected(battler, GIMMICK_DYNAMAX))
    {
        pwr = GetMaxMovePower(move);
        move = GetMaxMove(battler, move);
        acc = 0;
    }

    u8 pwr_num[3], acc_num[3];
    u8 cat_desc[7] = _("CAT: ");
    u8 pwr_desc[7] = _("PWR: ");
    u8 acc_desc[7] = _("ACC: ");
    u8 cat_start[] = _("{CLEAR_TO 0x03}");
    u8 pwr_start[] = _("{CLEAR_TO 0x38}");
    u8 acc_start[] = _("{CLEAR_TO 0x6C}");
    LoadMessageBoxAndBorderGfx();
    DrawStdWindowFrame(B_WIN_MOVE_DESCRIPTION, FALSE);
    if (pwr < 2)
        StringCopy(pwr_num, gText_BattleSwitchWhich5);
    else
        ConvertIntToDecimalStringN(pwr_num, pwr, STR_CONV_MODE_LEFT_ALIGN, 3);
    if (acc < 2)
        StringCopy(acc_num, gText_BattleSwitchWhich5);
    else
        ConvertIntToDecimalStringN(acc_num, acc, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringCopy(gDisplayedStringBattle, cat_start);
    StringAppend(gDisplayedStringBattle, cat_desc);
    StringAppend(gDisplayedStringBattle, pwr_start);
    StringAppend(gDisplayedStringBattle, pwr_desc);
    StringAppend(gDisplayedStringBattle, pwr_num);
    StringAppend(gDisplayedStringBattle, acc_start);
    StringAppend(gDisplayedStringBattle, acc_desc);
    StringAppend(gDisplayedStringBattle, acc_num);
    StringAppend(gDisplayedStringBattle, gText_NewLine);
    StringAppend(gDisplayedStringBattle, GetMoveDescription(move));
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_MOVE_DESCRIPTION);

    if (gCategoryIconSpriteId == 0xFF)
        gCategoryIconSpriteId = CreateSprite(&gSpriteTemplate_CategoryIcons, 38, 64, 1);

    StartSpriteAnim(&gSprites[gCategoryIconSpriteId], cat);

    CopyWindowToVram(B_WIN_MOVE_DESCRIPTION, COPYWIN_FULL);
}

void MoveSelectionCreateCursorAt(u8 cursorPosition, u8 baseTileNum)
{
    /*u16 src[2];
    src[0] = baseTileNum + 1;
    src[1] = baseTileNum + 2;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 9 * (cursorPosition & 1) + 1, 55 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);*/
}

void MoveSelectionDestroyCursorAt(u8 cursorPosition)
{
    /*u16 src[2];
    src[0] = 0x1016;
    src[1] = 0x1016;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 9 * (cursorPosition & 1) + 1, 55 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);*/
}

void ActionSelectionCreateCursorAt(u8 cursorPosition, u8 baseTileNum)
{
    /*u16 src[2];
    src[0] = 1;
    src[1] = 2;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 7 * (cursorPosition & 1) + 16, 35 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);*/
}

void ActionSelectionDestroyCursorAt(u8 cursorPosition)
{
    /*u16 src[2];
    src[0] = 0x1016;
    src[1] = 0x1016;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 7 * (cursorPosition & 1) + 16, 35 + (cursorPosition & 2), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);*/
}

void CB2_SetUpReshowBattleScreenAfterMenu(void)
{
    SetMainCallback2(ReshowBattleScreenAfterMenu);
}

void CB2_SetUpReshowBattleScreenAfterMenu2(void)
{
    SetMainCallback2(ReshowBattleScreenAfterMenu);
}

static void PrintLinkStandbyMsg(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        BattlePutTextOnWindow(gText_LinkStandby, B_WIN_MSG);
    }
}

static void PlayerHandleLoadMonSprite(u32 battler)
{
    BattleLoadMonSpriteGfx(GetBattlerMon(battler), battler);
    gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
    gBattlerControllerFuncs[battler] = CompleteOnBattlerSpritePosX_0;
}

u32 LinkPlayerGetTrainerPicId(u32 multiplayerId)
{
    u32 trainerPicId;

    u8 gender = gLinkPlayers[multiplayerId].gender;
    u8 version = gLinkPlayers[multiplayerId].version & 0xFF;

    if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
        trainerPicId = gender + TRAINER_BACK_PIC_RED;
    else if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
        trainerPicId = gender + TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN;
    else
        trainerPicId = gender + TRAINER_BACK_PIC_BRENDAN;

    return trainerPicId;
}

static u32 PlayerGetTrainerBackPicId(void)
{
    u8 costume = VarGet(VAR_COSTUME_NUM);
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        trainerPicId = LinkPlayerGetTrainerPicId(GetMultiplayerId());
    else{
        switch(costume){
            case 1:
                trainerPicId = gSaveBlock2Ptr->playerGender + TRAINER_BACK_PIC_BRENDAN2;
            break;
            default:
                trainerPicId = gSaveBlock2Ptr->playerGender + TRAINER_BACK_PIC_BRENDAN;
            break;
        }
    }

    return trainerPicId;
}

// In emerald it's possible to have a tag battle in the battle frontier facilities with AI
// which use the front sprite for both the player and the partner as opposed to any other battles (including the one with Steven)
// that use an animated back pic.
static void PlayerHandleDrawTrainerPic(u32 battler)
{
    bool32 isFrontPic;
    s16 xPos, yPos;
    u32 trainerPicId;
    if (IsMultibattleTest())
    {
        trainerPicId = TRAINER_BACK_PIC_BRENDAN;
        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
            xPos = 32;
        else
            xPos = 80;
        yPos = (8 - gTrainerBacksprites[trainerPicId].coordinates.size) * 4 + 80;
    }
    else
    {
        trainerPicId = PlayerGetTrainerBackPicId();
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if ((GetBattlerPosition(battler) & BIT_FLANK) != B_FLANK_LEFT) // Second mon, on the right.
                xPos = 90;
            else // First mon, on the left.
                xPos = 32;

            if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId < TRAINER_PARTNER(PARTNER_NONE))
            {
                xPos = 90;
                yPos = 80;
            }
            else
            {
                yPos = (8 - gTrainerBacksprites[trainerPicId].coordinates.size) * 4 + 80;
            }
        }
        else
        {
            xPos = 80;
            yPos = (8 - gTrainerBacksprites[trainerPicId].coordinates.size) * 4 + 80;
        }
    }

    // Use front pic table for any tag battles unless your partner is Steven or a custom partner.
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId < TRAINER_PARTNER(PARTNER_NONE))
    {
        trainerPicId = PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender);
        isFrontPic = TRUE;
    }
    else // Use back pic in all the other usual circumstances.
    {
        isFrontPic = FALSE;
    }

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, isFrontPic, xPos, yPos, -1);
}

static void PlayerHandleTrainerSlide(u32 battler)
{
    u32 trainerPicId = PlayerGetTrainerBackPicId();
    BtlController_HandleTrainerSlide(battler, trainerPicId);
}

static void PlayerHandleTrainerSlideBack(u32 battler)
{
    BtlController_HandleTrainerSlideBack(battler, 50, TRUE);
}

static void PlayerHandlePaletteFade(u32 battler)
{
    BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_BLACK);
    BtlController_Complete(battler);
}

static void PlayerHandleSuccessBallThrowAnim(u32 battler)
{
    BtlController_HandleSuccessBallThrowAnim(battler, gBattlerTarget, B_ANIM_BALL_THROW, TRUE);
}

void PlayerHandleBallThrowAnim(u32 battler)
{
    BtlController_HandleBallThrowAnim(battler, gBattlerTarget, B_ANIM_BALL_THROW, TRUE);
}

static void PlayerHandlePause(u32 battler)
{
    u8 timer = gBattleResources->bufferA[battler][1];

    while (timer != 0)
        timer--;

    BtlController_Complete(battler);
}

static void HandleChooseActionAfterDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT;
        PrintBattleWindow_ActionPromt(battler);

        if (gBattleStruct->aiDelayTimer != 0)
        {
            gBattleStruct->aiDelayFrames = gMain.vblankCounter1 - gBattleStruct->aiDelayTimer;
            gBattleStruct->aiDelayTimer = 0;
            if (DEBUG_AI_DELAY_TIMER)
            {
                static const u8 sFramesText[] = _(" frames thinking\n");
                static const u8 sCyclesText[] = _(" cycles");
                ConvertIntToDecimalStringN(gDisplayedStringBattle, gBattleStruct->aiDelayFrames, STR_CONV_MODE_RIGHT_ALIGN, 3);
                u8* end = StringAppend(gDisplayedStringBattle, sFramesText);
                ConvertIntToDecimalStringN(end, gBattleStruct->aiDelayCycles, STR_CONV_MODE_RIGHT_ALIGN, 8);
                // Clear old result once read out
                gBattleStruct->aiDelayCycles = 0;
                StringAppend(gDisplayedStringBattle, sCyclesText);
                BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
            }
        }
        gBattlerControllerFuncs[battler] = HandleInputChooseAction;
    }
}

static void PlayerHandleChooseAction(u32 battler)
{
    // "What will {x} do?" + "Fight/Pokémon/Bag/Run" menu
    s32 i;

	//Reshow Bg
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    ShowBg(1);

    gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;
    BattleTv_ClearExplosionFaintCause();
    PrintBattleWindow_ActionPromt(battler);

    //BattlePutTextOnWindow(gText_BattleMenu, B_WIN_ACTION_MENU);

    /*for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    TryRestoreLastUsedBall();
    ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo);

    if (B_SHOW_PARTNER_TARGET && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && IsBattlerAlive(B_POSITION_PLAYER_RIGHT))
    {
        StringCopy(gStringVar1, COMPOUND_STRING("Partner will use:\n"));
        u32 move = GetChosenMoveFromPosition(B_POSITION_PLAYER_RIGHT);
        StringAppend(gStringVar1, GetMoveName(move));
        u32 moveTarget = GetBattlerMoveTargetType(B_POSITION_PLAYER_RIGHT, move);
        if (moveTarget == MOVE_TARGET_SELECTED)
        {
            if (gAiBattleData->chosenTarget[B_POSITION_PLAYER_RIGHT] == B_POSITION_OPPONENT_LEFT)
                StringAppend(gStringVar1, COMPOUND_STRING(" -{UP_ARROW}"));
            else if (gAiBattleData->chosenTarget[B_POSITION_PLAYER_RIGHT] == B_POSITION_OPPONENT_RIGHT)
                StringAppend(gStringVar1, COMPOUND_STRING(" {UP_ARROW}-"));
            else if (gAiBattleData->chosenTarget[B_POSITION_PLAYER_RIGHT] == B_POSITION_PLAYER_LEFT)
                StringAppend(gStringVar1, COMPOUND_STRING(" {DOWN_ARROW}-"));
            else if (gAiBattleData->chosenTarget[B_POSITION_PLAYER_RIGHT] == B_POSITION_PLAYER_RIGHT)
                StringAppend(gStringVar1, COMPOUND_STRING(" -{DOWN_ARROW}"));
        }
        else if (moveTarget == MOVE_TARGET_BOTH)
        {
            StringAppend(gStringVar1, COMPOUND_STRING(" {UP_ARROW}{UP_ARROW}"));
        }
        else if (moveTarget == MOVE_TARGET_FOES_AND_ALLY)
        {
            StringAppend(gStringVar1, COMPOUND_STRING(" {V_D_ARROW}{UP_ARROW}"));
        }
        else if (moveTarget == MOVE_TARGET_ALL_BATTLERS)
        {
            StringAppend(gStringVar1, COMPOUND_STRING(" {V_D_ARROW}{V_D_ARROW}"));
        }
        BattlePutTextOnWindow(gStringVar1, B_WIN_ACTION_PROMPT);
    }
    else
    {
        BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
    }*/
}

static void PlayerHandleYesNoBox(u32 battler)
{
    if (IsOnPlayerSide(battler))
    {
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gMultiUsePlayerCursor = 1;
        BattleCreateYesNoCursorAt(1);
        gBattlerControllerFuncs[battler] = PlayerHandleYesNoInput;
    }
    else
    {
        BtlController_Complete(battler);
    }
}

void HandleChooseMoveAfterDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT * 2;
        PrintBattleWindow_MoveWindow(battler, FALSE);
        gBattlerControllerFuncs[battler] = HandleInputChooseMove;
    }
}

// arenaMindPoints is used here as a placeholder for a timer.

static void PlayerChooseMoveInBattlePalace(u32 battler)
{
    if (--gBattleStruct->arenaMindPoints[battler] == 0)
    {
        gBattlePalaceMoveSelectionRngValue = gRngValue;
        BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_EXEC_SCRIPT, ChooseMoveAndTargetInBattlePalace(battler));
        BtlController_Complete(battler);
    }
}

void PlayerHandleChooseMove(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
    {
        gBattleStruct->arenaMindPoints[battler] = 8;
        gBattlerControllerFuncs[battler] = PlayerChooseMoveInBattlePalace;
    }
    else
    {
        struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);

        InitMoveSelectionsVarsAndStrings(battler);
        gBattleStruct->gimmick.playerSelect = FALSE;
        //TryToAddMoveInfoWindow();

        AssignUsableZMoves(battler, moveInfo->moves);
        gBattleStruct->zmove.viable = (gBattleStruct->zmove.possibleZMoves[battler] & (1u << gMoveSelectionCursor[battler])) != 0;

        if (!IsGimmickTriggerSpriteActive())
            gBattleStruct->gimmick.triggerSpriteId = 0xFF;
        else if (!IsGimmickTriggerSpriteMatchingBattler(battler))
            DestroyGimmickTriggerSprite();
        if (!(gBattleStruct->gimmick.usableGimmick[battler] == GIMMICK_Z_MOVE && !gBattleStruct->zmove.viable))
            CreateGimmickTriggerSprite(battler);

        gBattlerControllerFuncs[battler] = HandleChooseMoveAfterDma3;
    }
}

void InitMoveSelectionsVarsAndStrings(u32 battler)
{
    LoadTypeIcons(battler);
    MoveSelectionDisplayMoveNames(battler);
    gMultiUsePlayerCursor = 0xFF;
    MoveSelectionCreateCursorAt(gMoveSelectionCursor[battler], 0);
    if (B_SHOW_EFFECTIVENESS)
        MoveSelectionDisplayMoveEffectiveness(CheckTargetTypeEffectiveness(battler), battler);
    else
        MoveSelectionDisplayPpString(battler);
    MoveSelectionDisplayPpNumber(battler);
    MoveSelectionDisplayMoveType(battler);
}

static void PlayerHandleChooseItem(u32 battler)
{
    s32 i;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = OpenBagAndChooseItem;
    gBattlerInMenuId = battler;

    for (i = 0; i < ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][1 + i];
}

static void PlayerHandleChoosePokemon(u32 battler)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][4 + i];

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleResources->bufferA[battler][1] != PARTY_ACTION_CANT_SWITCH
        && gBattleResources->bufferA[battler][1] != PARTY_ACTION_CHOOSE_FAINTED_MON
        && gBattleResources->bufferA[battler][1] != PARTY_ACTION_SEND_MON_TO_BOX)
    {
        BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gBattlerPartyIndexes[battler] + 1, gBattlePartyCurrentOrder);
        BtlController_Complete(battler);
    }
    else
    {
        gBattleControllerData[battler] = CreateTask(TaskDummy, 0xFF);
        gTasks[gBattleControllerData[battler]].data[0] = gBattleResources->bufferA[battler][1];
        *(&gBattleStruct->battlerPreventingSwitchout) = gBattleResources->bufferA[battler][8];
        *(&gBattleStruct->prevSelectedPartySlot) = gBattleResources->bufferA[battler][2];
        *(&gBattleStruct->abilityPreventingSwitchout) = (gBattleResources->bufferA[battler][3] & 0xFF) | (gBattleResources->bufferA[battler][7] << 8);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gBattlerControllerFuncs[battler] = OpenPartyMenuToChooseMon;
        gBattlerInMenuId = battler;
    }
}

static void PlayerHandleCmd23(u32 battler)
{
    BattleStopLowHpSound();
    BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_BLACK);
    BtlController_Complete(battler);
}

void PlayerHandleExpUpdate(u32 battler)
{
    u8 monId = gBattleResources->bufferA[battler][1];
    s32 taskId, expPointsToGive;

    if (GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL) >= MAX_LEVEL)
    {
        BtlController_Complete(battler);
    }
    else
    {
        LoadBattleBarGfx(1);
        expPointsToGive = T1_READ_32(&gBattleResources->bufferA[battler][2]);
        taskId = CreateTask(Task_GiveExpToMon, 10);
        gTasks[taskId].tExpTask_monId = monId;
        gTasks[taskId].tExpTask_gainedExp_1 = expPointsToGive;
        gTasks[taskId].tExpTask_gainedExp_2 = expPointsToGive >> 16;
        gTasks[taskId].tExpTask_battler = battler;
        gBattlerControllerFuncs[battler] = BattleControllerDummy;
    }
}

#undef tExpTask_monId
#undef tExpTask_battler
#undef tExpTask_gainedExp_1
#undef tExpTask_gainedExp_2
#undef tExpTask_frames

static void PlayerHandleStatusXor(u32 battler)
{
    u32 val = GetMonData(GetBattlerMon(battler), MON_DATA_STATUS) ^ gBattleResources->bufferA[battler][1];

    SetMonData(GetBattlerMon(battler), MON_DATA_STATUS, &val);
    BtlController_Complete(battler);
}

static void PlayerHandleDMA3Transfer(u32 battler)
{
    u32 dstArg = gBattleResources->bufferA[battler][1]
            | (gBattleResources->bufferA[battler][2] << 8)
            | (gBattleResources->bufferA[battler][3] << 16)
            | (gBattleResources->bufferA[battler][4] << 24);
    u16 sizeArg = gBattleResources->bufferA[battler][5] | (gBattleResources->bufferA[battler][6] << 8);

    const u8 *src = &gBattleResources->bufferA[battler][7];
    u8 *dst = (u8 *)(dstArg);
    u32 size = sizeArg;

    while (1)
    {
        if (size <= 0x1000)
        {
            DmaCopy16(3, src, dst, size);
            break;
        }
        DmaCopy16(3, src, dst, 0x1000);
        src += 0x1000;
        dst += 0x1000;
        size -= 0x1000;
    }
    BtlController_Complete(battler);
}

static void PlayerHandlePlayBGM(u32 battler)
{
    PlayBGM(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
    BtlController_Complete(battler);
}

static void PlayerHandleTwoReturnValues(u32 battler)
{
    BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_MOVE, 0);
    BtlController_Complete(battler);
}

static void PlayerHandleChosenMonReturnValue(u32 battler)
{
    BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, 0, NULL);
    BtlController_Complete(battler);
}

static void PlayerHandleOneReturnValue(u32 battler)
{
    BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, 0);
    BtlController_Complete(battler);
}

static void PlayerHandleOneReturnValue_Duplicate(u32 battler)
{
    BtlController_EmitOneReturnValue_Duplicate(battler, B_COMM_TO_ENGINE, 0);
    BtlController_Complete(battler);
}

static void PlayerHandleIntroTrainerBallThrow(u32 battler)
{
    const u32 paletteIndex = PlayerGetTrainerBackPicId();
    const u16 *trainerPal = gTrainerBacksprites[paletteIndex].palette.data;
    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F8, trainerPal, 31, Intro_TryShinyAnimShowHealthbox);
}

static void PlayerHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, TRUE);
}

static void PlayerHandleEndBounceEffect(u32 battler)
{
    EndBounceEffect(battler, BOUNCE_HEALTHBOX);
    EndBounceEffect(battler, BOUNCE_MON);
    BtlController_Complete(battler);
}

static void PlayerHandleLinkStandbyMsg(u32 battler)
{
    RecordedBattle_RecordAllBattlerData(&gBattleResources->bufferA[battler][2]);
    switch (gBattleResources->bufferA[battler][1])
    {
    case LINK_STANDBY_MSG_STOP_BOUNCE:
        PrintLinkStandbyMsg();
        // fall through
    case LINK_STANDBY_STOP_BOUNCE_ONLY:
        EndBounceEffect(battler, BOUNCE_HEALTHBOX);
        EndBounceEffect(battler, BOUNCE_MON);
        break;
    case LINK_STANDBY_MSG_ONLY:
        PrintLinkStandbyMsg();
        break;
    }
    BtlController_Complete(battler);
}

static void PlayerHandleResetActionMoveSelection(u32 battler)
{
    switch (gBattleResources->bufferA[battler][1])
    {
    case RESET_ACTION_MOVE_SELECTION:
        gActionSelectionCursor[battler] = 0;
        gMoveSelectionCursor[battler] = 0;
        break;
    case RESET_ACTION_SELECTION:
        gActionSelectionCursor[battler] = 0;
        break;
    case RESET_MOVE_SELECTION:
        gMoveSelectionCursor[battler] = 0;
        break;
    }
    BtlController_Complete(battler);
}

static void PlayerHandleEndLinkBattle(u32 battler)
{
    RecordedBattle_RecordAllBattlerData(&gBattleResources->bufferA[battler][4]);
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    gSaveBlock2Ptr->frontier.disableRecordBattle = gBattleResources->bufferA[battler][2];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    BtlController_Complete(battler);
    gBattlerControllerFuncs[battler] = SetBattleEndCallbacks;
}

static void Controller_WaitForDebug(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_Complete(battler);
    }
}

static void PlayerHandleBattleDebug(u32 battler)
{
    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    SetMainCallback2(CB2_BattleDebugMenu);
    gBattlerControllerFuncs[battler] = Controller_WaitForDebug;
}

static bool32 ShouldShowTypeEffectiveness(u32 targetId)
{
    if (B_SHOW_EFFECTIVENESS == SHOW_EFFECTIVENESS_CAUGHT)
        return GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[targetId].species), FLAG_GET_CAUGHT);

    if (B_SHOW_EFFECTIVENESS == SHOW_EFFECTIVENESS_SEEN)
        return GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[targetId].species), FLAG_GET_SEEN);

    return TRUE;
}

static u32 CheckTypeEffectiveness(u32 battlerAtk, u32 battlerDef)
{
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battlerAtk][4]);
    struct DamageContext ctx = {0};
    ctx.battlerAtk = battlerAtk;
    ctx.battlerDef = battlerDef;
    ctx.move = moveInfo->moves[gMoveSelectionCursor[battlerAtk]];
    ctx.moveType = CheckDynamicMoveType(GetBattlerMon(battlerAtk), ctx.move, battlerAtk, MON_IN_BATTLE);
    ctx.updateFlags = FALSE;
    ctx.holdEffectAtk = GetBattlerHoldEffect(battlerAtk);
    ctx.holdEffectDef = GetBattlerHoldEffect(battlerDef);

    uq4_12_t modifier = CalcTypeEffectivenessMultiplier(&ctx);

    if (!ShouldShowTypeEffectiveness(battlerDef))
        return EFFECTIVENESS_CANNOT_VIEW;

    if (modifier == UQ_4_12(0.0))
        return EFFECTIVENESS_NO_EFFECT; // No effect
    else if (modifier <= UQ_4_12(0.5))
        return EFFECTIVENESS_NOT_VERY_EFFECTIVE; // Not very effective
    else if (modifier >= UQ_4_12(2.0))
        return EFFECTIVENESS_SUPER_EFFECTIVE; // Super effective
    return EFFECTIVENESS_NORMAL; // Normal effectiveness
}

static uq4_12_t CheckTypeEffectivenessMod(u32 battlerAtk, u32 battlerDef, u16 move)
{
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battlerAtk][4]);
    struct DamageContext ctx = {0};
    ctx.battlerAtk = battlerAtk;
    ctx.battlerDef = battlerDef;
    ctx.move = move;
    ctx.moveType = CheckDynamicMoveType(GetBattlerMon(battlerAtk), ctx.move, battlerAtk, MON_IN_BATTLE);
    ctx.updateFlags = FALSE;
    ctx.holdEffectAtk = GetBattlerHoldEffect(battlerAtk);
    ctx.holdEffectDef = GetBattlerHoldEffect(battlerDef);

    uq4_12_t modifier = CalcTypeEffectivenessMultiplier(&ctx);

    if (!ShouldShowTypeEffectiveness(battlerDef))
        return UQ_4_12(1.0);

    return modifier;
}

static u32 CheckTargetTypeEffectiveness(u32 battler)
{
    u32 battlerFoe = BATTLE_OPPOSITE(battler);
    u32 foeEffectiveness = CheckTypeEffectiveness(battler, battlerFoe);

    if (IsDoubleBattle())
    {
        u32 partnerFoe = BATTLE_PARTNER(battlerFoe);
        u32 partnerFoeEffectiveness = CheckTypeEffectiveness(battler, partnerFoe);
        if (!IsBattlerAlive(battlerFoe))
            return partnerFoeEffectiveness;
        if (IsBattlerAlive(battlerFoe) && IsBattlerAlive(partnerFoe)
         && partnerFoeEffectiveness > foeEffectiveness)
            return partnerFoeEffectiveness;
    }
    return foeEffectiveness; // fallthrough for any other circumstance
}

static void MoveSelectionDisplayMoveEffectiveness(u32 foeEffectiveness, u32 battler)
{
    static const u8 noIcon[] =  _("");
    static const u8 effectiveIcon[] =  _("{CIRCLE_HOLLOW}");
    static const u8 superEffectiveIcon[] =  _("{CIRCLE_DOT}");
    static const u8 notVeryEffectiveIcon[] =  _("{TRIANGLE}");
    static const u8 immuneIcon[] =  _("{BIG_MULT_X}");
    struct ChooseMoveStruct *moveInfo = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    u8 *txtPtr;

    txtPtr = StringCopy(gDisplayedStringBattle, gText_MoveInterfacePP);

    if (!IsBattleMoveStatus(moveInfo->moves[gMoveSelectionCursor[battler]]))
    {
        switch (foeEffectiveness)
        {
        case EFFECTIVENESS_SUPER_EFFECTIVE:
            StringCopy(txtPtr, superEffectiveIcon);
            break;
        case EFFECTIVENESS_NOT_VERY_EFFECTIVE:
            StringCopy(txtPtr, notVeryEffectiveIcon);
            break;
        case EFFECTIVENESS_NO_EFFECT:
            StringCopy(txtPtr, immuneIcon);
            break;
        case EFFECTIVENESS_NORMAL:
            StringCopy(txtPtr, effectiveIcon);
            break;
        default:
        case EFFECTIVENESS_CANNOT_VIEW:
            StringCopy(txtPtr, noIcon);
            break;
        }
    }

    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_PP);
}

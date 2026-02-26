#include "global.h"
#include "adoption.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item_icon.h"
#include "item_menu.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "random.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "constants/adoption_tiers.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define TAG_ICON_BASE 9110

#define ADOPTION_MENU_PALETTE_ID 12

enum
{
    WIN_MONEY,
    WIN_TIER_LIST,
    WIN_TIER_DESCRIPTION,
    WIN_MESSAGE,
};

enum
{
    OBJ_EVENT_ID,
    X_COORD,
    Y_COORD,
    ANIM_NUM,
    LAYER_TYPE
};

enum
{
    COLORID_NORMAL,      // Item descriptions, quantity in bag, and quantity/price
    COLORID_TIER_LIST,   // The text in the item list, and the cursor normally
    COLORID_GRAY_CURSOR, // When the cursor has selected an item to purchase
};

struct AdoptionAskMenuInfo
{
    u8 windowId;
};

struct AdoptionMenuData
{
    u16 tilemapBuffers[4][0x400];
    u16 selectedRow;
    u16 scrollOffset;
    u32 totalCost;
    u8 iconSlot;
    u8 iconSpriteIds[2];
    s16 viewportObjects[OBJECT_EVENTS_COUNT][5];
};

struct AdoptionTierInfo
{
    u16 price;
    const u8 *name;
    const u8 *description;
    const u16 *species;
    const u16 speciesCount;
};

static EWRAM_DATA struct AdoptionAskMenuInfo sAdoptionAskMenuInfo = {0};
static EWRAM_DATA struct AdoptionMenuData *sAdoptionMenuData = NULL;

static void Task_HandleActionMenuAdopt(u8 taskId);
static void Task_HandleActionMenuQuit(u8 taskId);
static void Task_GoToAdoptionMenu(u8 taskId);
static void Task_AdoptionAskMenu(u8 taskId);
static void CB2_InitAdoptionMenu(void);
static void AdoptionMenuBuildListMenuTemplate(void);
static void AdoptionMenuPrintTierDescriptionAndShowTierIcon(s32 tierId, bool8 onInit, struct ListMenu *list);
static void AdoptionMenuAddTierIcon(s32 tierId, u8 iconSlot);
static void AdoptionMenuRemoveTierIcon(s32 tierId, u8 iconSlot);
static void AdoptionMenuPrintPriceInList(u8 windowId, u32 tierId, u8 y);
static void AdoptionMenuInitBgs(void);
static void AdoptionMenuInitWindows(void);
static void AdoptionMenuDecompressBgGraphics(void);
static void AdoptionMenuDrawGraphics(void);
static void AdoptionMenuDrawMapGraphics(void);
static void AdoptionMenuCollectObjectEventData(void);
static void AdoptionMenuDrawObjectEvents(void);
static bool8 AdoptionMenuCheckIfObjectEventOverlapsMenuBg(s16*);
static void AdoptionMenuDrawMapBg(void);
static void AdoptionMenuDrawMapMetatile(s16 x, s16 y, const u16 *src, u8 metatileLayerType);
static void AdoptionMenuDrawMapMetatileLayer(u16 *dest, s16 offset1, s16 offset2, const u16 *src);
static bool8 AdoptionMenuCheckForOverlapWithMenuBg(int x, int y);
static void AdoptionMenuCopyMenuBgToBg1TilemapBuffer(void);
static void AdoptionMenuConfirmPurchase(u8 taskId);
static void Task_AdoptionMenu(u8 taskId);
static void AdoptionMenuReturnToTierList(u8 taskId);
static void AdoptionMenuTryMakePurchase(u8 taskId);
static void ExitAdoptionMenu(u8 taskId);

static const u8 sText_Adopt[] = _("Adopt");
static const u8 sText_Quit[]  = _("Quit");
static const u8 sText_NoEggsAvailable[] =_("I'm sorry, but we don't have any EGGs\navailable right now.{PAUSE_UNTIL_PRESS}");
static const u8 sText_NoRoomForThisEgg[] = _("You've too many POKéMON.\nThere's no room for this EGG…{PAUSE_UNTIL_PRESS}");
static const u8 sText_YouReceivedEggParty[] =  _("Take good care of it.\nI'll place the EGG in your party.");
static const u8 sText_YouReceivedEggSomeonePC[] = _("Take good care of it.\nI'll send the EGG to SOMEONE'S PC.");
static const u8 sText_YouReceivedEggLanettePC[] = _("Take good care of it.\nI'll send the EGG to LANETTE'S PC.");

#include "data/adoption_tiers.h"

static const struct YesNoFuncTable sAdoptionMenuYesNoFuncs =
{
    AdoptionMenuTryMakePurchase,
    AdoptionMenuReturnToTierList
};

static const struct MenuAction sAdoptionAskMenuActions[] =
{
    { sText_Adopt, {.void_u8=Task_HandleActionMenuAdopt} },
    { sText_Quit,  {.void_u8=Task_HandleActionMenuQuit} }
};

static const struct WindowTemplate sAdoptionAskWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 1,
    .width = 9,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x0008,
};

static const struct ListMenuItem sAdoptionMenuListMenuItems[] =
{
    {
        .name = sAdoptionTiersInfo[ADOPTION_TIER_BASIC].name,
        .id = ADOPTION_TIER_BASIC,
    },
    {
        .name = sAdoptionTiersInfo[ADOPTION_TIER_MEDIUM].name,
        .id = ADOPTION_TIER_MEDIUM,
    },
    {
        .name = sAdoptionTiersInfo[ADOPTION_TIER_TOP].name,
        .id = ADOPTION_TIER_TOP,
    },
    {
        .name = sAdoptionTiersInfo[ADOPTION_TIER_SUPREME].name,
        .id = ADOPTION_TIER_SUPREME,
    },
    {
        .name = sAdoptionTiersInfo[ADOPTION_TIER_LEGENDARY].name,
        .id = ADOPTION_TIER_LEGENDARY,
    },
    {
        .name = sAdoptionTiersInfo[ADOPTION_TIER_SEVII].name,
        .id = ADOPTION_TIER_SEVII,
    },
    {
        .name = gText_Cancel2,
        .id = LIST_CANCEL,
    }
};

static const struct ListMenuTemplate sAdoptionMenuListTemplate =
{
    .items = sAdoptionMenuListMenuItems,
    .moveCursorFunc = AdoptionMenuPrintTierDescriptionAndShowTierIcon,
    .itemPrintFunc = AdoptionMenuPrintPriceInList,
    .totalItems = ARRAY_COUNT(sAdoptionMenuListMenuItems),
    .maxShowed = 8,
    .windowId = WIN_TIER_LIST,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NARROW,
    .cursorKind = CURSOR_BLACK_ARROW,
    .textNarrowWidth = 84,
};

static const struct BgTemplate sAdoptionMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sAdoptionMenuWindowTemplates[] =
{
    [WIN_MONEY] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x001E,
    },
    [WIN_TIER_LIST] = {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 2,
        .width = 15,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 0x0032,
    },
    [WIN_TIER_DESCRIPTION] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0122,
    },
    [WIN_MESSAGE] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x01A2,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sAdoptionMenuYesNoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x020E,
};

static const u8 sAdoptionMenuTextColors[][3] =
{
    [COLORID_NORMAL]      = {1, 2, 3},
    [COLORID_TIER_LIST]   = {0, 2, 3},
    [COLORID_GRAY_CURSOR] = {0, 3, 2},
};

static void Task_AdoptionAskMenu(u8 taskId)
{
    s8 inputCode = Menu_ProcessInputNoWrap();
    switch (inputCode)
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        Task_HandleActionMenuQuit(taskId);
        break;
    default:
        sAdoptionAskMenuActions[inputCode].func.void_u8(taskId);
        break;
    }
}

void sCreateAdoptionMenuWindow(void)
{
    u8 windowId = AddWindow(&sAdoptionAskWindowTemplate);
    int numMenuItems = ARRAY_COUNT(sAdoptionAskMenuActions);

    sAdoptionAskMenuInfo.windowId = windowId;
    SetStandardWindowBorderStyle(windowId, FALSE);
    PrintMenuTable(windowId, numMenuItems, sAdoptionAskMenuActions);
    InitMenuInUpperLeftCornerNormal(windowId, numMenuItems, 0);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_MAP);

    CreateTask(Task_AdoptionAskMenu, 8);
}

void CreateAdoptionMenu(void)
{
    LockPlayerFieldControls();
    sCreateAdoptionMenuWindow();
}

void Task_HandleActionMenuAdopt(u8 taskId)
{
    gTasks[taskId].func = Task_GoToAdoptionMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

void Task_HandleActionMenuQuit(u8 taskId)
{
    ClearStdWindowAndFrameToTransparent(sAdoptionAskMenuInfo.windowId, TRUE);
    RemoveWindow(sAdoptionAskMenuInfo.windowId);
    UnlockPlayerFieldControls();
    DestroyTask(taskId);
    ScriptContext_Enable();
}

void Task_GoToAdoptionMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2(CB2_InitAdoptionMenu);
    }
}

static void CB2_AdoptionMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_AdoptionMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define tTierId     data[6]
#define tListTaskId data[7]

static void CB2_InitAdoptionMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        CpuFastFill(0, (void *)OAM, OAM_SIZE);
        ScanlineEffect_Stop();
        ResetTempTileDataBuffers();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        ClearScheduledBgCopiesToVram();
        sAdoptionMenuData = AllocZeroed(sizeof(struct AdoptionMenuData));
        sAdoptionMenuData->iconSpriteIds[0] = SPRITE_NONE;
        sAdoptionMenuData->iconSpriteIds[1] = SPRITE_NONE;
        AdoptionMenuBuildListMenuTemplate();
        AdoptionMenuInitBgs();
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x20, 0x20);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
        AdoptionMenuInitWindows();
        AdoptionMenuDecompressBgGraphics();
        gMain.state++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
            gMain.state++;
        break;
    default:
        AdoptionMenuDrawGraphics();
        taskId = CreateTask(Task_AdoptionMenu, 8);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_AdoptionMenu);
        SetMainCallback2(CB2_AdoptionMenu);
        break;
    }
}

static void AdoptionMenuBuildListMenuTemplate(void)
{
    gMultiuseListMenuTemplate = sAdoptionMenuListTemplate;
}

static void AdoptionMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorId)
{
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, y, 0, 0, sAdoptionMenuTextColors[colorId], speed, text);
}

static void AdoptionMenuPrintTierDescriptionAndShowTierIcon(s32 tierId, bool8 onInit, struct ListMenu *list)
{
    const u8 *description;

    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    AdoptionMenuAddTierIcon(tierId, sAdoptionMenuData->iconSlot);
    AdoptionMenuRemoveTierIcon(tierId, sAdoptionMenuData->iconSlot ^ 1);
    sAdoptionMenuData->iconSlot ^= 1;

    if (tierId != LIST_CANCEL)
        description = sAdoptionTiersInfo[tierId].description;
    else
        description = gText_QuitShopping;

    FillWindowPixelBuffer(WIN_TIER_DESCRIPTION, PIXEL_FILL(0));
    AdoptionMenuPrint(WIN_TIER_DESCRIPTION, description, 3, 1, 0, COLORID_NORMAL);
}

static void AdoptionMenuPrintPriceInList(u8 windowId, u32 tierId, u8 y)
{
    if (tierId != LIST_CANCEL)
    {
        ConvertIntToDecimalStringN(
            gStringVar1,
            sAdoptionTiersInfo[tierId].price,
            STR_CONV_MODE_LEFT_ALIGN,
            6);
        if (IsPlayerPartyAndPokemonStorageFull())
            StringCopy(gStringVar4, gText_SoldOut);
        else
            StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        u8 x = GetStringRightAlignXOffset(FONT_NARROW, gStringVar4, 120);
        AddTextPrinterParameterized4(windowId, FONT_NARROW, x, y, 0, 0, sAdoptionMenuTextColors[COLORID_TIER_LIST], TEXT_SKIP_DRAW, gStringVar4);
    }
}

static void AdoptionMenuAddTierIcon(s32 tierId, u8 iconSlot)
{
    u8 spriteId;
    u8 *spriteIdPtr = &sAdoptionMenuData->iconSpriteIds[iconSlot];
    if (*spriteIdPtr != SPRITE_NONE)
        return;

    if (tierId != LIST_CANCEL)
    {
        LoadMonIconPalette(SPECIES_EGG);
        spriteId = CreateMonIconNoPersonality(SPECIES_EGG, SpriteCB_MonIcon, 20, 84, 4);
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdPtr = spriteId;
            gSprites[spriteId].oam.priority = 0;
        }
    }
    else
    {
        spriteId = AddItemIconSprite(iconSlot + TAG_ICON_BASE, iconSlot + TAG_ICON_BASE, ITEM_LIST_END);
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdPtr = spriteId;
            gSprites[spriteId].x2 = 24;
            gSprites[spriteId].y2 = 88;
        }
    }
}

static void AdoptionMenuRemoveTierIcon(s32 tierId, u8 iconSlot)
{
    u8 *spriteIdPtr = &sAdoptionMenuData->iconSpriteIds[iconSlot];
    if (*spriteIdPtr == SPRITE_NONE)
        return;

    // Since all tier icons are the same (and use the same tag), their tiles and palettes are not freed.
    if (tierId == LIST_CANCEL)
    {
        FreeSpriteTilesByTag(iconSlot + TAG_ICON_BASE);
        FreeSpritePaletteByTag(iconSlot + TAG_ICON_BASE);
    }
    DestroySprite(&gSprites[*spriteIdPtr]);
    *spriteIdPtr = SPRITE_NONE;
}

static void AdoptionMenuInitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sAdoptionMenuBgTemplates, ARRAY_COUNT(sAdoptionMenuBgTemplates));
    SetBgTilemapBuffer(1, sAdoptionMenuData->tilemapBuffers[1]);
    SetBgTilemapBuffer(2, sAdoptionMenuData->tilemapBuffers[3]);
    SetBgTilemapBuffer(3, sAdoptionMenuData->tilemapBuffers[2]);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void AdoptionMenuInitWindows(void)
{
    InitWindows(sAdoptionMenuWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(WIN_MONEY, 1, BG_PLTT_ID(13));
    LoadMessageBoxGfx(WIN_MONEY, 0xA, BG_PLTT_ID(14));
    PutWindowTilemap(WIN_MONEY);
    PutWindowTilemap(WIN_TIER_LIST);
    PutWindowTilemap(WIN_TIER_DESCRIPTION);
}

static void AdoptionMenuDecompressBgGraphics(void)
{
    DecompressAndCopyTileDataToVram(1, gShopMenu_Gfx, 0x3A0, 0x3E3, 0);
    DecompressDataWithHeaderWram(gShopMenu_Tilemap, sAdoptionMenuData->tilemapBuffers[0]);
    LoadPalette(gShopMenu_Pal, BG_PLTT_ID(ADOPTION_MENU_PALETTE_ID), PLTT_SIZE_4BPP);
}

static void AdoptionMenuDrawGraphics(void)
{
    AdoptionMenuDrawMapGraphics();
    AdoptionMenuCopyMenuBgToBg1TilemapBuffer();
    AddMoneyLabelObject(19, 11);
    PrintMoneyAmountInMoneyBoxWithBorder(WIN_MONEY, 1, 13, GetMoney(&gSaveBlock1Ptr->money));
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
}

static void AdoptionMenuDrawMapGraphics(void)
{
    AdoptionMenuCollectObjectEventData();
    AdoptionMenuDrawObjectEvents();
    AdoptionMenuDrawMapBg();
}

static void AdoptionMenuCollectObjectEventData(void)
{
    s16 facingX, facingY;
    u8 x, y;
    u8 numObjects = 0;

    GetXYCoordsOneStepInFrontOfPlayer(&facingX, &facingY);

    for (y = 0; y < OBJECT_EVENTS_COUNT; y++)
        sAdoptionMenuData->viewportObjects[y][OBJ_EVENT_ID] = OBJECT_EVENTS_COUNT;

    for (y = 0; y < 5; y++)
        for (x = 0; x < 7; x++)
        {
            u8 objEventId = GetObjectEventIdByXY(facingX - 4 + x, facingY - 2 + y);
            if (objEventId != OBJECT_EVENTS_COUNT && !(gObjectEvents[objEventId].active && gObjectEvents[objEventId].graphicsId & OBJ_EVENT_MON && gObjectEvents[objEventId].localId != OBJ_EVENT_ID_FOLLOWER))
            {
                sAdoptionMenuData->viewportObjects[numObjects][OBJ_EVENT_ID] = objEventId;
                sAdoptionMenuData->viewportObjects[numObjects][X_COORD] = x;
                sAdoptionMenuData->viewportObjects[numObjects][Y_COORD] = y;
                sAdoptionMenuData->viewportObjects[numObjects][LAYER_TYPE] = MapGridGetMetatileLayerTypeAt(facingX - 4 + x, facingY - 2 + y);

                switch (gObjectEvents[objEventId].facingDirection)
                {
                case DIR_SOUTH:
                    sAdoptionMenuData->viewportObjects[numObjects][ANIM_NUM] = ANIM_STD_FACE_SOUTH;
                    break;
                case DIR_NORTH:
                    sAdoptionMenuData->viewportObjects[numObjects][ANIM_NUM] = ANIM_STD_FACE_NORTH;
                    break;
                case DIR_WEST:
                    sAdoptionMenuData->viewportObjects[numObjects][ANIM_NUM] = ANIM_STD_FACE_WEST;
                    break;
                case DIR_EAST:
                default:
                    sAdoptionMenuData->viewportObjects[numObjects][ANIM_NUM] = ANIM_STD_FACE_EAST;
                    break;
                }
                numObjects++;
            }
        }
}

static void AdoptionMenuDrawObjectEvents(void)
{
    u8 i;
    u8 spriteId;
    const struct ObjectEventGraphicsInfo *graphicsInfo;
    u8 weatherTemp = gWeatherPtr->palProcessingState;

    // This function runs during fadeout, so the weather palette processing state must be temporarily changed,
    // so that time-blending will work properly
    if (weatherTemp == WEATHER_PAL_STATE_SCREEN_FADING_OUT)
        gWeatherPtr->palProcessingState = WEATHER_PAL_STATE_IDLE;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (sAdoptionMenuData->viewportObjects[i][OBJ_EVENT_ID] == OBJECT_EVENTS_COUNT)
            continue;

        graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[sAdoptionMenuData->viewportObjects[i][OBJ_EVENT_ID]].graphicsId);

        spriteId = CreateObjectGraphicsSprite(
            gObjectEvents[sAdoptionMenuData->viewportObjects[i][OBJ_EVENT_ID]].graphicsId,
            SpriteCallbackDummy,
            (u16)sAdoptionMenuData->viewportObjects[i][X_COORD] * 16 + 8,
            (u16)sAdoptionMenuData->viewportObjects[i][Y_COORD] * 16 + 48 - graphicsInfo->height / 2,
            2);

        if (AdoptionMenuCheckIfObjectEventOverlapsMenuBg(sAdoptionMenuData->viewportObjects[i]) == TRUE)
        {
            gSprites[spriteId].subspriteTableNum = 4;
            gSprites[spriteId].subspriteMode = SUBSPRITES_ON;
        }

        StartSpriteAnim(&gSprites[spriteId], sAdoptionMenuData->viewportObjects[i][ANIM_NUM]);
    }

    gWeatherPtr->palProcessingState = weatherTemp; // restore weather state
    CpuFastCopy(gPlttBufferFaded + 16*16, gPlttBufferUnfaded + 16*16, PLTT_BUFFER_SIZE);
}

static bool8 AdoptionMenuCheckIfObjectEventOverlapsMenuBg(s16 *object)
{
    if (!AdoptionMenuCheckForOverlapWithMenuBg(object[X_COORD], object[Y_COORD] + 2) && object[LAYER_TYPE] != METATILE_LAYER_TYPE_COVERED)
        return TRUE;
    else
        return FALSE;
}

static void AdoptionMenuDrawMapBg(void)
{
    s16 x, y;
    const struct MapLayout *mapLayout;
    u16 metatile;
    u8 metatileLayerType;

    mapLayout = gMapHeader.mapLayout;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    x -= 4;
    y -= 4;

    for (s16 j = 0; j < 10; j++)
        for (s16 i = 0; i < 15; i++)
        {
            metatile = MapGridGetMetatileIdAt(x + i, y + j);
            if (AdoptionMenuCheckForOverlapWithMenuBg(i, j) == TRUE)
                metatileLayerType = MapGridGetMetatileLayerTypeAt(x + i, y + j);
            else
                metatileLayerType = METATILE_LAYER_TYPE_COVERED;

            if (metatile < NUM_METATILES_IN_PRIMARY)
                AdoptionMenuDrawMapMetatile(i, j, mapLayout->primaryTileset->metatiles + metatile * NUM_TILES_PER_METATILE, metatileLayerType);
            else
                AdoptionMenuDrawMapMetatile(i, j, mapLayout->secondaryTileset->metatiles + ((metatile - NUM_METATILES_IN_PRIMARY) * NUM_TILES_PER_METATILE), metatileLayerType);
        }
}

static void AdoptionMenuDrawMapMetatile(s16 x, s16 y, const u16 *src, u8 metatileLayerType)
{
    u16 offset1 = x * 2;
    u16 offset2 = y * 64;

    switch (metatileLayerType)
    {
    case METATILE_LAYER_TYPE_NORMAL:
        AdoptionMenuDrawMapMetatileLayer(sAdoptionMenuData->tilemapBuffers[3], offset1, offset2, src);
        AdoptionMenuDrawMapMetatileLayer(sAdoptionMenuData->tilemapBuffers[1], offset1, offset2, src + 4);
        break;
    case METATILE_LAYER_TYPE_COVERED:
        AdoptionMenuDrawMapMetatileLayer(sAdoptionMenuData->tilemapBuffers[2], offset1, offset2, src);
        AdoptionMenuDrawMapMetatileLayer(sAdoptionMenuData->tilemapBuffers[3], offset1, offset2, src + 4);
        break;
    case METATILE_LAYER_TYPE_SPLIT:
        AdoptionMenuDrawMapMetatileLayer(sAdoptionMenuData->tilemapBuffers[2], offset1, offset2, src);
        AdoptionMenuDrawMapMetatileLayer(sAdoptionMenuData->tilemapBuffers[1], offset1, offset2, src + 4);
        break;
    }
}

static void AdoptionMenuDrawMapMetatileLayer(u16 *dest, s16 offset1, s16 offset2, const u16 *src)
{
    dest[offset1 + offset2] = src[0]; // top left
    dest[offset1 + offset2 + 1] = src[1]; // top right
    dest[offset1 + offset2 + 32] = src[2]; // bottom left
    dest[offset1 + offset2 + 33] = src[3]; // bottom right
}

static bool8 AdoptionMenuCheckForOverlapWithMenuBg(int x, int y)
{
    const u16 *metatile = sAdoptionMenuData->tilemapBuffers[0];
    int offset1 = x * 2;
    int offset2 = y * 64;

    if (metatile[offset2 + offset1] == 0 &&
        metatile[offset2 + offset1 + 32] == 0 &&
        metatile[offset2 + offset1 + 1] == 0 &&
        metatile[offset2 + offset1 + 33] == 0)
        return TRUE;

    return FALSE;
}

static void AdoptionMenuCopyMenuBgToBg1TilemapBuffer(void)
{
    s16 i;
    u16 *dest = sAdoptionMenuData->tilemapBuffers[1];
    const u16 *src = sAdoptionMenuData->tilemapBuffers[0];

    for (i = 0; i < 1024; i++)
        if (src[i] != 0)
            dest[i] = src[i] + ((ADOPTION_MENU_PALETTE_ID << 12) | 0x3E3);
}

static void AdoptionMenuPrintCursor(u8 listTaskId, u8 colorId)
{
    u16 y = ListMenuGetYCoordForPrintingArrowCursor(listTaskId);
    AdoptionMenuPrint(WIN_TIER_LIST, gText_SelectorArrow2, 0, y, 0, colorId);
}

static void AdoptionMenuDisplayMessage(u8 taskId, const u8 *text, TaskFunc callback)
{
    DisplayMessageAndContinueTask(taskId, WIN_MESSAGE, 10, 14, FONT_NORMAL, GetPlayerTextSpeedDelay(), text, callback);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_AdoptionMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        s32 tierId = ListMenu_ProcessInput(tListTaskId);

        switch (tierId)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            ExitAdoptionMenu(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            tTierId = tierId;
            ClearWindowTilemap(WIN_TIER_DESCRIPTION);
            AdoptionMenuPrintCursor(tListTaskId, COLORID_GRAY_CURSOR);

            sAdoptionMenuData->totalCost = sAdoptionTiersInfo[tierId].price;

            if (IsPlayerPartyAndPokemonStorageFull())
                AdoptionMenuDisplayMessage(taskId, sText_NoEggsAvailable, AdoptionMenuReturnToTierList);
            else if (!IsEnoughMoney(&gSaveBlock1Ptr->money, sAdoptionMenuData->totalCost))
                AdoptionMenuDisplayMessage(taskId, gText_YouDontHaveMoney, AdoptionMenuReturnToTierList);
            else
            {
                StringCopy(gStringVar1, sAdoptionTiersInfo[tierId].name);
                ConvertIntToDecimalStringN(gStringVar2, sAdoptionMenuData->totalCost, STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
                AdoptionMenuDisplayMessage(taskId, gText_Var1IsItThatllBeVar2, AdoptionMenuConfirmPurchase);
            }
            break;
        }
    }
}

static void AdoptionMenuReturnToTierList(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ClearDialogWindowAndFrameToTransparent(WIN_MESSAGE, FALSE);
    RedrawListMenu(tListTaskId);
    AdoptionMenuPrintCursor(tListTaskId, COLORID_TIER_LIST);
    PutWindowTilemap(WIN_TIER_LIST);
    PutWindowTilemap(WIN_TIER_DESCRIPTION);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_AdoptionMenu;
};

static void AdoptionMenuConfirmPurchase(u8 taskId)
{
    CreateYesNoMenuWithCallbacks(taskId, &sAdoptionMenuYesNoWindowTemplate, 1, 0, 0,1, 13, &sAdoptionMenuYesNoFuncs);
}

static void Task_ReturnToTierListAfterPurchase(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
        AdoptionMenuReturnToTierList(taskId);
}

static void AdoptionMenuSubstractMoney(u8 taskId)
{
    IncrementGameStat(GAME_STAT_SHOPPED);
    RemoveMoney(&gSaveBlock1Ptr->money, sAdoptionMenuData->totalCost);
    PlaySE(SE_SHOP);
    PrintMoneyAmountInMoneyBox(WIN_MONEY, GetMoney(&gSaveBlock1Ptr->money), 0);
    gTasks[taskId].func = Task_ReturnToTierListAfterPurchase;
}

static void AdoptionMenuTryMakePurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PutWindowTilemap(WIN_TIER_LIST);

    u16 specie = *(typeof(u16) *)RandomElementArray(RNG_NONE, sAdoptionTiersInfo[tTierId].species, sizeof(u16), sAdoptionTiersInfo[tTierId].speciesCount);
    switch (ScriptGiveEgg(specie))
    {
    case MON_GIVEN_TO_PARTY:
        AdoptionMenuDisplayMessage(taskId, sText_YouReceivedEggParty, AdoptionMenuSubstractMoney);
        break;
    case MON_GIVEN_TO_PC:
        if (FlagGet(FLAG_SYS_PC_LANETTE))
            AdoptionMenuDisplayMessage(taskId, sText_YouReceivedEggLanettePC, AdoptionMenuSubstractMoney);
        else
            AdoptionMenuDisplayMessage(taskId, sText_YouReceivedEggSomeonePC, AdoptionMenuSubstractMoney);
        break;
    case MON_CANT_GIVE:
    default:
        AdoptionMenuDisplayMessage(taskId, sText_NoRoomForThisEgg, AdoptionMenuReturnToTierList);
        break;
    }
}

#undef tTierId
#undef tListTaskId

static void ShowAdoptionAskMenuAfterExiting(u8 taskId)
{
    CreateAdoptionMenu();
    DestroyTask(taskId);
}

static void Task_ReturnToAdoptionAskMenu(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
        DisplayItemMessageOnField(taskId, gText_CanIHelpWithAnythingElse, ShowAdoptionAskMenuAfterExiting);
}

static void MapPostLoadHook_ReturnToAdoptionAskMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_ReturnToAdoptionAskMenu, 8);
}

static void AdoptionMenuFreeMemory(void)
{
    Free(sAdoptionMenuData);
    FreeAllWindowBuffers();
}

static void Task_ExitAdoptionMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        RemoveMoneyLabelObject();
        AdoptionMenuFreeMemory();
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void ExitAdoptionMenu(u8 taskId)
{
    gFieldCallback = MapPostLoadHook_ReturnToAdoptionAskMenu;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ExitAdoptionMenu;
}

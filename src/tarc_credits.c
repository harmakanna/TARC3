#include "global.h"
#include "main.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "window.h"
#include "constants/characters.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#include "credits.h"
#include "title_screen.h"

enum CreditsType
{
    TITLE_CREDIT,
    REGULAR_CREDIT,
    WAIT_CREDIT,
    PAUSE_CREDIT,
    END_CREDIT
};

struct CreditsEntry
{
    enum CreditsType type;
    const u8 *text;
};

struct SampleUiState
{
    u8 loadState;
    u8 mode;
    u8 spriteId;
};

static EWRAM_DATA struct SampleUiState *sSampleUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

#define CREDITS_TITLE(str) {.type = TITLE_CREDIT,   .text = COMPOUND_STRING(str)}
#define CREDITS_NORMAL(str) {.type = REGULAR_CREDIT,   .text = COMPOUND_STRING(str)}
#define CREDITS_SCROLL(str) {.type = WAIT_CREDIT,   .text = (u8 *)(str)}
#define CREDITS_PAUSE(str) {.type = PAUSE_CREDIT,   .text = (u8 *)(str)}
#define CREDITS_END {.type = END_CREDIT, .text = NULL}

static const struct CreditsEntry sCreditsEntryTable[] =
{
    CREDITS_TITLE("A BETTER PLACE"),
    CREDITS_NORMAL("a game by Jamie, Kumatora, and Unfolding"),
    CREDITS_SCROLL(90),
    CREDITS_PAUSE(300),
    CREDITS_TITLE("built on"),
    CREDITS_NORMAL("RHH's pokeemerald-expansion (1.16)"),
    CREDITS_NORMAL("itself based on"),
    CREDITS_NORMAL("pret's decompilation of"),
    CREDITS_NORMAL("Pokemon Emerald by Game Freak"),
    CREDITS_TITLE("OTHER CONTRIBUTIONS"),
    CREDITS_TITLE("Feature Branches:"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Unbound Quest Menu by PSF"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Quest Icons by Belle"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Battle Speedup by hedara"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("BW Summary Screen by RavePossum"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("BW Party Menu by Archie"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("BW Music by Aichiya"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Rotom Start Menu by HashtagMarky"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("BW Battle Interface by mudskip"),
    CREDITS_NORMAL(""),
    CREDITS_TITLE("Tilesets:"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Silph City by Ekat, HeartlessDragoon,"),
    CREDITS_NORMAL("Morlockhater, Nemu, Ross Hawkins,"),
    CREDITS_NORMAL("Pokemon Dawn, Slimshady, Vurtax,"),
    CREDITS_NORMAL("Thedeadheroalistar, The-Red-Ex, and Zein"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Dark City by J-Treecko252"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Fountain by Kyledove and Speed"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Battle Platform + Stadium by KingTapir"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Hotel Interior by Ekat, Vurtax,"),
    CREDITS_NORMAL("HeartlessDragoon, and Halcyon Team"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Game Corner Heist by Ekat, Aveontrainer,"),
    CREDITS_NORMAL("Vurtax, Heartlessdragoon, HeroAlistar,"),
    CREDITS_NORMAL("Redblueyellow, SteamyJ, Anonaplacca,"),
    CREDITS_NORMAL("Pokémon Rejuvenation, and Puggsoy"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Ivy Woods by Ekat, Vurtax, Zein,"),
    CREDITS_NORMAL("and HeartlessDragoon"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Floating Cliffs by Ekat, HeroAlistar,"),
    CREDITS_NORMAL("Vurtax, and HeartlessDragoon"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Fall Cafe by Ekat, HeartlessDragoon,"),
    CREDITS_NORMAL("Vurtax, and HeroAlistar"),
    CREDITS_TITLE("Overworld Sprites:"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Leaf by kwenio"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Kumatora rip from Mother 3 by Solink"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Fairy Tale Girl from Mother 3 by"),
    CREDITS_NORMAL("kyle dove and ulithium dragon"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Officer by ryuujiryu"),
    CREDITS_NORMAL(""),
    CREDITS_TITLE("Trainer Sprites:"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Leaf by kwenio"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Idol by Rubire4"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Officer by Pawkkie and Project Palladium"),
    CREDITS_TITLE("Other Graphics:"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Title font (Xenosphere) by Darrell Flood"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Title screen city render by bbmotion"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("VR City sprite templates by Coffee Cup"),
    CREDITS_TITLE("Special Thanks:"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Team Aqua's Hideout, for hosting TARC,"),
    CREDITS_NORMAL("and cultivating a such a brilliant,"),
    CREDITS_NORMAL("helpful, and endlessly creative community."),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Doc Breeb, for being an excellent (and"),
    CREDITS_NORMAL("thorough) last minute playtester."),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Jamie, for incredible technical wizardry,"),
    CREDITS_NORMAL("creating brand new systems from scratch,"),
    CREDITS_NORMAL("and a laserlike attention to detail."),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Kumatora, for raw talent, drive, and"),
    CREDITS_NORMAL("competence in every single field -"),
    CREDITS_NORMAL("spriting, writing, map design,"),
    CREDITS_NORMAL("scripting, music, and game design."),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("Unfolding, for writing the credits!"),
    CREDITS_NORMAL("hehehehehe"),
    CREDITS_NORMAL(""),
    CREDITS_TITLE("Unfolding's Game Recommendations:"),
    CREDITS_NORMAL(""),
    CREDITS_NORMAL("It's become my custom to spotlight some"),
    CREDITS_NORMAL("better games you could be playing, so"),
    CREDITS_NORMAL("go check out Chants of Sennaar and"),
    CREDITS_NORMAL("Cryptmaster, two small indie games"),
    CREDITS_NORMAL("about language and meaning!"),
    CREDITS_SCROLL(90),
    CREDITS_TITLE("Thank you for playing!"),
    CREDITS_SCROLL(90),
    CREDITS_PAUSE(300),
    CREDITS_PAUSE(300),
    CREDITS_END,
};

static void CB2_TarcCredits()
{

}

static void SampleUi_SetupCB(void);

void StartBetterPlaceCredits(void)
{
   // SetMainCallback2(CB2_StartCreditsSequence);
    sSampleUiState = AllocZeroed(sizeof(struct SampleUiState));

    sSampleUiState->loadState = 0;

    SetMainCallback2(SampleUi_SetupCB);
    m4aSongNumStart(MUS_BW12_147);
}

enum WindowIds
{
    WINDOW_0
};

static const struct BgTemplate sSampleUiBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    }
};

static const struct WindowTemplate sSampleUiWindowTemplates[] =
{
    [WINDOW_0] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 0,
        .width = 26,
        .height = 24,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

enum FontColor
{
    FONT_WHITE,
    FONT_RED
};

static const u8 sSampleUiWindowFontColors[][3] =
{
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
};

// Callbacks for the sample UI
static void SampleUi_MainCB(void);
static void SampleUi_VBlankCB(void);

// Sample UI tasks
static void Task_SampleUiWaitFadeIn(u8 taskId);
static void Task_SampleUiMainInput(u8 taskId);
static void Task_SampleUiWaitAndExit(u8 taskId);

// Sample UI helper functions
static void SampleUi_ResetGpuRegsAndBgs(void);
static bool8 SampleUi_InitBgs(void);
static void SampleUi_FadeAndBail(void);
static bool8 SampleUi_LoadGraphics(void);
static void SampleUi_InitWindows(void);
static void SampleUi_PrintUiSampleWindowText(void);
static void SampleUi_FreeResources(void);

static void Task_SampleUiPrintTagline(u8 taskId);

static void PrintCreditsLine(u32 tableIndex)
{
    u32 font;

    if (sCreditsEntryTable[tableIndex].type == TITLE_CREDIT)
        font = FONT_NORMAL;
    else if (sCreditsEntryTable[tableIndex].type == REGULAR_CREDIT)
        font = FONT_SMALL;
    else
        return;

    u32 width = GetStringWidth(font, sCreditsEntryTable[tableIndex].text, 0);
    s32 x;
    if (width > 218)
        x = 0;
    else
        x = (240 - width) / 2 - 16;
    //DebugPrintf("tableIndex %d width %d x %d", tableIndex, width, x);
    AddTextPrinterParameterized4(WINDOW_0, font, x, 160, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sCreditsEntryTable[tableIndex].text);
}

#define SCROLL_CREDITS_SPEED 1
#define SCROLL_CREDITS_DELAY 2

#define TITLE_CREDIT_SPACING 64
#define REGULAR_CREDIT_SPACING 16

static void PrepareCreditAction(u8 taskId)
{
    switch (sCreditsEntryTable[++gTasks[taskId].data[3]].type)
    {
        case TITLE_CREDIT:
            gTasks[taskId].data[2] = TITLE_CREDIT_SPACING;
            break;
        case REGULAR_CREDIT:
            gTasks[taskId].data[2] = REGULAR_CREDIT_SPACING;
            break;
        case PAUSE_CREDIT:
            gTasks[taskId].data[0] = 2;
        case WAIT_CREDIT:
            gTasks[taskId].data[2] = (u32) sCreditsEntryTable[gTasks[taskId].data[3]].text;
            break;
        case END_CREDIT:
            BeginNormalPaletteFade(PALETTES_ALL, 3, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_SampleUiWaitAndExit;
            break;
    }
}
static void Task_PrintCredits(u8 taskId)
{
    if (gTasks[taskId].data[2] == 0)
    {
        gTasks[taskId].data[0] = 1;
        PrintCreditsLine(gTasks[taskId].data[3]);
        PrepareCreditAction(taskId);
    }
    if (gTasks[taskId].data[0] == 0)
    {
        //PrintCreditsLine(0, Y_CREDIT_INIT);
        //PrintCreditsLine(1, Y_CREDIT_INIT + 16);

        CopyWindowToVram(WINDOW_0, COPYWIN_GFX);
        gTasks[taskId].data[0]++;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 2;
    }
    else if (gTasks[taskId].data[0] == 1)
    {
        //DebugPrintf("ScrollWindow");
        if (++gTasks[taskId].data[1] % SCROLL_CREDITS_DELAY == 0)
        {
            gTasks[taskId].data[2] -= SCROLL_CREDITS_SPEED;
            ScrollWindow(WINDOW_0, 0, SCROLL_CREDITS_SPEED, 0);
            CopyWindowToVram(WINDOW_0, COPYWIN_GFX);
            gTasks[taskId].data[1] = 0;
        }
    }
    else if (gTasks[taskId].data[0] == 2)
    {
        gTasks[taskId].data[2] -= 1;
    }

}

static void SampleUi_ResetGpuRegsAndBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    CpuFill16(0, (void *)VRAM, VRAM_SIZE);
    CpuFill32(0, (void *)OAM, OAM_SIZE);
}

static void SampleUi_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        SampleUi_ResetGpuRegsAndBgs();
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (SampleUi_InitBgs())
        {
            sSampleUiState->loadState = 0;
            gMain.state++;
        }
        else
        {
            SampleUi_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (SampleUi_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        SampleUi_InitWindows();
        CreateTask(Task_SampleUiWaitFadeIn, 0);
        BeginNormalPaletteFade(PALETTES_ALL, 2, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 5:
        SetVBlankCallback(SampleUi_VBlankCB);
        SetMainCallback2(SampleUi_MainCB);
        break;
    }
}

static void SampleUi_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void SampleUi_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_SampleUiWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_PrintCredits;
        gTasks[taskId].data[0] = 1;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0;
    }
}


static const u8 sText_Text1[] = _("Jamie's Tech Demo");
static void SampleUi_PrintInitialText(void)
{
    FillWindowPixelBuffer(WINDOW_0, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    AddTextPrinterParameterized4(WINDOW_0, FONT_NORMAL, 24, 3, 0, 0,
        sSampleUiWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_Text1);

    CopyWindowToVram(WINDOW_0, COPYWIN_GFX);
}


#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 SampleUi_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sSampleUiBgTemplates, NELEMS(sSampleUiBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void Task_SampleUiWaitAndExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        //DebugPrintf("Task_SampleUiWaitAndExit");
        SetMainCallback2(CB2_InitTitleScreen);
        SampleUi_FreeResources();
        DestroyTask(taskId);
    }
}

static void SampleUi_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_SampleUiWaitAndExit, 0);
    SetVBlankCallback(SampleUi_VBlankCB);
    SetMainCallback2(SampleUi_MainCB);
}

static bool8 SampleUi_LoadGraphics(void)
{
    switch (sSampleUiState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        sSampleUiState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            sSampleUiState->loadState++;
        }

        break;
    case 2:
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sSampleUiState->loadState++;
    default:
        sSampleUiState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void SampleUi_InitWindows(void)
{
    InitWindows(sSampleUiWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WINDOW_0, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_0);
    CopyWindowToVram(WINDOW_0, 3);
}

static void SampleUi_FreeResources(void)
{
    if (sSampleUiState != NULL)
    {
        Free(sSampleUiState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}

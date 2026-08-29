#include "global.h"
#include "gpu_regs.h"
#include "main.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "task.h"
#include "trainer_pokemon_sprites.h"

static void CB2_GraphicsSandbox(void);
static void VBlankCB_GraphicsSandbox(void);

static void TrainerTransform(void);

void GraphicsSandboxInit(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);

    ResetPaletteFade();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();

    SetVBlankCallback(VBlankCB_GraphicsSandbox);
    SetMainCallback2(CB2_GraphicsSandbox);

    TrainerTransform();
}

static void Task_TransformTrainer(u8 taskId);

static void CB2_GraphicsSandbox(void)
{
    RunTasks();
    AnimateSprites();
    //if (!FuncIsActiveTask(Task_TransformTrainer))
    BuildOamBuffer();
    UpdatePaletteFade();
}

static EWRAM_DATA u16 sOamTest1 = 0;
static EWRAM_DATA u16 sOamTest2 = 0;
static EWRAM_DATA u16 sVcountTest = 0;

static void VBlankCB_GraphicsSandbox(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    
}

static void HblankCb_SetOamSprite(void)
{
    u16 *ptr = (void *)OAM + 4;
    //*ptr = sOamTest;
    if (REG_VCOUNT < sVcountTest)
        *ptr = sOamTest1;
    else
        *ptr = sOamTest2;
    //DebugPrintf("VCount_SetOamSprite %d %d", sVcountTest, REG_VCOUNT);
}

static void Task_TransformTrainer(u8 taskId)
{
    //SetVBlankCallback(NULL);
    sVcountTest = 159 - gTasks[taskId].data[3];
    
    //DmaCopy16(0, ((void *)&gSprites[gTasks[taskId].data[0]].oam) + 4, (void *)OAM + 4, 2);
    sOamTest1 = *((u16 *)(((void *)&gSprites[gTasks[taskId].data[0]].oam) + 4));
    sOamTest2 = *((u16 *)(((void *)&gSprites[gTasks[taskId].data[4]].oam) + 4));
    /*
    if (gTasks[taskId].data[3] < 120)
    {
        //*(u16 *)(OAM + 4) = gTasks[taskId].data[1];
        //gSprites[gTasks[taskId].data[0]].oam.tileNum = gTasks[taskId].data[1];
        //gSprites[gTasks[taskId].data[0]].oam.paletteNum = 0;
        DmaCopy16(0, ((void *)&gSprites[gTasks[taskId].data[0]].oam) + 4, (void *)OAM + 4, 2);
        //for (u)
        //DebugPrintf()
        //memcpy(&gMain.oamBuffer[0], &gSprites[gTasks[taskId].data[0]].oam, sizeof(struct OamData));
    }
    else
    {
        //*(u16 *)(OAM + 4) = gTasks[taskId].data[2];
        //gSprites[gTasks[taskId].data[0]].oam.tileNum = gTasks[taskId].data[2];
        //gSprites[gTasks[taskId].data[0]].oam.paletteNum = 1;
        DmaCopy16(0, ((void *)&gSprites[gTasks[taskId].data[4]].oam) + 4, (void *)OAM + 4, 2);
        //memcpy(&gMain.oamBuffer[0],  &gSprites[gTasks[taskId].data[4]].oam, sizeof(struct OamData));
    }
    */
    gTasks[taskId].data[3]++;
    if (gTasks[taskId].data[3] == 160)
        gTasks[taskId].data[3] = 0;
    DebugPrintf("Task_TransformTrainer %d", gTasks[taskId].data[3]);
}

static void TrainerTransform(void)
{
    SetHBlankCallback(HblankCb_SetOamSprite);
    EnableInterrupts(INTR_FLAG_HBLANK | INTR_FLAG_VBLANK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    u32 taskId = CreateTask(Task_TransformTrainer, 0);
    
    gTasks[taskId].data[0] = CreateTrainerPicSprite(TRAINER_PIC_MAY, TRUE, 120, 80, 0, TAG_NONE);
    u32 spriteId =  CreateTrainerPicSprite(TRAINER_PIC_DIGITAL_SOPHIE, TRUE, 88, 48, 1, TAG_NONE);
    gTasks[taskId].data[4] = spriteId;
    gSprites[spriteId].invisible = TRUE;
    //void *ptr = &gSprites[gTasks[taskId].data[0]].oam + 4;
    gTasks[taskId].data[1] = gSprites[gTasks[taskId].data[0]].oam.tileNum;
    //ptr = &gSprites[gTasks[taskId].data[0]].oam + 4;
    gTasks[taskId].data[2] = gSprites[spriteId].oam.tileNum;
    gTasks[taskId].data[3] = 0;
   
    //LoadOam();
}

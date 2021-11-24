/*
 * flexRAM_helper.c
 *
 *  Created on: Nov 22, 2021
 *      Author: jaeyeon
 */

#include "fsl_flexram.h"
#include "fsl_debug_console.h"
#include "fsl_cache.h"
#include "flexRAM_helper.h"

void APP_FLEXRAM_IRQ_HANDLER(void)
{
    if (FLEXRAM_GetInterruptStatus(APP_FLEXRAM) & kFLEXRAM_OCRAMAccessError)
    {
        FLEXRAM_ClearInterruptStatus(APP_FLEXRAM, kFLEXRAM_OCRAMAccessError);
        s_flexram_ocram_access_error_match = true;
    }

    __DSB();
}


void BOARD_InitFlexRAM()
{
	 PRINTF("\r\nFLEXRAM ram allocate example.\r\n");

	/* enable IRQ */
	EnableIRQ(APP_FLEXRAM_IRQ);
	/* reallocate ram */
	OCRAM_Reallocate();
	/* init flexram */
	FLEXRAM_Init(APP_FLEXRAM);
	/*test OCRAM access*/
	OCRAM_Access();

	PRINTF("\r\nFLEXRAM ram allocate example finish.\r\n");
}

static status_t OCRAM_Reallocate(void)
{
    flexram_allocate_ram_t ramAllocate = {
        .ocramBankNum = APP_OCRAM_ALLOCATE_BANK_NUM,
        .dtcmBankNum  = APP_DTCM_ALLOCATE_BANK_NUM,
        .itcmBankNum  = APP_ITCM_ALLOCATE_BANK_NUM,
    };

    PRINTF("\r\nAllocate on-chip ram:\r\n");
    PRINTF("\r\n   OCRAM bank numbers %d\r\n", ramAllocate.ocramBankNum);
    PRINTF("\r\n   DTCM  bank numbers %d\r\n", ramAllocate.dtcmBankNum);
    PRINTF("\r\n   ITCM  bank numbers %d\r\n", ramAllocate.itcmBankNum);

    if (FLEXRAM_AllocateRam(&ramAllocate) != kStatus_Success)
    {
        PRINTF("\r\nAllocate on-chip ram fail\r\n");
        return kStatus_Fail;
    }
    else
    {
        PRINTF("\r\nAllocate on-chip ram success\r\n");
    }

    return kStatus_Success;
}

static void OCRAM_Access(void)
{
    uint32_t *ocramAddr = (uint32_t *)APP_FLEXRAM_OCRAM_START_ADDR;

    /* enable FLEXRAM OCRAM access error interrupt*/
    FLEXRAM_EnableInterruptSignal(APP_FLEXRAM, kFLEXRAM_OCRAMAccessError);

    for (;;)
    {
        *ocramAddr = 0xCCU;
        /* Synchronizes the execution stream with memory accesses */
        __DSB();
        __ISB();

        DCACHE_CleanByRange((uint32_t)ocramAddr, sizeof(uint32_t));

        /* check ocram access error event */
        if (s_flexram_ocram_access_error_match)
        {
            s_flexram_ocram_access_error_match = false;
            PRINTF("\r\nOCRAM access to 0x%x boundary.\r\n", ocramAddr);
            break;
        }

        ocramAddr++;
    }
}

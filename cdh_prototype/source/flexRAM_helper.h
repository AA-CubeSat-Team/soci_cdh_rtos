/*
 * flexRAM_helper.h
 *
 *  Created on: Nov 22, 2021
 *      Author: jaeyeon
 *
 * Based on flexram_ram_allocate SDK example project.
 */

#ifndef FLEXRAM_HELPER_H_
#define FLEXRAM_HELPER_H_


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APP_FLEXRAM     FLEXRAM
#define APP_FLEXRAM_IRQ FLEXRAM_IRQn

#define APP_FLEXRAM_IRQ_HANDLER FLEXRAM_IRQHandler

#define APP_FLEXRAM_OCRAM_START_ADDR 0x20200000
#define APP_FLEXRAM_OCRAM_MAGIC_ADDR 0x202000A0

#define APP_FLEXRAM_DTCM_START_ADDR 0x20000000
#define APP_FLEXRAM_DTCM_MAGIC_ADDR 0x200000A0

#define APP_FLEXRAM_ITCM_START_ADDR 0x0
#define APP_FLEXRAM_ITCM_MAGIC_ADDR 0xA0

/* OCRAM relocate definition */
#define APP_OCRAM_SIZE              (256 * 1024U)
#define APP_OCRAM_ALLOCATE_BANK_NUM 2
#define APP_ITCM_ALLOCATE_BANK_NUM  4
#define APP_DTCM_ALLOCATE_BANK_NUM  2

/*******************************************************************************
 * Variables
 ******************************************************************************/
static bool s_flexram_ocram_access_error_match = false;

/*
 * initializes and reallocates flexRAM
 */
void BOARD_InitFlexRAM(void);

/*!
 * @brief OCRAM reallocate function.
 *
 * @param base FLEXRAM base address.
 */
static status_t OCRAM_Reallocate(void);

/*!
 * @brief ocram access function.
 *
 * @param base FLEXRAM base address.
 */
static void OCRAM_Access(void);

#endif /* FLEXRAM_HELPER_H_ */

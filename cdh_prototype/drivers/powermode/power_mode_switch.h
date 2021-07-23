/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _POWER_MODE_SWITCH_H_
#define _POWER_MODE_SWITCH_H_

#include "fsl_common.h"
#include "lpm.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum _app_wakeup_source
{
    kAPP_WakeupSourceGPT, /*!< Wakeup by PIT.        */
    kAPP_WakeupSourcePin, /*!< Wakeup by external pin. */
} app_wakeup_source_t;

extern lpm_power_mode_t s_targetPowerMode;
extern lpm_power_mode_t s_curRunMode;
extern const char *s_modeNames[];

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

void APP_PowerPreSwitchHook(lpm_power_mode_t targetMode);
void APP_PowerPostSwitchHook(lpm_power_mode_t targetMode);
lpm_power_mode_t APP_GetLPMPowerMode(void);

/*API functions*/
void APP_WAKEUP_GPT_IRQn_HANDLER(void);
void APP_WAKEUP_BUTTON_IRQ_HANDLER(void);
void APP_SetRunMode(lpm_power_mode_t powerMode);
bool APP_CheckPowerMode(lpm_power_mode_t originPowerMode, lpm_power_mode_t targetPowerMode);
lpm_power_mode_t APP_GetLPMPowerMode(void);
lpm_power_mode_t APP_GetRunMode(void);
//uint8_t APP_GetWakeupTimeout(void);
void APP_ShowPowerMode(lpm_power_mode_t powerMode);


#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* _POWER_MODE_SWITCH_H_ */

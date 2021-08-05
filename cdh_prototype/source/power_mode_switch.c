/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "fsl_common.h"
#include "power_mode_switch.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "lpm.h"
#include "fsl_gpt.h"
#include "fsl_lpuart.h"
#include "specific.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define CPU_NAME "iMXRT1021"

/*******************************************************************************
 * Variables
 ******************************************************************************/

lpm_power_mode_t s_targetPowerMode;
lpm_power_mode_t s_curRunMode = LPM_PowerModeLowPowerRun; //LPM_PowerModeOverRun

const char *s_modeNames[] = {"Over RUN",    "Full Run",       "Low Speed Run", "Low Power Run",
                                    "System Idle", "Low Power Idle", "Suspend"};

/*******************************************************************************
 * Code
 ******************************************************************************/


lpm_power_mode_t APP_GetRunMode(void)
{
    return s_curRunMode;
}

void APP_SetRunMode(lpm_power_mode_t powerMode)
{
    s_curRunMode = powerMode;
}

/*
 * Check whether could switch to target power mode from current mode.
 * Return true if could switch, return false if could not switch.
 */
bool APP_CheckPowerMode(lpm_power_mode_t originPowerMode, lpm_power_mode_t targetPowerMode)
{
    bool modeValid = true;

    /* If current mode is Lowpower run mode, the target mode should not be system idle mode. */
    if ((originPowerMode == LPM_PowerModeLowPowerRun) && (targetPowerMode == LPM_PowerModeSysIdle))
    {
        PRINTF("Low Power Run mode can't enter System Idle mode.\r\n");
        modeValid = false;
    }

    /* Don't need to change power mode if current mode is already the target mode. */
    if (originPowerMode == targetPowerMode)
    {
        PRINTF("Already in the target power mode.\r\n");
        modeValid = false;
    }

    return modeValid;
}

lpm_power_mode_t APP_GetLPMPowerMode(void)
{
    return s_targetPowerMode;
}

static void APP_ShowPowerMode(lpm_power_mode_t powerMode)
{
    if (powerMode <= LPM_PowerModeEnd)
    {
        PRINTF("    Power mode: %s\r\n", s_modeNames[powerMode]);
        APP_PrintRunFrequency(1);
    }
    else
    {
        assert(0);
    }
}

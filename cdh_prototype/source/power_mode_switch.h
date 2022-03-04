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

extern lpm_power_mode_t s_targetPowerMode;
extern lpm_power_mode_t s_curRunMode;
extern const char *s_modeNames[];

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

lpm_power_mode_t APP_GetLPMPowerMode(void);
void APP_SetRunMode(lpm_power_mode_t powerMode);

#endif /* _POWER_MODE_SWITCH_H_ */

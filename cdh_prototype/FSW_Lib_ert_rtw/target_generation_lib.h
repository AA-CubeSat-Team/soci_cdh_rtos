/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_generation_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_target_generation_lib_h_
#define RTW_HEADER_target_generation_lib_h_
#include <math.h>
#include <string.h>
#ifndef FSW_Lib_COMMON_INCLUDES_
#define FSW_Lib_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include "FSW_Lib_types.h"

/* Child system includes */
#include "quat_rectify_lib.h"
#include "rt_sys_FSW_Lib_12.h"
#include "rt_sys_FSW_Lib_16.h"
#include "rt_sys_FSW_Lib_23.h"

extern void target_generation_lib_Init(void);
extern void target_generation_lib(uint8_T rtu_gnc_mode, const real_T
  rtu_sc2sun_eci_unit[3], const real_T rtu_sc2targ_eci_unit[3], const real_T
  rtu_r_eci_m[3], const real_T rtu_quat_soar_cmd[4], real_T rtu_MET_epoch,
  real_T rtu_MET_utc_s, boolean_T rtu_sc_above_targ, real_T rtu_img_active);

#endif                                 /* RTW_HEADER_target_generation_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

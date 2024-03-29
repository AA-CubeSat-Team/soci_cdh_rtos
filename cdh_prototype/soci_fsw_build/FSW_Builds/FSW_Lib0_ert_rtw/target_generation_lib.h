/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_generation_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_target_generation_lib_h_
#define RTW_HEADER_target_generation_lib_h_
#include <math.h>
#include <string.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "quat_rectify_lib.h"
#include "rt_sys_MEKF_lib_37.h"
#include "rt_sys_MEKF_lib_41.h"
#include "rt_sys_MEKF_lib_48.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

extern void target_generation_lib_Init(void);
extern void target_generation_lib(uint8_T rtu_gnc_mode, const real_T
  rtu_sc2sun_eci_unit[3], const real_T rtu_sc2targ_eci_unit[3], const real_T
  rtu_r_eci_m[3], const real_T rtu_sc_quat_in[4], const real_T
  rtu_body_rates_radps[3], const real_T rtu_RWA_rpm[4], const real_T
  rtu_quat_soar_cmd[4], real_T rtu_MET_epoch, real_T rtu_MET_utc_s, real_T
  rty_quat_cmd[4], real_T rty_body_rates_cmd[3], real_T rty_torque_body_ff[3]);

#endif                                 /* RTW_HEADER_target_generation_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

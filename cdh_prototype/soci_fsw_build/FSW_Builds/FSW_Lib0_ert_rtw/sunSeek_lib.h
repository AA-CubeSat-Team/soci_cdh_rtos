/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sunSeek_lib.h
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

#ifndef RTW_HEADER_sunSeek_lib_h_
#define RTW_HEADER_sunSeek_lib_h_
#include <math.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

extern void sunSeek_lib(uint8_T rtu_ss_valid, const real_T
  rtu_sc2sun_pd_body_unit[3], const real_T rtu_sc2sun_ss_body_unit[3], const
  real_T rtu_w_err_radps[3], real_T rty_torque_cmd_body_Nm[3]);

#endif                                 /* RTW_HEADER_sunSeek_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

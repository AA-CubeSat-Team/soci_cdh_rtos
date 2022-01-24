/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_39.h
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 14 15:17:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_sys_MEKF_lib_39_h_
#define RTW_HEADER_rt_sys_MEKF_lib_39_h_
#include <math.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Parameters for system: '<S188>/Positive Trace' */
struct P_PositiveTrace_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S190>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S190>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S190>/Gain1'
                                        */
};

extern void PositiveTrace(real_T rtu_traceDCM, const real_T rtu_DCM[9], real_T
  *rty_qwqxqyqz, real_T rty_qwqxqyqz_i[3], P_PositiveTrace *localP);

#endif                                 /* RTW_HEADER_rt_sys_MEKF_lib_39_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

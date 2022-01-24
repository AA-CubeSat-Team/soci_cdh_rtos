/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_rectify_lib.h
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

#ifndef RTW_HEADER_quat_rectify_lib_h_
#define RTW_HEADER_quat_rectify_lib_h_
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Parameters for system: '<S125>/quat_rectify_lib' */
struct P_quat_rectify_lib_ {
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<S181>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S181>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S181>/Switch'
                                        */
};

extern void quat_rectify_lib(const real_T rtu_q[4], real_T rty_rectq[4],
  P_quat_rectify_lib *localP);

#endif                                 /* RTW_HEADER_quat_rectify_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

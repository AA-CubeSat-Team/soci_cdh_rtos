/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_err_lib.h
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

#ifndef RTW_HEADER_quat_err_lib_h_
#define RTW_HEADER_quat_err_lib_h_
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "quat_rectify_lib.h"

/* Parameters for system: '<S5>/quat_err_lib' */
struct P_quat_err_lib_ {
  P_quat_rectify_lib quat_rectify_lib_c;/* '<S231>/quat_rectify_lib' */
};

extern void quat_err_lib(const real_T rtu_quat_cmd[4], const real_T rtu_quat_sc
  [4], real_T rty_quat_err[4], P_quat_err_lib *localP);

#endif                                 /* RTW_HEADER_quat_err_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

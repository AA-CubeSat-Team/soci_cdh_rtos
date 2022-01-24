/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: null_control_lib.h
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

#ifndef RTW_HEADER_null_control_lib_h_
#define RTW_HEADER_null_control_lib_h_
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Parameters for system: '<S236>/null_control_lib1' */
struct P_null_control_lib_ {
  real_T null_control_input_Value[3];  /* Expression: zeros(3,1)
                                        * Referenced by: '<S255>/null_control_input'
                                        */
};

extern void null_control_lib(real_T rty_null_MTQ_cmd_Am2[3], P_null_control_lib *
  localP);

#endif                                 /* RTW_HEADER_null_control_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

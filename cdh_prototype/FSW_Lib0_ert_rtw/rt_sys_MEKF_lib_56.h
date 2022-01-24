/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_56.h
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

#ifndef RTW_HEADER_rt_sys_MEKF_lib_56_h_
#define RTW_HEADER_rt_sys_MEKF_lib_56_h_
#include <math.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"
#include "rt_assert.h"

/* Block signals and states (default storage) for system '<S191>/If Warning//Error' */
typedef struct {
  real_T rtu_dcm[9];
  void* Assertion_slioAccessor;        /* '<S220>/Assertion' */
  void* Assertion_slioAccessor_e;      /* '<S221>/Assertion' */
  void* Assertion_slioAccessor_l;      /* '<S222>/Assertion' */
  void* Assertion_slioAccessor_p;      /* '<S223>/Assertion' */
} DW_IfWarningError;

/* Parameters for system: '<S191>/If Warning//Error' */
struct P_IfWarningError_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S217>/Constant1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S216>/Constant1'
                                        */
  real_T Bias1_Bias[9];                /* Expression: -eye(3)
                                        * Referenced by: '<S218>/Bias1'
                                        */
  real_T Bias_Bias;                    /* Expression: -1
                                        * Referenced by: '<S219>/Bias'
                                        */
};

extern void IfWarningError(const real_T rtu_dcm[9], DW_IfWarningError *localDW,
  P_IfWarningError *localP, real_T rtp_action, real_T rtp_tolerance);

#endif                                 /* RTW_HEADER_rt_sys_MEKF_lib_56_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

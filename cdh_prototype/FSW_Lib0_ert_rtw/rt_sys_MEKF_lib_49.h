/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_49.h
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

#ifndef RTW_HEADER_rt_sys_MEKF_lib_49_h_
#define RTW_HEADER_rt_sys_MEKF_lib_49_h_
#include <math.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Parameters for system: '<S188>/Negative Trace' */
struct P_NegativeTrace_ {
  real_T Constant2_Value[2];           /* Expression: [0 1]
                                        * Referenced by: '<S205>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S205>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S206>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S194>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S194>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S194>/Gain4'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S194>/Gain'
                                        */
  real_T Constant2_Value_h[2];         /* Expression: [0 1]
                                        * Referenced by: '<S210>/Constant2'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0.5
                                        * Referenced by: '<S210>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S211>/Constant'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S195>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S195>/Gain2'
                                        */
  real_T Gain3_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S195>/Gain3'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 0.5
                                        * Referenced by: '<S195>/Gain'
                                        */
  real_T Constant2_Value_i[2];         /* Expression: [0 1]
                                        * Referenced by: '<S200>/Constant2'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0.5
                                        * Referenced by: '<S200>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S201>/Constant'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 1
                                        * Referenced by: '<S193>/Gain1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S193>/Gain2'
                                        */
  real_T Gain3_Gain_fl;                /* Expression: 1
                                        * Referenced by: '<S193>/Gain3'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 0.5
                                        * Referenced by: '<S193>/Gain'
                                        */
};

extern void NegativeTrace(const real_T rtu_DCM[9], real_T rty_qwqxqyqz[4],
  P_NegativeTrace *localP);

#endif                                 /* RTW_HEADER_rt_sys_MEKF_lib_49_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

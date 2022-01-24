/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CrossProdMatrix_lib.h
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

#ifndef RTW_HEADER_CrossProdMatrix_lib_h_
#define RTW_HEADER_CrossProdMatrix_lib_h_
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Parameters for system: '<S132>/CrossProdMatrix_lib' */
struct P_CrossProdMatrix_lib_ {
  real_T null_Value;                   /* Expression: 0
                                        * Referenced by: '<S138>/null'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S138>/Gain'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S138>/Gain3'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S138>/Gain1'
                                        */
};

/* Parameters for system: '<S124>/CrossProdMatrix_lib' */
struct P_CrossProdMatrix_lib_g_ {
  real_T null_Value;                   /* Expression: 0
                                        * Referenced by: '<S161>/null'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S161>/Gain'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S161>/Gain3'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S161>/Gain1'
                                        */
};

extern void CrossProdMatrix_lib(real_T rtu_vector, real_T rtu_vector_h, real_T
  rtu_vector_o, real_T rty_skew_mat[9], P_CrossProdMatrix_lib *localP);
extern void CrossProdMatrix_lib_m(const real_T rtu_vector[3], real_T
  rty_skew_mat[9], P_CrossProdMatrix_lib_g *localP);

#endif                                 /* RTW_HEADER_CrossProdMatrix_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

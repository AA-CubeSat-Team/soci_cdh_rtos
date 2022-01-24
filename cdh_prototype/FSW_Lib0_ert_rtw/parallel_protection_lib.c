/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_protection_lib.c
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

#include "parallel_protection_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for atomic system:
 *    '<S115>/parallel_protection_lib'
 *    '<S125>/parallel_protection_lib'
 *    '<S125>/parallel_protection_lib1'
 */
boolean_T parallel_protection_lib(const real_T rtu_vector_1[3], const real_T
  rtu_vector_2[3], P_parallel_protection_lib *localP, real_T rtp_min_angle_deg)
{
  boolean_T rty_non_parallel_0;

  /* Switch: '<S126>/Switch' incorporates:
   *  Abs: '<S126>/Abs'
   *  Constant: '<S126>/Constant'
   *  Constant: '<S126>/Constant1'
   *  Constant: '<S126>/min_angle_deg'
   *  DotProduct: '<S126>/Dot Product'
   *  DotProduct: '<S126>/Dot Product1'
   *  DotProduct: '<S126>/Dot Product2'
   *  Gain: '<S126>/DEG2RAD'
   *  Product: '<S126>/Divide'
   *  Product: '<S126>/Multiply'
   *  Sqrt: '<S126>/Sqrt'
   *  Sqrt: '<S126>/Sqrt1'
   *  Sum: '<S126>/Sum'
   *  Trigonometry: '<S126>/Cos'
   */
  if (fabs(((rtu_vector_1[0] * rtu_vector_2[0] + rtu_vector_1[1] * rtu_vector_2
             [1]) + rtu_vector_1[2] * rtu_vector_2[2]) / (sqrt((rtu_vector_1[0] *
          rtu_vector_1[0] + rtu_vector_1[1] * rtu_vector_1[1]) + rtu_vector_1[2]
         * rtu_vector_1[2]) * sqrt((rtu_vector_2[0] * rtu_vector_2[0] +
          rtu_vector_2[1] * rtu_vector_2[1]) + rtu_vector_2[2] * rtu_vector_2[2])))
      - cos(rtP.fswParams.constants.convert.DEG2RAD * rtp_min_angle_deg) >=
      localP->Switch_Threshold) {
    rty_non_parallel_0 = localP->Constant1_Value;
  } else {
    rty_non_parallel_0 = localP->Constant_Value;
  }

  /* End of Switch: '<S126>/Switch' */
  return rty_non_parallel_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

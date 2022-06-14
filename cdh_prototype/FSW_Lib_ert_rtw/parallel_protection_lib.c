/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_protection_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "parallel_protection_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for atomic system:
 *    '<S115>/parallel_protection_lib'
 *    '<S125>/parallel_protection_lib'
 *    '<S125>/parallel_protection_lib1'
 */
boolean_T parallel_protection_lib(const real_T rtu_vector_1[3], const real_T
  rtu_vector_2[3], real_T rtp_min_angle_deg)
{
  /* Switch: '<S126>/Switch' incorporates:
   *  Abs: '<S126>/Abs'
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
  return !(fabs(((rtu_vector_1[0] * rtu_vector_2[0] + rtu_vector_1[1] *
                  rtu_vector_2[1]) + rtu_vector_1[2] * rtu_vector_2[2]) / (sqrt
             ((rtu_vector_1[0] * rtu_vector_1[0] + rtu_vector_1[1] *
               rtu_vector_1[1]) + rtu_vector_1[2] * rtu_vector_1[2]) * sqrt
             ((rtu_vector_2[0] * rtu_vector_2[0] + rtu_vector_2[1] *
               rtu_vector_2[1]) + rtu_vector_2[2] * rtu_vector_2[2]))) - cos
           (0.017453292519943295 * rtp_min_angle_deg) >= 0.0);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

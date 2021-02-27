/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_protection_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:43:08 2021
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
 *    '<S16>/parallel_protection_lib'
 *    '<S23>/parallel_protection_lib'
 *    '<S23>/parallel_protection_lib1'
 */
boolean_T parallel_protection_lib(const real_T rtu_vector_1[3], const real_T
  rtu_vector_2[3], real_T rtp_min_angle_deg)
{
  /* Switch: '<S24>/Switch' incorporates:
   *  Abs: '<S24>/Abs'
   *  Constant: '<S24>/min_angle_deg'
   *  DotProduct: '<S24>/Dot Product'
   *  DotProduct: '<S24>/Dot Product1'
   *  DotProduct: '<S24>/Dot Product2'
   *  Gain: '<S24>/DEG2RAD'
   *  Product: '<S24>/Divide'
   *  Product: '<S24>/Multiply'
   *  Sqrt: '<S24>/Sqrt'
   *  Sqrt: '<S24>/Sqrt1'
   *  Sum: '<S24>/Sum'
   *  Trigonometry: '<S24>/Cos'
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

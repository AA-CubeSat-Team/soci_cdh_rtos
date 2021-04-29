/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_protection_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
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
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for atomic system:
 *    '<S106>/parallel_protection_lib'
 *    '<S113>/parallel_protection_lib'
 *    '<S113>/parallel_protection_lib1'
 */
boolean_T parallel_protection_lib(const real_T rtu_vector_1[3], const real_T
  rtu_vector_2[3], real_T rtp_min_angle_deg)
{
  /* Switch: '<S114>/Switch' incorporates:
   *  Abs: '<S114>/Abs'
   *  Constant: '<S114>/min_angle_deg'
   *  DotProduct: '<S114>/Dot Product'
   *  DotProduct: '<S114>/Dot Product1'
   *  DotProduct: '<S114>/Dot Product2'
   *  Gain: '<S114>/DEG2RAD'
   *  Product: '<S114>/Divide'
   *  Product: '<S114>/Multiply'
   *  Sqrt: '<S114>/Sqrt'
   *  Sqrt: '<S114>/Sqrt1'
   *  Sum: '<S114>/Sum'
   *  Trigonometry: '<S114>/Cos'
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

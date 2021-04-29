/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twonorm.c
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

#include "twonorm.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for atomic system:
 *    '<S19>/twonorm1'
 *    '<S19>/twonorm2'
 *    '<S19>/twonorm3'
 *    '<S48>/twonorm'
 *    '<S47>/twonorm'
 *    '<S49>/twonorm'
 *    '<S18>/twonorm1'
 *    '<S18>/twonorm2'
 *    '<S18>/twonorm3'
 *    '<S63>/twonorm1'
 *    ...
 */
real_T twonorm(const real_T rtu_vec[3])
{
  /* Sqrt: '<S44>/Sqrt' incorporates:
   *  DotProduct: '<S44>/Dot Product'
   */
  return sqrt((rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]) + rtu_vec[2] *
              rtu_vec[2]);
}

/*
 * Output and update for atomic system:
 *    '<S267>/twonorm'
 *    '<S268>/twonorm'
 */
real_T twonorm_h(const real_T rtu_vec[2])
{
  /* Sqrt: '<S313>/Sqrt' incorporates:
   *  DotProduct: '<S313>/Dot Product'
   */
  return sqrt(rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]);
}

/* Output and update for atomic system: '<S355>/twonorm' */
real_T twonorm_o(const real_T rtu_vec[4])
{
  /* Sqrt: '<S359>/Sqrt' incorporates:
   *  DotProduct: '<S359>/Dot Product'
   */
  return sqrt(((rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]) + rtu_vec[2] *
               rtu_vec[2]) + rtu_vec[3] * rtu_vec[3]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

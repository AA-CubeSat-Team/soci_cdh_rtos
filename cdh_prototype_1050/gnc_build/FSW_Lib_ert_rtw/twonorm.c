/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twonorm.c
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

#include "twonorm.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for atomic system:
 *    '<S175>/twonorm'
 *    '<S176>/twonorm'
 */
real_T twonorm(const real_T rtu_vec[2])
{
  /* Sqrt: '<S221>/Sqrt' incorporates:
   *  DotProduct: '<S221>/Dot Product'
   */
  return sqrt(rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]);
}

/* Output and update for atomic system: '<S263>/twonorm' */
real_T twonorm_o(const real_T rtu_vec[4])
{
  /* Sqrt: '<S267>/Sqrt' incorporates:
   *  DotProduct: '<S267>/Dot Product'
   */
  return sqrt(((rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]) + rtu_vec[2] *
               rtu_vec[2]) + rtu_vec[3] * rtu_vec[3]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twonorm.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "twonorm.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Output and update for atomic system: '<S17>/twonorm' */
real_T twonorm(const real_T rtu_vec[2])
{
  /* Sqrt: '<S41>/Sqrt' incorporates:
   *  DotProduct: '<S41>/Dot Product'
   */
  return sqrt(rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]);
}

/*
 * Output and update for atomic system:
 *    '<S99>/twonorm'
 *    '<S107>/twonorm'
 *    '<S143>/twonorm1'
 *    '<S9>/twonorm'
 */
real_T twonorm_m(const real_T rtu_vec[3])
{
  /* Sqrt: '<S104>/Sqrt' incorporates:
   *  DotProduct: '<S104>/Dot Product'
   */
  return sqrt((rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]) + rtu_vec[2] *
              rtu_vec[2]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

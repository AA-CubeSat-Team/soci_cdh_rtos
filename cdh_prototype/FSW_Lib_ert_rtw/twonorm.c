/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twonorm.c
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

#include "twonorm.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for atomic system:
 *    '<S26>/twonorm'
 *    '<S26>/twonorm1'
 *    '<S26>/twonorm2'
 *    '<S53>/twonorm'
 *    '<S52>/twonorm'
 *    '<S54>/twonorm'
 *    '<S25>/twonorm1'
 *    '<S25>/twonorm2'
 *    '<S25>/twonorm3'
 *    '<S68>/twonorm'
 *    ...
 */
real_T twonorm(const real_T rtu_vec[3])
{
  /* Sqrt: '<S49>/Sqrt' incorporates:
   *  DotProduct: '<S49>/Dot Product'
   */
  return sqrt((rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]) + rtu_vec[2] *
              rtu_vec[2]);
}

/*
 * Output and update for atomic system:
 *    '<S293>/twonorm'
 *    '<S294>/twonorm'
 */
real_T twonorm_f(const real_T rtu_vec[2])
{
  /* Sqrt: '<S299>/Sqrt' incorporates:
   *  DotProduct: '<S299>/Dot Product'
   */
  return sqrt(rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twonorm.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
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
 *    '<S25>/twonorm'
 *    '<S25>/twonorm1'
 *    '<S25>/twonorm2'
 *    '<S52>/twonorm'
 *    '<S51>/twonorm'
 *    '<S53>/twonorm'
 *    '<S24>/twonorm1'
 *    '<S24>/twonorm2'
 *    '<S24>/twonorm3'
 *    '<S67>/twonorm'
 *    ...
 */
real_T twonorm(const real_T rtu_vec[3])
{
  /* Sqrt: '<S48>/Sqrt' incorporates:
   *  DotProduct: '<S48>/Dot Product'
   */
  return sqrt((rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]) + rtu_vec[2] *
              rtu_vec[2]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

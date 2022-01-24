/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: twonorm.c
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

#include "twonorm.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

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
 *    '<S294>/twonorm'
 *    '<S295>/twonorm'
 */
real_T twonorm_f(const real_T rtu_vec[2])
{
  /* Sqrt: '<S340>/Sqrt' incorporates:
   *  DotProduct: '<S340>/Dot Product'
   */
  return sqrt(rtu_vec[0] * rtu_vec[0] + rtu_vec[1] * rtu_vec[1]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

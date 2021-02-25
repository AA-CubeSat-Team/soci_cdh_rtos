/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_err_lib.c
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

#include "quat_err_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Output and update for atomic system: '<S5>/quat_err_lib' */
void quat_err_lib(const real_T rtu_quat_cmd[4], const real_T rtu_quat_sc[4],
                  real_T rty_quat_err[4])
{
  real_T rtb_TmpSignalConversionAtquat_j[4];

  /* SignalConversion: '<S125>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
   *  Product: '<S155>/Product'
   *  Product: '<S155>/Product1'
   *  Product: '<S155>/Product2'
   *  Product: '<S155>/Product3'
   *  Product: '<S156>/Product'
   *  Product: '<S156>/Product1'
   *  Product: '<S156>/Product2'
   *  Product: '<S156>/Product3'
   *  Product: '<S157>/Product'
   *  Product: '<S157>/Product1'
   *  Product: '<S157>/Product2'
   *  Product: '<S157>/Product3'
   *  Product: '<S158>/Product'
   *  Product: '<S158>/Product1'
   *  Product: '<S158>/Product2'
   *  Product: '<S158>/Product3'
   *  Sum: '<S155>/Sum'
   *  Sum: '<S156>/Sum'
   *  Sum: '<S157>/Sum'
   *  Sum: '<S158>/Sum'
   *  UnaryMinus: '<S152>/Unary Minus'
   *  UnaryMinus: '<S152>/Unary Minus1'
   *  UnaryMinus: '<S152>/Unary Minus2'
   */
  rtb_TmpSignalConversionAtquat_j[0] = ((rtu_quat_cmd[0] * rtu_quat_sc[0] -
    -rtu_quat_cmd[1] * rtu_quat_sc[1]) - -rtu_quat_cmd[2] * rtu_quat_sc[2]) -
    -rtu_quat_cmd[3] * rtu_quat_sc[3];
  rtb_TmpSignalConversionAtquat_j[1] = ((rtu_quat_cmd[0] * rtu_quat_sc[1] +
    -rtu_quat_cmd[1] * rtu_quat_sc[0]) + -rtu_quat_cmd[2] * rtu_quat_sc[3]) -
    -rtu_quat_cmd[3] * rtu_quat_sc[2];
  rtb_TmpSignalConversionAtquat_j[2] = ((rtu_quat_cmd[0] * rtu_quat_sc[2] -
    -rtu_quat_cmd[1] * rtu_quat_sc[3]) + -rtu_quat_cmd[2] * rtu_quat_sc[0]) +
    -rtu_quat_cmd[3] * rtu_quat_sc[1];
  rtb_TmpSignalConversionAtquat_j[3] = ((rtu_quat_cmd[0] * rtu_quat_sc[3] +
    -rtu_quat_cmd[1] * rtu_quat_sc[2]) - -rtu_quat_cmd[2] * rtu_quat_sc[1]) +
    -rtu_quat_cmd[3] * rtu_quat_sc[0];

  /* Outputs for Atomic SubSystem: '<S125>/quat_rectify_lib' */
  quat_rectify_lib(rtb_TmpSignalConversionAtquat_j, rty_quat_err);

  /* End of Outputs for SubSystem: '<S125>/quat_rectify_lib' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

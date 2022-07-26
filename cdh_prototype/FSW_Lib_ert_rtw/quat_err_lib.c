/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_err_lib.c
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

#include "quat_err_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Output and update for atomic system: '<S6>/quat_err_lib' */
void quat_err_lib(const real_T rtu_quat_cmd[4], const real_T rtu_quat_sc[4],
                  real_T rty_quat_err[4])
{
  real_T rtb_TmpSignalConversionAtquat_r[4];

  /* SignalConversion generated from: '<S90>/quat_rectify_lib' incorporates:
   *  Product: '<S129>/Product'
   *  Product: '<S129>/Product1'
   *  Product: '<S129>/Product2'
   *  Product: '<S129>/Product3'
   *  Product: '<S130>/Product'
   *  Product: '<S130>/Product1'
   *  Product: '<S130>/Product2'
   *  Product: '<S130>/Product3'
   *  Product: '<S131>/Product'
   *  Product: '<S131>/Product1'
   *  Product: '<S131>/Product2'
   *  Product: '<S131>/Product3'
   *  Product: '<S132>/Product'
   *  Product: '<S132>/Product1'
   *  Product: '<S132>/Product2'
   *  Product: '<S132>/Product3'
   *  Sum: '<S129>/Sum'
   *  Sum: '<S130>/Sum'
   *  Sum: '<S131>/Sum'
   *  Sum: '<S132>/Sum'
   *  UnaryMinus: '<S126>/Unary Minus'
   *  UnaryMinus: '<S126>/Unary Minus1'
   *  UnaryMinus: '<S126>/Unary Minus2'
   */
  rtb_TmpSignalConversionAtquat_r[0] = ((rtu_quat_cmd[0] * rtu_quat_sc[0] -
    -rtu_quat_cmd[1] * rtu_quat_sc[1]) - -rtu_quat_cmd[2] * rtu_quat_sc[2]) -
    -rtu_quat_cmd[3] * rtu_quat_sc[3];
  rtb_TmpSignalConversionAtquat_r[1] = ((rtu_quat_cmd[0] * rtu_quat_sc[1] +
    -rtu_quat_cmd[1] * rtu_quat_sc[0]) + -rtu_quat_cmd[2] * rtu_quat_sc[3]) -
    -rtu_quat_cmd[3] * rtu_quat_sc[2];
  rtb_TmpSignalConversionAtquat_r[2] = ((rtu_quat_cmd[0] * rtu_quat_sc[2] -
    -rtu_quat_cmd[1] * rtu_quat_sc[3]) + -rtu_quat_cmd[2] * rtu_quat_sc[0]) +
    -rtu_quat_cmd[3] * rtu_quat_sc[1];
  rtb_TmpSignalConversionAtquat_r[3] = ((rtu_quat_cmd[0] * rtu_quat_sc[3] +
    -rtu_quat_cmd[1] * rtu_quat_sc[2]) - -rtu_quat_cmd[2] * rtu_quat_sc[1]) +
    -rtu_quat_cmd[3] * rtu_quat_sc[0];

  /* Outputs for Atomic SubSystem: '<S90>/quat_rectify_lib' */
  quat_rectify_lib(rtb_TmpSignalConversionAtquat_r, rty_quat_err);

  /* End of Outputs for SubSystem: '<S90>/quat_rectify_lib' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

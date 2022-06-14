/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_err_lib.c
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

#include "quat_err_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Output and update for atomic system: '<S5>/quat_err_lib' */
void quat_err_lib(const real_T rtu_quat_cmd[4], const real_T rtu_quat_sc[4],
                  real_T rty_quat_err[4])
{
  real_T rtb_TmpSignalConversionAtquat_b[4];

  /* SignalConversion generated from: '<S231>/quat_rectify_lib' incorporates:
   *  Product: '<S270>/Product'
   *  Product: '<S270>/Product1'
   *  Product: '<S270>/Product2'
   *  Product: '<S270>/Product3'
   *  Product: '<S271>/Product'
   *  Product: '<S271>/Product1'
   *  Product: '<S271>/Product2'
   *  Product: '<S271>/Product3'
   *  Product: '<S272>/Product'
   *  Product: '<S272>/Product1'
   *  Product: '<S272>/Product2'
   *  Product: '<S272>/Product3'
   *  Product: '<S273>/Product'
   *  Product: '<S273>/Product1'
   *  Product: '<S273>/Product2'
   *  Product: '<S273>/Product3'
   *  Sum: '<S270>/Sum'
   *  Sum: '<S271>/Sum'
   *  Sum: '<S272>/Sum'
   *  Sum: '<S273>/Sum'
   *  UnaryMinus: '<S267>/Unary Minus'
   *  UnaryMinus: '<S267>/Unary Minus1'
   *  UnaryMinus: '<S267>/Unary Minus2'
   */
  rtb_TmpSignalConversionAtquat_b[0] = ((rtu_quat_cmd[0] * rtu_quat_sc[0] -
    -rtu_quat_cmd[1] * rtu_quat_sc[1]) - -rtu_quat_cmd[2] * rtu_quat_sc[2]) -
    -rtu_quat_cmd[3] * rtu_quat_sc[3];
  rtb_TmpSignalConversionAtquat_b[1] = ((rtu_quat_cmd[0] * rtu_quat_sc[1] +
    -rtu_quat_cmd[1] * rtu_quat_sc[0]) + -rtu_quat_cmd[2] * rtu_quat_sc[3]) -
    -rtu_quat_cmd[3] * rtu_quat_sc[2];
  rtb_TmpSignalConversionAtquat_b[2] = ((rtu_quat_cmd[0] * rtu_quat_sc[2] -
    -rtu_quat_cmd[1] * rtu_quat_sc[3]) + -rtu_quat_cmd[2] * rtu_quat_sc[0]) +
    -rtu_quat_cmd[3] * rtu_quat_sc[1];
  rtb_TmpSignalConversionAtquat_b[3] = ((rtu_quat_cmd[0] * rtu_quat_sc[3] +
    -rtu_quat_cmd[1] * rtu_quat_sc[2]) - -rtu_quat_cmd[2] * rtu_quat_sc[1]) +
    -rtu_quat_cmd[3] * rtu_quat_sc[0];

  /* Outputs for Atomic SubSystem: '<S231>/quat_rectify_lib' */
  quat_rectify_lib(rtb_TmpSignalConversionAtquat_b, rty_quat_err);

  /* End of Outputs for SubSystem: '<S231>/quat_rectify_lib' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

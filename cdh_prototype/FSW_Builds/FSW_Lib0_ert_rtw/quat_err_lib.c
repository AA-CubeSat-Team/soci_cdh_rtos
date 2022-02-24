/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_err_lib.c
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

#include "quat_err_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* Output and update for atomic system: '<S5>/quat_err_lib' */
void quat_err_lib(const real_T rtu_quat_cmd[4], const real_T rtu_quat_sc[4],
                  real_T rty_quat_err[4])
{
  real_T rtb_TmpSignalConversionAtquat_g[4];

  /* SignalConversion: '<S230>/TmpSignal ConversionAtquat_rectify_libInport1' incorporates:
   *  Product: '<S269>/Product'
   *  Product: '<S269>/Product1'
   *  Product: '<S269>/Product2'
   *  Product: '<S269>/Product3'
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
   *  Sum: '<S269>/Sum'
   *  Sum: '<S270>/Sum'
   *  Sum: '<S271>/Sum'
   *  Sum: '<S272>/Sum'
   *  UnaryMinus: '<S266>/Unary Minus'
   *  UnaryMinus: '<S266>/Unary Minus1'
   *  UnaryMinus: '<S266>/Unary Minus2'
   */
  rtb_TmpSignalConversionAtquat_g[0] = ((rtu_quat_cmd[0] * rtu_quat_sc[0] -
    -rtu_quat_cmd[1] * rtu_quat_sc[1]) - -rtu_quat_cmd[2] * rtu_quat_sc[2]) -
    -rtu_quat_cmd[3] * rtu_quat_sc[3];
  rtb_TmpSignalConversionAtquat_g[1] = ((rtu_quat_cmd[0] * rtu_quat_sc[1] +
    -rtu_quat_cmd[1] * rtu_quat_sc[0]) + -rtu_quat_cmd[2] * rtu_quat_sc[3]) -
    -rtu_quat_cmd[3] * rtu_quat_sc[2];
  rtb_TmpSignalConversionAtquat_g[2] = ((rtu_quat_cmd[0] * rtu_quat_sc[2] -
    -rtu_quat_cmd[1] * rtu_quat_sc[3]) + -rtu_quat_cmd[2] * rtu_quat_sc[0]) +
    -rtu_quat_cmd[3] * rtu_quat_sc[1];
  rtb_TmpSignalConversionAtquat_g[3] = ((rtu_quat_cmd[0] * rtu_quat_sc[3] +
    -rtu_quat_cmd[1] * rtu_quat_sc[2]) - -rtu_quat_cmd[2] * rtu_quat_sc[1]) +
    -rtu_quat_cmd[3] * rtu_quat_sc[0];

  /* Outputs for Atomic SubSystem: '<S230>/quat_rectify_lib' */
  quat_rectify_lib(rtb_TmpSignalConversionAtquat_g, rty_quat_err);

  /* End of Outputs for SubSystem: '<S230>/quat_rectify_lib' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

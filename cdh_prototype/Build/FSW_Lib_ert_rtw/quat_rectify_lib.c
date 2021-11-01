/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_rectify_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Oct 26 16:29:45 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "quat_rectify_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for atomic system:
 *    '<S125>/quat_rectify_lib'
 *    '<S124>/quat_rectify_lib'
 *    '<S231>/quat_rectify_lib'
 *    '<S10>/quat_rectify_lib'
 */
void quat_rectify_lib(const real_T rtu_q[4], real_T rty_rectq[4])
{
  int32_T rtb_Switch_bf;

  /* Switch: '<S181>/Switch' incorporates:
   *  Constant: '<S181>/Constant'
   *  Constant: '<S181>/Constant1'
   */
  if (rtu_q[0] >= 0.0) {
    rtb_Switch_bf = 1;
  } else {
    rtb_Switch_bf = -1;
  }

  /* End of Switch: '<S181>/Switch' */

  /* Product: '<S181>/Multiply' */
  rty_rectq[0] = (real_T)rtb_Switch_bf * rtu_q[0];
  rty_rectq[1] = (real_T)rtb_Switch_bf * rtu_q[1];
  rty_rectq[2] = (real_T)rtb_Switch_bf * rtu_q[2];
  rty_rectq[3] = (real_T)rtb_Switch_bf * rtu_q[3];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

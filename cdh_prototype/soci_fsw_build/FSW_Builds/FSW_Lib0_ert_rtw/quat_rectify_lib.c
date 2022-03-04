/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_rectify_lib.c
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

#include "quat_rectify_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for atomic system:
 *    '<S124>/quat_rectify_lib'
 *    '<S123>/quat_rectify_lib'
 *    '<S230>/quat_rectify_lib'
 *    '<S9>/quat_rectify_lib'
 */
void quat_rectify_lib(const real_T rtu_q[4], real_T rty_rectq[4])
{
  int32_T rtb_Switch_j;

  /* Switch: '<S180>/Switch' incorporates:
   *  Constant: '<S180>/Constant'
   *  Constant: '<S180>/Constant1'
   */
  if (rtu_q[0] >= 0.0) {
    rtb_Switch_j = 1;
  } else {
    rtb_Switch_j = -1;
  }

  /* End of Switch: '<S180>/Switch' */

  /* Product: '<S180>/Multiply' */
  rty_rectq[0] = (real_T)rtb_Switch_j * rtu_q[0];
  rty_rectq[1] = (real_T)rtb_Switch_j * rtu_q[1];
  rty_rectq[2] = (real_T)rtb_Switch_j * rtu_q[2];
  rty_rectq[3] = (real_T)rtb_Switch_j * rtu_q[3];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

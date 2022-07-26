/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: quat_rectify_lib.c
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

#include "quat_rectify_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for atomic system:
 *    '<S90>/quat_rectify_lib'
 *    '<S11>/quat_rectify_lib'
 */
void quat_rectify_lib(const real_T rtu_q[4], real_T rty_rectq[4])
{
  int32_T rtb_Switch_bl;

  /* Switch: '<S128>/Switch' incorporates:
   *  Constant: '<S128>/Constant'
   *  Constant: '<S128>/Constant1'
   */
  if (rtu_q[0] >= 0.0) {
    rtb_Switch_bl = 1;
  } else {
    rtb_Switch_bl = -1;
  }

  /* End of Switch: '<S128>/Switch' */

  /* Product: '<S128>/Multiply' */
  rty_rectq[0] = (real_T)rtb_Switch_bl * rtu_q[0];
  rty_rectq[1] = (real_T)rtb_Switch_bl * rtu_q[1];
  rty_rectq[2] = (real_T)rtb_Switch_bl * rtu_q[2];
  rty_rectq[3] = (real_T)rtb_Switch_bl * rtu_q[3];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

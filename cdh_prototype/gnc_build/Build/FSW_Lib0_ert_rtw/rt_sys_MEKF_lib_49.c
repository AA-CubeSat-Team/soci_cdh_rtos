/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_49.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "rt_sys_MEKF_lib_49.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for action system:
 *    '<S176>/If Warning//Error'
 *    '<S373>/If Warning//Error'
 */
void IfWarningError(const real_T rtu_dcm[9], real_T rtp_action, real_T
                    rtp_tolerance)
{
  boolean_T tmp;
  boolean_T rtb_Compare_l[9];
  real_T rtu_dcm_0[9];
  int32_T i;
  int32_T i_0;

  /* Bias: '<S203>/Bias1' incorporates:
   *  Math: '<S203>/Math Function'
   *  Product: '<S203>/Product'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_dcm_0[i + 3 * i_0] = ((rtu_dcm[3 * i + 1] * rtu_dcm[3 * i_0 + 1] +
        rtu_dcm[3 * i] * rtu_dcm[3 * i_0]) + rtu_dcm[3 * i + 2] * rtu_dcm[3 *
        i_0 + 2]) + rtCP_Bias1_Bias[3 * i_0 + i];
    }
  }

  for (i = 0; i < 9; i++) {
    /* RelationalOperator: '<S209>/Compare' incorporates:
     *  Abs: '<S203>/Abs2'
     *  Bias: '<S203>/Bias1'
     *  Constant: '<S209>/Constant'
     */
    rtb_Compare_l[i] = (fabs(rtu_dcm_0[i]) > rtp_tolerance);
  }

  /* Logic: '<S203>/Logical Operator1' */
  tmp = rtb_Compare_l[0];
  for (i = 0; i < 8; i++) {
    tmp = (tmp || rtb_Compare_l[i + 1]);
  }

  /* If: '<S200>/If' incorporates:
   *  Abs: '<S204>/Abs1'
   *  Bias: '<S204>/Bias'
   *  Constant: '<S211>/Constant'
   *  Logic: '<S203>/Logical Operator1'
   *  Product: '<S210>/Product'
   *  Product: '<S210>/Product1'
   *  Product: '<S210>/Product2'
   *  Product: '<S210>/Product3'
   *  Product: '<S210>/Product4'
   *  Product: '<S210>/Product5'
   *  RelationalOperator: '<S211>/Compare'
   *  Sum: '<S210>/Sum'
   */
  if (fabs((((((rtu_dcm[0] * rtu_dcm[4] * rtu_dcm[8] - rtu_dcm[0] * rtu_dcm[5] *
                rtu_dcm[7]) - rtu_dcm[1] * rtu_dcm[3] * rtu_dcm[8]) + rtu_dcm[2]
              * rtu_dcm[3] * rtu_dcm[7]) + rtu_dcm[1] * rtu_dcm[5] * rtu_dcm[6])
            - rtu_dcm[2] * rtu_dcm[4] * rtu_dcm[6]) + -1.0) > rtp_tolerance) {
    /* Outputs for IfAction SubSystem: '<S200>/If Not Proper' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    /* If: '<S202>/If' incorporates:
     *  Constant: '<S202>/Constant'
     */
    if (rtp_action == 2.0) {
      /* Outputs for IfAction SubSystem: '<S202>/Warning' incorporates:
       *  ActionPort: '<S208>/Action Port'
       */
      /* Assertion: '<S208>/Assertion' incorporates:
       *  Constant: '<S202>/Constant1'
       */
      utAssert(false);

      /* End of Outputs for SubSystem: '<S202>/Warning' */
    } else {
      if (rtp_action == 3.0) {
        /* Outputs for IfAction SubSystem: '<S202>/Error' incorporates:
         *  ActionPort: '<S207>/Action Port'
         */
        /* Assertion: '<S207>/Assertion' incorporates:
         *  Constant: '<S202>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S202>/Error' */
      }
    }

    /* End of If: '<S202>/If' */
    /* End of Outputs for SubSystem: '<S200>/If Not Proper' */
  } else {
    if (tmp) {
      /* Outputs for IfAction SubSystem: '<S200>/Else If Not Orthogonal' incorporates:
       *  ActionPort: '<S201>/Action Port'
       */
      /* If: '<S201>/If' incorporates:
       *  Constant: '<S201>/Constant'
       */
      if (rtp_action == 2.0) {
        /* Outputs for IfAction SubSystem: '<S201>/Warning' incorporates:
         *  ActionPort: '<S206>/Action Port'
         */
        /* Assertion: '<S206>/Assertion' incorporates:
         *  Constant: '<S201>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S201>/Warning' */
      } else {
        if (rtp_action == 3.0) {
          /* Outputs for IfAction SubSystem: '<S201>/Error' incorporates:
           *  ActionPort: '<S205>/Action Port'
           */
          /* Assertion: '<S205>/Assertion' incorporates:
           *  Constant: '<S201>/Constant1'
           */
          utAssert(false);

          /* End of Outputs for SubSystem: '<S201>/Error' */
        }
      }

      /* End of If: '<S201>/If' */
      /* End of Outputs for SubSystem: '<S200>/Else If Not Orthogonal' */
    }
  }

  /* End of If: '<S200>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

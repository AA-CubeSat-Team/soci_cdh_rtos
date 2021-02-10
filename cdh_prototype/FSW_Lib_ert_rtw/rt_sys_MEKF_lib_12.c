/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_12.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep  9 13:53:00 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_private.h>
#include <gnc_build/FSW_Lib_ert_rtw/rt_sys_MEKF_lib_12.h>

/*
 * Output and update for action system:
 *    '<S69>/If Warning//Error'
 *    '<S336>/If Warning//Error'
 */
void IfWarningError(const real_T rtu_dcm[9], real_T rtp_action, real_T
                    rtp_tolerance)
{
  boolean_T tmp;
  boolean_T rtb_Compare_j3[9];
  real_T rtu_dcm_0[9];
  int32_T i;
  int32_T i_0;

  /* Bias: '<S96>/Bias1' incorporates:
   *  Math: '<S96>/Math Function'
   *  Product: '<S96>/Product'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_dcm_0[i + 3 * i_0] = ((rtu_dcm[3 * i + 1] * rtu_dcm[3 * i_0 + 1] +
        rtu_dcm[3 * i] * rtu_dcm[3 * i_0]) + rtu_dcm[3 * i + 2] * rtu_dcm[3 *
        i_0 + 2]) + rtConstP.pooled6[3 * i_0 + i];
    }
  }

  for (i = 0; i < 9; i++) {
    /* RelationalOperator: '<S102>/Compare' incorporates:
     *  Abs: '<S96>/Abs2'
     *  Bias: '<S96>/Bias1'
     *  Constant: '<S102>/Constant'
     */
    rtb_Compare_j3[i] = (fabs(rtu_dcm_0[i]) > rtp_tolerance);
  }

  /* Logic: '<S96>/Logical Operator1' */
  tmp = rtb_Compare_j3[0];
  for (i = 0; i < 8; i++) {
    tmp = (tmp || rtb_Compare_j3[i + 1]);
  }

  /* If: '<S93>/If' incorporates:
   *  Abs: '<S97>/Abs1'
   *  Bias: '<S97>/Bias'
   *  Constant: '<S104>/Constant'
   *  Logic: '<S96>/Logical Operator1'
   *  Product: '<S103>/Product'
   *  Product: '<S103>/Product1'
   *  Product: '<S103>/Product2'
   *  Product: '<S103>/Product3'
   *  Product: '<S103>/Product4'
   *  Product: '<S103>/Product5'
   *  RelationalOperator: '<S104>/Compare'
   *  Sum: '<S103>/Sum'
   */
  if (fabs((((((rtu_dcm[0] * rtu_dcm[4] * rtu_dcm[8] - rtu_dcm[0] * rtu_dcm[5] *
                rtu_dcm[7]) - rtu_dcm[1] * rtu_dcm[3] * rtu_dcm[8]) + rtu_dcm[2]
              * rtu_dcm[3] * rtu_dcm[7]) + rtu_dcm[1] * rtu_dcm[5] * rtu_dcm[6])
            - rtu_dcm[2] * rtu_dcm[4] * rtu_dcm[6]) + -1.0) > rtp_tolerance) {
    /* Outputs for IfAction SubSystem: '<S93>/If Not Proper' incorporates:
     *  ActionPort: '<S95>/Action Port'
     */
    /* If: '<S95>/If' incorporates:
     *  Constant: '<S95>/Constant'
     */
    if (rtp_action == 2.0) {
      /* Outputs for IfAction SubSystem: '<S95>/Warning' incorporates:
       *  ActionPort: '<S101>/Action Port'
       */
      /* Assertion: '<S101>/Assertion' incorporates:
       *  Constant: '<S95>/Constant1'
       */
      utAssert(false);

      /* End of Outputs for SubSystem: '<S95>/Warning' */
    } else {
      if (rtp_action == 3.0) {
        /* Outputs for IfAction SubSystem: '<S95>/Error' incorporates:
         *  ActionPort: '<S100>/Action Port'
         */
        /* Assertion: '<S100>/Assertion' incorporates:
         *  Constant: '<S95>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S95>/Error' */
      }
    }

    /* End of If: '<S95>/If' */
    /* End of Outputs for SubSystem: '<S93>/If Not Proper' */
  } else {
    if (tmp) {
      /* Outputs for IfAction SubSystem: '<S93>/Else If Not Orthogonal' incorporates:
       *  ActionPort: '<S94>/Action Port'
       */
      /* If: '<S94>/If' incorporates:
       *  Constant: '<S94>/Constant'
       */
      if (rtp_action == 2.0) {
        /* Outputs for IfAction SubSystem: '<S94>/Warning' incorporates:
         *  ActionPort: '<S99>/Action Port'
         */
        /* Assertion: '<S99>/Assertion' incorporates:
         *  Constant: '<S94>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S94>/Warning' */
      } else {
        if (rtp_action == 3.0) {
          /* Outputs for IfAction SubSystem: '<S94>/Error' incorporates:
           *  ActionPort: '<S98>/Action Port'
           */
          /* Assertion: '<S98>/Assertion' incorporates:
           *  Constant: '<S94>/Constant1'
           */
          utAssert(false);

          /* End of Outputs for SubSystem: '<S94>/Error' */
        }
      }

      /* End of If: '<S94>/If' */
      /* End of Outputs for SubSystem: '<S93>/Else If Not Orthogonal' */
    }
  }

  /* End of If: '<S93>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

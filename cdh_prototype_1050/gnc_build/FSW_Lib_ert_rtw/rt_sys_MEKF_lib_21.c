/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_21.c
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

#include "rt_sys_MEKF_lib_21.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S86>/If Warning//Error'
 *    '<S281>/If Warning//Error'
 */
void IfWarningError(const real_T rtu_dcm[9], real_T rtp_action, real_T
                    rtp_tolerance)
{
  boolean_T tmp;
  boolean_T rtb_Compare_l[9];
  real_T rtu_dcm_0[9];
  int32_T i;
  int32_T i_0;

  /* Bias: '<S113>/Bias1' incorporates:
   *  Math: '<S113>/Math Function'
   *  Product: '<S113>/Product'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_dcm_0[i + 3 * i_0] = ((rtu_dcm[3 * i + 1] * rtu_dcm[3 * i_0 + 1] +
        rtu_dcm[3 * i] * rtu_dcm[3 * i_0]) + rtu_dcm[3 * i + 2] * rtu_dcm[3 *
        i_0 + 2]) + rtCP_Bias1_Bias[3 * i_0 + i];
    }
  }

  for (i = 0; i < 9; i++) {
    /* RelationalOperator: '<S119>/Compare' incorporates:
     *  Abs: '<S113>/Abs2'
     *  Bias: '<S113>/Bias1'
     *  Constant: '<S119>/Constant'
     */
    rtb_Compare_l[i] = (fabs(rtu_dcm_0[i]) > rtp_tolerance);
  }

  /* Logic: '<S113>/Logical Operator1' */
  tmp = rtb_Compare_l[0];
  for (i = 0; i < 8; i++) {
    tmp = (tmp || rtb_Compare_l[i + 1]);
  }

  /* If: '<S110>/If' incorporates:
   *  Abs: '<S114>/Abs1'
   *  Bias: '<S114>/Bias'
   *  Constant: '<S121>/Constant'
   *  Logic: '<S113>/Logical Operator1'
   *  Product: '<S120>/Product'
   *  Product: '<S120>/Product1'
   *  Product: '<S120>/Product2'
   *  Product: '<S120>/Product3'
   *  Product: '<S120>/Product4'
   *  Product: '<S120>/Product5'
   *  RelationalOperator: '<S121>/Compare'
   *  Sum: '<S120>/Sum'
   */
  if (fabs((((((rtu_dcm[0] * rtu_dcm[4] * rtu_dcm[8] - rtu_dcm[0] * rtu_dcm[5] *
                rtu_dcm[7]) - rtu_dcm[1] * rtu_dcm[3] * rtu_dcm[8]) + rtu_dcm[2]
              * rtu_dcm[3] * rtu_dcm[7]) + rtu_dcm[1] * rtu_dcm[5] * rtu_dcm[6])
            - rtu_dcm[2] * rtu_dcm[4] * rtu_dcm[6]) + -1.0) > rtp_tolerance) {
    /* Outputs for IfAction SubSystem: '<S110>/If Not Proper' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    /* If: '<S112>/If' incorporates:
     *  Constant: '<S112>/Constant'
     */
    if (rtp_action == 2.0) {
      /* Outputs for IfAction SubSystem: '<S112>/Warning' incorporates:
       *  ActionPort: '<S118>/Action Port'
       */
      /* Assertion: '<S118>/Assertion' incorporates:
       *  Constant: '<S112>/Constant1'
       */
      utAssert(false);

      /* End of Outputs for SubSystem: '<S112>/Warning' */
    } else {
      if (rtp_action == 3.0) {
        /* Outputs for IfAction SubSystem: '<S112>/Error' incorporates:
         *  ActionPort: '<S117>/Action Port'
         */
        /* Assertion: '<S117>/Assertion' incorporates:
         *  Constant: '<S112>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S112>/Error' */
      }
    }

    /* End of If: '<S112>/If' */
    /* End of Outputs for SubSystem: '<S110>/If Not Proper' */
  } else {
    if (tmp) {
      /* Outputs for IfAction SubSystem: '<S110>/Else If Not Orthogonal' incorporates:
       *  ActionPort: '<S111>/Action Port'
       */
      /* If: '<S111>/If' incorporates:
       *  Constant: '<S111>/Constant'
       */
      if (rtp_action == 2.0) {
        /* Outputs for IfAction SubSystem: '<S111>/Warning' incorporates:
         *  ActionPort: '<S116>/Action Port'
         */
        /* Assertion: '<S116>/Assertion' incorporates:
         *  Constant: '<S111>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S111>/Warning' */
      } else {
        if (rtp_action == 3.0) {
          /* Outputs for IfAction SubSystem: '<S111>/Error' incorporates:
           *  ActionPort: '<S115>/Action Port'
           */
          /* Assertion: '<S115>/Assertion' incorporates:
           *  Constant: '<S111>/Constant1'
           */
          utAssert(false);

          /* End of Outputs for SubSystem: '<S111>/Error' */
        }
      }

      /* End of If: '<S111>/If' */
      /* End of Outputs for SubSystem: '<S110>/Else If Not Orthogonal' */
    }
  }

  /* End of If: '<S110>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

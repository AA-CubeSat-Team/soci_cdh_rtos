/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_48.c
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

#include "rt_sys_MEKF_lib_48.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for action system:
 *    '<S190>/If Warning//Error'
 *    '<S304>/If Warning//Error'
 */
void IfWarningError(const real_T rtu_dcm[9], real_T rtp_action, real_T
                    rtp_tolerance)
{
  boolean_T tmp;
  boolean_T rtb_Compare_or[9];
  real_T rtu_dcm_0[9];
  int32_T i;
  int32_T i_0;

  /* Bias: '<S217>/Bias1' incorporates:
   *  Math: '<S217>/Math Function'
   *  Product: '<S217>/Product'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_dcm_0[i + 3 * i_0] = ((rtu_dcm[3 * i + 1] * rtu_dcm[3 * i_0 + 1] +
        rtu_dcm[3 * i] * rtu_dcm[3 * i_0]) + rtu_dcm[3 * i + 2] * rtu_dcm[3 *
        i_0 + 2]) + rtCP_Bias1_Bias[3 * i_0 + i];
    }
  }

  for (i = 0; i < 9; i++) {
    /* RelationalOperator: '<S223>/Compare' incorporates:
     *  Abs: '<S217>/Abs2'
     *  Bias: '<S217>/Bias1'
     *  Constant: '<S223>/Constant'
     */
    rtb_Compare_or[i] = (fabs(rtu_dcm_0[i]) > rtp_tolerance);
  }

  /* Logic: '<S217>/Logical Operator1' */
  tmp = rtb_Compare_or[0];
  for (i = 0; i < 8; i++) {
    tmp = (tmp || rtb_Compare_or[i + 1]);
  }

  /* If: '<S214>/If' incorporates:
   *  Abs: '<S218>/Abs1'
   *  Bias: '<S218>/Bias'
   *  Constant: '<S225>/Constant'
   *  Logic: '<S217>/Logical Operator1'
   *  Product: '<S224>/Product'
   *  Product: '<S224>/Product1'
   *  Product: '<S224>/Product2'
   *  Product: '<S224>/Product3'
   *  Product: '<S224>/Product4'
   *  Product: '<S224>/Product5'
   *  RelationalOperator: '<S225>/Compare'
   *  Sum: '<S224>/Sum'
   */
  if (fabs((((((rtu_dcm[0] * rtu_dcm[4] * rtu_dcm[8] - rtu_dcm[0] * rtu_dcm[5] *
                rtu_dcm[7]) - rtu_dcm[1] * rtu_dcm[3] * rtu_dcm[8]) + rtu_dcm[2]
              * rtu_dcm[3] * rtu_dcm[7]) + rtu_dcm[1] * rtu_dcm[5] * rtu_dcm[6])
            - rtu_dcm[2] * rtu_dcm[4] * rtu_dcm[6]) + -1.0) > rtp_tolerance) {
    /* Outputs for IfAction SubSystem: '<S214>/If Not Proper' incorporates:
     *  ActionPort: '<S216>/Action Port'
     */
    /* If: '<S216>/If' incorporates:
     *  Constant: '<S216>/Constant'
     */
    if (rtp_action == 2.0) {
      /* Outputs for IfAction SubSystem: '<S216>/Warning' incorporates:
       *  ActionPort: '<S222>/Action Port'
       */
      /* Assertion: '<S222>/Assertion' incorporates:
       *  Constant: '<S216>/Constant1'
       */
      utAssert(false);

      /* End of Outputs for SubSystem: '<S216>/Warning' */
    } else {
      if (rtp_action == 3.0) {
        /* Outputs for IfAction SubSystem: '<S216>/Error' incorporates:
         *  ActionPort: '<S221>/Action Port'
         */
        /* Assertion: '<S221>/Assertion' incorporates:
         *  Constant: '<S216>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S216>/Error' */
      }
    }

    /* End of If: '<S216>/If' */
    /* End of Outputs for SubSystem: '<S214>/If Not Proper' */
  } else {
    if (tmp) {
      /* Outputs for IfAction SubSystem: '<S214>/Else If Not Orthogonal' incorporates:
       *  ActionPort: '<S215>/Action Port'
       */
      /* If: '<S215>/If' incorporates:
       *  Constant: '<S215>/Constant'
       */
      if (rtp_action == 2.0) {
        /* Outputs for IfAction SubSystem: '<S215>/Warning' incorporates:
         *  ActionPort: '<S220>/Action Port'
         */
        /* Assertion: '<S220>/Assertion' incorporates:
         *  Constant: '<S215>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S215>/Warning' */
      } else {
        if (rtp_action == 3.0) {
          /* Outputs for IfAction SubSystem: '<S215>/Error' incorporates:
           *  ActionPort: '<S219>/Action Port'
           */
          /* Assertion: '<S219>/Assertion' incorporates:
           *  Constant: '<S215>/Constant1'
           */
          utAssert(false);

          /* End of Outputs for SubSystem: '<S215>/Error' */
        }
      }

      /* End of If: '<S215>/If' */
      /* End of Outputs for SubSystem: '<S214>/Else If Not Orthogonal' */
    }
  }

  /* End of If: '<S214>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

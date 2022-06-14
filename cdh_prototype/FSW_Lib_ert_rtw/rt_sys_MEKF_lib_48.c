/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_48.c
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

#include "rt_sys_MEKF_lib_48.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S191>/If Warning//Error'
 *    '<S347>/If Warning//Error'
 */
void IfWarningError(const real_T rtu_dcm[9], real_T rtp_action, real_T
                    rtp_tolerance)
{
  real_T rtu_dcm_0[9];
  int32_T i;
  int32_T i_0;
  int32_T rtu_dcm_tmp;
  boolean_T rtb_Compare_f[9];
  boolean_T tmp;

  /* Bias: '<S218>/Bias1' incorporates:
   *  Math: '<S218>/Math Function'
   *  Product: '<S218>/Product'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_dcm_tmp = 3 * i_0 + i;
      rtu_dcm_0[rtu_dcm_tmp] = ((rtu_dcm[3 * i + 1] * rtu_dcm[3 * i_0 + 1] +
        rtu_dcm[3 * i] * rtu_dcm[3 * i_0]) + rtu_dcm[3 * i + 2] * rtu_dcm[3 *
        i_0 + 2]) + rtCP_Bias1_Bias[rtu_dcm_tmp];
    }
  }

  /* End of Bias: '<S218>/Bias1' */

  /* RelationalOperator: '<S224>/Compare' incorporates:
   *  Abs: '<S218>/Abs2'
   *  Constant: '<S224>/Constant'
   */
  for (i = 0; i < 9; i++) {
    rtb_Compare_f[i] = (fabs(rtu_dcm_0[i]) > rtp_tolerance);
  }

  /* End of RelationalOperator: '<S224>/Compare' */

  /* Logic: '<S218>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S224>/Compare'
   */
  tmp = rtb_Compare_f[0];
  for (i = 0; i < 8; i++) {
    tmp = (tmp || rtb_Compare_f[i + 1]);
  }

  /* If: '<S215>/If' incorporates:
   *  Abs: '<S219>/Abs1'
   *  Bias: '<S219>/Bias'
   *  Constant: '<S226>/Constant'
   *  Logic: '<S218>/Logical Operator1'
   *  Product: '<S225>/Product'
   *  Product: '<S225>/Product1'
   *  Product: '<S225>/Product2'
   *  Product: '<S225>/Product3'
   *  Product: '<S225>/Product4'
   *  Product: '<S225>/Product5'
   *  RelationalOperator: '<S226>/Compare'
   *  Sum: '<S225>/Sum'
   */
  if (fabs((((((rtu_dcm[0] * rtu_dcm[4] * rtu_dcm[8] - rtu_dcm[0] * rtu_dcm[5] *
                rtu_dcm[7]) - rtu_dcm[1] * rtu_dcm[3] * rtu_dcm[8]) + rtu_dcm[2]
              * rtu_dcm[3] * rtu_dcm[7]) + rtu_dcm[1] * rtu_dcm[5] * rtu_dcm[6])
            - rtu_dcm[2] * rtu_dcm[4] * rtu_dcm[6]) + -1.0) > rtp_tolerance) {
    /* Outputs for IfAction SubSystem: '<S215>/If Not Proper' incorporates:
     *  ActionPort: '<S217>/Action Port'
     */
    /* If: '<S217>/If' incorporates:
     *  Constant: '<S217>/Constant'
     */
    if (rtp_action == 2.0) {
      /* Outputs for IfAction SubSystem: '<S217>/Warning' incorporates:
       *  ActionPort: '<S223>/Action Port'
       */
      /* Assertion: '<S223>/Assertion' incorporates:
       *  Constant: '<S217>/Constant1'
       */
      utAssert(false);

      /* End of Outputs for SubSystem: '<S217>/Warning' */
    } else {
      if (rtp_action == 3.0) {
        /* Outputs for IfAction SubSystem: '<S217>/Error' incorporates:
         *  ActionPort: '<S222>/Action Port'
         */
        /* Assertion: '<S222>/Assertion' incorporates:
         *  Constant: '<S217>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S217>/Error' */
      }
    }

    /* End of If: '<S217>/If' */
    /* End of Outputs for SubSystem: '<S215>/If Not Proper' */
  } else {
    if (tmp) {
      /* Outputs for IfAction SubSystem: '<S215>/Else If Not Orthogonal' incorporates:
       *  ActionPort: '<S216>/Action Port'
       */
      /* If: '<S216>/If' incorporates:
       *  Constant: '<S216>/Constant'
       */
      if (rtp_action == 2.0) {
        /* Outputs for IfAction SubSystem: '<S216>/Warning' incorporates:
         *  ActionPort: '<S221>/Action Port'
         */
        /* Assertion: '<S221>/Assertion' incorporates:
         *  Constant: '<S216>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S216>/Warning' */
      } else {
        if (rtp_action == 3.0) {
          /* Outputs for IfAction SubSystem: '<S216>/Error' incorporates:
           *  ActionPort: '<S220>/Action Port'
           */
          /* Assertion: '<S220>/Assertion' incorporates:
           *  Constant: '<S216>/Constant1'
           */
          utAssert(false);

          /* End of Outputs for SubSystem: '<S216>/Error' */
        }
      }

      /* End of If: '<S216>/If' */
      /* End of Outputs for SubSystem: '<S215>/Else If Not Orthogonal' */
    }
  }

  /* End of If: '<S215>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

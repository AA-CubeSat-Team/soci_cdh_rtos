/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_FSW_Lib_23.c
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

#include "rt_sys_FSW_Lib_23.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for action system:
 *    '<S50>/If Warning//Error'
 *    '<S169>/If Warning//Error'
 */
void IfWarningError(const real_T rtu_dcm[9], real_T rtp_action, real_T
                    rtp_tolerance)
{
  real_T rtu_dcm_0[9];
  int32_T i;
  int32_T i_0;
  int32_T rtu_dcm_tmp;
  boolean_T rtb_Compare_b[9];
  boolean_T tmp;

  /* Bias: '<S77>/Bias1' incorporates:
   *  Math: '<S77>/Math Function'
   *  Product: '<S77>/Product'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_dcm_tmp = 3 * i_0 + i;
      rtu_dcm_0[rtu_dcm_tmp] = ((rtu_dcm[3 * i + 1] * rtu_dcm[3 * i_0 + 1] +
        rtu_dcm[3 * i] * rtu_dcm[3 * i_0]) + rtu_dcm[3 * i + 2] * rtu_dcm[3 *
        i_0 + 2]) + rtConstP.pooled9[rtu_dcm_tmp];
    }
  }

  /* End of Bias: '<S77>/Bias1' */

  /* RelationalOperator: '<S83>/Compare' incorporates:
   *  Abs: '<S77>/Abs2'
   *  Constant: '<S83>/Constant'
   */
  for (i = 0; i < 9; i++) {
    rtb_Compare_b[i] = (fabs(rtu_dcm_0[i]) > rtp_tolerance);
  }

  /* End of RelationalOperator: '<S83>/Compare' */

  /* Logic: '<S77>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S83>/Compare'
   */
  tmp = rtb_Compare_b[0];
  for (i = 0; i < 8; i++) {
    tmp = (tmp || rtb_Compare_b[i + 1]);
  }

  /* If: '<S74>/If' incorporates:
   *  Abs: '<S78>/Abs1'
   *  Bias: '<S78>/Bias'
   *  Constant: '<S85>/Constant'
   *  Logic: '<S77>/Logical Operator1'
   *  Product: '<S84>/Product'
   *  Product: '<S84>/Product1'
   *  Product: '<S84>/Product2'
   *  Product: '<S84>/Product3'
   *  Product: '<S84>/Product4'
   *  Product: '<S84>/Product5'
   *  RelationalOperator: '<S85>/Compare'
   *  Sum: '<S84>/Sum'
   */
  if (fabs((((((rtu_dcm[0] * rtu_dcm[4] * rtu_dcm[8] - rtu_dcm[0] * rtu_dcm[5] *
                rtu_dcm[7]) - rtu_dcm[1] * rtu_dcm[3] * rtu_dcm[8]) + rtu_dcm[2]
              * rtu_dcm[3] * rtu_dcm[7]) + rtu_dcm[1] * rtu_dcm[5] * rtu_dcm[6])
            - rtu_dcm[2] * rtu_dcm[4] * rtu_dcm[6]) + -1.0) > rtp_tolerance) {
    /* Outputs for IfAction SubSystem: '<S74>/If Not Proper' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    /* If: '<S76>/If' incorporates:
     *  Constant: '<S76>/Constant'
     */
    if (rtp_action == 2.0) {
      /* Outputs for IfAction SubSystem: '<S76>/Warning' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      /* Assertion: '<S82>/Assertion' incorporates:
       *  Constant: '<S76>/Constant1'
       */
      utAssert(false);

      /* End of Outputs for SubSystem: '<S76>/Warning' */
    } else {
      if (rtp_action == 3.0) {
        /* Outputs for IfAction SubSystem: '<S76>/Error' incorporates:
         *  ActionPort: '<S81>/Action Port'
         */
        /* Assertion: '<S81>/Assertion' incorporates:
         *  Constant: '<S76>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S76>/Error' */
      }
    }

    /* End of If: '<S76>/If' */
    /* End of Outputs for SubSystem: '<S74>/If Not Proper' */
  } else {
    if (tmp) {
      /* Outputs for IfAction SubSystem: '<S74>/Else If Not Orthogonal' incorporates:
       *  ActionPort: '<S75>/Action Port'
       */
      /* If: '<S75>/If' incorporates:
       *  Constant: '<S75>/Constant'
       */
      if (rtp_action == 2.0) {
        /* Outputs for IfAction SubSystem: '<S75>/Warning' incorporates:
         *  ActionPort: '<S80>/Action Port'
         */
        /* Assertion: '<S80>/Assertion' incorporates:
         *  Constant: '<S75>/Constant1'
         */
        utAssert(false);

        /* End of Outputs for SubSystem: '<S75>/Warning' */
      } else {
        if (rtp_action == 3.0) {
          /* Outputs for IfAction SubSystem: '<S75>/Error' incorporates:
           *  ActionPort: '<S79>/Action Port'
           */
          /* Assertion: '<S79>/Assertion' incorporates:
           *  Constant: '<S75>/Constant1'
           */
          utAssert(false);

          /* End of Outputs for SubSystem: '<S75>/Error' */
        }
      }

      /* End of If: '<S75>/If' */
      /* End of Outputs for SubSystem: '<S74>/Else If Not Orthogonal' */
    }
  }

  /* End of If: '<S74>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

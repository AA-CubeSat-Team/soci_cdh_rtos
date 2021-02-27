/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sunSeek_lib.c
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

#include "sunSeek_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Output and update for atomic system: '<S132>/sunSeek_lib' */
void sunSeek_lib(void)
{
  real_T rtb_Sin;
  real_T u0;
  int32_T i;
  real_T rtb_Kp_idx_1;
  real_T rtb_Kp_idx_2;
  real_T rtb_Kp_idx_0;

  /* Switch: '<S149>/Switch' */
  if (rtDW.Reshape4) {
    rtb_Kp_idx_0 = rtDW.ss_2_body[0];
    rtb_Kp_idx_1 = rtDW.ss_2_body[1];
    rtb_Kp_idx_2 = rtDW.ss_2_body[2];
  } else {
    rtb_Kp_idx_0 = rtDW.sun_body_unit[0];
    rtb_Kp_idx_1 = rtDW.sun_body_unit[1];
    rtb_Kp_idx_2 = rtDW.sun_body_unit[2];
  }

  /* End of Switch: '<S149>/Switch' */

  /* DotProduct: '<S150>/Dot Product' */
  u0 = (0.0 * rtb_Kp_idx_0 + rtb_Kp_idx_1) + 0.0 * rtb_Kp_idx_2;

  /* Saturate: '<S150>/sat_pm1' incorporates:
   *  DotProduct: '<S150>/Dot Product'
   */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  /* End of Saturate: '<S150>/sat_pm1' */

  /* Trigonometry: '<S150>/Sin' incorporates:
   *  Gain: '<S150>/Gain'
   *  Trigonometry: '<S150>/Acos'
   */
  rtb_Sin = sin(0.5 * acos(u0));

  /* Product: '<S150>/Product' incorporates:
   *  Product: '<S151>/Element product'
   *  Sum: '<S151>/Add3'
   */
  u0 = (rtb_Kp_idx_1 * 0.0 - rtb_Kp_idx_2) * rtb_Sin;
  rtb_Kp_idx_2 = (rtb_Kp_idx_2 * 0.0 - rtb_Kp_idx_0 * 0.0) * rtb_Sin;
  rtb_Kp_idx_0 = (rtb_Kp_idx_0 - rtb_Kp_idx_1 * 0.0) * rtb_Sin;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S149>/Sum' incorporates:
     *  Gain: '<S149>/Kd'
     *  Gain: '<S149>/Kp'
     */
    rtDW.Merge[i] = (rtCP_Kp_Gain[i + 6] * rtb_Kp_idx_0 + (rtCP_Kp_Gain[i + 3] *
      rtb_Kp_idx_2 + rtCP_Kp_Gain[i] * u0)) - (rtCP_Kd_Gain[i + 6] *
      rtDW.w_err_radps[2] + (rtCP_Kd_Gain[i + 3] * rtDW.w_err_radps[1] +
      rtCP_Kd_Gain[i] * rtDW.w_err_radps[0]));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

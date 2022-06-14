/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_select_lib.c
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

#include "mode_select_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"
#include "rt_roundd_snf.h"

/* System initialize for atomic system: '<S1>/mode_select_lib' */
void mode_select_lib_Init(DW_mode_select_lib *localDW)
{
  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 3U;
}

/* Output and update for atomic system: '<S1>/mode_select_lib' */
uint8_T mode_select_lib(const real_T rtu_telecom[6], boolean_T rtu_eclipse,
  uint8_T rtu_ss_valid, boolean_T rtu_sc_above_targ, const real_T
  rtu_body_rates_radps[3], real_T rtu_MET_utc_s, real_T rtu_MET_soar_utc_s,
  const real_T rtu_RWA_rpm[4], const ConstB_mode_select_lib *localC,
  DW_mode_select_lib *localDW)
{
  uint8_T rty_gnc_mode_0;
  real_T tmp[4];
  real_T rtb_Subtract1[3];
  real_T rtb_Sqrt_a;
  real_T tmp_0;
  int32_T i;

  /* Product: '<S330>/Matrix Multiply1' incorporates:
   *  Constant: '<S330>/A_wheel2body '
   *  Gain: '<S330>/rpm2radps'
   *  S-Function (sdspdiag2): '<S330>/Create Diagonal Matrix'
   */
  for (i = 0; i < 4; i++) {
    tmp_0 = localC->CreateDiagonalMatrix[i + 12] * (0.10471975511965977 *
      rtu_RWA_rpm[3]) + (localC->CreateDiagonalMatrix[i + 8] *
                         (0.10471975511965977 * rtu_RWA_rpm[2]) +
                         (localC->CreateDiagonalMatrix[i + 4] *
                          (0.10471975511965977 * rtu_RWA_rpm[1]) +
                          0.10471975511965977 * rtu_RWA_rpm[0] *
                          localC->CreateDiagonalMatrix[i]));
    tmp[i] = tmp_0;
  }

  for (i = 0; i < 3; i++) {
    tmp_0 = rtCP_A_wheel2body_Value_h[i + 9] * tmp[3] +
      (rtCP_A_wheel2body_Value_h[i + 6] * tmp[2] + (rtCP_A_wheel2body_Value_h[i
        + 3] * tmp[1] + rtCP_A_wheel2body_Value_h[i] * tmp[0]));

    /* Sum: '<S330>/Subtract1' incorporates:
     *  Constant: '<S330>/A_wheel2body '
     *  Constant: '<S330>/scParams.J '
     *  Product: '<S330>/Matrix Multiply'
     */
    rtb_Subtract1[i] = ((rtCP_scParamsJ_Value_h[i + 3] * rtu_body_rates_radps[1]
                         + rtCP_scParamsJ_Value_h[i] * rtu_body_rates_radps[0])
                        + rtCP_scParamsJ_Value_h[i + 6] * rtu_body_rates_radps[2])
      + tmp_0;
  }

  /* End of Product: '<S330>/Matrix Multiply1' */

  /* Outputs for Atomic SubSystem: '<S330>/twonorm1' */
  rtb_Sqrt_a = twonorm(rtb_Subtract1);

  /* End of Outputs for SubSystem: '<S330>/twonorm1' */

  /* Relay: '<S330>/Relay3' */
  localDW->Relay3_Mode = ((rtb_Sqrt_a >= 0.00236570528450198) || ((!(rtb_Sqrt_a <=
    0.00118285264225099)) && localDW->Relay3_Mode));

  /* Outputs for Atomic SubSystem: '<S9>/twonorm' */
  rtb_Sqrt_a = twonorm(rtu_body_rates_radps);

  /* End of Outputs for SubSystem: '<S9>/twonorm' */

  /* Relay: '<S9>/Relay' */
  localDW->Relay_Mode = ((rtb_Sqrt_a >= 0.26179938779914941) || ((!(rtb_Sqrt_a <=
    0.0087266462599716477)) && localDW->Relay_Mode));

  /* Sum: '<S331>/Sum' */
  rtb_Sqrt_a = rtu_MET_utc_s - rtu_MET_soar_utc_s;

  /* MATLAB Function: '<S9>/mode_select' incorporates:
   *  Relay: '<S330>/Relay3'
   *  Relay: '<S9>/Relay'
   */
  if (rtu_telecom[1] != 0.0) {
    rty_gnc_mode_0 = 0U;
  } else if (rtu_telecom[0] != 0.0) {
    tmp_0 = rt_roundd_snf(rtu_telecom[0]);
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        rty_gnc_mode_0 = (uint8_T)tmp_0;
      } else {
        rty_gnc_mode_0 = 0U;
      }
    } else {
      rty_gnc_mode_0 = MAX_uint8_T;
    }
  } else if (rtu_telecom[2] != 0.0) {
    rty_gnc_mode_0 = 1U;
  } else if (!(rtu_telecom[3] != 0.0)) {
    rty_gnc_mode_0 = 2U;
  } else if (localDW->Relay_Mode || localDW->Relay3_Mode) {
    rty_gnc_mode_0 = 3U;
  } else if ((!rtu_eclipse) && (rtu_ss_valid < 2)) {
    rty_gnc_mode_0 = 5U;
  } else if ((rtu_telecom[5] != 0.0) && ((rtb_Sqrt_a >= 0.0) && (rtb_Sqrt_a <
               25.0) && (rtu_MET_soar_utc_s != 0.0))) {
    rty_gnc_mode_0 = 8U;
  } else if (rtu_telecom[4] != 0.0) {
    if (rtu_sc_above_targ) {
      rty_gnc_mode_0 = 7U;
    } else {
      rty_gnc_mode_0 = 6U;
    }
  } else {
    rty_gnc_mode_0 = 6U;
  }

  /* End of MATLAB Function: '<S9>/mode_select' */

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_gnc_mode_0;
  return rty_gnc_mode_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

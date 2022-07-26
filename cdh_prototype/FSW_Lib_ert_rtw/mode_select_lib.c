/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_select_lib.c
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

#include "mode_select_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Output and update for atomic system: '<S1>/mode_select_lib' */
void mode_select_lib(const real_T rtu_telecom[6], boolean_T rtu_eclipse, uint8_T
                     rtu_ss_valid, const real_T rtu_body_rates_radps[3], real_T
                     rtu_MET_utc_s, real_T rtu_MET_soar_utc_s, const real_T
                     rtu_RWA_rpm[4], uint8_T *rty_gnc_mode, const
                     ConstB_mode_select_lib *localC, DW_mode_select_lib *localDW)
{
  real_T tmp[4];
  real_T rtb_Subtract1[3];
  real_T rtb_Sqrt_g;
  real_T tmp_0;
  int32_T i;

  /* Product: '<S143>/Matrix Multiply1' incorporates:
   *  Constant: '<S143>/A_wheel2body '
   *  Gain: '<S143>/rpm2radps'
   *  S-Function (sdspdiag2): '<S143>/Create Diagonal Matrix'
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
    tmp_0 = rtConstP.pooled13[i + 9] * tmp[3] + (rtConstP.pooled13[i + 6] * tmp
      [2] + (rtConstP.pooled13[i + 3] * tmp[1] + rtConstP.pooled13[i] * tmp[0]));

    /* Sum: '<S143>/Subtract1' incorporates:
     *  Constant: '<S143>/A_wheel2body '
     *  Constant: '<S143>/scParams.J '
     *  Product: '<S143>/Matrix Multiply'
     */
    rtb_Subtract1[i] = tmp_0 + (rtConstP.pooled16[i + 6] * rtu_body_rates_radps
      [2] + (rtConstP.pooled16[i + 3] * rtu_body_rates_radps[1] +
             rtConstP.pooled16[i] * rtu_body_rates_radps[0]));
  }

  /* End of Product: '<S143>/Matrix Multiply1' */

  /* Outputs for Atomic SubSystem: '<S143>/twonorm1' */
  rtb_Sqrt_g = twonorm_m(rtb_Subtract1);

  /* End of Outputs for SubSystem: '<S143>/twonorm1' */

  /* Relay: '<S143>/Relay3' */
  localDW->Relay3_Mode = ((rtb_Sqrt_g >= 1.0) || ((!(rtb_Sqrt_g <= 1.0)) &&
    localDW->Relay3_Mode));

  /* Outputs for Atomic SubSystem: '<S9>/twonorm' */
  rtb_Sqrt_g = twonorm_m(rtu_body_rates_radps);

  /* End of Outputs for SubSystem: '<S9>/twonorm' */

  /* Relay: '<S9>/Relay' */
  localDW->Relay_Mode = ((rtb_Sqrt_g >= 0.26179938779914941) || ((!(rtb_Sqrt_g <=
    0.0087266462599716477)) && localDW->Relay_Mode));

  /* Sum: '<S144>/Sum' */
  rtb_Sqrt_g = rtu_MET_utc_s - rtu_MET_soar_utc_s;

  /* MATLAB Function: '<S9>/mode_select' incorporates:
   *  Relay: '<S143>/Relay3'
   *  Relay: '<S9>/Relay'
   */
  if (rtu_telecom[1] != 0.0) {
    /* RateTransition: '<S9>/Rate Transition9' */
    *rty_gnc_mode = 0U;
  } else if (rtu_telecom[0] != 0.0) {
    tmp_0 = rt_roundd_snf(rtu_telecom[0]);
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        /* RateTransition: '<S9>/Rate Transition9' */
        *rty_gnc_mode = (uint8_T)tmp_0;
      } else {
        /* RateTransition: '<S9>/Rate Transition9' */
        *rty_gnc_mode = 0U;
      }
    } else {
      /* RateTransition: '<S9>/Rate Transition9' */
      *rty_gnc_mode = MAX_uint8_T;
    }
  } else if (rtu_telecom[2] != 0.0) {
    /* RateTransition: '<S9>/Rate Transition9' */
    *rty_gnc_mode = 1U;
  } else if (!(rtu_telecom[3] != 0.0)) {
    /* RateTransition: '<S9>/Rate Transition9' */
    *rty_gnc_mode = 2U;
  } else if (localDW->Relay_Mode || localDW->Relay3_Mode) {
    /* RateTransition: '<S9>/Rate Transition9' */
    *rty_gnc_mode = 3U;
  } else if ((!rtu_eclipse) && (rtu_ss_valid < 2)) {
    /* RateTransition: '<S9>/Rate Transition9' */
    *rty_gnc_mode = 5U;
  } else if ((rtu_telecom[5] != 0.0) && ((rtb_Sqrt_g >= 0.0) && (rtb_Sqrt_g <
               25.0) && (rtu_MET_soar_utc_s != 0.0))) {
    /* RateTransition: '<S9>/Rate Transition9' */
    *rty_gnc_mode = 8U;
  } else {
    /* RateTransition: '<S9>/Rate Transition9' */
    *rty_gnc_mode = 6U;
  }

  /* End of MATLAB Function: '<S9>/mode_select' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

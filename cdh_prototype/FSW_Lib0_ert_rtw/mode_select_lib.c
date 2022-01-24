/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_select_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 14 15:17:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "mode_select_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "rt_roundd_snf.h"

/* Output and update for atomic system: '<S1>/mode_select_lib' */
uint8_T mode_select_lib(const real_T rtu_telecom[6], boolean_T rtu_eclipse,
  uint8_T rtu_ss_valid, boolean_T rtu_sc_above_targ, const real_T
  rtu_body_rates_radps[3], real_T rtu_MET_utc_s, real_T rtu_MET_soar_utc_s,
  const real_T rtu_RWA_rpm[4], DW_mode_select_lib *localDW, P_mode_select_lib
  *localP)
{
  uint8_T rty_gnc_mode_0;
  real_T rtb_Subtract1_j[3];
  real_T rtb_Sqrt_a;
  int32_T i;
  real_T tmp;
  real_T rtb_CreateDiagonalMatrix_o_0;

  /* S-Function (sdspdiag2): '<S382>/Create Diagonal Matrix' incorporates:
   *  Constant: '<S382>/J_w_wheel_kgm2'
   */
  memset(&localDW->CreateDiagonalMatrix_o[0], 0, sizeof(real_T) << 4U);
  localDW->CreateDiagonalMatrix_o[0] = rtP.fswParams.allocator.inertia[0];
  localDW->CreateDiagonalMatrix_o[5] = rtP.fswParams.allocator.inertia[1];
  localDW->CreateDiagonalMatrix_o[10] = rtP.fswParams.allocator.inertia[2];
  localDW->CreateDiagonalMatrix_o[15] = rtP.fswParams.allocator.inertia[3];

  /* Product: '<S382>/Matrix Multiply1' incorporates:
   *  Constant: '<S382>/A_wheel2body '
   *  Gain: '<S382>/rpm2radps'
   */
  for (i = 0; i < 4; i++) {
    rtb_CreateDiagonalMatrix_o_0 = localDW->CreateDiagonalMatrix_o[i + 12] *
      (rtP.fswParams.constants.convert.RPM2RPS * rtu_RWA_rpm[3]) +
      (localDW->CreateDiagonalMatrix_o[i + 8] *
       (rtP.fswParams.constants.convert.RPM2RPS * rtu_RWA_rpm[2]) +
       (localDW->CreateDiagonalMatrix_o[i + 4] *
        (rtP.fswParams.constants.convert.RPM2RPS * rtu_RWA_rpm[1]) +
        rtP.fswParams.constants.convert.RPM2RPS * rtu_RWA_rpm[0] *
        localDW->CreateDiagonalMatrix_o[i]));
    localDW->rtb_CreateDiagonalMatrix_o_m[i] = rtb_CreateDiagonalMatrix_o_0;
  }

  for (i = 0; i < 3; i++) {
    rtb_CreateDiagonalMatrix_o_0 = rtP.fswParams.allocator.A_wheel2body[i + 9] *
      localDW->rtb_CreateDiagonalMatrix_o_m[3] +
      (rtP.fswParams.allocator.A_wheel2body[i + 6] *
       localDW->rtb_CreateDiagonalMatrix_o_m[2] +
       (rtP.fswParams.allocator.A_wheel2body[i + 3] *
        localDW->rtb_CreateDiagonalMatrix_o_m[1] +
        rtP.fswParams.allocator.A_wheel2body[i] *
        localDW->rtb_CreateDiagonalMatrix_o_m[0]));

    /* Sum: '<S382>/Subtract1' incorporates:
     *  Constant: '<S382>/A_wheel2body '
     *  Constant: '<S382>/scParams.J '
     *  Product: '<S382>/Matrix Multiply'
     */
    rtb_Subtract1_j[i] = ((rtP.fswParams.scParams.J[i + 3] *
      rtu_body_rates_radps[1] + rtP.fswParams.scParams.J[i] *
      rtu_body_rates_radps[0]) + rtP.fswParams.scParams.J[i + 6] *
                          rtu_body_rates_radps[2]) +
      rtb_CreateDiagonalMatrix_o_0;
  }

  /* End of Product: '<S382>/Matrix Multiply1' */

  /* Outputs for Atomic SubSystem: '<S382>/twonorm1' */
  rtb_Sqrt_a = twonorm(rtb_Subtract1_j);

  /* End of Outputs for SubSystem: '<S382>/twonorm1' */

  /* Relay: '<S382>/Relay3' */
  if (rtb_Sqrt_a >= rtP.fswParams.mode_select.h_max) {
    localDW->Relay3_Mode = true;
  } else {
    if (rtb_Sqrt_a <= rtP.fswParams.mode_select.h_min) {
      localDW->Relay3_Mode = false;
    }
  }

  /* Outputs for Atomic SubSystem: '<S9>/twonorm' */
  rtb_Sqrt_a = twonorm(rtu_body_rates_radps);

  /* End of Outputs for SubSystem: '<S9>/twonorm' */

  /* Relay: '<S9>/Relay' */
  if (rtb_Sqrt_a >= rtP.fswParams.mode_select.body_rate_threshold_max) {
    localDW->Relay_Mode = true;
  } else {
    if (rtb_Sqrt_a <= rtP.fswParams.mode_select.body_rate_threshold_min) {
      localDW->Relay_Mode = false;
    }
  }

  /* Sum: '<S383>/Sum' */
  rtb_Sqrt_a = rtu_MET_utc_s - rtu_MET_soar_utc_s;

  /* MATLAB Function: '<S9>/mode_select' incorporates:
   *  Constant: '<S387>/Constant'
   *  Constant: '<S388>/Constant'
   *  Constant: '<S389>/Constant'
   *  Logic: '<S383>/AND'
   *  RelationalOperator: '<S387>/Compare'
   *  RelationalOperator: '<S388>/Compare'
   *  RelationalOperator: '<S389>/Compare'
   *  Relay: '<S9>/Relay'
   */
  if (rtu_telecom[1] != 0.0) {
    rty_gnc_mode_0 = 0U;
  } else if (rtu_telecom[0] != 0.0) {
    rtb_CreateDiagonalMatrix_o_0 = rt_roundd_snf(rtu_telecom[0]);
    if (rtb_CreateDiagonalMatrix_o_0 < 256.0) {
      if (rtb_CreateDiagonalMatrix_o_0 >= 0.0) {
        rty_gnc_mode_0 = (uint8_T)rtb_CreateDiagonalMatrix_o_0;
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
  } else {
    if (localDW->Relay_Mode) {
      /* Relay: '<S9>/Relay' */
      rtb_CreateDiagonalMatrix_o_0 = localP->Relay_YOn;
    } else {
      /* Relay: '<S9>/Relay' */
      rtb_CreateDiagonalMatrix_o_0 = localP->Relay_YOff;
    }

    /* Relay: '<S382>/Relay3' */
    if (localDW->Relay3_Mode) {
      tmp = localP->Relay3_YOn;
    } else {
      tmp = localP->Relay3_YOff;
    }

    if ((rtb_CreateDiagonalMatrix_o_0 != 0.0) || (tmp != 0.0)) {
      rty_gnc_mode_0 = 3U;
    } else if ((!rtu_eclipse) && (rtu_ss_valid < 2)) {
      rty_gnc_mode_0 = 5U;
    } else if ((rtu_telecom[5] != 0.0) && ((rtb_Sqrt_a >=
                 localP->CompareToConstant_const) && (rtb_Sqrt_a <
                 localP->CompareToConstant2_const) && (rtu_MET_soar_utc_s !=
                 localP->CompareToConstant1_const))) {
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
  }

  /* End of MATLAB Function: '<S9>/mode_select' */
  return rty_gnc_mode_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

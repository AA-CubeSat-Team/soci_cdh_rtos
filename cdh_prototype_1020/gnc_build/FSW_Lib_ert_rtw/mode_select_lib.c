/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_select_lib.c
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

#include "mode_select_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"
#include "rt_roundd_snf.h"

/* System initialize for atomic system: '<S1>/mode_select_lib' */
void mode_select_lib_Init(DW_mode_select_lib *localDW)
{
  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  localDW->UnitDelay_DSTATE_i = 3U;
}

/* Output and update for atomic system: '<S1>/mode_select_lib' */
void mode_select_lib(const real_T rtu_telecom[6], boolean_T rtu_eclipse,
                     boolean_T rtu_ss_valid, boolean_T rtu_sc_above_targ, const
                     real_T rtu_body_rates_radps[3], real_T rtu_MET_utc_s,
                     real_T rtu_MET_soar_utc_s, const real_T rtu_RWA_rpm[4],
                     uint8_T *rty_gnc_mode, DW_mode_select_lib *localDW)
{
  boolean_T rEQ0;
  real_T rtb_Sum_kv;
  boolean_T rtb_OR;
  uint8_T rtb_UnitDelay_lg;
  real_T rtb_Abs1_p_idx_3;
  real_T rtb_Abs1_p_idx_2;
  real_T rtb_Abs1_p_idx_1;
  real_T rtb_Abs_h_idx_2;
  real_T rtb_Abs_h_idx_1;
  real_T rtb_Abs_h_idx_0;
  boolean_T guard1 = false;

  /* Abs: '<S263>/Abs1' */
  rtb_Abs1_p_idx_1 = fabs(rtu_RWA_rpm[1]);
  rtb_Abs1_p_idx_2 = fabs(rtu_RWA_rpm[2]);
  rtb_Abs1_p_idx_3 = fabs(rtu_RWA_rpm[3]);

  /* Abs: '<S9>/Abs' */
  rtb_Abs_h_idx_0 = fabs(rtu_body_rates_radps[0]);
  rtb_Abs_h_idx_1 = fabs(rtu_body_rates_radps[1]);
  rtb_Abs_h_idx_2 = fabs(rtu_body_rates_radps[2]);

  /* MinMax: '<S9>/MinMax' */
  if ((rtb_Abs_h_idx_0 > rtb_Abs_h_idx_1) || rtIsNaN(rtb_Abs_h_idx_1)) {
    rtb_Abs_h_idx_1 = rtb_Abs_h_idx_0;
  }

  if ((!(rtb_Abs_h_idx_1 > rtb_Abs_h_idx_2)) && (!rtIsNaN(rtb_Abs_h_idx_2))) {
    rtb_Abs_h_idx_1 = rtb_Abs_h_idx_2;
  }

  /* Relay: '<S9>/Relay' incorporates:
   *  MinMax: '<S9>/MinMax'
   */
  if (rtb_Abs_h_idx_1 >= 0.15707963267948966) {
    localDW->Relay_Mode = true;
  } else {
    if (rtb_Abs_h_idx_1 <= 0.0087266462599716477) {
      localDW->Relay_Mode = false;
    }
  }

  /* Outputs for Atomic SubSystem: '<S263>/twonorm' */
  rtb_Sum_kv = twonorm_o(rtu_RWA_rpm);

  /* End of Outputs for SubSystem: '<S263>/twonorm' */

  /* Relay: '<S263>/Relay2' */
  if (rtb_Sum_kv >= 6000.0) {
    localDW->Relay2_Mode = true;
  } else {
    if (rtb_Sum_kv <= 2200.0) {
      localDW->Relay2_Mode = false;
    }
  }

  /* MinMax: '<S263>/MinMax1' incorporates:
   *  Abs: '<S263>/Abs1'
   */
  rtb_Sum_kv = fabs(rtu_RWA_rpm[0]);
  rtb_Abs_h_idx_1 = rtb_Sum_kv;
  if ((rtb_Abs_h_idx_1 > rtb_Abs1_p_idx_1) || rtIsNaN(rtb_Abs1_p_idx_1)) {
    rtb_Sum_kv = rtb_Abs_h_idx_1;
  } else {
    rtb_Sum_kv = rtb_Abs1_p_idx_1;
  }

  rtb_Abs_h_idx_1 = rtb_Sum_kv;
  if ((rtb_Abs_h_idx_1 > rtb_Abs1_p_idx_2) || rtIsNaN(rtb_Abs1_p_idx_2)) {
    rtb_Sum_kv = rtb_Abs_h_idx_1;
  } else {
    rtb_Sum_kv = rtb_Abs1_p_idx_2;
  }

  rtb_Abs_h_idx_1 = rtb_Sum_kv;
  if ((rtb_Abs_h_idx_1 > rtb_Abs1_p_idx_3) || rtIsNaN(rtb_Abs1_p_idx_3)) {
    rtb_Sum_kv = rtb_Abs_h_idx_1;
  } else {
    rtb_Sum_kv = rtb_Abs1_p_idx_3;
  }

  /* End of MinMax: '<S263>/MinMax1' */

  /* Relay: '<S263>/Relay1' */
  if (rtb_Sum_kv >= 5000.0) {
    localDW->Relay1_Mode = true;
  } else {
    if (rtb_Sum_kv <= 1500.0) {
      localDW->Relay1_Mode = false;
    }
  }

  rtb_Sum_kv = localDW->Relay1_Mode;

  /* End of Relay: '<S263>/Relay1' */

  /* Logic: '<S263>/OR' incorporates:
   *  Relay: '<S263>/Relay2'
   */
  rtb_OR = (localDW->Relay2_Mode || (rtb_Sum_kv != 0.0));

  /* Sum: '<S264>/Sum' */
  rtb_Sum_kv = rtu_MET_utc_s - rtu_MET_soar_utc_s;

  /* UnitDelay: '<S9>/Unit Delay' */
  rtb_UnitDelay_lg = localDW->UnitDelay_DSTATE_i;

  /* MATLAB Function: '<S265>/desat_timer_logic' incorporates:
   *  Constant: '<S265>/Constant'
   *  Constant: '<S265>/Constant1'
   *  UnitDelay: '<S265>/Unit Delay'
   *  UnitDelay: '<S265>/Unit Delay1'
   *  UnitDelay: '<S265>/Unit Delay2'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  rtb_Abs_h_idx_1 = localDW->UnitDelay_DSTATE;
  rtb_Abs1_p_idx_1 = localDW->UnitDelay2_DSTATE;
  if ((localDW->UnitDelay_DSTATE_i == 4) && (localDW->UnitDelay1_DSTATE != 4)) {
    rtb_Abs_h_idx_1 = rtu_MET_utc_s;
    rtb_Abs1_p_idx_1 = 1.0;
  }

  if (rtb_Abs1_p_idx_1 == 1.0) {
    rtb_Abs1_p_idx_2 = rtu_MET_utc_s - rtb_Abs_h_idx_1;
    if ((!rtIsInf(rtb_Abs1_p_idx_2)) && (!rtIsNaN(rtb_Abs1_p_idx_2))) {
      if (rtb_Abs1_p_idx_2 == 0.0) {
        rtb_Abs1_p_idx_3 = 0.0;
      } else {
        rtb_Abs1_p_idx_3 = fmod(rtb_Abs1_p_idx_2, 5738.99281851731);
        rEQ0 = (rtb_Abs1_p_idx_3 == 0.0);
        if (!rEQ0) {
          rtb_Abs_h_idx_0 = fabs(rtb_Abs1_p_idx_2 / 5738.99281851731);
          rEQ0 = (fabs(rtb_Abs_h_idx_0 - floor(rtb_Abs_h_idx_0 + 0.5)) <=
                  2.2204460492503131E-16 * rtb_Abs_h_idx_0);
        }

        if (rEQ0) {
          rtb_Abs1_p_idx_3 = 0.0;
        } else {
          if (rtb_Abs1_p_idx_2 < 0.0) {
            rtb_Abs1_p_idx_3 += 5738.99281851731;
          }
        }
      }
    } else {
      rtb_Abs1_p_idx_3 = (rtNaN);
    }

    if ((rtb_Abs1_p_idx_3 < 30.0) && (rtb_Abs1_p_idx_2 > 30.0)) {
      rtb_Abs1_p_idx_1 = 0.0;
    }
  }

  /* MATLAB Function: '<S9>/mode_select' incorporates:
   *  MATLAB Function: '<S265>/desat_timer_logic'
   *  Relay: '<S9>/Relay'
   */
  if (rtu_telecom[1] != 0.0) {
    *rty_gnc_mode = 0U;
  } else if (rtu_telecom[0] != 0.0) {
    rtb_Abs1_p_idx_2 = rt_roundd_snf(rtu_telecom[0]);
    if (rtb_Abs1_p_idx_2 < 256.0) {
      if (rtb_Abs1_p_idx_2 >= 0.0) {
        *rty_gnc_mode = (uint8_T)rtb_Abs1_p_idx_2;
      } else {
        *rty_gnc_mode = 0U;
      }
    } else {
      *rty_gnc_mode = MAX_uint8_T;
    }
  } else if (rtu_telecom[2] != 0.0) {
    *rty_gnc_mode = 1U;
  } else if (!(rtu_telecom[3] != 0.0)) {
    *rty_gnc_mode = 2U;
  } else if (localDW->Relay_Mode) {
    *rty_gnc_mode = 3U;
  } else if (rtb_OR || (rtb_Abs1_p_idx_1 != 0.0)) {
    if (!rtb_OR) {
      *rty_gnc_mode = 3U;
    } else {
      *rty_gnc_mode = 4U;
    }
  } else if ((!rtu_eclipse) && (!rtu_ss_valid)) {
    *rty_gnc_mode = 5U;
  } else {
    guard1 = false;
    if (rtu_telecom[5] != 0.0) {
      if (rtu_telecom[4] != 0.0) {
        *rty_gnc_mode = 8U;
      } else if ((rtb_Sum_kv >= 0.0) && (rtb_Sum_kv < 25.0) &&
                 (rtu_MET_soar_utc_s != 0.0)) {
        *rty_gnc_mode = 8U;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (rtu_telecom[4] != 0.0) {
        if (rtu_sc_above_targ) {
          *rty_gnc_mode = 7U;
        } else {
          *rty_gnc_mode = 6U;
        }
      } else {
        *rty_gnc_mode = 6U;
      }
    }
  }

  /* End of MATLAB Function: '<S9>/mode_select' */

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  localDW->UnitDelay_DSTATE_i = *rty_gnc_mode;

  /* Update for UnitDelay: '<S265>/Unit Delay' incorporates:
   *  MATLAB Function: '<S265>/desat_timer_logic'
   */
  localDW->UnitDelay_DSTATE = rtb_Abs_h_idx_1;

  /* Update for UnitDelay: '<S265>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = rtb_UnitDelay_lg;

  /* Update for UnitDelay: '<S265>/Unit Delay2' incorporates:
   *  MATLAB Function: '<S265>/desat_timer_logic'
   */
  localDW->UnitDelay2_DSTATE = rtb_Abs1_p_idx_1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

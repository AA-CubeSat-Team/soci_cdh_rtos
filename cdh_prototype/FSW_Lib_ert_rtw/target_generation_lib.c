/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_generation_lib.c
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

#include "target_generation_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Forward declaration for local functions */
static real_T norm(const real_T x[3]);
static void align_vecs(real_T Body1[3], real_T Inertial1[3], real_T Body2[3],
  real_T Inertial2[3], real_T C_cmd[9]);

/* Function for MATLAB Function: '<S11>/target_gen' */
static real_T norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S11>/target_gen' */
static void align_vecs(real_T Body1[3], real_T Inertial1[3], real_T Body2[3],
  real_T Inertial2[3], real_T C_cmd[9])
{
  real_T Body1_0[9];
  real_T Inertial1_0[9];
  real_T Ytb[3];
  real_T Yti[3];
  real_T Ztb[3];
  real_T Zti[3];
  real_T Body1_1;
  real_T Body2_0;
  real_T Inertial1_1;
  real_T Inertial2_0;
  real_T Ytb_0;
  real_T Yti_0;
  int32_T C_cmd_tmp;
  int32_T i;
  int32_T i_0;
  Body2_0 = norm(Body1);
  Inertial2_0 = norm(Body2);
  Body1[0] /= Body2_0;
  Body2[0] /= Inertial2_0;
  Body1[1] /= Body2_0;
  Body2[1] /= Inertial2_0;
  Body1_1 = Body1[2] / Body2_0;
  Body2_0 = Body2[2] / Inertial2_0;
  Ytb[0] = Body1[1] * Body2_0 - Body1_1 * Body2[1];
  Ytb[1] = Body1_1 * Body2[0] - Body1[0] * Body2_0;
  Ytb[2] = Body1[0] * Body2[1] - Body1[1] * Body2[0];
  Body2_0 = norm(Ytb);
  Ytb[0] /= Body2_0;
  Ytb[1] /= Body2_0;
  Ytb_0 = Ytb[2] / Body2_0;
  Ztb[0] = Body1[1] * Ytb_0 - Body1_1 * Ytb[1];
  Ztb[1] = Body1_1 * Ytb[0] - Body1[0] * Ytb_0;
  Ztb[2] = Body1[0] * Ytb[1] - Body1[1] * Ytb[0];
  Body2_0 = norm(Ztb);
  Inertial2_0 = norm(Inertial1);
  Yti_0 = norm(Inertial2);
  Ztb[0] /= Body2_0;
  Inertial1[0] /= Inertial2_0;
  Inertial2[0] /= Yti_0;
  Ztb[1] /= Body2_0;
  Inertial1[1] /= Inertial2_0;
  Inertial2[1] /= Yti_0;
  Inertial1_1 = Inertial1[2] / Inertial2_0;
  Inertial2_0 = Inertial2[2] / Yti_0;
  Yti[0] = Inertial1[1] * Inertial2_0 - Inertial1_1 * Inertial2[1];
  Yti[1] = Inertial1_1 * Inertial2[0] - Inertial1[0] * Inertial2_0;
  Yti[2] = Inertial1[0] * Inertial2[1] - Inertial1[1] * Inertial2[0];
  Inertial2_0 = norm(Yti);
  Yti[0] /= Inertial2_0;
  Yti[1] /= Inertial2_0;
  Yti_0 = Yti[2] / Inertial2_0;
  Zti[0] = Inertial1[1] * Yti_0 - Inertial1_1 * Yti[1];
  Zti[1] = Inertial1_1 * Yti[0] - Inertial1[0] * Yti_0;
  Zti[2] = Inertial1[0] * Yti[1] - Inertial1[1] * Yti[0];
  Inertial2_0 = norm(Zti);
  Body1_0[0] = Body1[0];
  Body1_0[3] = Ytb[0];
  Body1_0[6] = Ztb[0];
  Inertial1_0[0] = Inertial1[0];
  Inertial1_0[1] = Yti[0];
  Inertial1_0[2] = Zti[0] / Inertial2_0;
  Body1_0[1] = Body1[1];
  Body1_0[4] = Ytb[1];
  Body1_0[7] = Ztb[1];
  Inertial1_0[3] = Inertial1[1];
  Inertial1_0[4] = Yti[1];
  Inertial1_0[5] = Zti[1] / Inertial2_0;
  Body1_0[2] = Body1_1;
  Body1_0[5] = Ytb_0;
  Body1_0[8] = Ztb[2] / Body2_0;
  Inertial1_0[6] = Inertial1_1;
  Inertial1_0[7] = Yti_0;
  Inertial1_0[8] = Zti[2] / Inertial2_0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      C_cmd_tmp = i + 3 * i_0;
      C_cmd[C_cmd_tmp] = 0.0;
      C_cmd[C_cmd_tmp] += Inertial1_0[3 * i_0] * Body1_0[i];
      C_cmd[C_cmd_tmp] += Inertial1_0[3 * i_0 + 1] * Body1_0[i + 3];
      C_cmd[C_cmd_tmp] += Inertial1_0[3 * i_0 + 2] * Body1_0[i + 6];
    }
  }
}

/* System initialize for atomic system: '<S1>/target_generation_lib' */
void target_generation_lib_Init(void)
{
  /* SystemInitialize for Merge: '<S162>/Merge' */
  rtDW.Merge_f[0] = 1.0;
  rtDW.Merge_f[1] = 0.0;
  rtDW.Merge_f[2] = 0.0;
  rtDW.Merge_f[3] = 0.0;
}

/* Output and update for atomic system: '<S1>/target_generation_lib' */
void target_generation_lib(uint8_T rtu_gnc_mode, const real_T
  rtu_sc2sun_eci_unit[3], const real_T rtu_sc2targ_eci_unit[3], const real_T
  rtu_r_eci_m[3], const real_T rtu_quat_soar_cmd[4], real_T rtu_MET_epoch,
  real_T rtu_MET_utc_s, boolean_T rtu_sc_above_targ, real_T rtu_img_active)
{
  static const real_T d[3] = { 0.0, 0.0, -1.0 };

  static const real_T e[3] = { 0.0, 0.0, 1.0 };

  real_T rtb_C_cmd[9];
  real_T rtb_Switch[4];
  real_T e_0[3];
  real_T rtb_MathFunction[3];
  real_T rtb_Switch1[3];
  real_T rtu_sc2sun_eci_unit_0[3];
  real_T rtb_Sum;
  int32_T i;

  /* Switch: '<S11>/Switch1' incorporates:
   *  Gain: '<S11>/Gain'
   *  Logic: '<S11>/AND'
   */
  if (rtu_sc_above_targ && (rtu_img_active != 0.0)) {
    rtb_Switch1[0] = rtu_r_eci_m[0];
    rtb_Switch1[1] = rtu_r_eci_m[1];
    rtb_Switch1[2] = rtu_r_eci_m[2];
  } else {
    rtb_Switch1[0] = -rtu_r_eci_m[0];
    rtb_Switch1[1] = -rtu_r_eci_m[1];
    rtb_Switch1[2] = -rtu_r_eci_m[2];
  }

  /* End of Switch: '<S11>/Switch1' */

  /* Sum: '<S163>/Sum of Elements' incorporates:
   *  Math: '<S163>/Math Function'
   */
  rtb_Sum = (rtb_Switch1[0] * rtb_Switch1[0] + rtb_Switch1[1] * rtb_Switch1[1])
    + rtb_Switch1[2] * rtb_Switch1[2];

  /* Math: '<S163>/Math Function1'
   *
   * About '<S163>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sum < 0.0) {
    rtb_Sum = -sqrt(fabs(rtb_Sum));
  } else {
    rtb_Sum = sqrt(rtb_Sum);
  }

  /* End of Math: '<S163>/Math Function1' */

  /* Switch: '<S163>/Switch' incorporates:
   *  Constant: '<S163>/Constant'
   *  Product: '<S163>/Product'
   */
  if (rtb_Sum > 0.0) {
    rtb_Switch[0] = rtb_Switch1[0];
    rtb_Switch[1] = rtb_Switch1[1];
    rtb_Switch[2] = rtb_Switch1[2];
    rtb_Switch[3] = rtb_Sum;
  } else {
    rtb_Switch[0] = rtb_Switch1[0] * 0.0;
    rtb_Switch[1] = rtb_Switch1[1] * 0.0;
    rtb_Switch[2] = rtb_Switch1[2] * 0.0;
    rtb_Switch[3] = 1.0;
  }

  /* End of Switch: '<S163>/Switch' */

  /* Product: '<S163>/Divide' */
  rtb_Switch1[0] = rtb_Switch[0] / rtb_Switch[3];
  rtb_Switch1[1] = rtb_Switch[1] / rtb_Switch[3];
  rtb_Switch1[2] = rtb_Switch[2] / rtb_Switch[3];

  /* MATLAB Function: '<S11>/target_gen' */
  if (rtu_gnc_mode == 7) {
    rtb_Switch1[0] = -rtb_Switch1[0];
    rtb_Switch1[1] = -rtb_Switch1[1];
    rtb_Switch1[2] = -rtb_Switch1[2];
  }

  rtb_C_cmd[0] = 0.766044443118978;
  rtb_C_cmd[3] = 0.64278760968653925;
  rtb_C_cmd[6] = 0.0;
  rtb_C_cmd[1] = -0.64278760968653925;
  rtb_C_cmd[4] = 0.766044443118978;
  rtb_C_cmd[7] = 0.0;
  rtb_C_cmd[2] = 0.0;
  rtb_C_cmd[5] = 0.0;
  rtb_C_cmd[8] = 1.0;
  for (i = 0; i < 3; i++) {
    rtb_MathFunction[i] = rtb_C_cmd[i + 3] + rtb_C_cmd[i] * 0.0;
  }

  if (norm(rtu_sc2sun_eci_unit) < 0.001) {
    memset(&rtb_C_cmd[0], 0, 9U * sizeof(real_T));
    rtb_C_cmd[0] = 1.0;
    rtb_C_cmd[4] = 1.0;
    rtb_C_cmd[8] = 1.0;
  } else if (norm(rtu_sc2targ_eci_unit) < 0.001) {
    memset(&rtb_C_cmd[0], 0, 9U * sizeof(real_T));
    rtb_C_cmd[0] = 1.0;
    rtb_C_cmd[4] = 1.0;
    rtb_C_cmd[8] = 1.0;
  } else if (norm(rtb_Switch1) < 0.001) {
    memset(&rtb_C_cmd[0], 0, 9U * sizeof(real_T));
    rtb_C_cmd[0] = 1.0;
    rtb_C_cmd[4] = 1.0;
    rtb_C_cmd[8] = 1.0;
  } else if (rtu_gnc_mode == 8) {
    if (fabs((rtu_sc2sun_eci_unit[0] * rtu_sc2targ_eci_unit[0] +
              rtu_sc2sun_eci_unit[1] * rtu_sc2targ_eci_unit[1]) +
             rtu_sc2sun_eci_unit[2] * rtu_sc2targ_eci_unit[2]) > 0.999) {
      memset(&rtb_C_cmd[0], 0, 9U * sizeof(real_T));
      rtb_C_cmd[0] = 1.0;
      rtb_C_cmd[4] = 1.0;
      rtb_C_cmd[8] = 1.0;
    } else {
      for (i = 0; i < 3; i++) {
        rtu_sc2sun_eci_unit_0[i] = rtu_sc2sun_eci_unit[i];
      }

      for (i = 0; i < 3; i++) {
        rtb_Switch1[i] = d[i];
      }

      for (i = 0; i < 3; i++) {
        e_0[i] = rtu_sc2targ_eci_unit[i];
      }

      align_vecs(rtb_MathFunction, rtu_sc2sun_eci_unit_0, rtb_Switch1, e_0,
                 rtb_C_cmd);
    }
  } else if ((rtu_gnc_mode == 4) || (rtu_gnc_mode == 5) || (rtu_gnc_mode == 6) ||
             (rtu_gnc_mode == 7)) {
    if (fabs((rtb_Switch1[0] * rtu_sc2sun_eci_unit[0] + rtb_Switch1[1] *
              rtu_sc2sun_eci_unit[1]) + rtb_Switch1[2] * rtu_sc2sun_eci_unit[2])
        > 0.999) {
      memset(&rtb_C_cmd[0], 0, 9U * sizeof(real_T));
      rtb_C_cmd[0] = 1.0;
      rtb_C_cmd[4] = 1.0;
      rtb_C_cmd[8] = 1.0;
    } else {
      for (i = 0; i < 3; i++) {
        rtu_sc2sun_eci_unit_0[i] = rtu_sc2sun_eci_unit[i];
      }

      for (i = 0; i < 3; i++) {
        e_0[i] = e[i];
      }

      align_vecs(rtb_MathFunction, rtu_sc2sun_eci_unit_0, e_0, rtb_Switch1,
                 rtb_C_cmd);
    }
  } else {
    memset(&rtb_C_cmd[0], 0, 9U * sizeof(real_T));
    rtb_C_cmd[0] = 1.0;
    rtb_C_cmd[4] = 1.0;
    rtb_C_cmd[8] = 1.0;
  }

  /* End of MATLAB Function: '<S11>/target_gen' */

  /* Outputs for IfAction SubSystem: '<S169>/If Warning//Error' incorporates:
   *  ActionPort: '<S193>/if'
   */
  /* If: '<S169>/If1' */
  IfWarningError(rtb_C_cmd, 2.0, 1.0E-12);

  /* End of Outputs for SubSystem: '<S169>/If Warning//Error' */

  /* Sum: '<S170>/Add' */
  rtb_Sum = (rtb_C_cmd[0] + rtb_C_cmd[4]) + rtb_C_cmd[8];

  /* If: '<S162>/If' */
  if (rtb_Sum > 0.0) {
    /* Outputs for IfAction SubSystem: '<S162>/Positive Trace' incorporates:
     *  ActionPort: '<S168>/Action Port'
     */
    PositiveTrace(rtb_Sum, rtb_C_cmd, &rtDW.Merge_f[0], &rtDW.Merge_f[1]);

    /* End of Outputs for SubSystem: '<S162>/Positive Trace' */
  } else {
    /* Outputs for IfAction SubSystem: '<S162>/Negative Trace' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    NegativeTrace(rtb_C_cmd, rtDW.Merge_f);

    /* End of Outputs for SubSystem: '<S162>/Negative Trace' */
  }

  /* End of If: '<S162>/If' */

  /* Sum: '<S164>/Sum' */
  rtb_Sum = rtu_MET_utc_s - rtu_MET_epoch;

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S205>/Constant'
   *  Constant: '<S206>/Constant'
   *  Constant: '<S207>/Constant'
   *  Logic: '<S11>/NOT'
   *  Logic: '<S164>/AND'
   *  RelationalOperator: '<S205>/Compare'
   *  RelationalOperator: '<S206>/Compare'
   *  RelationalOperator: '<S207>/Compare'
   */
  if ((!(rtb_Sum >= 0.0)) || (!(rtb_Sum < 25.0)) || (!(rtu_MET_epoch != 0.0))) {
    /* Outport: '<Root>/cmd_quat' incorporates:
     *  Math: '<S11>/Transpose'
     */
    rtY.cmd_quat[0] = rtDW.Merge_f[0];

    /* Reshape: '<S11>/Reshape' incorporates:
     *  Math: '<S11>/Transpose'
     */
    rtb_Switch[0] = rtDW.Merge_f[0];

    /* Outport: '<Root>/cmd_quat' incorporates:
     *  Math: '<S11>/Transpose'
     */
    rtY.cmd_quat[1] = rtDW.Merge_f[1];

    /* Reshape: '<S11>/Reshape' incorporates:
     *  Math: '<S11>/Transpose'
     */
    rtb_Switch[1] = rtDW.Merge_f[1];

    /* Outport: '<Root>/cmd_quat' incorporates:
     *  Math: '<S11>/Transpose'
     */
    rtY.cmd_quat[2] = rtDW.Merge_f[2];

    /* Reshape: '<S11>/Reshape' incorporates:
     *  Math: '<S11>/Transpose'
     */
    rtb_Switch[2] = rtDW.Merge_f[2];

    /* Outport: '<Root>/cmd_quat' incorporates:
     *  Math: '<S11>/Transpose'
     */
    rtY.cmd_quat[3] = rtDW.Merge_f[3];

    /* Reshape: '<S11>/Reshape' incorporates:
     *  Math: '<S11>/Transpose'
     */
    rtb_Switch[3] = rtDW.Merge_f[3];

    /* Outputs for Atomic SubSystem: '<S11>/quat_rectify_lib' */
    /* Outport: '<Root>/cmd_quat' */
    quat_rectify_lib(rtb_Switch, rtY.cmd_quat);

    /* End of Outputs for SubSystem: '<S11>/quat_rectify_lib' */
  } else {
    /* Outport: '<Root>/cmd_quat' */
    rtY.cmd_quat[0] = rtu_quat_soar_cmd[0];
    rtY.cmd_quat[1] = rtu_quat_soar_cmd[1];
    rtY.cmd_quat[2] = rtu_quat_soar_cmd[2];
    rtY.cmd_quat[3] = rtu_quat_soar_cmd[3];
  }

  /* End of Switch: '<S11>/Switch' */

  /* Outport: '<Root>/soar_telemetry' incorporates:
   *  Constant: '<S11>/Constant18'
   */
  rtY.soar_telemetry_e = FSW_Lib_rtZsoar_telemetry;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: align_vecs_GEQPakmX.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
 */

#include "rtwtypes.h"
#include "norm_2e9Xj4lM.h"
#include "align_vecs_GEQPakmX.h"

/* Function for MATLAB Function: '<S9>/target_gen' */
void align_vecs_GEQPakmX(real_T Body1[3], real_T Inertial1[3], real_T Body2[3],
  real_T Inertial2[3], real_T C_cmd[9])
{
  real_T Ytb[3];
  real_T Ztb[3];
  real_T Yti[3];
  real_T Zti[3];
  real_T Body1_0[9];
  real_T Inertial1_0[9];
  int32_T i;
  int32_T i_0;
  real_T Body1_1;
  real_T Body2_0;
  real_T Ytb_0;
  real_T Inertial1_1;
  real_T Inertial2_0;
  real_T Yti_0;
  int32_T C_cmd_tmp;
  int32_T C_cmd_tmp_0;
  Body2_0 = norm_2e9Xj4lM(Body1);
  Inertial2_0 = norm_2e9Xj4lM(Body2);
  Body1[0] /= Body2_0;
  Body2[0] /= Inertial2_0;
  Body1[1] /= Body2_0;
  Body2[1] /= Inertial2_0;
  Body1_1 = Body1[2] / Body2_0;
  Body2_0 = Body2[2] / Inertial2_0;
  Ytb[0] = Body1[1] * Body2_0 - Body1_1 * Body2[1];
  Ytb[1] = Body1_1 * Body2[0] - Body1[0] * Body2_0;
  Ytb[2] = Body1[0] * Body2[1] - Body1[1] * Body2[0];
  Body2_0 = norm_2e9Xj4lM(Ytb);
  Ytb[0] /= Body2_0;
  Ytb[1] /= Body2_0;
  Ytb_0 = Ytb[2] / Body2_0;
  Ztb[0] = Body1[1] * Ytb_0 - Body1_1 * Ytb[1];
  Ztb[1] = Body1_1 * Ytb[0] - Body1[0] * Ytb_0;
  Ztb[2] = Body1[0] * Ytb[1] - Body1[1] * Ytb[0];
  Body2_0 = norm_2e9Xj4lM(Ztb);
  Inertial2_0 = norm_2e9Xj4lM(Inertial1);
  Yti_0 = norm_2e9Xj4lM(Inertial2);
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
  Inertial2_0 = norm_2e9Xj4lM(Yti);
  Yti[0] /= Inertial2_0;
  Yti[1] /= Inertial2_0;
  Yti_0 = Yti[2] / Inertial2_0;
  Zti[0] = Inertial1[1] * Yti_0 - Inertial1_1 * Yti[1];
  Zti[1] = Inertial1_1 * Yti[0] - Inertial1[0] * Yti_0;
  Zti[2] = Inertial1[0] * Yti[1] - Inertial1[1] * Yti[0];
  Inertial2_0 = norm_2e9Xj4lM(Zti);
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
      C_cmd_tmp_0 = 3 * i_0 + i;
      C_cmd[C_cmd_tmp] = C_cmd[C_cmd_tmp_0] + Inertial1_0[3 * i_0] * Body1_0[i];
      C_cmd[C_cmd_tmp] = Inertial1_0[3 * i_0 + 1] * Body1_0[i + 3] +
        C_cmd[C_cmd_tmp_0];
      C_cmd[C_cmd_tmp] = Inertial1_0[3 * i_0 + 2] * Body1_0[i + 6] +
        C_cmd[C_cmd_tmp_0];
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

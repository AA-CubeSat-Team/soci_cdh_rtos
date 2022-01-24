/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: target_generation_lib.c
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

#include "target_generation_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"
#include "MWDSP_EPH_R_B.h"
#include "bsearch_s1bfmSFP.h"
#include "eye_bAKT5eRN.h"
#include "eye_y3VYXK5u.h"
#include "norm_UjNDAYVY.h"
#include "norm_ajWdQkav.h"

/* Forward declaration for local functions */
static real_T norm_2e9Xj4lM_g(const real_T x[3]);
static void align_vecs_GEQPakmX_m(real_T Body1[3], real_T Inertial1[3], real_T
  Body2[3], real_T Inertial2[3], real_T C_cmd[9]);
static void mldivide_FcIbHgdz_o(const real_T A[9], const real_T B_1[3], real_T
  Y[3]);
static void deriv_3jC2Hyd6_i(real_T t, const real_T x[10], const real_T u[30],
  const real_T ut[10], const real_T J[9], real_T dx[10]);
static real_T xnrm2_ooZ215qV_d(int32_T n, const real_T x[16], int32_T ix0);
static real_T rt_hypotd_snf_h(real_T u0, real_T u1);
static void xzlarf_tQsI3TnT_j(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[16], int32_T ic0, real_T work[4]);
static void xgehrd_vbf45fhC_i(real_T a[16], real_T tau[3]);
static void xdlanv2_FIBA3SmX_b(real_T *a, real_T *b, real_T *c, real_T *d,
  real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn);
static void xrot_JzPltzlP_p(int32_T n, real_T x[16], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void xrot_DROkKeLU_e(int32_T n, real_T x[16], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void xrot_6iHri7if_n(real_T x[16], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static real_T xnrm2_hQNiN0t8_b(int32_T n, const real_T x[3]);
static real_T xzlarfg_J3AXVwxO_i(int32_T n, real_T *alpha1, real_T x[3]);
static int32_T eml_dlahqr_HClTWgbm_f(real_T h[16], real_T z[16]);
static void schur_hD1lAh31_m(const real_T A[16], real_T V[16], real_T T[16]);
static void linspace_dCtge7ie_l(real_T d1, real_T d2, real_T y[10]);
static void mrdivide_helper_JpwaVRMh_b(const real_T A[9], const real_T B_2[9],
  real_T y[9]);
static void Q_linearize_CKnbADMM_d(const real_T x[10], const real_T u[3], const
  real_T J[9], real_T A[100], real_T f[10]);
static void get_f_vals_Gr0pzuuC_l(real_T t, const real_T x[10], const real_T u[6],
  const real_T tspan[10], const real_T J[9], real_T f[10], real_T A[100], real_T
  Bp[30], real_T Bm[30], real_T Z[10]);
static void xgetrf_CjXcXVfl_i(real_T A[100], int32_T ipiv[10], int32_T *info);
static void mldivide_gjtSm7pm_e(const real_T A[100], real_T B_5[30]);
static void mldivide_JgAM3Jry_p(const real_T A[100], real_T B_6[10]);
static void deriv_CsN416wG_c(real_T t, const real_T X_1[190], const real_T u[6],
  const real_T tspan[10], real_T s, const real_T J[9], real_T DX[190]);
static void foh_OxYXiak1_m(const real_T X_0[100], const real_T U[30], real_T s,
  const real_T J[9], real_T EH[10000], real_T BE[3000], real_T ES[100], real_T
  AR[100]);
static void inv_v2jI2dX7_g(const real_T x[9], real_T y[9]);
static void kron_gzkpgh2R_c(const real_T A[100], const real_T B_3[30], real_T K
  [3000]);
static void kron_mrguWHGo_i(const real_T A[100], const real_T B_4[9], real_T K
  [900]);
static void parse_ecos_4lHXAQLu_p(const real_T xi[10], const real_T xf[7], const
  real_T J[9], const real_T EH[10000], const real_T BE[3000], const real_T ES
  [100], const real_T AR[100], const real_T ME[16], const real_T MI[16], real_T
  T_max, real_T w_max, real_T s_max, real_T s_min, real_T w_v, real_T c[332],
  real_T G[157368], real_T h[474], real_T A[38844], real_T b[117]);
static void my_find_pTqw9ctN_i(const real_T X_3[38844], int32_T Xir[1278],
  real_T Xpr[1278]);
static void convert_to_CCS_TWUhmVkC_j(const real_T X_2[38844], int32_T Xir[1278],
  int32_T Xjc[333], real_T Xpr[1278]);
static void my_find_gHak93YM_k(const real_T X_5[157368], int32_T Xir[834],
  real_T Xpr[834]);
static void convert_to_CCS_uvSSMF4Z_o(const real_T X_4[157368], int32_T Xir[834],
  int32_T Xjc[333], real_T Xpr[834]);

/* Output and update for Simulink Function: '<S438>/call to ECOS SOCP solver (compiled C function)' */
void run_ecos(int32_T rtu_n, int32_T rtu_m, int32_T rtu_p, int32_T rtu_l,
              int32_T rtu_ncones, const real_T rtu_c[332], const int32_T
              rtu_Gjc[333], const int32_T rtu_Gir[834], const real_T rtu_Gpr[834],
              const real_T rtu_h[474], const int32_T rtu_q[21], const int32_T
              rtu_Ajc[333], const int32_T rtu_Air[1278], const real_T rtu_Apr
              [1278], const real_T rtu_b[117], real_T rty_y[333])
{
  int32_T rtb_TmpSignalConversionAtnOutpo;
  int32_T rtb_TmpSignalConversionAtmOutpo;
  int32_T rtb_TmpSignalConversionAtpOutpo;
  int32_T rtb_TmpSignalConversionAtlOutpo;
  int32_T rtb_TmpSignalConversionAtncones;

  /* SignalConversion: '<S443>/TmpSignal ConversionAtAirOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtAirO_p[0], &rtu_Air[0], 1278U * sizeof
         (int32_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAtAprOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtAprO_m[0], &rtu_Apr[0], 1278U * sizeof
         (real_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAtGirOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtGirO_c[0], &rtu_Gir[0], 834U * sizeof
         (int32_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAtGprOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtGprO_c[0], &rtu_Gpr[0], 834U * sizeof
         (real_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAthOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAthOut_k[0], &rtu_h[0], 474U * sizeof
         (real_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAtnOutport1' */
  rtb_TmpSignalConversionAtnOutpo = rtu_n;

  /* SignalConversion: '<S443>/TmpSignal ConversionAtmOutport1' */
  rtb_TmpSignalConversionAtmOutpo = rtu_m;

  /* SignalConversion: '<S443>/TmpSignal ConversionAtpOutport1' */
  rtb_TmpSignalConversionAtpOutpo = rtu_p;

  /* SignalConversion: '<S443>/TmpSignal ConversionAtlOutport1' */
  rtb_TmpSignalConversionAtlOutpo = rtu_l;

  /* SignalConversion: '<S443>/TmpSignal ConversionAtnconesOutport1' */
  rtb_TmpSignalConversionAtncones = rtu_ncones;

  /* SignalConversion: '<S443>/TmpSignal ConversionAtcOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtcOut_c[0], &rtu_c[0], 332U * sizeof
         (real_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAtqOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtqOut_g[0], &rtu_q[0], 21U * sizeof
         (int32_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAtbOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtbOut_b[0], &rtu_b[0], 117U * sizeof
         (real_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAtGjcOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtGjcO_f[0], &rtu_Gjc[0], 333U * sizeof
         (int32_T));

  /* SignalConversion: '<S443>/TmpSignal ConversionAtAjcOutport1' */
  memcpy(&rtDW.rtb_TmpSignalConversionAtAjcO_g[0], &rtu_Ajc[0], 333U * sizeof
         (int32_T));

  /* S-Function (sfun_ecos): '<S443>/sfun_ecos' */
  callecos(rtb_TmpSignalConversionAtnOutpo, rtb_TmpSignalConversionAtmOutpo,
           rtb_TmpSignalConversionAtpOutpo, rtb_TmpSignalConversionAtlOutpo,
           rtb_TmpSignalConversionAtncones, (real_T*)
           &rtDW.rtb_TmpSignalConversionAtcOut_c[0], (int32_T*)
           &rtDW.rtb_TmpSignalConversionAtGjcO_f[0], (int32_T*)
           &rtDW.rtb_TmpSignalConversionAtGirO_c[0], (real_T*)
           &rtDW.rtb_TmpSignalConversionAtGprO_c[0], (real_T*)
           &rtDW.rtb_TmpSignalConversionAthOut_k[0], (int32_T*)
           &rtDW.rtb_TmpSignalConversionAtqOut_g[0], (int32_T*)
           &rtDW.rtb_TmpSignalConversionAtAjcO_g[0], (int32_T*)
           &rtDW.rtb_TmpSignalConversionAtAirO_p[0], (real_T*)
           &rtDW.rtb_TmpSignalConversionAtAprO_m[0], (real_T*)
           &rtDW.rtb_TmpSignalConversionAtbOut_b[0], &rtDW.sfun_ecos[0]);

  /* SignalConversion: '<S443>/TmpSignal ConversionAtyInport1' */
  memcpy(&rty_y[0], &rtDW.sfun_ecos[0], 333U * sizeof(real_T));
}

/* Function for MATLAB Function: '<S10>/target_gen' */
static real_T norm_2e9Xj4lM_g(const real_T x[3])
{
  real_T y;
  real_T t;
  rtDW.scale_j = 3.3121686421112381E-170;
  rtDW.absxk_h = fabs(x[0]);
  if (rtDW.absxk_h > 3.3121686421112381E-170) {
    y = 1.0;
    rtDW.scale_j = rtDW.absxk_h;
  } else {
    t = rtDW.absxk_h / 3.3121686421112381E-170;
    y = t * t;
  }

  rtDW.absxk_h = fabs(x[1]);
  if (rtDW.absxk_h > rtDW.scale_j) {
    t = rtDW.scale_j / rtDW.absxk_h;
    y = y * t * t + 1.0;
    rtDW.scale_j = rtDW.absxk_h;
  } else {
    t = rtDW.absxk_h / rtDW.scale_j;
    y += t * t;
  }

  rtDW.absxk_h = fabs(x[2]);
  if (rtDW.absxk_h > rtDW.scale_j) {
    t = rtDW.scale_j / rtDW.absxk_h;
    y = y * t * t + 1.0;
    rtDW.scale_j = rtDW.absxk_h;
  } else {
    t = rtDW.absxk_h / rtDW.scale_j;
    y += t * t;
  }

  return rtDW.scale_j * sqrt(y);
}

/* Function for MATLAB Function: '<S10>/target_gen' */
static void align_vecs_GEQPakmX_m(real_T Body1[3], real_T Inertial1[3], real_T
  Body2[3], real_T Inertial2[3], real_T C_cmd[9])
{
  int32_T i;
  int32_T i_0;
  int32_T C_cmd_tmp;
  int32_T C_cmd_tmp_0;
  rtDW.Body2 = norm_2e9Xj4lM_g(Body1);
  rtDW.Inertial2 = norm_2e9Xj4lM_g(Body2);
  Body1[0] /= rtDW.Body2;
  Body2[0] /= rtDW.Inertial2;
  Body1[1] /= rtDW.Body2;
  Body2[1] /= rtDW.Inertial2;
  rtDW.Body1_m = Body1[2] / rtDW.Body2;
  rtDW.Body2 = Body2[2] / rtDW.Inertial2;
  rtDW.Ytb[0] = Body1[1] * rtDW.Body2 - rtDW.Body1_m * Body2[1];
  rtDW.Ytb[1] = rtDW.Body1_m * Body2[0] - Body1[0] * rtDW.Body2;
  rtDW.Ytb[2] = Body1[0] * Body2[1] - Body1[1] * Body2[0];
  rtDW.Body2 = norm_2e9Xj4lM_g(rtDW.Ytb);
  rtDW.Ytb[0] /= rtDW.Body2;
  rtDW.Ytb[1] /= rtDW.Body2;
  rtDW.Ytb_c = rtDW.Ytb[2] / rtDW.Body2;
  rtDW.Ztb[0] = Body1[1] * rtDW.Ytb_c - rtDW.Body1_m * rtDW.Ytb[1];
  rtDW.Ztb[1] = rtDW.Body1_m * rtDW.Ytb[0] - Body1[0] * rtDW.Ytb_c;
  rtDW.Ztb[2] = Body1[0] * rtDW.Ytb[1] - Body1[1] * rtDW.Ytb[0];
  rtDW.Body2 = norm_2e9Xj4lM_g(rtDW.Ztb);
  rtDW.Inertial2 = norm_2e9Xj4lM_g(Inertial1);
  rtDW.Yti_m = norm_2e9Xj4lM_g(Inertial2);
  rtDW.Ztb[0] /= rtDW.Body2;
  Inertial1[0] /= rtDW.Inertial2;
  Inertial2[0] /= rtDW.Yti_m;
  rtDW.Ztb[1] /= rtDW.Body2;
  Inertial1[1] /= rtDW.Inertial2;
  Inertial2[1] /= rtDW.Yti_m;
  rtDW.Inertial1_m = Inertial1[2] / rtDW.Inertial2;
  rtDW.Inertial2 = Inertial2[2] / rtDW.Yti_m;
  rtDW.Yti[0] = Inertial1[1] * rtDW.Inertial2 - rtDW.Inertial1_m * Inertial2[1];
  rtDW.Yti[1] = rtDW.Inertial1_m * Inertial2[0] - Inertial1[0] * rtDW.Inertial2;
  rtDW.Yti[2] = Inertial1[0] * Inertial2[1] - Inertial1[1] * Inertial2[0];
  rtDW.Inertial2 = norm_2e9Xj4lM_g(rtDW.Yti);
  rtDW.Yti[0] /= rtDW.Inertial2;
  rtDW.Yti[1] /= rtDW.Inertial2;
  rtDW.Yti_m = rtDW.Yti[2] / rtDW.Inertial2;
  rtDW.Zti[0] = Inertial1[1] * rtDW.Yti_m - rtDW.Inertial1_m * rtDW.Yti[1];
  rtDW.Zti[1] = rtDW.Inertial1_m * rtDW.Yti[0] - Inertial1[0] * rtDW.Yti_m;
  rtDW.Zti[2] = Inertial1[0] * rtDW.Yti[1] - Inertial1[1] * rtDW.Yti[0];
  rtDW.Inertial2 = norm_2e9Xj4lM_g(rtDW.Zti);
  rtDW.Body1[0] = Body1[0];
  rtDW.Body1[3] = rtDW.Ytb[0];
  rtDW.Body1[6] = rtDW.Ztb[0];
  rtDW.Inertial1[0] = Inertial1[0];
  rtDW.Inertial1[1] = rtDW.Yti[0];
  rtDW.Inertial1[2] = rtDW.Zti[0] / rtDW.Inertial2;
  rtDW.Body1[1] = Body1[1];
  rtDW.Body1[4] = rtDW.Ytb[1];
  rtDW.Body1[7] = rtDW.Ztb[1];
  rtDW.Inertial1[3] = Inertial1[1];
  rtDW.Inertial1[4] = rtDW.Yti[1];
  rtDW.Inertial1[5] = rtDW.Zti[1] / rtDW.Inertial2;
  rtDW.Body1[2] = rtDW.Body1_m;
  rtDW.Body1[5] = rtDW.Ytb_c;
  rtDW.Body1[8] = rtDW.Ztb[2] / rtDW.Body2;
  rtDW.Inertial1[6] = rtDW.Inertial1_m;
  rtDW.Inertial1[7] = rtDW.Yti_m;
  rtDW.Inertial1[8] = rtDW.Zti[2] / rtDW.Inertial2;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      C_cmd_tmp = i + 3 * i_0;
      C_cmd[C_cmd_tmp] = 0.0;
      C_cmd_tmp_0 = 3 * i_0 + i;
      C_cmd[C_cmd_tmp] = C_cmd[C_cmd_tmp_0] + rtDW.Inertial1[3 * i_0] *
        rtDW.Body1[i];
      C_cmd[C_cmd_tmp] = rtDW.Inertial1[3 * i_0 + 1] * rtDW.Body1[i + 3] +
        C_cmd[C_cmd_tmp_0];
      C_cmd[C_cmd_tmp] = rtDW.Inertial1[3 * i_0 + 2] * rtDW.Body1[i + 6] +
        C_cmd[C_cmd_tmp_0];
    }
  }
}

/* Function for MATLAB Function: '<S437>/soar_INTERP' */
static void mldivide_FcIbHgdz_o(const real_T A[9], const real_T B_1[3], real_T
  Y[3])
{
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  memcpy(&rtDW.b_A_n[0], &A[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  rtDW.maxval_o = fabs(A[0]);
  rtDW.a21_n = fabs(A[1]);
  if (rtDW.a21_n > rtDW.maxval_o) {
    rtDW.maxval_o = rtDW.a21_n;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(A[2]) > rtDW.maxval_o) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  rtDW.b_A_n[r2] = A[r2] / A[r1];
  rtDW.b_A_n[r3] /= rtDW.b_A_n[r1];
  rtDW.b_A_n[3 + r2] -= rtDW.b_A_n[3 + r1] * rtDW.b_A_n[r2];
  rtDW.b_A_n[3 + r3] -= rtDW.b_A_n[3 + r1] * rtDW.b_A_n[r3];
  rtDW.b_A_n[6 + r2] -= rtDW.b_A_n[6 + r1] * rtDW.b_A_n[r2];
  rtDW.b_A_n[6 + r3] -= rtDW.b_A_n[6 + r1] * rtDW.b_A_n[r3];
  if (fabs(rtDW.b_A_n[3 + r3]) > fabs(rtDW.b_A_n[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  rtDW.b_A_n[3 + r3] /= rtDW.b_A_n[3 + r2];
  rtDW.b_A_n[6 + r3] -= rtDW.b_A_n[3 + r3] * rtDW.b_A_n[6 + r2];
  Y[1] = B_1[r2] - B_1[r1] * rtDW.b_A_n[r2];
  Y[2] = (B_1[r3] - B_1[r1] * rtDW.b_A_n[r3]) - rtDW.b_A_n[3 + r3] * Y[1];
  Y[2] /= rtDW.b_A_n[6 + r3];
  Y[0] = B_1[r1] - rtDW.b_A_n[6 + r1] * Y[2];
  Y[1] -= rtDW.b_A_n[6 + r2] * Y[2];
  Y[1] /= rtDW.b_A_n[3 + r2];
  Y[0] -= rtDW.b_A_n[3 + r1] * Y[1];
  Y[0] /= rtDW.b_A_n[r1];
}

/* Function for MATLAB Function: '<S437>/soar_INTERP' */
static void deriv_3jC2Hyd6_i(real_T t, const real_T x[10], const real_T u[30],
  const real_T ut[10], const real_T J[9], real_T dx[10])
{
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  int32_T mag_tmp;
  int32_T varargin_2_tmp;
  int32_T exitg1;
  rtDW.scale_n = 3.3121686421112381E-170;
  rtDW.absxk_i = fabs(x[0]);
  if (rtDW.absxk_i > 3.3121686421112381E-170) {
    rtDW.mag = 1.0;
    rtDW.scale_n = rtDW.absxk_i;
  } else {
    rtDW.b_t = rtDW.absxk_i / 3.3121686421112381E-170;
    rtDW.mag = rtDW.b_t * rtDW.b_t;
  }

  rtDW.absxk_i = fabs(x[1]);
  if (rtDW.absxk_i > rtDW.scale_n) {
    rtDW.b_t = rtDW.scale_n / rtDW.absxk_i;
    rtDW.mag = rtDW.mag * rtDW.b_t * rtDW.b_t + 1.0;
    rtDW.scale_n = rtDW.absxk_i;
  } else {
    rtDW.b_t = rtDW.absxk_i / rtDW.scale_n;
    rtDW.mag += rtDW.b_t * rtDW.b_t;
  }

  rtDW.absxk_i = fabs(x[2]);
  if (rtDW.absxk_i > rtDW.scale_n) {
    rtDW.b_t = rtDW.scale_n / rtDW.absxk_i;
    rtDW.mag = rtDW.mag * rtDW.b_t * rtDW.b_t + 1.0;
    rtDW.scale_n = rtDW.absxk_i;
  } else {
    rtDW.b_t = rtDW.absxk_i / rtDW.scale_n;
    rtDW.mag += rtDW.b_t * rtDW.b_t;
  }

  rtDW.absxk_i = fabs(x[3]);
  if (rtDW.absxk_i > rtDW.scale_n) {
    rtDW.b_t = rtDW.scale_n / rtDW.absxk_i;
    rtDW.mag = rtDW.mag * rtDW.b_t * rtDW.b_t + 1.0;
    rtDW.scale_n = rtDW.absxk_i;
  } else {
    rtDW.b_t = rtDW.absxk_i / rtDW.scale_n;
    rtDW.mag += rtDW.b_t * rtDW.b_t;
  }

  rtDW.mag = rtDW.scale_n * sqrt(rtDW.mag);
  if (rtDW.mag < 1.0E-5) {
    memset(&dx[0], 0, 10U * sizeof(real_T));
  } else {
    rtDW.q_b[0] = x[0] / rtDW.mag;
    rtDW.q_b[1] = x[1] / rtDW.mag;
    rtDW.q_b[2] = x[2] / rtDW.mag;
    rtDW.q_b[3] = x[3] / rtDW.mag;
    if (t > ut[9]) {
      rtDW.u_t[0] = 0.0;
      rtDW.u_t[1] = 0.0;
      rtDW.u_t[2] = 0.0;
    } else if (t < ut[0]) {
      rtDW.u_t[0] = 0.0;
      rtDW.u_t[1] = 0.0;
      rtDW.u_t[2] = 0.0;
    } else {
      for (rtDW.n_e = 0; rtDW.n_e < 3; rtDW.n_e++) {
        for (rtDW.offset = 0; rtDW.offset < 10; rtDW.offset++) {
          rtDW.varargin_2[rtDW.offset + 10 * rtDW.n_e] = u[3 * rtDW.offset +
            rtDW.n_e];
        }
      }

      memcpy(&rtDW.b_x_b[0], &ut[0], 10U * sizeof(real_T));
      rtDW.n_e = 0;
      do {
        exitg1 = 0;
        if (rtDW.n_e < 10) {
          if (rtIsNaN(ut[rtDW.n_e])) {
            exitg1 = 1;
          } else {
            rtDW.n_e++;
          }
        } else {
          if (ut[1] < ut[0]) {
            for (rtDW.n_e = 0; rtDW.n_e < 5; rtDW.n_e++) {
              rtDW.mag = rtDW.b_x_b[rtDW.n_e];
              rtDW.b_x_b[rtDW.n_e] = rtDW.b_x_b[9 - rtDW.n_e];
              rtDW.b_x_b[9 - rtDW.n_e] = rtDW.mag;
            }

            for (rtDW.n_e = 0; rtDW.n_e < 3; rtDW.n_e++) {
              rtDW.offset = rtDW.n_e * 10;
              for (rtDW.c_k_j = 0; rtDW.c_k_j < 5; rtDW.c_k_j++) {
                mag_tmp = rtDW.offset + rtDW.c_k_j;
                rtDW.mag = rtDW.varargin_2[mag_tmp];
                varargin_2_tmp = (rtDW.offset - rtDW.c_k_j) + 9;
                rtDW.varargin_2[mag_tmp] = rtDW.varargin_2[varargin_2_tmp];
                rtDW.varargin_2[varargin_2_tmp] = rtDW.mag;
              }
            }
          }

          rtDW.u_t[0] = (rtNaN);
          rtDW.u_t[1] = (rtNaN);
          rtDW.u_t[2] = (rtNaN);
          if (rtIsNaN(t)) {
            rtDW.u_t[0] = (rtNaN);
            rtDW.u_t[1] = (rtNaN);
            rtDW.u_t[2] = (rtNaN);
          } else {
            if ((!(t > rtDW.b_x_b[9])) && (!(t < rtDW.b_x_b[0]))) {
              rtDW.n_e = bsearch_s1bfmSFP(rtDW.b_x_b, t);
              rtDW.mag = rtDW.b_x_b[rtDW.n_e - 1];
              rtDW.mag = (t - rtDW.mag) / (rtDW.b_x_b[rtDW.n_e] - rtDW.mag);
              if (rtDW.mag == 0.0) {
                rtDW.u_t[0] = rtDW.varargin_2[rtDW.n_e - 1];
                rtDW.u_t[1] = rtDW.varargin_2[rtDW.n_e + 9];
                rtDW.u_t[2] = rtDW.varargin_2[rtDW.n_e + 19];
              } else if (rtDW.mag == 1.0) {
                rtDW.u_t[0] = rtDW.varargin_2[rtDW.n_e];
                rtDW.u_t[1] = rtDW.varargin_2[rtDW.n_e + 10];
                rtDW.u_t[2] = rtDW.varargin_2[rtDW.n_e + 20];
              } else {
                rtDW.scale_n = rtDW.varargin_2[rtDW.n_e - 1];
                if (rtDW.scale_n == rtDW.varargin_2[rtDW.n_e]) {
                  rtDW.u_t[0] = rtDW.scale_n;
                } else {
                  rtDW.u_t[0] = (1.0 - rtDW.mag) * rtDW.scale_n + rtDW.mag *
                    rtDW.varargin_2[rtDW.n_e];
                }

                rtDW.scale_n = rtDW.varargin_2[rtDW.n_e + 9];
                rtDW.absxk_i = rtDW.varargin_2[rtDW.n_e + 10];
                if (rtDW.scale_n == rtDW.absxk_i) {
                  rtDW.u_t[1] = rtDW.scale_n;
                } else {
                  rtDW.u_t[1] = (1.0 - rtDW.mag) * rtDW.scale_n + rtDW.mag *
                    rtDW.absxk_i;
                }

                rtDW.scale_n = rtDW.varargin_2[rtDW.n_e + 19];
                rtDW.absxk_i = rtDW.varargin_2[rtDW.n_e + 20];
                if (rtDW.scale_n == rtDW.absxk_i) {
                  rtDW.u_t[2] = rtDW.scale_n;
                } else {
                  rtDW.u_t[2] = (1.0 - rtDW.mag) * rtDW.scale_n + rtDW.mag *
                    rtDW.absxk_i;
                }
              }
            }
          }

          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    rtDW.dv10[0] = 0.0;
    rtDW.dv10[3] = -x[6];
    rtDW.dv10[6] = x[5];
    rtDW.dv10[1] = x[6];
    rtDW.dv10[4] = 0.0;
    rtDW.dv10[7] = -x[4];
    rtDW.dv10[2] = -x[5];
    rtDW.dv10[5] = x[4];
    rtDW.dv10[8] = 0.0;
    for (rtDW.n_e = 0; rtDW.n_e < 3; rtDW.n_e++) {
      rtDW.J_h[rtDW.n_e] = ((J[rtDW.n_e + 3] * x[5] + J[rtDW.n_e] * x[4]) +
                            J[rtDW.n_e + 6] * x[6]) + x[7 + rtDW.n_e];
    }

    for (rtDW.n_e = 0; rtDW.n_e < 3; rtDW.n_e++) {
      rtDW.u_t_l[rtDW.n_e] = -rtDW.u_t[rtDW.n_e] - ((rtDW.dv10[rtDW.n_e + 3] *
        rtDW.J_h[1] + rtDW.dv10[rtDW.n_e] * rtDW.J_h[0]) + rtDW.dv10[rtDW.n_e +
        6] * rtDW.J_h[2]);
    }

    mldivide_FcIbHgdz_o(J, rtDW.u_t_l, rtDW.J_h);
    rtDW.mag = rtDW.q_b[0];
    rtDW.dv10[0] = 0.0;
    rtDW.dv10[3] = -rtDW.q_b[3];
    rtDW.dv10[6] = rtDW.q_b[2];
    rtDW.dv10[1] = rtDW.q_b[3];
    rtDW.dv10[4] = 0.0;
    rtDW.dv10[7] = -rtDW.q_b[1];
    rtDW.dv10[2] = -rtDW.q_b[2];
    rtDW.dv10[5] = rtDW.q_b[1];
    rtDW.dv10[8] = 0.0;
    for (rtDW.n_e = 0; rtDW.n_e < 3; rtDW.n_e++) {
      rtDW.offset = rtDW.n_e << 2;
      rtDW.dv9[rtDW.offset] = -rtDW.q_b[1 + rtDW.n_e] * 0.5;
      rtDW.dv9[1 + rtDW.offset] = ((real_T)b[3 * rtDW.n_e] * rtDW.mag +
        rtDW.dv10[3 * rtDW.n_e]) * 0.5;
      rtDW.c_k_j = 3 * rtDW.n_e + 1;
      rtDW.dv9[2 + rtDW.offset] = ((real_T)b[rtDW.c_k_j] * rtDW.mag +
        rtDW.dv10[rtDW.c_k_j]) * 0.5;
      rtDW.c_k_j = 3 * rtDW.n_e + 2;
      rtDW.dv9[3 + rtDW.offset] = ((real_T)b[rtDW.c_k_j] * rtDW.mag +
        rtDW.dv10[rtDW.c_k_j]) * 0.5;
    }

    for (rtDW.n_e = 0; rtDW.n_e < 4; rtDW.n_e++) {
      dx[rtDW.n_e] = rtDW.dv9[rtDW.n_e + 8] * x[6] + (rtDW.dv9[rtDW.n_e + 4] *
        x[5] + rtDW.dv9[rtDW.n_e] * x[4]);
    }

    dx[4] = rtDW.J_h[0];
    dx[7] = rtDW.u_t[0];
    dx[5] = rtDW.J_h[1];
    dx[8] = rtDW.u_t[1];
    dx[6] = rtDW.J_h[2];
    dx[9] = rtDW.u_t[2];
  }
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static real_T xnrm2_ooZ215qV_d(int32_T n, const real_T x[16], int32_T ix0)
{
  real_T y;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      rtDW.scale_f = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > rtDW.scale_f) {
          t = rtDW.scale_f / absxk;
          y = y * t * t + 1.0;
          rtDW.scale_f = absxk;
        } else {
          t = absxk / rtDW.scale_f;
          y += t * t;
        }
      }

      y = rtDW.scale_f * sqrt(y);
    }
  }

  return y;
}

static real_T rt_hypotd_snf_h(real_T u0, real_T u1)
{
  real_T y;
  rtDW.a_p = fabs(u0);
  y = fabs(u1);
  if (rtDW.a_p < y) {
    rtDW.a_p /= y;
    y *= sqrt(rtDW.a_p * rtDW.a_p + 1.0);
  } else if (rtDW.a_p > y) {
    y /= rtDW.a_p;
    y = sqrt(y * y + 1.0) * rtDW.a_p;
  } else {
    if (!rtIsNaN(y)) {
      y = rtDW.a_p * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static void xzlarf_tQsI3TnT_j(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[16], int32_T ic0, real_T work[4])
{
  int32_T coltop;
  int32_T ix;
  int32_T iac;
  int32_T d;
  int32_T b_ia;
  int32_T jy;
  int32_T exitg1;
  boolean_T exitg2;
  if (tau != 0.0) {
    rtDW.lastv = m;
    rtDW.lastc = iv0 + m;
    while ((rtDW.lastv > 0) && (C[rtDW.lastc - 2] == 0.0)) {
      rtDW.lastv--;
      rtDW.lastc--;
    }

    rtDW.lastc = n - 1;
    exitg2 = false;
    while ((!exitg2) && (rtDW.lastc + 1 > 0)) {
      coltop = (rtDW.lastc << 2) + ic0;
      jy = coltop;
      do {
        exitg1 = 0;
        if (jy <= (coltop + rtDW.lastv) - 1) {
          if (C[jy - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jy++;
          }
        } else {
          rtDW.lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    rtDW.lastv = 0;
    rtDW.lastc = -1;
  }

  if (rtDW.lastv > 0) {
    if (rtDW.lastc + 1 != 0) {
      for (coltop = 0; coltop <= rtDW.lastc; coltop++) {
        work[coltop] = 0.0;
      }

      coltop = 0;
      jy = (rtDW.lastc << 2) + ic0;
      for (iac = ic0; iac <= jy; iac += 4) {
        ix = iv0;
        rtDW.c_a = 0.0;
        d = (iac + rtDW.lastv) - 1;
        for (b_ia = iac; b_ia <= d; b_ia++) {
          rtDW.c_a += C[b_ia - 1] * C[ix - 1];
          ix++;
        }

        work[coltop] += rtDW.c_a;
        coltop++;
      }
    }

    if (!(-tau == 0.0)) {
      coltop = ic0 - 1;
      jy = 0;
      for (iac = 0; iac <= rtDW.lastc; iac++) {
        if (work[jy] != 0.0) {
          rtDW.c_a = work[jy] * -tau;
          ix = iv0;
          d = rtDW.lastv + coltop;
          for (b_ia = coltop; b_ia < d; b_ia++) {
            C[b_ia] += C[ix - 1] * rtDW.c_a;
            ix++;
          }
        }

        jy++;
        coltop += 4;
      }
    }
  }
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static void xgehrd_vbf45fhC_i(real_T a[16], real_T tau[3])
{
  int32_T exitg1;
  boolean_T exitg2;
  rtDW.work_b[0] = 0.0;
  rtDW.work_b[1] = 0.0;
  rtDW.work_b[2] = 0.0;
  rtDW.work_b[3] = 0.0;
  rtDW.ia0 = 3;
  rtDW.alpha1 = a[1];
  rtDW.temp_p = 0.0;
  rtDW.xnorm = xnrm2_ooZ215qV_d(2, a, 3);
  if (rtDW.xnorm != 0.0) {
    rtDW.xnorm = rt_hypotd_snf_h(a[1], rtDW.xnorm);
    if (a[1] >= 0.0) {
      rtDW.xnorm = -rtDW.xnorm;
    }

    if (fabs(rtDW.xnorm) < 1.0020841800044864E-292) {
      rtDW.knt = -1;
      do {
        rtDW.knt++;
        rtDW.rowleft = 3;
        while (rtDW.rowleft <= 4) {
          a[rtDW.rowleft - 1] *= 9.9792015476736E+291;
          rtDW.rowleft++;
        }

        rtDW.xnorm *= 9.9792015476736E+291;
        rtDW.alpha1 *= 9.9792015476736E+291;
      } while (!(fabs(rtDW.xnorm) >= 1.0020841800044864E-292));

      rtDW.xnorm = rt_hypotd_snf_h(rtDW.alpha1, xnrm2_ooZ215qV_d(2, a, 3));
      if (rtDW.alpha1 >= 0.0) {
        rtDW.xnorm = -rtDW.xnorm;
      }

      rtDW.temp_p = (rtDW.xnorm - rtDW.alpha1) / rtDW.xnorm;
      rtDW.alpha1 = 1.0 / (rtDW.alpha1 - rtDW.xnorm);
      while (rtDW.ia0 <= 4) {
        a[rtDW.ia0 - 1] *= rtDW.alpha1;
        rtDW.ia0++;
      }

      rtDW.ia0 = 0;
      while (rtDW.ia0 <= rtDW.knt) {
        rtDW.xnorm *= 1.0020841800044864E-292;
        rtDW.ia0++;
      }

      rtDW.alpha1 = rtDW.xnorm;
    } else {
      rtDW.temp_p = (rtDW.xnorm - a[1]) / rtDW.xnorm;
      rtDW.alpha1 = 1.0 / (a[1] - rtDW.xnorm);
      while (rtDW.ia0 <= 4) {
        a[rtDW.ia0 - 1] *= rtDW.alpha1;
        rtDW.ia0++;
      }

      rtDW.alpha1 = rtDW.xnorm;
    }
  }

  tau[0] = rtDW.temp_p;
  a[1] = 1.0;
  rtDW.jy = 1;
  if (rtDW.temp_p != 0.0) {
    rtDW.knt = 2;
    rtDW.ia0 = 3;
    while ((rtDW.knt + 1 > 0) && (a[rtDW.ia0] == 0.0)) {
      rtDW.knt--;
      rtDW.ia0--;
    }

    rtDW.ia0 = 4;
    exitg2 = false;
    while ((!exitg2) && (rtDW.ia0 > 0)) {
      rtDW.rowleft = 4 + rtDW.ia0;
      rtDW.ia = rtDW.rowleft;
      do {
        exitg1 = 0;
        if (rtDW.ia <= (rtDW.knt << 2) + rtDW.rowleft) {
          if (a[rtDW.ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            rtDW.ia += 4;
          }
        } else {
          rtDW.ia0--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    rtDW.knt = -1;
    rtDW.ia0 = 0;
  }

  if (rtDW.knt + 1 > 0) {
    if (rtDW.ia0 != 0) {
      rtDW.rowleft = 0;
      while (rtDW.rowleft <= rtDW.ia0 - 1) {
        rtDW.work_b[rtDW.rowleft] = 0.0;
        rtDW.rowleft++;
      }

      rtDW.rowleft = 1;
      rtDW.ia = (rtDW.knt << 2) + 5;
      rtDW.b_ix = 5;
      while (rtDW.b_ix <= rtDW.ia) {
        rtDW.iy = 0;
        rtDW.g = (rtDW.b_ix + rtDW.ia0) - 1;
        rtDW.b_ia = rtDW.b_ix;
        while (rtDW.b_ia <= rtDW.g) {
          rtDW.work_b[rtDW.iy] += a[rtDW.b_ia - 1] * a[rtDW.rowleft];
          rtDW.iy++;
          rtDW.b_ia++;
        }

        rtDW.rowleft++;
        rtDW.b_ix += 4;
      }
    }

    if (!(-rtDW.temp_p == 0.0)) {
      rtDW.rowleft = 4;
      rtDW.ia = 0;
      while (rtDW.ia <= rtDW.knt) {
        if (a[rtDW.jy] != 0.0) {
          rtDW.temp_p = a[rtDW.jy] * -tau[0];
          rtDW.b_ix = 0;
          rtDW.iy = rtDW.ia0 + rtDW.rowleft;
          rtDW.g = rtDW.rowleft;
          while (rtDW.g + 1 <= rtDW.iy) {
            a[rtDW.g] += rtDW.work_b[rtDW.b_ix] * rtDW.temp_p;
            rtDW.b_ix++;
            rtDW.g++;
          }
        }

        rtDW.jy++;
        rtDW.rowleft += 4;
        rtDW.ia++;
      }
    }
  }

  xzlarf_tQsI3TnT_j(3, 3, 2, tau[0], a, 6, rtDW.work_b);
  a[1] = rtDW.alpha1;
  rtDW.alpha1 = a[6];
  rtDW.temp_p = 0.0;
  rtDW.xnorm = xnrm2_ooZ215qV_d(1, a, 8);
  if (rtDW.xnorm != 0.0) {
    rtDW.xnorm = rt_hypotd_snf_h(a[6], rtDW.xnorm);
    if (a[6] >= 0.0) {
      rtDW.xnorm = -rtDW.xnorm;
    }

    if (fabs(rtDW.xnorm) < 1.0020841800044864E-292) {
      rtDW.knt = -1;
      do {
        rtDW.knt++;
        a[7] *= 9.9792015476736E+291;
        rtDW.xnorm *= 9.9792015476736E+291;
        rtDW.alpha1 *= 9.9792015476736E+291;
      } while (!(fabs(rtDW.xnorm) >= 1.0020841800044864E-292));

      rtDW.xnorm = rt_hypotd_snf_h(rtDW.alpha1, xnrm2_ooZ215qV_d(1, a, 8));
      if (rtDW.alpha1 >= 0.0) {
        rtDW.xnorm = -rtDW.xnorm;
      }

      rtDW.temp_p = (rtDW.xnorm - rtDW.alpha1) / rtDW.xnorm;
      rtDW.alpha1 = 1.0 / (rtDW.alpha1 - rtDW.xnorm);
      a[7] *= rtDW.alpha1;
      rtDW.ia0 = 0;
      while (rtDW.ia0 <= rtDW.knt) {
        rtDW.xnorm *= 1.0020841800044864E-292;
        rtDW.ia0++;
      }

      rtDW.alpha1 = rtDW.xnorm;
    } else {
      rtDW.temp_p = (rtDW.xnorm - a[6]) / rtDW.xnorm;
      a[7] *= 1.0 / (a[6] - rtDW.xnorm);
      rtDW.alpha1 = rtDW.xnorm;
    }
  }

  tau[1] = rtDW.temp_p;
  a[6] = 1.0;
  rtDW.jy = 6;
  if (rtDW.temp_p != 0.0) {
    rtDW.knt = 1;
    rtDW.ia0 = 7;
    while ((rtDW.knt + 1 > 0) && (a[rtDW.ia0] == 0.0)) {
      rtDW.knt--;
      rtDW.ia0--;
    }

    rtDW.ia0 = 4;
    exitg2 = false;
    while ((!exitg2) && (rtDW.ia0 > 0)) {
      rtDW.rowleft = 8 + rtDW.ia0;
      rtDW.ia = rtDW.rowleft;
      do {
        exitg1 = 0;
        if (rtDW.ia <= (rtDW.knt << 2) + rtDW.rowleft) {
          if (a[rtDW.ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            rtDW.ia += 4;
          }
        } else {
          rtDW.ia0--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    rtDW.knt = -1;
    rtDW.ia0 = 0;
  }

  if (rtDW.knt + 1 > 0) {
    if (rtDW.ia0 != 0) {
      rtDW.rowleft = 0;
      while (rtDW.rowleft <= rtDW.ia0 - 1) {
        rtDW.work_b[rtDW.rowleft] = 0.0;
        rtDW.rowleft++;
      }

      rtDW.rowleft = 6;
      rtDW.ia = (rtDW.knt << 2) + 9;
      rtDW.b_ix = 9;
      while (rtDW.b_ix <= rtDW.ia) {
        rtDW.iy = 0;
        rtDW.g = (rtDW.b_ix + rtDW.ia0) - 1;
        rtDW.b_ia = rtDW.b_ix;
        while (rtDW.b_ia <= rtDW.g) {
          rtDW.work_b[rtDW.iy] += a[rtDW.b_ia - 1] * a[rtDW.rowleft];
          rtDW.iy++;
          rtDW.b_ia++;
        }

        rtDW.rowleft++;
        rtDW.b_ix += 4;
      }
    }

    if (!(-rtDW.temp_p == 0.0)) {
      rtDW.rowleft = 8;
      rtDW.ia = 0;
      while (rtDW.ia <= rtDW.knt) {
        if (a[rtDW.jy] != 0.0) {
          rtDW.temp_p = a[rtDW.jy] * -tau[1];
          rtDW.b_ix = 0;
          rtDW.iy = rtDW.ia0 + rtDW.rowleft;
          rtDW.g = rtDW.rowleft;
          while (rtDW.g + 1 <= rtDW.iy) {
            a[rtDW.g] += rtDW.work_b[rtDW.b_ix] * rtDW.temp_p;
            rtDW.b_ix++;
            rtDW.g++;
          }
        }

        rtDW.jy++;
        rtDW.rowleft += 4;
        rtDW.ia++;
      }
    }
  }

  xzlarf_tQsI3TnT_j(2, 2, 7, tau[1], a, 11, rtDW.work_b);
  a[6] = rtDW.alpha1;
  rtDW.alpha1 = a[11];
  rtDW.temp_p = 0.0;
  rtDW.xnorm_tmp = xnrm2_ooZ215qV_d(0, a, 12);
  if (rtDW.xnorm_tmp != 0.0) {
    rtDW.xnorm = rt_hypotd_snf_h(a[11], rtDW.xnorm_tmp);
    if (a[11] >= 0.0) {
      rtDW.xnorm = -rtDW.xnorm;
    }

    if (fabs(rtDW.xnorm) < 1.0020841800044864E-292) {
      rtDW.knt = -1;
      do {
        rtDW.knt++;
        rtDW.xnorm *= 9.9792015476736E+291;
        rtDW.alpha1 *= 9.9792015476736E+291;
      } while (!(fabs(rtDW.xnorm) >= 1.0020841800044864E-292));

      rtDW.xnorm = rt_hypotd_snf_h(rtDW.alpha1, rtDW.xnorm_tmp);
      if (rtDW.alpha1 >= 0.0) {
        rtDW.xnorm = -rtDW.xnorm;
      }

      rtDW.temp_p = (rtDW.xnorm - rtDW.alpha1) / rtDW.xnorm;
      rtDW.ia0 = 0;
      while (rtDW.ia0 <= rtDW.knt) {
        rtDW.xnorm *= 1.0020841800044864E-292;
        rtDW.ia0++;
      }

      rtDW.alpha1 = rtDW.xnorm;
    } else {
      rtDW.temp_p = (rtDW.xnorm - a[11]) / rtDW.xnorm;
      rtDW.alpha1 = rtDW.xnorm;
    }
  }

  tau[2] = rtDW.temp_p;
  a[11] = 1.0;
  rtDW.jy = 11;
  if (rtDW.temp_p != 0.0) {
    rtDW.knt = 0;
    rtDW.ia0 = 11;
    while ((rtDW.knt + 1 > 0) && (a[rtDW.ia0] == 0.0)) {
      rtDW.knt--;
      rtDW.ia0--;
    }

    rtDW.ia0 = 4;
    exitg2 = false;
    while ((!exitg2) && (rtDW.ia0 > 0)) {
      rtDW.rowleft = 12 + rtDW.ia0;
      rtDW.ia = rtDW.rowleft;
      do {
        exitg1 = 0;
        if (rtDW.ia <= (rtDW.knt << 2) + rtDW.rowleft) {
          if (a[rtDW.ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            rtDW.ia += 4;
          }
        } else {
          rtDW.ia0--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    rtDW.knt = -1;
    rtDW.ia0 = 0;
  }

  if (rtDW.knt + 1 > 0) {
    if (rtDW.ia0 != 0) {
      rtDW.rowleft = 0;
      while (rtDW.rowleft <= rtDW.ia0 - 1) {
        rtDW.work_b[rtDW.rowleft] = 0.0;
        rtDW.rowleft++;
      }

      rtDW.rowleft = 11;
      rtDW.ia = (rtDW.knt << 2) + 13;
      rtDW.b_ix = 13;
      while (rtDW.b_ix <= rtDW.ia) {
        rtDW.iy = 0;
        rtDW.g = (rtDW.b_ix + rtDW.ia0) - 1;
        rtDW.b_ia = rtDW.b_ix;
        while (rtDW.b_ia <= rtDW.g) {
          rtDW.work_b[rtDW.iy] += a[rtDW.b_ia - 1] * a[rtDW.rowleft];
          rtDW.iy++;
          rtDW.b_ia++;
        }

        rtDW.rowleft++;
        rtDW.b_ix += 4;
      }
    }

    if (!(-rtDW.temp_p == 0.0)) {
      rtDW.rowleft = 12;
      rtDW.ia = 0;
      while (rtDW.ia <= rtDW.knt) {
        if (a[rtDW.jy] != 0.0) {
          rtDW.temp_p = a[rtDW.jy] * -tau[2];
          rtDW.b_ix = 0;
          rtDW.iy = rtDW.ia0 + rtDW.rowleft;
          rtDW.g = rtDW.rowleft;
          while (rtDW.g + 1 <= rtDW.iy) {
            a[rtDW.g] += rtDW.work_b[rtDW.b_ix] * rtDW.temp_p;
            rtDW.b_ix++;
            rtDW.g++;
          }
        }

        rtDW.jy++;
        rtDW.rowleft += 4;
        rtDW.ia++;
      }
    }
  }

  xzlarf_tQsI3TnT_j(1, 1, 12, tau[2], a, 16, rtDW.work_b);
  a[11] = rtDW.alpha1;
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static void xdlanv2_FIBA3SmX_b(real_T *a, real_T *b, real_T *c, real_T *d,
  real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn)
{
  int32_T b_0;
  int32_T c_0;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    rtDW.temp_c = *d;
    *d = *a;
    *a = rtDW.temp_c;
    *b = -*c;
    *c = 0.0;
  } else {
    rtDW.temp_c = *a - *d;
    if ((rtDW.temp_c == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      rtDW.p = 0.5 * rtDW.temp_c;
      rtDW.bcmis = fabs(*b);
      rtDW.z = fabs(*c);
      if ((rtDW.bcmis > rtDW.z) || rtIsNaN(rtDW.z)) {
        rtDW.bcmax = rtDW.bcmis;
      } else {
        rtDW.bcmax = rtDW.z;
      }

      if ((rtDW.bcmis < rtDW.z) || rtIsNaN(rtDW.z)) {
        rtDW.z = rtDW.bcmis;
      }

      if (!(*b < 0.0)) {
        b_0 = 1;
      } else {
        b_0 = -1;
      }

      if (!(*c < 0.0)) {
        c_0 = 1;
      } else {
        c_0 = -1;
      }

      rtDW.bcmis = rtDW.z * (real_T)b_0 * (real_T)c_0;
      rtDW.scale_c = fabs(rtDW.p);
      if ((!(rtDW.scale_c > rtDW.bcmax)) && (!rtIsNaN(rtDW.bcmax))) {
        rtDW.scale_c = rtDW.bcmax;
      }

      rtDW.z = rtDW.p / rtDW.scale_c * rtDW.p + rtDW.bcmax / rtDW.scale_c *
        rtDW.bcmis;
      if (rtDW.z >= 8.8817841970012523E-16) {
        if (!(rtDW.p < 0.0)) {
          rtDW.z = sqrt(rtDW.scale_c) * sqrt(rtDW.z);
        } else {
          rtDW.z = -(sqrt(rtDW.scale_c) * sqrt(rtDW.z));
        }

        rtDW.z += rtDW.p;
        *a = *d + rtDW.z;
        *d -= rtDW.bcmax / rtDW.z * rtDW.bcmis;
        rtDW.bcmax = rt_hypotd_snf_h(*c, rtDW.z);
        *cs = rtDW.z / rtDW.bcmax;
        *sn = *c / rtDW.bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        rtDW.bcmis = *b + *c;
        rtDW.bcmax = rt_hypotd_snf_h(rtDW.bcmis, rtDW.temp_c);
        *cs = sqrt((fabs(rtDW.bcmis) / rtDW.bcmax + 1.0) * 0.5);
        if (!(rtDW.bcmis < 0.0)) {
          b_0 = 1;
        } else {
          b_0 = -1;
        }

        *sn = -(rtDW.p / (rtDW.bcmax * *cs)) * (real_T)b_0;
        rtDW.temp_c = *a * *cs + *b * *sn;
        rtDW.p = -*a * *sn + *b * *cs;
        rtDW.bcmax = *c * *cs + *d * *sn;
        rtDW.bcmis = -*c * *sn + *d * *cs;
        *b = rtDW.p * *cs + rtDW.bcmis * *sn;
        *c = -rtDW.temp_c * *sn + rtDW.bcmax * *cs;
        rtDW.temp_c = ((rtDW.temp_c * *cs + rtDW.bcmax * *sn) + (-rtDW.p * *sn +
          rtDW.bcmis * *cs)) * 0.5;
        *a = rtDW.temp_c;
        *d = rtDW.temp_c;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              rtDW.z = sqrt(fabs(*b));
              rtDW.bcmis = sqrt(fabs(*c));
              rtDW.p = rtDW.z * rtDW.bcmis;
              if (*c < 0.0) {
                rtDW.p = -rtDW.p;
              }

              rtDW.bcmax = 1.0 / sqrt(fabs(*b + *c));
              *a = rtDW.temp_c + rtDW.p;
              *d = rtDW.temp_c - rtDW.p;
              *b -= *c;
              *c = 0.0;
              rtDW.p = rtDW.z * rtDW.bcmax;
              rtDW.bcmax *= rtDW.bcmis;
              rtDW.temp_c = *cs * rtDW.p - *sn * rtDW.bcmax;
              *sn = *cs * rtDW.bcmax + *sn * rtDW.p;
              *cs = rtDW.temp_c;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            rtDW.temp_c = *cs;
            *cs = -*sn;
            *sn = rtDW.temp_c;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static void xrot_JzPltzlP_p(int32_T n, real_T x[16], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      rtDW.temp_i = c * x[ix] + s * x[iy];
      x[iy] = c * x[iy] - s * x[ix];
      x[ix] = rtDW.temp_i;
      iy += 4;
      ix += 4;
    }
  }
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static void xrot_DROkKeLU_e(int32_T n, real_T x[16], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      rtDW.temp_o2 = c * x[ix] + s * x[iy];
      x[iy] = c * x[iy] - s * x[ix];
      x[ix] = rtDW.temp_o2;
      iy++;
      ix++;
    }
  }
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static void xrot_6iHri7if_n(real_T x[16], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  int32_T ix;
  int32_T iy;
  ix = ix0 - 1;
  iy = iy0 - 1;
  rtDW.temp_f = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = rtDW.temp_f;
  iy++;
  ix++;
  rtDW.temp_f = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = rtDW.temp_f;
  iy++;
  ix++;
  rtDW.temp_f = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = rtDW.temp_f;
  iy++;
  ix++;
  rtDW.temp_f = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = rtDW.temp_f;
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static real_T xnrm2_hQNiN0t8_b(int32_T n, const real_T x[3])
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[1]);
    } else {
      rtDW.scale_a = 3.3121686421112381E-170;
      for (k = 2; k <= 1 + n; k++) {
        rtDW.absxk_a = fabs(x[k - 1]);
        if (rtDW.absxk_a > rtDW.scale_a) {
          rtDW.t_i = rtDW.scale_a / rtDW.absxk_a;
          y = y * rtDW.t_i * rtDW.t_i + 1.0;
          rtDW.scale_a = rtDW.absxk_a;
        } else {
          rtDW.t_i = rtDW.absxk_a / rtDW.scale_a;
          y += rtDW.t_i * rtDW.t_i;
        }
      }

      y = rtDW.scale_a * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static real_T xzlarfg_J3AXVwxO_i(int32_T n, real_T *alpha1, real_T x[3])
{
  real_T tau;
  int32_T knt;
  int32_T c_k;
  tau = 0.0;
  if (n > 0) {
    rtDW.xnorm_e = xnrm2_hQNiN0t8_b(n - 1, x);
    if (rtDW.xnorm_e != 0.0) {
      rtDW.xnorm_e = rt_hypotd_snf_h(*alpha1, rtDW.xnorm_e);
      if (*alpha1 >= 0.0) {
        rtDW.xnorm_e = -rtDW.xnorm_e;
      }

      if (fabs(rtDW.xnorm_e) < 1.0020841800044864E-292) {
        knt = -1;
        do {
          knt++;
          for (c_k = 1; c_k < n; c_k++) {
            x[c_k] *= 9.9792015476736E+291;
          }

          rtDW.xnorm_e *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(rtDW.xnorm_e) >= 1.0020841800044864E-292));

        rtDW.xnorm_e = rt_hypotd_snf_h(*alpha1, xnrm2_hQNiN0t8_b(n - 1, x));
        if (*alpha1 >= 0.0) {
          rtDW.xnorm_e = -rtDW.xnorm_e;
        }

        tau = (rtDW.xnorm_e - *alpha1) / rtDW.xnorm_e;
        *alpha1 = 1.0 / (*alpha1 - rtDW.xnorm_e);
        for (c_k = 1; c_k < n; c_k++) {
          x[c_k] *= *alpha1;
        }

        for (c_k = 0; c_k <= knt; c_k++) {
          rtDW.xnorm_e *= 1.0020841800044864E-292;
        }

        *alpha1 = rtDW.xnorm_e;
      } else {
        tau = (rtDW.xnorm_e - *alpha1) / rtDW.xnorm_e;
        *alpha1 = 1.0 / (*alpha1 - rtDW.xnorm_e);
        for (knt = 1; knt < n; knt++) {
          x[knt] *= *alpha1;
        }

        *alpha1 = rtDW.xnorm_e;
      }
    }
  }

  return tau;
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static int32_T eml_dlahqr_HClTWgbm_f(real_T h[16], real_T z[16])
{
  int32_T info;
  boolean_T goto150;
  int32_T h12_tmp;
  int32_T h12_tmp_tmp;
  int32_T h12_tmp_tmp_0;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  info = 0;
  rtDW.v[0] = 0.0;
  rtDW.v[1] = 0.0;
  rtDW.v[2] = 0.0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[7] = 0.0;
  rtDW.i_o = 3;
  exitg1 = false;
  while ((!exitg1) && (rtDW.i_o + 1 >= 1)) {
    rtDW.L = 1;
    goto150 = false;
    rtDW.its = 0;
    exitg2 = false;
    while ((!exitg2) && (rtDW.its < 301)) {
      rtDW.k_b = rtDW.i_o;
      exitg3 = false;
      while ((!exitg3) && (rtDW.k_b + 1 > rtDW.L)) {
        rtDW.hoffset = ((rtDW.k_b - 1) << 2) + rtDW.k_b;
        rtDW.ba = fabs(h[rtDW.hoffset]);
        if (rtDW.ba <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          rtDW.tst_tmp_g = (rtDW.k_b << 2) + rtDW.k_b;
          rtDW.htmp1 = fabs(h[rtDW.tst_tmp_g]);
          rtDW.tst_tmp = h[rtDW.hoffset - 1];
          rtDW.tst = fabs(rtDW.tst_tmp) + rtDW.htmp1;
          if (rtDW.tst == 0.0) {
            if (rtDW.k_b - 1 >= 1) {
              rtDW.tst = fabs(h[(((rtDW.k_b - 2) << 2) + rtDW.k_b) - 1]);
            }

            if (rtDW.k_b + 2 <= 4) {
              rtDW.tst += fabs(h[rtDW.tst_tmp_g + 1]);
            }
          }

          if (rtDW.ba <= 2.2204460492503131E-16 * rtDW.tst) {
            rtDW.tst = fabs(h[rtDW.tst_tmp_g - 1]);
            if (rtDW.ba > rtDW.tst) {
              rtDW.ab = rtDW.ba;
              rtDW.ba = rtDW.tst;
            } else {
              rtDW.ab = rtDW.tst;
            }

            rtDW.tst = fabs(rtDW.tst_tmp - h[(rtDW.k_b << 2) + rtDW.k_b]);
            if (rtDW.htmp1 > rtDW.tst) {
              rtDW.aa = rtDW.htmp1;
              rtDW.htmp1 = rtDW.tst;
            } else {
              rtDW.aa = rtDW.tst;
            }

            rtDW.tst = rtDW.aa + rtDW.ab;
            rtDW.htmp1 = rtDW.aa / rtDW.tst * rtDW.htmp1 *
              2.2204460492503131E-16;
            if ((4.0083367200179456E-292 > rtDW.htmp1) || rtIsNaN(rtDW.htmp1)) {
              rtDW.htmp1 = 4.0083367200179456E-292;
            }

            if (rtDW.ab / rtDW.tst * rtDW.ba <= rtDW.htmp1) {
              exitg3 = true;
            } else {
              rtDW.k_b--;
            }
          } else {
            rtDW.k_b--;
          }
        }
      }

      rtDW.L = rtDW.k_b + 1;
      if (rtDW.k_b + 1 > 1) {
        h[rtDW.k_b + ((rtDW.k_b - 1) << 2)] = 0.0;
      }

      if (rtDW.k_b + 1 >= rtDW.i_o) {
        goto150 = true;
        exitg2 = true;
      } else {
        switch (rtDW.its) {
         case 10:
          rtDW.tst = fabs(h[(((rtDW.k_b + 1) << 2) + rtDW.k_b) + 2]) + fabs(h
            [((rtDW.k_b << 2) + rtDW.k_b) + 1]);
          rtDW.ba = h[(rtDW.k_b << 2) + rtDW.k_b] + 0.75 * rtDW.tst;
          rtDW.h12 = -0.4375 * rtDW.tst;
          rtDW.aa = rtDW.tst;
          rtDW.htmp1 = rtDW.ba;
          break;

         case 20:
          rtDW.tst = fabs(h[(((rtDW.i_o - 2) << 2) + rtDW.i_o) - 1]) + fabs(h
            [((rtDW.i_o - 1) << 2) + rtDW.i_o]);
          rtDW.ba = h[(rtDW.i_o << 2) + rtDW.i_o] + 0.75 * rtDW.tst;
          rtDW.h12 = -0.4375 * rtDW.tst;
          rtDW.aa = rtDW.tst;
          rtDW.htmp1 = rtDW.ba;
          break;

         default:
          rtDW.m = ((rtDW.i_o - 1) << 2) + rtDW.i_o;
          rtDW.ba = h[rtDW.m - 1];
          rtDW.aa = h[rtDW.m];
          h12_tmp = (rtDW.i_o << 2) + rtDW.i_o;
          rtDW.h12 = h[h12_tmp - 1];
          rtDW.htmp1 = h[h12_tmp];
          break;
        }

        rtDW.tst = ((fabs(rtDW.ba) + fabs(rtDW.h12)) + fabs(rtDW.aa)) + fabs
          (rtDW.htmp1);
        if (rtDW.tst == 0.0) {
          rtDW.ba = 0.0;
          rtDW.htmp1 = 0.0;
          rtDW.ab = 0.0;
          rtDW.aa = 0.0;
        } else {
          rtDW.ba /= rtDW.tst;
          rtDW.aa /= rtDW.tst;
          rtDW.h12 /= rtDW.tst;
          rtDW.htmp1 /= rtDW.tst;
          rtDW.ab = (rtDW.ba + rtDW.htmp1) / 2.0;
          rtDW.ba = (rtDW.ba - rtDW.ab) * (rtDW.htmp1 - rtDW.ab) - rtDW.h12 *
            rtDW.aa;
          rtDW.aa = sqrt(fabs(rtDW.ba));
          if (rtDW.ba >= 0.0) {
            rtDW.ba = rtDW.ab * rtDW.tst;
            rtDW.ab = rtDW.ba;
            rtDW.htmp1 = rtDW.aa * rtDW.tst;
            rtDW.aa = -rtDW.htmp1;
          } else {
            rtDW.ba = rtDW.ab + rtDW.aa;
            rtDW.ab -= rtDW.aa;
            if (fabs(rtDW.ba - rtDW.htmp1) <= fabs(rtDW.ab - rtDW.htmp1)) {
              rtDW.ba *= rtDW.tst;
              rtDW.ab = rtDW.ba;
            } else {
              rtDW.ab *= rtDW.tst;
              rtDW.ba = rtDW.ab;
            }

            rtDW.htmp1 = 0.0;
            rtDW.aa = 0.0;
          }
        }

        rtDW.m = rtDW.i_o - 1;
        exitg3 = false;
        while ((!exitg3) && (rtDW.m >= rtDW.k_b + 1)) {
          rtDW.tst_tmp_g = ((rtDW.m - 1) << 2) + rtDW.m;
          rtDW.tst_tmp_tmp = h[rtDW.tst_tmp_g - 1];
          rtDW.tst_tmp = rtDW.tst_tmp_tmp - rtDW.ab;
          rtDW.tst = (fabs(rtDW.tst_tmp) + fabs(rtDW.aa)) + fabs
            (h[rtDW.tst_tmp_g]);
          rtDW.h12 = h[((rtDW.m - 1) << 2) + rtDW.m] / rtDW.tst;
          rtDW.tst_tmp_g = (rtDW.m << 2) + rtDW.m;
          rtDW.v[0] = (rtDW.tst_tmp / rtDW.tst * (rtDW.tst_tmp_tmp - rtDW.ba) +
                       h[rtDW.tst_tmp_g - 1] * rtDW.h12) - rtDW.aa / rtDW.tst *
            rtDW.htmp1;
          rtDW.v[1] = (((rtDW.tst_tmp_tmp + h[rtDW.tst_tmp_g]) - rtDW.ba) -
                       rtDW.ab) * rtDW.h12;
          rtDW.v[2] = h[rtDW.tst_tmp_g + 1] * rtDW.h12;
          rtDW.tst = (fabs(rtDW.v[0]) + fabs(rtDW.v[1])) + fabs(rtDW.v[2]);
          rtDW.v[0] /= rtDW.tst;
          rtDW.v[1] /= rtDW.tst;
          rtDW.v[2] /= rtDW.tst;
          if (rtDW.k_b + 1 == rtDW.m) {
            exitg3 = true;
          } else {
            rtDW.hoffset = ((rtDW.m - 2) << 2) + rtDW.m;
            if (fabs(h[rtDW.hoffset - 1]) * (fabs(rtDW.v[1]) + fabs(rtDW.v[2])) <=
                ((fabs(h[rtDW.hoffset - 2]) + fabs(rtDW.tst_tmp_tmp)) + fabs(h
                  [(rtDW.m << 2) + rtDW.m])) * (2.2204460492503131E-16 * fabs
                 (rtDW.v[0]))) {
              exitg3 = true;
            } else {
              rtDW.m--;
            }
          }
        }

        rtDW.tst_tmp_g = rtDW.m;
        while (rtDW.tst_tmp_g <= rtDW.i_o) {
          rtDW.nr = (rtDW.i_o - rtDW.tst_tmp_g) + 2;
          if (3 < rtDW.nr) {
            rtDW.nr = 3;
          }

          if (rtDW.tst_tmp_g > rtDW.m) {
            h12_tmp = (((rtDW.tst_tmp_g - 2) << 2) + rtDW.tst_tmp_g) - 1;
            rtDW.j_a = 0;
            while (rtDW.j_a <= rtDW.nr - 1) {
              rtDW.v[rtDW.j_a] = h[rtDW.j_a + h12_tmp];
              rtDW.j_a++;
            }
          }

          rtDW.htmp1 = rtDW.v[0];
          rtDW.b_v[0] = rtDW.v[0];
          rtDW.b_v[1] = rtDW.v[1];
          rtDW.b_v[2] = rtDW.v[2];
          rtDW.tst = xzlarfg_J3AXVwxO_i(rtDW.nr, &rtDW.htmp1, rtDW.b_v);
          rtDW.v[1] = rtDW.b_v[1];
          rtDW.v[2] = rtDW.b_v[2];
          rtDW.v[0] = rtDW.htmp1;
          if (rtDW.tst_tmp_g > rtDW.m) {
            h[(rtDW.tst_tmp_g + ((rtDW.tst_tmp_g - 2) << 2)) - 1] = rtDW.htmp1;
            h[rtDW.tst_tmp_g + ((rtDW.tst_tmp_g - 2) << 2)] = 0.0;
            if (rtDW.tst_tmp_g < rtDW.i_o) {
              h[(rtDW.tst_tmp_g + ((rtDW.tst_tmp_g - 2) << 2)) + 1] = 0.0;
            }
          } else {
            if (rtDW.m > rtDW.k_b + 1) {
              h[(rtDW.tst_tmp_g + ((rtDW.tst_tmp_g - 2) << 2)) - 1] *= 1.0 -
                rtDW.tst;
            }
          }

          rtDW.htmp1 = rtDW.b_v[1];
          rtDW.ab = rtDW.tst * rtDW.b_v[1];
          switch (rtDW.nr) {
           case 3:
            rtDW.ba = rtDW.b_v[2];
            rtDW.aa = rtDW.tst * rtDW.b_v[2];
            rtDW.nr = rtDW.tst_tmp_g - 1;
            while (rtDW.nr + 1 < 5) {
              rtDW.hoffset = rtDW.nr << 2;
              h12_tmp = rtDW.hoffset + rtDW.tst_tmp_g;
              rtDW.j_a = h12_tmp - 1;
              h12_tmp_tmp = h12_tmp + 1;
              rtDW.h12 = (h[rtDW.j_a] + h[h12_tmp] * rtDW.htmp1) + h[h12_tmp_tmp]
                * rtDW.ba;
              rtDW.hoffset += rtDW.tst_tmp_g;
              h[rtDW.hoffset - 1] = h[rtDW.j_a] - rtDW.h12 * rtDW.tst;
              h[rtDW.hoffset] = h[h12_tmp] - rtDW.h12 * rtDW.ab;
              h[rtDW.hoffset + 1] = h[h12_tmp_tmp] - rtDW.h12 * rtDW.aa;
              rtDW.nr++;
            }

            h12_tmp = rtDW.tst_tmp_g + 3;
            rtDW.nr = rtDW.i_o + 1;
            if (h12_tmp < rtDW.nr) {
              rtDW.nr = h12_tmp;
            }

            rtDW.hoffset = 0;
            while (rtDW.hoffset <= rtDW.nr - 1) {
              rtDW.tst_tmp = h[((rtDW.tst_tmp_g - 1) << 2) + rtDW.hoffset];
              h12_tmp = (rtDW.tst_tmp_g << 2) + rtDW.hoffset;
              rtDW.j_a = ((rtDW.tst_tmp_g + 1) << 2) + rtDW.hoffset;
              rtDW.h12 = (rtDW.tst_tmp + h[h12_tmp] * rtDW.htmp1) + h[rtDW.j_a] *
                rtDW.ba;
              h[rtDW.hoffset + ((rtDW.tst_tmp_g - 1) << 2)] = rtDW.tst_tmp -
                rtDW.h12 * rtDW.tst;
              h[rtDW.hoffset + (rtDW.tst_tmp_g << 2)] = h[h12_tmp] - rtDW.h12 *
                rtDW.ab;
              h[rtDW.hoffset + ((rtDW.tst_tmp_g + 1) << 2)] = h[rtDW.j_a] -
                rtDW.h12 * rtDW.aa;
              rtDW.hoffset++;
            }

            for (rtDW.nr = 0; rtDW.nr < 4; rtDW.nr++) {
              rtDW.hoffset = (rtDW.tst_tmp_g - 1) << 2;
              rtDW.tst_tmp = z[rtDW.hoffset + rtDW.nr];
              h12_tmp_tmp = rtDW.tst_tmp_g << 2;
              h12_tmp = h12_tmp_tmp + rtDW.nr;
              h12_tmp_tmp_0 = (rtDW.tst_tmp_g + 1) << 2;
              rtDW.j_a = h12_tmp_tmp_0 + rtDW.nr;
              rtDW.h12 = (rtDW.tst_tmp + z[h12_tmp] * rtDW.htmp1) + z[rtDW.j_a] *
                rtDW.ba;
              z[rtDW.nr + rtDW.hoffset] = rtDW.tst_tmp - rtDW.h12 * rtDW.tst;
              z[rtDW.nr + h12_tmp_tmp] = z[h12_tmp] - rtDW.h12 * rtDW.ab;
              z[rtDW.nr + h12_tmp_tmp_0] = z[rtDW.j_a] - rtDW.h12 * rtDW.aa;
            }
            break;

           case 2:
            rtDW.nr = rtDW.tst_tmp_g - 1;
            while (rtDW.nr + 1 < 5) {
              rtDW.hoffset = rtDW.nr << 2;
              h12_tmp = rtDW.hoffset + rtDW.tst_tmp_g;
              rtDW.j_a = h12_tmp - 1;
              rtDW.h12 = h[rtDW.j_a] + h[h12_tmp] * rtDW.htmp1;
              rtDW.hoffset += rtDW.tst_tmp_g;
              h[rtDW.hoffset - 1] = h[rtDW.j_a] - rtDW.h12 * rtDW.tst;
              h[rtDW.hoffset] = h[h12_tmp] - rtDW.h12 * rtDW.ab;
              rtDW.nr++;
            }

            rtDW.nr = 0;
            while (rtDW.nr <= rtDW.i_o) {
              rtDW.h12 = h[((rtDW.tst_tmp_g - 1) << 2) + rtDW.nr] + h
                [(rtDW.tst_tmp_g << 2) + rtDW.nr] * rtDW.htmp1;
              h[rtDW.nr + ((rtDW.tst_tmp_g - 1) << 2)] -= rtDW.h12 * rtDW.tst;
              h[rtDW.nr + (rtDW.tst_tmp_g << 2)] -= rtDW.h12 * rtDW.ab;
              rtDW.nr++;
            }

            for (rtDW.nr = 0; rtDW.nr < 4; rtDW.nr++) {
              h12_tmp = ((rtDW.tst_tmp_g - 1) << 2) + rtDW.nr;
              rtDW.j_a = (rtDW.tst_tmp_g << 2) + rtDW.nr;
              rtDW.h12 = z[h12_tmp] + z[rtDW.j_a] * rtDW.htmp1;
              z[rtDW.nr + ((rtDW.tst_tmp_g - 1) << 2)] = z[h12_tmp] - rtDW.h12 *
                rtDW.tst;
              z[rtDW.nr + (rtDW.tst_tmp_g << 2)] = z[rtDW.j_a] - rtDW.h12 *
                rtDW.ab;
            }
            break;
          }

          rtDW.tst_tmp_g++;
        }

        rtDW.its++;
      }
    }

    if (!goto150) {
      info = rtDW.i_o + 1;
      exitg1 = true;
    } else {
      if ((rtDW.i_o + 1 != rtDW.L) && (rtDW.L == rtDW.i_o)) {
        rtDW.tst = h[(((rtDW.i_o - 1) << 2) + rtDW.i_o) - 1];
        rtDW.htmp1 = h[((rtDW.i_o << 2) + rtDW.i_o) - 1];
        rtDW.ab = h[((rtDW.i_o - 1) << 2) + rtDW.i_o];
        rtDW.ba = h[(rtDW.i_o << 2) + rtDW.i_o];
        xdlanv2_FIBA3SmX_b(&rtDW.tst, &rtDW.htmp1, &rtDW.ab, &rtDW.ba, &rtDW.aa,
                           &rtDW.h12, &rtDW.tst_tmp, &rtDW.tst_tmp_tmp, &rtDW.cs,
                           &rtDW.sn);
        rtDW.hoffset = rtDW.i_o + ((rtDW.i_o - 1) << 2);
        h[rtDW.hoffset - 1] = rtDW.tst;
        rtDW.its = rtDW.i_o + (rtDW.i_o << 2);
        h[rtDW.its - 1] = rtDW.htmp1;
        h[rtDW.hoffset] = rtDW.ab;
        h[rtDW.its] = rtDW.ba;
        if (4 > rtDW.i_o + 1) {
          xrot_JzPltzlP_p(3 - rtDW.i_o, h, rtDW.i_o + ((rtDW.i_o + 1) << 2),
                          (rtDW.i_o + ((rtDW.i_o + 1) << 2)) + 1, rtDW.cs,
                          rtDW.sn);
        }

        xrot_DROkKeLU_e(rtDW.i_o - 1, h, 1 + ((rtDW.i_o - 1) << 2), 1 +
                        (rtDW.i_o << 2), rtDW.cs, rtDW.sn);
        xrot_6iHri7if_n(z, 1 + ((rtDW.i_o - 1) << 2), 1 + (rtDW.i_o << 2),
                        rtDW.cs, rtDW.sn);
      }

      rtDW.i_o = rtDW.L - 2;
    }
  }

  return info;
}

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
static void schur_hD1lAh31_m(const real_T A[16], real_T V[16], real_T T[16])
{
  boolean_T p;
  p = true;
  for (rtDW.itau = 0; rtDW.itau < 16; rtDW.itau++) {
    p = (p && ((!rtIsInf(A[rtDW.itau])) && (!rtIsNaN(A[rtDW.itau]))));
  }

  if (!p) {
    for (rtDW.itau = 0; rtDW.itau < 16; rtDW.itau++) {
      V[rtDW.itau] = (rtNaN);
    }

    rtDW.itau = 2;
    while (rtDW.itau < 5) {
      V[rtDW.itau - 1] = 0.0;
      rtDW.itau++;
    }

    rtDW.itau = 3;
    while (rtDW.itau < 5) {
      V[rtDW.itau + 3] = 0.0;
      rtDW.itau++;
    }

    V[11] = 0.0;
    for (rtDW.itau = 0; rtDW.itau < 16; rtDW.itau++) {
      T[rtDW.itau] = (rtNaN);
    }
  } else {
    memcpy(&T[0], &A[0], sizeof(real_T) << 4U);
    xgehrd_vbf45fhC_i(T, rtDW.tau);
    memcpy(&V[0], &T[0], sizeof(real_T) << 4U);
    rtDW.itau = 0;
    while (rtDW.itau <= 2) {
      V[12 + rtDW.itau] = 0.0;
      rtDW.itau++;
    }

    rtDW.itau = 0;
    while (rtDW.itau <= 1) {
      V[8 + rtDW.itau] = 0.0;
      rtDW.itau++;
    }

    rtDW.itau = 1;
    while (rtDW.itau + 3 <= 4) {
      V[rtDW.itau + 10] = V[rtDW.itau + 6];
      rtDW.itau++;
    }

    V[4] = 0.0;
    rtDW.itau = 0;
    while (rtDW.itau + 3 <= 4) {
      V[rtDW.itau + 6] = V[rtDW.itau + 2];
      rtDW.itau++;
    }

    rtDW.work[0] = 0.0;
    V[1] = 0.0;
    rtDW.work[1] = 0.0;
    V[2] = 0.0;
    rtDW.work[2] = 0.0;
    V[3] = 0.0;
    rtDW.work[3] = 0.0;
    V[0] = 1.0;
    V[15] = 1.0 - rtDW.tau[2];
    rtDW.itau = 0;
    while (rtDW.itau <= 1) {
      V[14 - rtDW.itau] = 0.0;
      rtDW.itau++;
    }

    V[10] = 1.0;
    xzlarf_tQsI3TnT_j(2, 1, 11, rtDW.tau[1], V, 15, rtDW.work);
    rtDW.itau = 11;
    while (rtDW.itau + 1 <= 12) {
      V[rtDW.itau] *= -rtDW.tau[1];
      rtDW.itau++;
    }

    V[10] = 1.0 - rtDW.tau[1];
    V[9] = 0.0;
    V[5] = 1.0;
    xzlarf_tQsI3TnT_j(3, 2, 6, rtDW.tau[0], V, 10, rtDW.work);
    rtDW.itau = 6;
    while (rtDW.itau + 1 <= 8) {
      V[rtDW.itau] *= -rtDW.tau[0];
      rtDW.itau++;
    }

    V[5] = 1.0 - rtDW.tau[0];
    eml_dlahqr_HClTWgbm_f(T, V);
    T[3] = 0.0;
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void linspace_dCtge7ie_l(real_T d1, real_T d2, real_T y[10])
{
  real_T delta2;
  int32_T b_k;
  y[9] = d2;
  y[0] = d1;
  if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307) ||
       (fabs(d2) > 8.9884656743115785E+307))) {
    rtDW.delta1 = d1 / 9.0;
    delta2 = d2 / 9.0;
    for (b_k = 0; b_k < 8; b_k++) {
      y[b_k + 1] = ((1.0 + (real_T)b_k) * delta2 + d1) - (1.0 + (real_T)b_k) *
        rtDW.delta1;
    }
  } else {
    rtDW.delta1 = (d2 - d1) / 9.0;
    for (b_k = 0; b_k < 8; b_k++) {
      y[b_k + 1] = (1.0 + (real_T)b_k) * rtDW.delta1 + d1;
    }
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void mrdivide_helper_JpwaVRMh_b(const real_T A[9], const real_T B_2[9],
  real_T y[9])
{
  int32_T y_tmp;
  int32_T y_tmp_0;
  int32_T y_tmp_1;
  int32_T y_tmp_2;
  memcpy(&rtDW.b_A_g[0], &B_2[0], 9U * sizeof(real_T));
  rtDW.r1_h = 0;
  rtDW.r2_l = 1;
  rtDW.r3_h = 2;
  rtDW.maxval_j = fabs(B_2[0]);
  rtDW.a21 = fabs(B_2[1]);
  if (rtDW.a21 > rtDW.maxval_j) {
    rtDW.maxval_j = rtDW.a21;
    rtDW.r1_h = 1;
    rtDW.r2_l = 0;
  }

  if (fabs(B_2[2]) > rtDW.maxval_j) {
    rtDW.r1_h = 2;
    rtDW.r2_l = 1;
    rtDW.r3_h = 0;
  }

  rtDW.b_A_g[rtDW.r2_l] = B_2[rtDW.r2_l] / B_2[rtDW.r1_h];
  rtDW.b_A_g[rtDW.r3_h] /= rtDW.b_A_g[rtDW.r1_h];
  rtDW.b_A_g[3 + rtDW.r2_l] -= rtDW.b_A_g[3 + rtDW.r1_h] * rtDW.b_A_g[rtDW.r2_l];
  rtDW.b_A_g[3 + rtDW.r3_h] -= rtDW.b_A_g[3 + rtDW.r1_h] * rtDW.b_A_g[rtDW.r3_h];
  rtDW.b_A_g[6 + rtDW.r2_l] -= rtDW.b_A_g[6 + rtDW.r1_h] * rtDW.b_A_g[rtDW.r2_l];
  rtDW.b_A_g[6 + rtDW.r3_h] -= rtDW.b_A_g[6 + rtDW.r1_h] * rtDW.b_A_g[rtDW.r3_h];
  if (fabs(rtDW.b_A_g[3 + rtDW.r3_h]) > fabs(rtDW.b_A_g[3 + rtDW.r2_l])) {
    rtDW.rtemp_m = rtDW.r2_l;
    rtDW.r2_l = rtDW.r3_h;
    rtDW.r3_h = rtDW.rtemp_m;
  }

  rtDW.b_A_g[3 + rtDW.r3_h] /= rtDW.b_A_g[3 + rtDW.r2_l];
  rtDW.b_A_g[6 + rtDW.r3_h] -= rtDW.b_A_g[3 + rtDW.r3_h] * rtDW.b_A_g[6 +
    rtDW.r2_l];
  y[3 * rtDW.r1_h] = A[0] / rtDW.b_A_g[rtDW.r1_h];
  rtDW.maxval_j = rtDW.b_A_g[3 + rtDW.r1_h];
  y[3 * rtDW.r2_l] = A[3] - y[3 * rtDW.r1_h] * rtDW.maxval_j;
  rtDW.a21 = rtDW.b_A_g[6 + rtDW.r1_h];
  y[3 * rtDW.r3_h] = A[6] - y[3 * rtDW.r1_h] * rtDW.a21;
  rtDW.y_tmp = rtDW.b_A_g[3 + rtDW.r2_l];
  y[3 * rtDW.r2_l] /= rtDW.y_tmp;
  rtDW.y_tmp_f = rtDW.b_A_g[6 + rtDW.r2_l];
  y[3 * rtDW.r3_h] -= y[3 * rtDW.r2_l] * rtDW.y_tmp_f;
  rtDW.y_tmp_a = rtDW.b_A_g[6 + rtDW.r3_h];
  y[3 * rtDW.r3_h] /= rtDW.y_tmp_a;
  rtDW.y_tmp_j = rtDW.b_A_g[3 + rtDW.r3_h];
  y[3 * rtDW.r2_l] -= y[3 * rtDW.r3_h] * rtDW.y_tmp_j;
  y[3 * rtDW.r1_h] -= y[3 * rtDW.r3_h] * rtDW.b_A_g[rtDW.r3_h];
  y[3 * rtDW.r1_h] -= y[3 * rtDW.r2_l] * rtDW.b_A_g[rtDW.r2_l];
  rtDW.rtemp_m = 1 + 3 * rtDW.r1_h;
  y[rtDW.rtemp_m] = A[1] / rtDW.b_A_g[rtDW.r1_h];
  rtDW.y_tmp_m = 3 * rtDW.r1_h + 1;
  y_tmp = 1 + 3 * rtDW.r2_l;
  y[y_tmp] = A[4] - y[rtDW.y_tmp_m] * rtDW.maxval_j;
  y_tmp_1 = 1 + 3 * rtDW.r3_h;
  y[y_tmp_1] = A[7] - y[rtDW.y_tmp_m] * rtDW.a21;
  y_tmp_0 = 3 * rtDW.r2_l + 1;
  y[y_tmp] = y[y_tmp_0] / rtDW.y_tmp;
  y_tmp_2 = 3 * rtDW.r3_h + 1;
  y[y_tmp_1] = y[y_tmp_2] - y[y_tmp_0] * rtDW.y_tmp_f;
  y[y_tmp_1] = y[y_tmp_2] / rtDW.y_tmp_a;
  y[y_tmp] = y[y_tmp_0] - y[y_tmp_2] * rtDW.y_tmp_j;
  y[rtDW.rtemp_m] = y[rtDW.y_tmp_m] - y[y_tmp_2] * rtDW.b_A_g[rtDW.r3_h];
  y[rtDW.rtemp_m] = y[rtDW.y_tmp_m] - y[y_tmp_0] * rtDW.b_A_g[rtDW.r2_l];
  rtDW.rtemp_m = 2 + 3 * rtDW.r1_h;
  y[rtDW.rtemp_m] = A[2] / rtDW.b_A_g[rtDW.r1_h];
  rtDW.y_tmp_m = 3 * rtDW.r1_h + 2;
  y_tmp = 2 + 3 * rtDW.r2_l;
  y[y_tmp] = A[5] - y[rtDW.y_tmp_m] * rtDW.maxval_j;
  y_tmp_1 = 2 + 3 * rtDW.r3_h;
  y[y_tmp_1] = A[8] - y[rtDW.y_tmp_m] * rtDW.a21;
  y_tmp_0 = 3 * rtDW.r2_l + 2;
  y[y_tmp] = y[y_tmp_0] / rtDW.y_tmp;
  y_tmp_2 = 3 * rtDW.r3_h + 2;
  y[y_tmp_1] = y[y_tmp_2] - y[y_tmp_0] * rtDW.y_tmp_f;
  y[y_tmp_1] = y[y_tmp_2] / rtDW.y_tmp_a;
  y[y_tmp] = y[y_tmp_0] - y[y_tmp_2] * rtDW.y_tmp_j;
  y[rtDW.rtemp_m] = y[rtDW.y_tmp_m] - y[y_tmp_2] * rtDW.b_A_g[rtDW.r3_h];
  y[rtDW.rtemp_m] = y[rtDW.y_tmp_m] - y[y_tmp_0] * rtDW.b_A_g[rtDW.r2_l];
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void Q_linearize_CKnbADMM_d(const real_T x[10], const real_T u[3], const
  real_T J[9], real_T A[100], real_T f[10])
{
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  rtDW.scale = 3.3121686421112381E-170;
  rtDW.absxk = fabs(x[0]);
  if (rtDW.absxk > 3.3121686421112381E-170) {
    rtDW.maxval = 1.0;
    rtDW.scale = rtDW.absxk;
  } else {
    rtDW.t_e = rtDW.absxk / 3.3121686421112381E-170;
    rtDW.maxval = rtDW.t_e * rtDW.t_e;
  }

  rtDW.absxk = fabs(x[1]);
  if (rtDW.absxk > rtDW.scale) {
    rtDW.t_e = rtDW.scale / rtDW.absxk;
    rtDW.maxval = rtDW.maxval * rtDW.t_e * rtDW.t_e + 1.0;
    rtDW.scale = rtDW.absxk;
  } else {
    rtDW.t_e = rtDW.absxk / rtDW.scale;
    rtDW.maxval += rtDW.t_e * rtDW.t_e;
  }

  rtDW.absxk = fabs(x[2]);
  if (rtDW.absxk > rtDW.scale) {
    rtDW.t_e = rtDW.scale / rtDW.absxk;
    rtDW.maxval = rtDW.maxval * rtDW.t_e * rtDW.t_e + 1.0;
    rtDW.scale = rtDW.absxk;
  } else {
    rtDW.t_e = rtDW.absxk / rtDW.scale;
    rtDW.maxval += rtDW.t_e * rtDW.t_e;
  }

  rtDW.absxk = fabs(x[3]);
  if (rtDW.absxk > rtDW.scale) {
    rtDW.t_e = rtDW.scale / rtDW.absxk;
    rtDW.maxval = rtDW.maxval * rtDW.t_e * rtDW.t_e + 1.0;
    rtDW.scale = rtDW.absxk;
  } else {
    rtDW.t_e = rtDW.absxk / rtDW.scale;
    rtDW.maxval += rtDW.t_e * rtDW.t_e;
  }

  rtDW.maxval = rtDW.scale * sqrt(rtDW.maxval);
  rtDW.q[0] = x[0] / rtDW.maxval;
  rtDW.q[1] = x[1] / rtDW.maxval;
  rtDW.q[2] = x[2] / rtDW.maxval;
  rtDW.q[3] = x[3] / rtDW.maxval;
  memcpy(&rtDW.b_A[0], &J[0], 9U * sizeof(real_T));
  rtDW.r1 = 0;
  rtDW.r2 = 1;
  rtDW.r3 = 2;
  rtDW.scale = fabs(J[0]);
  rtDW.maxval = rtDW.scale;
  rtDW.absxk = fabs(J[1]);
  if (rtDW.absxk > rtDW.scale) {
    rtDW.maxval = rtDW.absxk;
    rtDW.r1 = 1;
    rtDW.r2 = 0;
  }

  rtDW.t_e = fabs(J[2]);
  if (rtDW.t_e > rtDW.maxval) {
    rtDW.r1 = 2;
    rtDW.r2 = 1;
    rtDW.r3 = 0;
  }

  rtDW.b_A[rtDW.r2] = J[rtDW.r2] / J[rtDW.r1];
  rtDW.b_A[rtDW.r3] /= rtDW.b_A[rtDW.r1];
  rtDW.b_A[3 + rtDW.r2] -= rtDW.b_A[3 + rtDW.r1] * rtDW.b_A[rtDW.r2];
  rtDW.b_A[3 + rtDW.r3] -= rtDW.b_A[3 + rtDW.r1] * rtDW.b_A[rtDW.r3];
  rtDW.b_A[6 + rtDW.r2] -= rtDW.b_A[6 + rtDW.r1] * rtDW.b_A[rtDW.r2];
  rtDW.b_A[6 + rtDW.r3] -= rtDW.b_A[6 + rtDW.r1] * rtDW.b_A[rtDW.r3];
  if (fabs(rtDW.b_A[3 + rtDW.r3]) > fabs(rtDW.b_A[3 + rtDW.r2])) {
    rtDW.rtemp = rtDW.r2;
    rtDW.r2 = rtDW.r3;
    rtDW.r3 = rtDW.rtemp;
  }

  rtDW.b_A[3 + rtDW.r3] /= rtDW.b_A[3 + rtDW.r2];
  rtDW.b_A[6 + rtDW.r3] -= rtDW.b_A[3 + rtDW.r3] * rtDW.b_A[6 + rtDW.r2];
  rtDW.maxval = x[4 + rtDW.r1];
  rtDW.w[1] = x[4 + rtDW.r2] - rtDW.maxval * rtDW.b_A[rtDW.r2];
  rtDW.w[2] = (x[4 + rtDW.r3] - rtDW.maxval * rtDW.b_A[rtDW.r3]) - rtDW.b_A[3 +
    rtDW.r3] * rtDW.w[1];
  rtDW.w[2] /= rtDW.b_A[6 + rtDW.r3];
  rtDW.w[0] = rtDW.maxval - rtDW.b_A[6 + rtDW.r1] * rtDW.w[2];
  rtDW.w[1] -= rtDW.b_A[6 + rtDW.r2] * rtDW.w[2];
  rtDW.w[1] /= rtDW.b_A[3 + rtDW.r2];
  rtDW.w[0] -= rtDW.b_A[3 + rtDW.r1] * rtDW.w[1];
  rtDW.w[0] /= rtDW.b_A[rtDW.r1];
  rtDW.maxval = rtDW.q[0];
  rtDW.b_A[0] = 0.0;
  rtDW.b_A[3] = -rtDW.q[3];
  rtDW.b_A[6] = rtDW.q[2];
  rtDW.b_A[1] = rtDW.q[3];
  rtDW.b_A[4] = 0.0;
  rtDW.b_A[7] = -rtDW.q[1];
  rtDW.b_A[2] = -rtDW.q[2];
  rtDW.b_A[5] = rtDW.q[1];
  rtDW.b_A[8] = 0.0;
  for (rtDW.r1 = 0; rtDW.r1 < 3; rtDW.r1++) {
    rtDW.r2 = rtDW.r1 << 2;
    rtDW.b_y_tmp[rtDW.r2] = -rtDW.q[1 + rtDW.r1] * 0.5;
    rtDW.b_y_tmp[1 + rtDW.r2] = ((real_T)b[3 * rtDW.r1] * rtDW.maxval +
      rtDW.b_A[3 * rtDW.r1]) * 0.5;
    rtDW.r3 = 3 * rtDW.r1 + 1;
    rtDW.b_y_tmp[2 + rtDW.r2] = ((real_T)b[rtDW.r3] * rtDW.maxval +
      rtDW.b_A[rtDW.r3]) * 0.5;
    rtDW.r3 = 3 * rtDW.r1 + 2;
    rtDW.b_y_tmp[3 + rtDW.r2] = ((real_T)b[rtDW.r3] * rtDW.maxval +
      rtDW.b_A[rtDW.r3]) * 0.5;
  }

  memcpy(&rtDW.b_A[0], &J[0], 9U * sizeof(real_T));
  rtDW.r1 = 0;
  rtDW.r2 = 1;
  rtDW.r3 = 2;
  rtDW.maxval = rtDW.scale;
  if (rtDW.absxk > rtDW.scale) {
    rtDW.maxval = rtDW.absxk;
    rtDW.r1 = 1;
    rtDW.r2 = 0;
  }

  if (rtDW.t_e > rtDW.maxval) {
    rtDW.r1 = 2;
    rtDW.r2 = 1;
    rtDW.r3 = 0;
  }

  rtDW.b_A[rtDW.r2] = J[rtDW.r2] / J[rtDW.r1];
  rtDW.b_A[rtDW.r3] /= rtDW.b_A[rtDW.r1];
  rtDW.b_A[3 + rtDW.r2] -= rtDW.b_A[3 + rtDW.r1] * rtDW.b_A[rtDW.r2];
  rtDW.b_A[3 + rtDW.r3] -= rtDW.b_A[3 + rtDW.r1] * rtDW.b_A[rtDW.r3];
  rtDW.b_A[6 + rtDW.r2] -= rtDW.b_A[6 + rtDW.r1] * rtDW.b_A[rtDW.r2];
  rtDW.b_A[6 + rtDW.r3] -= rtDW.b_A[6 + rtDW.r1] * rtDW.b_A[rtDW.r3];
  if (fabs(rtDW.b_A[3 + rtDW.r3]) > fabs(rtDW.b_A[3 + rtDW.r2])) {
    rtDW.rtemp = rtDW.r2;
    rtDW.r2 = rtDW.r3;
    rtDW.r3 = rtDW.rtemp;
  }

  rtDW.b_A[3 + rtDW.r3] /= rtDW.b_A[3 + rtDW.r2];
  rtDW.b_A[6 + rtDW.r3] -= rtDW.b_A[3 + rtDW.r3] * rtDW.b_A[6 + rtDW.r2];
  rtDW.rtemp = rtDW.r1 << 2;
  rtDW.dfq_dhb[rtDW.rtemp] = rtDW.b_y_tmp[0] / rtDW.b_A[rtDW.r1];
  rtDW.dfq_dhb_tmp_l = rtDW.r2 << 2;
  rtDW.maxval = rtDW.b_A[3 + rtDW.r1];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] = rtDW.b_y_tmp[4] - rtDW.dfq_dhb[rtDW.rtemp] *
    rtDW.maxval;
  rtDW.dfq_dhb_tmp_m = rtDW.r3 << 2;
  rtDW.scale = rtDW.b_A[6 + rtDW.r1];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] = rtDW.b_y_tmp[8] - rtDW.dfq_dhb[rtDW.rtemp] *
    rtDW.scale;
  rtDW.absxk = rtDW.b_A[3 + rtDW.r2];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] /= rtDW.absxk;
  rtDW.t_e = rtDW.b_A[6 + rtDW.r2];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] -= rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] *
    rtDW.t_e;
  rtDW.dfq_dhb_tmp = rtDW.b_A[6 + rtDW.r3];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] /= rtDW.dfq_dhb_tmp;
  rtDW.dfq_dhb_tmp_b = rtDW.b_A[3 + rtDW.r3];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] -= rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] *
    rtDW.dfq_dhb_tmp_b;
  rtDW.dfq_dhb[rtDW.rtemp] -= rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] *
    rtDW.b_A[rtDW.r3];
  rtDW.dfq_dhb[rtDW.rtemp] -= rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] *
    rtDW.b_A[rtDW.r2];
  rtDW.dfq_dhb_tmp_o = 1 + rtDW.rtemp;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.b_y_tmp[1] / rtDW.b_A[rtDW.r1];
  rtDW.dfq_dhb_tmp_mj = rtDW.rtemp + 1;
  rtDW.dfq_dhb_tmp_c = 1 + rtDW.dfq_dhb_tmp_l;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.b_y_tmp[5] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] * rtDW.maxval;
  rtDW.dfq_dhb_tmp_p = 1 + rtDW.dfq_dhb_tmp_m;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_p] = rtDW.b_y_tmp[9] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] * rtDW.scale;
  rtDW.dfq_dhb_tmp_f = rtDW.dfq_dhb_tmp_l + 1;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_f] /
    rtDW.absxk;
  rtDW.dfq_dhb_tmp_e = rtDW.dfq_dhb_tmp_m + 1;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_p] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_e] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_f] * rtDW.t_e;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_p] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_e] /
    rtDW.dfq_dhb_tmp;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_f] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_e] * rtDW.dfq_dhb_tmp_b;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_e] * rtDW.b_A[rtDW.r3];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_f] * rtDW.b_A[rtDW.r2];
  rtDW.dfq_dhb_tmp_o = 2 + rtDW.rtemp;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.b_y_tmp[2] / rtDW.b_A[rtDW.r1];
  rtDW.dfq_dhb_tmp_mj = rtDW.rtemp + 2;
  rtDW.dfq_dhb_tmp_c = 2 + rtDW.dfq_dhb_tmp_l;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.b_y_tmp[6] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] * rtDW.maxval;
  rtDW.dfq_dhb_tmp_p = 2 + rtDW.dfq_dhb_tmp_m;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_p] = rtDW.b_y_tmp[10] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] * rtDW.scale;
  rtDW.dfq_dhb_tmp_f = rtDW.dfq_dhb_tmp_l + 2;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_f] /
    rtDW.absxk;
  rtDW.dfq_dhb_tmp_e = rtDW.dfq_dhb_tmp_m + 2;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_p] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_e] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_f] * rtDW.t_e;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_p] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_e] /
    rtDW.dfq_dhb_tmp;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_f] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_e] * rtDW.dfq_dhb_tmp_b;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_e] * rtDW.b_A[rtDW.r3];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_f] * rtDW.b_A[rtDW.r2];
  rtDW.dfq_dhb_tmp_o = 3 + rtDW.rtemp;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.b_y_tmp[3] / rtDW.b_A[rtDW.r1];
  rtDW.rtemp += 3;
  rtDW.dfq_dhb_tmp_mj = 3 + rtDW.dfq_dhb_tmp_l;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] = rtDW.b_y_tmp[7] - rtDW.dfq_dhb[rtDW.rtemp]
    * rtDW.maxval;
  rtDW.dfq_dhb_tmp_c = 3 + rtDW.dfq_dhb_tmp_m;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.b_y_tmp[11] - rtDW.dfq_dhb[rtDW.rtemp]
    * rtDW.scale;
  rtDW.dfq_dhb_tmp_l += 3;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] /
    rtDW.absxk;
  rtDW.dfq_dhb_tmp_m += 3;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] * rtDW.t_e;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_c] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] /
    rtDW.dfq_dhb_tmp;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_mj] = rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] * rtDW.dfq_dhb_tmp_b;
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.dfq_dhb[rtDW.rtemp] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_m] * rtDW.b_A[rtDW.r3];
  rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_o] = rtDW.dfq_dhb[rtDW.rtemp] -
    rtDW.dfq_dhb[rtDW.dfq_dhb_tmp_l] * rtDW.b_A[rtDW.r2];
  rtDW.maxval = x[4] + x[7];
  rtDW.scale = x[5] + x[8];
  rtDW.absxk = x[6] + x[9];
  rtDW.b_A[0] = 0.0;
  rtDW.b_A[3] = -rtDW.absxk;
  rtDW.b_A[6] = rtDW.scale;
  rtDW.b_A[1] = rtDW.absxk;
  rtDW.b_A[4] = 0.0;
  rtDW.b_A[7] = -rtDW.maxval;
  rtDW.b_A[2] = -rtDW.scale;
  rtDW.b_A[5] = rtDW.maxval;
  rtDW.b_A[8] = 0.0;
  for (rtDW.r1 = 0; rtDW.r1 < 4; rtDW.r1++) {
    rtDW.q[rtDW.r1] = rtDW.b_y_tmp[rtDW.r1 + 8] * rtDW.w[2] +
      (rtDW.b_y_tmp[rtDW.r1 + 4] * rtDW.w[1] + rtDW.b_y_tmp[rtDW.r1] * rtDW.w[0]);
  }

  f[0] = rtDW.q[0];
  f[1] = rtDW.q[1];
  f[2] = rtDW.q[2];
  f[3] = rtDW.q[3];
  rtDW.dv4[0] = 0.0;
  rtDW.dv4[3] = -x[6];
  rtDW.dv4[6] = x[5];
  rtDW.dv4[1] = x[6];
  rtDW.dv4[4] = 0.0;
  rtDW.dv4[7] = -x[4];
  rtDW.dv4[2] = -x[5];
  rtDW.dv4[5] = x[4];
  rtDW.dv4[8] = 0.0;
  mrdivide_helper_JpwaVRMh_b(rtDW.dv4, J, rtDW.dv5);
  rtDW.dv4[0] = 0.0;
  rtDW.dv4[3] = -x[9];
  rtDW.dv4[6] = x[8];
  rtDW.dv4[1] = x[9];
  rtDW.dv4[4] = 0.0;
  rtDW.dv4[7] = -x[7];
  rtDW.dv4[2] = -x[8];
  rtDW.dv4[5] = x[7];
  rtDW.dv4[8] = 0.0;
  mrdivide_helper_JpwaVRMh_b(rtDW.dv4, J, rtDW.dv6);
  rtDW.dv4[0] = 0.0;
  rtDW.dv4[3] = -rtDW.w[2];
  rtDW.dv4[6] = rtDW.w[1];
  rtDW.dv4[1] = rtDW.w[2];
  rtDW.dv4[4] = 0.0;
  rtDW.dv4[7] = -rtDW.w[0];
  rtDW.dv4[2] = -rtDW.w[1];
  rtDW.dv4[5] = rtDW.w[0];
  rtDW.dv4[8] = 0.0;
  A[0] = 0.0;
  for (rtDW.r1 = 0; rtDW.r1 < 3; rtDW.r1++) {
    f[rtDW.r1 + 4] = ((rtDW.b_A[rtDW.r1 + 3] * rtDW.w[1] + rtDW.b_A[rtDW.r1] *
                       rtDW.w[0]) + rtDW.b_A[rtDW.r1 + 6] * rtDW.w[2]) +
      -u[rtDW.r1];
    f[rtDW.r1 + 7] = u[rtDW.r1];
    A[10 * (rtDW.r1 + 1)] = 0.5 * -rtDW.w[rtDW.r1];
    A[rtDW.r1 + 1] = 0.5 * rtDW.w[rtDW.r1];
    rtDW.r2 = rtDW.r1 << 2;
    rtDW.r3 = 10 * (rtDW.r1 + 4);
    A[rtDW.r3] = rtDW.dfq_dhb[rtDW.r2];
    rtDW.rtemp = 10 * (rtDW.r1 + 7);
    A[rtDW.rtemp] = 0.0;
    A[1 + rtDW.r3] = rtDW.dfq_dhb[rtDW.r2 + 1];
    A[1 + rtDW.rtemp] = 0.0;
    A[2 + rtDW.r3] = rtDW.dfq_dhb[rtDW.r2 + 2];
    A[2 + rtDW.rtemp] = 0.0;
    A[3 + rtDW.r3] = rtDW.dfq_dhb[rtDW.r2 + 3];
    A[3 + rtDW.rtemp] = 0.0;
  }

  A[11] = -0.0;
  A[21] = 0.5 * rtDW.w[2];
  A[31] = 0.5 * -rtDW.w[1];
  A[12] = 0.5 * -rtDW.w[2];
  A[22] = -0.0;
  A[32] = 0.5 * rtDW.w[0];
  A[13] = 0.5 * rtDW.w[1];
  A[23] = 0.5 * -rtDW.w[0];
  A[33] = -0.0;
  for (rtDW.r1 = 0; rtDW.r1 < 4; rtDW.r1++) {
    A[4 + 10 * rtDW.r1] = 0.0;
    A[5 + 10 * rtDW.r1] = 0.0;
    A[6 + 10 * rtDW.r1] = 0.0;
  }

  for (rtDW.r1 = 0; rtDW.r1 < 3; rtDW.r1++) {
    rtDW.r2 = 10 * (rtDW.r1 + 4);
    A[4 + rtDW.r2] = (rtDW.dv5[3 * rtDW.r1] - rtDW.dv4[3 * rtDW.r1]) + rtDW.dv6
      [3 * rtDW.r1];
    rtDW.r3 = 3 * rtDW.r1 + 1;
    A[5 + rtDW.r2] = (rtDW.dv5[rtDW.r3] - rtDW.dv4[rtDW.r3]) + rtDW.dv6[rtDW.r3];
    rtDW.r3 = 3 * rtDW.r1 + 2;
    A[6 + rtDW.r2] = (rtDW.dv5[rtDW.r3] - rtDW.dv4[rtDW.r3]) + rtDW.dv6[rtDW.r3];
  }

  A[74] = -0.0;
  A[84] = rtDW.w[2];
  A[94] = -rtDW.w[1];
  A[75] = -rtDW.w[2];
  A[85] = -0.0;
  A[95] = rtDW.w[0];
  A[76] = rtDW.w[1];
  A[86] = -rtDW.w[0];
  A[96] = -0.0;
  for (rtDW.r1 = 0; rtDW.r1 < 10; rtDW.r1++) {
    A[7 + 10 * rtDW.r1] = 0.0;
    A[8 + 10 * rtDW.r1] = 0.0;
    A[9 + 10 * rtDW.r1] = 0.0;
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void get_f_vals_Gr0pzuuC_l(real_T t, const real_T x[10], const real_T u[6],
  const real_T tspan[10], const real_T J[9], real_T f[10], real_T A[100], real_T
  Bp[30], real_T Bm[30], real_T Z[10])
{
  static const int8_T b[30] = { 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1 };

  rtDW.lam_kp = tspan[9] - tspan[0];
  rtDW.lam_km = (tspan[9] - t) / rtDW.lam_kp;
  rtDW.lam_kp = (t - tspan[0]) / rtDW.lam_kp;
  rtDW.u_tau[0] = rtDW.lam_km * u[0] + rtDW.lam_kp * u[3];
  rtDW.u_tau[1] = rtDW.lam_km * u[1] + rtDW.lam_kp * u[4];
  rtDW.u_tau[2] = rtDW.lam_km * u[2] + rtDW.lam_kp * u[5];
  Q_linearize_CKnbADMM_d(x, rtDW.u_tau, J, A, f);
  for (rtDW.i8 = 0; rtDW.i8 < 30; rtDW.i8++) {
    Bp[rtDW.i8] = rtDW.lam_kp * (real_T)b[rtDW.i8];
    Bm[rtDW.i8] = rtDW.lam_km * (real_T)b[rtDW.i8];
    rtDW.Bp_tmp[rtDW.i8] = b[rtDW.i8];
  }

  for (rtDW.i8 = 0; rtDW.i8 < 100; rtDW.i8++) {
    rtDW.A_p[rtDW.i8] = -A[rtDW.i8];
  }

  for (rtDW.i8 = 0; rtDW.i8 < 10; rtDW.i8++) {
    rtDW.A_d[rtDW.i8] = 0.0;
    for (rtDW.i9 = 0; rtDW.i9 < 10; rtDW.i9++) {
      rtDW.A_d[rtDW.i8] += rtDW.A_p[10 * rtDW.i9 + rtDW.i8] * x[rtDW.i9];
    }

    Z[rtDW.i8] = rtDW.A_d[rtDW.i8] - ((real_T)rtDW.Bp_tmp[rtDW.i8 + 20] *
      rtDW.u_tau[2] + ((real_T)rtDW.Bp_tmp[rtDW.i8 + 10] * rtDW.u_tau[1] +
                       (real_T)rtDW.Bp_tmp[rtDW.i8] * rtDW.u_tau[0]));
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void xgetrf_CjXcXVfl_i(real_T A[100], int32_T ipiv[10], int32_T *info)
{
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  for (rtDW.j = 0; rtDW.j < 10; rtDW.j++) {
    ipiv[rtDW.j] = 1 + rtDW.j;
  }

  *info = 0;
  for (rtDW.j = 0; rtDW.j < 9; rtDW.j++) {
    rtDW.c_k = rtDW.j * 11;
    iy = 0;
    rtDW.ix = rtDW.c_k;
    rtDW.smax = fabs(A[rtDW.c_k]);
    rtDW.k_p = 2;
    while (rtDW.k_p <= 10 - rtDW.j) {
      rtDW.ix++;
      rtDW.s_j = fabs(A[rtDW.ix]);
      if (rtDW.s_j > rtDW.smax) {
        iy = rtDW.k_p - 1;
        rtDW.smax = rtDW.s_j;
      }

      rtDW.k_p++;
    }

    if (A[rtDW.c_k + iy] != 0.0) {
      if (iy != 0) {
        iy += rtDW.j;
        ipiv[rtDW.j] = iy + 1;
        rtDW.ix = rtDW.j;
        for (rtDW.k_p = 0; rtDW.k_p < 10; rtDW.k_p++) {
          rtDW.smax = A[rtDW.ix];
          A[rtDW.ix] = A[iy];
          A[iy] = rtDW.smax;
          rtDW.ix += 10;
          iy += 10;
        }
      }

      iy = (rtDW.c_k - rtDW.j) + 10;
      rtDW.ix = rtDW.c_k + 1;
      while (rtDW.ix + 1 <= iy) {
        A[rtDW.ix] /= A[rtDW.c_k];
        rtDW.ix++;
      }
    } else {
      *info = rtDW.j + 1;
    }

    iy = rtDW.c_k;
    rtDW.ix = rtDW.c_k + 10;
    rtDW.k_p = 0;
    while (rtDW.k_p <= 8 - rtDW.j) {
      if (A[rtDW.ix] != 0.0) {
        rtDW.smax = -A[rtDW.ix];
        c_ix = rtDW.c_k + 1;
        d = (iy - rtDW.j) + 20;
        for (ijA = 11 + iy; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * rtDW.smax;
          c_ix++;
        }
      }

      rtDW.ix += 10;
      iy += 10;
      rtDW.k_p++;
    }
  }

  if ((*info == 0) && (!(A[99] != 0.0))) {
    *info = 10;
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void mldivide_gjtSm7pm_e(const real_T A[100], real_T B_5[30])
{
  memcpy(&rtDW.b_A_l[0], &A[0], 100U * sizeof(real_T));
  xgetrf_CjXcXVfl_i(rtDW.b_A_l, rtDW.ipiv, &rtDW.info);
  for (rtDW.info = 0; rtDW.info < 9; rtDW.info++) {
    if (rtDW.info + 1 != rtDW.ipiv[rtDW.info]) {
      rtDW.ip = rtDW.ipiv[rtDW.info] - 1;
      rtDW.temp = B_5[rtDW.info];
      B_5[rtDW.info] = B_5[rtDW.ip];
      B_5[rtDW.ip] = rtDW.temp;
      rtDW.temp = B_5[rtDW.info + 10];
      B_5[rtDW.info + 10] = B_5[rtDW.ip + 10];
      B_5[rtDW.ip + 10] = rtDW.temp;
      rtDW.temp = B_5[rtDW.info + 20];
      B_5[rtDW.info + 20] = B_5[rtDW.ip + 20];
      B_5[rtDW.ip + 20] = rtDW.temp;
    }
  }

  for (rtDW.info = 0; rtDW.info < 3; rtDW.info++) {
    rtDW.ip = 10 * rtDW.info;
    for (rtDW.xj = 0; rtDW.xj < 10; rtDW.xj++) {
      rtDW.kAcol = 10 * rtDW.xj;
      if (B_5[rtDW.xj + rtDW.ip] != 0.0) {
        rtDW.i_c = rtDW.xj + 2;
        while (rtDW.i_c < 11) {
          rtDW.i11 = (rtDW.i_c + rtDW.ip) - 1;
          B_5[rtDW.i11] -= rtDW.b_A_l[(rtDW.i_c + rtDW.kAcol) - 1] * B_5[rtDW.xj
            + rtDW.ip];
          rtDW.i_c++;
        }
      }
    }
  }

  for (rtDW.info = 0; rtDW.info < 3; rtDW.info++) {
    rtDW.ip = 10 * rtDW.info;
    for (rtDW.xj = 9; rtDW.xj >= 0; rtDW.xj--) {
      rtDW.kAcol = 10 * rtDW.xj;
      if (B_5[rtDW.xj + rtDW.ip] != 0.0) {
        B_5[rtDW.xj + rtDW.ip] /= rtDW.b_A_l[rtDW.xj + rtDW.kAcol];
        rtDW.i_c = 0;
        while (rtDW.i_c <= rtDW.xj - 1) {
          rtDW.i11 = rtDW.i_c + rtDW.ip;
          B_5[rtDW.i11] -= B_5[rtDW.xj + rtDW.ip] * rtDW.b_A_l[rtDW.i_c +
            rtDW.kAcol];
          rtDW.i_c++;
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void mldivide_JgAM3Jry_p(const real_T A[100], real_T B_6[10])
{
  memcpy(&rtDW.b_A_o[0], &A[0], 100U * sizeof(real_T));
  xgetrf_CjXcXVfl_i(rtDW.b_A_o, rtDW.ipiv_g, &rtDW.info_p);
  for (rtDW.info_p = 0; rtDW.info_p < 9; rtDW.info_p++) {
    if (rtDW.info_p + 1 != rtDW.ipiv_g[rtDW.info_p]) {
      rtDW.temp_o = B_6[rtDW.info_p];
      B_6[rtDW.info_p] = B_6[rtDW.ipiv_g[rtDW.info_p] - 1];
      B_6[rtDW.ipiv_g[rtDW.info_p] - 1] = rtDW.temp_o;
    }
  }

  for (rtDW.info_p = 0; rtDW.info_p < 10; rtDW.info_p++) {
    rtDW.kAcol_p = 10 * rtDW.info_p;
    if (B_6[rtDW.info_p] != 0.0) {
      rtDW.i_a = rtDW.info_p + 1;
      while (rtDW.i_a + 1 < 11) {
        B_6[rtDW.i_a] -= rtDW.b_A_o[rtDW.i_a + rtDW.kAcol_p] * B_6[rtDW.info_p];
        rtDW.i_a++;
      }
    }
  }

  for (rtDW.info_p = 9; rtDW.info_p >= 0; rtDW.info_p--) {
    rtDW.kAcol_p = 10 * rtDW.info_p;
    if (B_6[rtDW.info_p] != 0.0) {
      B_6[rtDW.info_p] /= rtDW.b_A_o[rtDW.info_p + rtDW.kAcol_p];
      rtDW.i_a = 0;
      while (rtDW.i_a <= rtDW.info_p - 1) {
        B_6[rtDW.i_a] -= rtDW.b_A_o[rtDW.i_a + rtDW.kAcol_p] * B_6[rtDW.info_p];
        rtDW.i_a++;
      }
    }
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void deriv_CsN416wG_c(real_T t, const real_T X_1[190], const real_T u[6],
  const real_T tspan[10], real_T s, const real_T J[9], real_T DX[190])
{
  get_f_vals_Gr0pzuuC_l(t, &X_1[0], u, tspan, J, rtDW.f, rtDW.A_k, rtDW.Bdp_dot,
                        rtDW.Bdm_dot, rtDW.Zd_dot);
  for (rtDW.i5 = 0; rtDW.i5 < 30; rtDW.i5++) {
    rtDW.Bdp_dot[rtDW.i5] *= s;
  }

  mldivide_gjtSm7pm_e(&X_1[10], rtDW.Bdp_dot);
  for (rtDW.i5 = 0; rtDW.i5 < 30; rtDW.i5++) {
    rtDW.Bdm_dot[rtDW.i5] *= s;
  }

  mldivide_gjtSm7pm_e(&X_1[10], rtDW.Bdm_dot);
  memcpy(&rtDW.Sd_dot[0], &rtDW.f[0], 10U * sizeof(real_T));
  mldivide_JgAM3Jry_p(&X_1[10], rtDW.Sd_dot);
  for (rtDW.i5 = 0; rtDW.i5 < 10; rtDW.i5++) {
    rtDW.Zd_dot[rtDW.i5] *= s;
  }

  mldivide_JgAM3Jry_p(&X_1[10], rtDW.Zd_dot);
  memcpy(&rtDW.X_c[0], &X_1[10], 100U * sizeof(real_T));
  for (rtDW.i5 = 0; rtDW.i5 < 10; rtDW.i5++) {
    for (rtDW.i6 = 0; rtDW.i6 < 10; rtDW.i6++) {
      rtDW.s_tmp = rtDW.i5 + 10 * rtDW.i6;
      rtDW.s_b[rtDW.s_tmp] = 0.0;
      for (rtDW.i7 = 0; rtDW.i7 < 10; rtDW.i7++) {
        rtDW.s_b[rtDW.s_tmp] = rtDW.A_k[10 * rtDW.i7 + rtDW.i5] * s * rtDW.X_c
          [10 * rtDW.i6 + rtDW.i7] + rtDW.s_b[10 * rtDW.i6 + rtDW.i5];
      }
    }

    DX[rtDW.i5] = s * rtDW.f[rtDW.i5];
  }

  memcpy(&DX[10], &rtDW.s_b[0], 100U * sizeof(real_T));
  for (rtDW.i5 = 0; rtDW.i5 < 30; rtDW.i5++) {
    DX[rtDW.i5 + 110] = rtDW.Bdp_dot[rtDW.i5];
    DX[rtDW.i5 + 140] = rtDW.Bdm_dot[rtDW.i5];
  }

  for (rtDW.i5 = 0; rtDW.i5 < 10; rtDW.i5++) {
    DX[rtDW.i5 + 170] = rtDW.Sd_dot[rtDW.i5];
    DX[rtDW.i5 + 180] = rtDW.Zd_dot[rtDW.i5];
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void foh_OxYXiak1_m(const real_T X_0[100], const real_T U[30], real_T s,
  const real_T J[9], real_T EH[10000], real_T BE[3000], real_T ES[100], real_T
  AR[100])
{
  real_T *P0;
  memset(&EH[0], 0, 10000U * sizeof(real_T));
  eye_y3VYXK5u(rtDW.EH_tmp);
  for (rtDW.i0 = 0; rtDW.i0 < 10; rtDW.i0++) {
    memcpy(&EH[rtDW.i0 * 100], &rtDW.EH_tmp[rtDW.i0 * 10], 10U * sizeof(real_T));
  }

  memset(&BE[0], 0, 3000U * sizeof(real_T));
  memset(&ES[0], 0, 100U * sizeof(real_T));
  memset(&AR[0], 0, 100U * sizeof(real_T));
  for (rtDW.k = 0; rtDW.k < 9; rtDW.k++) {
    rtDW.i0 = 10 * rtDW.k;
    memcpy(&rtDW.P0[0], &X_0[rtDW.i0], 10U * sizeof(real_T));
    memcpy(&rtDW.P0[10], &rtDW.EH_tmp[0], 100U * sizeof(real_T));
    for (rtDW.i0 = 0; rtDW.i0 < 30; rtDW.i0++) {
      rtDW.P0[rtDW.i0 + 110] = 0.0;
      rtDW.P0[rtDW.i0 + 140] = 0.0;
    }

    for (rtDW.i0 = 0; rtDW.i0 < 10; rtDW.i0++) {
      rtDW.P0[rtDW.i0 + 170] = 0.0;
      rtDW.P0[rtDW.i0 + 180] = 0.0;
    }

    rtDW.i0 = 3 * rtDW.k;
    rtDW.i4 = (1 + rtDW.k) * 3;
    rtDW.u[0] = U[rtDW.i0];
    rtDW.u[3] = U[rtDW.i4];
    rtDW.u[1] = U[1 + rtDW.i0];
    rtDW.u[4] = U[1 + rtDW.i4];
    rtDW.u[2] = U[2 + rtDW.i0];
    rtDW.u[5] = U[2 + rtDW.i4];
    linspace_dCtge7ie_l(0.1111111111111111 * (real_T)rtDW.k, ((real_T)rtDW.k +
      1.0) * 0.1111111111111111, rtDW.tspan);
    for (rtDW.k_ = 0; rtDW.k_ < 9; rtDW.k_++) {
      rtDW.h_d = rtDW.tspan[rtDW.k_ + 1] - rtDW.tspan[rtDW.k_];
      deriv_CsN416wG_c(rtDW.tspan[rtDW.k_], rtDW.P0, rtDW.u, rtDW.tspan, s, J,
                       rtDW.k1);
      rtDW.a = rtDW.h_d / 2.0;
      for (rtDW.i0 = 0; rtDW.i0 < 190; rtDW.i0++) {
        rtDW.P0_m[rtDW.i0] = rtDW.a * rtDW.k1[rtDW.i0] + rtDW.P0[rtDW.i0];
      }

      deriv_CsN416wG_c(rtDW.h_d / 2.0 + rtDW.tspan[rtDW.k_], rtDW.P0_m, rtDW.u,
                       rtDW.tspan, s, J, rtDW.k2);
      rtDW.a = rtDW.h_d / 2.0;
      for (rtDW.i0 = 0; rtDW.i0 < 190; rtDW.i0++) {
        rtDW.P0_m[rtDW.i0] = rtDW.a * rtDW.k2[rtDW.i0] + rtDW.P0[rtDW.i0];
      }

      deriv_CsN416wG_c(rtDW.h_d / 2.0 + rtDW.tspan[rtDW.k_], rtDW.P0_m, rtDW.u,
                       rtDW.tspan, s, J, rtDW.k3);
      for (rtDW.i0 = 0; rtDW.i0 < 190; rtDW.i0++) {
        rtDW.P0_m[rtDW.i0] = rtDW.h_d * rtDW.k3[rtDW.i0] + rtDW.P0[rtDW.i0];
      }

      deriv_CsN416wG_c(rtDW.tspan[rtDW.k_] + rtDW.h_d, rtDW.P0_m, rtDW.u,
                       rtDW.tspan, s, J, rtDW.k4);
      rtDW.h_d /= 6.0;
      for (rtDW.i0 = 0; rtDW.i0 < 190; rtDW.i0++) {
        rtDW.P0[rtDW.i0] += (((2.0 * rtDW.k2[rtDW.i0] + rtDW.k1[rtDW.i0]) + 2.0 *
                              rtDW.k3[rtDW.i0]) + rtDW.k4[rtDW.i0]) * rtDW.h_d;
      }
    }

    for (rtDW.i0 = 0; rtDW.i0 < 100; rtDW.i0++) {
      rtDW.h_d = rtDW.P0[10 + rtDW.i0];
      rtDW.Ad[rtDW.i0] = rtDW.h_d;
      rtDW.P0_c[rtDW.i0] = rtDW.h_d;
    }

    rtDW.i0 = (1 + rtDW.k) * 10;
    rtDW.k_ = 10 * rtDW.k;
    for (rtDW.i1 = 0; rtDW.i1 < 10; rtDW.i1++) {
      memcpy(&EH[rtDW.i1 * 100 + (rtDW.i0 + rtDW.k_ * 100)], &rtDW.P0_c[rtDW.i1 *
             10], 10U * sizeof(real_T));
    }

    P0 = &rtDW.P0[140];
    rtDW.k_ = 3 * rtDW.k;
    for (rtDW.i1 = 0; rtDW.i1 < 10; rtDW.i1++) {
      for (rtDW.i2 = 0; rtDW.i2 < 3; rtDW.i2++) {
        rtDW.BE_tmp = rtDW.i2 + rtDW.k_;
        rtDW.BE_tmp_o = (rtDW.i1 + rtDW.i0) + 100 * rtDW.BE_tmp;
        BE[rtDW.BE_tmp_o] = 0.0;
        for (rtDW.i3 = 0; rtDW.i3 < 10; rtDW.i3++) {
          BE[rtDW.BE_tmp_o] = BE[(rtDW.BE_tmp * 100 + rtDW.i1) + rtDW.i0] +
            rtDW.Ad[10 * rtDW.i3 + rtDW.i1] * P0[10 * rtDW.i2 + rtDW.i3];
        }
      }
    }

    P0 = &rtDW.P0[110];
    for (rtDW.k_ = 0; rtDW.k_ < 10; rtDW.k_++) {
      for (rtDW.i1 = 0; rtDW.i1 < 3; rtDW.i1++) {
        rtDW.BE_tmp = rtDW.i1 + rtDW.i4;
        rtDW.BE_tmp_o = (rtDW.k_ + rtDW.i0) + 100 * rtDW.BE_tmp;
        BE[rtDW.BE_tmp_o] = 0.0;
        for (rtDW.i2 = 0; rtDW.i2 < 10; rtDW.i2++) {
          BE[rtDW.BE_tmp_o] = BE[(rtDW.BE_tmp * 100 + rtDW.k_) + rtDW.i0] +
            rtDW.Ad[10 * rtDW.i2 + rtDW.k_] * P0[10 * rtDW.i1 + rtDW.i2];
        }
      }

      rtDW.tspan[rtDW.k_] = 0.0;
      for (rtDW.i1 = 0; rtDW.i1 < 10; rtDW.i1++) {
        rtDW.tspan[rtDW.k_] += rtDW.Ad[10 * rtDW.i1 + rtDW.k_] * rtDW.P0[170 +
          rtDW.i1];
      }

      ES[rtDW.k_ + rtDW.i0] = rtDW.tspan[rtDW.k_];
      rtDW.Ad_j[rtDW.k_] = 0.0;
      for (rtDW.i1 = 0; rtDW.i1 < 10; rtDW.i1++) {
        rtDW.Ad_j[rtDW.k_] += rtDW.Ad[10 * rtDW.i1 + rtDW.k_] * rtDW.P0[180 +
          rtDW.i1];
      }

      AR[rtDW.k_ + rtDW.i0] = rtDW.Ad_j[rtDW.k_];
    }
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void inv_v2jI2dX7_g(const real_T x[9], real_T y[9])
{
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  memcpy(&rtDW.b_x[0], &x[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  rtDW.absx11 = fabs(x[0]);
  rtDW.absx21 = fabs(x[1]);
  rtDW.absx31 = fabs(x[2]);
  if ((rtDW.absx21 > rtDW.absx11) && (rtDW.absx21 > rtDW.absx31)) {
    p1 = 3;
    p2 = 0;
    rtDW.b_x[0] = x[1];
    rtDW.b_x[1] = x[0];
    rtDW.b_x[3] = x[4];
    rtDW.b_x[4] = x[3];
    rtDW.b_x[6] = x[7];
    rtDW.b_x[7] = x[6];
  } else {
    if (rtDW.absx31 > rtDW.absx11) {
      p1 = 6;
      p3 = 0;
      rtDW.b_x[0] = x[2];
      rtDW.b_x[2] = x[0];
      rtDW.b_x[3] = x[5];
      rtDW.b_x[5] = x[3];
      rtDW.b_x[6] = x[8];
      rtDW.b_x[8] = x[6];
    }
  }

  rtDW.absx31 = rtDW.b_x[1] / rtDW.b_x[0];
  rtDW.b_x[1] = rtDW.absx31;
  rtDW.absx11 = rtDW.b_x[2] / rtDW.b_x[0];
  rtDW.b_x[2] = rtDW.absx11;
  rtDW.b_x[4] -= rtDW.absx31 * rtDW.b_x[3];
  rtDW.b_x[5] -= rtDW.absx11 * rtDW.b_x[3];
  rtDW.b_x[7] -= rtDW.absx31 * rtDW.b_x[6];
  rtDW.b_x[8] -= rtDW.absx11 * rtDW.b_x[6];
  if (fabs(rtDW.b_x[5]) > fabs(rtDW.b_x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    rtDW.b_x[1] = rtDW.absx11;
    rtDW.b_x[2] = rtDW.absx31;
    rtDW.absx11 = rtDW.b_x[4];
    rtDW.b_x[4] = rtDW.b_x[5];
    rtDW.b_x[5] = rtDW.absx11;
    rtDW.absx11 = rtDW.b_x[7];
    rtDW.b_x[7] = rtDW.b_x[8];
    rtDW.b_x[8] = rtDW.absx11;
  }

  rtDW.absx31 = rtDW.b_x[5] / rtDW.b_x[4];
  rtDW.b_x[8] -= rtDW.absx31 * rtDW.b_x[7];
  rtDW.absx11 = (rtDW.absx31 * rtDW.b_x[1] - rtDW.b_x[2]) / rtDW.b_x[8];
  rtDW.absx21 = -(rtDW.b_x[7] * rtDW.absx11 + rtDW.b_x[1]) / rtDW.b_x[4];
  y[p1] = ((1.0 - rtDW.b_x[3] * rtDW.absx21) - rtDW.b_x[6] * rtDW.absx11) /
    rtDW.b_x[0];
  y[p1 + 1] = rtDW.absx21;
  y[p1 + 2] = rtDW.absx11;
  rtDW.absx11 = -rtDW.absx31 / rtDW.b_x[8];
  rtDW.absx21 = (1.0 - rtDW.b_x[7] * rtDW.absx11) / rtDW.b_x[4];
  y[p2] = -(rtDW.b_x[3] * rtDW.absx21 + rtDW.b_x[6] * rtDW.absx11) / rtDW.b_x[0];
  y[p2 + 1] = rtDW.absx21;
  y[p2 + 2] = rtDW.absx11;
  rtDW.absx11 = 1.0 / rtDW.b_x[8];
  rtDW.absx21 = -rtDW.b_x[7] * rtDW.absx11 / rtDW.b_x[4];
  y[p3] = -(rtDW.b_x[3] * rtDW.absx21 + rtDW.b_x[6] * rtDW.absx11) / rtDW.b_x[0];
  y[p3 + 1] = rtDW.absx21;
  y[p3 + 2] = rtDW.absx11;
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void kron_gzkpgh2R_c(const real_T A[100], const real_T B_3[30], real_T K
  [3000])
{
  int32_T kidx;
  int32_T b_j1;
  int32_T j2;
  int32_T i1;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 10; b_j1++) {
    for (j2 = 0; j2 < 10; j2++) {
      for (i1 = 0; i1 < 10; i1++) {
        kidx++;
        rtDW.K_tmp_i = A[10 * b_j1 + i1];
        K[kidx] = rtDW.K_tmp_i * B_3[3 * j2];
        kidx++;
        K[kidx] = rtDW.K_tmp_i * B_3[3 * j2 + 1];
        kidx++;
        K[kidx] = rtDW.K_tmp_i * B_3[3 * j2 + 2];
      }
    }
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void kron_mrguWHGo_i(const real_T A[100], const real_T B_4[9], real_T K
  [900])
{
  int32_T kidx;
  int32_T b_j1;
  int32_T j2;
  int32_T i1;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 10; b_j1++) {
    for (j2 = 0; j2 < 3; j2++) {
      for (i1 = 0; i1 < 10; i1++) {
        kidx++;
        rtDW.K_tmp = A[10 * b_j1 + i1];
        K[kidx] = rtDW.K_tmp * B_4[3 * j2];
        kidx++;
        K[kidx] = rtDW.K_tmp * B_4[3 * j2 + 1];
        kidx++;
        K[kidx] = rtDW.K_tmp * B_4[3 * j2 + 2];
      }
    }
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void parse_ecos_4lHXAQLu_p(const real_T xi[10], const real_T xf[7], const
  real_T J[9], const real_T EH[10000], const real_T BE[3000], const real_T ES
  [100], const real_T AR[100], const real_T ME[16], const real_T MI[16], real_T
  T_max, real_T w_max, real_T s_max, real_T s_min, real_T w_v, real_T c[332],
  real_T G[157368], real_T h[474], real_T A[38844], real_T b[117])
{
  static const real_T d[100] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0 };

  static const real_T e[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T f[3320] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T g[2324] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const real_T i[92] = { 0.70710678118654746, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.70710678118654746, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T j[6] = { 2.1213203435596424, 0.0, 0.0, 0.0, 0.0,
    -0.70710678118654746 };

  static const real_T l[332] = { -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.70710678118654746, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0 };

  static const real_T m[332] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.70710678118654746, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T Hs[332] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const int8_T n[332] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0 };

  static const int8_T c_b[40] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  int32_T MI_tmp;
  int32_T MI_tmp_0;
  for (rtDW.i_h = 0; rtDW.i_h < 30; rtDW.i_h++) {
    rtDW.u_max[rtDW.i_h] = T_max;
    rtDW.b_w_max[rtDW.i_h] = w_max;
  }

  inv_v2jI2dX7_g(J, rtDW.dv8);
  memset(&rtDW.dv7[0], 0, 12U * sizeof(real_T));
  for (rtDW.i_h = 0; rtDW.i_h < 9; rtDW.i_h++) {
    rtDW.dv7[rtDW.i_h + 12] = rtDW.dv8[rtDW.i_h];
    rtDW.dv7[rtDW.i_h + 21] = 0.0;
  }

  kron_gzkpgh2R_c(d, rtDW.dv7, rtDW.dv1);
  memcpy(&rtDW.Hw[0], &rtDW.dv1[0], 3000U * sizeof(real_T));
  memset(&rtDW.Hw[3000], 0, 6960U * sizeof(real_T));
  kron_mrguWHGo_i(d, e, rtDW.dv0);
  memset(&rtDW.Hu[0], 0, 3000U * sizeof(real_T));
  memcpy(&rtDW.Hu[3000], &rtDW.dv0[0], 900U * sizeof(real_T));
  memset(&rtDW.Hu[3900], 0, 6060U * sizeof(real_T));
  rtDW.Hu[3000] = 0.70710678118654757;
  rtDW.Hu[3031] = 0.70710678118654757;
  rtDW.Hu[3062] = 0.70710678118654757;
  rtDW.Hu[3837] = 0.70710678118654757;
  rtDW.Hu[3868] = 0.70710678118654757;
  rtDW.Hu[3899] = 0.70710678118654757;
  eye_bAKT5eRN(rtDW.Hv_tmp);
  memset(&rtDW.Hv[0], 0, 13200U * sizeof(real_T));
  for (rtDW.i_h = 0; rtDW.i_h < 10000; rtDW.i_h++) {
    rtDW.Hv[rtDW.i_h + 13200] = rtDW.Hv_tmp[rtDW.i_h];
    rtDW.Hv[rtDW.i_h + 23200] = 0.0;
  }

  memset(&rtDW.Hev[0], 0, 23200U * sizeof(real_T));
  memcpy(&rtDW.Hev[23200], &rtDW.Hv_tmp[0], 10000U * sizeof(real_T));
  memset(&c[0], 0, 130U * sizeof(real_T));
  c[130] = 1.0;
  c[131] = 0.0;
  for (rtDW.i_h = 0; rtDW.i_h < 100; rtDW.i_h++) {
    c[rtDW.i_h + 132] = 0.0;
    c[rtDW.i_h + 232] = w_v;
  }

  for (rtDW.i_h = 0; rtDW.i_h < 332; rtDW.i_h++) {
    for (rtDW.i10 = 0; rtDW.i10 < 10; rtDW.i10++) {
      A[rtDW.i10 + 117 * rtDW.i_h] = f[10 * rtDW.i_h + rtDW.i10];
    }
  }

  for (rtDW.i_h = 0; rtDW.i_h < 100; rtDW.i_h++) {
    for (rtDW.i10 = 0; rtDW.i10 < 100; rtDW.i10++) {
      rtDW.A_tmp = 100 * rtDW.i_h + rtDW.i10;
      A[(rtDW.i10 + 117 * rtDW.i_h) + 10] = EH[rtDW.A_tmp] -
        rtDW.Hv_tmp[rtDW.A_tmp];
    }
  }

  for (rtDW.i_h = 0; rtDW.i_h < 30; rtDW.i_h++) {
    memcpy(&A[rtDW.i_h * 117 + 11710], &BE[rtDW.i_h * 100], 100U * sizeof(real_T));
  }

  for (rtDW.i_h = 0; rtDW.i_h < 100; rtDW.i_h++) {
    A[rtDW.i_h + 15220] = 0.0;
    A[rtDW.i_h + 15337] = ES[rtDW.i_h];
    for (rtDW.i10 = 0; rtDW.i10 < 100; rtDW.i10++) {
      A[(rtDW.i10 + 117 * (rtDW.i_h + 132)) + 10] = rtDW.Hv_tmp[100 * rtDW.i_h +
        rtDW.i10];
      A[(rtDW.i10 + 117 * (rtDW.i_h + 232)) + 10] = 0.0;
    }
  }

  for (rtDW.i_h = 0; rtDW.i_h < 332; rtDW.i_h++) {
    for (rtDW.i10 = 0; rtDW.i10 < 7; rtDW.i10++) {
      A[(rtDW.i10 + 117 * rtDW.i_h) + 110] = g[7 * rtDW.i_h + rtDW.i10];
    }
  }

  memcpy(&b[0], &xi[0], 10U * sizeof(real_T));
  for (rtDW.i_h = 0; rtDW.i_h < 100; rtDW.i_h++) {
    b[rtDW.i_h + 10] = -AR[rtDW.i_h];
  }

  for (rtDW.i_h = 0; rtDW.i_h < 7; rtDW.i_h++) {
    b[rtDW.i_h + 110] = xf[rtDW.i_h];
  }

  for (rtDW.i_h = 0; rtDW.i_h < 332; rtDW.i_h++) {
    rtDW.Gquad_[92 * rtDW.i_h] = l[rtDW.i_h];
    for (rtDW.i10 = 0; rtDW.i10 < 30; rtDW.i10++) {
      rtDW.Gquad_[(rtDW.i10 + 92 * rtDW.i_h) + 1] = -rtDW.Hu[30 * rtDW.i_h +
        rtDW.i10];
    }

    rtDW.Gquad_[31 + 92 * rtDW.i_h] = m[rtDW.i_h];
    memset(&rtDW.Gquad_[rtDW.i_h * 92 + 32], 0, 60U * sizeof(real_T));
  }

  memcpy(&rtDW.hquad_[0], &i[0], 92U * sizeof(real_T));
  for (rtDW.A_tmp = 0; rtDW.A_tmp < 10; rtDW.A_tmp++) {
    memset(&rtDW.Hk[0], 0, 3320U * sizeof(int8_T));
    rtDW.i_h = 10 * rtDW.A_tmp;
    for (rtDW.i10 = 0; rtDW.i10 < 10; rtDW.i10++) {
      for (rtDW.MI_tmp = 0; rtDW.MI_tmp < 10; rtDW.MI_tmp++) {
        rtDW.Hk[rtDW.MI_tmp + 10 * (rtDW.i10 + rtDW.i_h)] = (int8_T)d[10 *
          rtDW.i10 + rtDW.MI_tmp];
      }
    }

    for (rtDW.i_h = 0; rtDW.i_h < 4; rtDW.i_h++) {
      for (rtDW.i10 = 0; rtDW.i10 < 10; rtDW.i10++) {
        rtDW.MI_tmp = rtDW.i10 << 2;
        MI_tmp = rtDW.i_h + rtDW.MI_tmp;
        rtDW.MI_d[MI_tmp] = 0.0;
        MI_tmp_0 = rtDW.MI_tmp + rtDW.i_h;
        rtDW.MI_d[MI_tmp] = rtDW.MI_d[MI_tmp_0] + (real_T)c_b[rtDW.MI_tmp] *
          MI[rtDW.i_h];
        rtDW.MI_d[MI_tmp] = (real_T)c_b[rtDW.MI_tmp + 1] * MI[rtDW.i_h + 4] +
          rtDW.MI_d[MI_tmp_0];
        rtDW.MI_d[MI_tmp] = (real_T)c_b[rtDW.MI_tmp + 2] * MI[rtDW.i_h + 8] +
          rtDW.MI_d[MI_tmp_0];
        rtDW.MI_d[MI_tmp] = (real_T)c_b[rtDW.MI_tmp + 3] * MI[rtDW.i_h + 12] +
          rtDW.MI_d[MI_tmp_0];
      }

      for (rtDW.i10 = 0; rtDW.i10 < 332; rtDW.i10++) {
        rtDW.d0 = 0.0;
        for (rtDW.MI_tmp = 0; rtDW.MI_tmp < 10; rtDW.MI_tmp++) {
          rtDW.d0 += rtDW.MI_d[(rtDW.MI_tmp << 2) + rtDW.i_h] * (real_T)rtDW.Hk
            [10 * rtDW.i10 + rtDW.MI_tmp];
        }

        rtDW.MI[rtDW.i_h + (rtDW.i10 << 2)] = -rtDW.d0;
      }
    }

    rtDW.i_h = 6 * rtDW.A_tmp;
    for (rtDW.i10 = 0; rtDW.i10 < 332; rtDW.i10++) {
      rtDW.Gquad_[(rtDW.i_h + 92 * rtDW.i10) + 32] = 0.0;
    }

    for (rtDW.i10 = 0; rtDW.i10 < 332; rtDW.i10++) {
      rtDW.MI_tmp = rtDW.i10 << 2;
      MI_tmp = rtDW.i_h + 92 * rtDW.i10;
      rtDW.Gquad_[MI_tmp + 33] = rtDW.MI[rtDW.MI_tmp];
      rtDW.Gquad_[MI_tmp + 34] = rtDW.MI[rtDW.MI_tmp + 1];
      rtDW.Gquad_[MI_tmp + 35] = rtDW.MI[rtDW.MI_tmp + 2];
      rtDW.Gquad_[MI_tmp + 36] = rtDW.MI[rtDW.MI_tmp + 3];
    }

    for (rtDW.i10 = 0; rtDW.i10 < 332; rtDW.i10++) {
      rtDW.Gquad_[(rtDW.i_h + 92 * rtDW.i10) + 37] = 0.0;
    }

    rtDW.i_h = 6 * rtDW.A_tmp;
    for (rtDW.i10 = 0; rtDW.i10 < 6; rtDW.i10++) {
      rtDW.hquad_[(rtDW.i10 + rtDW.i_h) + 32] = j[rtDW.i10];
    }
  }

  for (rtDW.i_h = 0; rtDW.i_h < 332; rtDW.i_h++) {
    memcpy(&rtDW.Gquad__[rtDW.i_h * 152], &rtDW.Gquad_[rtDW.i_h * 92], 92U *
           sizeof(real_T));
    memset(&rtDW.Gquad__[rtDW.i_h * 152 + 92], 0, 60U * sizeof(real_T));
  }

  memcpy(&rtDW.hquad__[0], &rtDW.hquad_[0], 92U * sizeof(real_T));
  memset(&rtDW.hquad__[92], 0, 60U * sizeof(real_T));
  for (rtDW.A_tmp = 0; rtDW.A_tmp < 10; rtDW.A_tmp++) {
    memset(&rtDW.Hk[0], 0, 3320U * sizeof(int8_T));
    rtDW.i_h = 10 * rtDW.A_tmp;
    for (rtDW.i10 = 0; rtDW.i10 < 10; rtDW.i10++) {
      for (rtDW.MI_tmp = 0; rtDW.MI_tmp < 10; rtDW.MI_tmp++) {
        rtDW.Hk[rtDW.MI_tmp + 10 * (rtDW.i10 + rtDW.i_h)] = (int8_T)d[10 *
          rtDW.i10 + rtDW.MI_tmp];
      }
    }

    for (rtDW.i_h = 0; rtDW.i_h < 4; rtDW.i_h++) {
      for (rtDW.i10 = 0; rtDW.i10 < 10; rtDW.i10++) {
        rtDW.MI_tmp = rtDW.i10 << 2;
        MI_tmp = rtDW.i_h + rtDW.MI_tmp;
        rtDW.MI_d[MI_tmp] = 0.0;
        MI_tmp_0 = rtDW.MI_tmp + rtDW.i_h;
        rtDW.MI_d[MI_tmp] = rtDW.MI_d[MI_tmp_0] + (real_T)c_b[rtDW.MI_tmp] *
          ME[rtDW.i_h];
        rtDW.MI_d[MI_tmp] = (real_T)c_b[rtDW.MI_tmp + 1] * ME[rtDW.i_h + 4] +
          rtDW.MI_d[MI_tmp_0];
        rtDW.MI_d[MI_tmp] = (real_T)c_b[rtDW.MI_tmp + 2] * ME[rtDW.i_h + 8] +
          rtDW.MI_d[MI_tmp_0];
        rtDW.MI_d[MI_tmp] = (real_T)c_b[rtDW.MI_tmp + 3] * ME[rtDW.i_h + 12] +
          rtDW.MI_d[MI_tmp_0];
      }

      for (rtDW.i10 = 0; rtDW.i10 < 332; rtDW.i10++) {
        rtDW.d0 = 0.0;
        for (rtDW.MI_tmp = 0; rtDW.MI_tmp < 10; rtDW.MI_tmp++) {
          rtDW.d0 += rtDW.MI_d[(rtDW.MI_tmp << 2) + rtDW.i_h] * (real_T)rtDW.Hk
            [10 * rtDW.i10 + rtDW.MI_tmp];
        }

        rtDW.MI[rtDW.i_h + (rtDW.i10 << 2)] = -rtDW.d0;
      }
    }

    rtDW.i_h = 6 * rtDW.A_tmp;
    for (rtDW.i10 = 0; rtDW.i10 < 332; rtDW.i10++) {
      rtDW.Gquad__[(rtDW.i_h + 152 * rtDW.i10) + 32] = 0.0;
    }

    for (rtDW.i10 = 0; rtDW.i10 < 332; rtDW.i10++) {
      rtDW.MI_tmp = rtDW.i10 << 2;
      MI_tmp = rtDW.i_h + 152 * rtDW.i10;
      rtDW.Gquad__[MI_tmp + 33] = rtDW.MI[rtDW.MI_tmp];
      rtDW.Gquad__[MI_tmp + 34] = rtDW.MI[rtDW.MI_tmp + 1];
      rtDW.Gquad__[MI_tmp + 35] = rtDW.MI[rtDW.MI_tmp + 2];
      rtDW.Gquad__[MI_tmp + 36] = rtDW.MI[rtDW.MI_tmp + 3];
    }

    for (rtDW.i10 = 0; rtDW.i10 < 332; rtDW.i10++) {
      rtDW.Gquad__[(rtDW.i_h + 152 * rtDW.i10) + 37] = 0.0;
    }

    rtDW.i_h = 6 * rtDW.A_tmp;
    for (rtDW.i10 = 0; rtDW.i10 < 6; rtDW.i10++) {
      rtDW.hquad__[(rtDW.i10 + rtDW.i_h) + 32] = j[rtDW.i10];
    }
  }

  for (rtDW.i_h = 0; rtDW.i_h < 332; rtDW.i_h++) {
    for (rtDW.i10 = 0; rtDW.i10 < 30; rtDW.i10++) {
      rtDW.MI_tmp = 30 * rtDW.i_h + rtDW.i10;
      rtDW.A_tmp = rtDW.i10 + 474 * rtDW.i_h;
      G[rtDW.A_tmp] = rtDW.Hw[rtDW.MI_tmp];
      G[rtDW.A_tmp + 30] = -rtDW.Hw[rtDW.MI_tmp];
      G[rtDW.A_tmp + 60] = rtDW.Hu[rtDW.MI_tmp];
      G[rtDW.A_tmp + 90] = -rtDW.Hu[rtDW.MI_tmp];
    }

    G[120 + 474 * rtDW.i_h] = Hs[rtDW.i_h];
    G[121 + 474 * rtDW.i_h] = n[rtDW.i_h];
    for (rtDW.i10 = 0; rtDW.i10 < 100; rtDW.i10++) {
      rtDW.MI_tmp = 100 * rtDW.i_h + rtDW.i10;
      rtDW.A_tmp = rtDW.i10 + 474 * rtDW.i_h;
      G[rtDW.A_tmp + 122] = rtDW.Hv[rtDW.MI_tmp] - rtDW.Hev[rtDW.MI_tmp];
      G[rtDW.A_tmp + 222] = -rtDW.Hv[rtDW.MI_tmp] - rtDW.Hev[rtDW.MI_tmp];
    }

    memcpy(&G[rtDW.i_h * 474 + 322], &rtDW.Gquad__[rtDW.i_h * 152], 152U *
           sizeof(real_T));
  }

  for (rtDW.i_h = 0; rtDW.i_h < 30; rtDW.i_h++) {
    h[rtDW.i_h] = rtDW.b_w_max[rtDW.i_h];
    h[rtDW.i_h + 30] = rtDW.b_w_max[rtDW.i_h];
    h[rtDW.i_h + 60] = rtDW.u_max[rtDW.i_h];
    h[rtDW.i_h + 90] = rtDW.u_max[rtDW.i_h];
  }

  h[120] = s_max;
  h[121] = -s_min;
  for (rtDW.i_h = 0; rtDW.i_h < 100; rtDW.i_h++) {
    h[rtDW.i_h + 122] = 0.0;
    h[rtDW.i_h + 222] = 0.0;
  }

  memcpy(&h[322], &rtDW.hquad__[0], 152U * sizeof(real_T));
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void my_find_pTqw9ctN_i(const real_T X_3[38844], int32_T Xir[1278],
  real_T Xpr[1278])
{
  uint32_T id;
  int32_T row;
  int32_T n;
  int32_T k;
  int32_T Xir_tmp;
  memset(&Xir[0], 0, 1278U * sizeof(int32_T));
  memset(&Xpr[0], 0, 1278U * sizeof(real_T));
  n = 0;
  for (k = 0; k < 38844; k++) {
    if (X_3[k] != 0.0) {
      n++;
    }
  }

  id = 1U;
  for (k = 0; k < 332; k++) {
    for (row = 0; row < 117; row++) {
      rtDW.X_o = X_3[117 * k + row];
      if ((rtDW.X_o != 0.0) && (id < (real_T)n + 1.0)) {
        Xir_tmp = (int32_T)id - 1;
        Xir[Xir_tmp] = row;
        Xpr[Xir_tmp] = rtDW.X_o;
        id++;
      }
    }
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void convert_to_CCS_TWUhmVkC_j(const real_T X_2[38844], int32_T Xir[1278],
  int32_T Xjc[333], real_T Xpr[1278])
{
  int32_T b_k;
  my_find_pTqw9ctN_i(X_2, Xir, Xpr);
  memset(&Xjc[0], 0, 333U * sizeof(int32_T));
  for (rtDW.col_e = 0; rtDW.col_e < 331; rtDW.col_e++) {
    rtDW.b_n_f = 0;
    for (b_k = 0; b_k < 117; b_k++) {
      if (X_2[117 * rtDW.col_e + b_k] != 0.0) {
        rtDW.b_n_f++;
      }
    }

    if ((Xjc[rtDW.col_e] < 0) && (rtDW.b_n_f < MIN_int32_T - Xjc[rtDW.col_e])) {
      Xjc[rtDW.col_e + 1] = MIN_int32_T;
    } else if ((Xjc[rtDW.col_e] > 0) && (rtDW.b_n_f > MAX_int32_T
                - Xjc[rtDW.col_e])) {
      Xjc[rtDW.col_e + 1] = MAX_int32_T;
    } else {
      Xjc[rtDW.col_e + 1] = Xjc[rtDW.col_e] + rtDW.b_n_f;
    }
  }

  rtDW.col_e = 0;
  for (rtDW.b_n_f = 0; rtDW.b_n_f < 38844; rtDW.b_n_f++) {
    if (X_2[rtDW.b_n_f] != 0.0) {
      rtDW.col_e++;
    }
  }

  Xjc[332] = rtDW.col_e;
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void my_find_gHak93YM_k(const real_T X_5[157368], int32_T Xir[834],
  real_T Xpr[834])
{
  uint32_T id;
  int32_T row;
  int32_T n;
  int32_T k;
  int32_T Xir_tmp;
  memset(&Xir[0], 0, 834U * sizeof(int32_T));
  memset(&Xpr[0], 0, 834U * sizeof(real_T));
  n = 0;
  for (k = 0; k < 157368; k++) {
    if (X_5[k] != 0.0) {
      n++;
    }
  }

  id = 1U;
  for (k = 0; k < 332; k++) {
    for (row = 0; row < 474; row++) {
      rtDW.X_lt = X_5[474 * k + row];
      if ((rtDW.X_lt != 0.0) && (id < (real_T)n + 1.0)) {
        Xir_tmp = (int32_T)id - 1;
        Xir[Xir_tmp] = row;
        Xpr[Xir_tmp] = rtDW.X_lt;
        id++;
      }
    }
  }
}

/* Function for MATLAB Function: '<S438>/SOLVE' */
static void convert_to_CCS_uvSSMF4Z_o(const real_T X_4[157368], int32_T Xir[834],
  int32_T Xjc[333], real_T Xpr[834])
{
  int32_T b_k;
  my_find_gHak93YM_k(X_4, Xir, Xpr);
  memset(&Xjc[0], 0, 333U * sizeof(int32_T));
  for (rtDW.col = 0; rtDW.col < 331; rtDW.col++) {
    rtDW.b_n = 0;
    for (b_k = 0; b_k < 474; b_k++) {
      if (X_4[474 * rtDW.col + b_k] != 0.0) {
        rtDW.b_n++;
      }
    }

    if ((Xjc[rtDW.col] < 0) && (rtDW.b_n < MIN_int32_T - Xjc[rtDW.col])) {
      Xjc[rtDW.col + 1] = MIN_int32_T;
    } else if ((Xjc[rtDW.col] > 0) && (rtDW.b_n > MAX_int32_T - Xjc[rtDW.col]))
    {
      Xjc[rtDW.col + 1] = MAX_int32_T;
    } else {
      Xjc[rtDW.col + 1] = Xjc[rtDW.col] + rtDW.b_n;
    }
  }

  rtDW.col = 0;
  for (rtDW.b_n = 0; rtDW.b_n < 157368; rtDW.b_n++) {
    if (X_4[rtDW.b_n] != 0.0) {
      rtDW.col++;
    }
  }

  Xjc[332] = rtDW.col;
}

/* System initialize for atomic system: '<S1>/target_generation_lib' */
void target_generation_lib_Init(real_T rty_soar_telemetry[100], real_T
  rty_soar_telemetry_i[30], real_T *rty_soar_telemetry_d, real_T
  rty_soar_telemetry_im[17])
{
  int32_T i;

  /* InitializeConditions for UnitDelay: '<S436>/Delay Input1'
   *
   * Block description for '<S436>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE = rtP.DetectRisePositive_vinit;

  /* InitializeConditions for UnitDelay: '<S437>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_p = rtP.UnitDelay_InitialCondition;

  /* InitializeConditions for Delay: '<S437>/Resettable Delay' */
  rtDW.icLoad = 1U;

  /* InitializeConditions for S-Function (sdspcount2): '<S394>/Counter' */
  rtDW.Counter_ClkEphState = 5U;
  rtDW.Counter_Count = rtP.Counter_InitialCount;

  /* SystemInitialize for Merge: '<S390>/Merge' */
  rtDW.Merge_n[0] = rtP.Merge_InitialOutput[0];
  rtDW.Merge_n[1] = rtP.Merge_InitialOutput[1];
  rtDW.Merge_n[2] = rtP.Merge_InitialOutput[2];
  rtDW.Merge_n[3] = rtP.Merge_InitialOutput[3];

  /* SystemInitialize for Triggered SubSystem: '<S394>/soar_lib' */
  /* SystemInitialize for Outport: '<S438>/opt_state' */
  for (i = 0; i < 100; i++) {
    rty_soar_telemetry[i] = rtP.opt_state_Y0;
  }

  /* End of SystemInitialize for Outport: '<S438>/opt_state' */

  /* SystemInitialize for Outport: '<S438>/opt_ctrl_Nm' */
  for (i = 0; i < 30; i++) {
    rty_soar_telemetry_i[i] = rtP.opt_ctrl_Nm_Y0;
  }

  /* End of SystemInitialize for Outport: '<S438>/opt_ctrl_Nm' */

  /* SystemInitialize for Outport: '<S438>/final_time_s' */
  *rty_soar_telemetry_d = rtP.final_time_s_Y0;

  /* SystemInitialize for Outport: '<S438>/exitcode' */
  for (i = 0; i < 17; i++) {
    rty_soar_telemetry_im[i] = rtP.exitcode_Y0;
  }

  /* End of SystemInitialize for Outport: '<S438>/exitcode' */
  rtPrevZCX.soar_lib_Trig_ZCE = ZERO_ZCSIG;

  /* End of SystemInitialize for SubSystem: '<S394>/soar_lib' */
}

/* Output and update for atomic system: '<S1>/target_generation_lib' */
void target_generation_lib(uint8_T rtu_gnc_mode, const real_T
  rtu_sc2sun_eci_unit[3], const real_T rtu_sc2targ_eci_unit[3], const real_T
  rtu_r_eci_m[3], const real_T rtu_sc_quat_in[4], const real_T
  rtu_body_rates_radps[3], const real_T rtu_RWA_rpm[4], const real_T
  rtu_quat_soar_cmd[4], real_T rtu_MET_epoch, real_T rtu_MET_utc_s, real_T
  rty_quat_cmd[4], real_T rty_body_rates_cmd[3], real_T rty_torque_body_ff[3],
  uint8_T *rty_target_gen_flag, real_T rty_soar_telemetry[100], real_T
  rty_soar_telemetry_i[30], real_T *rty_soar_telemetry_d, real_T
  rty_soar_telemetry_im[17], uint32_T *rty_soar_telemetry_h)
{
  static const real_T J[9] = { 0.0118206435013, 0.00043170726620000006,
    -7.3061275000000005E-6, 0.00043170726620000006, 0.0116363514485,
    -9.29219316E-5, -7.3061275000000005E-6, -9.29219316E-5, 0.0060345844268 };

  int8_T flag;
  static const real_T c_y[16] = { 0.50000000000000011, 0.0, 0.0, 0.0, 0.0,
    0.50000000000000011, 0.0, 0.0, 0.0, 0.0, 0.50000000000000011, 0.0, 0.0, 0.0,
    0.0, 0.50000000000000011 };

  static const int8_T b[3] = { 0, 1, 0 };

  static const int8_T b_b[3] = { 0, 0, -1 };

  static const int8_T d_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T d_y[16] = { 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2
  };

  static const real_T e_y[16] = { 0.64278760968653936, 0.0, 0.0, 0.0, 0.0,
    0.64278760968653936, 0.0, 0.0, 0.0, 0.0, 0.64278760968653936, 0.0, 0.0, 0.0,
    0.0, 0.64278760968653936 };

  static const int8_T d[21] = { 32, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6 };

  boolean_T rtb_Compare_lr;
  boolean_T rtb_AND;
  boolean_T rtb_FixPtRelationalOperator;
  uint8_T rtb_flag;
  static const real_T tmp[9] = { 0.0118206435013, 0.00043170726620000006,
    -7.3061275000000005E-6, 0.00043170726620000006, 0.0116363514485,
    -9.29219316E-5, -7.3061275000000005E-6, -9.29219316E-5, 0.0060345844268 };

  real_T *V;
  boolean_T exitg1;
  int32_T exitg2;

  /* Product: '<S391>/Product' incorporates:
   *  Constant: '<S391>/wheel_inertia'
   */
  rtDW.Switch_o[0] = rtP.fswParams.allocator.inertia[0] * rtu_RWA_rpm[0];
  rtDW.Switch_o[1] = rtP.fswParams.allocator.inertia[1] * rtu_RWA_rpm[1];
  rtDW.Switch_o[2] = rtP.fswParams.allocator.inertia[2] * rtu_RWA_rpm[2];
  rtDW.Switch_o[3] = rtP.fswParams.allocator.inertia[3] * rtu_RWA_rpm[3];
  for (rtDW.i = 0; rtDW.i < 3; rtDW.i++) {
    /* Product: '<S391>/Product1' incorporates:
     *  Constant: '<S391>/A_wheel2body'
     */
    rtDW.Add = rtP.fswParams.allocator.A_wheel2body[rtDW.i + 9] * rtDW.Switch_o
      [3] + (rtP.fswParams.allocator.A_wheel2body[rtDW.i + 6] * rtDW.Switch_o[2]
             + (rtP.fswParams.allocator.A_wheel2body[rtDW.i + 3] *
                rtDW.Switch_o[1] + rtP.fswParams.allocator.A_wheel2body[rtDW.i] *
                rtDW.Switch_o[0]));

    /* Gain: '<S10>/Gain' */
    rtDW.Sum = rtP.Gain_Gain_o * rtu_r_eci_m[rtDW.i];

    /* Math: '<S392>/Math Function' */
    rtDW.MathFunction[rtDW.i] = rtDW.Sum * rtDW.Sum;

    /* Gain: '<S10>/Gain' */
    rtDW.Gain[rtDW.i] = rtDW.Sum;

    /* Product: '<S391>/Product1' incorporates:
     *  Constant: '<S391>/A_wheel2body'
     */
    rtDW.Product1[rtDW.i] = rtDW.Add;
  }

  /* Sum: '<S392>/Sum of Elements' */
  rtDW.Sum = (rtDW.MathFunction[0] + rtDW.MathFunction[1]) + rtDW.MathFunction[2];

  /* Math: '<S392>/Math Function1'
   *
   * About '<S392>/Math Function1':
   *  Operator: sqrt
   */
  if (rtDW.Sum < 0.0) {
    rtDW.Sum = -sqrt(fabs(rtDW.Sum));
  } else {
    rtDW.Sum = sqrt(rtDW.Sum);
  }

  /* End of Math: '<S392>/Math Function1' */

  /* Switch: '<S392>/Switch' incorporates:
   *  Constant: '<S392>/Constant'
   *  Product: '<S392>/Product'
   */
  if (rtDW.Sum > rtP.NormalizeVector1_maxzero) {
    rtDW.Switch_o[0] = rtDW.Gain[0];
    rtDW.Switch_o[1] = rtDW.Gain[1];
    rtDW.Switch_o[2] = rtDW.Gain[2];
    rtDW.Switch_o[3] = rtDW.Sum;
  } else {
    rtDW.Switch_o[0] = rtDW.Gain[0] * 0.0;
    rtDW.Switch_o[1] = rtDW.Gain[1] * 0.0;
    rtDW.Switch_o[2] = rtDW.Gain[2] * 0.0;
    rtDW.Switch_o[3] = rtP.Constant_Value_c;
  }

  /* End of Switch: '<S392>/Switch' */

  /* MATLAB Function: '<S10>/target_gen' incorporates:
   *  Constant: '<S10>/ss_offset_rad'
   */
  rtb_flag = 0U;
  rtDW.Sum = sin(rtP.fswParams.scParams.ss_offset_rad);
  rtDW.coff = cos(rtP.fswParams.scParams.ss_offset_rad);
  rtDW.C_cmd[0] = rtDW.coff;
  rtDW.C_cmd[3] = rtDW.Sum;
  rtDW.C_cmd[6] = 0.0;
  rtDW.C_cmd[1] = -rtDW.Sum;
  rtDW.C_cmd[4] = rtDW.coff;
  rtDW.C_cmd[7] = 0.0;

  /* Product: '<S392>/Divide' */
  rtDW.Gain[0] = rtDW.Switch_o[0] / rtDW.Switch_o[3];

  /* MATLAB Function: '<S10>/target_gen' */
  rtDW.C_cmd[2] = 0.0;

  /* Product: '<S392>/Divide' */
  rtDW.Gain[1] = rtDW.Switch_o[1] / rtDW.Switch_o[3];

  /* MATLAB Function: '<S10>/target_gen' */
  rtDW.C_cmd[5] = 0.0;

  /* Product: '<S392>/Divide' */
  rtDW.Gain[2] = rtDW.Switch_o[2] / rtDW.Switch_o[3];

  /* MATLAB Function: '<S10>/target_gen' */
  rtDW.C_cmd[8] = 1.0;
  for (rtDW.i = 0; rtDW.i < 3; rtDW.i++) {
    rtDW.MathFunction[rtDW.i] = rtDW.C_cmd[rtDW.i + 3] + rtDW.C_cmd[rtDW.i] *
      0.0;
  }

  if (norm_2e9Xj4lM_g(rtu_sc2sun_eci_unit) < 0.001) {
    memset(&rtDW.C_cmd[0], 0, 9U * sizeof(real_T));
    rtDW.C_cmd[0] = 1.0;
    rtDW.C_cmd[4] = 1.0;
    rtDW.C_cmd[8] = 1.0;
    rtb_flag = 1U;
  } else if (norm_2e9Xj4lM_g(rtu_sc2targ_eci_unit) < 0.001) {
    memset(&rtDW.C_cmd[0], 0, 9U * sizeof(real_T));
    rtDW.C_cmd[0] = 1.0;
    rtDW.C_cmd[4] = 1.0;
    rtDW.C_cmd[8] = 1.0;
    rtb_flag = 2U;
  } else if (norm_2e9Xj4lM_g(rtDW.Gain) < 0.001) {
    memset(&rtDW.C_cmd[0], 0, 9U * sizeof(real_T));
    rtDW.C_cmd[0] = 1.0;
    rtDW.C_cmd[4] = 1.0;
    rtDW.C_cmd[8] = 1.0;
    rtb_flag = 3U;
  } else if ((rtu_gnc_mode == 7) || (rtu_gnc_mode == 8)) {
    if (fabs((rtu_sc2sun_eci_unit[0] * rtu_sc2targ_eci_unit[0] +
              rtu_sc2sun_eci_unit[1] * rtu_sc2targ_eci_unit[1]) +
             rtu_sc2sun_eci_unit[2] * rtu_sc2targ_eci_unit[2]) > 0.999) {
      memset(&rtDW.C_cmd[0], 0, 9U * sizeof(real_T));
      rtDW.C_cmd[0] = 1.0;
      rtDW.C_cmd[4] = 1.0;
      rtDW.C_cmd[8] = 1.0;
      rtb_flag = 4U;
    } else {
      rtDW.rtu_sc2sun_eci_unit_l[0] = rtu_sc2sun_eci_unit[0];
      rtDW.Gain[0] = 0.0;
      rtDW.e[0] = rtu_sc2targ_eci_unit[0];
      rtDW.rtu_sc2sun_eci_unit_l[1] = rtu_sc2sun_eci_unit[1];
      rtDW.Gain[1] = 0.0;
      rtDW.e[1] = rtu_sc2targ_eci_unit[1];
      rtDW.rtu_sc2sun_eci_unit_l[2] = rtu_sc2sun_eci_unit[2];
      rtDW.Gain[2] = -1.0;
      rtDW.e[2] = rtu_sc2targ_eci_unit[2];
      align_vecs_GEQPakmX_m(rtDW.MathFunction, rtDW.rtu_sc2sun_eci_unit_l,
                            rtDW.Gain, rtDW.e, rtDW.C_cmd);
    }
  } else if ((rtu_gnc_mode == 4) || (rtu_gnc_mode == 5) || (rtu_gnc_mode == 6))
  {
    if (fabs((rtDW.Gain[0] * rtu_sc2sun_eci_unit[0] + rtDW.Gain[1] *
              rtu_sc2sun_eci_unit[1]) + rtDW.Gain[2] * rtu_sc2sun_eci_unit[2]) >
        0.999) {
      memset(&rtDW.C_cmd[0], 0, 9U * sizeof(real_T));
      rtDW.C_cmd[0] = 1.0;
      rtDW.C_cmd[4] = 1.0;
      rtDW.C_cmd[8] = 1.0;
      rtb_flag = 5U;
    } else {
      rtDW.rtu_sc2sun_eci_unit_l[0] = rtu_sc2sun_eci_unit[0];
      rtDW.e[0] = 0.0;
      rtDW.rtb_Gain_dh[0] = rtDW.Gain[0];
      rtDW.rtu_sc2sun_eci_unit_l[1] = rtu_sc2sun_eci_unit[1];
      rtDW.e[1] = 0.0;
      rtDW.rtb_Gain_dh[1] = rtDW.Gain[1];
      rtDW.rtu_sc2sun_eci_unit_l[2] = rtu_sc2sun_eci_unit[2];
      rtDW.e[2] = 1.0;
      rtDW.rtb_Gain_dh[2] = rtDW.Gain[2];
      align_vecs_GEQPakmX_m(rtDW.MathFunction, rtDW.rtu_sc2sun_eci_unit_l,
                            rtDW.e, rtDW.rtb_Gain_dh, rtDW.C_cmd);
    }
  } else {
    memset(&rtDW.C_cmd[0], 0, 9U * sizeof(real_T));
    rtDW.C_cmd[0] = 1.0;
    rtDW.C_cmd[4] = 1.0;
    rtDW.C_cmd[8] = 1.0;
  }

  /* Sum: '<S400>/Add' */
  rtDW.Add = (rtDW.C_cmd[0] + rtDW.C_cmd[4]) + rtDW.C_cmd[8];

  /* If: '<S390>/If' */
  if (rtDW.Add > 0.0) {
    /* Outputs for IfAction SubSystem: '<S390>/Positive Trace' incorporates:
     *  ActionPort: '<S398>/Action Port'
     */
    PositiveTrace(rtDW.Add, rtDW.C_cmd, &rtDW.Merge_n[0], &rtDW.Merge_n[1],
                  &rtP.PositiveTrace_p);

    /* End of Outputs for SubSystem: '<S390>/Positive Trace' */
  } else {
    /* Outputs for IfAction SubSystem: '<S390>/Negative Trace' incorporates:
     *  ActionPort: '<S397>/Action Port'
     */
    NegativeTrace(rtDW.C_cmd, rtDW.Merge_n, &rtP.NegativeTrace_l);

    /* End of Outputs for SubSystem: '<S390>/Negative Trace' */
  }

  /* End of If: '<S390>/If' */

  /* Reshape: '<S10>/Reshape' incorporates:
   *  Math: '<S10>/Transpose'
   */
  rtDW.Reshape[0] = rtDW.Merge_n[0];

  /* Math: '<S10>/Transpose' */
  rtDW.Switch_o[0] = rtDW.Merge_n[0];

  /* Reshape: '<S10>/Reshape' incorporates:
   *  Math: '<S10>/Transpose'
   */
  rtDW.Reshape[1] = rtDW.Merge_n[1];

  /* Math: '<S10>/Transpose' */
  rtDW.Switch_o[1] = rtDW.Merge_n[1];

  /* Reshape: '<S10>/Reshape' incorporates:
   *  Math: '<S10>/Transpose'
   */
  rtDW.Reshape[2] = rtDW.Merge_n[2];

  /* Math: '<S10>/Transpose' */
  rtDW.Switch_o[2] = rtDW.Merge_n[2];

  /* Reshape: '<S10>/Reshape' incorporates:
   *  Math: '<S10>/Transpose'
   */
  rtDW.Reshape[3] = rtDW.Merge_n[3];

  /* Math: '<S10>/Transpose' */
  rtDW.Switch_o[3] = rtDW.Merge_n[3];

  /* Outputs for Atomic SubSystem: '<S10>/quat_rectify_lib' */
  quat_rectify_lib(rtDW.Reshape, rtDW.Switch_o, &rtP.quat_rectify_lib_l);

  /* End of Outputs for SubSystem: '<S10>/quat_rectify_lib' */

  /* Switch: '<S10>/Switch' */
  if (rtu_MET_epoch != 0.0) {
    rtDW.Reshape[0] = rtu_quat_soar_cmd[0];
    rtDW.Reshape[1] = rtu_quat_soar_cmd[1];
    rtDW.Reshape[2] = rtu_quat_soar_cmd[2];
    rtDW.Reshape[3] = rtu_quat_soar_cmd[3];
  } else {
    rtDW.Reshape[0] = rtDW.Switch_o[0];
    rtDW.Reshape[1] = rtDW.Switch_o[1];
    rtDW.Reshape[2] = rtDW.Switch_o[2];
    rtDW.Reshape[3] = rtDW.Switch_o[3];
  }

  /* End of Switch: '<S10>/Switch' */

  /* RelationalOperator: '<S439>/Compare' incorporates:
   *  Constant: '<S435>/Constant'
   *  Constant: '<S439>/Constant'
   *  RelationalOperator: '<S435>/Compare'
   */
  rtb_Compare_lr = ((rtu_gnc_mode == rtP.CompareToConstant_const_f2) > (int32_T)
                    rtP.Constant_Value_h4);

  /* RelationalOperator: '<S436>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S436>/Delay Input1'
   *
   * Block description for '<S436>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)rtb_Compare_lr > (int32_T)
    rtDW.DelayInput1_DSTATE);

  /* Outputs for Triggered SubSystem: '<S394>/soar_lib' incorporates:
   *  TriggerPort: '<S438>/Trigger'
   */
  if (rtb_FixPtRelationalOperator && (rtPrevZCX.soar_lib_Trig_ZCE != POS_ZCSIG))
  {
    /* MATLAB Function: '<S438>/INITIALIZE' incorporates:
     *  Constant: '<S10>/Constant'
     */
    memcpy(&rtDW.J[0], &tmp[0], 9U * sizeof(real_T));
    rtDW.Add = (rtu_sc2sun_eci_unit[0] * 0.0 + rtu_sc2sun_eci_unit[1] * 0.0) +
      -rtu_sc2sun_eci_unit[2];
    rtDW.Sum = (rtu_sc2sun_eci_unit[0] * 0.0 + rtu_sc2sun_eci_unit[1]) +
      rtu_sc2sun_eci_unit[2] * 0.0;
    rtDW.dv2[0] = 0.0;
    rtDW.dv2[3] = -rtu_sc2sun_eci_unit[2];
    rtDW.dv2[6] = rtu_sc2sun_eci_unit[1];
    rtDW.dv2[1] = rtu_sc2sun_eci_unit[2];
    rtDW.dv2[4] = 0.0;
    rtDW.dv2[7] = -rtu_sc2sun_eci_unit[0];
    rtDW.dv2[2] = -rtu_sc2sun_eci_unit[1];
    rtDW.dv2[5] = rtu_sc2sun_eci_unit[0];
    rtDW.dv2[8] = 0.0;
    rtDW.dv3[0] = 0.0;
    rtDW.dv3[3] = -rtu_sc2sun_eci_unit[2];
    rtDW.dv3[6] = rtu_sc2sun_eci_unit[1];
    rtDW.dv3[1] = rtu_sc2sun_eci_unit[2];
    rtDW.dv3[4] = 0.0;
    rtDW.dv3[7] = -rtu_sc2sun_eci_unit[0];
    rtDW.dv3[2] = -rtu_sc2sun_eci_unit[1];
    rtDW.dv3[5] = rtu_sc2sun_eci_unit[0];
    rtDW.dv3[8] = 0.0;
    rtDW.MI_f[0] = rtDW.Add;
    for (rtDW.i = 0; rtDW.i < 3; rtDW.i++) {
      rtDW.rtu_sc2sun_eci_unit[rtDW.i] = rtu_sc2sun_eci_unit[rtDW.i] * 0.0;
      rtDW.b_b[rtDW.i] = (real_T)b_b[rtDW.i] * rtu_sc2sun_eci_unit[0];
      rtDW.rtu_sc2sun_eci_unit[rtDW.i + 3] = rtu_sc2sun_eci_unit[rtDW.i] * 0.0;
      rtDW.b_b[rtDW.i + 3] = (real_T)b_b[rtDW.i] * rtu_sc2sun_eci_unit[1];
      rtDW.rtu_sc2sun_eci_unit[rtDW.i + 6] = -rtu_sc2sun_eci_unit[rtDW.i];
      rtDW.b_b[rtDW.i + 6] = (real_T)b_b[rtDW.i] * rtu_sc2sun_eci_unit[2];
      rtDW.MI_f[(rtDW.i + 1) << 2] = -rtDW.dv2[rtDW.i + 6] + (rtDW.dv2[rtDW.i +
        3] * 0.0 + rtDW.dv2[rtDW.i] * 0.0);
      rtDW.MI_f[rtDW.i + 1] = -rtDW.dv3[rtDW.i + 6] + (rtDW.dv3[rtDW.i + 3] *
        0.0 + rtDW.dv3[rtDW.i] * 0.0);
    }

    for (rtDW.i = 0; rtDW.i < 3; rtDW.i++) {
      rtDW.n = (rtDW.i + 1) << 2;
      rtDW.MI_f[1 + rtDW.n] = (rtDW.rtu_sc2sun_eci_unit[3 * rtDW.i] + rtDW.b_b[3
        * rtDW.i]) - (real_T)d_b[3 * rtDW.i] * rtDW.Add;
      rtDW.rtu_sc2sun_eci_unit_tmp = 3 * rtDW.i + 1;
      rtDW.MI_f[2 + rtDW.n] =
        (rtDW.rtu_sc2sun_eci_unit[rtDW.rtu_sc2sun_eci_unit_tmp] +
         rtDW.b_b[rtDW.rtu_sc2sun_eci_unit_tmp]) - (real_T)
        d_b[rtDW.rtu_sc2sun_eci_unit_tmp] * rtDW.Add;
      rtDW.rtu_sc2sun_eci_unit_tmp = 3 * rtDW.i + 2;
      rtDW.MI_f[3 + rtDW.n] =
        (rtDW.rtu_sc2sun_eci_unit[rtDW.rtu_sc2sun_eci_unit_tmp] +
         rtDW.b_b[rtDW.rtu_sc2sun_eci_unit_tmp]) - (real_T)
        d_b[rtDW.rtu_sc2sun_eci_unit_tmp] * rtDW.Add;
    }

    for (rtDW.i = 0; rtDW.i < 16; rtDW.i++) {
      rtDW.Mi[rtDW.i] = (rtDW.MI_f[rtDW.i] - e_y[rtDW.i]) + (real_T)d_y[rtDW.i];
    }

    schur_hD1lAh31_m(rtDW.Mi, rtDW.MI_f, rtDW.De);
    rtDW.dv2[0] = 0.0;
    rtDW.dv2[3] = -rtu_sc2sun_eci_unit[2];
    rtDW.dv2[6] = rtu_sc2sun_eci_unit[1];
    rtDW.dv2[1] = rtu_sc2sun_eci_unit[2];
    rtDW.dv2[4] = 0.0;
    rtDW.dv2[7] = -rtu_sc2sun_eci_unit[0];
    rtDW.dv2[2] = -rtu_sc2sun_eci_unit[1];
    rtDW.dv2[5] = rtu_sc2sun_eci_unit[0];
    rtDW.dv2[8] = 0.0;
    rtDW.dv3[0] = 0.0;
    rtDW.dv3[3] = -rtu_sc2sun_eci_unit[2];
    rtDW.dv3[6] = rtu_sc2sun_eci_unit[1];
    rtDW.dv3[1] = rtu_sc2sun_eci_unit[2];
    rtDW.dv3[4] = 0.0;
    rtDW.dv3[7] = -rtu_sc2sun_eci_unit[0];
    rtDW.dv3[2] = -rtu_sc2sun_eci_unit[1];
    rtDW.dv3[5] = rtu_sc2sun_eci_unit[0];
    rtDW.dv3[8] = 0.0;
    rtDW.Mi[0] = rtDW.Sum;
    for (rtDW.i = 0; rtDW.i < 3; rtDW.i++) {
      rtDW.rtu_sc2sun_eci_unit[rtDW.i] = rtu_sc2sun_eci_unit[rtDW.i] * 0.0;
      rtDW.b_b[rtDW.i] = (real_T)b[rtDW.i] * rtu_sc2sun_eci_unit[0];
      rtDW.rtu_sc2sun_eci_unit[rtDW.i + 3] = rtu_sc2sun_eci_unit[rtDW.i];
      rtDW.b_b[rtDW.i + 3] = (real_T)b[rtDW.i] * rtu_sc2sun_eci_unit[1];
      rtDW.rtu_sc2sun_eci_unit[rtDW.i + 6] = rtu_sc2sun_eci_unit[rtDW.i] * 0.0;
      rtDW.b_b[rtDW.i + 6] = (real_T)b[rtDW.i] * rtu_sc2sun_eci_unit[2];
      rtDW.Mi[(rtDW.i + 1) << 2] = rtDW.dv2[rtDW.i + 6] * 0.0 + (rtDW.dv2[rtDW.i
        + 3] + rtDW.dv2[rtDW.i] * 0.0);
      rtDW.Mi[rtDW.i + 1] = rtDW.dv3[rtDW.i + 6] * 0.0 + (rtDW.dv3[rtDW.i + 3] +
        rtDW.dv3[rtDW.i] * 0.0);
    }

    for (rtDW.i = 0; rtDW.i < 3; rtDW.i++) {
      rtDW.n = (rtDW.i + 1) << 2;
      rtDW.Mi[1 + rtDW.n] = (rtDW.rtu_sc2sun_eci_unit[3 * rtDW.i] + rtDW.b_b[3 *
        rtDW.i]) - (real_T)d_b[3 * rtDW.i] * rtDW.Sum;
      rtDW.rtu_sc2sun_eci_unit_tmp = 3 * rtDW.i + 1;
      rtDW.Mi[2 + rtDW.n] =
        (rtDW.rtu_sc2sun_eci_unit[rtDW.rtu_sc2sun_eci_unit_tmp] +
         rtDW.b_b[rtDW.rtu_sc2sun_eci_unit_tmp]) - (real_T)
        d_b[rtDW.rtu_sc2sun_eci_unit_tmp] * rtDW.Sum;
      rtDW.rtu_sc2sun_eci_unit_tmp = 3 * rtDW.i + 2;
      rtDW.Mi[3 + rtDW.n] =
        (rtDW.rtu_sc2sun_eci_unit[rtDW.rtu_sc2sun_eci_unit_tmp] +
         rtDW.b_b[rtDW.rtu_sc2sun_eci_unit_tmp]) - (real_T)
        d_b[rtDW.rtu_sc2sun_eci_unit_tmp] * rtDW.Sum;
    }

    for (rtDW.i = 0; rtDW.i < 16; rtDW.i++) {
      rtDW.d_y[rtDW.i] = (real_T)d_y[rtDW.i] - (rtDW.Mi[rtDW.i] - c_y[rtDW.i]);
    }

    schur_hD1lAh31_m(rtDW.d_y, rtDW.Mi, rtDW.Di);
    rtDW.De[0] = sqrt(rtDW.De[0]);
    rtDW.Di[0] = sqrt(rtDW.Di[0]);
    rtDW.De[5] = sqrt(rtDW.De[5]);
    rtDW.Di[5] = sqrt(rtDW.Di[5]);
    rtDW.De[10] = sqrt(rtDW.De[10]);
    rtDW.Di[10] = sqrt(rtDW.Di[10]);
    rtDW.De[15] = sqrt(rtDW.De[15]);
    rtDW.Di[15] = sqrt(rtDW.Di[15]);
    for (rtDW.i = 0; rtDW.i < 4; rtDW.i++) {
      for (rtDW.n = 0; rtDW.n < 4; rtDW.n++) {
        rtDW.rtu_sc2sun_eci_unit_tmp = rtDW.n << 2;
        rtDW.rtb_MI_tmp = rtDW.i + rtDW.rtu_sc2sun_eci_unit_tmp;
        rtDW.d_y[rtDW.rtb_MI_tmp] = 0.0;
        rtDW.rtb_MI_tmp_c = rtDW.rtu_sc2sun_eci_unit_tmp + rtDW.i;
        rtDW.d_y[rtDW.rtb_MI_tmp] = rtDW.d_y[rtDW.rtb_MI_tmp_c] +
          rtDW.De[rtDW.rtu_sc2sun_eci_unit_tmp] * rtDW.MI_f[rtDW.i];
        rtDW.d_y[rtDW.rtb_MI_tmp] = rtDW.De[rtDW.rtu_sc2sun_eci_unit_tmp + 1] *
          rtDW.MI_f[rtDW.i + 4] + rtDW.d_y[rtDW.rtb_MI_tmp_c];
        rtDW.d_y[rtDW.rtb_MI_tmp] = rtDW.De[rtDW.rtu_sc2sun_eci_unit_tmp + 2] *
          rtDW.MI_f[rtDW.i + 8] + rtDW.d_y[rtDW.rtb_MI_tmp_c];
        rtDW.d_y[rtDW.rtb_MI_tmp] = rtDW.De[rtDW.rtu_sc2sun_eci_unit_tmp + 3] *
          rtDW.MI_f[rtDW.i + 12] + rtDW.d_y[rtDW.rtb_MI_tmp_c];
      }

      for (rtDW.n = 0; rtDW.n < 4; rtDW.n++) {
        rtDW.rtu_sc2sun_eci_unit_tmp = rtDW.n << 2;
        rtDW.rtb_MI_tmp = rtDW.i + rtDW.rtu_sc2sun_eci_unit_tmp;
        rtDW.ME[rtDW.rtb_MI_tmp] = 0.0;
        rtDW.Mi_g[rtDW.rtb_MI_tmp] = 0.0;
        rtDW.rtb_MI_tmp_c = rtDW.rtu_sc2sun_eci_unit_tmp + rtDW.i;
        rtDW.ME[rtDW.rtb_MI_tmp] = rtDW.ME[rtDW.rtb_MI_tmp_c] + rtDW.d_y[rtDW.i]
          * rtDW.MI_f[rtDW.n];
        rtDW.Mi_g[rtDW.rtb_MI_tmp] = rtDW.Mi_g[rtDW.rtb_MI_tmp_c] +
          rtDW.Di[rtDW.rtu_sc2sun_eci_unit_tmp] * rtDW.Mi[rtDW.i];
        rtDW.ME[rtDW.rtb_MI_tmp] = rtDW.ME[rtDW.rtb_MI_tmp_c] + rtDW.d_y[rtDW.i
          + 4] * rtDW.MI_f[rtDW.n + 4];
        rtDW.Mi_g[rtDW.rtb_MI_tmp] = rtDW.Di[rtDW.rtu_sc2sun_eci_unit_tmp + 1] *
          rtDW.Mi[rtDW.i + 4] + rtDW.Mi_g[rtDW.rtb_MI_tmp_c];
        rtDW.ME[rtDW.rtb_MI_tmp] = rtDW.ME[rtDW.rtb_MI_tmp_c] + rtDW.d_y[rtDW.i
          + 8] * rtDW.MI_f[rtDW.n + 8];
        rtDW.Mi_g[rtDW.rtb_MI_tmp] = rtDW.Di[rtDW.rtu_sc2sun_eci_unit_tmp + 2] *
          rtDW.Mi[rtDW.i + 8] + rtDW.Mi_g[rtDW.rtb_MI_tmp_c];
        rtDW.ME[rtDW.rtb_MI_tmp] = rtDW.ME[rtDW.rtb_MI_tmp_c] + rtDW.d_y[rtDW.i
          + 12] * rtDW.MI_f[rtDW.n + 12];
        rtDW.Mi_g[rtDW.rtb_MI_tmp] = rtDW.Di[rtDW.rtu_sc2sun_eci_unit_tmp + 3] *
          rtDW.Mi[rtDW.i + 12] + rtDW.Mi_g[rtDW.rtb_MI_tmp_c];
      }
    }

    for (rtDW.i = 0; rtDW.i < 4; rtDW.i++) {
      for (rtDW.n = 0; rtDW.n < 4; rtDW.n++) {
        rtDW.rtu_sc2sun_eci_unit_tmp = rtDW.n << 2;
        rtDW.rtb_MI_tmp = rtDW.i + rtDW.rtu_sc2sun_eci_unit_tmp;
        rtDW.MI_f[rtDW.rtb_MI_tmp] = 0.0;
        rtDW.rtu_sc2sun_eci_unit_tmp += rtDW.i;
        rtDW.MI_f[rtDW.rtb_MI_tmp] = rtDW.MI_f[rtDW.rtu_sc2sun_eci_unit_tmp] +
          rtDW.Mi_g[rtDW.i] * rtDW.Mi[rtDW.n];
        rtDW.MI_f[rtDW.rtb_MI_tmp] = rtDW.MI_f[rtDW.rtu_sc2sun_eci_unit_tmp] +
          rtDW.Mi_g[rtDW.i + 4] * rtDW.Mi[rtDW.n + 4];
        rtDW.MI_f[rtDW.rtb_MI_tmp] = rtDW.MI_f[rtDW.rtu_sc2sun_eci_unit_tmp] +
          rtDW.Mi_g[rtDW.i + 8] * rtDW.Mi[rtDW.n + 8];
        rtDW.MI_f[rtDW.rtb_MI_tmp] = rtDW.MI_f[rtDW.rtu_sc2sun_eci_unit_tmp] +
          rtDW.Mi_g[rtDW.i + 12] * rtDW.Mi[rtDW.n + 12];
      }
    }

    memset(&rtDW.X_l[0], 0, 100U * sizeof(real_T));
    memset(&rtDW.U[0], 0, 30U * sizeof(real_T));
    rtDW.s = 25.0;
    flag = 0;
    rtDW.Add = ((rtu_sc_quat_in[0] * rtDW.Reshape[0] + rtu_sc_quat_in[1] *
                 rtDW.Reshape[1]) + rtu_sc_quat_in[2] * rtDW.Reshape[2]) +
      rtu_sc_quat_in[3] * rtDW.Reshape[3];
    if (1.0 - rtDW.Add < 0.0) {
      rtDW.Add = 0.0;
    } else {
      rtDW.Add = acos(rtDW.Add);
    }

    if (rtDW.Add > 3.1415926535897931) {
      flag = 2;
      for (rtDW.n = 0; rtDW.n < 10; rtDW.n++) {
        rtDW.i = rtDW.n << 2;
        rtDW.qb[rtDW.i] = 1.0;
        rtDW.qb[rtDW.i + 1] = 0.0;
        rtDW.qb[rtDW.i + 2] = 0.0;
        rtDW.qb[rtDW.i + 3] = 0.0;
      }
    } else {
      rtDW.Sum = sin(rtDW.Add);
      if (rtDW.Sum < 1.0E-8) {
        for (rtDW.n = 0; rtDW.n < 10; rtDW.n++) {
          rtDW.i = rtDW.n << 2;
          rtDW.qb[rtDW.i] = rtu_sc_quat_in[0];
          rtDW.qb[rtDW.i + 1] = rtu_sc_quat_in[1];
          rtDW.qb[rtDW.i + 2] = rtu_sc_quat_in[2];
          rtDW.qb[rtDW.i + 3] = rtu_sc_quat_in[3];
        }
      } else {
        for (rtDW.n = 0; rtDW.n < 10; rtDW.n++) {
          rtDW.t = ((1.0 + (real_T)rtDW.n) - 1.0) / 9.0;
          rtDW.coff = sin((1.0 - rtDW.t) * rtDW.Add);
          rtDW.t = sin(rtDW.t * rtDW.Add);
          rtDW.coff /= rtDW.Sum;
          rtDW.t /= rtDW.Sum;
          rtDW.i = rtDW.n << 2;
          rtDW.qb[rtDW.i] = rtDW.coff * rtu_sc_quat_in[0] + rtDW.t *
            rtDW.Reshape[0];
          rtDW.qb[1 + rtDW.i] = rtDW.coff * rtu_sc_quat_in[1] + rtDW.t *
            rtDW.Reshape[1];
          rtDW.qb[2 + rtDW.i] = rtDW.coff * rtu_sc_quat_in[2] + rtDW.t *
            rtDW.Reshape[2];
          rtDW.qb[3 + rtDW.i] = rtDW.coff * rtu_sc_quat_in[3] + rtDW.t *
            rtDW.Reshape[3];
        }
      }
    }

    if (flag == 0) {
      for (rtDW.n = 0; rtDW.n < 10; rtDW.n++) {
        rtDW.Add = 0.1111111111111111 * (real_T)rtDW.n;
        if (rtDW.Add == 0.0) {
          rtDW.Gain[0] = rtu_body_rates_radps[0];
          rtDW.Gain[1] = rtu_body_rates_radps[1];
          rtDW.Gain[2] = rtu_body_rates_radps[2];
        } else {
          if (rtDW.Add == 1.0) {
            rtDW.Gain[0] = rtP.Constant_Value_e3[0];
          } else if (rtu_body_rates_radps[0] == rtP.Constant_Value_e3[0]) {
            rtDW.Gain[0] = rtu_body_rates_radps[0];
          } else {
            rtDW.Gain[0] = (1.0 - rtDW.Add) * rtu_body_rates_radps[0] + rtDW.Add
              * rtP.Constant_Value_e3[0];
          }

          if (rtDW.Add == 1.0) {
            rtDW.Gain[1] = rtP.Constant_Value_e3[1];
          } else if (rtu_body_rates_radps[1] == rtP.Constant_Value_e3[1]) {
            rtDW.Gain[1] = rtu_body_rates_radps[1];
          } else {
            rtDW.Gain[1] = (1.0 - rtDW.Add) * rtu_body_rates_radps[1] + rtDW.Add
              * rtP.Constant_Value_e3[1];
          }

          if (rtDW.Add == 1.0) {
            rtDW.Gain[2] = rtP.Constant_Value_e3[2];
          } else if (rtu_body_rates_radps[2] == rtP.Constant_Value_e3[2]) {
            rtDW.Gain[2] = rtu_body_rates_radps[2];
          } else {
            rtDW.Gain[2] = (1.0 - rtDW.Add) * rtu_body_rates_radps[2] + rtDW.Add
              * rtP.Constant_Value_e3[2];
          }
        }

        for (rtDW.i = 0; rtDW.i < 3; rtDW.i++) {
          rtDW.MathFunction[rtDW.i] = rtDW.J[rtDW.i + 6] * rtDW.Gain[2] +
            (rtDW.J[rtDW.i + 3] * rtDW.Gain[1] + rtDW.J[rtDW.i] * rtDW.Gain[0]);
        }

        rtDW.X_l[10 * rtDW.n] = rtDW.qb[rtDW.n << 2];
        rtDW.X_l[1 + 10 * rtDW.n] = rtDW.qb[(rtDW.n << 2) + 1];
        rtDW.X_l[2 + 10 * rtDW.n] = rtDW.qb[(rtDW.n << 2) + 2];
        rtDW.X_l[3 + 10 * rtDW.n] = rtDW.qb[(rtDW.n << 2) + 3];
        rtDW.X_l[4 + 10 * rtDW.n] = rtDW.MathFunction[0];
        rtDW.X_l[7 + 10 * rtDW.n] = rtDW.Product1[0];
        rtDW.U[3 * rtDW.n] = 0.0;
        rtDW.X_l[5 + 10 * rtDW.n] = rtDW.MathFunction[1];
        rtDW.X_l[8 + 10 * rtDW.n] = rtDW.Product1[1];
        rtDW.U[1 + 3 * rtDW.n] = 0.0;
        rtDW.X_l[6 + 10 * rtDW.n] = rtDW.MathFunction[2];
        rtDW.X_l[9 + 10 * rtDW.n] = rtDW.Product1[2];
        rtDW.U[2 + 3 * rtDW.n] = 0.0;
      }
    }

    /* MATLAB Function: '<S438>/SOLVE' incorporates:
     *  MATLAB Function: '<S438>/INITIALIZE'
     */
    for (rtDW.i = 0; rtDW.i < 100; rtDW.i++) {
      rty_soar_telemetry[rtDW.i] = rtDW.X_l[rtDW.i];
    }

    for (rtDW.i = 0; rtDW.i < 30; rtDW.i++) {
      rty_soar_telemetry_i[rtDW.i] = rtDW.U[rtDW.i];
    }

    *rty_soar_telemetry_d = rtDW.s;
    rtDW.Add = *rty_soar_telemetry_d;
    memset(&rtDW.exitcode_c[0], 0, 17U * sizeof(real_T));
    if (flag == 0) {
      for (rtDW.i = 0; rtDW.i < 10; rtDW.i++) {
        rtDW.xi[rtDW.i] = rty_soar_telemetry[rtDW.i];
      }

      for (rtDW.i = 0; rtDW.i < 7; rtDW.i++) {
        rtDW.xf[rtDW.i] = rty_soar_telemetry[rtDW.i + 90];
      }

      rtDW.rtu_sc2sun_eci_unit_tmp = 1;
      rtDW.n = 0;
      exitg1 = false;
      while ((!exitg1) && (rtDW.n < 15)) {
        rtDW.rtu_sc2sun_eci_unit_tmp = rtDW.n + 1;
        foh_OxYXiak1_m(rty_soar_telemetry, rty_soar_telemetry_i, rtDW.Add,
                       rtDW.J, rtDW.EH, rtDW.BE, rtDW.ES, rtDW.AR);
        parse_ecos_4lHXAQLu_p(rtDW.xi, rtDW.xf, rtDW.J, rtDW.EH, rtDW.BE,
                              rtDW.ES, rtDW.AR, rtDW.ME, rtDW.MI_f, 0.0028, 0.1,
                              25.0, 15.0, 100.0, rtDW.c, rtDW.G, rtDW.h, rtDW.A,
                              rtDW.b);
        convert_to_CCS_TWUhmVkC_j(rtDW.A, rtDW.Air, rtDW.Ajc, rtDW.Apr);
        convert_to_CCS_uvSSMF4Z_o(rtDW.G, rtDW.Gir, rtDW.Gjc, rtDW.Gpr);
        for (rtDW.i = 0; rtDW.i < 21; rtDW.i++) {
          rtDW.d[rtDW.i] = d[rtDW.i];
        }

        run_ecos(332, 474, 117, 322, 21, rtDW.c, rtDW.Gjc, rtDW.Gir, rtDW.Gpr,
                 rtDW.h, rtDW.d, rtDW.Ajc, rtDW.Air, rtDW.Apr, rtDW.b, rtDW.y);
        for (rtDW.i = 0; rtDW.i < 100; rtDW.i++) {
          rtDW.ES[rtDW.i] = rty_soar_telemetry[rtDW.i] - rtDW.y[rtDW.i];
        }

        rtDW.diff = norm_ajWdQkav(rtDW.ES);
        for (rtDW.i = 0; rtDW.i < 100; rtDW.i++) {
          rty_soar_telemetry[rtDW.i] = rtDW.y[rtDW.i];
        }

        for (rtDW.i = 0; rtDW.i < 30; rtDW.i++) {
          rty_soar_telemetry_i[rtDW.i] = rtDW.y[100 + rtDW.i];
        }

        rtDW.Add = rtDW.y[131];
        V = &rtDW.y[132];
        rtDW.exitcode_c[rtDW.n] = rtDW.y[332];
        if (rtDW.exitcode_c[rtDW.n] != 0.0) {
          rtDW.exitcode_c[16] = -1.0;
        }

        if ((1 + rtDW.n > 1) && (norm_UjNDAYVY(&rtDW.y[132]) < 1.0E-5) &&
            (rtDW.diff < 0.01)) {
          rtDW.exitcode_c[15] = 1.0 + (real_T)rtDW.n;
          exitg1 = true;
        } else {
          rtDW.n++;
        }
      }

      if (rtDW.rtu_sc2sun_eci_unit_tmp == 15) {
        rtDW.exitcode_c[15] = 15.0;
        if (rtDW.exitcode_c[16] != -1.0) {
          if (norm_UjNDAYVY(V) > 1.0E-5) {
            rtDW.exitcode_c[16] = 3.0;
          } else {
            if (rtDW.diff > 0.05) {
              rtDW.exitcode_c[16] = 4.0;
            }
          }
        }
      }
    } else {
      rtDW.exitcode_c[16] = flag;
      for (rtDW.i = 0; rtDW.i < 100; rtDW.i++) {
        rty_soar_telemetry[rtDW.i] = 0.0;
      }

      for (rtDW.i = 0; rtDW.i < 30; rtDW.i++) {
        rty_soar_telemetry_i[rtDW.i] = 0.0;
      }

      rtDW.Add = 25.0;
    }

    *rty_soar_telemetry_d = rtDW.Add;
    memcpy(&rty_soar_telemetry_im[0], &rtDW.exitcode_c[0], 17U * sizeof(real_T));

    /* End of MATLAB Function: '<S438>/SOLVE' */
  }

  rtPrevZCX.soar_lib_Trig_ZCE = rtb_FixPtRelationalOperator;

  /* End of Outputs for SubSystem: '<S394>/soar_lib' */

  /* Sum: '<S394>/Sum' */
  rtDW.Sum = rtu_MET_utc_s - rtu_MET_epoch;

  /* Switch: '<S437>/Switch' incorporates:
   *  UnitDelay: '<S437>/Unit Delay'
   */
  if (rtb_FixPtRelationalOperator) {
    rtDW.diff = rtDW.Sum;
  } else {
    rtDW.diff = rtDW.UnitDelay_DSTATE_p;
  }

  /* End of Switch: '<S437>/Switch' */

  /* Sum: '<S437>/Subtract' */
  rtDW.Add = rtDW.Sum - rtDW.diff;

  /* Delay: '<S437>/Resettable Delay' incorporates:
   *  SignalConversion: '<S437>/TmpSignal ConversionAtResettable DelayInport3'
   */
  if (rtb_FixPtRelationalOperator && (rtPrevZCX.ResettableDelay_Reset_ZCE !=
       POS_ZCSIG)) {
    rtDW.icLoad = 1U;
  }

  rtPrevZCX.ResettableDelay_Reset_ZCE = rtb_FixPtRelationalOperator;
  if (rtDW.icLoad != 0) {
    rtDW.ResettableDelay_DSTATE[0] = rtu_sc_quat_in[0];
    rtDW.ResettableDelay_DSTATE[1] = rtu_sc_quat_in[1];
    rtDW.ResettableDelay_DSTATE[2] = rtu_sc_quat_in[2];
    rtDW.ResettableDelay_DSTATE[3] = rtu_sc_quat_in[3];
    rtDW.ResettableDelay_DSTATE[4] = rtu_body_rates_radps[0];
    rtDW.ResettableDelay_DSTATE[7] = rtDW.Product1[0];
    rtDW.ResettableDelay_DSTATE[5] = rtu_body_rates_radps[1];
    rtDW.ResettableDelay_DSTATE[8] = rtDW.Product1[1];
    rtDW.ResettableDelay_DSTATE[6] = rtu_body_rates_radps[2];
    rtDW.ResettableDelay_DSTATE[9] = rtDW.Product1[2];
  }

  /* MATLAB Function: '<S437>/soar_INTERP' incorporates:
   *  Delay: '<S437>/Resettable Delay'
   */
  rtDW.xi[9] = *rty_soar_telemetry_d;
  rtDW.xi[0] = 0.0;
  if ((*rty_soar_telemetry_d < 0.0) && (fabs(*rty_soar_telemetry_d) >
       8.9884656743115785E+307)) {
    rtDW.Sum = *rty_soar_telemetry_d / 9.0;
    for (rtDW.rtu_sc2sun_eci_unit_tmp = 0; rtDW.rtu_sc2sun_eci_unit_tmp < 8;
         rtDW.rtu_sc2sun_eci_unit_tmp++) {
      rtDW.xi[rtDW.rtu_sc2sun_eci_unit_tmp + 1] = (1.0 + (real_T)
        rtDW.rtu_sc2sun_eci_unit_tmp) * rtDW.Sum;
    }
  } else {
    rtDW.Sum = *rty_soar_telemetry_d / 9.0;
    for (rtDW.n = 0; rtDW.n < 8; rtDW.n++) {
      rtDW.xi[rtDW.n + 1] = (1.0 + (real_T)rtDW.n) * rtDW.Sum;
    }
  }

  if ((*rty_soar_telemetry_d > 2.2204460492503131E-16) && (rtDW.Add >=
       *rty_soar_telemetry_d)) {
    rtDW.Product1[0] = 0.0;
    rtDW.Product1[1] = 0.0;
    rtDW.Product1[2] = 0.0;
    mldivide_FcIbHgdz_o(J, &rty_soar_telemetry[94], rtDW.Gain);
    rtDW.x_opt_t[0] = rty_soar_telemetry[90];
    rtDW.x_opt_t[1] = rty_soar_telemetry[91];
    rtDW.x_opt_t[2] = rty_soar_telemetry[92];
    rtDW.x_opt_t[3] = rty_soar_telemetry[93];
    rtDW.x_opt_t[4] = rtDW.Gain[0];
    rtDW.x_opt_t[5] = rtDW.Gain[1];
    rtDW.x_opt_t[6] = rtDW.Gain[2];
    rtDW.x_opt_t[7] = rty_soar_telemetry[97];
    rtDW.x_opt_t[8] = rty_soar_telemetry[98];
    rtDW.x_opt_t[9] = rty_soar_telemetry[99];
  } else if (*rty_soar_telemetry_d > 2.2204460492503131E-16) {
    memcpy(&rtDW.x_opt_t[0], &rtDW.ResettableDelay_DSTATE[0], 10U * sizeof
           (real_T));
    for (rtDW.rtu_sc2sun_eci_unit_tmp = 0; rtDW.rtu_sc2sun_eci_unit_tmp < 10;
         rtDW.rtu_sc2sun_eci_unit_tmp++) {
      deriv_3jC2Hyd6_i(rtDW.Add, rtDW.x_opt_t, rty_soar_telemetry_i, rtDW.xi, J,
                       rtDW.k1_g);
      for (rtDW.i = 0; rtDW.i < 10; rtDW.i++) {
        rtDW.rtb_x_opt_t_l[rtDW.i] = 0.0125 * rtDW.k1_g[rtDW.i] +
          rtDW.x_opt_t[rtDW.i];
      }

      deriv_3jC2Hyd6_i(rtDW.Add + 0.0125, rtDW.rtb_x_opt_t_l,
                       rty_soar_telemetry_i, rtDW.xi, J, rtDW.k2_m);
      for (rtDW.i = 0; rtDW.i < 10; rtDW.i++) {
        rtDW.rtb_x_opt_t_l[rtDW.i] = 0.0125 * rtDW.k2_m[rtDW.i] +
          rtDW.x_opt_t[rtDW.i];
      }

      deriv_3jC2Hyd6_i(rtDW.Add + 0.0125, rtDW.rtb_x_opt_t_l,
                       rty_soar_telemetry_i, rtDW.xi, J, rtDW.k3_n);
      for (rtDW.i = 0; rtDW.i < 10; rtDW.i++) {
        rtDW.rtb_x_opt_t_l[rtDW.i] = 0.025 * rtDW.k3_n[rtDW.i] +
          rtDW.x_opt_t[rtDW.i];
      }

      deriv_3jC2Hyd6_i(rtDW.Add + 0.025, rtDW.rtb_x_opt_t_l,
                       rty_soar_telemetry_i, rtDW.xi, J, rtDW.k4_p);
      for (rtDW.i = 0; rtDW.i < 10; rtDW.i++) {
        rtDW.x_opt_t[rtDW.i] += (((2.0 * rtDW.k2_m[rtDW.i] + rtDW.k1_g[rtDW.i])
          + 2.0 * rtDW.k3_n[rtDW.i]) + rtDW.k4_p[rtDW.i]) *
          0.0041666666666666666;
      }
    }

    if (rtDW.Add > rtDW.xi[9]) {
      rtDW.Product1[0] = 0.0;
      rtDW.Product1[1] = 0.0;
      rtDW.Product1[2] = 0.0;
    } else if (rtDW.Add < 0.0) {
      rtDW.Product1[0] = 0.0;
      rtDW.Product1[1] = 0.0;
      rtDW.Product1[2] = 0.0;
    } else {
      for (rtDW.rtu_sc2sun_eci_unit_tmp = 0; rtDW.rtu_sc2sun_eci_unit_tmp < 3;
           rtDW.rtu_sc2sun_eci_unit_tmp++) {
        for (rtDW.i = 0; rtDW.i < 10; rtDW.i++) {
          rtDW.k1_g[rtDW.i] = rty_soar_telemetry_i[3 * rtDW.i +
            rtDW.rtu_sc2sun_eci_unit_tmp];
        }

        memcpy(&rtDW.k2_m[0], &rtDW.xi[0], 10U * sizeof(real_T));
        rtDW.n = 0;
        do {
          exitg2 = 0;
          if (rtDW.n < 10) {
            if (rtIsNaN(rtDW.xi[rtDW.n])) {
              exitg2 = 1;
            } else {
              rtDW.n++;
            }
          } else {
            if (rtDW.xi[1] < 0.0) {
              for (rtDW.n = 0; rtDW.n < 5; rtDW.n++) {
                rtDW.xtmp = rtDW.k2_m[rtDW.n];
                rtDW.k2_m[rtDW.n] = rtDW.k2_m[9 - rtDW.n];
                rtDW.k2_m[9 - rtDW.n] = rtDW.xtmp;
              }

              for (rtDW.n = 0; rtDW.n < 5; rtDW.n++) {
                rtDW.xtmp = rtDW.k1_g[rtDW.n];
                rtDW.k1_g[rtDW.n] = rtDW.k1_g[9 - rtDW.n];
                rtDW.k1_g[9 - rtDW.n] = rtDW.xtmp;
              }
            }

            rtDW.xtmp = (rtNaN);
            if ((!rtIsNaN(rtDW.Add)) && (!(rtDW.Add > rtDW.k2_m[9])) &&
                (!(rtDW.Add < rtDW.k2_m[0]))) {
              rtDW.n = bsearch_s1bfmSFP(rtDW.k2_m, rtDW.Add) - 1;
              rtDW.xtmp = (rtDW.Add - rtDW.k2_m[rtDW.n]) / (rtDW.k2_m[rtDW.n + 1]
                - rtDW.k2_m[rtDW.n]);
              if (rtDW.xtmp == 0.0) {
                rtDW.xtmp = rtDW.k1_g[rtDW.n];
              } else if (rtDW.xtmp == 1.0) {
                rtDW.xtmp = rtDW.k1_g[rtDW.n + 1];
              } else {
                rtDW.Sum = rtDW.k1_g[rtDW.n + 1];
                if (rtDW.Sum == rtDW.k1_g[rtDW.n]) {
                  rtDW.xtmp = rtDW.k1_g[rtDW.n];
                } else {
                  rtDW.xtmp = (1.0 - rtDW.xtmp) * rtDW.k1_g[rtDW.n] + rtDW.Sum *
                    rtDW.xtmp;
                }
              }
            }

            exitg2 = 1;
          }
        } while (exitg2 == 0);

        rtDW.Product1[rtDW.rtu_sc2sun_eci_unit_tmp] = rtDW.xtmp;
      }
    }
  } else {
    rtDW.Product1[0] = 0.0;
    rtDW.Product1[1] = 0.0;
    rtDW.Product1[2] = 0.0;
    memcpy(&rtDW.x_opt_t[0], &rtDW.ResettableDelay_DSTATE[0], 10U * sizeof
           (real_T));
  }

  /* End of MATLAB Function: '<S437>/soar_INTERP' */

  /* If: '<S399>/If1' incorporates:
   *  Constant: '<S399>/Constant'
   */
  if (rtP.DirectionCosineMatrixtoQuaterni != 1.0) {
    /* Outputs for IfAction SubSystem: '<S399>/If Warning//Error' incorporates:
     *  ActionPort: '<S423>/if'
     */
    IfWarningError(rtDW.C_cmd, &rtDW.IfWarningError_d, &rtP.IfWarningError_d,
                   rtP.DirectionCosineMatrixtoQuaterni,
                   rtP.DirectionCosineMatrixtoQuater_g);

    /* End of Outputs for SubSystem: '<S399>/If Warning//Error' */
  }

  /* End of If: '<S399>/If1' */

  /* Logic: '<S396>/AND' incorporates:
   *  Abs: '<S396>/Abs'
   *  Constant: '<S444>/Constant'
   *  Constant: '<S445>/Constant'
   *  RelationalOperator: '<S444>/Compare'
   *  RelationalOperator: '<S445>/Compare'
   */
  rtb_AND = ((rtu_gnc_mode == rtP.CompareToConstant_const_a) && (fabs
              (rty_soar_telemetry_im[16]) < rtP.CompareToConstant1_const));

  /* Switch: '<S396>/Switch' */
  rtDW.xtmp = rtDW.Switch_o[0];
  if (rtb_AND) {
    rtDW.xtmp = rtDW.x_opt_t[0];
  }

  /* RateTransition: '<S10>/Rate Transition6' */
  rty_quat_cmd[0] = rtDW.xtmp;

  /* Switch: '<S396>/Switch' */
  rtDW.xtmp = rtDW.Switch_o[1];
  if (rtb_AND) {
    rtDW.xtmp = rtDW.x_opt_t[1];
  }

  /* RateTransition: '<S10>/Rate Transition6' */
  rty_quat_cmd[1] = rtDW.xtmp;

  /* Switch: '<S396>/Switch' */
  rtDW.xtmp = rtDW.Switch_o[2];
  if (rtb_AND) {
    rtDW.xtmp = rtDW.x_opt_t[2];
  }

  /* RateTransition: '<S10>/Rate Transition6' */
  rty_quat_cmd[2] = rtDW.xtmp;

  /* Switch: '<S396>/Switch' incorporates:
   *  Constant: '<S396>/Constant'
   *  Constant: '<S396>/Constant1'
   *  Switch: '<S396>/Switch1'
   *  Switch: '<S396>/Switch2'
   */
  rtDW.xtmp = rtDW.Switch_o[3];
  if (rtb_AND) {
    rtDW.xtmp = rtDW.x_opt_t[3];
    rty_body_rates_cmd[0] = rtDW.x_opt_t[4];
    rty_torque_body_ff[0] = rtDW.Product1[0];
    rty_body_rates_cmd[1] = rtDW.x_opt_t[5];
    rty_torque_body_ff[1] = rtDW.Product1[1];
    rty_body_rates_cmd[2] = rtDW.x_opt_t[6];
    rty_torque_body_ff[2] = rtDW.Product1[2];

    /* Switch: '<S396>/Switch3' incorporates:
     *  Constant: '<S396>/Constant2'
     */
    *rty_target_gen_flag = rtP.Constant2_Value_o;
  } else {
    rty_body_rates_cmd[0] = rtP.Constant1_Value_m[0];
    rty_torque_body_ff[0] = rtP.Constant_Value_j[0];
    rty_body_rates_cmd[1] = rtP.Constant1_Value_m[1];
    rty_torque_body_ff[1] = rtP.Constant_Value_j[1];
    rty_body_rates_cmd[2] = rtP.Constant1_Value_m[2];
    rty_torque_body_ff[2] = rtP.Constant_Value_j[2];

    /* Switch: '<S396>/Switch3' incorporates:
     *  Constant: '<S396>/Constant'
     *  Constant: '<S396>/Constant1'
     */
    *rty_target_gen_flag = rtb_flag;
  }

  /* RateTransition: '<S10>/Rate Transition6' */
  rty_quat_cmd[3] = rtDW.xtmp;

  /* S-Function (sdspcount2): '<S394>/Counter' */
  if (MWDSP_EPH_R_B(rtb_FixPtRelationalOperator, &rtDW.Counter_ClkEphState) !=
      0U) {
    rtDW.Counter_Count++;
  }

  *rty_soar_telemetry_h = rtDW.Counter_Count;

  /* End of S-Function (sdspcount2): '<S394>/Counter' */

  /* Update for UnitDelay: '<S436>/Delay Input1'
   *
   * Block description for '<S436>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE = rtb_Compare_lr;

  /* Update for UnitDelay: '<S437>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_p = rtDW.diff;

  /* Update for Delay: '<S437>/Resettable Delay' */
  rtDW.icLoad = 0U;
  memcpy(&rtDW.ResettableDelay_DSTATE[0], &rtDW.x_opt_t[0], 10U * sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

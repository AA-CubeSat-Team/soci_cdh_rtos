/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: get_f_vals_QHwIX6tr.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "mrdiv_lFGeJT69.h"
#include "get_f_vals_QHwIX6tr.h"

/* Function for MATLAB Function: '<S386>/SOLVE' */
void get_f_vals_QHwIX6tr(real_T t, const real_T x[10], const real_T u[6], const
  real_T tspan[10], const real_T J[9], real_T f[10], real_T A[100], real_T Bp[30],
  real_T Bm[30], real_T Z[10])
{
  static const int8_T b[30] = { 0, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1 };

  static const int8_T b_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T A_0[100];
  real_T dfq_dhb[12];
  real_T y[12];
  real_T A_1[10];
  real_T Y[9];
  real_T b_A[9];
  real_T tmp[9];
  real_T q[4];
  real_T hb[3];
  real_T u_tau[3];
  real_T w[3];
  real_T absxk;
  real_T b_t;
  real_T dfq_dhb_tmp_1;
  real_T dfq_dhb_tmp_2;
  real_T lam_km;
  real_T lam_kp;
  real_T maxval;
  real_T scale;
  int32_T dfq_dhb_tmp;
  int32_T dfq_dhb_tmp_0;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  int8_T Bp_tmp[30];
  lam_kp = tspan[9] - tspan[0];
  lam_km = (tspan[9] - t) / lam_kp;
  lam_kp = (t - tspan[0]) / lam_kp;
  u_tau[0] = lam_km * u[0] + lam_kp * u[3];
  u_tau[1] = lam_km * u[1] + lam_kp * u[4];
  u_tau[2] = lam_km * u[2] + lam_kp * u[5];
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    maxval = 1.0;
    scale = absxk;
  } else {
    b_t = absxk / 3.3121686421112381E-170;
    maxval = b_t * b_t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    b_t = scale / absxk;
    maxval = maxval * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    maxval += b_t * b_t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    b_t = scale / absxk;
    maxval = maxval * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    maxval += b_t * b_t;
  }

  absxk = fabs(x[3]);
  if (absxk > scale) {
    b_t = scale / absxk;
    maxval = maxval * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    maxval += b_t * b_t;
  }

  maxval = scale * sqrt(maxval);
  q[0] = x[0] / maxval;
  q[1] = x[1] / maxval;
  q[2] = x[2] / maxval;
  q[3] = x[3] / maxval;
  memcpy(&b_A[0], &J[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  b_t = fabs(J[0]);
  maxval = b_t;
  scale = fabs(J[1]);
  if (scale > b_t) {
    maxval = scale;
    r1 = 1;
    r2 = 0;
  }

  absxk = fabs(J[2]);
  if (absxk > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  b_A[r2] = J[r2] / J[r1];
  b_A[r3] /= b_A[r1];
  b_A[r2 + 3] -= b_A[r1 + 3] * b_A[r2];
  b_A[r3 + 3] -= b_A[r1 + 3] * b_A[r3];
  b_A[r2 + 6] -= b_A[r1 + 6] * b_A[r2];
  b_A[r3 + 6] -= b_A[r1 + 6] * b_A[r3];
  if (fabs(b_A[r3 + 3]) > fabs(b_A[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  maxval = x[r1 + 4];
  w[1] = x[r2 + 4] - maxval * b_A[r2];
  w[2] = (x[r3 + 4] - maxval * b_A[r3]) - b_A[r3 + 3] * w[1];
  w[2] /= b_A[r3 + 6];
  w[0] = maxval - b_A[r1 + 6] * w[2];
  w[1] -= b_A[r2 + 6] * w[2];
  w[1] /= b_A[r2 + 3];
  w[0] -= b_A[r1 + 3] * w[1];
  w[0] /= b_A[r1];
  maxval = q[0];
  tmp[0] = 0.0;
  tmp[3] = -q[3];
  tmp[6] = q[2];
  tmp[1] = q[3];
  tmp[4] = 0.0;
  tmp[7] = -q[1];
  tmp[2] = -q[2];
  tmp[5] = q[1];
  tmp[8] = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    r2 = r1 << 2;
    y[r2] = -q[r1 + 1] * 0.5;
    y[r2 + 1] = ((real_T)b_b[3 * r1] * maxval + tmp[3 * r1]) * 0.5;
    r3 = 3 * r1 + 1;
    y[r2 + 2] = ((real_T)b_b[r3] * maxval + tmp[r3]) * 0.5;
    r3 = 3 * r1 + 2;
    y[r2 + 3] = ((real_T)b_b[r3] * maxval + tmp[r3]) * 0.5;
  }

  memcpy(&b_A[0], &J[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  if (scale > b_t) {
    b_t = scale;
    r1 = 1;
    r2 = 0;
  }

  if (absxk > b_t) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  b_A[r2] = J[r2] / J[r1];
  b_A[r3] /= b_A[r1];
  b_A[r2 + 3] -= b_A[r1 + 3] * b_A[r2];
  b_A[r3 + 3] -= b_A[r1 + 3] * b_A[r3];
  b_A[r2 + 6] -= b_A[r1 + 6] * b_A[r2];
  b_A[r3 + 6] -= b_A[r1 + 6] * b_A[r3];
  if (fabs(b_A[r3 + 3]) > fabs(b_A[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  rtemp = r1 << 2;
  dfq_dhb[rtemp] = y[0] / b_A[r1];
  dfq_dhb_tmp = r2 << 2;
  scale = b_A[r1 + 3];
  dfq_dhb[dfq_dhb_tmp] = y[4] - dfq_dhb[rtemp] * scale;
  dfq_dhb_tmp_0 = r3 << 2;
  absxk = b_A[r1 + 6];
  dfq_dhb[dfq_dhb_tmp_0] = y[8] - dfq_dhb[rtemp] * absxk;
  b_t = b_A[r2 + 3];
  dfq_dhb[dfq_dhb_tmp] /= b_t;
  maxval = b_A[r2 + 6];
  dfq_dhb[dfq_dhb_tmp_0] -= dfq_dhb[dfq_dhb_tmp] * maxval;
  dfq_dhb_tmp_1 = b_A[r3 + 6];
  dfq_dhb[dfq_dhb_tmp_0] /= dfq_dhb_tmp_1;
  dfq_dhb_tmp_2 = b_A[r3 + 3];
  dfq_dhb[dfq_dhb_tmp] -= dfq_dhb[dfq_dhb_tmp_0] * dfq_dhb_tmp_2;
  dfq_dhb[rtemp] -= dfq_dhb[dfq_dhb_tmp_0] * b_A[r3];
  dfq_dhb[rtemp] -= dfq_dhb[dfq_dhb_tmp] * b_A[r2];
  dfq_dhb[rtemp + 1] = y[1] / b_A[r1];
  dfq_dhb[dfq_dhb_tmp + 1] = y[5] - dfq_dhb[rtemp + 1] * scale;
  dfq_dhb[dfq_dhb_tmp_0 + 1] = y[9] - dfq_dhb[rtemp + 1] * absxk;
  dfq_dhb[dfq_dhb_tmp + 1] /= b_t;
  dfq_dhb[dfq_dhb_tmp_0 + 1] -= dfq_dhb[dfq_dhb_tmp + 1] * maxval;
  dfq_dhb[dfq_dhb_tmp_0 + 1] /= dfq_dhb_tmp_1;
  dfq_dhb[dfq_dhb_tmp + 1] -= dfq_dhb[dfq_dhb_tmp_0 + 1] * dfq_dhb_tmp_2;
  dfq_dhb[rtemp + 1] -= dfq_dhb[dfq_dhb_tmp_0 + 1] * b_A[r3];
  dfq_dhb[rtemp + 1] -= dfq_dhb[dfq_dhb_tmp + 1] * b_A[r2];
  dfq_dhb[rtemp + 2] = y[2] / b_A[r1];
  dfq_dhb[dfq_dhb_tmp + 2] = y[6] - dfq_dhb[rtemp + 2] * scale;
  dfq_dhb[dfq_dhb_tmp_0 + 2] = y[10] - dfq_dhb[rtemp + 2] * absxk;
  dfq_dhb[dfq_dhb_tmp + 2] /= b_t;
  dfq_dhb[dfq_dhb_tmp_0 + 2] -= dfq_dhb[dfq_dhb_tmp + 2] * maxval;
  dfq_dhb[dfq_dhb_tmp_0 + 2] /= dfq_dhb_tmp_1;
  dfq_dhb[dfq_dhb_tmp + 2] -= dfq_dhb[dfq_dhb_tmp_0 + 2] * dfq_dhb_tmp_2;
  dfq_dhb[rtemp + 2] -= dfq_dhb[dfq_dhb_tmp_0 + 2] * b_A[r3];
  dfq_dhb[rtemp + 2] -= dfq_dhb[dfq_dhb_tmp + 2] * b_A[r2];
  dfq_dhb[rtemp + 3] = y[3] / b_A[r1];
  dfq_dhb[dfq_dhb_tmp + 3] = y[7] - dfq_dhb[rtemp + 3] * scale;
  dfq_dhb[dfq_dhb_tmp_0 + 3] = y[11] - dfq_dhb[rtemp + 3] * absxk;
  dfq_dhb[dfq_dhb_tmp + 3] /= b_t;
  dfq_dhb[dfq_dhb_tmp_0 + 3] -= dfq_dhb[dfq_dhb_tmp + 3] * maxval;
  dfq_dhb[dfq_dhb_tmp_0 + 3] /= dfq_dhb_tmp_1;
  dfq_dhb[dfq_dhb_tmp + 3] -= dfq_dhb[dfq_dhb_tmp_0 + 3] * dfq_dhb_tmp_2;
  dfq_dhb[rtemp + 3] -= dfq_dhb[dfq_dhb_tmp_0 + 3] * b_A[r3];
  dfq_dhb[rtemp + 3] -= dfq_dhb[dfq_dhb_tmp + 3] * b_A[r2];
  tmp[0] = 0.0;
  tmp[3] = -x[6];
  tmp[6] = x[5];
  tmp[1] = x[6];
  tmp[4] = 0.0;
  tmp[7] = -x[4];
  tmp[2] = -x[5];
  tmp[5] = x[4];
  tmp[8] = 0.0;
  mrdiv_lFGeJT69(tmp, J, b_A);
  tmp[0] = 0.0;
  tmp[3] = -x[9];
  tmp[6] = x[8];
  tmp[1] = x[9];
  tmp[4] = 0.0;
  tmp[7] = -x[7];
  tmp[2] = -x[8];
  tmp[5] = x[7];
  tmp[8] = 0.0;
  mrdiv_lFGeJT69(tmp, J, Y);
  A[0] = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    scale = w[r1];
    hb[r1] = x[r1 + 4] + x[r1 + 7];
    A[10 * (r1 + 1)] = 0.5 * -scale;
    A[r1 + 1] = 0.5 * scale;
    r2 = r1 << 2;
    r3 = 10 * (r1 + 4);
    A[r3] = dfq_dhb[r2];
    rtemp = 10 * (r1 + 7);
    A[rtemp] = 0.0;
    A[r3 + 1] = dfq_dhb[r2 + 1];
    A[rtemp + 1] = 0.0;
    A[r3 + 2] = dfq_dhb[r2 + 2];
    A[rtemp + 2] = 0.0;
    A[r3 + 3] = dfq_dhb[r2 + 3];
    A[rtemp + 3] = 0.0;
  }

  A[11] = -0.0;
  A[21] = 0.5 * w[2];
  A[31] = 0.5 * -w[1];
  A[12] = 0.5 * -w[2];
  A[22] = -0.0;
  A[32] = 0.5 * w[0];
  A[13] = 0.5 * w[1];
  A[23] = 0.5 * -w[0];
  A[33] = -0.0;
  for (r1 = 0; r1 < 4; r1++) {
    A[10 * r1 + 4] = 0.0;
    A[10 * r1 + 5] = 0.0;
    A[10 * r1 + 6] = 0.0;
  }

  A[44] = b_A[0] + Y[0];
  A[45] = (b_A[1] - w[2]) + Y[1];
  A[46] = (b_A[2] - (-w[1])) + Y[2];
  A[54] = (b_A[3] - (-w[2])) + Y[3];
  A[55] = b_A[4] + Y[4];
  A[56] = (b_A[5] - w[0]) + Y[5];
  A[64] = (b_A[6] - w[1]) + Y[6];
  A[65] = (b_A[7] - (-w[0])) + Y[7];
  A[66] = b_A[8] + Y[8];
  A[74] = -0.0;
  A[84] = w[2];
  A[94] = -w[1];
  A[75] = -w[2];
  A[85] = -0.0;
  A[95] = w[0];
  A[76] = w[1];
  A[86] = -w[0];
  A[96] = -0.0;
  for (r1 = 0; r1 < 10; r1++) {
    A[10 * r1 + 7] = 0.0;
    A[10 * r1 + 8] = 0.0;
    A[10 * r1 + 9] = 0.0;
  }

  maxval = q[0];
  tmp[0] = 0.0;
  tmp[3] = -q[3];
  tmp[6] = q[2];
  tmp[1] = q[3];
  tmp[4] = 0.0;
  tmp[7] = -q[1];
  tmp[2] = -q[2];
  tmp[5] = q[1];
  tmp[8] = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    r2 = r1 << 2;
    y[r2] = -q[r1 + 1] * 0.5;
    y[r2 + 1] = ((real_T)b_b[3 * r1] * maxval + tmp[3 * r1]) * 0.5;
    r3 = 3 * r1 + 1;
    y[r2 + 2] = ((real_T)b_b[r3] * maxval + tmp[r3]) * 0.5;
    r3 = 3 * r1 + 2;
    y[r2 + 3] = ((real_T)b_b[r3] * maxval + tmp[r3]) * 0.5;
  }

  tmp[0] = 0.0;
  tmp[3] = -hb[2];
  tmp[6] = hb[1];
  tmp[1] = hb[2];
  tmp[4] = 0.0;
  tmp[7] = -hb[0];
  tmp[2] = -hb[1];
  tmp[5] = hb[0];
  tmp[8] = 0.0;
  for (r1 = 0; r1 < 4; r1++) {
    q[r1] = y[r1 + 8] * w[2] + (y[r1 + 4] * w[1] + y[r1] * w[0]);
  }

  for (r1 = 0; r1 < 3; r1++) {
    hb[r1] = ((tmp[r1 + 3] * w[1] + tmp[r1] * w[0]) + tmp[r1 + 6] * w[2]) +
      -u_tau[r1];
  }

  f[0] = q[0];
  f[1] = q[1];
  f[2] = q[2];
  f[3] = q[3];
  f[4] = hb[0];
  f[7] = u_tau[0];
  f[5] = hb[1];
  f[8] = u_tau[1];
  f[6] = hb[2];
  f[9] = u_tau[2];
  for (r1 = 0; r1 < 30; r1++) {
    r2 = b[r1];
    Bp[r1] = lam_kp * (real_T)r2;
    Bm[r1] = lam_km * (real_T)r2;
    Bp_tmp[r1] = (int8_T)r2;
  }

  for (r1 = 0; r1 < 100; r1++) {
    A_0[r1] = -A[r1];
  }

  for (r1 = 0; r1 < 10; r1++) {
    A_1[r1] = 0.0;
    for (r2 = 0; r2 < 10; r2++) {
      A_1[r1] += A_0[10 * r2 + r1] * x[r2];
    }

    Z[r1] = A_1[r1] - ((real_T)Bp_tmp[r1 + 20] * u_tau[2] + ((real_T)Bp_tmp[r1 +
      10] * u_tau[1] + (real_T)Bp_tmp[r1] * u_tau[0]));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

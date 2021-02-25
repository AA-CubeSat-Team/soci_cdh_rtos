/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Q_linearize_4x0wWNNK.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:19:10 2021
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "mrdivide_helper_JpwaVRMh.h"
#include "Q_linearize_4x0wWNNK.h"

/* Function for MATLAB Function: '<S317>/SOLVE' */
void Q_linearize_4x0wWNNK(const real_T x[10], const real_T u[3], const real_T J
  [9], real_T A[100], real_T f[10])
{
  real_T q[4];
  real_T w[3];
  real_T dfq_dhb[12];
  real_T scale;
  real_T absxk;
  real_T t;
  real_T b_A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  int32_T rtemp;
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T b_y_tmp[12];
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[9];
  int32_T dfq_dhb_tmp;
  int32_T dfq_dhb_tmp_0;
  int32_T dfq_dhb_tmp_1;
  int32_T dfq_dhb_tmp_2;
  int32_T dfq_dhb_tmp_3;
  int32_T dfq_dhb_tmp_4;
  int32_T dfq_dhb_tmp_5;
  real_T dfq_dhb_tmp_6;
  real_T dfq_dhb_tmp_7;
  int32_T dfq_dhb_tmp_8;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    maxval = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    maxval = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    maxval = maxval * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    maxval += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    maxval = maxval * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    maxval += t * t;
  }

  absxk = fabs(x[3]);
  if (absxk > scale) {
    t = scale / absxk;
    maxval = maxval * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    maxval += t * t;
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
  scale = fabs(J[0]);
  maxval = scale;
  absxk = fabs(J[1]);
  if (absxk > scale) {
    maxval = absxk;
    r1 = 1;
    r2 = 0;
  }

  t = fabs(J[2]);
  if (t > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  b_A[r2] = J[r2] / J[r1];
  b_A[r3] /= b_A[r1];
  b_A[3 + r2] -= b_A[3 + r1] * b_A[r2];
  b_A[3 + r3] -= b_A[3 + r1] * b_A[r3];
  b_A[6 + r2] -= b_A[6 + r1] * b_A[r2];
  b_A[6 + r3] -= b_A[6 + r1] * b_A[r3];
  if (fabs(b_A[3 + r3]) > fabs(b_A[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  b_A[3 + r3] /= b_A[3 + r2];
  b_A[6 + r3] -= b_A[3 + r3] * b_A[6 + r2];
  maxval = x[4 + r1];
  w[1] = x[4 + r2] - maxval * b_A[r2];
  w[2] = (x[4 + r3] - maxval * b_A[r3]) - b_A[3 + r3] * w[1];
  w[2] /= b_A[6 + r3];
  w[0] = maxval - b_A[6 + r1] * w[2];
  w[1] -= b_A[6 + r2] * w[2];
  w[1] /= b_A[3 + r2];
  w[0] -= b_A[3 + r1] * w[1];
  w[0] /= b_A[r1];
  maxval = q[0];
  b_A[0] = 0.0;
  b_A[3] = -q[3];
  b_A[6] = q[2];
  b_A[1] = q[3];
  b_A[4] = 0.0;
  b_A[7] = -q[1];
  b_A[2] = -q[2];
  b_A[5] = q[1];
  b_A[8] = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    r2 = r1 << 2;
    b_y_tmp[r2] = -q[1 + r1] * 0.5;
    b_y_tmp[1 + r2] = ((real_T)b[3 * r1] * maxval + b_A[3 * r1]) * 0.5;
    r3 = 3 * r1 + 1;
    b_y_tmp[2 + r2] = ((real_T)b[r3] * maxval + b_A[r3]) * 0.5;
    r3 = 3 * r1 + 2;
    b_y_tmp[3 + r2] = ((real_T)b[r3] * maxval + b_A[r3]) * 0.5;
  }

  memcpy(&b_A[0], &J[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = scale;
  if (absxk > scale) {
    maxval = absxk;
    r1 = 1;
    r2 = 0;
  }

  if (t > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  b_A[r2] = J[r2] / J[r1];
  b_A[r3] /= b_A[r1];
  b_A[3 + r2] -= b_A[3 + r1] * b_A[r2];
  b_A[3 + r3] -= b_A[3 + r1] * b_A[r3];
  b_A[6 + r2] -= b_A[6 + r1] * b_A[r2];
  b_A[6 + r3] -= b_A[6 + r1] * b_A[r3];
  if (fabs(b_A[3 + r3]) > fabs(b_A[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  b_A[3 + r3] /= b_A[3 + r2];
  b_A[6 + r3] -= b_A[3 + r3] * b_A[6 + r2];
  rtemp = r1 << 2;
  dfq_dhb[rtemp] = b_y_tmp[0] / b_A[r1];
  dfq_dhb_tmp = r2 << 2;
  maxval = b_A[3 + r1];
  dfq_dhb[dfq_dhb_tmp] = b_y_tmp[4] - dfq_dhb[rtemp] * maxval;
  dfq_dhb_tmp_0 = r3 << 2;
  scale = b_A[6 + r1];
  dfq_dhb[dfq_dhb_tmp_0] = b_y_tmp[8] - dfq_dhb[rtemp] * scale;
  absxk = b_A[3 + r2];
  dfq_dhb[dfq_dhb_tmp] /= absxk;
  t = b_A[6 + r2];
  dfq_dhb[dfq_dhb_tmp_0] -= dfq_dhb[dfq_dhb_tmp] * t;
  dfq_dhb_tmp_6 = b_A[6 + r3];
  dfq_dhb[dfq_dhb_tmp_0] /= dfq_dhb_tmp_6;
  dfq_dhb_tmp_7 = b_A[3 + r3];
  dfq_dhb[dfq_dhb_tmp] -= dfq_dhb[dfq_dhb_tmp_0] * dfq_dhb_tmp_7;
  dfq_dhb[rtemp] -= dfq_dhb[dfq_dhb_tmp_0] * b_A[r3];
  dfq_dhb[rtemp] -= dfq_dhb[dfq_dhb_tmp] * b_A[r2];
  dfq_dhb_tmp_8 = 1 + rtemp;
  dfq_dhb[dfq_dhb_tmp_8] = b_y_tmp[1] / b_A[r1];
  dfq_dhb_tmp_1 = rtemp + 1;
  dfq_dhb_tmp_2 = 1 + dfq_dhb_tmp;
  dfq_dhb[dfq_dhb_tmp_2] = b_y_tmp[5] - dfq_dhb[dfq_dhb_tmp_1] * maxval;
  dfq_dhb_tmp_4 = 1 + dfq_dhb_tmp_0;
  dfq_dhb[dfq_dhb_tmp_4] = b_y_tmp[9] - dfq_dhb[dfq_dhb_tmp_1] * scale;
  dfq_dhb_tmp_3 = dfq_dhb_tmp + 1;
  dfq_dhb[dfq_dhb_tmp_2] = dfq_dhb[dfq_dhb_tmp_3] / absxk;
  dfq_dhb_tmp_5 = dfq_dhb_tmp_0 + 1;
  dfq_dhb[dfq_dhb_tmp_4] = dfq_dhb[dfq_dhb_tmp_5] - dfq_dhb[dfq_dhb_tmp_3] * t;
  dfq_dhb[dfq_dhb_tmp_4] = dfq_dhb[dfq_dhb_tmp_5] / dfq_dhb_tmp_6;
  dfq_dhb[dfq_dhb_tmp_2] = dfq_dhb[dfq_dhb_tmp_3] - dfq_dhb[dfq_dhb_tmp_5] *
    dfq_dhb_tmp_7;
  dfq_dhb[dfq_dhb_tmp_8] = dfq_dhb[dfq_dhb_tmp_1] - dfq_dhb[dfq_dhb_tmp_5] *
    b_A[r3];
  dfq_dhb[dfq_dhb_tmp_8] = dfq_dhb[dfq_dhb_tmp_1] - dfq_dhb[dfq_dhb_tmp_3] *
    b_A[r2];
  dfq_dhb_tmp_8 = 2 + rtemp;
  dfq_dhb[dfq_dhb_tmp_8] = b_y_tmp[2] / b_A[r1];
  dfq_dhb_tmp_1 = rtemp + 2;
  dfq_dhb_tmp_2 = 2 + dfq_dhb_tmp;
  dfq_dhb[dfq_dhb_tmp_2] = b_y_tmp[6] - dfq_dhb[dfq_dhb_tmp_1] * maxval;
  dfq_dhb_tmp_4 = 2 + dfq_dhb_tmp_0;
  dfq_dhb[dfq_dhb_tmp_4] = b_y_tmp[10] - dfq_dhb[dfq_dhb_tmp_1] * scale;
  dfq_dhb_tmp_3 = dfq_dhb_tmp + 2;
  dfq_dhb[dfq_dhb_tmp_2] = dfq_dhb[dfq_dhb_tmp_3] / absxk;
  dfq_dhb_tmp_5 = dfq_dhb_tmp_0 + 2;
  dfq_dhb[dfq_dhb_tmp_4] = dfq_dhb[dfq_dhb_tmp_5] - dfq_dhb[dfq_dhb_tmp_3] * t;
  dfq_dhb[dfq_dhb_tmp_4] = dfq_dhb[dfq_dhb_tmp_5] / dfq_dhb_tmp_6;
  dfq_dhb[dfq_dhb_tmp_2] = dfq_dhb[dfq_dhb_tmp_3] - dfq_dhb[dfq_dhb_tmp_5] *
    dfq_dhb_tmp_7;
  dfq_dhb[dfq_dhb_tmp_8] = dfq_dhb[dfq_dhb_tmp_1] - dfq_dhb[dfq_dhb_tmp_5] *
    b_A[r3];
  dfq_dhb[dfq_dhb_tmp_8] = dfq_dhb[dfq_dhb_tmp_1] - dfq_dhb[dfq_dhb_tmp_3] *
    b_A[r2];
  dfq_dhb_tmp_8 = 3 + rtemp;
  dfq_dhb[dfq_dhb_tmp_8] = b_y_tmp[3] / b_A[r1];
  rtemp += 3;
  dfq_dhb_tmp_1 = 3 + dfq_dhb_tmp;
  dfq_dhb[dfq_dhb_tmp_1] = b_y_tmp[7] - dfq_dhb[rtemp] * maxval;
  dfq_dhb_tmp_2 = 3 + dfq_dhb_tmp_0;
  dfq_dhb[dfq_dhb_tmp_2] = b_y_tmp[11] - dfq_dhb[rtemp] * scale;
  dfq_dhb_tmp += 3;
  dfq_dhb[dfq_dhb_tmp_1] = dfq_dhb[dfq_dhb_tmp] / absxk;
  dfq_dhb_tmp_0 += 3;
  dfq_dhb[dfq_dhb_tmp_2] = dfq_dhb[dfq_dhb_tmp_0] - dfq_dhb[dfq_dhb_tmp] * t;
  dfq_dhb[dfq_dhb_tmp_2] = dfq_dhb[dfq_dhb_tmp_0] / dfq_dhb_tmp_6;
  dfq_dhb[dfq_dhb_tmp_1] = dfq_dhb[dfq_dhb_tmp] - dfq_dhb[dfq_dhb_tmp_0] *
    dfq_dhb_tmp_7;
  dfq_dhb[dfq_dhb_tmp_8] = dfq_dhb[rtemp] - dfq_dhb[dfq_dhb_tmp_0] * b_A[r3];
  dfq_dhb[dfq_dhb_tmp_8] = dfq_dhb[rtemp] - dfq_dhb[dfq_dhb_tmp] * b_A[r2];
  maxval = x[4] + x[7];
  scale = x[5] + x[8];
  absxk = x[6] + x[9];
  b_A[0] = 0.0;
  b_A[3] = -absxk;
  b_A[6] = scale;
  b_A[1] = absxk;
  b_A[4] = 0.0;
  b_A[7] = -maxval;
  b_A[2] = -scale;
  b_A[5] = maxval;
  b_A[8] = 0.0;
  for (r1 = 0; r1 < 4; r1++) {
    q[r1] = b_y_tmp[r1 + 8] * w[2] + (b_y_tmp[r1 + 4] * w[1] + b_y_tmp[r1] * w[0]);
  }

  f[0] = q[0];
  f[1] = q[1];
  f[2] = q[2];
  f[3] = q[3];
  tmp[0] = 0.0;
  tmp[3] = -x[6];
  tmp[6] = x[5];
  tmp[1] = x[6];
  tmp[4] = 0.0;
  tmp[7] = -x[4];
  tmp[2] = -x[5];
  tmp[5] = x[4];
  tmp[8] = 0.0;
  mrdivide_helper_JpwaVRMh(tmp, J, tmp_0);
  tmp[0] = 0.0;
  tmp[3] = -x[9];
  tmp[6] = x[8];
  tmp[1] = x[9];
  tmp[4] = 0.0;
  tmp[7] = -x[7];
  tmp[2] = -x[8];
  tmp[5] = x[7];
  tmp[8] = 0.0;
  mrdivide_helper_JpwaVRMh(tmp, J, tmp_1);
  tmp[0] = 0.0;
  tmp[3] = -w[2];
  tmp[6] = w[1];
  tmp[1] = w[2];
  tmp[4] = 0.0;
  tmp[7] = -w[0];
  tmp[2] = -w[1];
  tmp[5] = w[0];
  tmp[8] = 0.0;
  A[0] = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    f[r1 + 4] = ((b_A[r1 + 3] * w[1] + b_A[r1] * w[0]) + b_A[r1 + 6] * w[2]) +
      -u[r1];
    f[r1 + 7] = u[r1];
    A[10 * (r1 + 1)] = 0.5 * -w[r1];
    A[r1 + 1] = 0.5 * w[r1];
    r2 = r1 << 2;
    r3 = 10 * (r1 + 4);
    A[r3] = dfq_dhb[r2];
    rtemp = 10 * (r1 + 7);
    A[rtemp] = 0.0;
    A[1 + r3] = dfq_dhb[r2 + 1];
    A[1 + rtemp] = 0.0;
    A[2 + r3] = dfq_dhb[r2 + 2];
    A[2 + rtemp] = 0.0;
    A[3 + r3] = dfq_dhb[r2 + 3];
    A[3 + rtemp] = 0.0;
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
    A[4 + 10 * r1] = 0.0;
    A[5 + 10 * r1] = 0.0;
    A[6 + 10 * r1] = 0.0;
  }

  for (r1 = 0; r1 < 3; r1++) {
    r2 = 10 * (r1 + 4);
    A[4 + r2] = (tmp_0[3 * r1] - tmp[3 * r1]) + tmp_1[3 * r1];
    r3 = 3 * r1 + 1;
    A[5 + r2] = (tmp_0[r3] - tmp[r3]) + tmp_1[r3];
    r3 = 3 * r1 + 2;
    A[6 + r2] = (tmp_0[r3] - tmp[r3]) + tmp_1[r3];
  }

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
    A[7 + 10 * r1] = 0.0;
    A[8 + 10 * r1] = 0.0;
    A[9 + 10 * r1] = 0.0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

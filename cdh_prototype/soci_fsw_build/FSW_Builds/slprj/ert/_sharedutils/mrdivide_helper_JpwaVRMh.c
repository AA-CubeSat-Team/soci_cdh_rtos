/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mrdivide_helper_JpwaVRMh.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "mrdivide_helper_JpwaVRMh.h"

/* Function for MATLAB Function: '<S343>/SOLVE' */
void mrdivide_helper_JpwaVRMh(const real_T A[9], const real_T B_2[9], real_T y[9])
{
  real_T b_A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  int32_T y_tmp;
  real_T y_tmp_0;
  int32_T y_tmp_1;
  int32_T y_tmp_2;
  real_T y_tmp_3;
  int32_T y_tmp_4;
  int32_T y_tmp_5;
  real_T y_tmp_6;
  real_T y_tmp_7;
  memcpy(&b_A[0], &B_2[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(B_2[0]);
  a21 = fabs(B_2[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(B_2[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  b_A[r2] = B_2[r2] / B_2[r1];
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
  y[3 * r1] = A[0] / b_A[r1];
  maxval = b_A[3 + r1];
  y[3 * r2] = A[3] - y[3 * r1] * maxval;
  a21 = b_A[6 + r1];
  y[3 * r3] = A[6] - y[3 * r1] * a21;
  y_tmp_0 = b_A[3 + r2];
  y[3 * r2] /= y_tmp_0;
  y_tmp_3 = b_A[6 + r2];
  y[3 * r3] -= y[3 * r2] * y_tmp_3;
  y_tmp_6 = b_A[6 + r3];
  y[3 * r3] /= y_tmp_6;
  y_tmp_7 = b_A[3 + r3];
  y[3 * r2] -= y[3 * r3] * y_tmp_7;
  y[3 * r1] -= y[3 * r3] * b_A[r3];
  y[3 * r1] -= y[3 * r2] * b_A[r2];
  rtemp = 1 + 3 * r1;
  y[rtemp] = A[1] / b_A[r1];
  y_tmp = 3 * r1 + 1;
  y_tmp_1 = 1 + 3 * r2;
  y[y_tmp_1] = A[4] - y[y_tmp] * maxval;
  y_tmp_4 = 1 + 3 * r3;
  y[y_tmp_4] = A[7] - y[y_tmp] * a21;
  y_tmp_2 = 3 * r2 + 1;
  y[y_tmp_1] = y[y_tmp_2] / y_tmp_0;
  y_tmp_5 = 3 * r3 + 1;
  y[y_tmp_4] = y[y_tmp_5] - y[y_tmp_2] * y_tmp_3;
  y[y_tmp_4] = y[y_tmp_5] / y_tmp_6;
  y[y_tmp_1] = y[y_tmp_2] - y[y_tmp_5] * y_tmp_7;
  y[rtemp] = y[y_tmp] - y[y_tmp_5] * b_A[r3];
  y[rtemp] = y[y_tmp] - y[y_tmp_2] * b_A[r2];
  rtemp = 2 + 3 * r1;
  y[rtemp] = A[2] / b_A[r1];
  y_tmp = 3 * r1 + 2;
  y_tmp_1 = 2 + 3 * r2;
  y[y_tmp_1] = A[5] - y[y_tmp] * maxval;
  y_tmp_4 = 2 + 3 * r3;
  y[y_tmp_4] = A[8] - y[y_tmp] * a21;
  y_tmp_2 = 3 * r2 + 2;
  y[y_tmp_1] = y[y_tmp_2] / y_tmp_0;
  y_tmp_5 = 3 * r3 + 2;
  y[y_tmp_4] = y[y_tmp_5] - y[y_tmp_2] * y_tmp_3;
  y[y_tmp_4] = y[y_tmp_5] / y_tmp_6;
  y[y_tmp_1] = y[y_tmp_2] - y[y_tmp_5] * y_tmp_7;
  y[rtemp] = y[y_tmp] - y[y_tmp_5] * b_A[r3];
  y[rtemp] = y[y_tmp] - y[y_tmp_2] * b_A[r2];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

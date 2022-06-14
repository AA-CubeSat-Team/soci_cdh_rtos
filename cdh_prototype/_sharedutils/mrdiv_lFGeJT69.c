/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mrdiv_lFGeJT69.c
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

/* Function for MATLAB Function: '<S386>/SOLVE' */
void mrdiv_lFGeJT69(const real_T A[9], const real_T B_2[9], real_T Y[9])
{
  real_T b_A[9];
  real_T Y_tmp_0;
  real_T Y_tmp_2;
  real_T Y_tmp_3;
  real_T Y_tmp_4;
  real_T maxval;
  real_T y;
  int32_T Y_tmp;
  int32_T Y_tmp_1;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  memcpy(&b_A[0], &B_2[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(B_2[0]);
  y = fabs(B_2[1]);
  if (y > maxval) {
    maxval = y;
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
  Y[3 * r1] = A[0] / b_A[r1];
  maxval = b_A[r1 + 3];
  Y[3 * r2] = A[3] - Y[3 * r1] * maxval;
  y = b_A[r1 + 6];
  Y[3 * r3] = A[6] - Y[3 * r1] * y;
  Y_tmp_0 = b_A[r2 + 3];
  Y[3 * r2] /= Y_tmp_0;
  Y_tmp_2 = b_A[r2 + 6];
  Y[3 * r3] -= Y[3 * r2] * Y_tmp_2;
  Y_tmp_3 = b_A[r3 + 6];
  Y[3 * r3] /= Y_tmp_3;
  Y_tmp_4 = b_A[r3 + 3];
  Y[3 * r2] -= Y[3 * r3] * Y_tmp_4;
  Y[3 * r1] -= Y[3 * r3] * b_A[r3];
  Y[3 * r1] -= Y[3 * r2] * b_A[r2];
  rtemp = 3 * r1 + 1;
  Y[rtemp] = A[1] / b_A[r1];
  Y_tmp = 3 * r2 + 1;
  Y[Y_tmp] = A[4] - Y[rtemp] * maxval;
  Y_tmp_1 = 3 * r3 + 1;
  Y[Y_tmp_1] = A[7] - Y[rtemp] * y;
  Y[Y_tmp] /= Y_tmp_0;
  Y[Y_tmp_1] -= Y[Y_tmp] * Y_tmp_2;
  Y[Y_tmp_1] /= Y_tmp_3;
  Y[Y_tmp] -= Y[Y_tmp_1] * Y_tmp_4;
  Y[rtemp] -= Y[Y_tmp_1] * b_A[r3];
  Y[rtemp] -= Y[Y_tmp] * b_A[r2];
  rtemp = 3 * r1 + 2;
  Y[rtemp] = A[2] / b_A[r1];
  Y_tmp = 3 * r2 + 2;
  Y[Y_tmp] = A[5] - Y[rtemp] * maxval;
  Y_tmp_1 = 3 * r3 + 2;
  Y[Y_tmp_1] = A[8] - Y[rtemp] * y;
  Y[Y_tmp] /= Y_tmp_0;
  Y[Y_tmp_1] -= Y[Y_tmp] * Y_tmp_2;
  Y[Y_tmp_1] /= Y_tmp_3;
  Y[Y_tmp] -= Y[Y_tmp_1] * Y_tmp_4;
  Y[rtemp] -= Y[Y_tmp_1] * b_A[r3];
  Y[rtemp] -= Y[Y_tmp] * b_A[r2];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

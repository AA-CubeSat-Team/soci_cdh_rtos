/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mldivide_gjtSm7pm.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 25 17:45:01 2021
 */

#include "rtwtypes.h"
#include <string.h>
#include "xgetrf_CjXcXVfl.h"
#include "mldivide_gjtSm7pm.h"

/* Function for MATLAB Function: '<S438>/SOLVE' */
void mldivide_gjtSm7pm(const real_T A[100], real_T B_5[30])
{
  real_T temp;
  int32_T ip;
  real_T b_A[100];
  int32_T ipiv[10];
  int32_T info;
  int32_T xj;
  int32_T kAcol;
  int32_T i;
  int32_T tmp;
  memcpy(&b_A[0], &A[0], 100U * sizeof(real_T));
  xgetrf_CjXcXVfl(b_A, ipiv, &info);
  for (info = 0; info < 9; info++) {
    if (info + 1 != ipiv[info]) {
      ip = ipiv[info] - 1;
      temp = B_5[info];
      B_5[info] = B_5[ip];
      B_5[ip] = temp;
      temp = B_5[info + 10];
      B_5[info + 10] = B_5[ip + 10];
      B_5[ip + 10] = temp;
      temp = B_5[info + 20];
      B_5[info + 20] = B_5[ip + 20];
      B_5[ip + 20] = temp;
    }
  }

  for (info = 0; info < 3; info++) {
    ip = 10 * info;
    for (xj = 0; xj < 10; xj++) {
      kAcol = 10 * xj;
      if (B_5[xj + ip] != 0.0) {
        for (i = xj + 2; i < 11; i++) {
          tmp = (i + ip) - 1;
          B_5[tmp] -= b_A[(i + kAcol) - 1] * B_5[xj + ip];
        }
      }
    }
  }

  for (info = 0; info < 3; info++) {
    ip = 10 * info;
    for (xj = 9; xj >= 0; xj--) {
      kAcol = 10 * xj;
      if (B_5[xj + ip] != 0.0) {
        B_5[xj + ip] /= b_A[xj + kAcol];
        for (i = 0; i < xj; i++) {
          tmp = i + ip;
          B_5[tmp] -= B_5[xj + ip] * b_A[i + kAcol];
        }
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mldivide_JgAM3Jry.c
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
#include "mldivide_JgAM3Jry.h"

/* Function for MATLAB Function: '<S438>/SOLVE' */
void mldivide_JgAM3Jry(const real_T A[100], real_T B_6[10])
{
  real_T temp;
  real_T b_A[100];
  int32_T ipiv[10];
  int32_T info;
  int32_T kAcol;
  int32_T i;
  memcpy(&b_A[0], &A[0], 100U * sizeof(real_T));
  xgetrf_CjXcXVfl(b_A, ipiv, &info);
  for (info = 0; info < 9; info++) {
    if (info + 1 != ipiv[info]) {
      temp = B_6[info];
      B_6[info] = B_6[ipiv[info] - 1];
      B_6[ipiv[info] - 1] = temp;
    }
  }

  for (info = 0; info < 10; info++) {
    kAcol = 10 * info;
    if (B_6[info] != 0.0) {
      for (i = info + 1; i + 1 < 11; i++) {
        B_6[i] -= b_A[i + kAcol] * B_6[info];
      }
    }
  }

  for (info = 9; info >= 0; info--) {
    kAcol = 10 * info;
    if (B_6[info] != 0.0) {
      B_6[info] /= b_A[info + kAcol];
      for (i = 0; i < info; i++) {
        B_6[i] -= b_A[i + kAcol] * B_6[info];
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

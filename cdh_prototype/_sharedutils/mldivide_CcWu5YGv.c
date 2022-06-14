/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mldivide_CcWu5YGv.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <string.h>
#include "xgetrf_HqzFX9EF.h"
#include "mldivide_CcWu5YGv.h"

/* Function for MATLAB Function: '<S386>/SOLVE' */
void mldivide_CcWu5YGv(const real_T A[100], real_T B_6[10])
{
  real_T b_A[100];
  real_T temp;
  int32_T ipiv[10];
  int32_T b_i;
  int32_T info;
  int32_T kAcol;
  memcpy(&b_A[0], &A[0], 100U * sizeof(real_T));
  xgetrf_HqzFX9EF(b_A, ipiv, &info);
  for (info = 0; info < 9; info++) {
    kAcol = ipiv[info];
    if (info + 1 != kAcol) {
      temp = B_6[info];
      B_6[info] = B_6[kAcol - 1];
      B_6[kAcol - 1] = temp;
    }
  }

  for (info = 0; info < 10; info++) {
    kAcol = 10 * info;
    if (B_6[info] != 0.0) {
      for (b_i = info + 1; b_i + 1 < 11; b_i++) {
        B_6[b_i] -= b_A[b_i + kAcol] * B_6[info];
      }
    }
  }

  for (info = 9; info >= 0; info--) {
    kAcol = 10 * info;
    if (B_6[info] != 0.0) {
      B_6[info] /= b_A[info + kAcol];
      for (b_i = 0; b_i < info; b_i++) {
        B_6[b_i] -= b_A[b_i + kAcol] * B_6[info];
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mldivide_Uh5i7tR8.c
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
#include "mldivide_Uh5i7tR8.h"

/* Function for MATLAB Function: '<S386>/SOLVE' */
void mldivide_Uh5i7tR8(const real_T A[100], const real_T B_3[30], real_T Y[30])
{
  real_T b_A[100];
  real_T temp;
  int32_T ipiv[10];
  int32_T Y_tmp;
  int32_T b_i;
  int32_T info;
  int32_T ip;
  int32_T j;
  int32_T kAcol;
  int32_T tmp;
  memcpy(&b_A[0], &A[0], 100U * sizeof(real_T));
  xgetrf_HqzFX9EF(b_A, ipiv, &info);
  memcpy(&Y[0], &B_3[0], 30U * sizeof(real_T));
  for (info = 0; info < 9; info++) {
    ip = ipiv[info];
    if (info + 1 != ip) {
      temp = Y[info];
      Y[info] = Y[ip - 1];
      Y[ip - 1] = temp;
      temp = Y[info + 10];
      Y[info + 10] = Y[ip + 9];
      Y[ip + 9] = temp;
      temp = Y[info + 20];
      Y[info + 20] = Y[ip + 19];
      Y[ip + 19] = temp;
    }
  }

  for (info = 0; info < 3; info++) {
    ip = 10 * info;
    for (j = 0; j < 10; j++) {
      kAcol = 10 * j;
      tmp = j + ip;
      if (Y[tmp] != 0.0) {
        for (b_i = j + 2; b_i < 11; b_i++) {
          Y_tmp = (b_i + ip) - 1;
          Y[Y_tmp] -= b_A[(b_i + kAcol) - 1] * Y[tmp];
        }
      }
    }
  }

  for (info = 0; info < 3; info++) {
    ip = 10 * info;
    for (j = 9; j >= 0; j--) {
      kAcol = 10 * j;
      tmp = j + ip;
      temp = Y[tmp];
      if (temp != 0.0) {
        Y[tmp] = temp / b_A[j + kAcol];
        for (b_i = 0; b_i < j; b_i++) {
          Y_tmp = b_i + ip;
          Y[Y_tmp] -= Y[tmp] * b_A[b_i + kAcol];
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

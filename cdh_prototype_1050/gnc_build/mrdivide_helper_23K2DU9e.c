/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mrdivide_helper_23K2DU9e.c
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
#include "mrdivide_helper_23K2DU9e.h"

/* Function for MATLAB Function: '<S19>/QR_factorization' */
void mrdivide_helper_23K2DU9e(real_T A[36], const real_T B_0[36])
{
  real_T b_A[36];
  int8_T ipiv[6];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&b_A[0], &B_0[0], 36U * sizeof(real_T));
  for (d = 0; d < 6; d++) {
    ipiv[d] = (int8_T)(1 + d);
  }

  for (j = 0; j < 5; j++) {
    jBcol = j * 7;
    iy = 0;
    ix = jBcol;
    smax = fabs(b_A[jBcol]);
    for (kBcol = 2; kBcol <= 6 - j; kBcol++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > smax) {
        iy = kBcol - 1;
        smax = s;
      }
    }

    if (b_A[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (kBcol = 0; kBcol < 6; kBcol++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      iy = (jBcol - j) + 6;
      for (ix = jBcol + 1; ix < iy; ix++) {
        b_A[ix] /= b_A[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 6;
    for (kBcol = 0; kBcol <= 4 - j; kBcol++) {
      if (b_A[ix] != 0.0) {
        smax = -b_A[ix];
        c_ix = jBcol + 1;
        d = (iy - j) + 12;
        for (ijA = 7 + iy; ijA < d; ijA++) {
          b_A[ijA] += b_A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 6;
      iy += 6;
    }
  }

  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    iy = 6 * j;
    for (ix = 0; ix < j; ix++) {
      kBcol = 6 * ix;
      smax = b_A[ix + iy];
      if (smax != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          d = c_ix + jBcol;
          A[d] -= smax * A[c_ix + kBcol];
        }
      }
    }

    smax = 1.0 / b_A[j + iy];
    for (iy = 0; iy < 6; iy++) {
      d = iy + jBcol;
      A[d] *= smax;
    }
  }

  for (j = 5; j >= 0; j--) {
    jBcol = 6 * j;
    iy = 6 * j - 1;
    for (ix = j + 2; ix < 7; ix++) {
      kBcol = (ix - 1) * 6;
      smax = b_A[ix + iy];
      if (smax != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          A[c_ix + jBcol] -= smax * A[c_ix + kBcol];
        }
      }
    }
  }

  for (j = 4; j >= 0; j--) {
    if (j + 1 != ipiv[j]) {
      jBcol = ipiv[j] - 1;
      for (iy = 0; iy < 6; iy++) {
        smax = A[6 * j + iy];
        A[iy + 6 * j] = A[6 * jBcol + iy];
        A[iy + 6 * jBcol] = smax;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

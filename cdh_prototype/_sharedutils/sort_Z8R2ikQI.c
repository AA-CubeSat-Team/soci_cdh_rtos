/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sort_Z8R2ikQI.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include "merge_B5HnnN1b.h"
#include "rt_nonfinite.h"
#include "sort_Z8R2ikQI.h"

/* Function for MATLAB Function: '<S14>/MATLAB Function' */
void sort_Z8R2ikQI(real_T x[6], int32_T idx[6])
{
  real_T xwork[6];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T iwork[6];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int32_T nNaNs;
  int8_T idx4[4];
  int8_T perm[4];
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  for (i = 0; i < 6; i++) {
    idx[i] = 0;
    xwork[i] = 0.0;
  }

  nNaNs = 0;
  ib = -1;
  for (i = 0; i < 6; i++) {
    if (rtIsNaN(x[i])) {
      idx[5 - nNaNs] = i + 1;
      xwork[5 - nNaNs] = x[i];
      nNaNs++;
    } else {
      ib++;
      idx4[ib] = (int8_T)(i + 1);
      x4[ib] = x[i];
      if (ib + 1 == 4) {
        ib = i - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        tmp = x4[i1 - 1];
        tmp_0 = x4[i3 - 1];
        if (tmp <= tmp_0) {
          tmp = x4[i2 - 1];
          if (tmp <= tmp_0) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (tmp <= x4[i4 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          tmp_0 = x4[i4 - 1];
          if (tmp <= tmp_0) {
            if (x4[i2 - 1] <= tmp_0) {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i2;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)i2;
            }
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i4;
            perm[2] = (int8_T)i1;
            perm[3] = (int8_T)i2;
          }
        }

        idx[ib - 3] = idx4[perm[0] - 1];
        idx[ib - 2] = idx4[perm[1] - 1];
        idx[ib - 1] = idx4[perm[2] - 1];
        idx[ib] = idx4[perm[3] - 1];
        x[ib - 3] = x4[perm[0] - 1];
        x[ib - 2] = x4[perm[1] - 1];
        x[ib - 1] = x4[perm[2] - 1];
        x[ib] = x4[perm[3] - 1];
        ib = -1;
      }
    }
  }

  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1) {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      break;
    }

    for (i = 0; i <= ib; i++) {
      i1 = perm[i] - 1;
      i2 = ((i - nNaNs) - ib) + 5;
      idx[i2] = idx4[i1];
      x[i2] = x4[i1];
    }
  }

  i = (nNaNs >> 1) + 6;
  for (ib = 6; ib - 6 <= i - 7; ib++) {
    i2 = ib - nNaNs;
    i1 = idx[i2];
    idx[i2] = idx[11 - ib];
    idx[11 - ib] = i1;
    x[i2] = xwork[11 - ib];
    x[11 - ib] = xwork[i2];
  }

  if ((nNaNs & 1U) != 0U) {
    i -= nNaNs;
    x[i] = xwork[i];
  }

  if (6 - nNaNs > 1) {
    for (i = 0; i < 6; i++) {
      iwork[i] = 0;
    }

    ib = (6 - nNaNs) >> 2;
    i = 4;
    while (ib > 1) {
      if ((ib & 1U) != 0U) {
        ib--;
        i1 = i * ib;
        i2 = 6 - (nNaNs + i1);
        if (i2 > i) {
          merge_B5HnnN1b(idx, x, i1, i, i2 - i, iwork, xwork);
        }
      }

      i1 = i << 1;
      ib >>= 1;
      for (i2 = 0; i2 < ib; i2++) {
        merge_B5HnnN1b(idx, x, i2 * i1, i, i, iwork, xwork);
      }

      i = i1;
    }

    if (6 - nNaNs > i) {
      merge_B5HnnN1b(idx, x, 0, i, 6 - (nNaNs + i), iwork, xwork);
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

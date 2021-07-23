/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sort_E8F8dFL3.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 */

#include "rtwtypes.h"
#include "merge_9L7gC4KK.h"
#include "rt_nonfinite.h"
#include "sort_E8F8dFL3.h"

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
void sort_E8F8dFL3(real_T x[6], int32_T idx[6])
{
  int32_T nNaNs;
  real_T xwork[6];
  int32_T iwork[6];
  real_T x4[4];
  int8_T idx4[4];
  int32_T m;
  int8_T perm[4];
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i;
  real_T tmp;
  real_T tmp_0;
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
  i = -1;
  for (m = 0; m < 6; m++) {
    if (rtIsNaN(x[m])) {
      idx[5 - nNaNs] = m + 1;
      xwork[5 - nNaNs] = x[m];
      nNaNs++;
    } else {
      i++;
      idx4[i] = (int8_T)(m + 1);
      x4[i] = x[m];
      if (i + 1 == 4) {
        i = m - nNaNs;
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
          if (x4[i2 - 1] <= tmp_0) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (x4[i2 - 1] <= x4[i4 - 1]) {
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

        i1 = perm[0] - 1;
        idx[i - 3] = idx4[i1];
        i2 = perm[1] - 1;
        idx[i - 2] = idx4[i2];
        i3 = perm[2] - 1;
        idx[i - 1] = idx4[i3];
        i4 = perm[3] - 1;
        idx[i] = idx4[i4];
        x[i - 3] = x4[i1];
        x[i - 2] = x4[i2];
        x[i - 1] = x4[i3];
        x[i] = x4[i4];
        i = -1;
      }
    }
  }

  if (i + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (i + 1) {
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

    for (m = 0; m <= i; m++) {
      i1 = perm[m] - 1;
      i2 = ((m - nNaNs) - i) + 5;
      idx[i2] = idx4[i1];
      x[i2] = x4[i1];
    }
  }

  m = (nNaNs >> 1) + 6;
  for (i = 6; i - 6 <= m - 7; i++) {
    i2 = i - nNaNs;
    i1 = idx[i2];
    idx[i2] = idx[11 - i];
    idx[11 - i] = i1;
    x[i2] = xwork[11 - i];
    x[11 - i] = xwork[i2];
  }

  if ((nNaNs & 1U) != 0U) {
    i = m - nNaNs;
    x[i] = xwork[i];
  }

  if (6 - nNaNs > 1) {
    for (i = 0; i < 6; i++) {
      iwork[i] = 0;
    }

    i = (6 - nNaNs) >> 2;
    m = 4;
    while (i > 1) {
      if ((i & 1U) != 0U) {
        i--;
        i1 = m * i;
        i2 = 6 - (nNaNs + i1);
        if (i2 > m) {
          merge_9L7gC4KK(idx, x, i1, m, i2 - m, iwork, xwork);
        }
      }

      i1 = m << 1;
      i >>= 1;
      for (i2 = 0; i2 < i; i2++) {
        merge_9L7gC4KK(idx, x, i2 * i1, m, m, iwork, xwork);
      }

      m = i1;
    }

    if (6 - nNaNs > m) {
      merge_9L7gC4KK(idx, x, 0, m, 6 - (nNaNs + m), iwork, xwork);
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

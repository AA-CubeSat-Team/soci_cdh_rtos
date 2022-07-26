/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: convert_to_CCS_fbGN0NKz.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun May  8 21:05:29 2022
 */

#include "rtwtypes.h"
#include <string.h>
#include "convert_to_CCS_fbGN0NKz.h"

/* Function for MATLAB Function: '<S210>/SOLVE' */
void convert_to_CCS_fbGN0NKz(const real_T X_3[38844], int32_T Xir[1278], int32_T
  Xjc[333], real_T Xpr[1278])
{
  real_T X_4;
  int32_T k;
  int32_T n;
  int32_T row;
  uint32_T id;
  memset(&Xir[0], 0, 1278U * sizeof(int32_T));
  memset(&Xpr[0], 0, 1278U * sizeof(real_T));
  n = 0;
  for (k = 0; k < 38844; k++) {
    if (X_3[k] != 0.0) {
      n++;
    }
  }

  id = 1U;
  for (k = 0; k < 332; k++) {
    for (row = 0; row < 117; row++) {
      X_4 = X_3[117 * k + row];
      if ((X_4 != 0.0) && (id < (real_T)n + 1.0)) {
        Xir[(int32_T)id - 1] = row;
        Xpr[(int32_T)id - 1] = X_4;
        id++;
      }
    }
  }

  memset(&Xjc[0], 0, 333U * sizeof(int32_T));
  for (n = 0; n < 331; n++) {
    k = 0;
    for (row = 0; row < 117; row++) {
      if (X_3[117 * n + row] != 0.0) {
        k++;
      }
    }

    row = Xjc[n];
    if ((row < 0) && (k < MIN_int32_T - row)) {
      Xjc[n + 1] = MIN_int32_T;
    } else if ((row > 0) && (k > MAX_int32_T - row)) {
      Xjc[n + 1] = MAX_int32_T;
    } else {
      Xjc[n + 1] = row + k;
    }
  }

  n = 0;
  for (k = 0; k < 38844; k++) {
    if (X_3[k] != 0.0) {
      n++;
    }
  }

  Xjc[332] = n;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

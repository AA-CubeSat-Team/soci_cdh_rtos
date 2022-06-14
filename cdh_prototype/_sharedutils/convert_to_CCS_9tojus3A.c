/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: convert_to_CCS_9tojus3A.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <string.h>
#include "convert_to_CCS_9tojus3A.h"

/* Function for MATLAB Function: '<S386>/SOLVE' */
void convert_to_CCS_9tojus3A(const real_T X_5[157368], int32_T Xir[834], int32_T
  Xjc[333], real_T Xpr[834])
{
  real_T X_6;
  int32_T k;
  int32_T n;
  int32_T row;
  uint32_T id;
  memset(&Xir[0], 0, 834U * sizeof(int32_T));
  memset(&Xpr[0], 0, 834U * sizeof(real_T));
  n = 0;
  for (k = 0; k < 157368; k++) {
    if (X_5[k] != 0.0) {
      n++;
    }
  }

  id = 1U;
  for (k = 0; k < 332; k++) {
    for (row = 0; row < 474; row++) {
      X_6 = X_5[474 * k + row];
      if ((X_6 != 0.0) && (id < (real_T)n + 1.0)) {
        Xir[(int32_T)id - 1] = row;
        Xpr[(int32_T)id - 1] = X_6;
        id++;
      }
    }
  }

  memset(&Xjc[0], 0, 333U * sizeof(int32_T));
  for (n = 0; n < 331; n++) {
    k = 0;
    for (row = 0; row < 474; row++) {
      if (X_5[474 * n + row] != 0.0) {
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
  for (k = 0; k < 157368; k++) {
    if (X_5[k] != 0.0) {
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

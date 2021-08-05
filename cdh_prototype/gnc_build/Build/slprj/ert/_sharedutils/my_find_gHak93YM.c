/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: my_find_gHak93YM.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 */

#include "rtwtypes.h"
#include <string.h>
#include "my_find_gHak93YM.h"

/* Function for MATLAB Function: '<S412>/SOLVE' */
void my_find_gHak93YM(const real_T X_7[157368], int32_T Xir[834], real_T Xpr[834])
{
  uint32_T id;
  int32_T row;
  int32_T n;
  int32_T k;
  real_T X_8;
  int32_T Xir_tmp;
  memset(&Xir[0], 0, 834U * sizeof(int32_T));
  memset(&Xpr[0], 0, 834U * sizeof(real_T));
  n = 0;
  for (k = 0; k < 157368; k++) {
    if (X_7[k] != 0.0) {
      n++;
    }
  }

  id = 1U;
  for (k = 0; k < 332; k++) {
    for (row = 0; row < 474; row++) {
      X_8 = X_7[474 * k + row];
      if ((X_8 != 0.0) && (id < (real_T)n + 1.0)) {
        Xir_tmp = (int32_T)id - 1;
        Xir[Xir_tmp] = row;
        Xpr[Xir_tmp] = X_8;
        id++;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

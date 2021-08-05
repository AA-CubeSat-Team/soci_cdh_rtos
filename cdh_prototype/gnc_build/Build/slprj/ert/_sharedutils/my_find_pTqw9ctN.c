/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: my_find_pTqw9ctN.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 */

#include "rtwtypes.h"
#include <string.h>
#include "my_find_pTqw9ctN.h"

/* Function for MATLAB Function: '<S412>/SOLVE' */
void my_find_pTqw9ctN(const real_T X_4[38844], int32_T Xir[1278], real_T Xpr
                      [1278])
{
  uint32_T id;
  int32_T row;
  int32_T n;
  int32_T k;
  real_T X_5;
  int32_T Xir_tmp;
  memset(&Xir[0], 0, 1278U * sizeof(int32_T));
  memset(&Xpr[0], 0, 1278U * sizeof(real_T));
  n = 0;
  for (k = 0; k < 38844; k++) {
    if (X_4[k] != 0.0) {
      n++;
    }
  }

  id = 1U;
  for (k = 0; k < 332; k++) {
    for (row = 0; row < 117; row++) {
      X_5 = X_4[117 * k + row];
      if ((X_5 != 0.0) && (id < (real_T)n + 1.0)) {
        Xir_tmp = (int32_T)id - 1;
        Xir[Xir_tmp] = row;
        Xpr[Xir_tmp] = X_5;
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

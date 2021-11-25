/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: convert_to_CCS_TWUhmVkC.c
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
#include "convert_to_CCS_TWUhmVkC.h"

/* Function for MATLAB Function: '<S412>/SOLVE' */
void convert_to_CCS_TWUhmVkC(const real_T X_3[38844], int32_T Xir[1278], int32_T
  Xjc[333], real_T Xpr[1278])
{
  int32_T col;
  int32_T b_n;
  int32_T b_k;
  my_find_pTqw9ctN(X_3, Xir, Xpr);
  memset(&Xjc[0], 0, 333U * sizeof(int32_T));
  for (col = 0; col < 331; col++) {
    b_n = 0;
    for (b_k = 0; b_k < 117; b_k++) {
      if (X_3[117 * col + b_k] != 0.0) {
        b_n++;
      }
    }

    if ((Xjc[col] < 0) && (b_n < MIN_int32_T - Xjc[col])) {
      Xjc[col + 1] = MIN_int32_T;
    } else if ((Xjc[col] > 0) && (b_n > MAX_int32_T - Xjc[col])) {
      Xjc[col + 1] = MAX_int32_T;
    } else {
      Xjc[col + 1] = Xjc[col] + b_n;
    }
  }

  col = 0;
  for (b_n = 0; b_n < 38844; b_n++) {
    if (X_3[b_n] != 0.0) {
      col++;
    }
  }

  Xjc[332] = col;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xrot_DROkKeLU.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
 */

#include "rtwtypes.h"
#include "xrot_DROkKeLU.h"

/* Function for MATLAB Function: '<S343>/INITIALIZE' */
void xrot_DROkKeLU(int32_T n, real_T x[16], int32_T ix0, int32_T iy0, real_T c,
                   real_T s)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      temp = c * x[ix] + s * x[iy];
      x[iy] = c * x[iy] - s * x[ix];
      x[ix] = temp;
      iy++;
      ix++;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

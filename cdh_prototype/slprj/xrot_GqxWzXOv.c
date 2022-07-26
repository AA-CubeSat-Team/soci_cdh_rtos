/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xrot_GqxWzXOv.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun May  8 21:05:29 2022
 */

#include "rtwtypes.h"
#include "xrot_GqxWzXOv.h"

/* Function for MATLAB Function: '<S210>/INITIALIZE' */
void xrot_GqxWzXOv(int32_T n, real_T x[16], int32_T ix0, int32_T iy0, real_T c,
                   real_T s)
{
  real_T temp;
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      temp = c * x[ix] + s * x[iy];
      x[iy] = c * x[iy] - s * x[ix];
      x[ix] = temp;
      iy += 4;
      ix += 4;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

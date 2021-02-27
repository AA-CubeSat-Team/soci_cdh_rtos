/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: eye_bAKT5eRN.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:19:10 2021
 */

#include "rtwtypes.h"
#include <string.h>
#include "eye_bAKT5eRN.h"

/* Function for MATLAB Function: '<S317>/SOLVE' */
void eye_bAKT5eRN(real_T b_I[10000])
{
  int32_T k;
  memset(&b_I[0], 0, 10000U * sizeof(real_T));
  for (k = 0; k < 100; k++) {
    b_I[k + 100 * k] = 1.0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

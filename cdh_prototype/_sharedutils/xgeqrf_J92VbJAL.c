/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xgeqrf_J92VbJAL.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <string.h>
#include "qrf_87AzkAFc.h"
#include "xgeqrf_J92VbJAL.h"

/* Function for MATLAB Function: '<S119>/QR_factorization' */
void xgeqrf_J92VbJAL(real_T A[144], real_T tau[12])
{
  memset(&tau[0], 0, 12U * sizeof(real_T));
  qrf_87AzkAFc(A, 1, 12, 12, 12, tau);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

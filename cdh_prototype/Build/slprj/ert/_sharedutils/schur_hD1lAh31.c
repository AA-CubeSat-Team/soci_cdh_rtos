/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: schur_hD1lAh31.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 25 17:45:01 2021
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "eml_dlahqr_HClTWgbm.h"
#include "xgehrd_vbf45fhC.h"
#include "xzlarf_tQsI3TnT.h"
#include "schur_hD1lAh31.h"

/* Function for MATLAB Function: '<S438>/INITIALIZE' */
void schur_hD1lAh31(const real_T A[16], real_T V[16], real_T T[16])
{
  real_T tau[3];
  boolean_T p;
  int32_T itau;
  real_T work[4];
  p = true;
  for (itau = 0; itau < 16; itau++) {
    p = (p && ((!rtIsInf(A[itau])) && (!rtIsNaN(A[itau]))));
  }

  if (!p) {
    for (itau = 0; itau < 16; itau++) {
      V[itau] = (rtNaN);
    }

    for (itau = 2; itau < 5; itau++) {
      V[itau - 1] = 0.0;
    }

    for (itau = 3; itau < 5; itau++) {
      V[itau + 3] = 0.0;
    }

    V[11] = 0.0;
    for (itau = 0; itau < 16; itau++) {
      T[itau] = (rtNaN);
    }
  } else {
    memcpy(&T[0], &A[0], sizeof(real_T) << 4U);
    xgehrd_vbf45fhC(T, tau);
    memcpy(&V[0], &T[0], sizeof(real_T) << 4U);
    for (itau = 0; itau < 3; itau++) {
      V[12 + itau] = 0.0;
    }

    for (itau = 0; itau < 2; itau++) {
      V[8 + itau] = 0.0;
    }

    for (itau = 1; itau + 3 < 5; itau++) {
      V[itau + 10] = V[itau + 6];
    }

    V[4] = 0.0;
    for (itau = 0; itau + 3 < 5; itau++) {
      V[itau + 6] = V[itau + 2];
    }

    work[0] = 0.0;
    V[1] = 0.0;
    work[1] = 0.0;
    V[2] = 0.0;
    work[2] = 0.0;
    V[3] = 0.0;
    work[3] = 0.0;
    V[0] = 1.0;
    V[15] = 1.0 - tau[2];
    for (itau = 0; itau < 2; itau++) {
      V[14 - itau] = 0.0;
    }

    V[10] = 1.0;
    xzlarf_tQsI3TnT(2, 1, 11, tau[1], V, 15, work);
    for (itau = 11; itau < 12; itau++) {
      V[itau] *= -tau[1];
    }

    V[10] = 1.0 - tau[1];
    V[9] = 0.0;
    V[5] = 1.0;
    xzlarf_tQsI3TnT(3, 2, 6, tau[0], V, 10, work);
    for (itau = 6; itau < 8; itau++) {
      V[itau] *= -tau[0];
    }

    V[5] = 1.0 - tau[0];
    eml_dlahqr_HClTWgbm(T, V);
    T[3] = 0.0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

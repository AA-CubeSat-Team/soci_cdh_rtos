/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep  9 13:53:00 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_private.h>
#include <gnc_build/FSW_Lib_ert_rtw/MEKF_lib.h>

/* Forward declaration for local functions */
static real_T xnrm2(int32_T n, const real_T x[144], int32_T ix0);
static void xgemv(int32_T m, int32_T n, const real_T A[144], int32_T ia0, const
                  real_T x[144], int32_T ix0, real_T y[12]);
static void xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const real_T
                  y[12], real_T A[144], int32_T ia0);
static void xgeqrf(real_T A[144], real_T tau[12]);
static void qr(const real_T A[144], real_T Q[144], real_T R[144]);
static void mrdivide_helper(real_T A[36], const real_T B_0[36]);
real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (rtIsNaN(u0) || rtIsInf(u0) || (rtIsNaN(u1) || rtIsInf(u1))) {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = fabs(u0 / u1);
      if (!(fabs(u1_0 - floor(u1_0 + 0.5)) > DBL_EPSILON * u1_0)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S20>/MATLAB Function'
 *    '<S59>/MATLAB Function'
 */
void MATLABFunction(real_T rtu_u, real_T rtu_min_angle_deg, boolean_T *rty_y)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  *rty_y = false;
  if (rtIsInf(rtu_min_angle_deg) || rtIsNaN(rtu_min_angle_deg)) {
    b_x = (rtNaN);
  } else {
    b_x = rt_remd_snf(rtu_min_angle_deg, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      b_x = cos(b_x);
      break;

     case 1:
      b_x = -sin(b_x);
      break;

     case -1:
      b_x = sin(b_x);
      break;

     default:
      b_x = -cos(b_x);
      break;
    }
  }

  if (fabs(rtu_u) <= b_x) {
    *rty_y = true;
  }
}

/* Function for MATLAB Function: '<S16>/QR Factorization' */
static real_T xnrm2(int32_T n, const real_T x[144], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S16>/QR Factorization' */
static void xgemv(int32_T m, int32_T n, const real_T A[144], int32_T ia0, const
                  real_T x[144], int32_T ix0, real_T y[12])
{
  int32_T ix;
  real_T c;
  int32_T b_iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 12 + ia0;
    for (iac = ia0; iac <= b; iac += 12) {
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S16>/QR Factorization' */
static void xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const real_T
                  y[12], real_T A[144], int32_T ia0)
{
  int32_T jA;
  int32_T jy;
  real_T temp;
  int32_T ix;
  int32_T j;
  int32_T b;
  int32_T ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 12;
    }
  }
}

/* Function for MATLAB Function: '<S16>/QR Factorization' */
static void xgeqrf(real_T A[144], real_T tau[12])
{
  real_T work[12];
  int32_T i_i;
  real_T b_atmp;
  int32_T i;
  real_T xnorm;
  int32_T knt;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T exitg1;
  boolean_T exitg2;
  memset(&work[0], 0, 12U * sizeof(real_T));
  for (i = 0; i < 12; i++) {
    i_i = i * 12 + i;
    if (1 + i < 12) {
      b_atmp = A[i_i];
      tau[i] = 0.0;
      xnorm = xnrm2(11 - i, A, i_i + 2);
      if (xnorm != 0.0) {
        xnorm = rt_hypotd_snf(A[i_i], xnorm);
        if (A[i_i] >= 0.0) {
          xnorm = -xnorm;
        }

        if (fabs(xnorm) < 1.0020841800044864E-292) {
          knt = -1;
          lastv = i_i - i;
          do {
            knt++;
            for (lastc = i_i + 1; lastc < lastv + 12; lastc++) {
              A[lastc] *= 9.9792015476736E+291;
            }

            xnorm *= 9.9792015476736E+291;
            b_atmp *= 9.9792015476736E+291;
          } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

          xnorm = rt_hypotd_snf(b_atmp, xnrm2(11 - i, A, i_i + 2));
          if (b_atmp >= 0.0) {
            xnorm = -xnorm;
          }

          tau[i] = (xnorm - b_atmp) / xnorm;
          b_atmp = 1.0 / (b_atmp - xnorm);
          lastv = i_i - i;
          for (lastc = i_i + 1; lastc < lastv + 12; lastc++) {
            A[lastc] *= b_atmp;
          }

          for (lastv = 0; lastv <= knt; lastv++) {
            xnorm *= 1.0020841800044864E-292;
          }

          b_atmp = xnorm;
        } else {
          tau[i] = (xnorm - A[i_i]) / xnorm;
          b_atmp = 1.0 / (A[i_i] - xnorm);
          knt = i_i - i;
          for (lastv = i_i + 1; lastv < knt + 12; lastv++) {
            A[lastv] *= b_atmp;
          }

          b_atmp = xnorm;
        }
      }

      A[i_i] = b_atmp;
      b_atmp = A[i_i];
      A[i_i] = 1.0;
      knt = ((1 + i) * 12 + i) + 1;
      if (tau[i] != 0.0) {
        lastv = 12 - i;
        lastc = i_i - i;
        while ((lastv > 0) && (A[lastc + 11] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 11 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = (lastc - 1) * 12 + knt;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + lastv) - 1) {
              if (A[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        xgemv(lastv, lastc, A, knt, A, i_i + 1, work);
        xgerc(lastv, lastc, -tau[i], i_i + 1, work, A, knt);
      }

      A[i_i] = b_atmp;
    } else {
      tau[11] = 0.0;
    }
  }
}

/* Function for MATLAB Function: '<S16>/QR Factorization' */
static void qr(const real_T A[144], real_T Q[144], real_T R[144])
{
  real_T b_A[144];
  real_T tau[12];
  int32_T d_i;
  int32_T itau;
  real_T work[12];
  int32_T iaii;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 144U * sizeof(real_T));
  xgeqrf(b_A, tau);
  for (itau = 0; itau < 12; itau++) {
    for (d_i = 0; d_i <= itau; d_i++) {
      R[d_i + 12 * itau] = b_A[12 * itau + d_i];
    }

    for (d_i = itau; d_i + 2 < 13; d_i++) {
      R[(d_i + 12 * itau) + 1] = 0.0;
    }

    work[itau] = 0.0;
  }

  itau = 11;
  for (d_i = 11; d_i >= 0; d_i--) {
    iaii = (d_i * 12 + d_i) + 1;
    if (d_i + 1 < 12) {
      b_A[iaii - 1] = 1.0;
      if (tau[itau] != 0.0) {
        lastv = 12 - d_i;
        lastc = (iaii - d_i) + 10;
        while ((lastv > 0) && (b_A[lastc] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 11 - d_i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = ((lastc - 1) * 12 + iaii) + 11;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia + 1 <= coltop + lastv) {
              if (b_A[ia] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        xgemv(lastv, lastc, b_A, iaii + 12, b_A, iaii, work);
        xgerc(lastv, lastc, -tau[itau], iaii, work, b_A, iaii + 12);
      }

      lastv = (iaii - d_i) + 11;
      for (lastc = iaii; lastc < lastv; lastc++) {
        b_A[lastc] *= -tau[itau];
      }
    }

    b_A[iaii - 1] = 1.0 - tau[itau];
    for (lastv = 0; lastv < d_i; lastv++) {
      b_A[(iaii - lastv) - 2] = 0.0;
    }

    itau--;
  }

  for (itau = 0; itau < 12; itau++) {
    memcpy(&Q[itau * 12], &b_A[itau * 12], 12U * sizeof(real_T));
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S16>/QR Factorization' */
static void mrdivide_helper(real_T A[36], const real_T B_0[36])
{
  real_T b_A[36];
  int8_T ipiv[6];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&b_A[0], &B_0[0], 36U * sizeof(real_T));
  for (d = 0; d < 6; d++) {
    ipiv[d] = (int8_T)(1 + d);
  }

  for (j = 0; j < 5; j++) {
    jBcol = j * 7;
    iy = 0;
    ix = jBcol;
    smax = fabs(b_A[jBcol]);
    for (kBcol = 2; kBcol <= 6 - j; kBcol++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > smax) {
        iy = kBcol - 1;
        smax = s;
      }
    }

    if (b_A[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (kBcol = 0; kBcol < 6; kBcol++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      iy = (jBcol - j) + 6;
      for (ix = jBcol + 1; ix < iy; ix++) {
        b_A[ix] /= b_A[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 6;
    for (kBcol = 0; kBcol <= 4 - j; kBcol++) {
      if (b_A[ix] != 0.0) {
        smax = -b_A[ix];
        c_ix = jBcol + 1;
        d = (iy - j) + 12;
        for (ijA = 7 + iy; ijA < d; ijA++) {
          b_A[ijA] += b_A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 6;
      iy += 6;
    }
  }

  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    iy = 6 * j;
    for (ix = 0; ix < j; ix++) {
      kBcol = 6 * ix;
      smax = b_A[ix + iy];
      if (smax != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          d = c_ix + jBcol;
          A[d] -= smax * A[c_ix + kBcol];
        }
      }
    }

    smax = 1.0 / b_A[j + iy];
    for (iy = 0; iy < 6; iy++) {
      d = iy + jBcol;
      A[d] *= smax;
    }
  }

  for (j = 5; j >= 0; j--) {
    jBcol = 6 * j;
    iy = 6 * j - 1;
    for (ix = j + 2; ix < 7; ix++) {
      kBcol = (ix - 1) * 6;
      smax = b_A[ix + iy];
      if (smax != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          A[c_ix + jBcol] -= smax * A[c_ix + kBcol];
        }
      }
    }
  }

  for (j = 4; j >= 0; j--) {
    if (j + 1 != ipiv[j]) {
      jBcol = ipiv[j] - 1;
      for (iy = 0; iy < 6; iy++) {
        smax = A[6 * j + iy];
        A[iy + 6 * j] = A[6 * jBcol + iy];
        A[iy + 6 * jBcol] = smax;
      }
    }
  }
}

/* System initialize for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Init(real_T rty_sc_quat[4], DW_MEKF_lib *localDW)
{
  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  memcpy(&localDW->UnitDelay_DSTATE[0], &rtConstP.UnitDelay_InitialCondition[0],
         36U * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay2' */
  localDW->UnitDelay2_DSTATE[0] = 1.0;
  localDW->UnitDelay2_DSTATE[1] = 0.0;
  localDW->UnitDelay2_DSTATE[2] = 0.0;
  localDW->UnitDelay2_DSTATE[3] = 0.0;

  /* InitializeConditions for RateTransition: '<S50>/Rate Transition' */
  memcpy(&localDW->RateTransition_Buffer0[0], &rtConstP.pooled17[0], 9U * sizeof
         (real_T));

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[0] = 1.0;

  /* SystemInitialize for IfAction SubSystem: '<S19>/Triad_alg' */
  /* SystemInitialize for Merge: '<S66>/Merge' */
  localDW->Merge[0] = 1.0;

  /* End of SystemInitialize for SubSystem: '<S19>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[0] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S19>/Triad_alg' */
  /* SystemInitialize for Merge: '<S66>/Merge' */
  localDW->Merge[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S19>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[1] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S19>/Triad_alg' */
  /* SystemInitialize for Merge: '<S66>/Merge' */
  localDW->Merge[2] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S19>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[2] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Triad Estimator' */
  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[3] = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S19>/Triad_alg' */
  /* SystemInitialize for Merge: '<S66>/Merge' */
  localDW->Merge[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S19>/Triad_alg' */
  /* End of SystemInitialize for SubSystem: '<S3>/Triad Estimator' */

  /* SystemInitialize for Merge: '<S3>/q (+) merge' */
  rty_sc_quat[3] = 0.0;
}

/* Start for atomic system: '<S1>/MEKF_lib' */
void MEKF_lib_Start(DW_MEKF_lib *localDW)
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    /* Start for RateTransition: '<S50>/Rate Transition' */
    localDW->RateTransition[i] = rtConstP.pooled17[i];

    /* Start for S-Function (sdspeye): '<S50>/Identity Matrix' */
    localDW->IdentityMatrix[i] = 0.0;
  }

  /* Start for S-Function (sdspeye): '<S50>/Identity Matrix' */
  /* Fill in 1's on the diagonal. */
  localDW->IdentityMatrix[0] = 1.0;
  localDW->IdentityMatrix[4] = 1.0;
  localDW->IdentityMatrix[8] = 1.0;
}

/* Output and update for atomic system: '<S1>/MEKF_lib' */
void MEKF_libTID0(RT_MODEL * const rtM, const real_T rtu_sc2sun_eci_unit[3],
                  const real_T rtu_mag_eci_T[3], const real_T
                  rtu_sun_meas_body_unit[3], const real_T rtu_mag_meas_body_T[3],
                  const real_T rtu_gyro_meas_body_radps[3], boolean_T
                  rtu_sunsensor_valid, boolean_T rtu_mag_meas_valid, boolean_T
                  rtu_gryo_meas_valid, boolean_T rtu_Triad_Activate, real_T
                  rty_sc_quat[4], real_T rty_sc_body_rates[3], real_T
                  rty_uSig_deg[3], real_T rty_Bias_radps[3], DW_MEKF_lib
                  *localDW)
{
  /* local block i/o variables */
  real_T rtb_MatrixConcatenate2_l[16];
  int8_T Phi_22[9];
  int8_T b_I[9];
  static const int8_T a[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_a[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T C[72];
  real_T unusedU2[144];
  real_T R[144];
  real_T rtb_ExtractDiagonal[6];
  real_T rtb_Merge_d[4];
  real_T rtb_Product5_k;
  real_T rtb_Product1_d5;
  real_T rtb_Product3_h;
  real_T rtb_Product1_h;
  real_T rtb_VectorConcatenate[12];
  real_T rtb_MatrixConcatenate3[9];
  int32_T idxStart;
  int32_T i;
  real_T rtb_M[3];
  real_T rtb_MathFunction1_oz[9];
  real_T rtb_P_cholmerge[36];
  real_T rtb_Phi[36];
  boolean_T rtb_AND;
  boolean_T rtb_LogicalOperator_j;
  real_T rtb_Sum_fk;
  real_T rtb_Sum_k1;
  real_T rtb_MatrixMultiply1_l[9];
  real_T tmp[144];
  real_T rtb_P_cholmerge_0[36];
  real_T rtu_sun_meas_body_unit_0[6];
  real_T rtu_sun_meas_body_unit_1[6];
  real_T rtb_M_l_idx_2;
  real_T rtb_M_l_idx_1;
  real_T rtb_M_l_idx_0;
  boolean_T rtb_AND_tmp;
  int32_T rtb_MatrixMultiply1_p_tmp;
  int32_T rtb_MatrixMultiply1_p_tmp_0;
  real_T rtb_Add_m_tmp;
  real_T rtb_Add_m_tmp_0;
  real_T rtb_Add_m_tmp_1;
  real_T unusedExpr[12];

  /* MATLAB Function: '<S20>/MATLAB Function' incorporates:
   *  Constant: '<S20>/min_angle_deg'
   *  DotProduct: '<S20>/Dot Product'
   *  DotProduct: '<S20>/Dot Product1'
   *  DotProduct: '<S20>/Dot Product2'
   *  Product: '<S20>/Divide'
   *  Product: '<S20>/Multiply'
   *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
   *  Sqrt: '<S20>/Sqrt'
   *  Sqrt: '<S20>/Sqrt1'
   */
  MATLABFunction(((rtu_sun_meas_body_unit[0] * rtu_mag_meas_body_T[0] +
                   rtu_sun_meas_body_unit[1] * rtu_mag_meas_body_T[1]) +
                  rtu_sun_meas_body_unit[2] * rtu_mag_meas_body_T[2]) / (sqrt
    ((rtu_sun_meas_body_unit[0] * rtu_sun_meas_body_unit[0] +
      rtu_sun_meas_body_unit[1] * rtu_sun_meas_body_unit[1]) +
     rtu_sun_meas_body_unit[2] * rtu_sun_meas_body_unit[2]) * sqrt
    ((rtu_mag_meas_body_T[0] * rtu_mag_meas_body_T[0] + rtu_mag_meas_body_T[1] *
      rtu_mag_meas_body_T[1]) + rtu_mag_meas_body_T[2] * rtu_mag_meas_body_T[2])),
                 1.5, &rtb_AND);

  /* Outputs for IfAction SubSystem: '<S3>/Triad Estimator' incorporates:
   *  ActionPort: '<S19>/Action Port'
   */
  /* If: '<S3>/Does Triad for u1 ==1 and//or gyro_valid == 0, else: MEKF' incorporates:
   *  Logic: '<S14>/AND'
   *  Logic: '<S19>/Logical Operator'
   */
  rtb_AND_tmp = (rtu_sunsensor_valid && rtu_mag_meas_valid);

  /* End of Outputs for SubSystem: '<S3>/Triad Estimator' */

  /* Logic: '<S14>/AND' */
  rtb_AND = (rtb_AND_tmp && rtb_AND && rtu_gryo_meas_valid);

  /* If: '<S3>/Does Triad for u1 ==1 and//or gyro_valid == 0, else: MEKF' incorporates:
   *  Inport: '<S22>/In1'
   *  UnitDelay: '<S15>/Unit Delay2'
   */
  if (rtu_Triad_Activate || (!rtu_gryo_meas_valid)) {
    /* Outputs for IfAction SubSystem: '<S3>/Triad Estimator' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* MATLAB Function: '<S59>/MATLAB Function' incorporates:
     *  Constant: '<S59>/min_angle_deg'
     *  DotProduct: '<S59>/Dot Product'
     *  DotProduct: '<S59>/Dot Product1'
     *  DotProduct: '<S59>/Dot Product2'
     *  Product: '<S59>/Divide'
     *  Product: '<S59>/Multiply'
     *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
     *  Sqrt: '<S59>/Sqrt'
     *  Sqrt: '<S59>/Sqrt1'
     */
    MATLABFunction(((rtu_sun_meas_body_unit[0] * rtu_mag_meas_body_T[0] +
                     rtu_sun_meas_body_unit[1] * rtu_mag_meas_body_T[1]) +
                    rtu_sun_meas_body_unit[2] * rtu_mag_meas_body_T[2]) / (sqrt
      ((rtu_sun_meas_body_unit[0] * rtu_sun_meas_body_unit[0] +
        rtu_sun_meas_body_unit[1] * rtu_sun_meas_body_unit[1]) +
       rtu_sun_meas_body_unit[2] * rtu_sun_meas_body_unit[2]) * sqrt
      ((rtu_mag_meas_body_T[0] * rtu_mag_meas_body_T[0] + rtu_mag_meas_body_T[1]
        * rtu_mag_meas_body_T[1]) + rtu_mag_meas_body_T[2] *
       rtu_mag_meas_body_T[2])), 2.5, &rtb_LogicalOperator_j);

    /* Logic: '<S19>/Logical Operator' */
    rtb_LogicalOperator_j = (rtb_AND_tmp && rtb_LogicalOperator_j);

    /* If: '<S19>/If' incorporates:
     *  Inport: '<S56>/quat_old'
     *  UnitDelay: '<S19>/Unit Delay'
     */
    if (rtb_LogicalOperator_j) {
      /* Outputs for IfAction SubSystem: '<S19>/Triad_alg' incorporates:
       *  ActionPort: '<S58>/Action Port'
       */
      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate3In1' incorporates:
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_MatrixConcatenate3[0] = rtu_sc2sun_eci_unit[0];

      /* Sum: '<S62>/Add3' incorporates:
       *  Product: '<S62>/Element product'
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_M[0] = rtu_sun_meas_body_unit[1] * rtu_mag_meas_body_T[2] -
        rtu_sun_meas_body_unit[2] * rtu_mag_meas_body_T[1];

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate3In1' incorporates:
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_MatrixConcatenate3[1] = rtu_sc2sun_eci_unit[1];

      /* Sum: '<S62>/Add3' incorporates:
       *  Product: '<S62>/Element product'
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_M[1] = rtu_sun_meas_body_unit[2] * rtu_mag_meas_body_T[0] -
        rtu_sun_meas_body_unit[0] * rtu_mag_meas_body_T[2];

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate3In1' incorporates:
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_MatrixConcatenate3[2] = rtu_sc2sun_eci_unit[2];

      /* Sum: '<S62>/Add3' incorporates:
       *  Product: '<S62>/Element product'
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_M[2] = rtu_sun_meas_body_unit[0] * rtu_mag_meas_body_T[1] -
        rtu_sun_meas_body_unit[1] * rtu_mag_meas_body_T[0];

      /* S-Function (sdsp2norm2): '<S58>/Normalization6' */
      rtb_Sum_fk = 1.0 / (sqrt((rtb_M[0] * rtb_M[0] + rtb_M[1] * rtb_M[1]) +
        rtb_M[2] * rtb_M[2]) + 1.0E-10);
      rtb_M[0] *= rtb_Sum_fk;

      /* Sum: '<S64>/Add3' incorporates:
       *  Product: '<S64>/Element product'
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_M_l_idx_0 = rtu_sc2sun_eci_unit[1] * rtu_mag_eci_T[2] -
        rtu_sc2sun_eci_unit[2] * rtu_mag_eci_T[1];

      /* S-Function (sdsp2norm2): '<S58>/Normalization6' */
      rtb_M[1] *= rtb_Sum_fk;

      /* Sum: '<S64>/Add3' incorporates:
       *  Product: '<S64>/Element product'
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_M_l_idx_1 = rtu_sc2sun_eci_unit[2] * rtu_mag_eci_T[0] -
        rtu_sc2sun_eci_unit[0] * rtu_mag_eci_T[2];

      /* S-Function (sdsp2norm2): '<S58>/Normalization6' */
      rtb_M[2] *= rtb_Sum_fk;

      /* Sum: '<S64>/Add3' incorporates:
       *  Product: '<S64>/Element product'
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_M_l_idx_2 = rtu_sc2sun_eci_unit[0] * rtu_mag_eci_T[1] -
        rtu_sc2sun_eci_unit[1] * rtu_mag_eci_T[0];

      /* S-Function (sdsp2norm2): '<S58>/Normalization7' */
      rtb_Sum_fk = 1.0 / (sqrt((rtb_M_l_idx_0 * rtb_M_l_idx_0 + rtb_M_l_idx_1 *
        rtb_M_l_idx_1) + rtb_M_l_idx_2 * rtb_M_l_idx_2) + 1.0E-10);
      rtb_M_l_idx_0 *= rtb_Sum_fk;
      rtb_M_l_idx_1 *= rtb_Sum_fk;
      rtb_M_l_idx_2 *= rtb_Sum_fk;

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[3] = rtb_M_l_idx_0;

      /* Sum: '<S65>/Add3' incorporates:
       *  Product: '<S65>/Element product'
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_MatrixConcatenate3[6] = rtu_sc2sun_eci_unit[1] * rtb_M_l_idx_2 -
        rtu_sc2sun_eci_unit[2] * rtb_M_l_idx_1;

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[4] = rtb_M_l_idx_1;

      /* Sum: '<S65>/Add3' incorporates:
       *  Product: '<S65>/Element product'
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_MatrixConcatenate3[7] = rtu_sc2sun_eci_unit[2] * rtb_M_l_idx_0 -
        rtu_sc2sun_eci_unit[0] * rtb_M_l_idx_2;

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate3In2' */
      rtb_MatrixConcatenate3[5] = rtb_M_l_idx_2;

      /* Sum: '<S65>/Add3' incorporates:
       *  Product: '<S65>/Element product'
       *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
       */
      rtb_MatrixConcatenate3[8] = rtu_sc2sun_eci_unit[0] * rtb_M_l_idx_1 -
        rtu_sc2sun_eci_unit[1] * rtb_M_l_idx_0;

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate2In1' incorporates:
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_MathFunction1_oz[0] = rtu_sun_meas_body_unit[0];

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_oz[3] = rtb_M[0];

      /* Sum: '<S63>/Add3' incorporates:
       *  Product: '<S63>/Element product'
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_MathFunction1_oz[6] = rtu_sun_meas_body_unit[1] * rtb_M[2] -
        rtu_sun_meas_body_unit[2] * rtb_M[1];

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate2In1' incorporates:
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_MathFunction1_oz[1] = rtu_sun_meas_body_unit[1];

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_oz[4] = rtb_M[1];

      /* Sum: '<S63>/Add3' incorporates:
       *  Product: '<S63>/Element product'
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_MathFunction1_oz[7] = rtu_sun_meas_body_unit[2] * rtb_M[0] -
        rtu_sun_meas_body_unit[0] * rtb_M[2];

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate2In1' incorporates:
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_MathFunction1_oz[2] = rtu_sun_meas_body_unit[2];

      /* SignalConversion: '<S58>/ConcatBufferAtMatrix Concatenate2In2' */
      rtb_MathFunction1_oz[5] = rtb_M[2];

      /* Sum: '<S63>/Add3' incorporates:
       *  Product: '<S63>/Element product'
       *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
       */
      rtb_MathFunction1_oz[8] = rtu_sun_meas_body_unit[0] * rtb_M[1] -
        rtu_sun_meas_body_unit[1] * rtb_M[0];

      /* Product: '<S58>/Matrix Multiply1' incorporates:
       *  Math: '<S58>/Math Function1'
       */
      for (i = 0; i < 3; i++) {
        for (idxStart = 0; idxStart < 3; idxStart++) {
          rtb_MatrixMultiply1_p_tmp = i + 3 * idxStart;
          rtb_MatrixMultiply1_l[rtb_MatrixMultiply1_p_tmp] = 0.0;
          rtb_MatrixMultiply1_p_tmp_0 = 3 * idxStart + i;
          rtb_MatrixMultiply1_l[rtb_MatrixMultiply1_p_tmp] =
            rtb_MatrixMultiply1_l[rtb_MatrixMultiply1_p_tmp_0] +
            rtb_MathFunction1_oz[i] * rtb_MatrixConcatenate3[idxStart];
          rtb_MatrixMultiply1_l[rtb_MatrixMultiply1_p_tmp] =
            rtb_MatrixMultiply1_l[rtb_MatrixMultiply1_p_tmp_0] +
            rtb_MathFunction1_oz[i + 3] * rtb_MatrixConcatenate3[idxStart + 3];
          rtb_MatrixMultiply1_l[rtb_MatrixMultiply1_p_tmp] =
            rtb_MatrixMultiply1_l[rtb_MatrixMultiply1_p_tmp_0] +
            rtb_MathFunction1_oz[i + 6] * rtb_MatrixConcatenate3[idxStart + 6];
        }
      }

      /* End of Product: '<S58>/Matrix Multiply1' */

      /* Sum: '<S70>/Add' */
      rtb_M_l_idx_0 = (rtb_MatrixMultiply1_l[0] + rtb_MatrixMultiply1_l[4]) +
        rtb_MatrixMultiply1_l[8];

      /* If: '<S66>/If' */
      if (rtb_M_l_idx_0 > 0.0) {
        /* Outputs for IfAction SubSystem: '<S66>/Positive Trace' incorporates:
         *  ActionPort: '<S68>/Action Port'
         */
        PositiveTrace(rtb_M_l_idx_0, rtb_MatrixMultiply1_l, &localDW->Merge[0],
                      &localDW->Merge[1]);

        /* End of Outputs for SubSystem: '<S66>/Positive Trace' */
      } else {
        /* Outputs for IfAction SubSystem: '<S66>/Negative Trace' incorporates:
         *  ActionPort: '<S67>/Action Port'
         */
        NegativeTrace(rtb_MatrixMultiply1_l, localDW->Merge);

        /* End of Outputs for SubSystem: '<S66>/Negative Trace' */
      }

      /* End of If: '<S66>/If' */

      /* Signum: '<S58>/Sign' */
      if (localDW->Merge[0] < 0.0) {
        rtb_M_l_idx_0 = -1.0;
      } else if (localDW->Merge[0] > 0.0) {
        rtb_M_l_idx_0 = 1.0;
      } else if (localDW->Merge[0] == 0.0) {
        rtb_M_l_idx_0 = 0.0;
      } else {
        rtb_M_l_idx_0 = (rtNaN);
      }

      /* End of Signum: '<S58>/Sign' */

      /* Product: '<S58>/Multiply' */
      rtb_Merge_d[0] = rtb_M_l_idx_0 * localDW->Merge[0];
      rtb_Merge_d[1] = rtb_M_l_idx_0 * localDW->Merge[1];
      rtb_Merge_d[2] = rtb_M_l_idx_0 * localDW->Merge[2];
      rtb_Merge_d[3] = rtb_M_l_idx_0 * localDW->Merge[3];

      /* End of Outputs for SubSystem: '<S19>/Triad_alg' */
    } else {
      /* Outputs for IfAction SubSystem: '<S19>/Bypass Triad' incorporates:
       *  ActionPort: '<S56>/Action Port'
       */
      rtb_Merge_d[0] = localDW->UnitDelay_DSTATE_p[0];
      rtb_Merge_d[1] = localDW->UnitDelay_DSTATE_p[1];
      rtb_Merge_d[2] = localDW->UnitDelay_DSTATE_p[2];
      rtb_Merge_d[3] = localDW->UnitDelay_DSTATE_p[3];

      /* End of Outputs for SubSystem: '<S19>/Bypass Triad' */
    }

    /* End of If: '<S19>/If' */

    /* Sqrt: '<S60>/sqrt' incorporates:
     *  Product: '<S61>/Product'
     *  Product: '<S61>/Product1'
     *  Product: '<S61>/Product2'
     *  Product: '<S61>/Product3'
     *  Sum: '<S61>/Sum'
     */
    rtb_M_l_idx_0 = sqrt(((rtb_Merge_d[0] * rtb_Merge_d[0] + rtb_Merge_d[1] *
      rtb_Merge_d[1]) + rtb_Merge_d[2] * rtb_Merge_d[2]) + rtb_Merge_d[3] *
                         rtb_Merge_d[3]);

    /* Product: '<S57>/Product' */
    localDW->Merge1[0] = rtb_Merge_d[0] / rtb_M_l_idx_0;

    /* Product: '<S57>/Product1' */
    localDW->Merge1[1] = rtb_Merge_d[1] / rtb_M_l_idx_0;

    /* Product: '<S57>/Product2' */
    localDW->Merge1[2] = rtb_Merge_d[2] / rtb_M_l_idx_0;

    /* Product: '<S57>/Product3' */
    localDW->Merge1[3] = rtb_Merge_d[3] / rtb_M_l_idx_0;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    localDW->UnitDelay_DSTATE_p[0] = rtb_Merge_d[0];
    localDW->UnitDelay_DSTATE_p[1] = rtb_Merge_d[1];
    localDW->UnitDelay_DSTATE_p[2] = rtb_Merge_d[2];
    localDW->UnitDelay_DSTATE_p[3] = rtb_Merge_d[3];

    /* End of Outputs for SubSystem: '<S3>/Triad Estimator' */
  } else {
    /* Outputs for IfAction SubSystem: '<S15>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    localDW->Merge1[0] = localDW->UnitDelay2_DSTATE[0];
    localDW->Merge1[1] = localDW->UnitDelay2_DSTATE[1];
    localDW->Merge1[2] = localDW->UnitDelay2_DSTATE[2];
    localDW->Merge1[3] = localDW->UnitDelay2_DSTATE[3];

    /* End of Outputs for SubSystem: '<S15>/If Action Subsystem2' */
  }

  /* If: '<S3>/If' incorporates:
   *  Inport: '<S13>/Bias (-)'
   *  Inport: '<S13>/P_chol (-)'
   *  Inport: '<S13>/q (-)'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (rtb_AND) {
    /* Outputs for IfAction SubSystem: '<S3>/Measurement Update' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* SignalConversion: '<S23>/ConcatBufferAtVertical Matrix ConcatenateIn2' */
    memset(&rtb_P_cholmerge[18], 0, 18U * sizeof(real_T));

    /* Sqrt: '<S37>/sqrt' incorporates:
     *  Product: '<S38>/Product'
     *  Product: '<S38>/Product1'
     *  Product: '<S38>/Product2'
     *  Product: '<S38>/Product3'
     *  Sqrt: '<S43>/sqrt'
     *  Sum: '<S38>/Sum'
     */
    rtb_M_l_idx_2 = sqrt(((localDW->Merge1[0] * localDW->Merge1[0] +
      localDW->Merge1[1] * localDW->Merge1[1]) + localDW->Merge1[2] *
                          localDW->Merge1[2]) + localDW->Merge1[3] *
                         localDW->Merge1[3]);

    /* Product: '<S33>/Product2' incorporates:
     *  Sqrt: '<S37>/sqrt'
     */
    rtb_Product3_h = localDW->Merge1[2] / rtb_M_l_idx_2;

    /* Product: '<S33>/Product3' incorporates:
     *  Sqrt: '<S37>/sqrt'
     */
    rtb_Product1_d5 = localDW->Merge1[3] / rtb_M_l_idx_2;

    /* Product: '<S33>/Product1' incorporates:
     *  Sqrt: '<S37>/sqrt'
     */
    rtb_M_l_idx_1 = localDW->Merge1[1] / rtb_M_l_idx_2;

    /* Product: '<S33>/Product' incorporates:
     *  Sqrt: '<S37>/sqrt'
     */
    rtb_Product5_k = localDW->Merge1[0] / rtb_M_l_idx_2;

    /* Product: '<S34>/Product7' incorporates:
     *  Product: '<S35>/Product7'
     */
    rtb_Sum_fk = rtb_Product1_d5 * rtb_Product1_d5;

    /* Product: '<S34>/Product' incorporates:
     *  Product: '<S35>/Product'
     */
    rtb_Add_m_tmp = rtb_M_l_idx_1 * rtb_Product3_h;

    /* Product: '<S34>/Product1' incorporates:
     *  Product: '<S35>/Product1'
     */
    rtb_Add_m_tmp_0 = rtb_Product5_k * rtb_Product1_d5;

    /* Product: '<S34>/Product3' incorporates:
     *  Product: '<S36>/Product'
     */
    rtb_Sum_k1 = rtb_M_l_idx_1 * rtb_Product1_d5;

    /* Product: '<S34>/Product2' incorporates:
     *  Product: '<S36>/Product1'
     */
    rtb_Product1_h = rtb_Product5_k * rtb_Product3_h;

    /* Product: '<S34>/Product6' incorporates:
     *  Product: '<S36>/Product7'
     */
    rtb_Add_m_tmp_1 = rtb_Product3_h * rtb_Product3_h;

    /* Sum: '<S34>/Sum' incorporates:
     *  Constant: '<S34>/Constant'
     *  Gain: '<S34>/Gain'
     *  Gain: '<S34>/Gain1'
     *  Gain: '<S34>/Gain2'
     *  Product: '<S34>/Product'
     *  Product: '<S34>/Product1'
     *  Product: '<S34>/Product2'
     *  Product: '<S34>/Product3'
     *  Product: '<S34>/Product4'
     *  Product: '<S34>/Product5'
     *  Product: '<S34>/Product6'
     *  Product: '<S34>/Product7'
     *  Product: '<S34>/Product8'
     *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
     *  Sum: '<S34>/Sum1'
     *  Sum: '<S34>/Sum2'
     *  Sum: '<S34>/Sum3'
     */
    rtb_M_l_idx_0 = (((0.5 - rtb_Add_m_tmp_1) - rtb_Sum_fk) * 2.0 *
                     rtu_sc2sun_eci_unit[0] + (rtb_Add_m_tmp + rtb_Add_m_tmp_0) *
                     2.0 * rtu_sc2sun_eci_unit[1]) + (rtb_Sum_k1 -
      rtb_Product1_h) * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Product: '<S35>/Product3' incorporates:
     *  Product: '<S36>/Product3'
     */
    rtb_Product3_h *= rtb_Product1_d5;

    /* Product: '<S35>/Product2' incorporates:
     *  Product: '<S36>/Product2'
     */
    rtb_Product5_k *= rtb_M_l_idx_1;

    /* Sum: '<S35>/Sum3' incorporates:
     *  Constant: '<S35>/Constant'
     *  Product: '<S35>/Product6'
     *  Sum: '<S36>/Sum3'
     */
    rtb_M_l_idx_1 = 0.5 - rtb_M_l_idx_1 * rtb_M_l_idx_1;

    /* Sum: '<S35>/Sum' incorporates:
     *  Gain: '<S35>/Gain'
     *  Gain: '<S35>/Gain1'
     *  Gain: '<S35>/Gain2'
     *  Product: '<S35>/Product2'
     *  Product: '<S35>/Product3'
     *  Product: '<S35>/Product4'
     *  Product: '<S35>/Product5'
     *  Product: '<S35>/Product8'
     *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
     *  Sum: '<S35>/Sum1'
     *  Sum: '<S35>/Sum2'
     *  Sum: '<S35>/Sum3'
     */
    rtb_Sum_fk = ((rtb_M_l_idx_1 - rtb_Sum_fk) * 2.0 * rtu_sc2sun_eci_unit[1] +
                  (rtb_Add_m_tmp - rtb_Add_m_tmp_0) * 2.0 * rtu_sc2sun_eci_unit
                  [0]) + (rtb_Product5_k + rtb_Product3_h) * 2.0 *
      rtu_sc2sun_eci_unit[2];

    /* Sum: '<S36>/Sum' incorporates:
     *  Gain: '<S36>/Gain'
     *  Gain: '<S36>/Gain1'
     *  Gain: '<S36>/Gain2'
     *  Product: '<S36>/Product4'
     *  Product: '<S36>/Product5'
     *  Product: '<S36>/Product8'
     *  RateTransition: '<S3>/sc2sun_eci_unit_rt1'
     *  Sum: '<S36>/Sum1'
     *  Sum: '<S36>/Sum2'
     *  Sum: '<S36>/Sum3'
     */
    rtb_Product5_k = ((rtb_Sum_k1 + rtb_Product1_h) * 2.0 * rtu_sc2sun_eci_unit
                      [0] + (rtb_Product3_h - rtb_Product5_k) * 2.0 *
                      rtu_sc2sun_eci_unit[1]) + (rtb_M_l_idx_1 - rtb_Add_m_tmp_1)
      * 2.0 * rtu_sc2sun_eci_unit[2];

    /* Outputs for Atomic SubSystem: '<S23>/CrossProdMatrix_lib' */
    CrossProdMatrix_lib(rtb_Product5_k, rtb_M_l_idx_0, rtb_Sum_fk,
                        rtb_MatrixConcatenate3);

    /* End of Outputs for SubSystem: '<S23>/CrossProdMatrix_lib' */

    /* Product: '<S39>/Product2' */
    rtb_Product1_h = localDW->Merge1[2] / rtb_M_l_idx_2;

    /* Product: '<S39>/Product3' */
    rtb_M_l_idx_1 = localDW->Merge1[3] / rtb_M_l_idx_2;

    /* Product: '<S39>/Product1' */
    rtb_Product1_d5 = localDW->Merge1[1] / rtb_M_l_idx_2;

    /* Product: '<S39>/Product' */
    rtb_M_l_idx_2 = localDW->Merge1[0] / rtb_M_l_idx_2;

    /* Sum: '<S40>/Sum' incorporates:
     *  Constant: '<S40>/Constant'
     *  Gain: '<S40>/Gain'
     *  Gain: '<S40>/Gain1'
     *  Gain: '<S40>/Gain2'
     *  Product: '<S40>/Product'
     *  Product: '<S40>/Product1'
     *  Product: '<S40>/Product2'
     *  Product: '<S40>/Product3'
     *  Product: '<S40>/Product4'
     *  Product: '<S40>/Product5'
     *  Product: '<S40>/Product6'
     *  Product: '<S40>/Product7'
     *  Product: '<S40>/Product8'
     *  Sum: '<S40>/Sum1'
     *  Sum: '<S40>/Sum2'
     *  Sum: '<S40>/Sum3'
     */
    rtb_Product3_h = (((0.5 - rtb_Product1_h * rtb_Product1_h) - rtb_M_l_idx_1 *
                       rtb_M_l_idx_1) * 2.0 * rtu_mag_eci_T[0] +
                      (rtb_Product1_d5 * rtb_Product1_h + rtb_M_l_idx_2 *
                       rtb_M_l_idx_1) * 2.0 * rtu_mag_eci_T[1]) +
      (rtb_Product1_d5 * rtb_M_l_idx_1 - rtb_M_l_idx_2 * rtb_Product1_h) * 2.0 *
      rtu_mag_eci_T[2];

    /* Sum: '<S41>/Sum' incorporates:
     *  Constant: '<S41>/Constant'
     *  Gain: '<S41>/Gain'
     *  Gain: '<S41>/Gain1'
     *  Gain: '<S41>/Gain2'
     *  Product: '<S41>/Product'
     *  Product: '<S41>/Product1'
     *  Product: '<S41>/Product2'
     *  Product: '<S41>/Product3'
     *  Product: '<S41>/Product4'
     *  Product: '<S41>/Product5'
     *  Product: '<S41>/Product6'
     *  Product: '<S41>/Product7'
     *  Product: '<S41>/Product8'
     *  Sum: '<S41>/Sum1'
     *  Sum: '<S41>/Sum2'
     *  Sum: '<S41>/Sum3'
     */
    rtb_Sum_k1 = (((0.5 - rtb_Product1_d5 * rtb_Product1_d5) - rtb_M_l_idx_1 *
                   rtb_M_l_idx_1) * 2.0 * rtu_mag_eci_T[1] + (rtb_Product1_d5 *
      rtb_Product1_h - rtb_M_l_idx_2 * rtb_M_l_idx_1) * 2.0 * rtu_mag_eci_T[0])
      + (rtb_M_l_idx_2 * rtb_Product1_d5 + rtb_Product1_h * rtb_M_l_idx_1) * 2.0
      * rtu_mag_eci_T[2];

    /* Sum: '<S42>/Sum' incorporates:
     *  Constant: '<S42>/Constant'
     *  Gain: '<S42>/Gain'
     *  Gain: '<S42>/Gain1'
     *  Gain: '<S42>/Gain2'
     *  Product: '<S42>/Product'
     *  Product: '<S42>/Product1'
     *  Product: '<S42>/Product2'
     *  Product: '<S42>/Product3'
     *  Product: '<S42>/Product4'
     *  Product: '<S42>/Product5'
     *  Product: '<S42>/Product6'
     *  Product: '<S42>/Product7'
     *  Product: '<S42>/Product8'
     *  Sum: '<S42>/Sum1'
     *  Sum: '<S42>/Sum2'
     *  Sum: '<S42>/Sum3'
     */
    rtb_Product1_d5 = ((rtb_Product1_d5 * rtb_M_l_idx_1 + rtb_M_l_idx_2 *
                        rtb_Product1_h) * 2.0 * rtu_mag_eci_T[0] +
                       (rtb_Product1_h * rtb_M_l_idx_1 - rtb_M_l_idx_2 *
                        rtb_Product1_d5) * 2.0 * rtu_mag_eci_T[1]) + ((0.5 -
      rtb_Product1_d5 * rtb_Product1_d5) - rtb_Product1_h * rtb_Product1_h) *
      2.0 * rtu_mag_eci_T[2];

    /* Outputs for Atomic SubSystem: '<S23>/CrossProdMatrix_lib1' */
    CrossProdMatrix_lib(rtb_Product1_d5, rtb_Product3_h, rtb_Sum_k1,
                        rtb_MathFunction1_oz);

    /* End of Outputs for SubSystem: '<S23>/CrossProdMatrix_lib1' */

    /* Concatenate: '<S23>/Horizontal Matrix Concatenate' */
    for (i = 0; i < 3; i++) {
      rtb_P_cholmerge[6 * i] = rtb_MatrixConcatenate3[3 * i];
      rtb_P_cholmerge[3 + 6 * i] = rtb_MathFunction1_oz[3 * i];
      rtb_MatrixMultiply1_p_tmp_0 = 3 * i + 1;
      rtb_P_cholmerge[1 + 6 * i] =
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_p_tmp_0];
      rtb_P_cholmerge[4 + 6 * i] =
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0];
      rtb_MatrixMultiply1_p_tmp_0 = 3 * i + 2;
      rtb_P_cholmerge[2 + 6 * i] =
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_p_tmp_0];
      rtb_P_cholmerge[5 + 6 * i] =
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0];
    }

    /* End of Concatenate: '<S23>/Horizontal Matrix Concatenate' */

    /* MATLAB Function: '<S16>/QR Factorization' incorporates:
     *  Constant: '<S16>/Constant'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MatrixMultiply1_p_tmp = i + 6 * idxStart;
        rtb_Phi[rtb_MatrixMultiply1_p_tmp] = 0.0;
        for (rtb_MatrixMultiply1_p_tmp_0 = 0; rtb_MatrixMultiply1_p_tmp_0 < 6;
             rtb_MatrixMultiply1_p_tmp_0++) {
          rtb_Phi[rtb_MatrixMultiply1_p_tmp] = localDW->UnitDelay_DSTATE[6 * i +
            rtb_MatrixMultiply1_p_tmp_0] * rtb_P_cholmerge[6 *
            rtb_MatrixMultiply1_p_tmp_0 + idxStart] + rtb_Phi[6 * idxStart + i];
        }

        tmp[idxStart + 12 * i] = rtConstP.Constant_Value[6 * idxStart + i];
        tmp[idxStart + 12 * (i + 6)] = 0.0;
      }
    }

    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        tmp[(idxStart + 12 * i) + 6] = rtb_Phi[6 * i + idxStart];
        tmp[(idxStart + 12 * (i + 6)) + 6] = localDW->UnitDelay_DSTATE[6 *
          idxStart + i];
      }
    }

    qr(tmp, unusedU2, R);
    for (i = 0; i < 6; i++) {
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MatrixMultiply1_p_tmp = idxStart + 6 * i;
        rtb_Phi[rtb_MatrixMultiply1_p_tmp] = R[(6 + idxStart) * 12 + i];
        rtb_P_cholmerge[rtb_MatrixMultiply1_p_tmp] = R[12 * idxStart + i];
      }
    }

    mrdivide_helper(rtb_Phi, rtb_P_cholmerge);
    if (!rtu_gryo_meas_valid) {
      for (i = 0; i < 6; i++) {
        rtb_Phi[3 + 6 * i] = 0.0;
        rtb_Phi[4 + 6 * i] = 0.0;
        rtb_Phi[5 + 6 * i] = 0.0;
      }
    }

    /* SignalConversion: '<S24>/ConcatBufferAtVector ConcatenateIn10' */
    rtb_VectorConcatenate[9] = localDW->Merge1[2];

    /* SignalConversion: '<S24>/ConcatBufferAtVector ConcatenateIn12' */
    rtb_VectorConcatenate[11] = localDW->Merge1[0];

    /* SignalConversion: '<S24>/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = localDW->Merge1[0];

    /* SignalConversion: '<S24>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = localDW->Merge1[3];

    /* SignalConversion: '<S24>/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = localDW->Merge1[0];

    /* SignalConversion: '<S24>/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = localDW->Merge1[1];

    /* Gain: '<S24>/Gain' */
    rtb_VectorConcatenate[0] = -localDW->Merge1[1];

    /* Gain: '<S24>/Gain1' */
    rtb_VectorConcatenate[3] = -localDW->Merge1[2];

    /* Gain: '<S24>/Gain2' */
    rtb_VectorConcatenate[4] = -localDW->Merge1[2];

    /* Gain: '<S24>/Gain3' */
    rtb_VectorConcatenate[5] = -localDW->Merge1[3];

    /* Gain: '<S24>/Gain4' */
    rtb_VectorConcatenate[8] = -localDW->Merge1[3];

    /* Gain: '<S24>/Gain5' */
    rtb_VectorConcatenate[10] = -localDW->Merge1[1];

    /* Sum: '<S16>/Create Measurement Residual' incorporates:
     *  RateTransition: '<S3>/sunsensor_body_rad_rt1'
     */
    rtb_ExtractDiagonal[0] = rtb_M_l_idx_0;
    rtb_ExtractDiagonal[1] = rtb_Sum_fk;
    rtb_ExtractDiagonal[2] = rtb_Product5_k;
    rtb_ExtractDiagonal[3] = rtb_Product3_h;
    rtb_ExtractDiagonal[4] = rtb_Sum_k1;
    rtb_ExtractDiagonal[5] = rtb_Product1_d5;
    rtu_sun_meas_body_unit_0[0] = rtu_sun_meas_body_unit[0];
    rtu_sun_meas_body_unit_0[3] = rtu_mag_meas_body_T[0];
    rtu_sun_meas_body_unit_0[1] = rtu_sun_meas_body_unit[1];
    rtu_sun_meas_body_unit_0[4] = rtu_mag_meas_body_T[1];
    rtu_sun_meas_body_unit_0[2] = rtu_sun_meas_body_unit[2];
    rtu_sun_meas_body_unit_0[5] = rtu_mag_meas_body_T[2];
    for (i = 0; i < 6; i++) {
      /* SignalConversion: '<S16>/OutportBufferForP_chol_plus' incorporates:
       *  MATLAB Function: '<S16>/QR Factorization'
       */
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_P_cholmerge[idxStart + 6 * i] = R[((6 + idxStart) * 12 + i) + 6];
      }

      /* Sum: '<S16>/Create Measurement Residual' */
      rtu_sun_meas_body_unit_1[i] = rtu_sun_meas_body_unit_0[i] -
        rtb_ExtractDiagonal[i];
    }

    /* Product: '<S16>/Product1' incorporates:
     *  MATLAB Function: '<S16>/QR Factorization'
     */
    for (i = 0; i < 6; i++) {
      rtb_MathFunction1_oz[i] = 0.0;
      for (idxStart = 0; idxStart < 6; idxStart++) {
        rtb_MathFunction1_oz[i] += rtb_Phi[6 * idxStart + i] *
          rtu_sun_meas_body_unit_1[idxStart];
      }
    }

    /* End of Product: '<S16>/Product1' */

    /* Sum: '<S16>/Updating Beta Bias ' incorporates:
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rty_Bias_radps[0] = rtb_MathFunction1_oz[3] + localDW->UnitDelay1_DSTATE[0];
    rty_Bias_radps[1] = rtb_MathFunction1_oz[4] + localDW->UnitDelay1_DSTATE[1];
    rty_Bias_radps[2] = rtb_MathFunction1_oz[5] + localDW->UnitDelay1_DSTATE[2];

    /* Sum: '<S16>/Sum' incorporates:
     *  Gain: '<S24>/Gain6'
     *  Product: '<S16>/Product'
     */
    for (i = 0; i < 4; i++) {
      rtb_Merge_d[i] = ((rtb_VectorConcatenate[i + 4] * 0.5 *
                         rtb_MathFunction1_oz[1] + 0.5 * rtb_VectorConcatenate[i]
                         * rtb_MathFunction1_oz[0]) + rtb_VectorConcatenate[i +
                        8] * 0.5 * rtb_MathFunction1_oz[2]) + localDW->Merge1[i];
    }

    /* End of Sum: '<S16>/Sum' */

    /* Sqrt: '<S31>/sqrt' incorporates:
     *  Product: '<S32>/Product'
     *  Product: '<S32>/Product1'
     *  Product: '<S32>/Product2'
     *  Product: '<S32>/Product3'
     *  Sum: '<S32>/Sum'
     */
    rtb_M_l_idx_2 = sqrt(((rtb_Merge_d[0] * rtb_Merge_d[0] + rtb_Merge_d[1] *
      rtb_Merge_d[1]) + rtb_Merge_d[2] * rtb_Merge_d[2]) + rtb_Merge_d[3] *
                         rtb_Merge_d[3]);

    /* Product: '<S26>/Product' */
    rty_sc_quat[0] = rtb_Merge_d[0] / rtb_M_l_idx_2;

    /* Product: '<S26>/Product1' */
    rty_sc_quat[1] = rtb_Merge_d[1] / rtb_M_l_idx_2;

    /* Product: '<S26>/Product2' */
    rty_sc_quat[2] = rtb_Merge_d[2] / rtb_M_l_idx_2;

    /* Product: '<S26>/Product3' */
    rty_sc_quat[3] = rtb_Merge_d[3] / rtb_M_l_idx_2;

    /* End of Outputs for SubSystem: '<S3>/Measurement Update' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/Bypass Meas. Update' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    rty_sc_quat[0] = localDW->Merge1[0];
    rty_sc_quat[1] = localDW->Merge1[1];
    rty_sc_quat[2] = localDW->Merge1[2];
    rty_sc_quat[3] = localDW->Merge1[3];
    memcpy(&rtb_P_cholmerge[0], &localDW->UnitDelay_DSTATE[0], 36U * sizeof
           (real_T));
    rty_Bias_radps[0] = localDW->UnitDelay1_DSTATE[0];
    rty_Bias_radps[1] = localDW->UnitDelay1_DSTATE[1];
    rty_Bias_radps[2] = localDW->UnitDelay1_DSTATE[2];

    /* End of Outputs for SubSystem: '<S3>/Bypass Meas. Update' */
  }

  /* End of If: '<S3>/If' */

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Sum_fk = rtu_gyro_meas_body_radps[0];
  } else {
    rtb_Sum_fk = 0.0;
  }

  /* Sum: '<S18>/Sum' */
  rty_sc_body_rates[0] = rtb_Sum_fk - rty_Bias_radps[0];

  /* Product: '<S18>/Matrix Multiply' incorporates:
   *  Math: '<S18>/Transpose'
   */
  rtb_M_l_idx_0 = rty_sc_body_rates[0] * rty_sc_body_rates[0];

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Sum_fk = rtu_gyro_meas_body_radps[1];
  } else {
    rtb_Sum_fk = 0.0;
  }

  /* Sum: '<S18>/Sum' */
  rty_sc_body_rates[1] = rtb_Sum_fk - rty_Bias_radps[1];

  /* Product: '<S18>/Matrix Multiply' incorporates:
   *  Math: '<S18>/Transpose'
   */
  rtb_M_l_idx_0 += rty_sc_body_rates[1] * rty_sc_body_rates[1];

  /* Switch: '<S3>/Switches to zero omega  if Gyro is offline ' */
  if (rtu_gryo_meas_valid) {
    rtb_Sum_fk = rtu_gyro_meas_body_radps[2];
  } else {
    rtb_Sum_fk = 0.0;
  }

  /* Sum: '<S18>/Sum' */
  rty_sc_body_rates[2] = rtb_Sum_fk - rty_Bias_radps[2];

  /* Product: '<S18>/Matrix Multiply' incorporates:
   *  Math: '<S18>/Transpose'
   */
  rtb_M_l_idx_0 += rty_sc_body_rates[2] * rty_sc_body_rates[2];

  /* Sqrt: '<S18>/Sqrt' incorporates:
   *  Product: '<S18>/Matrix Multiply'
   */
  rtb_M_l_idx_0 = sqrt(rtb_M_l_idx_0);

  /* Outputs for Atomic SubSystem: '<S18>/CrossProdMatrix_lib1' */
  CrossProdMatrix_lib_d(rty_sc_body_rates, rtb_MatrixConcatenate3);

  /* End of Outputs for SubSystem: '<S18>/CrossProdMatrix_lib1' */

  /* MATLAB Function: '<S18>/Create State Transition  Matrix' incorporates:
   *  Constant: '<S18>/Constant'
   */
  if (rtb_M_l_idx_0 < 1.0E-10) {
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
      Phi_22[i] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    for (idxStart = 0; idxStart < 3; idxStart++) {
      Phi_22[idxStart + 3 * idxStart] = 1;
      rtb_Phi[6 * idxStart] = b_I[3 * idxStart];
      rtb_MatrixMultiply1_p_tmp = 6 * (idxStart + 3);
      rtb_Phi[rtb_MatrixMultiply1_p_tmp] = (real_T)a[3 * idxStart] * 0.1;
      rtb_Phi[3 + 6 * idxStart] = 0.0;
      i = 3 * idxStart + 1;
      rtb_Phi[1 + 6 * idxStart] = b_I[i];
      rtb_Phi[1 + rtb_MatrixMultiply1_p_tmp] = (real_T)a[i] * 0.1;
      rtb_Phi[4 + 6 * idxStart] = 0.0;
      i = 3 * idxStart + 2;
      rtb_Phi[2 + 6 * idxStart] = b_I[i];
      rtb_Phi[2 + rtb_MatrixMultiply1_p_tmp] = (real_T)a[i] * 0.1;
      rtb_Phi[5 + 6 * idxStart] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_MatrixMultiply1_p_tmp = 6 * (i + 3);
      rtb_Phi[3 + rtb_MatrixMultiply1_p_tmp] = Phi_22[3 * i];
      rtb_Phi[4 + rtb_MatrixMultiply1_p_tmp] = Phi_22[3 * i + 1];
      rtb_Phi[5 + rtb_MatrixMultiply1_p_tmp] = Phi_22[3 * i + 2];
    }
  } else {
    for (i = 0; i < 9; i++) {
      b_I[i] = 0;
      Phi_22[i] = 0;
    }

    b_I[0] = 1;
    b_I[4] = 1;
    b_I[8] = 1;
    rtb_Product3_h = sin(rtb_M_l_idx_0 * 0.1);
    rtb_Sum_fk = rtb_Product3_h / rtb_M_l_idx_0;
    rtb_M_l_idx_1 = cos(rtb_M_l_idx_0 * 0.1);
    rtb_Product5_k = rtb_M_l_idx_0 * rtb_M_l_idx_0;
    rtb_Sum_k1 = rtb_M_l_idx_0 * 0.1 - rtb_Product3_h;
    rtb_M_l_idx_2 = rt_powd_snf(rtb_M_l_idx_0, 3.0);
    for (idxStart = 0; idxStart < 3; idxStart++) {
      Phi_22[idxStart + 3 * idxStart] = 1;
      for (i = 0; i < 3; i++) {
        rtb_MatrixMultiply1_p_tmp_0 = idxStart + 3 * i;
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0] = 0.0;
        rtb_MatrixMultiply1_p_tmp = 3 * i + idxStart;
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0] =
          rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp] +
          rtb_MatrixConcatenate3[3 * i] * rtb_MatrixConcatenate3[idxStart];
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0] =
          rtb_MatrixConcatenate3[3 * i + 1] * rtb_MatrixConcatenate3[idxStart +
          3] + rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp];
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0] =
          rtb_MatrixConcatenate3[3 * i + 2] * rtb_MatrixConcatenate3[idxStart +
          6] + rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_Product3_h = rtb_MathFunction1_oz[3 * i];
      rtb_Product1_d5 = rtb_MatrixConcatenate3[3 * i];
      rtb_Phi[6 * i] = (1.0 - rtb_M_l_idx_1) * rtb_Product3_h / rtb_Product5_k +
        ((real_T)b_I[3 * i] - rtb_Product1_d5 * rtb_Sum_fk);
      rtb_MatrixMultiply1_p_tmp = 6 * (i + 3);
      rtb_Phi[rtb_MatrixMultiply1_p_tmp] = ((1.0 - rtb_M_l_idx_1) *
        rtb_Product1_d5 / rtb_Product5_k - (real_T)b_a[3 * i] * 0.1) -
        rtb_Product3_h * rtb_Sum_k1 / rtb_M_l_idx_2;
      rtb_Phi[3 + 6 * i] = 0.0;
      rtb_Phi[3 + rtb_MatrixMultiply1_p_tmp] = Phi_22[3 * i];
      rtb_MatrixMultiply1_p_tmp_0 = 3 * i + 1;
      rtb_Phi[1 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_p_tmp_0] -
                            rtb_MatrixConcatenate3[rtb_MatrixMultiply1_p_tmp_0] *
                            rtb_Sum_fk) + (1.0 - rtb_M_l_idx_1) *
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0] / rtb_Product5_k;
      rtb_Phi[1 + rtb_MatrixMultiply1_p_tmp] = ((1.0 - rtb_M_l_idx_1) *
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_p_tmp_0] / rtb_Product5_k -
        (real_T)b_a[rtb_MatrixMultiply1_p_tmp_0] * 0.1) -
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0] * rtb_Sum_k1 /
        rtb_M_l_idx_2;
      rtb_Phi[4 + 6 * i] = 0.0;
      rtb_Phi[4 + rtb_MatrixMultiply1_p_tmp] =
        Phi_22[rtb_MatrixMultiply1_p_tmp_0];
      rtb_MatrixMultiply1_p_tmp_0 = 3 * i + 2;
      rtb_Phi[2 + 6 * i] = ((real_T)b_I[rtb_MatrixMultiply1_p_tmp_0] -
                            rtb_MatrixConcatenate3[rtb_MatrixMultiply1_p_tmp_0] *
                            rtb_Sum_fk) + (1.0 - rtb_M_l_idx_1) *
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0] / rtb_Product5_k;
      rtb_Phi[2 + rtb_MatrixMultiply1_p_tmp] = ((1.0 - rtb_M_l_idx_1) *
        rtb_MatrixConcatenate3[rtb_MatrixMultiply1_p_tmp_0] / rtb_Product5_k -
        (real_T)b_a[rtb_MatrixMultiply1_p_tmp_0] * 0.1) -
        rtb_MathFunction1_oz[rtb_MatrixMultiply1_p_tmp_0] * rtb_Sum_k1 /
        rtb_M_l_idx_2;
      rtb_Phi[5 + 6 * i] = 0.0;
      rtb_Phi[5 + rtb_MatrixMultiply1_p_tmp] =
        Phi_22[rtb_MatrixMultiply1_p_tmp_0];
    }
  }

  /* End of MATLAB Function: '<S18>/Create State Transition  Matrix' */

  /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
   *  Constant: '<S18>/Constant13'
   */
  for (i = 0; i < 6; i++) {
    for (idxStart = 0; idxStart < 6; idxStart++) {
      rtb_MatrixMultiply1_p_tmp_0 = i + 6 * idxStart;
      rtb_P_cholmerge_0[rtb_MatrixMultiply1_p_tmp_0] = 0.0;
      for (rtb_MatrixMultiply1_p_tmp = 0; rtb_MatrixMultiply1_p_tmp < 6;
           rtb_MatrixMultiply1_p_tmp++) {
        rtb_P_cholmerge_0[rtb_MatrixMultiply1_p_tmp_0] = rtb_P_cholmerge[6 * i +
          rtb_MatrixMultiply1_p_tmp] * rtb_Phi[6 * rtb_MatrixMultiply1_p_tmp +
          idxStart] + rtb_P_cholmerge_0[6 * idxStart + i];
      }
    }
  }

  for (idxStart = 0; idxStart < 6; idxStart++) {
    for (i = 0; i < 6; i++) {
      rtb_MatrixMultiply1_p_tmp = i + 12 * idxStart;
      C[rtb_MatrixMultiply1_p_tmp] = rtb_P_cholmerge_0[6 * idxStart + i];
      C[rtb_MatrixMultiply1_p_tmp + 6] = rtConstP.Constant13_Value[6 * i +
        idxStart];
    }

    for (i = 0; i < 12; i++) {
      unusedU2[i + 12 * idxStart] = C[12 * idxStart + i];
      unusedU2[i + 12 * (idxStart + 6)] = 0.0;
    }
  }

  xgeqrf(unusedU2, unusedExpr);
  for (idxStart = 0; idxStart < 6; idxStart++) {
    for (i = 0; i <= idxStart; i++) {
      C[i + 12 * idxStart] = unusedU2[12 * idxStart + i];
    }

    for (i = idxStart; i + 2 < 13; i++) {
      C[(i + 12 * idxStart) + 1] = 0.0;
    }
  }

  /* Trigonometry: '<S50>/Cos' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S50>/Constant'
   *  Product: '<S50>/Multiply'
   */
  rtb_Sum_fk = cos(0.05 * rtb_M_l_idx_0);

  /* SignalConversion: '<S50>/ConcatBufferAtMatrix ConcatenateIn1' */
  rtb_Merge_d[0] = rtb_Sum_fk;

  /* If: '<S49>/If' */
  if (rtb_M_l_idx_0 < 1.0E-10) {
    /* Outputs for IfAction SubSystem: '<S49>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    /* SignalConversion: '<S53>/OutportBufferForPsi_zero' incorporates:
     *  Constant: '<S53>/Constant'
     *  Constant: '<S53>/Constant1'
     *  Constant: '<S53>/Constant2'
     */
    rtb_M[0] = 0.0;
    rtb_M[1] = 0.0;
    rtb_M[2] = 0.0;

    /* End of Outputs for SubSystem: '<S49>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S49>/If Action Subsystem' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* Trigonometry: '<S52>/Sin' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S52>/Constant'
     *  Product: '<S52>/Divide'
     */
    rtb_Product1_d5 = sin(0.05 * rtb_M_l_idx_0);

    /* Product: '<S52>/Divide1' */
    rtb_M[0] = rtb_Product1_d5 * rty_sc_body_rates[0] / rtb_M_l_idx_0;
    rtb_M[1] = rtb_Product1_d5 * rty_sc_body_rates[1] / rtb_M_l_idx_0;
    rtb_M[2] = rtb_Product1_d5 * rty_sc_body_rates[2] / rtb_M_l_idx_0;

    /* End of Outputs for SubSystem: '<S49>/If Action Subsystem' */
  }

  /* End of If: '<S49>/If' */

  /* Math: '<S50>/Transpose2' incorporates:
   *  Gain: '<S50>/Gain'
   */
  rtb_Merge_d[1] = -rtb_M[0];
  rtb_Merge_d[2] = -rtb_M[1];
  rtb_Merge_d[3] = -rtb_M[2];

  /* Outputs for Atomic SubSystem: '<S18>/CrossProdMatrix_lib' */
  CrossProdMatrix_lib_d(rtb_M, &rtb_MatrixConcatenate2_l[0]);

  /* End of Outputs for SubSystem: '<S18>/CrossProdMatrix_lib' */

  /* RateTransition: '<S50>/Rate Transition' */
  if (rtM->Timing.RateInteraction.TID1_2 == 1) {
    memcpy(&localDW->RateTransition[0], &localDW->RateTransition_Buffer0[0], 9U *
           sizeof(real_T));
  }

  /* End of RateTransition: '<S50>/Rate Transition' */

  /* Sum: '<S50>/Add1' incorporates:
   *  Product: '<S50>/Matrix Multiply2'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i + 3] = rtb_Sum_fk * localDW->RateTransition[i] -
      rtb_MatrixConcatenate2_l[i];
  }

  /* End of Sum: '<S50>/Add1' */

  /* SignalConversion: '<S50>/ConcatBufferAtMatrix Concatenate1In1' */
  rtb_VectorConcatenate[0] = rtb_M[0];
  rtb_VectorConcatenate[1] = rtb_M[1];
  rtb_VectorConcatenate[2] = rtb_M[2];

  /* Concatenate: '<S50>/Matrix Concatenate2' */
  for (i = 0; i < 4; i++) {
    idxStart = i << 2;
    rtb_MatrixConcatenate2_l[idxStart] = rtb_Merge_d[i];
    rtb_MatrixConcatenate2_l[1 + idxStart] = rtb_VectorConcatenate[3 * i];
    rtb_MatrixConcatenate2_l[2 + idxStart] = rtb_VectorConcatenate[3 * i + 1];
    rtb_MatrixConcatenate2_l[3 + idxStart] = rtb_VectorConcatenate[3 * i + 2];
  }

  /* End of Concatenate: '<S50>/Matrix Concatenate2' */

  /* S-Function (sdspdiag2): '<S17>/Extract Diagonal' */
  for (i = 0; i < 6; i++) {
    rtb_ExtractDiagonal[i] = rtb_P_cholmerge[i * 7];
  }

  /* End of S-Function (sdspdiag2): '<S17>/Extract Diagonal' */

  /* Product: '<S18>/Product' */
  for (i = 0; i < 4; i++) {
    rtb_Sum_fk = rtb_MatrixConcatenate2_l[i + 12] * rty_sc_quat[3] +
      (rtb_MatrixConcatenate2_l[i + 8] * rty_sc_quat[2] +
       (rtb_MatrixConcatenate2_l[i + 4] * rty_sc_quat[1] +
        rtb_MatrixConcatenate2_l[i] * rty_sc_quat[0]));
    rtb_Merge_d[i] = rtb_Sum_fk;
  }

  /* End of Product: '<S18>/Product' */

  /* Gain: '<S17>/Multiply' incorporates:
   *  Abs: '<S17>/Abs'
   */
  rty_uSig_deg[0] = 171.88733853924697 * fabs(rtb_ExtractDiagonal[0]);
  rty_uSig_deg[1] = 171.88733853924697 * fabs(rtb_ExtractDiagonal[1]);
  rty_uSig_deg[2] = 171.88733853924697 * fabs(rtb_ExtractDiagonal[2]);

  /* Sqrt: '<S54>/sqrt' incorporates:
   *  Product: '<S55>/Product'
   *  Product: '<S55>/Product1'
   *  Product: '<S55>/Product2'
   *  Product: '<S55>/Product3'
   *  Sum: '<S55>/Sum'
   */
  rtb_Sum_fk = sqrt(((rtb_Merge_d[0] * rtb_Merge_d[0] + rtb_Merge_d[1] *
                      rtb_Merge_d[1]) + rtb_Merge_d[2] * rtb_Merge_d[2]) +
                    rtb_Merge_d[3] * rtb_Merge_d[3]);

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  MATLAB Function: '<S18>/MATLAB Function'
   */
  for (i = 0; i < 6; i++) {
    for (idxStart = 0; idxStart < 6; idxStart++) {
      localDW->UnitDelay_DSTATE[idxStart + 6 * i] = C[12 * idxStart + i];
    }
  }

  /* End of Update for UnitDelay: '<S3>/Unit Delay' */

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE[0] = rty_Bias_radps[0];
  localDW->UnitDelay1_DSTATE[1] = rty_Bias_radps[1];
  localDW->UnitDelay1_DSTATE[2] = rty_Bias_radps[2];

  /* Update for UnitDelay: '<S15>/Unit Delay2' incorporates:
   *  Product: '<S51>/Product'
   *  Product: '<S51>/Product1'
   *  Product: '<S51>/Product2'
   *  Product: '<S51>/Product3'
   */
  localDW->UnitDelay2_DSTATE[0] = rtb_Merge_d[0] / rtb_Sum_fk;
  localDW->UnitDelay2_DSTATE[1] = rtb_Merge_d[1] / rtb_Sum_fk;
  localDW->UnitDelay2_DSTATE[2] = rtb_Merge_d[2] / rtb_Sum_fk;
  localDW->UnitDelay2_DSTATE[3] = rtb_Merge_d[3] / rtb_Sum_fk;
}

/* Output and update for atomic system: '<S1>/MEKF_lib' */
void MEKF_libTID2(DW_MEKF_lib *localDW)
{
  /* Update for RateTransition: '<S50>/Rate Transition' */
  memcpy(&localDW->RateTransition_Buffer0[0], &localDW->IdentityMatrix[0], 9U *
         sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

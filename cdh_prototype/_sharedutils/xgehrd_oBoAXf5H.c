/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xgehrd_oBoAXf5H.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd_snf.h"
#include "xnrm2_KoFIUVBo.h"
#include "xzlarf_Ddk2Tem0.h"
#include "xgehrd_oBoAXf5H.h"

/* Function for MATLAB Function: '<S386>/INITIALIZE' */
void xgehrd_oBoAXf5H(real_T a[16], real_T tau[3])
{
  real_T work[4];
  real_T alpha1;
  real_T xnorm;
  int32_T b_ia;
  int32_T b_ix;
  int32_T exitg1;
  int32_T g;
  int32_T ia;
  int32_T ia0;
  int32_T iy;
  int32_T jy;
  int32_T knt;
  int32_T rowleft;
  boolean_T exitg2;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  work[3] = 0.0;
  ia0 = 3;
  alpha1 = a[1];
  tau[0] = 0.0;
  xnorm = xnrm2_KoFIUVBo(2, a, 3);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(a[1], xnorm);
    if (a[1] >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (rowleft = 3; rowleft < 5; rowleft++) {
          a[rowleft - 1] *= 9.9792015476736E+291;
        }

        xnorm *= 9.9792015476736E+291;
        alpha1 *= 9.9792015476736E+291;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = rt_hypotd_snf(alpha1, xnrm2_KoFIUVBo(2, a, 3));
      if (alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      tau[0] = (xnorm - alpha1) / xnorm;
      alpha1 = 1.0 / (alpha1 - xnorm);
      while (ia0 <= 4) {
        a[ia0 - 1] *= alpha1;
        ia0++;
      }

      for (ia0 = 0; ia0 <= knt; ia0++) {
        xnorm *= 1.0020841800044864E-292;
      }

      alpha1 = xnorm;
    } else {
      tau[0] = (xnorm - a[1]) / xnorm;
      alpha1 = 1.0 / (a[1] - xnorm);
      while (ia0 <= 4) {
        a[ia0 - 1] *= alpha1;
        ia0++;
      }

      alpha1 = xnorm;
    }
  }

  a[1] = 1.0;
  jy = 1;
  if (tau[0] != 0.0) {
    knt = 2;
    ia0 = 3;
    while ((knt + 1 > 0) && (a[ia0] == 0.0)) {
      knt--;
      ia0--;
    }

    ia0 = 4;
    exitg2 = false;
    while ((!exitg2) && (ia0 > 0)) {
      b_ia = ia0 + 4;
      do {
        exitg1 = 0;
        if (b_ia <= (ia0 + (knt << 2)) + 4) {
          if (a[b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            b_ia += 4;
          }
        } else {
          ia0--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = -1;
    ia0 = 0;
  }

  if (knt + 1 > 0) {
    if (ia0 != 0) {
      for (rowleft = 0; rowleft < ia0; rowleft++) {
        work[rowleft] = 0.0;
      }

      rowleft = 1;
      b_ia = (knt << 2) + 5;
      for (b_ix = 5; b_ix <= b_ia; b_ix += 4) {
        iy = 0;
        g = (b_ix + ia0) - 1;
        for (ia = b_ix; ia <= g; ia++) {
          work[iy] += a[ia - 1] * a[rowleft];
          iy++;
        }

        rowleft++;
      }
    }

    if (!(-tau[0] == 0.0)) {
      rowleft = 4;
      for (b_ia = 0; b_ia <= knt; b_ia++) {
        if (a[jy] != 0.0) {
          xnorm = a[jy] * -tau[0];
          b_ix = 0;
          iy = ia0 + rowleft;
          for (g = rowleft; g < iy; g++) {
            a[g] += work[b_ix] * xnorm;
            b_ix++;
          }
        }

        jy++;
        rowleft += 4;
      }
    }
  }

  xzlarf_Ddk2Tem0(3, 3, 2, tau[0], a, 6, work);
  a[1] = alpha1;
  alpha1 = a[6];
  tau[1] = 0.0;
  xnorm = xnrm2_KoFIUVBo(1, a, 8);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(a[6], xnorm);
    if (a[6] >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        a[7] *= 9.9792015476736E+291;
        xnorm *= 9.9792015476736E+291;
        alpha1 *= 9.9792015476736E+291;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = rt_hypotd_snf(alpha1, xnrm2_KoFIUVBo(1, a, 8));
      if (alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      tau[1] = (xnorm - alpha1) / xnorm;
      alpha1 = 1.0 / (alpha1 - xnorm);
      a[7] *= alpha1;
      for (ia0 = 0; ia0 <= knt; ia0++) {
        xnorm *= 1.0020841800044864E-292;
      }

      alpha1 = xnorm;
    } else {
      tau[1] = (xnorm - a[6]) / xnorm;
      a[7] *= 1.0 / (a[6] - xnorm);
      alpha1 = xnorm;
    }
  }

  a[6] = 1.0;
  jy = 6;
  if (tau[1] != 0.0) {
    knt = 1;
    ia0 = 7;
    while ((knt + 1 > 0) && (a[ia0] == 0.0)) {
      knt--;
      ia0--;
    }

    ia0 = 4;
    exitg2 = false;
    while ((!exitg2) && (ia0 > 0)) {
      b_ia = ia0 + 8;
      do {
        exitg1 = 0;
        if (b_ia <= (ia0 + (knt << 2)) + 8) {
          if (a[b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            b_ia += 4;
          }
        } else {
          ia0--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = -1;
    ia0 = 0;
  }

  if (knt + 1 > 0) {
    if (ia0 != 0) {
      for (rowleft = 0; rowleft < ia0; rowleft++) {
        work[rowleft] = 0.0;
      }

      rowleft = 6;
      b_ia = (knt << 2) + 9;
      for (b_ix = 9; b_ix <= b_ia; b_ix += 4) {
        iy = 0;
        g = (b_ix + ia0) - 1;
        for (ia = b_ix; ia <= g; ia++) {
          work[iy] += a[ia - 1] * a[rowleft];
          iy++;
        }

        rowleft++;
      }
    }

    if (!(-tau[1] == 0.0)) {
      rowleft = 8;
      for (b_ia = 0; b_ia <= knt; b_ia++) {
        if (a[jy] != 0.0) {
          xnorm = a[jy] * -tau[1];
          b_ix = 0;
          iy = ia0 + rowleft;
          for (g = rowleft; g < iy; g++) {
            a[g] += work[b_ix] * xnorm;
            b_ix++;
          }
        }

        jy++;
        rowleft += 4;
      }
    }
  }

  xzlarf_Ddk2Tem0(2, 2, 7, tau[1], a, 11, work);
  a[6] = alpha1;
  alpha1 = a[11];
  tau[2] = 0.0;
  xnorm = xnrm2_KoFIUVBo(0, a, 12);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(a[11], xnorm);
    if (a[11] >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        xnorm *= 9.9792015476736E+291;
        alpha1 *= 9.9792015476736E+291;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = rt_hypotd_snf(alpha1, xnrm2_KoFIUVBo(0, a, 12));
      if (alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      tau[2] = (xnorm - alpha1) / xnorm;
      for (ia0 = 0; ia0 <= knt; ia0++) {
        xnorm *= 1.0020841800044864E-292;
      }

      alpha1 = xnorm;
    } else {
      tau[2] = (xnorm - a[11]) / xnorm;
      alpha1 = xnorm;
    }
  }

  a[11] = 1.0;
  jy = 11;
  if (tau[2] != 0.0) {
    knt = 0;
    ia0 = 11;
    while ((knt + 1 > 0) && (a[ia0] == 0.0)) {
      knt--;
      ia0--;
    }

    ia0 = 4;
    exitg2 = false;
    while ((!exitg2) && (ia0 > 0)) {
      b_ia = ia0 + 12;
      do {
        exitg1 = 0;
        if (b_ia <= (ia0 + (knt << 2)) + 12) {
          if (a[b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            b_ia += 4;
          }
        } else {
          ia0--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = -1;
    ia0 = 0;
  }

  if (knt + 1 > 0) {
    if (ia0 != 0) {
      for (rowleft = 0; rowleft < ia0; rowleft++) {
        work[rowleft] = 0.0;
      }

      rowleft = 11;
      b_ia = (knt << 2) + 13;
      for (b_ix = 13; b_ix <= b_ia; b_ix += 4) {
        iy = 0;
        g = (b_ix + ia0) - 1;
        for (ia = b_ix; ia <= g; ia++) {
          work[iy] += a[ia - 1] * a[rowleft];
          iy++;
        }

        rowleft++;
      }
    }

    if (!(-tau[2] == 0.0)) {
      rowleft = 12;
      for (b_ia = 0; b_ia <= knt; b_ia++) {
        if (a[jy] != 0.0) {
          xnorm = a[jy] * -tau[2];
          b_ix = 0;
          iy = ia0 + rowleft;
          for (g = rowleft; g < iy; g++) {
            a[g] += work[b_ix] * xnorm;
            b_ix++;
          }
        }

        jy++;
        rowleft += 4;
      }
    }
  }

  xzlarf_Ddk2Tem0(1, 1, 12, tau[2], a, 16, work);
  a[11] = alpha1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

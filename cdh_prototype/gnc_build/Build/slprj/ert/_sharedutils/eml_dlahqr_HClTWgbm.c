/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: eml_dlahqr_HClTWgbm.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "xdlanv2_FIBA3SmX.h"
#include "xrot_6iHri7if.h"
#include "xrot_DROkKeLU.h"
#include "xrot_JzPltzlP.h"
#include "xzlarfg_J3AXVwxO.h"
#include "eml_dlahqr_HClTWgbm.h"

/* Function for MATLAB Function: '<S412>/INITIALIZE' */
int32_T eml_dlahqr_HClTWgbm(real_T h[16], real_T z[16])
{
  int32_T info;
  real_T v[3];
  int32_T i;
  int32_T L;
  boolean_T goto150;
  int32_T k;
  real_T tst;
  real_T htmp1;
  real_T ab;
  real_T ba;
  real_T aa;
  real_T h12;
  int32_T m;
  int32_T nr;
  int32_T hoffset;
  real_T cs;
  real_T sn;
  real_T b_v[3];
  int32_T its;
  int32_T j;
  int32_T tst_tmp;
  real_T tst_tmp_0;
  int32_T h12_tmp;
  real_T tst_tmp_tmp;
  int32_T h12_tmp_tmp;
  int32_T h12_tmp_tmp_0;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  info = 0;
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 0.0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[7] = 0.0;
  i = 3;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    L = 1;
    goto150 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L)) {
        hoffset = ((k - 1) << 2) + k;
        ba = fabs(h[hoffset]);
        if (ba <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          tst_tmp = (k << 2) + k;
          htmp1 = fabs(h[tst_tmp]);
          tst_tmp_0 = h[hoffset - 1];
          tst = fabs(tst_tmp_0) + htmp1;
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = fabs(h[(((k - 2) << 2) + k) - 1]);
            }

            if (k + 2 <= 4) {
              tst += fabs(h[tst_tmp + 1]);
            }
          }

          if (ba <= 2.2204460492503131E-16 * tst) {
            tst = fabs(h[tst_tmp - 1]);
            if (ba > tst) {
              ab = ba;
              ba = tst;
            } else {
              ab = tst;
            }

            tst = fabs(tst_tmp_0 - h[(k << 2) + k]);
            if (htmp1 > tst) {
              aa = htmp1;
              htmp1 = tst;
            } else {
              aa = tst;
            }

            tst = aa + ab;
            htmp1 = aa / tst * htmp1 * 2.2204460492503131E-16;
            if ((4.0083367200179456E-292 > htmp1) || rtIsNaN(htmp1)) {
              htmp1 = 4.0083367200179456E-292;
            }

            if (ab / tst * ba <= htmp1) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k + 1;
      if (k + 1 > 1) {
        h[k + ((k - 1) << 2)] = 0.0;
      }

      if (k + 1 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        switch (its) {
         case 10:
          tst = fabs(h[(((k + 1) << 2) + k) + 2]) + fabs(h[((k << 2) + k) + 1]);
          ba = h[(k << 2) + k] + 0.75 * tst;
          h12 = -0.4375 * tst;
          aa = tst;
          htmp1 = ba;
          break;

         case 20:
          tst = fabs(h[(((i - 2) << 2) + i) - 1]) + fabs(h[((i - 1) << 2) + i]);
          ba = h[(i << 2) + i] + 0.75 * tst;
          h12 = -0.4375 * tst;
          aa = tst;
          htmp1 = ba;
          break;

         default:
          m = ((i - 1) << 2) + i;
          ba = h[m - 1];
          aa = h[m];
          h12_tmp = (i << 2) + i;
          h12 = h[h12_tmp - 1];
          htmp1 = h[h12_tmp];
          break;
        }

        tst = ((fabs(ba) + fabs(h12)) + fabs(aa)) + fabs(htmp1);
        if (tst == 0.0) {
          ba = 0.0;
          htmp1 = 0.0;
          ab = 0.0;
          aa = 0.0;
        } else {
          ba /= tst;
          aa /= tst;
          h12 /= tst;
          htmp1 /= tst;
          ab = (ba + htmp1) / 2.0;
          ba = (ba - ab) * (htmp1 - ab) - h12 * aa;
          aa = sqrt(fabs(ba));
          if (ba >= 0.0) {
            ba = ab * tst;
            ab = ba;
            htmp1 = aa * tst;
            aa = -htmp1;
          } else {
            ba = ab + aa;
            ab -= aa;
            if (fabs(ba - htmp1) <= fabs(ab - htmp1)) {
              ba *= tst;
              ab = ba;
            } else {
              ab *= tst;
              ba = ab;
            }

            htmp1 = 0.0;
            aa = 0.0;
          }
        }

        m = i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          tst_tmp = ((m - 1) << 2) + m;
          tst_tmp_tmp = h[tst_tmp - 1];
          tst_tmp_0 = tst_tmp_tmp - ab;
          tst = (fabs(tst_tmp_0) + fabs(aa)) + fabs(h[tst_tmp]);
          h12 = h[((m - 1) << 2) + m] / tst;
          tst_tmp = (m << 2) + m;
          v[0] = (tst_tmp_0 / tst * (tst_tmp_tmp - ba) + h[tst_tmp - 1] * h12) -
            aa / tst * htmp1;
          v[1] = (((tst_tmp_tmp + h[tst_tmp]) - ba) - ab) * h12;
          v[2] = h[tst_tmp + 1] * h12;
          tst = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
          v[0] /= tst;
          v[1] /= tst;
          v[2] /= tst;
          if (k + 1 == m) {
            exitg3 = true;
          } else {
            hoffset = ((m - 2) << 2) + m;
            if (fabs(h[hoffset - 1]) * (fabs(v[1]) + fabs(v[2])) <= ((fabs
                  (h[hoffset - 2]) + fabs(tst_tmp_tmp)) + fabs(h[(m << 2) + m]))
                * (2.2204460492503131E-16 * fabs(v[0]))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
        }

        for (tst_tmp = m; tst_tmp <= i; tst_tmp++) {
          nr = (i - tst_tmp) + 2;
          if (3 < nr) {
            nr = 3;
          }

          if (tst_tmp > m) {
            h12_tmp = (((tst_tmp - 2) << 2) + tst_tmp) - 1;
            for (j = 0; j < nr; j++) {
              v[j] = h[j + h12_tmp];
            }
          }

          htmp1 = v[0];
          b_v[0] = v[0];
          b_v[1] = v[1];
          b_v[2] = v[2];
          tst = xzlarfg_J3AXVwxO(nr, &htmp1, b_v);
          v[1] = b_v[1];
          v[2] = b_v[2];
          v[0] = htmp1;
          if (tst_tmp > m) {
            h[(tst_tmp + ((tst_tmp - 2) << 2)) - 1] = htmp1;
            h[tst_tmp + ((tst_tmp - 2) << 2)] = 0.0;
            if (tst_tmp < i) {
              h[(tst_tmp + ((tst_tmp - 2) << 2)) + 1] = 0.0;
            }
          } else {
            if (m > k + 1) {
              h[(tst_tmp + ((tst_tmp - 2) << 2)) - 1] *= 1.0 - tst;
            }
          }

          htmp1 = b_v[1];
          ab = tst * b_v[1];
          switch (nr) {
           case 3:
            ba = b_v[2];
            aa = tst * b_v[2];
            for (nr = tst_tmp - 1; nr + 1 < 5; nr++) {
              hoffset = nr << 2;
              h12_tmp = hoffset + tst_tmp;
              j = h12_tmp - 1;
              h12_tmp_tmp = h12_tmp + 1;
              h12 = (h[j] + h[h12_tmp] * htmp1) + h[h12_tmp_tmp] * ba;
              hoffset += tst_tmp;
              h[hoffset - 1] = h[j] - h12 * tst;
              h[hoffset] = h[h12_tmp] - h12 * ab;
              h[hoffset + 1] = h[h12_tmp_tmp] - h12 * aa;
            }

            h12_tmp = tst_tmp + 3;
            nr = i + 1;
            if (h12_tmp < nr) {
              nr = h12_tmp;
            }

            for (hoffset = 0; hoffset < nr; hoffset++) {
              tst_tmp_0 = h[((tst_tmp - 1) << 2) + hoffset];
              h12_tmp = (tst_tmp << 2) + hoffset;
              j = ((tst_tmp + 1) << 2) + hoffset;
              h12 = (tst_tmp_0 + h[h12_tmp] * htmp1) + h[j] * ba;
              h[hoffset + ((tst_tmp - 1) << 2)] = tst_tmp_0 - h12 * tst;
              h[hoffset + (tst_tmp << 2)] = h[h12_tmp] - h12 * ab;
              h[hoffset + ((tst_tmp + 1) << 2)] = h[j] - h12 * aa;
            }

            for (nr = 0; nr < 4; nr++) {
              hoffset = (tst_tmp - 1) << 2;
              tst_tmp_0 = z[hoffset + nr];
              h12_tmp_tmp = tst_tmp << 2;
              h12_tmp = h12_tmp_tmp + nr;
              h12_tmp_tmp_0 = (tst_tmp + 1) << 2;
              j = h12_tmp_tmp_0 + nr;
              h12 = (tst_tmp_0 + z[h12_tmp] * htmp1) + z[j] * ba;
              z[nr + hoffset] = tst_tmp_0 - h12 * tst;
              z[nr + h12_tmp_tmp] = z[h12_tmp] - h12 * ab;
              z[nr + h12_tmp_tmp_0] = z[j] - h12 * aa;
            }
            break;

           case 2:
            for (nr = tst_tmp - 1; nr + 1 < 5; nr++) {
              hoffset = nr << 2;
              h12_tmp = hoffset + tst_tmp;
              j = h12_tmp - 1;
              h12 = h[j] + h[h12_tmp] * htmp1;
              hoffset += tst_tmp;
              h[hoffset - 1] = h[j] - h12 * tst;
              h[hoffset] = h[h12_tmp] - h12 * ab;
            }

            for (nr = 0; nr <= i; nr++) {
              h12 = h[((tst_tmp - 1) << 2) + nr] + h[(tst_tmp << 2) + nr] *
                htmp1;
              h[nr + ((tst_tmp - 1) << 2)] -= h12 * tst;
              h[nr + (tst_tmp << 2)] -= h12 * ab;
            }

            for (nr = 0; nr < 4; nr++) {
              h12_tmp = ((tst_tmp - 1) << 2) + nr;
              j = (tst_tmp << 2) + nr;
              h12 = z[h12_tmp] + z[j] * htmp1;
              z[nr + ((tst_tmp - 1) << 2)] = z[h12_tmp] - h12 * tst;
              z[nr + (tst_tmp << 2)] = z[j] - h12 * ab;
            }
            break;
          }
        }

        its++;
      }
    }

    if (!goto150) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((i + 1 != L) && (L == i)) {
        tst = h[(((i - 1) << 2) + i) - 1];
        htmp1 = h[((i << 2) + i) - 1];
        ab = h[((i - 1) << 2) + i];
        ba = h[(i << 2) + i];
        xdlanv2_FIBA3SmX(&tst, &htmp1, &ab, &ba, &aa, &h12, &tst_tmp_0,
                         &tst_tmp_tmp, &cs, &sn);
        hoffset = i + ((i - 1) << 2);
        h[hoffset - 1] = tst;
        its = i + (i << 2);
        h[its - 1] = htmp1;
        h[hoffset] = ab;
        h[its] = ba;
        if (4 > i + 1) {
          xrot_JzPltzlP(3 - i, h, i + ((i + 1) << 2), (i + ((i + 1) << 2)) + 1,
                        cs, sn);
        }

        xrot_DROkKeLU(i - 1, h, 1 + ((i - 1) << 2), 1 + (i << 2), cs, sn);
        xrot_6iHri7if(z, 1 + ((i - 1) << 2), 1 + (i << 2), cs, sn);
      }

      i = L - 2;
    }
  }

  return info;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

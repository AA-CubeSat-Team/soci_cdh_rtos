/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib.c
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

#include <gnc_build/FSW_Lib.h>
#include <gnc_build/FSW_Lib_private.h>

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void jseconds2ymdhms(real_T time_s_J2000, real_T *Year, real_T *Month,
  real_T *Day, real_T *Hour, real_T *Min, real_T *Sec, real_T *JC_J2000, real_T *
  JD);
static void factorial(real_T *n);
static real_T mod(real_T x);
static real_T norm(const real_T x[3]);
static void align_vecs(const real_T Body1[3], const real_T Inertial1[3], const
  real_T Body2[3], const real_T Inertial2[3], real_T C_cmd[9]);
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * Output and update for iterator system:
 *    '<S181>/While Iterator Subsystem'
 *    '<S237>/While Iterator Subsystem'
 *    '<S292>/While Iterator Subsystem'
 */
void WhileIteratorSubsystem(real_T rtu_rho, real_T rtu_z, real_T rtu_b, real_T
  rtu_uf, real_T rtu_e2, real_T rtu_ep2, real_T *rty_phi,
  DW_WhileIteratorSubsystem *localDW)
{
  int8_T s190_iter;
  real_T rtb_Switch_n;
  real_T rtb_Sum2_c;
  real_T rtb_sincos_o2_d;

  /* Outputs for Iterator SubSystem: '<S181>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S190>/While Iterator'
   */
  s190_iter = 1;

  /* End of Outputs for SubSystem: '<S181>/While Iterator Subsystem' */
  do {
    rtb_Switch_n = localDW->Memory_PreviousInput;
    if (s190_iter <= 0) {
      rtb_Switch_n = rt_atan2d_snf(rtu_z, rtu_uf * rtu_rho);
    }

    rtb_Sum2_c = sin(rtb_Switch_n);
    rtb_sincos_o2_d = cos(rtb_Switch_n);
    rtb_Sum2_c *= rtu_ep2 * rtu_b * rtb_Sum2_c * rtb_Sum2_c;
    rtb_Sum2_c += rtu_z;
    *rty_phi = rt_atan2d_snf(rtb_Sum2_c, rtu_rho - rtb_sincos_o2_d *
      rtb_sincos_o2_d * rtb_sincos_o2_d * rtu_e2 * 6.378137E+6);
    rtb_Sum2_c = rt_atan2d_snf(rtu_uf * sin(*rty_phi), cos(*rty_phi));
    localDW->Memory_PreviousInput = rtb_Sum2_c;
    s190_iter++;
  } while ((rtb_Switch_n != rtb_Sum2_c) && (s190_iter <= 5));
}

/* Function for MATLAB Function: '<S178>/MATLAB Function3' */
static void jseconds2ymdhms(real_T time_s_J2000, real_T *Year, real_T *Month,
  real_T *Day, real_T *Hour, real_T *Min, real_T *Sec, real_T *JC_J2000, real_T *
  JD)
{
  int8_T LMonth[12];
  real_T T_1900;
  real_T sum;
  static const int8_T b[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  int32_T i;
  for (i = 0; i < 12; i++) {
    LMonth[i] = b[i];
  }

  *JD = time_s_J2000 / 86400.0 + 2.451545E+6;
  *JC_J2000 = (*JD - 2.451545E+6) / 36525.0;
  sum = floor((*JD - 2.4150195E+6) / 365.25);
  *Year = 1900.0 + sum;
  T_1900 = (*JD - 2.4150195E+6) - (floor((((1900.0 + sum) - 1900.0) - 1.0) *
    0.25) + ((1900.0 + sum) - 1900.0) * 365.0);
  if (T_1900 < 1.0) {
    *Year = (1900.0 + sum) - 1.0;
    T_1900 = (*JD - 2.4150195E+6) - (floor(((((1900.0 + sum) - 1.0) - 1900.0) -
      1.0) * 0.25) + (((1900.0 + sum) - 1.0) - 1900.0) * 365.0);
  }

  if ((!rtIsInf(*Year)) && (!rtIsNaN(*Year))) {
    if (*Year == 0.0) {
      sum = 0.0;
    } else {
      sum = fmod(*Year, 4.0);
      if (sum == 0.0) {
        sum = 0.0;
      } else {
        if (*Year < 0.0) {
          sum += 4.0;
        }
      }
    }
  } else {
    sum = (rtNaN);
  }

  if (sum == 0.0) {
    LMonth[1] = 29;
  }

  *Day = floor(T_1900);
  sum = 0.0;
  *Month = 0.0;
  while (sum < *Day) {
    (*Month)++;
    sum += (real_T)LMonth[(int32_T)*Month - 1];
  }

  T_1900 = (T_1900 - *Day) * 24.0;
  *Hour = floor(T_1900);
  T_1900 -= *Hour;
  *Min = floor(T_1900 * 60.0);
  *Sec = (T_1900 - *Min / 60.0) * 3600.0;
}

/* Function for MATLAB Function: '<S294>/MATLAB Function' */
static void factorial(real_T *n)
{
  static const real_T b[170] = { 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0,
    40320.0, 362880.0, 3.6288E+6, 3.99168E+7, 4.790016E+8, 6.2270208E+9,
    8.71782912E+10, 1.307674368E+12, 2.0922789888E+13, 3.55687428096E+14,
    6.402373705728E+15, 1.21645100408832E+17, 2.43290200817664E+18,
    5.109094217170944E+19, 1.1240007277776077E+21, 2.5852016738884978E+22,
    6.2044840173323941E+23, 1.5511210043330986E+25, 4.0329146112660565E+26,
    1.0888869450418352E+28, 3.0488834461171384E+29, 8.8417619937397008E+30,
    2.6525285981219103E+32, 8.2228386541779224E+33, 2.6313083693369352E+35,
    8.6833176188118859E+36, 2.9523279903960412E+38, 1.0333147966386144E+40,
    3.7199332678990118E+41, 1.3763753091226343E+43, 5.23022617466601E+44,
    2.0397882081197442E+46, 8.1591528324789768E+47, 3.3452526613163803E+49,
    1.4050061177528798E+51, 6.0415263063373834E+52, 2.6582715747884485E+54,
    1.1962222086548019E+56, 5.5026221598120885E+57, 2.5862324151116818E+59,
    1.2413915592536073E+61, 6.0828186403426752E+62, 3.0414093201713376E+64,
    1.5511187532873822E+66, 8.0658175170943877E+67, 4.2748832840600255E+69,
    2.3084369733924138E+71, 1.2696403353658276E+73, 7.1099858780486348E+74,
    4.0526919504877221E+76, 2.3505613312828789E+78, 1.3868311854568986E+80,
    8.3209871127413916E+81, 5.0758021387722484E+83, 3.1469973260387939E+85,
    1.98260831540444E+87, 1.2688693218588417E+89, 8.2476505920824715E+90,
    5.4434493907744307E+92, 3.6471110918188683E+94, 2.4800355424368305E+96,
    1.711224524281413E+98, 1.197857166996989E+100, 8.5047858856786218E+101,
    6.1234458376886077E+103, 4.4701154615126834E+105, 3.3078854415193856E+107,
    2.4809140811395391E+109, 1.8854947016660498E+111, 1.4518309202828584E+113,
    1.1324281178206295E+115, 8.9461821307829729E+116, 7.1569457046263779E+118,
    5.7971260207473655E+120, 4.75364333701284E+122, 3.9455239697206569E+124,
    3.314240134565352E+126, 2.8171041143805494E+128, 2.4227095383672724E+130,
    2.1077572983795269E+132, 1.8548264225739836E+134, 1.6507955160908452E+136,
    1.4857159644817607E+138, 1.3520015276784023E+140, 1.24384140546413E+142,
    1.1567725070816409E+144, 1.0873661566567424E+146, 1.0329978488239052E+148,
    9.916779348709491E+149, 9.6192759682482062E+151, 9.426890448883242E+153,
    9.33262154439441E+155, 9.33262154439441E+157, 9.4259477598383536E+159,
    9.6144667150351211E+161, 9.9029007164861754E+163, 1.0299016745145622E+166,
    1.0813967582402903E+168, 1.1462805637347078E+170, 1.2265202031961373E+172,
    1.3246418194518284E+174, 1.4438595832024928E+176, 1.5882455415227421E+178,
    1.7629525510902437E+180, 1.9745068572210728E+182, 2.2311927486598123E+184,
    2.5435597334721862E+186, 2.9250936934930141E+188, 3.3931086844518965E+190,
    3.969937160808719E+192, 4.6845258497542883E+194, 5.5745857612076033E+196,
    6.6895029134491239E+198, 8.09429852527344E+200, 9.8750442008335976E+202,
    1.2146304367025325E+205, 1.5061417415111404E+207, 1.8826771768889254E+209,
    2.3721732428800459E+211, 3.0126600184576582E+213, 3.8562048236258025E+215,
    4.9745042224772855E+217, 6.4668554892204716E+219, 8.4715806908788174E+221,
    1.1182486511960039E+224, 1.4872707060906852E+226, 1.9929427461615181E+228,
    2.6904727073180495E+230, 3.6590428819525472E+232, 5.01288874827499E+234,
    6.9177864726194859E+236, 9.6157231969410859E+238, 1.346201247571752E+241,
    1.89814375907617E+243, 2.6953641378881614E+245, 3.8543707171800706E+247,
    5.5502938327393013E+249, 8.0479260574719866E+251, 1.17499720439091E+254,
    1.7272458904546376E+256, 2.5563239178728637E+258, 3.8089226376305671E+260,
    5.7133839564458505E+262, 8.6272097742332346E+264, 1.3113358856834518E+267,
    2.0063439050956811E+269, 3.0897696138473489E+271, 4.7891429014633912E+273,
    7.47106292628289E+275, 1.1729568794264138E+278, 1.8532718694937338E+280,
    2.9467022724950369E+282, 4.714723635992059E+284, 7.5907050539472148E+286,
    1.2296942187394488E+289, 2.0044015765453015E+291, 3.2872185855342945E+293,
    5.423910666131586E+295, 9.0036917057784329E+297, 1.5036165148649983E+300,
    2.5260757449731969E+302, 4.2690680090047027E+304, 7.257415615307994E+306 };

  if ((!(*n < 0.0)) && (!(floor(*n) != *n)) && ((!rtIsInf(*n)) && (!rtIsNaN(*n))))
  {
    if (*n > 170.0) {
      *n = (rtInf);
    } else if (*n < 1.0) {
      *n = 1.0;
    } else {
      *n = b[(int32_T)*n - 1];
    }
  }
}

/* Function for MATLAB Function: '<S177>/MATLAB Function' */
static real_T mod(real_T x)
{
  real_T r;
  boolean_T rEQ0;
  real_T q;
  if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = fmod(x, 6.2831853071795862);
      rEQ0 = (r == 0.0);
      if (!rEQ0) {
        q = fabs(x / 6.2831853071795862);
        rEQ0 = (fabs(q - floor(q + 0.5)) <= 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        r = 0.0;
      } else {
        if (x < 0.0) {
          r += 6.2831853071795862;
        }
      }
    }
  } else {
    r = (rtNaN);
  }

  return r;
}

/* Function for MATLAB Function: '<S179>/MATLAB Function1' */
static real_T norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S10>/target_gen_logic_nadir' */
static void align_vecs(const real_T Body1[3], const real_T Inertial1[3], const
  real_T Body2[3], const real_T Inertial2[3], real_T C_cmd[9])
{
  real_T c[3];
  real_T b_c[3];
  real_T tmp;
  real_T B1[9];
  real_T B2[9];
  int32_T i;
  int32_T i_0;
  real_T B1_idx_1;
  real_T B2_idx_2;
  real_T B1_idx_2;
  real_T B2_idx_1;
  real_T B2_idx_0;
  real_T B1_idx_0;
  real_T Ytb_idx_0;
  real_T Ytb_idx_1;
  real_T Ytb_idx_2;
  real_T S2_idx_2;
  real_T S2_idx_1;
  real_T S2_idx_0;
  real_T Yti_idx_1;
  real_T Yti_idx_2;
  real_T c_tmp;
  real_T c_tmp_0;
  real_T c_tmp_1;
  real_T b_c_tmp;
  real_T b_c_tmp_0;
  int32_T C_cmd_tmp;
  int32_T C_cmd_tmp_0;
  S2_idx_2 = norm(Body1);
  tmp = norm(Body2);
  B1_idx_0 = Body1[0] / S2_idx_2;
  B2_idx_0 = Body2[0] / tmp;
  B1_idx_1 = Body1[1] / S2_idx_2;
  B2_idx_1 = Body2[1] / tmp;
  B1_idx_2 = Body1[2] / S2_idx_2;
  B2_idx_2 = Body2[2] / tmp;
  c_tmp = B1_idx_1 * B2_idx_2 - B1_idx_2 * B2_idx_1;
  c[0] = c_tmp;
  c_tmp_0 = B1_idx_2 * B2_idx_0 - B1_idx_0 * B2_idx_2;
  c[1] = c_tmp_0;
  c_tmp_1 = B1_idx_0 * B2_idx_1 - B1_idx_1 * B2_idx_0;
  c[2] = c_tmp_1;
  S2_idx_2 = norm(c);
  Ytb_idx_0 = c_tmp / S2_idx_2;
  Ytb_idx_1 = c_tmp_0 / S2_idx_2;
  Ytb_idx_2 = c_tmp_1 / S2_idx_2;
  c_tmp = B1_idx_1 * Ytb_idx_2 - B1_idx_2 * Ytb_idx_1;
  c[0] = c_tmp;
  c_tmp_0 = B1_idx_2 * Ytb_idx_0 - B1_idx_0 * Ytb_idx_2;
  c[1] = c_tmp_0;
  c_tmp_1 = B1_idx_0 * Ytb_idx_1 - B1_idx_1 * Ytb_idx_0;
  c[2] = c_tmp_1;
  S2_idx_2 = norm(Inertial1);
  tmp = norm(Inertial2);
  B2_idx_0 = Inertial1[0] / S2_idx_2;
  S2_idx_0 = Inertial2[0] / tmp;
  B2_idx_1 = Inertial1[1] / S2_idx_2;
  S2_idx_1 = Inertial2[1] / tmp;
  B2_idx_2 = Inertial1[2] / S2_idx_2;
  S2_idx_2 = Inertial2[2] / tmp;
  b_c_tmp = B2_idx_1 * S2_idx_2 - B2_idx_2 * S2_idx_1;
  b_c[0] = b_c_tmp;
  b_c_tmp_0 = B2_idx_2 * S2_idx_0 - B2_idx_0 * S2_idx_2;
  b_c[1] = b_c_tmp_0;
  S2_idx_0 = B2_idx_0 * S2_idx_1 - B2_idx_1 * S2_idx_0;
  b_c[2] = S2_idx_0;
  S2_idx_2 = norm(b_c);
  S2_idx_1 = b_c_tmp / S2_idx_2;
  Yti_idx_1 = b_c_tmp_0 / S2_idx_2;
  Yti_idx_2 = S2_idx_0 / S2_idx_2;
  b_c_tmp = B2_idx_1 * Yti_idx_2 - B2_idx_2 * Yti_idx_1;
  b_c[0] = b_c_tmp;
  b_c_tmp_0 = B2_idx_2 * S2_idx_1 - B2_idx_0 * Yti_idx_2;
  b_c[1] = b_c_tmp_0;
  S2_idx_0 = B2_idx_0 * Yti_idx_1 - B2_idx_1 * S2_idx_1;
  b_c[2] = S2_idx_0;
  S2_idx_2 = norm(c);
  tmp = norm(b_c);
  B1[6] = c_tmp / S2_idx_2;
  B1[7] = c_tmp_0 / S2_idx_2;
  B1[8] = c_tmp_1 / S2_idx_2;
  B1[0] = B1_idx_0;
  B1[3] = Ytb_idx_0;
  B2[0] = B2_idx_0;
  B2[1] = S2_idx_1;
  B1[1] = B1_idx_1;
  B1[4] = Ytb_idx_1;
  B2[3] = B2_idx_1;
  B2[4] = Yti_idx_1;
  B1[2] = B1_idx_2;
  B1[5] = Ytb_idx_2;
  B2[6] = B2_idx_2;
  B2[7] = Yti_idx_2;
  B2[2] = b_c_tmp / tmp;
  B2[5] = b_c_tmp_0 / tmp;
  B2[8] = S2_idx_0 / tmp;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      C_cmd_tmp = i + 3 * i_0;
      C_cmd[C_cmd_tmp] = 0.0;
      C_cmd_tmp_0 = 3 * i_0 + i;
      C_cmd[C_cmd_tmp] = C_cmd[C_cmd_tmp_0] + B2[3 * i_0] * B1[i];
      C_cmd[C_cmd_tmp] = B2[3 * i_0 + 1] * B1[i + 3] + C_cmd[C_cmd_tmp_0];
      C_cmd[C_cmd_tmp] = B2[3 * i_0 + 2] * B1[i + 6] + C_cmd[C_cmd_tmp_0];
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void FSW_Lib_step0(void)               /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_VariableSelector1[3];
  real_T rtb_VariableSelector[3];
  real_T rtb_Saturation[4];
  int8_T rtb_UnitDelay_f;
  real_T RWA_A[12];
  real_T MTQ_B[15];
  real_T num_dead_MTQ;
  real_T b_temp[15];
  boolean_T d[16];
  boolean_T b_d[25];
  real_T y[9];
  boolean_T b_x[5];
  int32_T b_r1;
  int32_T b_r2;
  int32_T b_r3;
  real_T b_a21;
  int32_T b_rtemp;
  real_T epsb_1980;
  real_T M_moon;
  real_T M_sun;
  real_T u_moon;
  real_T D_sun;
  real_T O_moon;
  real_T dpsi_1980;
  real_T deps_1980;
  real_T api;
  static const real_T nc[300] = { 1.0, 9.0, 31.0, 2.0, 10.0, 32.0, 11.0, 33.0,
    34.0, 12.0, 35.0, 13.0, 36.0, 38.0, 37.0, 40.0, 39.0, 41.0, 14.0, 3.0, 42.0,
    45.0, 43.0, 44.0, 46.0, 15.0, 47.0, 16.0, 18.0, 48.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, -1.0, 1.0, 0.0, -1.0, -1.0, 1.0, 2.0,
    -2.0, 0.0, 2.0, 2.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 0.0,
    0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 0.0, 2.0, 0.0,
    2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, 0.0,
    0.0, 0.0, -2.0, 0.0, 0.0, -2.0, -2.0, -2.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0,
    -2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, -2.0, 0.0, 0.0, -2.0, 2.0, 1.0, 2.0,
    2.0, 2.0, 0.0, 0.0, 2.0, 1.0, 2.0, 2.0, 0.0, 1.0, 2.0, 1.0, 0.0, 2.0, 1.0,
    1.0, 0.0, 1.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0, 2.0, 1.0, -171996.0,
    -13187.0, -2274.0, 2062.0, 1426.0, 712.0, -517.0, -386.0, -301.0, 217.0,
    -158.0, 129.0, 123.0, 63.0, 63.0, -59.0, -58.0, -51.0, 48.0, 46.0, -38.0,
    -31.0, 29.0, 29.0, 26.0, -22.0, 21.0, 17.0, -16.0, 16.0, -174.2, -1.6, -0.2,
    0.2, -3.4, 0.1, 1.2, -0.4, 0.0, -0.5, 0.0, 0.1, 0.0, 0.1, 0.0, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.1, 0.1, 0.0, 92025.0,
    5736.0, 977.0, -895.0, 54.0, -7.0, 224.0, 200.0, 129.0, -95.0, -1.0, -70.0,
    -53.0, -33.0, -2.0, 26.0, 32.0, 27.0, 1.0, -24.0, 16.0, 13.0, -1.0, -12.0,
    -1.0, 0.0, -10.0, 0.0, 7.0, -8.0, 8.9, -3.1, -0.5, 0.5, -0.1, 0.0, -0.6, 0.0,
    -0.1, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T tsince_JD;
  real_T xi;
  real_T b_o;
  real_T eta;
  real_T C_5;
  real_T D_2;
  real_T D_3;
  real_T D_4;
  real_T IL3;
  real_T IL4;
  real_T IL5;
  real_T M_DF;
  real_T d_w;
  real_T M[3];
  real_T N[3];
  boolean_T rEQ0;
  real_T sp[13];
  real_T cp[13];
  real_T P_0[196];
  static const real_T g[156] = { -29438.2, -2444.5, 1351.8, 907.5, -232.9, 69.4,
    81.7, 24.2, 5.5, -2.0, 3.0, -2.0, -1493.5, 3014.7, -2351.6, 814.8, 360.1,
    67.7, -75.9, 8.9, 8.8, -6.1, -1.4, -0.1, 0.0, 1679.0, 1223.6, 117.8, 191.7,
    72.3, -7.1, -16.9, 3.0, 0.2, -2.3, 0.5, 0.0, 0.0, 582.3, -335.6, -141.3,
    -129.1, 52.2, -3.1, -3.2, 0.6, 2.1, 1.2, 0.0, 0.0, 0.0, 69.7, -157.2, -28.4,
    15.0, -20.7, 0.6, -0.5, -0.8, -0.9, 0.0, 0.0, 0.0, 0.0, 7.7, 13.6, 9.1, 13.3,
    -13.2, 1.8, 0.6, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, -70.3, -3.0, 11.6, -0.1, -0.7,
    -0.7, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.9, -16.3, 8.7, 2.2, 0.1, 0.6, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.1, -9.1, 2.4, 1.7, -0.4, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -10.4, -1.8, -0.2, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -3.6, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 3.5, -0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T dg[156] = { 7.0, -11.0, 2.4, -0.8, -0.3, -0.8, -0.3, -0.1,
    -0.1, 0.0, 0.0, 0.0, 9.0, -6.2, -5.7, -0.9, 0.6, -0.5, -0.2, 0.2, -0.1, 0.0,
    0.0, 0.0, 0.0, 0.3, 2.0, -6.5, -0.8, -0.1, -0.3, -0.2, 0.0, -0.1, 0.0, 0.0,
    0.0, 0.0, -11.0, 5.2, 0.1, 1.6, 0.9, 0.5, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0,
    -4.0, 1.2, -1.6, 0.1, -0.1, -0.4, -0.1, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 1.4,
    0.0, -0.6, 0.4, 0.0, -0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, -0.9,
    0.4, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.7, -0.1, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 0.0, -0.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.3, -0.1, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.1 };

  static const real_T h[156] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 4796.3, -2842.4, -113.7, 283.3, 46.9, -20.1, -54.3, 10.1,
    -21.8, 3.3, 0.0, -1.0, 0.0, -638.8, 246.5, -188.6, 196.5, 32.8, -19.5, -18.3,
    10.7, -0.4, 2.1, 0.3, 0.0, 0.0, -537.4, 180.7, -119.9, 59.1, 6.0, 13.3, 11.8,
    4.6, -0.6, 1.8, 0.0, 0.0, 0.0, -330.0, 16.0, -67.1, 24.5, -14.5, -6.8, 4.4,
    -1.1, -2.2, 0.0, 0.0, 0.0, 0.0, 100.6, 8.1, 3.5, 16.2, -6.9, -7.9, 0.7, 0.3,
    0.0, 0.0, 0.0, 0.0, 0.0, 61.9, -27.7, 6.0, 7.9, -0.6, -0.2, 0.7, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -2.9, -9.2, 1.0, -4.2, -2.1, -0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 2.4, -3.9, -2.9, -1.5, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 8.5, -1.1, -2.6, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -8.8,
    -2.0, -0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.3, -0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.8 };

  static const real_T dh[156] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -30.2, -29.6, 6.5, -0.4, 0.2, 0.3, 0.6, -0.4, -0.3, 0.0, 0.0,
    0.0, 0.0, -17.3, -0.8, 5.8, 2.3, -1.5, 0.5, 0.6, 0.1, 0.1, 0.1, 0.0, 0.0,
    0.0, -2.0, 3.8, 0.0, -1.2, -0.8, -0.1, -0.4, -0.2, 0.0, -0.1, 0.0, 0.0, 0.0,
    -3.5, 3.3, 0.4, -0.2, 0.6, 0.3, 0.1, 0.1, 0.1, 0.0, 0.0, 0.0, 0.0, -0.6, 0.2,
    -1.1, -0.2, 0.1, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.3, 0.1, -0.5,
    0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.5, -0.1, 0.0, 0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.5, -0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.1 };

  real_T sc2gs_unit[3];
  static const real_T b[3] = { 0.0, 0.0, -1.0 };

  static const real_T d_0[3] = { 0.0, 1.0, 0.0 };

  static const real_T e[3] = { 0.0, 0.0, 1.0 };

  real_T momentum_error_wheel[4];
  real_T rtb_MathFunction1_d[9];
  boolean_T rtb_LogicalOperator_l;
  real_T rtb_MathFunction_dj[9];
  real_T rtb_MathFunction1_jx[9];
  real_T rtb_Product2_p[3];
  real_T rtb_Gain[3];
  real_T rtb_MathFunction[3];
  real_T rtb_Transpose[4];
  real_T rtb_Multiply[4];
  real_T rtb_Multiply1[9];
  real_T rtb_Abs[5];
  real_T rtb_pos_teme_km[3];
  real_T rtb_vel_teme_kmps[3];
  real_T rtb_teme_to_gcrf[9];
  boolean_T RateTransition1[4];
  real_T rtb_nT2T[3];
  boolean_T rtb_VariableSelector3;
  int32_T i;
  real_T tmp[9];
  real_T M_0[9];
  real_T tmp_0[9];
  real_T M_1[9];
  real_T M_2[9];
  real_T rtb_MathFunction1_f[9];
  real_T rtb_nT2T_tmp[9];
  real_T tmp_1[4];
  real_T tmp_2[5];
  real_T tmp_3[5];
  real_T rtb_YMDHMS_UTC_idx_5;
  real_T rtb_YMDHMS_UTC_idx_2;
  real_T rtb_YMDHMS_UTC_idx_4;
  real_T rtb_YMDHMS_UTC_idx_1;
  real_T rtb_YMDHMS_UTC_idx_3;
  real_T rtb_YMDHMS_UTC_idx_0;
  int32_T b_temp_tmp;
  int32_T b_temp_tmp_0;
  int32_T b_temp_tmp_1;
  int32_T b_temp_tmp_2;
  int32_T b_temp_tmp_3;
  real_T epsb_1980_tmp;
  real_T epsb_1980_tmp_0;
  real_T D_sun_tmp;
  real_T api_tmp;
  real_T api_tmp_0;
  real_T D_4_tmp;
  real_T M_DF_tmp;
  real_T api_tmp_tmp;
  real_T api_tmp_1;
  boolean_T guard1 = false;
  boolean_T exitg1;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [1.0s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID1_2)++;
  if ((rtM->Timing.RateInteraction.TID1_2) > 9) {
    rtM->Timing.RateInteraction.TID1_2 = 0;
  }

  /* RateTransition: '<S4>/Rate Transition1' incorporates:
   *  Inport: '<Root>/act_meas'
   */
  RateTransition1[0] = rtU.act_meas.rwa_valid[0];
  RateTransition1[1] = rtU.act_meas.rwa_valid[1];
  RateTransition1[2] = rtU.act_meas.rwa_valid[2];
  RateTransition1[3] = rtU.act_meas.rwa_valid[3];

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant3'
   *  Inport: '<Root>/act_meas'
   *  RateTransition: '<S4>/Rate Transition1'
   */
  for (i = 0; i < 16; i++) {
    d[i] = false;
  }

  d[0] = rtU.act_meas.rwa_valid[0];
  d[5] = rtU.act_meas.rwa_valid[1];
  d[10] = rtU.act_meas.rwa_valid[2];
  d[15] = rtU.act_meas.rwa_valid[3];
  for (i = 0; i < 4; i++) {
    for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
      b_r1 = b_rtemp + 3 * i;
      RWA_A[b_r1] = 0.0;
      b_r2 = i << 2;
      b_r3 = 3 * i + b_rtemp;
      RWA_A[b_r1] = RWA_A[b_r3] + (real_T)d[b_r2] * rtConstP.pooled29[b_rtemp];
      RWA_A[b_r1] = (real_T)d[b_r2 + 1] * rtConstP.pooled29[b_rtemp + 3] +
        RWA_A[b_r3];
      RWA_A[b_r1] = (real_T)d[b_r2 + 2] * rtConstP.pooled29[b_rtemp + 6] +
        RWA_A[b_r3];
      RWA_A[b_r1] = (real_T)d[b_r2 + 3] * rtConstP.pooled29[b_rtemp + 9] +
        RWA_A[b_r3];
    }
  }

  for (i = 0; i < 25; i++) {
    b_d[i] = false;
  }

  for (b_r1 = 0; b_r1 < 5; b_r1++) {
    b_d[b_r1 + 5 * b_r1] = rtU.act_meas.mtq_valid[b_r1];
  }

  for (i = 0; i < 5; i++) {
    for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
      b_r2 = b_rtemp + 3 * i;
      MTQ_B[b_r2] = 0.0;
      for (b_r1 = 0; b_r1 < 5; b_r1++) {
        MTQ_B[b_r2] = rtConstP.Constant2_Value[3 * b_r1 + b_rtemp] * (real_T)
          b_d[5 * i + b_r1] + MTQ_B[3 * i + b_rtemp];
      }
    }
  }

  memcpy(&b_temp[0], &rtConstP.pooled24[0], 15U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    b_x[i] = !rtU.act_meas.mtq_valid[i];
  }

  if (((((real_T)b_x[0] + (real_T)b_x[1]) + (real_T)b_x[2]) + (real_T)b_x[3]) +
      (real_T)b_x[4] > 0.0) {
    if (((!rtU.act_meas.mtq_valid[0]) && (!rtU.act_meas.mtq_valid[1])) ||
        ((!rtU.act_meas.mtq_valid[2]) && (!rtU.act_meas.mtq_valid[3])) ||
        (!rtU.act_meas.mtq_valid[4])) {
      for (i = 0; i < 25; i++) {
        b_d[i] = false;
      }

      for (b_r1 = 0; b_r1 < 5; b_r1++) {
        b_d[b_r1 + 5 * b_r1] = rtU.act_meas.mtq_valid[b_r1];
      }

      for (i = 0; i < 3; i++) {
        for (b_rtemp = 0; b_rtemp < 5; b_rtemp++) {
          b_temp_tmp = b_rtemp + 5 * i;
          b_temp[b_temp_tmp] = 0.0;
          for (b_r1 = 0; b_r1 < 5; b_r1++) {
            b_temp[b_temp_tmp] = (real_T)b_d[5 * b_r1 + b_rtemp] *
              rtConstP.pooled24[5 * i + b_r1] + b_temp[5 * i + b_rtemp];
          }
        }
      }
    } else {
      for (i = 0; i < 25; i++) {
        b_d[i] = false;
      }

      for (b_r1 = 0; b_r1 < 5; b_r1++) {
        b_d[b_r1 + 5 * b_r1] = rtU.act_meas.mtq_valid[b_r1];
      }

      for (i = 0; i < 5; i++) {
        for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
          b_temp_tmp = b_rtemp + 3 * i;
          b_temp[b_temp_tmp] = 0.0;
          for (b_r1 = 0; b_r1 < 5; b_r1++) {
            b_temp[b_temp_tmp] = MTQ_B[3 * b_r1 + b_rtemp] * (real_T)b_d[5 * i +
              b_r1] + b_temp[3 * i + b_rtemp];
          }
        }
      }

      for (i = 0; i < 3; i++) {
        for (b_rtemp = 0; b_rtemp < 5; b_rtemp++) {
          MTQ_B[b_rtemp + 5 * i] = b_temp[3 * b_rtemp + i];
        }
      }

      for (i = 0; i < 3; i++) {
        for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
          b_r2 = b_rtemp + 3 * i;
          y[b_r2] = 0.0;
          for (b_r1 = 0; b_r1 < 5; b_r1++) {
            y[b_r2] = b_temp[3 * b_r1 + b_rtemp] * MTQ_B[5 * i + b_r1] + y[3 * i
              + b_rtemp];
          }
        }
      }

      b_r1 = 0;
      b_r2 = 1;
      b_r3 = 2;
      num_dead_MTQ = fabs(y[0]);
      b_a21 = fabs(y[1]);
      if (b_a21 > num_dead_MTQ) {
        num_dead_MTQ = b_a21;
        b_r1 = 1;
        b_r2 = 0;
      }

      if (fabs(y[2]) > num_dead_MTQ) {
        b_r1 = 2;
        b_r2 = 1;
        b_r3 = 0;
      }

      y[b_r2] /= y[b_r1];
      y[b_r3] /= y[b_r1];
      y[3 + b_r2] -= y[3 + b_r1] * y[b_r2];
      y[3 + b_r3] -= y[3 + b_r1] * y[b_r3];
      y[6 + b_r2] -= y[6 + b_r1] * y[b_r2];
      y[6 + b_r3] -= y[6 + b_r1] * y[b_r3];
      if (fabs(y[3 + b_r3]) > fabs(y[3 + b_r2])) {
        b_rtemp = b_r2;
        b_r2 = b_r3;
        b_r3 = b_rtemp;
      }

      y[3 + b_r3] /= y[3 + b_r2];
      y[6 + b_r3] -= y[3 + b_r3] * y[6 + b_r2];
      for (b_rtemp = 0; b_rtemp < 5; b_rtemp++) {
        b_temp_tmp = b_rtemp + 5 * b_r1;
        b_temp[b_temp_tmp] = MTQ_B[b_rtemp] / y[b_r1];
        i = 5 * b_r1 + b_rtemp;
        b_temp_tmp_0 = b_rtemp + 5 * b_r2;
        b_temp[b_temp_tmp_0] = MTQ_B[5 + b_rtemp] - b_temp[i] * y[3 + b_r1];
        b_temp_tmp_2 = b_rtemp + 5 * b_r3;
        b_temp[b_temp_tmp_2] = MTQ_B[10 + b_rtemp] - b_temp[i] * y[6 + b_r1];
        b_temp_tmp_1 = 5 * b_r2 + b_rtemp;
        b_temp[b_temp_tmp_0] = b_temp[b_temp_tmp_1] / y[3 + b_r2];
        b_temp_tmp_3 = 5 * b_r3 + b_rtemp;
        b_temp[b_temp_tmp_2] = b_temp[b_temp_tmp_3] - b_temp[b_temp_tmp_1] * y[6
          + b_r2];
        b_temp[b_temp_tmp_2] = b_temp[b_temp_tmp_3] / y[6 + b_r3];
        b_temp[b_temp_tmp_0] = b_temp[b_temp_tmp_1] - b_temp[b_temp_tmp_3] * y[3
          + b_r3];
        b_temp[b_temp_tmp] = b_temp[i] - b_temp[b_temp_tmp_3] * y[b_r3];
        b_temp[b_temp_tmp] = b_temp[i] - b_temp[b_temp_tmp_1] * y[b_r2];
      }
    }
  }

  /* MATLAB Function: '<S178>/MATLAB Function3' incorporates:
   *  Inport: '<Root>/telecommands'
   */
  jseconds2ymdhms(rtU.telecommands.MET_utc_s, &rtb_YMDHMS_UTC_idx_0,
                  &rtb_YMDHMS_UTC_idx_1, &rtb_YMDHMS_UTC_idx_2,
                  &rtb_YMDHMS_UTC_idx_3, &rtb_YMDHMS_UTC_idx_4,
                  &rtb_YMDHMS_UTC_idx_5, &M_sun, &tsince_JD);
  jseconds2ymdhms(rtU.telecommands.MET_utc_s + -0.0361535, &b_a21, &epsb_1980,
                  &M_moon, &O_moon, &M_sun, &dpsi_1980, &num_dead_MTQ, &u_moon);
  jseconds2ymdhms((rtU.telecommands.MET_utc_s + 37.0) + 32.184, &epsb_1980,
                  &M_moon, &O_moon, &M_sun, &dpsi_1980, &u_moon, &b_a21, &D_sun);

  /* MATLAB Function: '<S322>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S178>/MATLAB Function3'
   */
  epsb_1980_tmp = b_a21 * b_a21;
  epsb_1980_tmp_0 = rt_powd_snf(b_a21, 3.0);
  epsb_1980 = (((23.439291 - 0.0130042 * b_a21) - epsb_1980_tmp * 1.64E-7) +
               5.04E-7 * epsb_1980_tmp_0) * 0.017453292519943295;
  M_moon = (((477198.8673981 * b_a21 + 134.96298139) + epsb_1980_tmp * 0.0086972)
            + 1.78E-5 * epsb_1980_tmp_0) * 0.017453292519943295;
  M_sun = (((35999.05034 * b_a21 + 357.52772333) - epsb_1980_tmp * 0.0001603) -
           3.3E-6 * epsb_1980_tmp_0) * 0.017453292519943295;
  u_moon = (((483202.0175381 * b_a21 + 93.27191028) - epsb_1980_tmp * 0.0036825)
            + 3.1E-6 * epsb_1980_tmp_0) * 0.017453292519943295;
  D_sun = (((445267.11148 * b_a21 + 297.85036306) - epsb_1980_tmp * 0.0019142) +
           5.3E-6 * epsb_1980_tmp_0) * 0.017453292519943295;
  O_moon = (((125.04452222 - 1934.1362608 * b_a21) + epsb_1980_tmp * 0.0020708)
            + 2.2E-6 * epsb_1980_tmp_0) * 0.017453292519943295;
  dpsi_1980 = 0.0;
  deps_1980 = 0.0;
  for (b_r1 = 0; b_r1 < 30; b_r1++) {
    api = (((nc[30 + b_r1] * M_moon + nc[60 + b_r1] * M_sun) + nc[90 + b_r1] *
            u_moon) + nc[120 + b_r1] * D_sun) + nc[150 + b_r1] * O_moon;
    dpsi_1980 += (nc[210 + b_r1] * b_a21 + nc[180 + b_r1]) * 0.0001 * sin(api);
    deps_1980 += (nc[270 + b_r1] * b_a21 + nc[240 + b_r1]) * 0.0001 * cos(api);
  }

  u_moon = 4.84813681109536E-6 * deps_1980 + epsb_1980;
  M_sun = 4.84813681109536E-6 * dpsi_1980;
  M[0] = 1.0;
  rtb_pos_teme_km[0] = 0.0;
  M[1] = 0.0;
  rtb_pos_teme_km[1] = 0.0;
  M[2] = 0.0;
  rtb_pos_teme_km[2] = 1.0;
  D_sun = ((epsb_1980_tmp * 0.30188 + 2306.2181 * b_a21) + 0.017998 *
           epsb_1980_tmp_0) * 4.84813681109536E-6;
  M_moon = ((epsb_1980_tmp * 1.09468 + 2306.2181 * b_a21) + 0.018203 *
            epsb_1980_tmp_0) * 4.84813681109536E-6;
  deps_1980 = -(((2004.3109 * b_a21 - epsb_1980_tmp * 0.42665) - 0.041833 *
                 epsb_1980_tmp_0) * 4.84813681109536E-6);
  dpsi_1980 = ((dpsi_1980 * cos(epsb_1980) + 0.00264 * sin(O_moon)) + sin(2.0 *
    O_moon) * 6.3E-5) * 4.84813681109536E-6;
  api = ((3.1644001848128662E+9 * num_dead_MTQ + 67310.54841) + num_dead_MTQ *
         num_dead_MTQ * 0.093104) - 6.2E-6 * rt_powd_snf(num_dead_MTQ, 3.0);
  if (api < 0.0) {
    b_a21 = -1.0;
  } else if (api > 0.0) {
    b_a21 = 1.0;
  } else if (api == 0.0) {
    b_a21 = 0.0;
  } else {
    b_a21 = (rtNaN);
  }

  b_a21 *= 86400.0;
  O_moon = api;
  if ((!rtIsInf(api)) && (!rtIsNaN(api)) && (!rtIsNaN(b_a21))) {
    if (api == 0.0) {
      O_moon = b_a21 * 0.0;
    } else {
      if (b_a21 != 0.0) {
        O_moon = fmod(api, b_a21);
        if (O_moon == 0.0) {
          O_moon = b_a21 * 0.0;
        } else {
          if ((api < 0.0) != (b_a21 < 0.0)) {
            O_moon += b_a21;
          }
        }
      }
    }
  } else {
    if (b_a21 != 0.0) {
      O_moon = (rtNaN);
    }
  }

  api = O_moon / 240.0;
  if ((!rtIsInf(api)) && (!rtIsNaN(api))) {
    if (api == 0.0) {
      b_a21 = 0.0;
    } else {
      b_a21 = fmod(api, 360.0);
      if (b_a21 == 0.0) {
        b_a21 = 0.0;
      } else {
        if (api < 0.0) {
          b_a21 += 360.0;
        }
      }
    }
  } else {
    b_a21 = (rtNaN);
  }

  b_a21 = -(0.017453292519943295 * b_a21 + dpsi_1980);
  api = cos(D_sun);
  rtb_MathFunction1_f[0] = api;
  D_sun = sin(D_sun);
  rtb_MathFunction1_f[3] = D_sun;
  rtb_MathFunction1_f[6] = 0.0;
  rtb_MathFunction1_f[1] = -D_sun;
  rtb_MathFunction1_f[4] = api;
  rtb_MathFunction1_f[7] = 0.0;
  api = cos(deps_1980);
  M_1[0] = api;
  M_1[3] = 0.0;
  D_sun = sin(deps_1980);
  M_1[6] = -D_sun;
  rtb_MathFunction1_f[2] = 0.0;
  M_1[1] = 0.0;
  rtb_MathFunction1_f[5] = 0.0;
  M_1[4] = 1.0;
  rtb_MathFunction1_f[8] = 1.0;
  M_1[7] = 0.0;
  M_1[2] = D_sun;
  M_1[5] = 0.0;
  M_1[8] = api;
  api = cos(M_moon);
  tmp[0] = api;
  D_sun = sin(M_moon);
  tmp[3] = D_sun;
  tmp[6] = 0.0;
  tmp[1] = -D_sun;
  tmp[4] = api;
  tmp[7] = 0.0;
  M_0[1] = 0.0;
  O_moon = cos(-epsb_1980);
  M_0[4] = O_moon;
  M_moon = sin(-epsb_1980);
  M_0[7] = M_moon;
  M_0[2] = 0.0;
  M_0[5] = -M_moon;
  M_0[8] = O_moon;
  api = cos(M_sun);
  tmp_0[0] = api;
  D_sun = sin(M_sun);
  tmp_0[3] = D_sun;
  tmp_0[6] = 0.0;
  tmp_0[1] = -D_sun;
  tmp_0[4] = api;
  tmp_0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
      b_r1 = i + 3 * b_rtemp;
      rtb_nT2T_tmp[b_r1] = 0.0;
      b_r2 = 3 * b_rtemp + i;
      rtb_nT2T_tmp[b_r1] = rtb_nT2T_tmp[b_r2] + M_1[3 * b_rtemp] *
        rtb_MathFunction1_f[i];
      rtb_nT2T_tmp[b_r1] = M_1[3 * b_rtemp + 1] * rtb_MathFunction1_f[i + 3] +
        rtb_nT2T_tmp[b_r2];
      rtb_nT2T_tmp[b_r1] = M_1[3 * b_rtemp + 2] * rtb_MathFunction1_f[i + 6] +
        rtb_nT2T_tmp[b_r2];
    }

    b_rtemp = 2 + 3 * i;
    tmp[b_rtemp] = rtb_pos_teme_km[i];
    M_0[3 * i] = M[i];
    tmp_0[b_rtemp] = rtb_pos_teme_km[i];
  }

  M_2[1] = 0.0;
  O_moon = cos(u_moon);
  M_2[4] = O_moon;
  M_moon = sin(u_moon);
  M_2[7] = M_moon;
  M_2[2] = 0.0;
  M_2[5] = -M_moon;
  M_2[8] = O_moon;
  for (i = 0; i < 3; i++) {
    M_2[3 * i] = M[i];
    for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
      b_r1 = i + 3 * b_rtemp;
      M_1[b_r1] = 0.0;
      rtb_MathFunction1_f[b_r1] = 0.0;
      b_r2 = 3 * b_rtemp + i;
      M_1[b_r1] = M_1[b_r2] + tmp_0[3 * b_rtemp] * M_0[i];
      rtb_MathFunction1_f[b_r1] = rtb_MathFunction1_f[b_r2] + tmp[3 * b_rtemp] *
        rtb_nT2T_tmp[i];
      b_r3 = 3 * b_rtemp + 1;
      M_1[b_r1] = tmp_0[b_r3] * M_0[i + 3] + M_1[b_r2];
      rtb_MathFunction1_f[b_r1] = tmp[b_r3] * rtb_nT2T_tmp[i + 3] +
        rtb_MathFunction1_f[b_r2];
      b_r3 = 3 * b_rtemp + 2;
      M_1[b_r1] = tmp_0[b_r3] * M_0[i + 6] + M_1[b_r2];
      rtb_MathFunction1_f[b_r1] = tmp[b_r3] * rtb_nT2T_tmp[i + 6] +
        rtb_MathFunction1_f[b_r2];
    }
  }

  for (i = 0; i < 3; i++) {
    for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
      b_r1 = b_rtemp + 3 * i;
      M_0[b_r1] = 0.0;
      b_r2 = 3 * i + b_rtemp;
      M_0[b_r1] = M_0[b_r2] + M_2[3 * i] * M_1[b_rtemp];
      M_0[b_r1] = M_2[3 * i + 1] * M_1[b_rtemp + 3] + M_0[b_r2];
      M_0[b_r1] = M_2[3 * i + 2] * M_1[b_rtemp + 6] + M_0[b_r2];
    }
  }

  api = cos(-dpsi_1980);
  M_1[0] = api;
  D_sun = sin(-dpsi_1980);
  M_1[3] = D_sun;
  M_1[6] = 0.0;
  M_1[1] = -D_sun;
  M_1[4] = api;
  M_1[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
      b_r2 = i + 3 * b_rtemp;
      y[b_r2] = 0.0;
      b_r1 = 3 * b_rtemp + i;
      y[b_r2] = y[b_r1] + M_0[3 * b_rtemp] * rtb_MathFunction1_f[i];
      y[b_r2] = M_0[3 * b_rtemp + 1] * rtb_MathFunction1_f[i + 3] + y[b_r1];
      y[b_r2] = M_0[3 * b_rtemp + 2] * rtb_MathFunction1_f[i + 6] + y[b_r1];
    }

    M_1[2 + 3 * i] = rtb_pos_teme_km[i];
  }

  api = cos(b_a21);
  rtb_MathFunction1_f[0] = api;
  D_sun = sin(b_a21);
  rtb_MathFunction1_f[3] = D_sun;
  rtb_MathFunction1_f[6] = 0.0;
  rtb_MathFunction1_f[1] = -D_sun;
  rtb_MathFunction1_f[4] = api;
  rtb_MathFunction1_f[7] = 0.0;
  for (i = 0; i < 3; i++) {
    rtb_MathFunction1_f[2 + 3 * i] = rtb_pos_teme_km[i];

    /* Math: '<S178>/Transpose' */
    for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
      b_r1 = i + 3 * b_rtemp;
      rtb_teme_to_gcrf[b_r1] = 0.0;
      rtb_Multiply1[b_r1] = 0.0;
      b_r2 = 3 * b_rtemp + i;
      rtb_teme_to_gcrf[b_r1] = rtb_teme_to_gcrf[b_r2] + M_1[3 * b_rtemp] * y[i];
      rtb_Multiply1[b_r1] = rtb_Multiply1[b_r2] + rtb_MathFunction1_f[3 * i] *
        y[b_rtemp];
      rtb_teme_to_gcrf[b_r1] = M_1[3 * b_rtemp + 1] * y[i + 3] +
        rtb_teme_to_gcrf[b_r2];
      rtb_Multiply1[b_r1] = rtb_MathFunction1_f[3 * i + 1] * y[b_rtemp + 3] +
        rtb_Multiply1[b_r2];
      rtb_teme_to_gcrf[b_r1] = M_1[3 * b_rtemp + 2] * y[i + 6] +
        rtb_teme_to_gcrf[b_r2];
      rtb_Multiply1[b_r1] = rtb_MathFunction1_f[3 * i + 2] * y[b_rtemp + 6] +
        rtb_Multiply1[b_r2];
    }

    /* End of Math: '<S178>/Transpose' */
  }

  /* MATLAB Function: '<S176>/MATLAB Function' incorporates:
   *  Constant: '<S176>/JD_J2000'
   *  Inport: '<Root>/telecommands'
   *  MATLAB Function: '<S178>/MATLAB Function3'
   *  Sum: '<S176>/Sum'
   */
  O_moon = 1.88027916E-9;
  epsb_1980 = 1.01222928;
  b_a21 = rtU.telecommands.orbit_tle[3] * 0.0174532925;
  M_sun = rtU.telecommands.orbit_tle[6] * 0.0174532925;
  M_moon = rtU.telecommands.orbit_tle[7] * 0.0174532925;
  u_moon = rtU.telecommands.orbit_tle[8] * 2.0 * 3.1415926535897931 / 1440.0;
  if ((rtU.telecommands.orbit_tle[5] >= 1.0) || (rtU.telecommands.orbit_tle[5] <=
       0.0)) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_vel_teme_kmps[0] = 0.0;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_vel_teme_kmps[1] = 0.0;
    rtb_pos_teme_km[2] = 6878.137;
    rtb_vel_teme_kmps[2] = 0.0;
  } else if (u_moon == 0.0) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_vel_teme_kmps[0] = 0.0;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_vel_teme_kmps[1] = 0.0;
    rtb_pos_teme_km[2] = 6878.137;
    rtb_vel_teme_kmps[2] = 0.0;
  } else {
    tsince_JD = (tsince_JD - 2.451545E+6) - rtU.telecommands.orbit_tle[1];
    if (fabs(tsince_JD) < 1.0E-8) {
      tsince_JD = 0.0;
    } else {
      if (tsince_JD < 0.0) {
        tsince_JD = 0.0;
      }
    }

    dpsi_1980 = 1440.0 * tsince_JD;
    tsince_JD = rt_powd_snf(0.0743669161 / u_moon, 0.66666666666666663);
    D_sun_tmp = cos(b_a21);
    api = 1.0 - rtU.telecommands.orbit_tle[5] * rtU.telecommands.orbit_tle[5];
    D_sun = (D_sun_tmp * D_sun_tmp * 3.0 - 1.0) / rt_powd_snf(api, 1.5) *
      (0.000541308 / (tsince_JD * tsince_JD) * 1.5);
    tsince_JD *= ((1.0 - 0.33333333333333331 * D_sun) - D_sun * D_sun) -
      1.654320987654321 * rt_powd_snf(D_sun, 3.0);
    deps_1980 = (D_sun_tmp * D_sun_tmp * 3.0 - 1.0) / rt_powd_snf(1.0 -
      rtU.telecommands.orbit_tle[5] * rtU.telecommands.orbit_tle[5], 1.5) *
      (0.000541308 / (tsince_JD * tsince_JD) * 1.5);
    D_sun = u_moon / (1.0 + deps_1980);
    deps_1980 = tsince_JD / (1.0 - deps_1980);
    IL3 = (1.0 - rtU.telecommands.orbit_tle[5]) * deps_1980;
    tsince_JD = (IL3 - 1.0) * 6378.137;
    if (IL3 < 1.0344928307435228) {
      b_r1 = 1;
    } else {
      b_r1 = 0;
    }

    if ((tsince_JD >= 98.0) && (tsince_JD <= 156.0)) {
      epsb_1980 = (IL3 - 1.01222928) + 1.0;
      O_moon = rt_powd_snf(1.0188142770258546 - ((IL3 - 1.01222928) + 1.0), 4.0);
    } else {
      if (tsince_JD < 98.0) {
        O_moon = 6.0426196528035638E-8;
        epsb_1980 = 1.0031357118857749;
      }
    }

    xi = 1.0 / (deps_1980 - epsb_1980);
    b_o = sqrt(api);
    eta = deps_1980 * rtU.telecommands.orbit_tle[5] * xi;
    if (eta == 1.0) {
      rtb_pos_teme_km[0] = 6378.137;
      rtb_vel_teme_kmps[0] = 0.0;
      rtb_pos_teme_km[1] = 6378.137;
      rtb_vel_teme_kmps[1] = 0.0;
      rtb_pos_teme_km[2] = 6878.137;
      rtb_vel_teme_kmps[2] = 0.0;
    } else {
      d_w = eta * eta;
      tsince_JD = rt_powd_snf(xi, 4.0);
      api_tmp = rt_powd_snf(1.0 - eta * eta, -3.5);
      api_tmp_tmp = rt_powd_snf(eta, 3.0);
      api_tmp_0 = rtU.telecommands.orbit_tle[5] * api_tmp_tmp;
      api_tmp_1 = d_w * 1.5;
      api = ((((api_tmp_1 + 1.0) + 4.0 * rtU.telecommands.orbit_tle[5] * eta) +
              api_tmp_0) * deps_1980 + (D_sun_tmp * D_sun_tmp * 1.5 + -0.5) *
             (0.00081196200000000006 * xi) * ((d_w * 24.0 + 8.0) + 3.0 *
              rt_powd_snf(eta, 4.0)) / (1.0 - d_w)) * (O_moon * tsince_JD *
        D_sun * api_tmp) * rtU.telecommands.orbit_tle[2];
      C_5 = 0.0;
      D_2 = 0.0;
      D_3 = 0.0;
      D_4 = 0.0;
      IL3 = 0.0;
      IL4 = 0.0;
      IL5 = 0.0;
      if (b_r1 == 0) {
        C_5 = 2.0 * O_moon * tsince_JD * deps_1980 * (b_o * b_o) * api_tmp *
          ((2.75 * eta * (eta + rtU.telecommands.orbit_tle[5]) + 1.0) +
           api_tmp_0);
        u_moon = api * api;
        D_2 = 4.0 * deps_1980 * xi * u_moon;
        IL4 = rt_powd_snf(api, 3.0);
        D_3 = 1.3333333333333333 * deps_1980 * (xi * xi) * (17.0 * deps_1980 +
          epsb_1980) * IL4;
        D_4_tmp = rt_powd_snf(api, 4.0);
        D_4 = 0.66666666666666663 * deps_1980 * rt_powd_snf(xi, 3.0) * (221.0 *
          deps_1980 + 31.0 * epsb_1980) * D_4_tmp;
        IL3 = u_moon * 2.0 + D_2;
        IL4 = ((12.0 * api * D_2 + 3.0 * D_3) + 10.0 * IL4) * 0.25;
        IL5 = ((((12.0 * api * D_3 + 3.0 * D_4) + D_2 * D_2 * 6.0) + u_moon *
                30.0 * D_2) + 15.0 * D_4_tmp) * 0.2;
      }

      u_moon = rt_powd_snf(D_sun_tmp, 4.0);
      D_4_tmp = rt_powd_snf(deps_1980, 4.0);
      epsb_1980_tmp_0 = 16.0 * D_4_tmp;
      epsb_1980 = deps_1980 * deps_1980;
      M_DF_tmp = epsb_1980 * 2.0 * rt_powd_snf(b_o, 3.0);
      M_DF = (((D_sun_tmp * D_sun_tmp * 3.0 - 1.0) * 0.0016239240000000001 /
               M_DF_tmp + 1.0) + ((13.0 - D_sun_tmp * D_sun_tmp * 78.0) + 137.0 *
               u_moon) * 8.7904305259200008E-7 / (epsb_1980_tmp_0 * rt_powd_snf
               (b_o, 7.0))) * D_sun * dpsi_1980 + M_moon;
      epsb_1980_tmp = rt_powd_snf(b_o, 8.0);
      u_moon = ((((7.0 - D_sun_tmp * D_sun_tmp * 114.0) + 395.0 * u_moon) *
                 8.7904305259200008E-7 / (epsb_1980_tmp_0 * epsb_1980_tmp) +
                 (1.0 - D_sun_tmp * D_sun_tmp * 5.0) * -0.0016239240000000001 /
                 M_DF_tmp) + ((3.0 - D_sun_tmp * D_sun_tmp * 36.0) + 49.0 *
                 u_moon) * 3.1049437500000002E-6 / (4.0 * D_4_tmp *
                 epsb_1980_tmp)) * D_sun * dpsi_1980 + M_sun;
      epsb_1980_tmp *= 2.0 * D_4_tmp;
      epsb_1980_tmp_0 = dpsi_1980 * dpsi_1980;
      D_4_tmp = D_sun_tmp * D_sun_tmp * 7.0;
      epsb_1980 = ((((4.0 * D_sun_tmp - 19.0 * rt_powd_snf(D_sun_tmp, 3.0)) *
                     8.7904305259200008E-7 / epsb_1980_tmp +
                     -0.0016239240000000001 * D_sun_tmp / (epsb_1980 *
        rt_powd_snf(b_o, 4.0))) + (3.0 - D_4_tmp) * (3.1049437500000002E-6 *
        D_sun_tmp) / epsb_1980_tmp) * D_sun * dpsi_1980 +
                   rtU.telecommands.orbit_tle[4] * 0.0174532925) - D_sun *
        0.000541308 * D_sun_tmp / (epsb_1980 * (b_o * b_o)) * 10.5 * api *
        epsb_1980_tmp_0;
      if (b_r1 == 0) {
        d_w = O_moon * rt_powd_snf(xi, 5.0) * 2.538815E-6 * D_sun * sin(b_a21) /
          (0.000541308 * rtU.telecommands.orbit_tle[5]) *
          rtU.telecommands.orbit_tle[2] * cos(M_sun) * dpsi_1980;
        tsince_JD = -0.66666666666666663 * O_moon * rtU.telecommands.orbit_tle[2]
          * tsince_JD * (1.0 / (rtU.telecommands.orbit_tle[5] * eta)) *
          (rt_powd_snf(eta * cos(M_DF) + 1.0, 3.0) - rt_powd_snf(eta * cos
            (M_moon) + 1.0, 3.0));
        M_DF = (M_DF + d_w) + tsince_JD;
        u_moon = (u_moon - d_w) - tsince_JD;
        O_moon = (rtU.telecommands.orbit_tle[5] -
                  ((((rtU.telecommands.orbit_tle[5] * eta + 1.0) * (2.0 * eta) +
                     0.5 * rtU.telecommands.orbit_tle[5]) + 0.5 * rt_powd_snf
                    (eta, 3.0)) - ((((1.0 - eta * eta * 1.5) - 2.0 *
          rtU.telecommands.orbit_tle[5] * eta) - 0.5 *
          rtU.telecommands.orbit_tle[5] * rt_powd_snf(eta, 3.0)) * ((1.0 -
          D_sun_tmp * D_sun_tmp * 3.0) * 3.0) + ((eta * eta * 2.0 -
          rtU.telecommands.orbit_tle[5] * eta) - rtU.telecommands.orbit_tle[5] *
          rt_powd_snf(eta, 3.0)) * ((1.0 - D_sun_tmp * D_sun_tmp) * 0.75) * cos
                    (2.0 * M_sun)) * (0.001082616 * xi / ((1.0 - eta * eta) *
          deps_1980))) * (2.0 * D_sun * O_moon * rt_powd_snf(xi, 4.0) *
                          deps_1980 * (b_o * b_o) * rt_powd_snf(1.0 - eta * eta,
                    -3.5)) * rtU.telecommands.orbit_tle[2] * dpsi_1980) -
          rtU.telecommands.orbit_tle[2] * C_5 * (sin(M_DF) - sin(M_moon));
        xi = rt_powd_snf(dpsi_1980, 3.0);
        tsince_JD = rt_powd_snf(dpsi_1980, 4.0);
        M_sun = (((1.0 - api * dpsi_1980) - epsb_1980_tmp_0 * D_2) - D_3 * xi) -
          D_4 * tsince_JD;
        M_moon = M_sun * M_sun * deps_1980;
        api = (((1.5 * api * epsb_1980_tmp_0 + IL3 * xi) + IL4 * tsince_JD) +
               IL5 * rt_powd_snf(dpsi_1980, 5.0)) * D_sun + ((M_DF + u_moon) +
          epsb_1980);
      } else {
        IL3 = 1.0 - api * dpsi_1980;
        M_moon = IL3 * IL3 * deps_1980;
        D_2 = rtU.telecommands.orbit_tle[5] * eta;
        O_moon = rtU.telecommands.orbit_tle[5] - ((((D_2 + 1.0) * (2.0 * eta) +
          0.5 * rtU.telecommands.orbit_tle[5]) + 0.5 * api_tmp_tmp) - ((((1.0 -
          api_tmp_1) - 2.0 * rtU.telecommands.orbit_tle[5] * eta) - 0.5 *
          rtU.telecommands.orbit_tle[5] * api_tmp_tmp) * ((1.0 - D_sun_tmp *
          D_sun_tmp * 3.0) * 3.0) + ((d_w * 2.0 - D_2) - api_tmp_0) * ((1.0 -
          D_sun_tmp * D_sun_tmp) * 0.75) * cos(2.0 * M_sun)) * (0.001082616 * xi
          / ((1.0 - eta * eta) * deps_1980))) * (2.0 * D_sun * O_moon *
          tsince_JD * deps_1980 * (b_o * b_o) * api_tmp) *
          rtU.telecommands.orbit_tle[2] * dpsi_1980;
        api = 1.5 * api * D_sun * epsb_1980_tmp_0 + ((M_DF + u_moon) + epsb_1980);
      }

      if ((M_moon == 0.0) || (O_moon >= 1.0)) {
        rtb_pos_teme_km[0] = 6378.137;
        rtb_vel_teme_kmps[0] = 0.0;
        rtb_pos_teme_km[1] = 6378.137;
        rtb_vel_teme_kmps[1] = 0.0;
        rtb_pos_teme_km[2] = 6878.137;
        rtb_vel_teme_kmps[2] = 0.0;
      } else {
        deps_1980 = sqrt(1.0 - O_moon * O_moon);
        xi = cos(u_moon);
        M_sun = O_moon * xi;
        dpsi_1980 = deps_1980 * deps_1980;
        deps_1980 = 2.538815E-6 * sin(b_a21);
        D_sun = deps_1980 / (0.002165232 * M_moon * dpsi_1980) + O_moon * sin
          (u_moon);
        u_moon = (deps_1980 / (0.004330464 * M_moon * dpsi_1980) * O_moon * xi *
                  ((5.0 * D_sun_tmp + 3.0) / (1.0 + D_sun_tmp)) + api) -
          epsb_1980;
        if ((!rtIsInf(u_moon)) && (!rtIsNaN(u_moon))) {
          if (u_moon == 0.0) {
            deps_1980 = 0.0;
          } else {
            deps_1980 = fmod(u_moon, 6.2831853071795862);
            rEQ0 = (deps_1980 == 0.0);
            if (!rEQ0) {
              O_moon = fabs(u_moon / 6.2831853071795862);
              rEQ0 = (fabs(O_moon - floor(O_moon + 0.5)) <=
                      2.2204460492503131E-16 * O_moon);
            }

            if (rEQ0) {
              deps_1980 = 0.0;
            } else {
              if (u_moon < 0.0) {
                deps_1980 += 6.2831853071795862;
              }
            }
          }
        } else {
          deps_1980 = (rtNaN);
        }

        O_moon = deps_1980;
        u_moon = 0.0;
        b_r1 = 0;
        while ((fabs(O_moon - u_moon) > 1.0E-8) && (b_r1 < 10)) {
          O_moon = u_moon;
          u_moon += (((deps_1980 - D_sun * cos(u_moon)) + M_sun * sin(u_moon)) -
                     u_moon) / ((-D_sun * sin(u_moon) - M_sun * cos(u_moon)) +
                                1.0);
          b_r1++;
        }

        d_w = cos(u_moon);
        tsince_JD = sin(u_moon);
        api = M_sun * tsince_JD - D_sun * d_w;
        IL3 = sqrt(M_sun * M_sun + D_sun * D_sun);
        dpsi_1980 = 1.0 - IL3 * IL3;
        deps_1980 = dpsi_1980 * M_moon;
        O_moon = (1.0 - (M_sun * d_w + D_sun * tsince_JD)) * M_moon;
        if ((O_moon == 0.0) || (deps_1980 == 0.0)) {
          rtb_pos_teme_km[0] = 6378.137;
          rtb_vel_teme_kmps[0] = 0.0;
          rtb_pos_teme_km[1] = 6378.137;
          rtb_vel_teme_kmps[1] = 0.0;
          rtb_pos_teme_km[2] = 6878.137;
          rtb_vel_teme_kmps[2] = 0.0;
        } else {
          dpsi_1980 = sqrt(dpsi_1980);
          xi = M_moon / O_moon;
          M_sun = rt_atan2d_snf(((tsince_JD - D_sun) - M_sun * api / (dpsi_1980
            + 1.0)) * xi, (D_sun * api / (dpsi_1980 + 1.0) + (d_w - M_sun)) * xi);
          epsb_1980_tmp = deps_1980 * deps_1980;
          tsince_JD = cos(2.0 * M_sun);
          u_moon = (1.0 - dpsi_1980 * 0.00081196200000000006 * (D_sun_tmp *
                     D_sun_tmp * 3.0 - 1.0) / epsb_1980_tmp) * O_moon +
            0.000541308 / (2.0 * deps_1980) * (1.0 - D_sun_tmp * D_sun_tmp) *
            tsince_JD;
          dpsi_1980 = sin(2.0 * M_sun);
          D_sun = -(0.000541308 / (epsb_1980_tmp * 4.0)) * (D_4_tmp - 1.0) *
            dpsi_1980 + M_sun;
          epsb_1980_tmp = 0.0016239240000000001 * D_sun_tmp / (epsb_1980_tmp *
            2.0);
          epsb_1980 += epsb_1980_tmp * dpsi_1980;
          IL3 = epsb_1980_tmp * sin(b_a21) * tsince_JD + b_a21;
          M_sun = 0.000541308 * (0.0743669161 / rt_powd_snf(M_moon, 1.5)) /
            deps_1980;
          b_a21 = -M_sun * (1.0 - D_sun_tmp * D_sun_tmp) * dpsi_1980 +
            0.0743669161 * sqrt(M_moon) * api / O_moon;
          tsince_JD = ((1.0 - D_sun_tmp * D_sun_tmp) * tsince_JD - (1.0 -
            D_sun_tmp * D_sun_tmp * 3.0) * 1.5) * M_sun + 0.0743669161 * sqrt
            (deps_1980) / O_moon;
          O_moon = cos(IL3);
          M_moon = sin(epsb_1980);
          M[0] = -M_moon * O_moon;
          M_sun = cos(epsb_1980);
          M[1] = M_sun * O_moon;
          M[2] = sin(IL3);
          epsb_1980_tmp = sin(D_sun);
          epsb_1980 = cos(D_sun);
          O_moon = M[0] * epsb_1980_tmp + M_sun * epsb_1980;
          rtb_pos_teme_km[0] = u_moon * O_moon * 6378.137;
          rtb_vel_teme_kmps[0] = O_moon;
          O_moon = M[1] * epsb_1980_tmp + M_moon * epsb_1980;
          rtb_pos_teme_km[1] = u_moon * O_moon * 6378.137;
          rtb_vel_teme_kmps[1] = O_moon;
          O_moon = M[2] * epsb_1980_tmp + 0.0 * epsb_1980;
          rtb_pos_teme_km[2] = u_moon * O_moon * 6378.137;
          rtb_vel_teme_kmps[0] = ((M[0] * epsb_1980 - M_sun * epsb_1980_tmp) *
            tsince_JD + b_a21 * rtb_vel_teme_kmps[0]) * 106.30228333333334;
          rtb_vel_teme_kmps[1] = ((M[1] * epsb_1980 - M_moon * epsb_1980_tmp) *
            tsince_JD + b_a21 * rtb_vel_teme_kmps[1]) * 106.30228333333334;
          rtb_vel_teme_kmps[2] = ((M[2] * epsb_1980 - 0.0 * epsb_1980_tmp) *
            tsince_JD + b_a21 * O_moon) * 106.30228333333334;
        }
      }
    }
  }

  /* End of MATLAB Function: '<S176>/MATLAB Function' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S176>/Gain' incorporates:
     *  Product: '<S176>/Product'
     */
    M[i] = 1000.0 * (rtb_teme_to_gcrf[i + 6] * rtb_pos_teme_km[2] +
                     (rtb_teme_to_gcrf[i + 3] * rtb_pos_teme_km[1] +
                      rtb_teme_to_gcrf[i] * rtb_pos_teme_km[0]));
  }

  /* Product: '<S175>/MatrixMultiply' */
  for (i = 0; i < 3; i++) {
    rtb_pos_teme_km[i] = rtb_Multiply1[i + 6] * M[2] + (rtb_Multiply1[i + 3] *
      M[1] + rtb_Multiply1[i] * M[0]);
  }

  /* End of Product: '<S175>/MatrixMultiply' */

  /* Sqrt: '<S307>/sqrt' incorporates:
   *  Product: '<S307>/Product2'
   *  Product: '<S307>/Product3'
   *  Sum: '<S307>/Sum2'
   */
  M_moon = sqrt(rtb_pos_teme_km[0] * rtb_pos_teme_km[0] + rtb_pos_teme_km[1] *
                rtb_pos_teme_km[1]);

  /* Outputs for Iterator SubSystem: '<S292>/While Iterator Subsystem' */
  WhileIteratorSubsystem(M_moon, rtb_pos_teme_km[2], rtConstB.Product1,
    0.99664718933525254, 0.00669437999014133, rtConstB.Product2_c, &epsb_1980,
    &rtDW.WhileIteratorSubsystem_b);

  /* End of Outputs for SubSystem: '<S292>/While Iterator Subsystem' */

  /* UnitConversion: '<S306>/Unit Conversion' incorporates:
   *  Trigonometry: '<S292>/Trigonometric Function2'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  M_sun = 57.295779513082323 * epsb_1980;
  D_sun = 57.295779513082323 * rt_atan2d_snf(rtb_pos_teme_km[1],
    rtb_pos_teme_km[0]);

  /* UnitConversion: '<S304>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  b_a21 = 0.017453292519943295 * M_sun;

  /* Trigonometry: '<S291>/sincos' */
  O_moon = cos(b_a21);

  /* UnitConversion: '<S304>/Unit Conversion' incorporates:
   *  Trigonometry: '<S291>/sincos'
   */
  deps_1980 = sin(b_a21);
  b_a21 = 0.017453292519943295 * D_sun;

  /* Trigonometry: '<S291>/sincos' */
  dpsi_1980 = cos(b_a21);
  b_a21 = sin(b_a21);

  /* UnaryMinus: '<S295>/Unary Minus' incorporates:
   *  Product: '<S295>/u(1)*u(4)'
   */
  rtb_MathFunction1_d[0] = -(deps_1980 * dpsi_1980);

  /* UnaryMinus: '<S298>/Unary Minus' */
  rtb_MathFunction1_d[1] = -b_a21;

  /* UnaryMinus: '<S301>/Unary Minus' incorporates:
   *  Product: '<S301>/u(3)*u(4)'
   */
  rtb_MathFunction1_d[2] = -(O_moon * dpsi_1980);

  /* UnaryMinus: '<S296>/Unary Minus' incorporates:
   *  Product: '<S296>/u(1)*u(2)'
   */
  rtb_MathFunction1_d[3] = -(deps_1980 * b_a21);

  /* SignalConversion: '<S305>/ConcatBufferAtVector ConcatenateIn5' */
  rtb_MathFunction1_d[4] = dpsi_1980;

  /* UnaryMinus: '<S302>/Unary Minus' incorporates:
   *  Product: '<S302>/u(2)*u(3)'
   */
  rtb_MathFunction1_d[5] = -(b_a21 * O_moon);

  /* SignalConversion: '<S305>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction1_d[6] = O_moon;

  /* SignalConversion: '<S305>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S300>/Constant'
   */
  rtb_MathFunction1_d[7] = 0.0;

  /* UnaryMinus: '<S303>/Unary Minus' */
  rtb_MathFunction1_d[8] = -deps_1980;

  /* Math: '<S175>/Transpose' */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction1_f[3 * i] = rtb_MathFunction1_d[i];
    rtb_MathFunction1_f[1 + 3 * i] = rtb_MathFunction1_d[i + 3];
    rtb_MathFunction1_f[2 + 3 * i] = rtb_MathFunction1_d[i + 6];
  }

  memcpy(&rtb_MathFunction1_d[0], &rtb_MathFunction1_f[0], 9U * sizeof(real_T));

  /* End of Math: '<S175>/Transpose' */

  /* Trigonometry: '<S308>/sincos' */
  tsince_JD = sin(epsb_1980);

  /* Product: '<S308>/Product2' */
  O_moon = tsince_JD * 0.00669437999014133;

  /* Product: '<S308>/Product3' incorporates:
   *  Constant: '<S308>/Constant1'
   *  Constant: '<S308>/f'
   *  Product: '<S308>/Product1'
   *  Sqrt: '<S308>/sqrt'
   *  Sum: '<S308>/Sum'
   */
  b_a21 = 6.378137E+6 / sqrt(1.0 - O_moon * tsince_JD);

  /* Product: '<S308>/Product4' */
  O_moon *= b_a21;

  /* Sum: '<S308>/Sum2' */
  O_moon += rtb_pos_teme_km[2];

  /* Sum: '<S308>/Sum3' incorporates:
   *  Product: '<S308>/Product5'
   *  Product: '<S308>/Product6'
   *  Trigonometry: '<S308>/sincos'
   */
  epsb_1980 = (tsince_JD * O_moon - b_a21) + cos(epsb_1980) * M_moon;

  /* MATLAB Function: '<S175>/MATLAB Function' */
  if ((!rtIsInf(rtb_YMDHMS_UTC_idx_0)) && (!rtIsNaN(rtb_YMDHMS_UTC_idx_0))) {
    if (rtb_YMDHMS_UTC_idx_0 == 0.0) {
      O_moon = 0.0;
    } else {
      O_moon = fmod(rtb_YMDHMS_UTC_idx_0, 4.0);
      if (O_moon == 0.0) {
        O_moon = 0.0;
      } else {
        if (rtb_YMDHMS_UTC_idx_0 < 0.0) {
          O_moon += 4.0;
        }
      }
    }
  } else {
    O_moon = (rtNaN);
  }

  if (O_moon == 0.0) {
    b_a21 = 366.0;
    b_r1 = 29;
  } else {
    b_a21 = 365.25;
    b_r1 = 28;
  }

  if (!(rtb_YMDHMS_UTC_idx_1 == 1.0)) {
    if (rtb_YMDHMS_UTC_idx_1 == 2.0) {
      rtb_YMDHMS_UTC_idx_2 += 31.0;
    } else if (rtb_YMDHMS_UTC_idx_1 == 3.0) {
      rtb_YMDHMS_UTC_idx_2 += 31.0 + (real_T)b_r1;
    } else if (rtb_YMDHMS_UTC_idx_1 == 4.0) {
      rtb_YMDHMS_UTC_idx_2 += (31.0 + (real_T)b_r1) + 31.0;
    } else if (rtb_YMDHMS_UTC_idx_1 == 5.0) {
      rtb_YMDHMS_UTC_idx_2 += ((31.0 + (real_T)b_r1) + 31.0) + 30.0;
    } else if (rtb_YMDHMS_UTC_idx_1 == 6.0) {
      rtb_YMDHMS_UTC_idx_2 += (((31.0 + (real_T)b_r1) + 31.0) + 30.0) + 31.0;
    } else if (rtb_YMDHMS_UTC_idx_1 == 7.0) {
      rtb_YMDHMS_UTC_idx_2 += ((((31.0 + (real_T)b_r1) + 31.0) + 30.0) + 31.0) +
        30.0;
    } else if (rtb_YMDHMS_UTC_idx_1 == 8.0) {
      rtb_YMDHMS_UTC_idx_2 += (((((31.0 + (real_T)b_r1) + 31.0) + 30.0) + 31.0)
        + 30.0) + 31.0;
    } else if (rtb_YMDHMS_UTC_idx_1 == 9.0) {
      rtb_YMDHMS_UTC_idx_2 += ((((((31.0 + (real_T)b_r1) + 31.0) + 30.0) + 31.0)
        + 30.0) + 31.0) + 31.0;
    } else if (rtb_YMDHMS_UTC_idx_1 == 10.0) {
      rtb_YMDHMS_UTC_idx_2 += (((((((31.0 + (real_T)b_r1) + 31.0) + 30.0) + 31.0)
        + 30.0) + 31.0) + 31.0) + 30.0;
    } else if (rtb_YMDHMS_UTC_idx_1 == 11.0) {
      rtb_YMDHMS_UTC_idx_2 += ((((((((31.0 + (real_T)b_r1) + 31.0) + 30.0) +
        31.0) + 30.0) + 31.0) + 31.0) + 30.0) + 31.0;
    } else {
      rtb_YMDHMS_UTC_idx_2 += (((((((((31.0 + (real_T)b_r1) + 31.0) + 30.0) +
        31.0) + 30.0) + 31.0) + 31.0) + 30.0) + 31.0) + 30.0;
    }
  }

  b_a21 = (((rtb_YMDHMS_UTC_idx_3 / 24.0 + rtb_YMDHMS_UTC_idx_2) +
            rtb_YMDHMS_UTC_idx_4 / 1440.0) + rtb_YMDHMS_UTC_idx_5 / 86400.0) /
    b_a21 + rtb_YMDHMS_UTC_idx_0;

  /* End of MATLAB Function: '<S175>/MATLAB Function' */

  /* MATLAB Function: '<S294>/MATLAB Function' */
  tsince_JD = 0.017453292519943295 * M_sun;
  M_moon = 0.017453292519943295 * D_sun;
  D_sun = sin(tsince_JD);
  memset(&sp[0], 0, 13U * sizeof(real_T));
  memset(&cp[0], 0, 13U * sizeof(real_T));
  sp[1] = sin(M_moon);
  cp[0] = 1.0;
  cp[1] = cos(M_moon);
  b_r1 = 3;
  for (b_r2 = 0; b_r2 < 11; b_r2++) {
    b_r1 = 3 + b_r2;
    rtb_YMDHMS_UTC_idx_2 = cp[b_r2 + 1];
    sp[b_r2 + 2] = rtb_YMDHMS_UTC_idx_2 * sp[1] + sp[b_r2 + 1] * cp[1];
    cp[b_r2 + 2] = rtb_YMDHMS_UTC_idx_2 * cp[1] - sp[b_r2 + 1] * sp[1];
  }

  M_moon = 6.378137E+6 / sqrt(1.0 - D_sun * D_sun * 0.0066943799901413165);
  O_moon = (M_moon + epsb_1980) * cos(tsince_JD);
  M_moon = (M_moon * 0.99330562000985867 + epsb_1980) * D_sun;
  O_moon = sqrt(O_moon * O_moon + M_moon * M_moon);
  epsb_1980 = asin(M_moon / O_moon);
  D_sun = sin(epsb_1980);
  M_moon = 6.3712E+6 / O_moon;
  M_sun = M_moon * M_moon;
  memset(&P_0[0], 0, 196U * sizeof(real_T));
  api = sqrt(1.0 - D_sun * D_sun);
  dpsi_1980 = tan(epsb_1980);
  epsb_1980_tmp = 1.0 / cos(epsb_1980);
  P_0[0] = 1.0;
  P_0[1] = D_sun;
  P_0[15] = -api;
  b_r2 = 2;
  for (b_r3 = 0; b_r3 < 12; b_r3++) {
    b_r2 = 2 + b_r3;
    P_0[b_r3 + 2] = (((2.0 + (real_T)b_r3) * 2.0 - 1.0) * D_sun * P_0[b_r3 + 1]
                     - ((2.0 + (real_T)b_r3) - 1.0) * P_0[b_r3]) * (1.0 / (2.0 +
      (real_T)b_r3));
    b_r1 = 1;
    for (b_rtemp = 0; b_rtemp <= b_r3 + 1; b_rtemp++) {
      b_r1 = 1 + b_rtemp;
      i = 14 * b_rtemp + b_r3;
      b_temp_tmp = b_r3 - b_rtemp;
      rtb_YMDHMS_UTC_idx_2 = b_r3 + b_rtemp;
      b_temp_tmp_0 = i + 1;
      b_temp_tmp_2 = i + 2;
      P_0[(b_r3 + 14 * (b_rtemp + 1)) + 2] = ((((real_T)b_temp_tmp + 1.0) + 1.0)
        * D_sun * P_0[b_temp_tmp_2] - ((rtb_YMDHMS_UTC_idx_2 + 3.0) - 1.0) *
        P_0[b_temp_tmp_0]) * (1.0 / api);
      if ((1 + b_rtemp > 1) && (b_temp_tmp + 1 > 0)) {
        deps_1980 = ((real_T)(b_r3 - b_rtemp) - 1.0) + 1.0;
        factorial(&deps_1980);
        O_moon = (rtb_YMDHMS_UTC_idx_2 + 1.0) - 1.0;
        factorial(&O_moon);
        P_0[b_r3 + 14 * b_rtemp] = rt_powd_snf(-1.0, (1.0 + (real_T)b_rtemp) -
          1.0) * sqrt(2.0 * deps_1980 / O_moon) * P_0[i];
      }

      if ((1 + b_rtemp > 1) && (2 + b_r3 == 13)) {
        O_moon = (real_T)(b_r3 - b_rtemp) + 1.0;
        factorial(&O_moon);
        deps_1980 = (rtb_YMDHMS_UTC_idx_2 + 2.0) - 1.0;
        factorial(&deps_1980);
        P_0[(b_r3 + 14 * b_rtemp) + 1] = rt_powd_snf(-1.0, (1.0 + (real_T)
          b_rtemp) - 1.0) * sqrt(2.0 * O_moon / deps_1980) * P_0[b_temp_tmp_0];
        O_moon = ((real_T)(b_r3 - b_rtemp) + 1.0) + 1.0;
        factorial(&O_moon);
        deps_1980 = ((real_T)(b_r3 + b_rtemp) + 3.0) - 1.0;
        factorial(&deps_1980);
        P_0[(b_r3 + 14 * b_rtemp) + 2] = rt_powd_snf(-1.0, (1.0 + (real_T)
          b_rtemp) - 1.0) * sqrt(2.0 * O_moon / deps_1980) * P_0[b_temp_tmp_2];
      }
    }
  }

  deps_1980 = b_r2 - b_r1;
  factorial(&deps_1980);
  O_moon = b_r2 + b_r1;
  factorial(&O_moon);
  P_0[b_r2 + 14 * b_r1] *= sqrt(2.0 * deps_1980 / O_moon) * rt_powd_snf(-1.0,
    (real_T)b_r1);
  O_moon = 0.0;
  D_sun = 0.0;
  deps_1980 = 0.0;
  for (b_r1 = 0; b_r1 < 12; b_r1++) {
    M_sun *= M_moon;
    for (b_r2 = 0; b_r2 <= b_r1 + 1; b_r2++) {
      i = 12 * b_r2 + b_r1;
      api = dg[i] * (b_a21 - 2015.0) + g[i];
      IL3 = dh[i] * (b_a21 - 2015.0) + h[i];
      i = 14 * b_r2 + b_r1;
      D_2 = P_0[i + 1];
      rtb_YMDHMS_UTC_idx_2 = api * cp[b_r2] + IL3 * sp[b_r2];
      O_moon -= (((1.0 + (real_T)b_r1) + 1.0) * dpsi_1980 * D_2 - sqrt((b_r1 + 2)
                  * (b_r1 + 2) - b_r2 * b_r2) * epsb_1980_tmp * P_0[i + 2]) *
        (rtb_YMDHMS_UTC_idx_2 * M_sun);
      D_sun += (api * sp[b_r2] - IL3 * cp[b_r2]) * (M_sun * (real_T)b_r2) * D_2;
      deps_1980 -= ((1.0 + (real_T)b_r1) + 1.0) * M_sun * rtb_YMDHMS_UTC_idx_2 *
        D_2;
    }
  }

  for (i = 0; i < 3; i++) {
    /* Math: '<S175>/Transpose1' incorporates:
     *  Math: '<S174>/Math Function1'
     */
    rtb_MathFunction1_f[3 * i] = rtb_Multiply1[i];
    rtb_MathFunction1_f[1 + 3 * i] = rtb_Multiply1[i + 3];
    rtb_MathFunction1_f[2 + 3 * i] = rtb_Multiply1[i + 6];
  }

  /* MATLAB Function: '<S294>/MATLAB Function' */
  D_2 = epsb_1980 - tsince_JD;
  rtb_YMDHMS_UTC_idx_2 = sin(D_2);
  D_2 = cos(D_2);
  rtb_Gain[0] = D_2 * O_moon - rtb_YMDHMS_UTC_idx_2 * deps_1980;
  rtb_Gain[1] = epsb_1980_tmp * D_sun;
  rtb_Gain[2] = rtb_YMDHMS_UTC_idx_2 * O_moon + D_2 * deps_1980;

  /* UnitDelay: '<S9>/Unit Delay' */
  rtb_UnitDelay_f = rtDW.UnitDelay_DSTATE_j;

  /* MATLAB Function: '<S177>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S178>/MATLAB Function3'
   */
  tsince_JD = mod((35999.05034 * num_dead_MTQ + 357.5277233) *
                  0.017453292519943295);
  b_a21 = (mod((36000.77 * num_dead_MTQ + 280.46) * 0.017453292519943295) +
           0.033417233996490527 * sin(tsince_JD)) + sin(2.0 * tsince_JD) *
    0.00034897235311083654;
  num_dead_MTQ = (23.439291 - 0.0130042 * num_dead_MTQ) * 0.017453292519943295;
  O_moon = (1.000140612 - 0.016708617 * cos(tsince_JD)) - cos(2.0 * tsince_JD) *
    0.000139589;
  rtb_YMDHMS_UTC_idx_2 = O_moon * cos(b_a21);
  rtb_YMDHMS_UTC_idx_5 = sin(b_a21);
  rtb_YMDHMS_UTC_idx_4 = cos(num_dead_MTQ) * rtb_YMDHMS_UTC_idx_5 * O_moon;
  num_dead_MTQ = sin(num_dead_MTQ) * rtb_YMDHMS_UTC_idx_5 * O_moon;
  for (i = 0; i < 3; i++) {
    /* Product: '<S175>/Matrix Multiply1' */
    rtb_Product2_p[i] = 0.0;
    for (b_rtemp = 0; b_rtemp < 3; b_rtemp++) {
      /* Product: '<S175>/Matrix Multiply' incorporates:
       *  Math: '<S175>/Transpose1'
       *  Product: '<S175>/Matrix Multiply1'
       */
      b_r1 = i + 3 * b_rtemp;
      rtb_nT2T_tmp[b_r1] = 0.0;
      b_r2 = 3 * b_rtemp + i;
      rtb_nT2T_tmp[b_r1] = rtb_nT2T_tmp[b_r2] + rtb_MathFunction1_d[3 * b_rtemp]
        * rtb_MathFunction1_f[i];
      rtb_nT2T_tmp[b_r1] = rtb_MathFunction1_d[3 * b_rtemp + 1] *
        rtb_MathFunction1_f[i + 3] + rtb_nT2T_tmp[b_r2];
      rtb_nT2T_tmp[b_r1] = rtb_MathFunction1_d[3 * b_rtemp + 2] *
        rtb_MathFunction1_f[i + 6] + rtb_nT2T_tmp[b_r2];

      /* Product: '<S175>/Matrix Multiply1' */
      rtb_Product2_p[i] += rtb_nT2T_tmp[b_r2] * rtb_Gain[b_rtemp];
    }

    /* Gain: '<S175>/nT2T' */
    rtb_nT2T[i] = 1.0E-9 * rtb_Product2_p[i];

    /* Product: '<S177>/Product' incorporates:
     *  MATLAB Function: '<S322>/MATLAB Function'
     */
    rtb_pos_teme_km[i] = y[i + 6] * num_dead_MTQ + (y[i + 3] *
      rtb_YMDHMS_UTC_idx_4 + y[i] * rtb_YMDHMS_UTC_idx_2);

    /* Product: '<S174>/Product3' incorporates:
     *  Math: '<S174>/Math Function1'
     */
    N[i] = rtb_MathFunction1_f[i + 6] * M[2] + (rtb_MathFunction1_f[i + 3] * M[1]
      + rtb_MathFunction1_f[i] * M[0]);
  }

  /* Outputs for Iterator SubSystem: '<S181>/While Iterator Subsystem' */
  /* Sqrt: '<S188>/sqrt' incorporates:
   *  Product: '<S188>/Product2'
   *  Product: '<S188>/Product3'
   *  Sum: '<S188>/Sum2'
   */
  WhileIteratorSubsystem(sqrt(N[0] * N[0] + N[1] * N[1]), N[2],
    rtConstB.Product1_l, 0.99664718933525254, 0.00669437999014133,
    rtConstB.Product2_c0, &epsb_1980, &rtDW.WhileIteratorSubsystem_h);

  /* End of Outputs for SubSystem: '<S181>/While Iterator Subsystem' */

  /* UnitConversion: '<S187>/Unit Conversion' incorporates:
   *  Trigonometry: '<S181>/Trigonometric Function2'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  M_sun = 57.295779513082323 * epsb_1980;
  D_sun = 57.295779513082323 * rt_atan2d_snf(N[1], N[0]);

  /* RelationalOperator: '<S232>/Compare' incorporates:
   *  Constant: '<S232>/Constant'
   */
  rtb_LogicalOperator_l = false;

  /* UnaryMinus: '<S213>/Unary Minus' incorporates:
   *  Product: '<S213>/u(1)*u(4)'
   */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtb_MathFunction_dj[0] = 0.39379071463723742;

  /* UnaryMinus: '<S216>/Unary Minus' */
  rtb_MathFunction_dj[1] = 0.84520833385785676;

  /* UnaryMinus: '<S219>/Unary Minus' incorporates:
   *  Product: '<S219>/u(3)*u(4)'
   */
  rtb_MathFunction_dj[2] = 0.3613194506841827;

  /* UnaryMinus: '<S214>/Unary Minus' incorporates:
   *  Product: '<S214>/u(1)*u(2)'
   */
  rtb_MathFunction_dj[3] = 0.62277726647305831;

  /* SignalConversion: '<S223>/ConcatBufferAtVector ConcatenateIn5' */
  rtb_MathFunction_dj[4] = -0.5344369676371814;

  /* UnaryMinus: '<S220>/Unary Minus' incorporates:
   *  Product: '<S220>/u(2)*u(3)'
   */
  rtb_MathFunction_dj[5] = 0.57142418918621174;

  /* SignalConversion: '<S223>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction_dj[6] = 0.67607495844014154;

  /* SignalConversion: '<S223>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S218>/Constant'
   */
  rtb_MathFunction_dj[7] = 0.0;

  /* UnaryMinus: '<S221>/Unary Minus' */
  rtb_MathFunction_dj[8] = -0.73683285117464792;

  /* Math: '<S182>/Math Function1' */
  for (i = 0; i < 3; i++) {
    y[3 * i] = rtb_MathFunction_dj[i];
    y[1 + 3 * i] = rtb_MathFunction_dj[i + 3];
    y[2 + 3 * i] = rtb_MathFunction_dj[i + 6];
  }

  memcpy(&rtb_MathFunction_dj[0], &y[0], 9U * sizeof(real_T));

  /* End of Math: '<S182>/Math Function1' */

  /* UnaryMinus: '<S202>/Unary Minus' incorporates:
   *  Product: '<S202>/u(1)*u(4)'
   */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtb_MathFunction1_jx[0] = 0.39499714329391261;

  /* UnaryMinus: '<S205>/Unary Minus' */
  rtb_MathFunction1_jx[1] = 0.84520833385785676;

  /* UnaryMinus: '<S208>/Unary Minus' incorporates:
   *  Product: '<S208>/u(3)*u(4)'
   */
  rtb_MathFunction1_jx[2] = 0.36000017939839135;

  /* UnaryMinus: '<S203>/Unary Minus' incorporates:
   *  Product: '<S203>/u(1)*u(2)'
   */
  rtb_MathFunction1_jx[3] = 0.62468522497251422;

  /* SignalConversion: '<S212>/ConcatBufferAtVector ConcatenateIn5' */
  rtb_MathFunction1_jx[4] = -0.5344369676371814;

  /* UnaryMinus: '<S209>/Unary Minus' */
  rtb_MathFunction1_jx[5] = 0.56933777085646931;

  /* SignalConversion: '<S212>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_MathFunction1_jx[6] = 0.67360643293446032;

  /* SignalConversion: '<S212>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S207>/Constant'
   */
  rtb_MathFunction1_jx[7] = 0.0;

  /* UnaryMinus: '<S210>/Unary Minus' */
  rtb_MathFunction1_jx[8] = -0.73909023367198712;

  /* Math: '<S182>/Math Function' */
  for (i = 0; i < 3; i++) {
    y[3 * i] = rtb_MathFunction1_jx[i];
    y[1 + 3 * i] = rtb_MathFunction1_jx[i + 3];
    y[2 + 3 * i] = rtb_MathFunction1_jx[i + 6];
  }

  memcpy(&rtb_MathFunction1_jx[0], &y[0], 9U * sizeof(real_T));

  /* End of Math: '<S182>/Math Function' */

  /* MATLAB Function: '<S179>/MATLAB Function1' incorporates:
   *  Constant: '<S179>/Constant'
   *  Constant: '<S179>/Constant1'
   *  Constant: '<S179>/Constant2'
   *  Constant: '<S179>/Constant3'
   *  Constant: '<S179>/Constant4'
   */
  if ((M_sun < 62.653975) && (M_sun > 32.653975) && (D_sun > -133.555736) &&
      (D_sun < -118.555736)) {
    rtb_LogicalOperator_l = true;
  }

  for (i = 0; i < 3; i++) {
    /* MATLAB Function: '<S179>/MATLAB Function1' incorporates:
     *  Product: '<S182>/Product'
     *  Product: '<S182>/Product1'
     *  Sum: '<S182>/Sum'
     */
    rtb_Gain[i] = ((rtb_MathFunction_dj[i + 6] * -6.3665000424680039E+6 +
                    (rtb_MathFunction_dj[i + 3] * 0.0 + rtb_MathFunction_dj[i] *
                     0.0)) + (rtb_MathFunction1_jx[i + 6] * -44.0 +
      (rtb_MathFunction1_jx[i + 3] * 0.0 + rtb_MathFunction1_jx[i] * 0.0))) -
      N[i];
  }

  /* MATLAB Function: '<S179>/MATLAB Function1' */
  api = norm(rtb_Gain);
  num_dead_MTQ = rtb_Gain[0] / api;
  rtb_YMDHMS_UTC_idx_2 = rtb_Gain[1] / api;
  rtb_YMDHMS_UTC_idx_4 = rtb_Gain[2] / api;
  for (i = 0; i < 3; i++) {
    /* Math: '<S332>/Math Function' incorporates:
     *  Gain: '<S10>/Gain'
     */
    rtb_MathFunction[i] = -M[i] * -M[i];

    /* Gain: '<S10>/Gain' */
    rtb_Gain[i] = -M[i];

    /* Product: '<S174>/Product2' */
    rtb_Product2_p[i] = rtb_Multiply1[i + 6] * rtb_YMDHMS_UTC_idx_4 +
      (rtb_Multiply1[i + 3] * rtb_YMDHMS_UTC_idx_2 + rtb_Multiply1[i] *
       num_dead_MTQ);
  }

  /* Sum: '<S332>/Sum of Elements' */
  num_dead_MTQ = (rtb_MathFunction[0] + rtb_MathFunction[1]) + rtb_MathFunction
    [2];

  /* Math: '<S332>/Math Function1'
   *
   * About '<S332>/Math Function1':
   *  Operator: sqrt
   */
  if (num_dead_MTQ < 0.0) {
    num_dead_MTQ = -sqrt(fabs(num_dead_MTQ));
  } else {
    num_dead_MTQ = sqrt(num_dead_MTQ);
  }

  /* End of Math: '<S332>/Math Function1' */

  /* Switch: '<S332>/Switch' incorporates:
   *  Constant: '<S332>/Constant'
   *  Product: '<S332>/Product'
   */
  if (num_dead_MTQ > 0.0) {
    rtb_Transpose[0] = rtb_Gain[0];
    rtb_Transpose[1] = rtb_Gain[1];
    rtb_Transpose[2] = rtb_Gain[2];
    rtb_Transpose[3] = num_dead_MTQ;
  } else {
    rtb_Transpose[0] = rtb_Gain[0] * 0.0;
    rtb_Transpose[1] = rtb_Gain[1] * 0.0;
    rtb_Transpose[2] = rtb_Gain[2] * 0.0;
    rtb_Transpose[3] = 1.0;
  }

  /* End of Switch: '<S332>/Switch' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S332>/Divide' */
    rtb_Gain[i] = rtb_Transpose[i] / rtb_Transpose[3];

    /* Gain: '<S176>/Gain3' incorporates:
     *  Product: '<S176>/Product1'
     */
    rtb_MathFunction[i] = 1000.0 * (rtb_teme_to_gcrf[i + 6] * rtb_vel_teme_kmps
      [2] + (rtb_teme_to_gcrf[i + 3] * rtb_vel_teme_kmps[1] + rtb_teme_to_gcrf[i]
             * rtb_vel_teme_kmps[0]));
  }

  /* Sum: '<S331>/Sum of Elements' incorporates:
   *  Math: '<S331>/Math Function'
   */
  num_dead_MTQ = (rtb_MathFunction[0] * rtb_MathFunction[0] + rtb_MathFunction[1]
                  * rtb_MathFunction[1]) + rtb_MathFunction[2] *
    rtb_MathFunction[2];

  /* Math: '<S331>/Math Function1'
   *
   * About '<S331>/Math Function1':
   *  Operator: sqrt
   */
  if (num_dead_MTQ < 0.0) {
    num_dead_MTQ = -sqrt(fabs(num_dead_MTQ));
  } else {
    num_dead_MTQ = sqrt(num_dead_MTQ);
  }

  /* End of Math: '<S331>/Math Function1' */

  /* Switch: '<S331>/Switch' incorporates:
   *  Constant: '<S331>/Constant'
   *  Product: '<S331>/Product'
   */
  if (num_dead_MTQ > 0.0) {
    rtb_Transpose[0] = rtb_MathFunction[0];
    rtb_Transpose[1] = rtb_MathFunction[1];
    rtb_Transpose[2] = rtb_MathFunction[2];
    rtb_Transpose[3] = num_dead_MTQ;
  } else {
    rtb_Transpose[0] = rtb_MathFunction[0] * 0.0;
    rtb_Transpose[1] = rtb_MathFunction[1] * 0.0;
    rtb_Transpose[2] = rtb_MathFunction[2] * 0.0;
    rtb_Transpose[3] = 1.0;
  }

  /* End of Switch: '<S331>/Switch' */

  /* MATLAB Function: '<S10>/target_gen_logic_nadir' incorporates:
   *  Product: '<S331>/Divide'
   */
  b_r1 = 0;
  api = norm(rtb_pos_teme_km);
  guard1 = false;
  if (api < 0.001) {
    guard1 = true;
  } else {
    D_sun = norm(rtb_Product2_p);
    if (D_sun < 0.001) {
      guard1 = true;
    } else {
      rtb_MathFunction[0] = rtb_pos_teme_km[0] / api;
      num_dead_MTQ = rtb_Product2_p[0] / D_sun;
      O_moon = rtb_Transpose[0] / rtb_Transpose[3] * num_dead_MTQ;
      sc2gs_unit[0] = num_dead_MTQ;
      rtb_MathFunction[1] = rtb_pos_teme_km[1] / api;
      num_dead_MTQ = rtb_Product2_p[1] / D_sun;
      O_moon += rtb_Transpose[1] / rtb_Transpose[3] * num_dead_MTQ;
      sc2gs_unit[1] = num_dead_MTQ;
      rtb_MathFunction[2] = rtb_pos_teme_km[2] / api;
      num_dead_MTQ = rtb_Product2_p[2] / D_sun;
      O_moon += rtb_Transpose[2] / rtb_Transpose[3] * num_dead_MTQ;
      sc2gs_unit[2] = num_dead_MTQ;
      if (fabs(O_moon) > 0.999) {
        b_r1 = -1;
      } else {
        if (fabs((rtb_MathFunction[0] * sc2gs_unit[0] + rtb_MathFunction[1] *
                  sc2gs_unit[1]) + rtb_MathFunction[2] * num_dead_MTQ) > 0.999)
        {
          b_r1 = -1;
        }
      }
    }
  }

  if (guard1) {
    rtb_MathFunction[0] = 0.0;
    sc2gs_unit[0] = 0.0;
    rtb_MathFunction[1] = 0.0;
    sc2gs_unit[1] = 0.0;
    rtb_MathFunction[2] = 0.0;
    sc2gs_unit[2] = 0.0;
    b_r1 = -1;
  }

  if ((rtb_UnitDelay_f == 52) && (b_r1 == 0)) {
    align_vecs(b, sc2gs_unit, d_0, rtb_MathFunction, rtb_MathFunction1_d);
  } else if (((rtb_UnitDelay_f == 42) || (rtb_UnitDelay_f == 51)) && (b_r1 == 0))
  {
    align_vecs(d_0, rtb_MathFunction, e, rtb_Gain, rtb_MathFunction1_d);
  } else {
    memset(&rtb_MathFunction1_d[0], 0, 9U * sizeof(real_T));
    rtb_MathFunction1_d[0] = 1.0;
    rtb_MathFunction1_d[4] = 1.0;
    rtb_MathFunction1_d[8] = 1.0;
  }

  /* End of MATLAB Function: '<S10>/target_gen_logic_nadir' */

  /* Sum: '<S337>/Add' */
  rtb_vel_teme_kmps[0] = rtb_MathFunction1_d[0];
  rtb_vel_teme_kmps[1] = rtb_MathFunction1_d[4];
  rtb_vel_teme_kmps[2] = rtb_MathFunction1_d[8];
  b_a21 = (rtb_MathFunction1_d[0] + rtb_MathFunction1_d[4]) +
    rtb_MathFunction1_d[8];

  /* If: '<S330>/If' */
  if (b_a21 > 0.0) {
    /* Outputs for IfAction SubSystem: '<S330>/Positive Trace' incorporates:
     *  ActionPort: '<S335>/Action Port'
     */
    PositiveTrace(b_a21, rtb_MathFunction1_d, &rtDW.Merge[0], &rtDW.Merge[1]);

    /* End of Outputs for SubSystem: '<S330>/Positive Trace' */
  } else {
    /* Outputs for IfAction SubSystem: '<S330>/Negative Trace' incorporates:
     *  ActionPort: '<S334>/Action Port'
     */
    NegativeTrace(rtb_MathFunction1_d, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S330>/Negative Trace' */
  }

  /* End of If: '<S330>/If' */

  /* Trigonometry: '<S11>/Tan1' incorporates:
   *  Gain: '<S11>/deg2rad'
   *  Inport: '<Root>/sensor_meas'
   */
  num_dead_MTQ = tan(0.017453292519943295 * rtU.sensor_meas.sun_meas_ss_deg[0]);

  /* Trigonometry: '<S11>/Tan' incorporates:
   *  Gain: '<S11>/deg2rad'
   *  Inport: '<Root>/sensor_meas'
   */
  b_a21 = tan(0.017453292519943295 * rtU.sensor_meas.sun_meas_ss_deg[1]);

  /* Sqrt: '<S12>/Sqrt' incorporates:
   *  Constant: '<S12>/Constant'
   *  Math: '<S12>/Math Function'
   *  Math: '<S12>/Math Function1'
   *  Math: '<S12>/Math Function2'
   *  Sum: '<S12>/Sum'
   *
   * About '<S12>/Math Function2':
   *  Operator: reciprocal
   */
  tsince_JD = sqrt(1.0 / ((num_dead_MTQ * num_dead_MTQ + 1.0) + b_a21 * b_a21));

  /* SignalConversion: '<S11>/TmpSignal ConversionAtss->bodyInport2' incorporates:
   *  Product: '<S11>/Matrix Multiply'
   *  Product: '<S11>/Matrix Multiply1'
   */
  num_dead_MTQ *= tsince_JD;
  rtb_YMDHMS_UTC_idx_2 = tsince_JD * b_a21;

  /* Product: '<S11>/ss->body' incorporates:
   *  Constant: '<S11>/Constant1'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtss->bodyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Gain[i] = rtConstP.Constant1_Value_hk[i + 6] * tsince_JD +
      (rtConstP.Constant1_Value_hk[i + 3] * rtb_YMDHMS_UTC_idx_2 +
       rtConstP.Constant1_Value_hk[i] * num_dead_MTQ);
  }

  /* End of Product: '<S11>/ss->body' */

  /* S-Function (sdspperm2): '<S2>/Variable Selector1' incorporates:
   *  Inport: '<Root>/sensor_meas'
   */
  rtb_VariableSelector1[0] = rtU.sensor_meas.mag_body_T[0];
  rtb_VariableSelector1[1] = rtU.sensor_meas.mag_body_T[1];
  rtb_VariableSelector1[2] = rtU.sensor_meas.mag_body_T[2];

  /* S-Function (sdspperm2): '<S2>/Variable Selector' incorporates:
   *  Inport: '<Root>/sensor_meas'
   */
  rtb_VariableSelector[0] = rtU.sensor_meas.gyro_body_radps[0];
  rtb_VariableSelector[1] = rtU.sensor_meas.gyro_body_radps[1];
  rtb_VariableSelector[2] = rtU.sensor_meas.gyro_body_radps[2];

  /* Outputs for Atomic SubSystem: '<S1>/MEKF_lib' */
  /* Inport: '<Root>/sensor_meas' incorporates:
   *  Inport: '<Root>/telecommands'
   *  S-Function (sdspperm2): '<S2>/Variable Selector2'
   *  S-Function (sdspperm2): '<S2>/Variable Selector3'
   */
  MEKF_libTID0(rtM, rtb_pos_teme_km, rtb_nT2T, rtb_Gain, rtb_VariableSelector1,
               rtb_VariableSelector, rtU.sensor_meas.sun_meas_valid,
               rtU.sensor_meas.mag_meas_valid[0],
               rtU.sensor_meas.gyro_meas_valid[0],
               rtU.telecommands.triad_override, rtDW.qmerge, rtb_vel_teme_kmps,
               rtb_MathFunction, rtb_Product2_p, &rtDW.MEKF_lib_g);

  /* End of Outputs for SubSystem: '<S1>/MEKF_lib' */

  /* Sum: '<S160>/Sum' incorporates:
   *  Math: '<S10>/Transpose'
   *  Product: '<S160>/Product'
   *  Product: '<S160>/Product1'
   *  Product: '<S160>/Product2'
   *  Product: '<S160>/Product3'
   *  UnaryMinus: '<S158>/Unary Minus'
   *  UnaryMinus: '<S158>/Unary Minus1'
   *  UnaryMinus: '<S158>/Unary Minus2'
   */
  num_dead_MTQ = ((rtDW.Merge[0] * rtDW.qmerge[0] - -rtDW.Merge[1] *
                   rtDW.qmerge[1]) - -rtDW.Merge[2] * rtDW.qmerge[2]) -
    -rtDW.Merge[3] * rtDW.qmerge[3];

  /* Signum: '<S115>/Sign' */
  if (num_dead_MTQ < 0.0) {
    b_a21 = -1.0;
  } else if (num_dead_MTQ > 0.0) {
    b_a21 = 1.0;
  } else if (num_dead_MTQ == 0.0) {
    b_a21 = 0.0;
  } else {
    b_a21 = (rtNaN);
  }

  /* End of Signum: '<S115>/Sign' */

  /* Product: '<S115>/Multiply' incorporates:
   *  Math: '<S10>/Transpose'
   *  Product: '<S161>/Product'
   *  Product: '<S161>/Product1'
   *  Product: '<S161>/Product2'
   *  Product: '<S161>/Product3'
   *  Product: '<S162>/Product'
   *  Product: '<S162>/Product1'
   *  Product: '<S162>/Product2'
   *  Product: '<S162>/Product3'
   *  Product: '<S163>/Product'
   *  Product: '<S163>/Product1'
   *  Product: '<S163>/Product2'
   *  Product: '<S163>/Product3'
   *  Sum: '<S161>/Sum'
   *  Sum: '<S162>/Sum'
   *  Sum: '<S163>/Sum'
   *  UnaryMinus: '<S158>/Unary Minus'
   *  UnaryMinus: '<S158>/Unary Minus1'
   *  UnaryMinus: '<S158>/Unary Minus2'
   */
  rtb_Multiply[0] = b_a21 * num_dead_MTQ;
  rtb_Multiply[1] = (((rtDW.Merge[0] * rtDW.qmerge[1] + -rtDW.Merge[1] *
                       rtDW.qmerge[0]) + -rtDW.Merge[2] * rtDW.qmerge[3]) -
                     -rtDW.Merge[3] * rtDW.qmerge[2]) * b_a21;
  rtb_Multiply[2] = (((rtDW.Merge[0] * rtDW.qmerge[2] - -rtDW.Merge[1] *
                       rtDW.qmerge[3]) + -rtDW.Merge[2] * rtDW.qmerge[0]) +
                     -rtDW.Merge[3] * rtDW.qmerge[1]) * b_a21;
  rtb_Multiply[3] = (((rtDW.Merge[0] * rtDW.qmerge[3] + -rtDW.Merge[1] *
                       rtDW.qmerge[2]) - -rtDW.Merge[2] * rtDW.qmerge[1]) +
                     -rtDW.Merge[3] * rtDW.qmerge[0]) * b_a21;

  /* Trigonometry: '<S114>/Acos' */
  if (rtb_Multiply[0] > 1.0) {
    rtb_YMDHMS_UTC_idx_4 = 1.0;
  } else if (rtb_Multiply[0] < -1.0) {
    rtb_YMDHMS_UTC_idx_4 = -1.0;
  } else {
    rtb_YMDHMS_UTC_idx_4 = rtb_Multiply[0];
  }

  /* Abs: '<S114>/Abs' incorporates:
   *  Gain: '<S114>/Gain'
   *  Gain: '<S114>/RAD2DEG'
   *  Trigonometry: '<S114>/Acos'
   */
  epsb_1980 = fabs(2.0 * acos(rtb_YMDHMS_UTC_idx_4) * 57.295779513082323);

  /* Relay: '<S6>/Relay' */
  if (epsb_1980 >= 3.5) {
    rtDW.Relay_Mode = true;
  } else {
    if (epsb_1980 <= 1.5) {
      rtDW.Relay_Mode = false;
    }
  }

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  Relay: '<S6>/Relay'
   */
  b_r1 = 0;
  b_a21 = 0.0;
  b_r2 = 0;
  b_r3 = 0;
  if ((rtb_UnitDelay_f != 1) && (rtb_UnitDelay_f != 2)) {
    guard1 = false;
    if (rtb_UnitDelay_f == 3) {
      b_r1 = 1;
      guard1 = true;
    } else if (rtb_UnitDelay_f == 41) {
      b_a21 = 1.0;
      b_r1 = 1;
    } else {
      if ((rtb_UnitDelay_f == 42) || (rtb_UnitDelay_f == 51) || (rtb_UnitDelay_f
           == 52) || (rtb_UnitDelay_f == 53)) {
        b_r2 = 1;
        if (rtDW.Relay_Mode) {
          b_r3 = 1;
          b_r2 = 0;
        }
      }

      guard1 = true;
    }

    if (guard1) {
      if ((b_r1 + b_r2) + b_r3 > 1) {
        b_r1 = 1;
        b_r2 = 0;
        b_r3 = 0;
      }
    }
  }

  /* RateTransition: '<S4>/Rate Transition5' incorporates:
   *  Inport: '<Root>/act_meas'
   */
  rtb_Transpose[0] = rtU.act_meas.rwa_rpm[0];
  rtb_Transpose[1] = rtU.act_meas.rwa_rpm[1];
  rtb_Transpose[2] = rtU.act_meas.rwa_rpm[2];
  rtb_Transpose[3] = rtU.act_meas.rwa_rpm[3];

  /* If: '<S112>/If' incorporates:
   *  Inport: '<S144>/In1'
   *  Product: '<S145>/Multiply'
   *  Product: '<S147>/Divide1'
   */
  if (b_a21 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    /* Sum: '<S145>/Subtract' incorporates:
     *  Constant: '<S145>/rwa_inertia_matrix'
     *  Constant: '<S145>/wheel_momentum_target'
     *  Gain: '<S145>/RPM2RPS'
     *  Gain: '<S145>/RPM2RPS1'
     *  Inport: '<Root>/act_meas'
     *  Product: '<S145>/Matrix Multiply1'
     *  RateTransition: '<S4>/Rate Transition5'
     */
    for (i = 0; i < 4; i++) {
      tmp_1[i] = (((0.10471975511965977 * rtU.act_meas.rwa_rpm[0] *
                    rtConstP.pooled23[i] + rtConstP.pooled23[i + 4] *
                    (0.10471975511965977 * rtU.act_meas.rwa_rpm[1])) +
                   rtConstP.pooled23[i + 8] * (0.10471975511965977 *
        rtU.act_meas.rwa_rpm[2])) + rtConstP.pooled23[i + 12] *
                  (0.10471975511965977 * rtU.act_meas.rwa_rpm[3])) -
        0.10471975511965977 * rtConstP.pooled26[i];
    }

    /* End of Sum: '<S145>/Subtract' */

    /* Product: '<S145>/Matrix Multiply' incorporates:
     *  MATLAB Function: '<S5>/MATLAB Function'
     */
    for (i = 0; i < 3; i++) {
      num_dead_MTQ = RWA_A[i + 9] * tmp_1[3] + (RWA_A[i + 6] * tmp_1[2] +
        (RWA_A[i + 3] * tmp_1[1] + RWA_A[i] * tmp_1[0]));
      rtb_Product2_p[i] = num_dead_MTQ;
    }

    /* End of Product: '<S145>/Matrix Multiply' */

    /* Product: '<S146>/Element product' */
    rtb_YMDHMS_UTC_idx_2 = rtb_nT2T[0] * rtb_Product2_p[1];
    rtb_YMDHMS_UTC_idx_4 = rtb_nT2T[0] * rtb_Product2_p[2];
    rtb_YMDHMS_UTC_idx_5 = rtb_nT2T[1] * rtb_Product2_p[0];

    /* Sum: '<S148>/div by zero protection' incorporates:
     *  Constant: '<S148>/small'
     *  DotProduct: '<S154>/Dot Product'
     *  Sqrt: '<S154>/Sqrt'
     */
    rtb_YMDHMS_UTC_idx_1 = sqrt((rtb_nT2T[0] * rtb_nT2T[0] + rtb_nT2T[1] *
      rtb_nT2T[1]) + rtb_nT2T[2] * rtb_nT2T[2]) + 1.0E-8;

    /* Math: '<S145>/Square' */
    rtb_YMDHMS_UTC_idx_1 *= rtb_YMDHMS_UTC_idx_1;

    /* Product: '<S145>/Divide' incorporates:
     *  Product: '<S146>/Element product'
     *  Sum: '<S146>/Add3'
     */
    rtb_nT2T[0] = (rtb_nT2T[1] * rtb_Product2_p[2] - rtb_nT2T[2] *
                   rtb_Product2_p[1]) / rtb_YMDHMS_UTC_idx_1;
    rtb_nT2T[1] = (rtb_nT2T[2] * rtb_Product2_p[0] - rtb_YMDHMS_UTC_idx_4) /
      rtb_YMDHMS_UTC_idx_1;
    rtb_nT2T[2] = (rtb_YMDHMS_UTC_idx_2 - rtb_YMDHMS_UTC_idx_5) /
      rtb_YMDHMS_UTC_idx_1;

    /* Product: '<S147>/Matrix Multiply' incorporates:
     *  Constant: '<S147>/Constant'
     */
    for (i = 0; i < 5; i++) {
      tmp_2[i] = rtConstP.pooled24[i + 10] * rtb_nT2T[2] + (rtConstP.pooled24[i
        + 5] * rtb_nT2T[1] + rtConstP.pooled24[i] * rtb_nT2T[0]);
    }

    /* End of Product: '<S147>/Matrix Multiply' */
    for (i = 0; i < 5; i++) {
      /* Product: '<S147>/Matrix Multiply1' incorporates:
       *  Constant: '<S147>/Constant1'
       */
      tmp_3[i] = 0.0;
      for (b_rtemp = 0; b_rtemp < 5; b_rtemp++) {
        tmp_3[i] += rtConstP.Constant1_Value_h[5 * b_rtemp + i] * tmp_2[b_rtemp];
      }

      /* End of Product: '<S147>/Matrix Multiply1' */

      /* Abs: '<S147>/Abs' */
      rtb_Abs[i] = fabs(tmp_3[i]);
    }

    /* MinMax: '<S147>/Max' */
    if ((rtb_Abs[0] > rtb_Abs[1]) || rtIsNaN(rtb_Abs[1])) {
      rtb_YMDHMS_UTC_idx_1 = rtb_Abs[0];
    } else {
      rtb_YMDHMS_UTC_idx_1 = rtb_Abs[1];
    }

    if ((!(rtb_YMDHMS_UTC_idx_1 > rtb_Abs[2])) && (!rtIsNaN(rtb_Abs[2]))) {
      rtb_YMDHMS_UTC_idx_1 = rtb_Abs[2];
    }

    if ((!(rtb_YMDHMS_UTC_idx_1 > rtb_Abs[3])) && (!rtIsNaN(rtb_Abs[3]))) {
      rtb_YMDHMS_UTC_idx_1 = rtb_Abs[3];
    }

    if ((!(rtb_YMDHMS_UTC_idx_1 > rtb_Abs[4])) && (!rtIsNaN(rtb_Abs[4]))) {
      rtb_YMDHMS_UTC_idx_1 = rtb_Abs[4];
    }

    /* Sum: '<S150>/div by zero protection' incorporates:
     *  Constant: '<S150>/small'
     *  DotProduct: '<S153>/Dot Product'
     *  MinMax: '<S147>/Max'
     *  Sqrt: '<S153>/Sqrt'
     */
    num_dead_MTQ = sqrt(rtb_YMDHMS_UTC_idx_1 * rtb_YMDHMS_UTC_idx_1) + 1.0E-8;

    /* If: '<S149>/If3' incorporates:
     *  Abs: '<S149>/Abs1'
     *  Constant: '<S149>/Constant2'
     *  Constant: '<S149>/Constant3'
     *  Constant: '<S149>/Constant4'
     *  Inport: '<S155>/In1'
     *  Inport: '<S156>/In1'
     *  Product: '<S149>/Divide'
     *  Sum: '<S149>/Sum of Elements'
     */
    if ((fabs(rtb_Product2_p[0]) + fabs(rtb_Product2_p[1])) /
        0.0012367821958652297 > 1.0) {
      /* Outputs for IfAction SubSystem: '<S149>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S156>/Action Port'
       */
      rtb_YMDHMS_UTC_idx_0 = 1.0;

      /* End of Outputs for SubSystem: '<S149>/If Action Subsystem9' */
    } else {
      /* Outputs for IfAction SubSystem: '<S149>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S155>/Action Port'
       */
      rtb_YMDHMS_UTC_idx_0 = 0.125;

      /* End of Outputs for SubSystem: '<S149>/If Action Subsystem10' */
    }

    /* End of If: '<S149>/If3' */

    /* If: '<S147>/If3' incorporates:
     *  MinMax: '<S147>/Max'
     *  Product: '<S147>/Divide1'
     */
    rEQ0 = (rtb_YMDHMS_UTC_idx_1 > 1.0);
    if (rEQ0) {
      rtb_YMDHMS_UTC_idx_1 = rtb_nT2T[0] / num_dead_MTQ;
    } else {
      rtb_YMDHMS_UTC_idx_1 = rtb_nT2T[0];
    }

    rtb_nT2T[0] = rtb_YMDHMS_UTC_idx_1 * rtb_YMDHMS_UTC_idx_0;

    /* If: '<S147>/If3' incorporates:
     *  Product: '<S145>/Multiply'
     *  Product: '<S147>/Divide1'
     */
    if (rEQ0) {
      rtb_YMDHMS_UTC_idx_1 = rtb_nT2T[1] / num_dead_MTQ;
    } else {
      rtb_YMDHMS_UTC_idx_1 = rtb_nT2T[1];
    }

    rtb_nT2T[1] = rtb_YMDHMS_UTC_idx_1 * rtb_YMDHMS_UTC_idx_0;

    /* If: '<S147>/If3' incorporates:
     *  Product: '<S145>/Multiply'
     *  Product: '<S147>/Divide1'
     */
    if (rEQ0) {
      rtb_YMDHMS_UTC_idx_1 = rtb_nT2T[2] / num_dead_MTQ;
    } else {
      rtb_YMDHMS_UTC_idx_1 = rtb_nT2T[2];
    }

    rtb_nT2T[2] = rtb_YMDHMS_UTC_idx_1 * rtb_YMDHMS_UTC_idx_0;

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    rtb_nT2T[0] = 0.0;
    rtb_nT2T[1] = 0.0;
    rtb_nT2T[2] = 0.0;

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem1' */
  }

  /* End of If: '<S112>/If' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  for (i = 0; i < 4; i++) {
    /* Product: '<S157>/Product' incorporates:
     *  Constant: '<S157>/Constant'
     *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator'
     */
    api = rtConstP.Constant_Value_h[i + 12] *
      rtDW.DiscreteTimeIntegrator_DSTATE[3] + (rtConstP.Constant_Value_h[i + 8] *
      rtDW.DiscreteTimeIntegrator_DSTATE[2] + (rtConstP.Constant_Value_h[i + 4] *
      rtDW.DiscreteTimeIntegrator_DSTATE[1] + rtConstP.Constant_Value_h[i] *
      rtDW.DiscreteTimeIntegrator_DSTATE[0]));

    /* Saturate: '<S157>/Saturation' incorporates:
     *  Gain: '<S157>/radps_2_rpm'
     */
    num_dead_MTQ = 9.5492965855137211 * api;
    if (num_dead_MTQ > 6500.0) {
      num_dead_MTQ = 6500.0;
    } else {
      if (num_dead_MTQ < -6500.0) {
        num_dead_MTQ = -6500.0;
      }
    }

    /* End of Saturate: '<S157>/Saturation' */

    /* Product: '<S6>/Multiply' incorporates:
     *  Inport: '<Root>/act_meas'
     *  RateTransition: '<S4>/Rate Transition1'
     */
    rtY.fsw_out_j.rwa_cmd_rpm[i] = (real_T)rtU.act_meas.rwa_valid[i] *
      num_dead_MTQ;
  }

  for (i = 0; i < 5; i++) {
    /* Product: '<S6>/Multiply1' incorporates:
     *  Inport: '<Root>/act_meas'
     *  Product: '<S6>/Matrix Multiply1'
     */
    rtb_Multiply1[i] = (real_T)rtU.act_meas.mtq_valid[i] * (b_temp[i + 10] *
      rtb_nT2T[2] + (b_temp[i + 5] * rtb_nT2T[1] + b_temp[i] * rtb_nT2T[0]));
  }

  /* MATLAB Function: '<S107>/Desat_control_logic' incorporates:
   *  Constant: '<S107>/Constant'
   *  Constant: '<S107>/Constant1'
   *  Inport: '<Root>/act_meas'
   *  MATLAB Function: '<S5>/MATLAB Function'
   *  Product: '<S107>/Matrix Multiply'
   *  RateTransition: '<S4>/Rate Transition5'
   */
  for (i = 0; i < 4; i++) {
    momentum_error_wheel[i] = (((rtConstP.pooled23[i + 4] *
      rtU.act_meas.rwa_rpm[1] + rtConstP.pooled23[i] * rtU.act_meas.rwa_rpm[0])
      + rtConstP.pooled23[i + 8] * rtU.act_meas.rwa_rpm[2]) +
      rtConstP.pooled23[i + 12] * rtU.act_meas.rwa_rpm[3]) - rtConstP.pooled26[i];
  }

  for (i = 0; i < 3; i++) {
    rtb_YMDHMS_UTC_idx_1 = RWA_A[i + 9] * momentum_error_wheel[3] + (RWA_A[i + 6]
      * momentum_error_wheel[2] + (RWA_A[i + 3] * momentum_error_wheel[1] +
      RWA_A[i] * momentum_error_wheel[0]));
    rtb_nT2T[i] = rtb_YMDHMS_UTC_idx_1;
  }

  rtb_YMDHMS_UTC_idx_4 = 0.0;
  num_dead_MTQ = 0.0;
  rtb_YMDHMS_UTC_idx_2 = 0.0;
  rtb_YMDHMS_UTC_idx_5 = 0.0;
  if (b_a21 != 0.0) {
    rtb_Product2_p[0] = fabs(rtb_nT2T[0]);
    rtb_Product2_p[1] = fabs(rtb_nT2T[1]);
    rtb_Product2_p[2] = fabs(rtb_nT2T[2]);
    if (!rtIsNaN(rtb_Product2_p[0])) {
      b_rtemp = 1;
    } else {
      b_rtemp = 0;
      i = 2;
      exitg1 = false;
      while ((!exitg1) && (i < 4)) {
        if (!rtIsNaN(rtb_Product2_p[i - 1])) {
          b_rtemp = i;
          exitg1 = true;
        } else {
          i++;
        }
      }
    }

    if (b_rtemp == 0) {
      rtb_YMDHMS_UTC_idx_0 = rtb_Product2_p[0];
    } else {
      rtb_YMDHMS_UTC_idx_0 = rtb_Product2_p[b_rtemp - 1];
      while (b_rtemp + 1 < 4) {
        if (rtb_YMDHMS_UTC_idx_0 < rtb_Product2_p[b_rtemp]) {
          rtb_YMDHMS_UTC_idx_0 = rtb_Product2_p[b_rtemp];
        }

        b_rtemp++;
      }
    }

    if ((rtb_YMDHMS_UTC_idx_0 < 0.0012367821958652297) || (rtDW.UnitDelay_DSTATE
         != 0.0)) {
      if (momentum_error_wheel[0] < 0.0) {
        rtb_YMDHMS_UTC_idx_5 = -1.0;
      } else if (momentum_error_wheel[0] > 0.0) {
        rtb_YMDHMS_UTC_idx_5 = 1.0;
      } else if (momentum_error_wheel[0] == 0.0) {
        rtb_YMDHMS_UTC_idx_5 = 0.0;
      } else {
        rtb_YMDHMS_UTC_idx_5 = (rtNaN);
      }

      rtb_YMDHMS_UTC_idx_4 = -rtb_YMDHMS_UTC_idx_5;
      if (momentum_error_wheel[1] < 0.0) {
        rtb_YMDHMS_UTC_idx_5 = -1.0;
      } else if (momentum_error_wheel[1] > 0.0) {
        rtb_YMDHMS_UTC_idx_5 = 1.0;
      } else if (momentum_error_wheel[1] == 0.0) {
        rtb_YMDHMS_UTC_idx_5 = 0.0;
      } else {
        rtb_YMDHMS_UTC_idx_5 = (rtNaN);
      }

      num_dead_MTQ = -rtb_YMDHMS_UTC_idx_5;
      if (momentum_error_wheel[2] < 0.0) {
        rtb_YMDHMS_UTC_idx_5 = -1.0;
      } else if (momentum_error_wheel[2] > 0.0) {
        rtb_YMDHMS_UTC_idx_5 = 1.0;
      } else if (momentum_error_wheel[2] == 0.0) {
        rtb_YMDHMS_UTC_idx_5 = 0.0;
      } else {
        rtb_YMDHMS_UTC_idx_5 = (rtNaN);
      }

      rtb_YMDHMS_UTC_idx_2 = -rtb_YMDHMS_UTC_idx_5;
      if (momentum_error_wheel[3] < 0.0) {
        rtb_YMDHMS_UTC_idx_5 = -1.0;
      } else if (momentum_error_wheel[3] > 0.0) {
        rtb_YMDHMS_UTC_idx_5 = 1.0;
      } else if (momentum_error_wheel[3] == 0.0) {
        rtb_YMDHMS_UTC_idx_5 = 0.0;
      } else {
        rtb_YMDHMS_UTC_idx_5 = (rtNaN);
      }

      rtb_YMDHMS_UTC_idx_5 = -rtb_YMDHMS_UTC_idx_5;
      rtDW.rwa_spindown_flag = 1.0;
    } else {
      rtDW.rwa_spindown_flag = 0.0;
    }
  } else {
    rtDW.rwa_spindown_flag = 0.0;
  }

  /* End of MATLAB Function: '<S107>/Desat_control_logic' */

  /* If: '<S111>/If' incorporates:
   *  Gain: '<S137>/Gain'
   *  Inport: '<S136>/In1'
   *  MATLAB Function: '<S6>/MATLAB Function'
   *  Product: '<S137>/Matrix Multiply'
   */
  if (b_r1 == 1) {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem' incorporates:
     *  ActionPort: '<S135>/Action Port'
     */
    /* Product: '<S137>/Matrix Multiply' incorporates:
     *  Constant: '<S137>/Constant'
     */
    for (i = 0; i < 3; i++) {
      rtb_nT2T[i] = rtConstP.pooled22[i + 6] * rtb_vel_teme_kmps[2] +
        (rtConstP.pooled22[i + 3] * rtb_vel_teme_kmps[1] + rtConstP.pooled22[i] *
         rtb_vel_teme_kmps[0]);
    }

    /* Product: '<S138>/Matrix Multiply' incorporates:
     *  Constant: '<S138>/Constant'
     *  Product: '<S137>/Matrix Multiply'
     */
    for (i = 0; i < 4; i++) {
      tmp_1[i] = rtConstP.pooled20[i + 8] * rtb_nT2T[2] + (rtConstP.pooled20[i +
        4] * rtb_nT2T[1] + rtConstP.pooled20[i] * rtb_nT2T[0]);
    }

    /* End of Product: '<S138>/Matrix Multiply' */
    for (i = 0; i < 4; i++) {
      /* Product: '<S138>/Matrix Multiply1' incorporates:
       *  Constant: '<S138>/Constant1'
       */
      api = rtConstP.pooled19[i + 12] * tmp_1[3] + (rtConstP.pooled19[i + 8] *
        tmp_1[2] + (rtConstP.pooled19[i + 4] * tmp_1[1] + rtConstP.pooled19[i] *
                    tmp_1[0]));

      /* Abs: '<S138>/Abs' incorporates:
       *  Product: '<S138>/Matrix Multiply1'
       */
      momentum_error_wheel[i] = fabs(api);
    }

    /* MinMax: '<S138>/Max' */
    if ((momentum_error_wheel[0] > momentum_error_wheel[1]) || rtIsNaN
        (momentum_error_wheel[1])) {
      rtb_YMDHMS_UTC_idx_1 = momentum_error_wheel[0];
    } else {
      rtb_YMDHMS_UTC_idx_1 = momentum_error_wheel[1];
    }

    if ((!(rtb_YMDHMS_UTC_idx_1 > momentum_error_wheel[2])) && (!rtIsNaN
         (momentum_error_wheel[2]))) {
      rtb_YMDHMS_UTC_idx_1 = momentum_error_wheel[2];
    }

    if ((!(rtb_YMDHMS_UTC_idx_1 > momentum_error_wheel[3])) && (!rtIsNaN
         (momentum_error_wheel[3]))) {
      rtb_YMDHMS_UTC_idx_1 = momentum_error_wheel[3];
    }

    /* Sum: '<S139>/div by zero protection' incorporates:
     *  Constant: '<S139>/small'
     *  DotProduct: '<S142>/Dot Product'
     *  MinMax: '<S138>/Max'
     *  Sqrt: '<S142>/Sqrt'
     */
    rtb_YMDHMS_UTC_idx_0 = sqrt(rtb_YMDHMS_UTC_idx_1 * rtb_YMDHMS_UTC_idx_1) +
      1.0E-8;

    /* If: '<S138>/If3' incorporates:
     *  MinMax: '<S138>/Max'
     */
    rEQ0 = (rtb_YMDHMS_UTC_idx_1 > 1.0);
    if (rEQ0) {
      /* Gain: '<S137>/Gain' incorporates:
       *  Product: '<S137>/Matrix Multiply'
       *  Product: '<S138>/Divide1'
       */
      rtb_YMDHMS_UTC_idx_1 = -(rtb_nT2T[0] / rtb_YMDHMS_UTC_idx_0);
    } else {
      /* Gain: '<S137>/Gain' incorporates:
       *  Product: '<S137>/Matrix Multiply'
       */
      rtb_YMDHMS_UTC_idx_1 = -rtb_nT2T[0];
    }

    rtb_nT2T[0] = rtb_YMDHMS_UTC_idx_1;

    /* If: '<S138>/If3' incorporates:
     *  Gain: '<S137>/Gain'
     *  Product: '<S137>/Matrix Multiply'
     *  Product: '<S138>/Divide1'
     */
    if (rEQ0) {
      rtb_YMDHMS_UTC_idx_1 = -(rtb_nT2T[1] / rtb_YMDHMS_UTC_idx_0);
    } else {
      rtb_YMDHMS_UTC_idx_1 = -rtb_nT2T[1];
    }

    rtb_nT2T[1] = rtb_YMDHMS_UTC_idx_1;

    /* If: '<S138>/If3' incorporates:
     *  Gain: '<S137>/Gain'
     *  Product: '<S137>/Matrix Multiply'
     *  Product: '<S138>/Divide1'
     */
    if (rEQ0) {
      rtb_YMDHMS_UTC_idx_1 = -(rtb_nT2T[2] / rtb_YMDHMS_UTC_idx_0);
    } else {
      rtb_YMDHMS_UTC_idx_1 = -rtb_nT2T[2];
    }

    rtb_nT2T[2] = rtb_YMDHMS_UTC_idx_1;

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S136>/Action Port'
     */
    rtb_nT2T[0] = 0.0;
    rtb_nT2T[1] = 0.0;
    rtb_nT2T[2] = 0.0;

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem1' */
  }

  /* End of If: '<S111>/If' */

  /* If: '<S110>/If' incorporates:
   *  Inport: '<S133>/In1'
   *  MATLAB Function: '<S6>/MATLAB Function'
   */
  if (b_r2 == 1) {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem' incorporates:
     *  ActionPort: '<S132>/Action Port'
     */
    /* Sum: '<S134>/Sum' incorporates:
     *  Gain: '<S134>/Kp'
     *  Gain: '<S134>/kd'
     */
    for (i = 0; i < 3; i++) {
      rtb_Product2_p[i] = (0.0 - ((rtConstP.Kp_Gain[i + 3] * rtb_Multiply[2] +
        rtConstP.Kp_Gain[i] * rtb_Multiply[1]) + rtConstP.Kp_Gain[i + 6] *
        rtb_Multiply[3])) - ((rtConstP.pooled22[i + 3] * rtb_vel_teme_kmps[1] +
        rtConstP.pooled22[i] * rtb_vel_teme_kmps[0]) + rtConstP.pooled22[i + 6] *
        rtb_vel_teme_kmps[2]);
    }

    /* End of Sum: '<S134>/Sum' */
    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S133>/Action Port'
     */
    rtb_Product2_p[0] = 0.0;
    rtb_Product2_p[1] = 0.0;
    rtb_Product2_p[2] = 0.0;

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem1' */
  }

  /* End of If: '<S110>/If' */

  /* If: '<S109>/If' incorporates:
   *  Gain: '<S120>/Gain'
   *  Inport: '<S119>/In1'
   *  MATLAB Function: '<S6>/MATLAB Function'
   *  Product: '<S122>/Divide1'
   */
  if (b_r3 == 1) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    /* Sum: '<S121>/Subtract' incorporates:
     *  Memory: '<S120>/Memory'
     */
    b_a21 = rtb_Multiply[1] - rtDW.Memory_PreviousInput[0];

    /* DotProduct: '<S123>/Dot Product' */
    rtb_YMDHMS_UTC_idx_0 = b_a21 * b_a21;

    /* Sum: '<S121>/Subtract' incorporates:
     *  Memory: '<S120>/Memory'
     */
    b_a21 = rtb_Multiply[2] - rtDW.Memory_PreviousInput[1];

    /* DotProduct: '<S123>/Dot Product' */
    rtb_YMDHMS_UTC_idx_0 += b_a21 * b_a21;

    /* Sum: '<S121>/Subtract' incorporates:
     *  Memory: '<S120>/Memory'
     */
    b_a21 = rtb_Multiply[3] - rtDW.Memory_PreviousInput[2];

    /* DotProduct: '<S123>/Dot Product' */
    rtb_YMDHMS_UTC_idx_0 += b_a21 * b_a21;

    /* If: '<S121>/If' incorporates:
     *  Constant: '<S121>/Constant3'
     *  DotProduct: '<S123>/Dot Product'
     *  Inport: '<S125>/In1'
     *  Memory: '<S121>/Memory1'
     *  Product: '<S121>/Divide'
     *  Sqrt: '<S123>/Sqrt'
     */
    if (sqrt(rtb_YMDHMS_UTC_idx_0) / 0.001 > 1.0) {
      /* Outputs for IfAction SubSystem: '<S121>/If Action Subsystem' incorporates:
       *  ActionPort: '<S124>/Action Port'
       */
      /* Sum: '<S126>/div by zero protection' incorporates:
       *  Constant: '<S126>/small'
       *  DotProduct: '<S127>/Dot Product'
       *  Sqrt: '<S127>/Sqrt'
       */
      rtb_YMDHMS_UTC_idx_0 = sqrt((rtb_Multiply[1] * rtb_Multiply[1] +
        rtb_Multiply[2] * rtb_Multiply[2]) + rtb_Multiply[3] * rtb_Multiply[3])
        + 1.0E-8;

      /* Product: '<S124>/Divide' incorporates:
       *  Abs: '<S124>/Abs'
       *  Gain: '<S124>/Gain'
       */
      b_a21 = 0.074048048969306113 * fabs(rtb_Multiply[1]) /
        rtb_YMDHMS_UTC_idx_0;
      rtb_YMDHMS_UTC_idx_1 = 0.074048048969306113 * fabs(rtb_Multiply[2]) /
        rtb_YMDHMS_UTC_idx_0;
      rtb_YMDHMS_UTC_idx_0 = 0.074048048969306113 * fabs(rtb_Multiply[3]) /
        rtb_YMDHMS_UTC_idx_0;

      /* Product: '<S124>/Matrix Multiply' incorporates:
       *  Constant: '<S124>/Constant'
       */
      for (i = 0; i < 3; i++) {
        rtb_Gain[i] = rtConstP.Constant_Value_p[i + 6] * rtb_YMDHMS_UTC_idx_0 +
          (rtConstP.Constant_Value_p[i + 3] * rtb_YMDHMS_UTC_idx_1 +
           rtConstP.Constant_Value_p[i] * b_a21);
      }

      /* End of Product: '<S124>/Matrix Multiply' */

      /* S-Function (sdspdiag2): '<S124>/Create Diagonal Matrix' */
      memset(&rtb_teme_to_gcrf[0], 0, 9U * sizeof(real_T));
      rtb_teme_to_gcrf[0] = rtb_Gain[0];
      rtb_teme_to_gcrf[4] = rtb_Gain[1];
      rtb_teme_to_gcrf[8] = rtb_Gain[2];

      /* End of Outputs for SubSystem: '<S121>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S121>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S125>/Action Port'
       */
      memcpy(&rtb_teme_to_gcrf[0], &rtDW.Memory1_PreviousInput[0], 9U * sizeof
             (real_T));

      /* End of Outputs for SubSystem: '<S121>/If Action Subsystem1' */
    }

    /* End of If: '<S121>/If' */

    /* Product: '<S120>/Matrix Multiply1' incorporates:
     *  Constant: '<S120>/Constant1'
     */
    for (i = 0; i < 3; i++) {
      rtb_Gain[i] = rtConstP.Constant1_Value[i + 6] * rtb_Multiply[3] +
        (rtConstP.Constant1_Value[i + 3] * rtb_Multiply[2] +
         rtConstP.Constant1_Value[i] * rtb_Multiply[1]);
    }

    /* End of Product: '<S120>/Matrix Multiply1' */

    /* Saturate: '<S120>/Saturation1' */
    if (rtb_Gain[0] > 1.0) {
      b_a21 = 1.0;
    } else if (rtb_Gain[0] < -1.0) {
      b_a21 = -1.0;
    } else {
      b_a21 = rtb_Gain[0];
    }

    /* Saturate: '<S120>/Saturation2' */
    if (rtb_Gain[1] > 1.0) {
      rtb_YMDHMS_UTC_idx_1 = 1.0;
    } else if (rtb_Gain[1] < -1.0) {
      rtb_YMDHMS_UTC_idx_1 = -1.0;
    } else {
      rtb_YMDHMS_UTC_idx_1 = rtb_Gain[1];
    }

    /* Saturate: '<S120>/Saturation3' */
    if (rtb_Gain[2] > 1.0) {
      rtb_YMDHMS_UTC_idx_0 = 1.0;
    } else if (rtb_Gain[2] < -1.0) {
      rtb_YMDHMS_UTC_idx_0 = -1.0;
    } else {
      rtb_YMDHMS_UTC_idx_0 = rtb_Gain[2];
    }

    for (i = 0; i < 3; i++) {
      /* Sum: '<S120>/Add' incorporates:
       *  Constant: '<S120>/Constant'
       *  Product: '<S120>/Matrix Multiply'
       *  Product: '<S120>/Matrix Multiply2'
       *  Saturate: '<S120>/Saturation1'
       *  Saturate: '<S120>/Saturation2'
       *  Saturate: '<S120>/Saturation3'
       */
      rtb_MathFunction[i] = ((rtConstP.pooled22[i + 3] * rtb_vel_teme_kmps[1] +
        rtConstP.pooled22[i] * rtb_vel_teme_kmps[0]) + rtConstP.pooled22[i + 6] *
        rtb_vel_teme_kmps[2]) + (rtb_teme_to_gcrf[i + 6] * rtb_YMDHMS_UTC_idx_0
        + (rtb_teme_to_gcrf[i + 3] * rtb_YMDHMS_UTC_idx_1 + rtb_teme_to_gcrf[i] *
           b_a21));
    }

    /* Product: '<S122>/Matrix Multiply' incorporates:
     *  Constant: '<S122>/Constant'
     */
    for (i = 0; i < 4; i++) {
      tmp_1[i] = rtConstP.pooled20[i + 8] * rtb_MathFunction[2] +
        (rtConstP.pooled20[i + 4] * rtb_MathFunction[1] + rtConstP.pooled20[i] *
         rtb_MathFunction[0]);
    }

    /* End of Product: '<S122>/Matrix Multiply' */
    for (i = 0; i < 4; i++) {
      /* Product: '<S122>/Matrix Multiply1' incorporates:
       *  Constant: '<S122>/Constant1'
       */
      api = rtConstP.pooled19[i + 12] * tmp_1[3] + (rtConstP.pooled19[i + 8] *
        tmp_1[2] + (rtConstP.pooled19[i + 4] * tmp_1[1] + rtConstP.pooled19[i] *
                    tmp_1[0]));

      /* Abs: '<S122>/Abs' incorporates:
       *  Product: '<S122>/Matrix Multiply1'
       */
      momentum_error_wheel[i] = fabs(api);
    }

    /* MinMax: '<S122>/Max' */
    if ((momentum_error_wheel[0] > momentum_error_wheel[1]) || rtIsNaN
        (momentum_error_wheel[1])) {
      rtb_YMDHMS_UTC_idx_1 = momentum_error_wheel[0];
    } else {
      rtb_YMDHMS_UTC_idx_1 = momentum_error_wheel[1];
    }

    if ((!(rtb_YMDHMS_UTC_idx_1 > momentum_error_wheel[2])) && (!rtIsNaN
         (momentum_error_wheel[2]))) {
      rtb_YMDHMS_UTC_idx_1 = momentum_error_wheel[2];
    }

    if ((!(rtb_YMDHMS_UTC_idx_1 > momentum_error_wheel[3])) && (!rtIsNaN
         (momentum_error_wheel[3]))) {
      rtb_YMDHMS_UTC_idx_1 = momentum_error_wheel[3];
    }

    /* Sum: '<S128>/div by zero protection' incorporates:
     *  Constant: '<S128>/small'
     *  DotProduct: '<S131>/Dot Product'
     *  MinMax: '<S122>/Max'
     *  Sqrt: '<S131>/Sqrt'
     */
    rtb_YMDHMS_UTC_idx_0 = sqrt(rtb_YMDHMS_UTC_idx_1 * rtb_YMDHMS_UTC_idx_1) +
      1.0E-8;

    /* If: '<S122>/If3' incorporates:
     *  MinMax: '<S122>/Max'
     */
    rEQ0 = (rtb_YMDHMS_UTC_idx_1 > 1.0);
    if (rEQ0) {
      /* Gain: '<S120>/Gain' incorporates:
       *  Product: '<S122>/Divide1'
       */
      b_a21 = -(rtb_MathFunction[0] / rtb_YMDHMS_UTC_idx_0);
    } else {
      /* Gain: '<S120>/Gain' incorporates:
       *  Product: '<S122>/Divide1'
       */
      b_a21 = -rtb_MathFunction[0];
    }

    rtb_MathFunction[0] = b_a21;

    /* If: '<S122>/If3' incorporates:
     *  Gain: '<S120>/Gain'
     *  Product: '<S122>/Divide1'
     */
    if (rEQ0) {
      b_a21 = -(rtb_MathFunction[1] / rtb_YMDHMS_UTC_idx_0);
    } else {
      b_a21 = -rtb_MathFunction[1];
    }

    rtb_MathFunction[1] = b_a21;

    /* If: '<S122>/If3' incorporates:
     *  Gain: '<S120>/Gain'
     *  Product: '<S122>/Divide1'
     */
    if (rEQ0) {
      b_a21 = -(rtb_MathFunction[2] / rtb_YMDHMS_UTC_idx_0);
    } else {
      b_a21 = -rtb_MathFunction[2];
    }

    rtb_MathFunction[2] = b_a21;

    /* Update for Memory: '<S121>/Memory1' incorporates:
     *  Gain: '<S120>/Gain'
     *  Product: '<S122>/Divide1'
     */
    memcpy(&rtDW.Memory1_PreviousInput[0], &rtb_teme_to_gcrf[0], 9U * sizeof
           (real_T));

    /* Update for Memory: '<S120>/Memory' */
    rtDW.Memory_PreviousInput[0] = rtb_Multiply[1];
    rtDW.Memory_PreviousInput[1] = rtb_Multiply[2];
    rtDW.Memory_PreviousInput[2] = rtb_Multiply[3];

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    rtb_MathFunction[0] = 0.0;
    rtb_MathFunction[1] = 0.0;
    rtb_MathFunction[2] = 0.0;

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem1' */
  }

  /* End of If: '<S109>/If' */

  /* Sum: '<S6>/Add' */
  rtb_nT2T[0] = (rtb_nT2T[0] + rtb_Product2_p[0]) + rtb_MathFunction[0];
  rtb_nT2T[1] = (rtb_nT2T[1] + rtb_Product2_p[1]) + rtb_MathFunction[1];
  rtb_nT2T[2] = (rtb_nT2T[2] + rtb_Product2_p[2]) + rtb_MathFunction[2];

  /* Outputs for Atomic SubSystem: '<S6>/rwa_allocation_lib' */
  rwa_allocation_lib(rtb_nT2T, rtb_Transpose, RateTransition1, rtb_Multiply,
                     &rtDW.rwa_allocation_lib_o);

  /* End of Outputs for SubSystem: '<S6>/rwa_allocation_lib' */

  /* Sum: '<S6>/Add1' incorporates:
   *  Constant: '<S107>/Constant2'
   *  Product: '<S107>/Multiply'
   */
  rtb_YMDHMS_UTC_idx_4 = rtb_YMDHMS_UTC_idx_4 * 3.2000000000000005E-5 +
    rtb_Multiply[0];

  /* Saturate: '<S6>/Saturation' */
  if (rtb_YMDHMS_UTC_idx_4 > 0.0032) {
    rtb_Saturation[0] = 0.0032;
  } else if (rtb_YMDHMS_UTC_idx_4 < -0.0032) {
    rtb_Saturation[0] = -0.0032;
  } else {
    rtb_Saturation[0] = rtb_YMDHMS_UTC_idx_4;
  }

  /* Sum: '<S6>/Add1' incorporates:
   *  Abs: '<S326>/Abs1'
   *  Constant: '<S107>/Constant2'
   *  Inport: '<Root>/act_meas'
   *  Product: '<S107>/Multiply'
   *  RateTransition: '<S4>/Rate Transition5'
   */
  rtb_Multiply[0] = fabs(rtU.act_meas.rwa_rpm[0]);
  rtb_YMDHMS_UTC_idx_4 = num_dead_MTQ * 3.2000000000000005E-5 + rtb_Multiply[1];

  /* Saturate: '<S6>/Saturation' */
  if (rtb_YMDHMS_UTC_idx_4 > 0.0032) {
    rtb_Saturation[1] = 0.0032;
  } else if (rtb_YMDHMS_UTC_idx_4 < -0.0032) {
    rtb_Saturation[1] = -0.0032;
  } else {
    rtb_Saturation[1] = rtb_YMDHMS_UTC_idx_4;
  }

  /* Sum: '<S6>/Add1' incorporates:
   *  Abs: '<S326>/Abs1'
   *  Constant: '<S107>/Constant2'
   *  Inport: '<Root>/act_meas'
   *  Product: '<S107>/Multiply'
   *  RateTransition: '<S4>/Rate Transition5'
   */
  rtb_Multiply[1] = fabs(rtU.act_meas.rwa_rpm[1]);
  rtb_YMDHMS_UTC_idx_4 = rtb_YMDHMS_UTC_idx_2 * 3.2000000000000005E-5 +
    rtb_Multiply[2];

  /* Saturate: '<S6>/Saturation' */
  if (rtb_YMDHMS_UTC_idx_4 > 0.0032) {
    rtb_Saturation[2] = 0.0032;
  } else if (rtb_YMDHMS_UTC_idx_4 < -0.0032) {
    rtb_Saturation[2] = -0.0032;
  } else {
    rtb_Saturation[2] = rtb_YMDHMS_UTC_idx_4;
  }

  /* Sum: '<S6>/Add1' incorporates:
   *  Abs: '<S326>/Abs1'
   *  Constant: '<S107>/Constant2'
   *  Inport: '<Root>/act_meas'
   *  Product: '<S107>/Multiply'
   *  RateTransition: '<S4>/Rate Transition5'
   */
  rtb_Multiply[2] = fabs(rtU.act_meas.rwa_rpm[2]);
  rtb_YMDHMS_UTC_idx_4 = rtb_YMDHMS_UTC_idx_5 * 3.2000000000000005E-5 +
    rtb_Multiply[3];

  /* Saturate: '<S6>/Saturation' */
  if (rtb_YMDHMS_UTC_idx_4 > 0.0032) {
    rtb_Saturation[3] = 0.0032;
  } else if (rtb_YMDHMS_UTC_idx_4 < -0.0032) {
    rtb_Saturation[3] = -0.0032;
  } else {
    rtb_Saturation[3] = rtb_YMDHMS_UTC_idx_4;
  }

  /* Sum: '<S6>/Add1' incorporates:
   *  Abs: '<S326>/Abs1'
   *  Inport: '<Root>/act_meas'
   *  RateTransition: '<S4>/Rate Transition5'
   */
  rtb_Multiply[3] = fabs(rtU.act_meas.rwa_rpm[3]);

  /* Product: '<S241>/Product3' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtb_YMDHMS_UTC_idx_0 = N[1] * N[1];

  /* Sum: '<S241>/Sum2' incorporates:
   *  Product: '<S241>/Product2'
   */
  epsb_1980 = N[0] * N[0] + rtb_YMDHMS_UTC_idx_0;

  /* Outputs for Iterator SubSystem: '<S237>/While Iterator Subsystem' */
  /* Sqrt: '<S241>/sqrt' */
  WhileIteratorSubsystem(sqrt(epsb_1980), N[2], rtConstB.Product1_b,
    0.99664718933525254, 0.00669437999014133, rtConstB.Product2_d,
    &rtb_YMDHMS_UTC_idx_0, &rtDW.WhileIteratorSubsystem_i);

  /* End of Outputs for SubSystem: '<S237>/While Iterator Subsystem' */

  /* MATLAB Function: '<S319>/MATLAB Function' */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rEQ0 = false;

  /* Abs: '<S9>/Abs' */
  rtb_Product2_p[0] = fabs(rtb_vel_teme_kmps[0]);

  /* Gain: '<S7>/M2KM' */
  M[0] *= 0.001;

  /* MATLAB Function: '<S319>/MATLAB Function' */
  rtb_pos_teme_km[0] *= 1.49598073E+8;

  /* Abs: '<S9>/Abs' */
  rtb_Product2_p[1] = fabs(rtb_vel_teme_kmps[1]);

  /* Gain: '<S7>/M2KM' */
  M[1] *= 0.001;

  /* MATLAB Function: '<S319>/MATLAB Function' */
  rtb_pos_teme_km[1] *= 1.49598073E+8;

  /* Abs: '<S9>/Abs' */
  rtb_Product2_p[2] = fabs(rtb_vel_teme_kmps[2]);

  /* Gain: '<S7>/M2KM' */
  rtb_YMDHMS_UTC_idx_2 = 0.001 * M[2];

  /* MATLAB Function: '<S319>/MATLAB Function' */
  rtb_YMDHMS_UTC_idx_4 = rtb_pos_teme_km[2] * 1.49598073E+8;

  /* Gain: '<S7>/M2KM' */
  M[2] = rtb_YMDHMS_UTC_idx_2;

  /* MATLAB Function: '<S319>/MATLAB Function' */
  rtb_pos_teme_km[2] = rtb_YMDHMS_UTC_idx_4;
  num_dead_MTQ = norm(M);
  M_sun = norm(rtb_pos_teme_km);
  rtb_YMDHMS_UTC_idx_2 = (M[0] * rtb_pos_teme_km[0] + M[1] * rtb_pos_teme_km[1])
    + rtb_YMDHMS_UTC_idx_2 * rtb_YMDHMS_UTC_idx_4;
  rtb_YMDHMS_UTC_idx_0 = (num_dead_MTQ * num_dead_MTQ - rtb_YMDHMS_UTC_idx_2) /
    ((num_dead_MTQ * num_dead_MTQ + M_sun * M_sun) - rtb_YMDHMS_UTC_idx_2 * 2.0);
  if ((rtb_YMDHMS_UTC_idx_0 < 0.0) || (rtb_YMDHMS_UTC_idx_0 > 1.0)) {
    rEQ0 = true;
  }

  if (rtb_YMDHMS_UTC_idx_2 * rtb_YMDHMS_UTC_idx_0 + (1.0 - rtb_YMDHMS_UTC_idx_0)
      * (num_dead_MTQ * num_dead_MTQ) >= 4.0680631590768993E+7) {
    rEQ0 = true;
  }

  rtb_VariableSelector3 = !rEQ0;

  /* MinMax: '<S9>/MinMax' */
  if ((rtb_Product2_p[0] > rtb_Product2_p[1]) || rtIsNaN(rtb_Product2_p[1])) {
    rtb_YMDHMS_UTC_idx_1 = rtb_Product2_p[0];
  } else {
    rtb_YMDHMS_UTC_idx_1 = rtb_Product2_p[1];
  }

  if ((!(rtb_YMDHMS_UTC_idx_1 > rtb_Product2_p[2])) && (!rtIsNaN(rtb_Product2_p
        [2]))) {
    rtb_YMDHMS_UTC_idx_1 = rtb_Product2_p[2];
  }

  /* Relay: '<S9>/Relay' incorporates:
   *  MinMax: '<S9>/MinMax'
   */
  if (rtb_YMDHMS_UTC_idx_1 >= 0.15707963267948966) {
    rtDW.Relay_Mode_o = true;
  } else {
    if (rtb_YMDHMS_UTC_idx_1 <= 0.0087266462599716477) {
      rtDW.Relay_Mode_o = false;
    }
  }

  /* UnitDelay: '<S327>/Unit Delay' */
  rtDW.timer_start = rtDW.UnitDelay_DSTATE_d;

  /* MATLAB Function: '<S327>/desat_timer_logic' incorporates:
   *  Constant: '<S327>/Constant'
   *  Constant: '<S327>/Constant1'
   *  Inport: '<Root>/telecommands'
   *  UnitDelay: '<S327>/Unit Delay1'
   *  UnitDelay: '<S327>/Unit Delay2'
   */
  rtb_YMDHMS_UTC_idx_0 = rtDW.timer_start;
  rtb_YMDHMS_UTC_idx_1 = rtDW.UnitDelay2_DSTATE;
  if ((rtb_UnitDelay_f == 41) && (rtDW.UnitDelay1_DSTATE != 41)) {
    rtb_YMDHMS_UTC_idx_0 = rtU.telecommands.MET_utc_s;
    rtb_YMDHMS_UTC_idx_1 = 1.0;
  }

  if (rtb_YMDHMS_UTC_idx_1 == 1.0) {
    b_a21 = rtU.telecommands.MET_utc_s - rtb_YMDHMS_UTC_idx_0;
    if ((!rtIsInf(b_a21)) && (!rtIsNaN(b_a21))) {
      if (b_a21 == 0.0) {
        num_dead_MTQ = 0.0;
      } else {
        num_dead_MTQ = fmod(b_a21, 5460.0);
        if (num_dead_MTQ == 0.0) {
          num_dead_MTQ = 0.0;
        } else {
          if (b_a21 < 0.0) {
            num_dead_MTQ += 5460.0;
          }
        }
      }
    } else {
      num_dead_MTQ = (rtNaN);
    }

    if ((num_dead_MTQ < 30.0) && (b_a21 > 30.0)) {
      rtb_YMDHMS_UTC_idx_1 = 0.0;
    }
  }

  rtDW.desat_timer_flag = rtb_YMDHMS_UTC_idx_1;
  rtDW.timer_start = rtb_YMDHMS_UTC_idx_0;

  /* End of MATLAB Function: '<S327>/desat_timer_logic' */

  /* Sqrt: '<S328>/Sqrt' incorporates:
   *  DotProduct: '<S328>/Dot Product'
   *  Inport: '<Root>/act_meas'
   *  RateTransition: '<S4>/Rate Transition5'
   */
  epsb_1980 = sqrt(((rtU.act_meas.rwa_rpm[0] * rtU.act_meas.rwa_rpm[0] +
                     rtU.act_meas.rwa_rpm[1] * rtU.act_meas.rwa_rpm[1]) +
                    rtU.act_meas.rwa_rpm[2] * rtU.act_meas.rwa_rpm[2]) +
                   rtU.act_meas.rwa_rpm[3] * rtU.act_meas.rwa_rpm[3]);

  /* Relay: '<S326>/Relay2' */
  if (epsb_1980 >= 6000.0) {
    rtDW.Relay2_Mode = true;
  } else {
    if (epsb_1980 <= 2200.0) {
      rtDW.Relay2_Mode = false;
    }
  }

  /* MinMax: '<S326>/MinMax1' */
  if ((rtb_Multiply[0] > rtb_Multiply[1]) || rtIsNaN(rtb_Multiply[1])) {
    rtb_YMDHMS_UTC_idx_0 = rtb_Multiply[0];
  } else {
    rtb_YMDHMS_UTC_idx_0 = rtb_Multiply[1];
  }

  if ((!(rtb_YMDHMS_UTC_idx_0 > rtb_Multiply[2])) && (!rtIsNaN(rtb_Multiply[2])))
  {
    rtb_YMDHMS_UTC_idx_0 = rtb_Multiply[2];
  }

  if ((!(rtb_YMDHMS_UTC_idx_0 > rtb_Multiply[3])) && (!rtIsNaN(rtb_Multiply[3])))
  {
    rtb_YMDHMS_UTC_idx_0 = rtb_Multiply[3];
  }

  /* End of MinMax: '<S326>/MinMax1' */

  /* Relay: '<S326>/Relay1' */
  if (rtb_YMDHMS_UTC_idx_0 >= 5000.0) {
    rtDW.Relay1_Mode = true;
  } else {
    if (rtb_YMDHMS_UTC_idx_0 <= 1100.0) {
      rtDW.Relay1_Mode = false;
    }
  }

  /* Logic: '<S326>/OR' incorporates:
   *  Relay: '<S326>/Relay1'
   *  Relay: '<S326>/Relay2'
   */
  rEQ0 = (rtDW.Relay2_Mode || rtDW.Relay1_Mode);

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  Inport: '<Root>/act_meas'
   *  Inport: '<Root>/sensor_meas'
   *  Inport: '<Root>/telecommands'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S9>/Logical Operator'
   *  RateTransition: '<S4>/Rate Transition1'
   *  RelationalOperator: '<S324>/Compare'
   *  Relay: '<S9>/Relay'
   */
  rtDW.sc_mode = rtb_UnitDelay_f;
  if (rtU.telecommands.telecom[3] == 1.0) {
    rtDW.sc_mode = 1;
  } else if (rtU.telecommands.telecom[4] == 1.0) {
    rtDW.sc_mode = 2;
  } else if ((!rtU.act_meas.mtq_valid[0]) || (!rtU.act_meas.mtq_valid[1]) ||
             (!rtU.act_meas.mtq_valid[2]) || (!rtU.act_meas.mtq_valid[3]) ||
             (!rtU.act_meas.mtq_valid[4]) || ((!rtU.act_meas.rwa_valid[0]) ||
              (!rtU.act_meas.rwa_valid[1]) || (!rtU.act_meas.rwa_valid[2]) ||
              (!rtU.act_meas.rwa_valid[3]))) {
    rtDW.sc_mode = 2;
  } else if (rtU.telecommands.telecom[0] == 0.0) {
    if (rtDW.Relay_Mode_o) {
      rtDW.sc_mode = 3;
      if (rtb_UnitDelay_f == 41) {
        rtDW.sc_mode = 41;
      }
    } else if (rEQ0 || (rtDW.desat_timer_flag != 0.0)) {
      if (!rEQ0) {
        rtDW.sc_mode = 3;
      } else {
        rtDW.sc_mode = 41;
      }
    } else {
      if (rtb_VariableSelector3 && (!rtU.sensor_meas.sun_meas_valid)) {
        rtDW.sc_mode = 42;
      }

      if (rtU.telecommands.telecom[2] == 1.0) {
        rtDW.sc_mode = 51;
        if (rtb_LogicalOperator_l && rtb_VariableSelector3 &&
            (rtU.telecommands.telecom[5] == 1.0)) {
          rtDW.sc_mode = 52;
        }

        if (rtU.telecommands.telecom[6] == 1.0) {
          rtDW.sc_mode = 53;
        }
      }
    }
  } else {
    if (rtU.telecommands.telecom[0] != 0.0) {
      api = rt_roundd_snf(rtU.telecommands.telecom[0]);
      if (api < 128.0) {
        if (api >= -128.0) {
          rtDW.sc_mode = (int8_T)api;
        } else {
          rtDW.sc_mode = MIN_int8_T;
        }
      } else {
        rtDW.sc_mode = MAX_int8_T;
      }
    }
  }

  /* End of MATLAB Function: '<S9>/MATLAB Function' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_fsw_out_at_inport_0' incorporates:
   *  Outport: '<Root>/fsw_out'
   */
  for (i = 0; i < 5; i++) {
    rtY.fsw_out_j.mtq_cmd_Am2[i] = rtb_Multiply1[i];
  }

  for (i = 0; i < 6; i++) {
    rtY.fsw_out_j.gnc_telemetry[i] = 0.0;
  }

  /* End of BusCreator: '<Root>/BusConversion_InsertedFor_fsw_out_at_inport_0' */

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_j = rtDW.sc_mode;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] += 0.1 * rtb_Saturation[0];
  rtDW.DiscreteTimeIntegrator_DSTATE[1] += 0.1 * rtb_Saturation[1];
  rtDW.DiscreteTimeIntegrator_DSTATE[2] += 0.1 * rtb_Saturation[2];
  rtDW.DiscreteTimeIntegrator_DSTATE[3] += 0.1 * rtb_Saturation[3];

  /* Update for UnitDelay: '<S107>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtDW.rwa_spindown_flag;

  /* Update for UnitDelay: '<S327>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtb_UnitDelay_f;

  /* Update for UnitDelay: '<S327>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = rtDW.desat_timer_flag;

  /* Update for UnitDelay: '<S327>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_d = rtDW.timer_start;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[0] =
    (++rtM->Timing.clockTick0) * rtM->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick1++;
}

/* Model step function for TID2 */
void FSW_Lib_step2(void)               /* Sample time: [1.0s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_libTID2(&rtDW.MEKF_lib_g);

  /* End of Outputs for SubSystem: '<S1>/MEKF_lib' */
}

/* Model initialize function */
void FSW_Lib_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(rtM))));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.1;

  /* Start for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib_Start(&rtDW.MEKF_lib_g);

  /* End of Start for SubSystem: '<S1>/MEKF_lib' */

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_j = 1;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] = 0.0030919554896630744;

  /* SystemInitialize for Merge: '<S330>/Merge' */
  rtDW.Merge[0] = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[1] = -0.0030919554896630744;

  /* SystemInitialize for Merge: '<S330>/Merge' */
  rtDW.Merge[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[2] = 0.0030919554896630744;

  /* SystemInitialize for Merge: '<S330>/Merge' */
  rtDW.Merge[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[3] = -0.0030919554896630744;

  /* SystemInitialize for Merge: '<S330>/Merge' */
  rtDW.Merge[3] = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<S1>/MEKF_lib' */
  MEKF_lib_Init(rtDW.qmerge, &rtDW.MEKF_lib_g);

  /* End of SystemInitialize for SubSystem: '<S1>/MEKF_lib' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/If Action Subsystem' */
  /* InitializeConditions for Memory: '<S121>/Memory1' */
  memcpy(&rtDW.Memory1_PreviousInput[0], &rtConstP.pooled17[0], 9U * sizeof
         (real_T));

  /* InitializeConditions for Memory: '<S120>/Memory' */
  rtDW.Memory_PreviousInput[0] = 0.5;
  rtDW.Memory_PreviousInput[1] = 0.5;
  rtDW.Memory_PreviousInput[2] = 0.5;

  /* End of SystemInitialize for SubSystem: '<S109>/If Action Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

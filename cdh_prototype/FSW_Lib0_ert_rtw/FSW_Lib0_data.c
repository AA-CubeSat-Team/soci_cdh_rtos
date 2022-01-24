/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0_data.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 14 15:17:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* Invariant block signals (default storage) */
const ConstB rtConstB = {
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },/* '<S251>/Identity Matrix' */

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 }/* '<S243>/Identity Matrix' */
};

/* Block parameters (default storage) */
P rtP = {
  /* Variable: fswParams
   * Referenced by:
   *   '<S2>/maggyroProcessing_lib'
   *   '<S2>/maggyroProcessing_lib1'
   *   '<S2>/deg2rad'
   *   '<S3>/Unit Delay'
   *   '<S3>/Unit Delay1'
   *   '<S3>/Unit Delay3'
   *   '<S5>/RPM2Radps'
   *   '<S6>/M2KM'
   *   '<S9>/Relay'
   *   '<S9>/Unit Delay'
   *   '<S10>/ss_offset_rad'
   *   '<S115>/parallel_protection_lib'
   *   '<S119>/Constant'
   *   '<S119>/Saturation'
   *   '<S120>/Constant'
   *   '<S121>/Constant'
   *   '<S124>/Constant'
   *   '<S124>/Constant13'
   *   '<S125>/parallel_protection_lib'
   *   '<S125>/parallel_protection_lib1'
   *   '<S125>/Unit Delay'
   *   '<S229>/RAD2DEG'
   *   '<S288>/Constant'
   *   '<S288>/Constant1'
   *   '<S288>/Constant2'
   *   '<S290>/JD_J2000'
   *   '<S291>/AU2KM'
   *   '<S292>/Constant1'
   *   '<S382>/A_wheel2body '
   *   '<S382>/J_w_wheel_kgm2'
   *   '<S382>/scParams.J '
   *   '<S382>/rpm2radps'
   *   '<S382>/Relay3'
   *   '<S391>/A_wheel2body'
   *   '<S391>/wheel_inertia'
   *   '<S107>/deg2rad'
   *   '<S126>/DEG2RAD'
   *   '<S179>/DEG2RAD'
   *   '<S180>/DEG2RAD'
   *   '<S233>/Constant'
   *   '<S233>/radps_2_rpm'
   *   '<S233>/Saturation'
   *   '<S274>/Constant'
   *   '<S275>/feedback_gain'
   *   '<S275>/wheel_inertia_kgm2'
   *   '<S276>/Constant'
   *   '<S294>/deg2rad1'
   *   '<S294>/deg2rad2'
   *   '<S295>/deg2rad1'
   *   '<S295>/deg2rad2'
   *   '<S111>/Relay'
   *   '<S239>/Constant'
   *   '<S247>/Kp'
   *   '<S247>/kd'
   *   '<S256>/Kp'
   *   '<S256>/kd'
   *   '<S257>/Kd'
   *   '<S257>/Kp'
   *   '<S278>/Constant'
   *   '<S279>/Constant'
   *   '<S280>/Constant1'
   *   '<S336>/Constant'
   *   '<S342>/Constant'
   *   '<S112>/Lower Limit'
   *   '<S112>/Upper Limit'
   *   '<S113>/Lower Limit'
   *   '<S113>/Upper Limit'
   *   '<S242>/A_wheel2body '
   *   '<S242>/J_w_wheel_kgm2'
   *   '<S242>/h_targ_wheel_Nms'
   *   '<S242>/scParams.J '
   *   '<S243>/Gain'
   *   '<S244>/Gain3'
   *   '<S250>/A_wheel2body '
   *   '<S250>/J_w_wheel_kgm2'
   *   '<S250>/h_targ_wheel_Nms'
   *   '<S250>/scParams.J '
   *   '<S251>/Gain'
   *   '<S252>/Gain3'
   *   '<S258>/sunsensor_boresight_unit'
   */
  {
    0.25,

    {
      {
        0.001,
        1000.0,
        0.017453292519943295,
        57.295779513082323,
        86400.0,
        1.1574074074074073e-5,
        9.5492965855137211,
        0.10471975511965977,
        149598073.0,
        1.0e-9,
        1000000.0,
        1.0e-6,
        3600.0,
        0.00027777777777777778,
        60.0,
        0.016666666666666666
      },

      {
        1.0e-8,

        { 0.0, 0.0, 7.2921158553e-5 },
        398600.4418,
        6378.137,
        2451545.0,
        3.5,
        1.5
      }
    },

    {
      0.2,
      0.1,
      0.1,
      2.565438,

      { 1.0, 0.0, 0.0 },

      { 0.0, 1.0, 0.0 },

      { 0.0, 0.0, 1.0 },

      { 0.0118206435013, 0.00043170726620000006, -7.3061275000000005e-6,
        0.00043170726620000006, 0.0116363514485, -9.29219316e-5,
        -7.3061275000000005e-6, -9.29219316e-5, 0.0060345844268 },

      { 0.0021985999999999998, 0.0024908, -0.0080777 },
      2.2,
      0.020000000000000004,
      0.020000000000000004,
      0.010000000000000002,

      { 0.0, 0.0, 0.0 },
      0.69813170079773179
    },

    {
      { 0.92050485345244037, 0.0, 0.39073112848927377, 0.0, 0.92050485345244037,
        0.39073112848927377, -0.92050485345244037, 0.0, 0.39073112848927377, 0.0,
        -0.92050485345244037, 0.39073112848927377 },

      { 2.9526e-5, 2.9526e-5, 2.9526e-5, 2.9526e-5 },

      { 33868.4549210865, 33868.4549210865, 33868.4549210865, 33868.4549210865 },
      0.0032,
      6500.0,
      6U,

      { 0.0029991968249731822, -0.0030610359347664436, 0.0031228750445597051,
        -0.003184714154352967 },
      0.01,

      { 1.0, -1.0, 1.0, -1.0 },

      { 0.00294561553104781, 0.00214403277419873 },

      { 3U, 2U, 2U, 1U, 1U, 1U, 4U, 4U, 3U, 4U, 3U, 2U },

      { 1U, 1U, 1U, 2U, 2U, 3U, 2U, 3U, 4U, 3U, 4U, 4U },

      { 0.27159009435132403, 0.27159009435132403, 0.63982616631186306,
        0.54318018870264806, 0.0, -0.0, 0.27159009435132403,
        -0.27159009435132403, 0.63982616631186306, 0.27159009435132403,
        -0.27159009435132403, -0.63982616631186306, 0.0, -0.54318018870264806,
        0.0, -0.27159009435132403, -0.27159009435132403, 0.63982616631186306 },

      { -0.47020150830868962, 0.0, -0.47020150830868962, 0.47020150830868962,
        0.0, -0.47020150830868962 },

      { 1.0238646233366748, 1.9325548097883873, 1.0238646233366748,
        1.0238646233366748, 1.9325548097883873, 1.0238646233366748 }
    },

    {
      10.0,
      60.0,

      { 0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.70710678118654757,
        0.70710678118654757, 0.0, -0.70710678118654757, 0.70710678118654757, 0.0,
        0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

      { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
      130.0,
      0.21629296228661718,

      { 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

      { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
      4.3633,
      0.02,

      {
        10.0,
        4.0,
        5.0
      },
      0.0
    },

    {
      {
        { -0.0041792285888789622, -0.00015263156770876305, 2.583106149731759e-6,
          -0.00015263156770876305, -0.0041140715087521276, 3.2852863977656267e-5,
          2.583106149731759e-6, 3.2852863977656267e-5, -0.0021335477849165076 }
      },

      {
        { 0.0118206435013, 0.00043170726620000006, -7.3061275000000005e-6,
          0.00043170726620000006, 0.0116363514485, -9.29219316e-5,
          -7.3061275000000005e-6, -9.29219316e-5, 0.0060345844268 },

        { 0.92050485345244037, 0.0, 0.39073112848927377, 0.0,
          0.92050485345244037, 0.39073112848927377, -0.92050485345244037, 0.0,
          0.39073112848927377, 0.0, -0.92050485345244037, 0.39073112848927377 },

        { 0.54318018870264806, 0.0, -0.54318018870264806, 0.0, 0.0,
          0.54318018870264806, 0.0, -0.54318018870264806, 0.639826166311863,
          0.639826166311863, 0.63982616631186306, 0.63982616631186306 },
        0.10471975511965978,
        0.00224,

        { 446.42857142857144, 0.0, 0.0, 0.0, 0.0, 446.42857142857144, 0.0, 0.0,
          0.0, 0.0, 446.42857142857144, 0.0, 0.0, 0.0, 0.0, 446.42857142857144 },
        0.70710678118654757,
        0.5,

        { 1.0, 0.0, 0.0, 0.0 },

        { 0.61576604752958164, 0.26502842714851249, 0.26502842714851249,
          -0.69307433967516652 },

        { 0.0002944151071094408, 0.0, 0.0, 0.0, 0.0002898249708399083, 0.0, 0.0,
          0.0, 0.00039305533877398983 },
        0.001,

        { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

        { 20.074791027802114, 0.74477237925517437, -0.00929401890684035,
          0.73316085991389812, 20.074791027802114, -0.11820464249365011,
          -0.012407867876977091, -0.1603069799864271, 7.6765073915837805 },

        { 0.0083584571777579244, 0.0003052631354175261, -5.166212299463518e-6,
          0.0003052631354175261, 0.0082281430175042553, -6.5705727955312534e-5,
          -5.166212299463518e-6, -6.5705727955312534e-5, 0.0042670955698330152 },
        1.0,

        { 0.0, 0.0, 0.0 },

        { 1.0, 0.0, 0.0, 0.0 }
      },

      {
        { 0.010379269447506475, 0.010217449418602387, 0.00529874517936314 },

        { 0.0022784130629625535, 0.0022428910187985854, 0.001163157994406938 },

        { 1.0, 0.0, 0.0, 0.0 }
      },

      {
        170.0,
        99.760095101689075,

        { 0.00011820643501300003, 4.3170726620000016e-6, -7.3061275000000013e-8,
          4.3170726620000016e-6, 0.00011636351448500002, -9.2921931600000012e-7,
          -7.3061275000000013e-8, -9.2921931600000012e-7, 6.0345844268000013e-5
        },

        { 0.002127715830234, 7.7707307916000023e-5, -1.3151029500000002e-6,
          7.7707307916000023e-5, 0.0020945432607300004, -1.6725947688e-5,
          -1.3151029500000002e-6, -1.6725947688e-5, 0.0010862251968240001 }
      }
    },

    {
      { 0.002, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.002 }
    },

    {
      {
        { 0.0, 0.0, 0.0 },

        { 1.0, 0.0, 0.0, 0.0 },
        1.0,
        1.0,
        1.0,
        1.0,

        { 0.0, 0.0, 0.0 },

        { 0.0, 0.0, 0.0 },

        { 0.0, 0.0, 0.0 },

        { 0.0, 0.0, 0.0 },

        { 0.0, 0.0, 0.0 },
        1.0,

        { 3.1622776601683795e-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
          3.1622776601683795e-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
          3.1622776601683795e-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
          3.1622776601683795e-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
          3.1622776601683795e-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
          3.1622776601683795e-5 }
      },
      0.25,
      0.25,

      { 1.5812376481731011e-6, 0.0, 0.0, 1.1857800136281222e-9, 0.0, 0.0, 0.0,
        1.5812376481731011e-6, 0.0, 0.0, 1.1857800136281222e-9, 0.0, 0.0, 0.0,
        1.5812376481731011e-6, 0.0, 0.0, 1.1857800136281222e-9, 0.0, 0.0, 0.0,
        1.2246874673058134e-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        1.2246874673058134e-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        1.2246874673058134e-7 },

      { 0.0011252273833675241, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0011252273833675241, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0011252273833675241, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.700435e-7, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 1.6147e-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        1.1605070000000001e-7 },
      1.0,
      10.0,
      0.5,
      0.01745
    },

    {
      {
        47.655548,
        -122.3032,
        0.0,

        { 47.655548, -122.3032 },

        { -0.39497937598550986, 0.845231988038406, -0.35996413563401142,
          -0.624718338364105, -0.53439955688290364, -0.56933655364375457,
          -0.67358614167579844, 0.0, 0.73910872660408433 },

        { -2300110.1957947267, -3637964.6810316816, 4691164.1847676542 },
        0.17453292519943295
      }, {
        44.233334,
        -76.5,
        0.0,

        { 44.233334, -76.5 },

        { 0.1628473012874416, 0.97236992039767656, 0.16726474335380223,
          -0.67830782661242517, 0.23344536385590547, -0.69670779703582486,
          -0.71650488401665868, 0.0, 0.69758207487024393 },

        { 1068579.3832195178, -4450953.4592476171, 4426705.0636336347 },
        0.17453292519943295
      } }
    ,

    {
      3U,
      0.26179938779914941,
      0.0087266462599716477,
      0.00236570528450198,
      0.00118285264225099,
      5734.4050146055015,
      30.0
    }
  },

  /* Variable: simParams
   * Referenced by:
   *   '<S289>/nT2T'
   *   '<S107>/Constant1'
   *   '<S233>/Discrete-Time Integrator'
   */
  {
    {
      1.0,
      1.0,
      1.0,
      1.0,
      0.0
    },
    0.0125,

    {
      {
        0.001,
        1000.0,
        0.017453292519943295,
        57.295779513082323,
        86400.0,
        1.1574074074074073e-5,
        9.5492965855137211,
        0.10471975511965977,
        149598073.0,
        1.0e-9,
        1000000.0,
        1.0e-6,
        3600.0,
        0.00027777777777777778,
        60.0,
        0.016666666666666666
      },

      {
        1.0e-8,

        { 0.0, 0.0, 7.2921158553e-5 },
        398600.4418,
        6378.137,
        2451545.0,
        3.5,
        1.5
      }
    },

    {
      0.2,
      0.1,
      0.1,
      2.565438,

      { 1.0, 0.0, 0.0 },

      { 0.0, 1.0, 0.0 },

      { 0.0, 0.0, 1.0 },

      { 0.0118206435013, 0.00043170726620000006, -7.3061275000000005e-6,
        0.00043170726620000006, 0.0116363514485, -9.29219316e-5,
        -7.3061275000000005e-6, -9.29219316e-5, 0.0060345844268 },

      { 0.0021985999999999998, 0.0024908, -0.0080777 },
      2.2,
      0.020000000000000004,
      0.020000000000000004,
      0.010000000000000002,

      { 0.0, 0.0, 0.0 },
      0.69813170079773179
    },

    {
      -0.0361535,
      37.0,
      32.184,
      2021.0,
      683592486.43075967
    },

    {
      { 2021.0, 8.0, 242.0, 10.0, 48.0, 6.4307597279547046 },
      2459456.95007443,

      { -0.77275938783481024, 0.634697081559886, 0.0015947327463509118,
        -0.63469568969985313, -0.77276103320013523, 0.0013293020299886885,
        0.0020760514436936731, 1.506062260951583e-5, 0.99999784488946808 },

      { 0.12006605449996059, -0.31017064079156487, 0.90049540874970446,
        0.28015412716657473 },

      { 0.0, 0.0, 0.0 },

      { -2249.821148658642, -6544.2272627601478, 4.7650732560704343 },

      { -0.921468008034368, 0.34211525907819756, 7.5314342833619774 },
      -3.5336492858345046e-5,
      110.42517102912069,
      542024.00777489692,

      { -2249.821148658642, -6544.2272627601478, 4.7650732560704343,
        -0.921468008034368, 0.34211525907819756, 7.5314342833619774,
        0.12006605449996059, -0.31017064079156487, 0.90049540874970446,
        0.28015412716657473, 0.0, 0.0, 0.0 },

      {
        { 1000.0, -1000.0, 1000.0, -1000.0 },

        { 104.71975511965977, -104.71975511965977, 104.71975511965977,
          -104.71975511965977 },

        { 0.0030919554896630744, -0.0030919554896630744, 0.0030919554896630744,
          -0.0030919554896630744 },

        { -2.0422429553220341e-19, 2.0422429553220341e-19,
          6.0297712373061147e-20 },

        { 0.0, 0.0, 0.0, 0.0 },

        { 0.0, 0.0, 0.0, 0.0 },

        { 0.0, 0.0, 0.0 },
        0.0,
        0.0
      }
    },

    { 21.0, 7911.9500744300894, 0.00017033, 97.5508, 251.3052, 0.0017553,
      52.9833, 307.2997, 15.06695111 },

    {
      4.57e-6
    },

    {
      0.0125,

      {
        4.0,

        { 2.9526e-5, 0.0, 0.0, 0.0, 0.0, 2.9526e-5, 0.0, 0.0, 0.0, 0.0,
          2.9526e-5, 0.0, 0.0, 0.0, 0.0, 2.9526e-5 },

        { 0.01, 0.01, 0.01, 0.01 },
        0.4014257279586958,

        { 0.92050485345244037, 0.0, 0.39073112848927377, 0.0,
          0.92050485345244037, 0.39073112848927377, -0.92050485345244037, 0.0,
          0.39073112848927377, 0.0, -0.92050485345244037, 0.39073112848927377 },

        { 0.0029526, -0.0029526 },

        { 1.0, -0.28650479686019009 },

        { 0.0, 0.71349520313980985 },

        { 1.0, -0.28650479686019009 },

        {
          0.111,
          2.25,
          0.0,
          100.0,
          1.0,
          1.0
        },
        6500.0,
        680.67840827778844,
        0.0032,
        4.7011921651759866e-6,
        0.0032,
        1.452,

        { 0.0, 0.0, 0.0, 0.0 },

        { 345.0, 346.0, 347.0, 348.0 }
      },

      {
        { 1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
          1.0 },

        { 2.0, 2.0, 1.0 },

        { 1.0, 2.0 },

        { 3.0, 4.0 },
        5.0,

        { 0.28, 0.28, 0.131 },

        { 5.0, 5.0, 3.3 },

        { 1.14, 1.14, 0.078 },

        { 5.6999999999999993, 5.6999999999999993, 0.25739999999999996 },

        { 20.357142857142854, 20.357142857142854, 1.9648854961832058 },
        0.0,
        0.0,

        { 101.0, 102.0, 103.0, 104.0, 105.0 }
      }
    },

    {
      0.0125,

      {
        3.0,
        0.0125,

        {
          { 1.0e-9, 0.0, 0.0 }
        },

        { 1, 1, 1 },

        { 1.0, 11.0, 21.0 },

        { 0.0028058, 0.0052032, 0.0037329, 0.0028058, 0.0052032, 0.0037329,
          0.0028058, 0.0052032, 0.0037329 },

        { -200.0, -200.0, -200.0 },

        { 200.0, 200.0, 200.0 }
      },

      {
        3.0,
        0.0125,

        { 1.0, 2.0, 3.0, 12.0, 13.0, 14.0, 23.0, 24.0, 25.0 },

        { 31.0, 32.0, 33.0, 41.0, 42.0, 43.0, 51.0, 52.0, 53.0 },

        { 3.1622776601683792e-7, 3.1622776601683792e-7, 3.1622776601683792e-7 },

        { 3.1622776601683795e-10, 3.1622776601683795e-10, 3.1622776601683795e-10
        },

        { 4.84813681109536e-7, 4.84813681109536e-7, 4.84813681109536e-7,
          4.84813681109536e-7, 4.84813681109536e-7, 4.84813681109536e-7,
          4.84813681109536e-7, 4.84813681109536e-7, 4.84813681109536e-7 },

        { 6.9813170079773186e-5, 6.9813170079773186e-5, 6.9813170079773186e-5 },

        { -2.1816615649929121, -2.1816615649929121, -2.1816615649929121 },

        { 2.1816615649929121, 2.1816615649929121, 2.1816615649929121 }
      },

      {
        0.0125,

        { -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 },

        { -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 },
        1,
        0.02357,

        { 101.0, 102.0 },
        72.0
      },

      {
        { 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0,
          1.0, 0.0, 0.0, -1.0 },
        0.9,

        { 3.8142000000000005, 3.8142000000000005, 4.7682, 4.7682, 2.16, 0.0 },
        5.0
      },

      {
        170.0,

        { 44.570289969062969, 44.570289969062969, 35.652866909945054,
          35.652866909945054, 78.7037037037037, 0.0 },
        85.0
      }
    },

    {
      2.9,
      0.45,
      0.398,
      0.515,
      0.025,
      0.104,
      0.4,
      0.9,
      0.85,
      74592.0,
      0.9
    }
  },

  /* Mask Parameter: GeodetictoGeocentricLatitude_F
   * Referenced by:
   *   '<S298>/Constant'
   *   '<S327>/f'
   */
  0.0033528106647474805,

  /* Mask Parameter: RadiusatGeocentricLatitude_F
   * Referenced by: '<S300>/f'
   */
  0.0033528106647474805,

  /* Mask Parameter: maggyroProcessing_lib1_Gain
   * Referenced by: '<S2>/maggyroProcessing_lib1'
   */
  1.0,

  /* Mask Parameter: GeodetictoGeocentricLatitude_R
   * Referenced by: '<S327>/Re'
   */
  6.378137E+6,

  /* Mask Parameter: RadiusatGeocentricLatitude_R
   * Referenced by: '<S300>/Re'
   */
  6.378137E+6,

  /* Mask Parameter: DirectionCosineMatrixtoQuaterni
   * Referenced by:
   *   '<S399>/If Warning//Error'
   *   '<S399>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S445>/Constant'
   */
  0.1,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S333>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_o
   * Referenced by: '<S331>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_f
   * Referenced by: '<S334>/Constant'
   */
  180.0,

  /* Mask Parameter: target_groundpass_lib1_id
   * Referenced by: '<S288>/target_groundpass_lib1'
   */
  2.0,

  /* Mask Parameter: target_groundpass_lib_id
   * Referenced by: '<S288>/target_groundpass_lib'
   */
  1.0,

  /* Mask Parameter: NormalizeVector_maxzero
   * Referenced by: '<S241>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_c
   * Referenced by: '<S249>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero
   * Referenced by: '<S392>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_g
   * Referenced by: '<S376>/Switch'
   */
  0.0,

  /* Mask Parameter: DirectionCosineMatrixtoQuater_g
   * Referenced by: '<S399>/If Warning//Error'
   */
  1.0E-12,

  /* Mask Parameter: Counter_InitialCount
   * Referenced by: '<S394>/Counter'
   */
  0U,

  /* Mask Parameter: DetectRisePositive_vinit
   * Referenced by: '<S436>/Delay Input1'
   */
  0,

  /* Mask Parameter: CompareToConstant_const_f2
   * Referenced by: '<S435>/Constant'
   */
  8U,

  /* Mask Parameter: CompareToConstant_const_a
   * Referenced by: '<S444>/Constant'
   */
  8U,

  /* Mask Parameter: CompareToConstant1_const_c
   * Referenced by: '<S18>/Constant'
   */
  5U,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S17>/Constant'
   */
  4U,

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S21>/FixPt Switch'
   */
  10U,

  /* Computed Parameter: RateTransition4_19_InitialCondi
   * Referenced by: '<S1>/Rate Transition4'
   */
  {
    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  /* opt_state */

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    }
    ,                                  /* opt_ctrl_Nm */
    0.0,                               /* final_time_s */

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0 }
    ,                                  /* exitcode */
    0U                                 /* soar_count */
  },

  /* Expression: zeros(5,1)
   * Referenced by: '<S227>/mtq_off_cmd'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S230>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S230>/Constant1'
   */
  1.0,

  /* Expression: [0.5;-0.5;0.5;-0.5;1]
   * Referenced by: '<S230>/Constant'
   */
  { 0.5, -0.5, 0.5, -0.5, 1.0 },

  /* Expression: 1
   * Referenced by: '<S241>/Constant'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S244>/Gain'
   */
  -1.0,

  /* Expression: 11/5
   * Referenced by: '<S240>/DutyCycleAdjustment'
   */
  2.2,

  /* Expression: zeros(3,1)
   * Referenced by: '<S238>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S249>/Constant'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S252>/Gain'
   */
  -1.0,

  /* Expression: 11/5
   * Referenced by: '<S248>/DutyCycleAdjustment'
   */
  2.2,

  /* Expression: zeros(3,1)
   * Referenced by: '<S237>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S299>/Constant1'
   */
  0.0,

  /* Expression: 180
   * Referenced by: '<S299>/Constant'
   */
  180.0,

  /* Expression: -90
   * Referenced by: '<S329>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S329>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S329>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S332>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S332>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S332>/Bias1'
   */
  -180.0,

  /* Expression: 360
   * Referenced by: '<S330>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S330>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S330>/Bias1'
   */
  -180.0,

  /* Expression: 0
   * Referenced by: '<S366>/phi'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S372>/Memory'
   */
  0.0,

  /* Expression: R
   * Referenced by: '<S370>/Constant1'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S376>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S392>/Constant'
   */
  1.0,

  /* Computed Parameter: opt_state_Y0
   * Referenced by: '<S438>/opt_state'
   */
  0.0,

  /* Computed Parameter: opt_ctrl_Nm_Y0
   * Referenced by: '<S438>/opt_ctrl_Nm'
   */
  0.0,

  /* Computed Parameter: final_time_s_Y0
   * Referenced by: '<S438>/final_time_s'
   */
  0.0,

  /* Computed Parameter: exitcode_Y0
   * Referenced by: '<S438>/exitcode'
   */
  0.0,

  /* Expression: [0;0;0]
   * Referenced by: '<S396>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0;0;0]
   * Referenced by: '<S396>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0; 0; 0]
   * Referenced by: '<S10>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: -1
   * Referenced by: '<S10>/Gain'
   */
  -1.0,

  /* Expression: [1 0 0 0]
   * Referenced by: '<S390>/Merge'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S437>/Unit Delay'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S290>/Gain'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<S368>/Constant'
   */
  1.0,

  /* Expression: F
   * Referenced by: '<S368>/Constant1'
   */
  0.0033528106647474805,

  /* Expression: R
   * Referenced by: '<S349>/Constant'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S369>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S367>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S357>/Constant'
   */
  0.0,

  /* Expression: R
   * Referenced by: '<S365>/Constant1'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S365>/f'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S109>/Constant'
   */
  1.0,

  /* Expression: [0;0;1]
   * Referenced by: '<S11>/Unit Delay'
   */
  { 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S293>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S327>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S298>/f'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S317>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S293>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S300>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S306>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S293>/Constant1'
   */
  0.0,

  /* Expression: 1.002
   * Referenced by: '<S291>/Gain'
   */
  1.002,

  /* Expression: 0
   * Referenced by: '<S14>/Constant'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S228>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_f
   * Referenced by: '<S228>/Merge'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S233>/Discrete-Time Integrator'
   */
  0.25,

  /* Expression: 1
   * Referenced by: '<S229>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S229>/Saturation'
   */
  -1.0,

  /* Expression: 2
   * Referenced by: '<S229>/Gain'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Rate Transition4'
   */
  0.0,

  /* Computed Parameter: ResettableDelay_DelayLength
   * Referenced by: '<S437>/Resettable Delay'
   */
  1U,

  /* Expression: false
   * Referenced by: '<S111>/Relay'
   */
  0,

  /* Expression: true
   * Referenced by: '<S111>/Relay'
   */
  1,

  /* Computed Parameter: Constant_Value_h4
   * Referenced by: '<S439>/Constant'
   */
  0,

  /* Expression: [true;true;true;true;true]
   * Referenced by: '<S5>/Constant'
   */
  { 1, 1, 1, 1, 1 },

  /* Computed Parameter: RateTransition4_11_InitialCondi
   * Referenced by: '<S1>/Rate Transition4'
   */
  0,

  /* Computed Parameter: RateTransition4_13_InitialCondi
   * Referenced by: '<S1>/Rate Transition4'
   */
  0,

  /* Computed Parameter: RateTransition4_14_InitialCondi
   * Referenced by: '<S1>/Rate Transition4'
   */
  0,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S372>/Switch'
   */
  0,

  /* Computed Parameter: Constant_Value_js
   * Referenced by: '<S21>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_gq
   * Referenced by: '<S110>/Constant'
   */
  0U,

  /* Computed Parameter: Constant2_Value_o
   * Referenced by: '<S396>/Constant2'
   */
  8U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S19>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S20>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: RateTransition4_1_InitialCondit
   * Referenced by: '<S1>/Rate Transition4'
   */
  0U,

  /* Computed Parameter: RateTransition4_8_InitialCondit
   * Referenced by: '<S1>/Rate Transition4'
   */
  0U,

  /* Computed Parameter: RateTransition4_12_InitialCondi
   * Referenced by: '<S1>/Rate Transition4'
   */
  0U,

  /* Computed Parameter: RateTransition4_15_InitialCondi
   * Referenced by: '<S1>/Rate Transition4'
   */
  0U,

  /* Computed Parameter: RateTransition4_18_InitialCondi
   * Referenced by: '<S1>/Rate Transition4'
   */
  0U,

  /* Start of '<S10>/quat_rectify_lib' */
  {
    /* Expression: -1
     * Referenced by: '<S393>/Constant1'
     */
    -1.0,

    /* Expression: 1
     * Referenced by: '<S393>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S393>/Switch'
     */
    0.0
  }
  ,

  /* End of '<S10>/quat_rectify_lib' */

  /* Start of '<S399>/If Warning//Error' */
  {
    /* Expression: 0
     * Referenced by: '<S425>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S424>/Constant1'
     */
    0.0,

    /* Expression: -eye(3)
     * Referenced by: '<S426>/Bias1'
     */
    { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 },

    /* Expression: -1
     * Referenced by: '<S427>/Bias'
     */
    -1.0
  }
  ,

  /* End of '<S399>/If Warning//Error' */

  /* Start of '<S390>/Negative Trace' */
  {
    /* Expression: [0 1]
     * Referenced by: '<S413>/Constant2'
     */
    { 0.0, 1.0 },

    /* Expression: 0.5
     * Referenced by: '<S413>/Constant1'
     */
    0.5,

    /* Expression: 1
     * Referenced by: '<S414>/Constant'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S402>/Gain1'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S402>/Gain3'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S402>/Gain4'
     */
    1.0,

    /* Expression: 0.5
     * Referenced by: '<S402>/Gain'
     */
    0.5,

    /* Expression: [0 1]
     * Referenced by: '<S418>/Constant2'
     */
    { 0.0, 1.0 },

    /* Expression: 0.5
     * Referenced by: '<S418>/Constant1'
     */
    0.5,

    /* Expression: 1
     * Referenced by: '<S419>/Constant'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S403>/Gain1'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S403>/Gain2'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S403>/Gain3'
     */
    1.0,

    /* Expression: 0.5
     * Referenced by: '<S403>/Gain'
     */
    0.5,

    /* Expression: [0 1]
     * Referenced by: '<S408>/Constant2'
     */
    { 0.0, 1.0 },

    /* Expression: 0.5
     * Referenced by: '<S408>/Constant1'
     */
    0.5,

    /* Expression: 1
     * Referenced by: '<S409>/Constant'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S401>/Gain1'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S401>/Gain2'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S401>/Gain3'
     */
    1.0,

    /* Expression: 0.5
     * Referenced by: '<S401>/Gain'
     */
    0.5
  }
  ,

  /* End of '<S390>/Negative Trace' */

  /* Start of '<S390>/Positive Trace' */
  {
    /* Expression: 1
     * Referenced by: '<S398>/Constant'
     */
    1.0,

    /* Expression: 0.5
     * Referenced by: '<S398>/Gain'
     */
    0.5,

    /* Expression: 2
     * Referenced by: '<S398>/Gain1'
     */
    2.0
  }
  ,

  /* End of '<S390>/Positive Trace' */

  /* Start of '<S1>/mode_select_lib' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S387>/Constant'
     */
    0.0,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S389>/Constant'
     */
    25.0,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S388>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S382>/Relay3'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S382>/Relay3'
     */
    0.0,

    /* Computed Parameter: Relay_YOn
     * Referenced by: '<S9>/Relay'
     */
    1.0,

    /* Computed Parameter: Relay_YOff
     * Referenced by: '<S9>/Relay'
     */
    0.0
  }
  ,

  /* End of '<S1>/mode_select_lib' */

  /* Start of '<S288>/target_groundpass_lib1' */
  {
    /* Mask Parameter: NormalizeVector_maxzero
     * Referenced by: '<S343>/Switch'
     */
    0.0,

    /* Mask Parameter: NormalizeVector1_maxzero
     * Referenced by: '<S344>/Switch'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S343>/Constant'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S344>/Constant'
     */
    1.0,

    /* Expression: -1
     * Referenced by: '<S345>/Gain1'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S345>/Gain'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S345>/Constant'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S295>/Gain'
     */
    -1.0
  }
  ,

  /* End of '<S288>/target_groundpass_lib1' */

  /* Start of '<S288>/target_groundpass_lib' */
  {
    /* Mask Parameter: NormalizeVector_maxzero
     * Referenced by: '<S337>/Switch'
     */
    0.0,

    /* Mask Parameter: NormalizeVector1_maxzero
     * Referenced by: '<S338>/Switch'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S337>/Constant'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S338>/Constant'
     */
    1.0,

    /* Expression: -1
     * Referenced by: '<S339>/Gain1'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S339>/Gain'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S339>/Constant'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S294>/Gain'
     */
    -1.0
  }
  ,

  /* End of '<S288>/target_groundpass_lib' */

  /* Start of '<S5>/rwa_allocation_lib' */
  {
    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S275>/Discrete-Time Integrator'
     */
    0.25,

    /* Expression: 0
     * Referenced by: '<S275>/Discrete-Time Integrator'
     */
    0.0
  }
  ,

  /* End of '<S5>/rwa_allocation_lib' */

  /* Start of '<S5>/quat_err_lib' */
  {
    /* Start of '<S231>/quat_rectify_lib' */
    {
      /* Expression: -1
       * Referenced by: '<S269>/Constant1'
       */
      -1.0,

      /* Expression: 1
       * Referenced by: '<S269>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S269>/Switch'
       */
      0.0
    }
    /* End of '<S231>/quat_rectify_lib' */
  }
  ,

  /* End of '<S5>/quat_err_lib' */

  /* Start of '<S230>/If Action Subsystem5' */
  {
    /* Expression: 0
     * Referenced by: '<S266>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S230>/If Action Subsystem5' */

  /* Start of '<S230>/If Action Subsystem4' */
  {
    /* Expression: 2
     * Referenced by: '<S265>/Constant'
     */
    2.0
  }
  ,

  /* End of '<S230>/If Action Subsystem4' */

  /* Start of '<S230>/If Action Subsystem3' */
  {
    /* Expression: 1
     * Referenced by: '<S264>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S230>/If Action Subsystem3' */

  /* Start of '<S230>/If Action Subsystem2' */
  {
    /* Expression: 0
     * Referenced by: '<S263>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S230>/If Action Subsystem2' */

  /* Start of '<S230>/If Action Subsystem1' */
  {
    /* Expression: 2
     * Referenced by: '<S262>/Constant'
     */
    2.0
  }
  ,

  /* End of '<S230>/If Action Subsystem1' */

  /* Start of '<S230>/If Action Subsystem' */
  {
    /* Expression: 1
     * Referenced by: '<S261>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S230>/If Action Subsystem' */

  /* Start of '<S238>/sunSeek_lib' */
  {
    /* Mask Parameter: NormalizeVector_maxzero
     * Referenced by: '<S260>/Switch'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S260>/Constant'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S258>/sat_pm1'
     */
    1.0,

    /* Expression: -1
     * Referenced by: '<S258>/sat_pm1'
     */
    -1.0,

    /* Expression: 1/2
     * Referenced by: '<S258>/Gain'
     */
    0.5
  }
  ,

  /* End of '<S238>/sunSeek_lib' */

  /* Start of '<S236>/null_control_lib1' */
  {
    /* Expression: zeros(3,1)
     * Referenced by: '<S255>/null_control_input'
     */
    { 0.0, 0.0, 0.0 }
  }
  ,

  /* End of '<S236>/null_control_lib1' */

  /* Start of '<S1>/MEKF_lib' */
  {
    /* Mask Parameter: Normalization6_Bias
     * Referenced by: '<S177>/Normalization6'
     */
    1.0E-10,

    /* Mask Parameter: Normalization7_Bias
     * Referenced by: '<S177>/Normalization7'
     */
    1.0E-10,

    /* Mask Parameter: DirectionCosineMatrixtoQuaterni
     * Referenced by:
     *   '<S191>/If Warning//Error'
     *   '<S191>/Constant'
     */
    1.0,

    /* Mask Parameter: NormalizeVector1_maxzero
     * Referenced by: '<S175>/Switch'
     */
    0.0,

    /* Mask Parameter: NormalizeVector_maxzero
     * Referenced by: '<S174>/Switch'
     */
    0.0,

    /* Mask Parameter: DirectionCosineMatrixtoQuater_o
     * Referenced by: '<S191>/If Warning//Error'
     */
    4.4408920985006262E-16,

    /* Mask Parameter: DetectRisePositive_vinit
     * Referenced by: '<S157>/Delay Input1'
     */
    0,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S117>/Constant'
     */
    0U,

    /* Mask Parameter: CompareToConstant_const_b
     * Referenced by: '<S156>/Constant'
     */
    2U,

    /* Mask Parameter: CompareToConstant_const_n
     * Referenced by: '<S128>/Constant'
     */
    2U,

    /* Expression: [0;0;0]
     * Referenced by: '<S3>/Constant'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: 0.5
     * Referenced by: '<S145>/Constant'
     */
    0.5,

    /* Expression: 2
     * Referenced by: '<S145>/Gain2'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S145>/Gain'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S145>/Gain1'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S146>/Gain'
     */
    2.0,

    /* Expression: 0.5
     * Referenced by: '<S146>/Constant'
     */
    0.5,

    /* Expression: 2
     * Referenced by: '<S146>/Gain2'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S146>/Gain1'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S147>/Gain'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S147>/Gain1'
     */
    2.0,

    /* Expression: 0.5
     * Referenced by: '<S147>/Constant'
     */
    0.5,

    /* Expression: 2
     * Referenced by: '<S147>/Gain2'
     */
    2.0,

    /* Expression: 0.5
     * Referenced by: '<S151>/Constant'
     */
    0.5,

    /* Expression: 2
     * Referenced by: '<S151>/Gain2'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S151>/Gain'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S151>/Gain1'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S152>/Gain'
     */
    2.0,

    /* Expression: 0.5
     * Referenced by: '<S152>/Constant'
     */
    0.5,

    /* Expression: 2
     * Referenced by: '<S152>/Gain2'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S152>/Gain1'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S153>/Gain'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S153>/Gain1'
     */
    2.0,

    /* Expression: 0.5
     * Referenced by: '<S153>/Constant'
     */
    0.5,

    /* Expression: 2
     * Referenced by: '<S153>/Gain2'
     */
    2.0,

    /* Expression: zeros(3,3)
     * Referenced by: '<S132>/Constant1'
     */
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    /* Expression: zeros(3,3)
     * Referenced by: '<S132>/Constant2'
     */
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    /* Expression: -1
     * Referenced by: '<S137>/Gain'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S137>/Gain1'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S137>/Gain2'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S137>/Gain3'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S137>/Gain4'
     */
    -1.0,

    /* Expression: -1
     * Referenced by: '<S137>/Gain5'
     */
    -1.0,

    /* Expression: 0.5
     * Referenced by: '<S137>/Gain6'
     */
    0.5,

    /* Expression: [1 0 0 0]
     * Referenced by: '<S188>/Merge'
     */
    { 1.0, 0.0, 0.0, 0.0 },

    /* Expression: 1
     * Referenced by: '<S174>/Constant'
     */
    1.0,

    /* Expression: 1
     * Referenced by: '<S175>/Constant'
     */
    1.0,

    /* Expression: zeros(3,1)
     * Referenced by: '<S171>/Constant'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: 0.5
     * Referenced by: '<S170>/Constant'
     */
    0.5,

    /* Expression: 0.5
     * Referenced by: '<S165>/Constant'
     */
    0.5,

    /* Expression: -1
     * Referenced by: '<S165>/Gain'
     */
    -1.0,

    /* Expression: 3
     * Referenced by: '<S123>/multiply'
     */
    3.0,

    /* Computed Parameter: q_p_merge_InitialOutput
     * Referenced by: '<S3>/q_p_merge'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S121>/Switch'
     */
    2.0,

    /* Computed Parameter: Constant_Value_d
     * Referenced by: '<S158>/Constant'
     */
    0,

    /* Computed Parameter: Constant_Value_m0
     * Referenced by: '<S129>/Constant'
     */
    3U,

    /* Computed Parameter: cnst_Value
     * Referenced by: '<S131>/cnst'
     */
    0U,

    /* Start of '<S124>/quat_rectify_lib' */
    {
      /* Expression: -1
       * Referenced by: '<S167>/Constant1'
       */
      -1.0,

      /* Expression: 1
       * Referenced by: '<S167>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S167>/Switch'
       */
      0.0
    }
    ,

    /* End of '<S124>/quat_rectify_lib' */

    /* Start of '<S124>/CrossProdMatrix_lib1' */
    {
      /* Expression: 0
       * Referenced by: '<S162>/null'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S162>/Gain'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S162>/Gain3'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S162>/Gain1'
       */
      -1.0
    }
    ,

    /* End of '<S124>/CrossProdMatrix_lib1' */

    /* Start of '<S124>/CrossProdMatrix_lib' */
    {
      /* Expression: 0
       * Referenced by: '<S161>/null'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S161>/Gain'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S161>/Gain3'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S161>/Gain1'
       */
      -1.0
    }
    ,

    /* End of '<S124>/CrossProdMatrix_lib' */

    /* Start of '<S125>/quat_rectify_lib' */
    {
      /* Expression: -1
       * Referenced by: '<S181>/Constant1'
       */
      -1.0,

      /* Expression: 1
       * Referenced by: '<S181>/Constant'
       */
      1.0,

      /* Expression: 0
       * Referenced by: '<S181>/Switch'
       */
      0.0
    }
    ,

    /* End of '<S125>/quat_rectify_lib' */

    /* Start of '<S125>/parallel_protection_lib1' */
    {
      /* Expression: 0
       * Referenced by: '<S180>/Switch'
       */
      0.0,

      /* Expression: true
       * Referenced by: '<S180>/Constant'
       */
      1,

      /* Expression: false
       * Referenced by: '<S180>/Constant1'
       */
      0
    }
    ,

    /* End of '<S125>/parallel_protection_lib1' */

    /* Start of '<S125>/parallel_protection_lib' */
    {
      /* Expression: 0
       * Referenced by: '<S179>/Switch'
       */
      0.0,

      /* Expression: true
       * Referenced by: '<S179>/Constant'
       */
      1,

      /* Expression: false
       * Referenced by: '<S179>/Constant1'
       */
      0
    }
    ,

    /* End of '<S125>/parallel_protection_lib' */

    /* Start of '<S191>/If Warning//Error' */
    {
      /* Expression: 0
       * Referenced by: '<S217>/Constant1'
       */
      0.0,

      /* Expression: 0
       * Referenced by: '<S216>/Constant1'
       */
      0.0,

      /* Expression: -eye(3)
       * Referenced by: '<S218>/Bias1'
       */
      { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 },

      /* Expression: -1
       * Referenced by: '<S219>/Bias'
       */
      -1.0
    }
    ,

    /* End of '<S191>/If Warning//Error' */

    /* Start of '<S188>/Negative Trace' */
    {
      /* Expression: [0 1]
       * Referenced by: '<S205>/Constant2'
       */
      { 0.0, 1.0 },

      /* Expression: 0.5
       * Referenced by: '<S205>/Constant1'
       */
      0.5,

      /* Expression: 1
       * Referenced by: '<S206>/Constant'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S194>/Gain1'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S194>/Gain3'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S194>/Gain4'
       */
      1.0,

      /* Expression: 0.5
       * Referenced by: '<S194>/Gain'
       */
      0.5,

      /* Expression: [0 1]
       * Referenced by: '<S210>/Constant2'
       */
      { 0.0, 1.0 },

      /* Expression: 0.5
       * Referenced by: '<S210>/Constant1'
       */
      0.5,

      /* Expression: 1
       * Referenced by: '<S211>/Constant'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S195>/Gain1'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S195>/Gain2'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S195>/Gain3'
       */
      1.0,

      /* Expression: 0.5
       * Referenced by: '<S195>/Gain'
       */
      0.5,

      /* Expression: [0 1]
       * Referenced by: '<S200>/Constant2'
       */
      { 0.0, 1.0 },

      /* Expression: 0.5
       * Referenced by: '<S200>/Constant1'
       */
      0.5,

      /* Expression: 1
       * Referenced by: '<S201>/Constant'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S193>/Gain1'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S193>/Gain2'
       */
      1.0,

      /* Expression: 1
       * Referenced by: '<S193>/Gain3'
       */
      1.0,

      /* Expression: 0.5
       * Referenced by: '<S193>/Gain'
       */
      0.5
    }
    ,

    /* End of '<S188>/Negative Trace' */

    /* Start of '<S188>/Positive Trace' */
    {
      /* Expression: 1
       * Referenced by: '<S190>/Constant'
       */
      1.0,

      /* Expression: 0.5
       * Referenced by: '<S190>/Gain'
       */
      0.5,

      /* Expression: 2
       * Referenced by: '<S190>/Gain1'
       */
      2.0
    }
    ,

    /* End of '<S188>/Positive Trace' */

    /* Start of '<S3>/TRIADActivation_lib' */
    {
      /* Computed Parameter: Delay_DelayLength
       * Referenced by: '<S159>/Delay'
       */
      10U,

      /* Computed Parameter: Delay_InitialCondition
       * Referenced by: '<S159>/Delay'
       */
      1
    }
    ,

    /* End of '<S3>/TRIADActivation_lib' */

    /* Start of '<S132>/CrossProdMatrix_lib1' */
    {
      /* Expression: 0
       * Referenced by: '<S139>/null'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S139>/Gain'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S139>/Gain3'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S139>/Gain1'
       */
      -1.0
    }
    ,

    /* End of '<S132>/CrossProdMatrix_lib1' */

    /* Start of '<S132>/CrossProdMatrix_lib' */
    {
      /* Expression: 0
       * Referenced by: '<S138>/null'
       */
      0.0,

      /* Expression: -1
       * Referenced by: '<S138>/Gain'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S138>/Gain3'
       */
      -1.0,

      /* Expression: -1
       * Referenced by: '<S138>/Gain1'
       */
      -1.0
    }
    ,

    /* End of '<S132>/CrossProdMatrix_lib' */

    /* Start of '<S115>/parallel_protection_lib' */
    {
      /* Expression: 0
       * Referenced by: '<S126>/Switch'
       */
      0.0,

      /* Expression: true
       * Referenced by: '<S126>/Constant'
       */
      1,

      /* Expression: false
       * Referenced by: '<S126>/Constant1'
       */
      0
    }
    /* End of '<S115>/parallel_protection_lib' */
  }
  ,

  /* End of '<S1>/MEKF_lib' */

  /* Start of '<S2>/maggyroProcessing_lib1' */
  {
    /* Mask Parameter: CheckStaticRange1_min
     * Referenced by: '<S76>/min_val'
     */
    0.0,

    /* Mask Parameter: CheckStaticRange2_min
     * Referenced by: '<S77>/min_val'
     */
    0.0,

    /* Mask Parameter: CheckStaticRange4_min
     * Referenced by: '<S78>/min_val'
     */
    0.0,

    /* Expression: [0;0;0]
     * Referenced by: '<S95>/Constant'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: [0;0;0]
     * Referenced by: '<S94>/Constant'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: [0;0;0]
     * Referenced by: '<S96>/Constant'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: 1/2
     * Referenced by: '<S69>/Gain1'
     */
    0.5,

    /* Expression: 1
     * Referenced by: '<S66>/Gain1'
     */
    1.0,

    /* Expression: 1/3
     * Referenced by: '<S65>/Gain'
     */
    0.33333333333333331,

    /* Expression: rotation_calibration_matrix(:,:,1)
     * Referenced by: '<S64>/Constant'
     */
    { 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

    /* Expression: rotation_calibration_matrix(:,:,3)
     * Referenced by: '<S64>/Constant2'
     */
    { 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

    /* Expression: rotation_calibration_matrix(:,:,2)
     * Referenced by: '<S64>/Constant1'
     */
    { 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

    /* Computed Parameter: VariableSelector_Elements
     * Referenced by: '<S68>/Variable Selector'
     */
    0,

    /* Computed Parameter: VariableSelector1_Elements
     * Referenced by: '<S68>/Variable Selector1'
     */
    1,

    /* Computed Parameter: VariableSelector2_Elements
     * Referenced by: '<S68>/Variable Selector2'
     */
    2,

    /* Computed Parameter: VariableSelector6_Elements
     * Referenced by: '<S69>/Variable Selector6'
     */
    0,

    /* Computed Parameter: VariableSelector7_Elements
     * Referenced by: '<S69>/Variable Selector7'
     */
    1,

    /* Computed Parameter: VariableSelector8_Elements
     * Referenced by: '<S69>/Variable Selector8'
     */
    2,

    /* Computed Parameter: VariableSelector6_Elements_m
     * Referenced by: '<S66>/Variable Selector6'
     */
    0,

    /* Computed Parameter: VariableSelector7_Elements_b
     * Referenced by: '<S66>/Variable Selector7'
     */
    1,

    /* Computed Parameter: VariableSelector8_Elements_g
     * Referenced by: '<S66>/Variable Selector8'
     */
    2,

    /* Computed Parameter: VariableSelector3_Elements
     * Referenced by: '<S65>/Variable Selector3'
     */
    0,

    /* Computed Parameter: VariableSelector4_Elements
     * Referenced by: '<S65>/Variable Selector4'
     */
    1,

    /* Computed Parameter: VariableSelector5_Elements
     * Referenced by: '<S65>/Variable Selector5'
     */
    2,

    /* Computed Parameter: VariableSelector1_Elements_b
     * Referenced by: '<S64>/Variable Selector1'
     */
    1,

    /* Computed Parameter: VariableSelector2_Elements_g
     * Referenced by: '<S64>/Variable Selector2'
     */
    2,

    /* Computed Parameter: VariableSelector_Elements_e
     * Referenced by: '<S64>/Variable Selector'
     */
    0,

    /* Computed Parameter: VariableSelector6_Elements_o
     * Referenced by: '<S67>/Variable Selector6'
     */
    0,

    /* Computed Parameter: VariableSelector7_Elements_c
     * Referenced by: '<S67>/Variable Selector7'
     */
    1,

    /* Computed Parameter: VariableSelector8_Elements_e
     * Referenced by: '<S67>/Variable Selector8'
     */
    2,

    /* Expression: true
     * Referenced by: '<S66>/Constant'
     */
    1,

    /* Expression: false
     * Referenced by: '<S65>/Constant'
     */
    0,

    /* Start of '<S25>/If Action Subsystem14' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S81>/Constant'
       */
      0
    }
    ,

    /* End of '<S25>/If Action Subsystem14' */

    /* Start of '<S25>/If Action Subsystem4' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S84>/Constant'
       */
      0
    }
    ,

    /* End of '<S25>/If Action Subsystem4' */

    /* Start of '<S25>/If Action Subsystem2' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S82>/Constant'
       */
      0
    }
    ,

    /* End of '<S25>/If Action Subsystem2' */

    /* Start of '<S24>/If Action Subsystem2' */
    {
      /* Expression: [0;0;0]
       * Referenced by: '<S72>/Constant'
       */
      { 0.0, 0.0, 0.0 }
    }
    ,

    /* End of '<S24>/If Action Subsystem2' */

    /* Start of '<S24>/If Action Subsystem1' */
    {
      /* Expression: [0;0;0]
       * Referenced by: '<S70>/Constant'
       */
      { 0.0, 0.0, 0.0 }
    }
    ,

    /* End of '<S24>/If Action Subsystem1' */

    /* Start of '<S24>/If Action Subsystem14' */
    {
      /* Expression: [0;0;0]
       * Referenced by: '<S71>/Constant'
       */
      { 0.0, 0.0, 0.0 }
    }
    /* End of '<S24>/If Action Subsystem14' */
  }
  ,

  /* End of '<S2>/maggyroProcessing_lib1' */

  /* Start of '<S2>/maggyroProcessing_lib' */
  {
    /* Mask Parameter: CheckStaticRange1_min
     * Referenced by: '<S34>/min_val'
     */
    0.0,

    /* Mask Parameter: CheckStaticRange2_min
     * Referenced by: '<S35>/min_val'
     */
    0.0,

    /* Mask Parameter: CheckStaticRange4_min
     * Referenced by: '<S36>/min_val'
     */
    0.0,

    /* Expression: [0;0;0]
     * Referenced by: '<S53>/Constant'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: [0;0;0]
     * Referenced by: '<S52>/Constant'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: [0;0;0]
     * Referenced by: '<S54>/Constant'
     */
    { 0.0, 0.0, 0.0 },

    /* Expression: 1/2
     * Referenced by: '<S27>/Gain1'
     */
    0.5,

    /* Expression: 1
     * Referenced by: '<S24>/Gain1'
     */
    1.0,

    /* Expression: 1/3
     * Referenced by: '<S23>/Gain'
     */
    0.33333333333333331,

    /* Expression: rotation_calibration_matrix(:,:,1)
     * Referenced by: '<S22>/Constant'
     */
    { 0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

    /* Expression: rotation_calibration_matrix(:,:,3)
     * Referenced by: '<S22>/Constant2'
     */
    { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

    /* Expression: rotation_calibration_matrix(:,:,2)
     * Referenced by: '<S22>/Constant1'
     */
    { 0.70710678118654757, 0.70710678118654757, 0.0, -0.70710678118654757,
      0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

    /* Computed Parameter: VariableSelector_Elements
     * Referenced by: '<S26>/Variable Selector'
     */
    0,

    /* Computed Parameter: VariableSelector1_Elements
     * Referenced by: '<S26>/Variable Selector1'
     */
    1,

    /* Computed Parameter: VariableSelector2_Elements
     * Referenced by: '<S26>/Variable Selector2'
     */
    2,

    /* Computed Parameter: VariableSelector6_Elements
     * Referenced by: '<S27>/Variable Selector6'
     */
    0,

    /* Computed Parameter: VariableSelector7_Elements
     * Referenced by: '<S27>/Variable Selector7'
     */
    1,

    /* Computed Parameter: VariableSelector8_Elements
     * Referenced by: '<S27>/Variable Selector8'
     */
    2,

    /* Computed Parameter: VariableSelector6_Elements_m
     * Referenced by: '<S24>/Variable Selector6'
     */
    0,

    /* Computed Parameter: VariableSelector7_Elements_b
     * Referenced by: '<S24>/Variable Selector7'
     */
    1,

    /* Computed Parameter: VariableSelector8_Elements_g
     * Referenced by: '<S24>/Variable Selector8'
     */
    2,

    /* Computed Parameter: VariableSelector3_Elements
     * Referenced by: '<S23>/Variable Selector3'
     */
    0,

    /* Computed Parameter: VariableSelector4_Elements
     * Referenced by: '<S23>/Variable Selector4'
     */
    1,

    /* Computed Parameter: VariableSelector5_Elements
     * Referenced by: '<S23>/Variable Selector5'
     */
    2,

    /* Computed Parameter: VariableSelector1_Elements_b
     * Referenced by: '<S22>/Variable Selector1'
     */
    1,

    /* Computed Parameter: VariableSelector2_Elements_g
     * Referenced by: '<S22>/Variable Selector2'
     */
    2,

    /* Computed Parameter: VariableSelector_Elements_e
     * Referenced by: '<S22>/Variable Selector'
     */
    0,

    /* Computed Parameter: VariableSelector6_Elements_o
     * Referenced by: '<S25>/Variable Selector6'
     */
    0,

    /* Computed Parameter: VariableSelector7_Elements_c
     * Referenced by: '<S25>/Variable Selector7'
     */
    1,

    /* Computed Parameter: VariableSelector8_Elements_e
     * Referenced by: '<S25>/Variable Selector8'
     */
    2,

    /* Expression: true
     * Referenced by: '<S24>/Constant'
     */
    1,

    /* Expression: false
     * Referenced by: '<S23>/Constant'
     */
    0,

    /* Start of '<S25>/If Action Subsystem14' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S39>/Constant'
       */
      0
    }
    ,

    /* End of '<S25>/If Action Subsystem14' */

    /* Start of '<S25>/If Action Subsystem4' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S42>/Constant'
       */
      0
    }
    ,

    /* End of '<S25>/If Action Subsystem4' */

    /* Start of '<S25>/If Action Subsystem2' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S40>/Constant'
       */
      0
    }
    ,

    /* End of '<S25>/If Action Subsystem2' */

    /* Start of '<S24>/If Action Subsystem2' */
    {
      /* Expression: [0;0;0]
       * Referenced by: '<S30>/Constant'
       */
      { 0.0, 0.0, 0.0 }
    }
    ,

    /* End of '<S24>/If Action Subsystem2' */

    /* Start of '<S24>/If Action Subsystem1' */
    {
      /* Expression: [0;0;0]
       * Referenced by: '<S28>/Constant'
       */
      { 0.0, 0.0, 0.0 }
    }
    ,

    /* End of '<S24>/If Action Subsystem1' */

    /* Start of '<S24>/If Action Subsystem14' */
    {
      /* Expression: [0;0;0]
       * Referenced by: '<S29>/Constant'
       */
      { 0.0, 0.0, 0.0 }
    }
    /* End of '<S24>/If Action Subsystem14' */
  }
  /* End of '<S2>/maggyroProcessing_lib' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: soar_interface_lib0.h
 *
 * Code generated for Simulink model 'soar_interface_lib0'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep  3 10:45:38 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_soar_interface_lib0_h_
#define RTW_HEADER_soar_interface_lib0_h_
#include <gnc_build/FSW_Lib_ert_rtw/rtwtypes.h>

#include "zero_crossing_types.h"
#include <math.h>
#include <string.h>
#ifndef soar_interface_lib0_COMMON_INCLUDES_
# define soar_interface_lib0_COMMON_INCLUDES_
#include <gnc_build/FSW_Lib_ert_rtw/rtwtypes.h>
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* soar_interface_lib0_COMMON_INCLUDES_ */

#include <gnc_build/FSW_Lib_ert_rtw/rtGetNaN.h>
#include <gnc_build/FSW_Lib_ert_rtw/rt_nonfinite.h>
#include <gnc_build/FSW_Lib_ert_rtw/rtGetInf.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Custom Type definition for MATLAB Function: '<S5>/SOLVE' */
#ifndef struct_tag_sKpQB9jVSEZrFP5iOeb0DOE
#define struct_tag_sKpQB9jVSEZrFP5iOeb0DOE

struct tag_sKpQB9jVSEZrFP5iOeb0DOE
{
  real_T sc_mode;
  real_T quat_in[4];
  real_T w_body_radps[3];
  real_T hw_Nms[3];
  real_T quat_cmd[4];
  real_T w_body_cmd_radps[3];
  real_T sun_inertial_unit[3];
  real_T gps_epoch_s[2];
  real_T gps_time_s[2];
  real_T cmd_torque[3];
  real_T cmd_state[10];
};

#endif                                 /*struct_tag_sKpQB9jVSEZrFP5iOeb0DOE*/

#ifndef typedef_sKpQB9jVSEZrFP5iOeb0DOE
#define typedef_sKpQB9jVSEZrFP5iOeb0DOE

typedef struct tag_sKpQB9jVSEZrFP5iOeb0DOE sKpQB9jVSEZrFP5iOeb0DOE;

#endif                                 /*typedef_sKpQB9jVSEZrFP5iOeb0DOE*/

#ifndef struct_tag_sY11QAKtY7AAPAFOIKTlv1B
#define struct_tag_sY11QAKtY7AAPAFOIKTlv1B

struct tag_sY11QAKtY7AAPAFOIKTlv1B
{
  sKpQB9jVSEZrFP5iOeb0DOE ic;
  char_T config[3];
  real_T N;
  real_T dt;
  real_T sample_time_s;
  real_T interp_sample_time_s;
  real_T c_size;
  real_T Air_size;
  real_T Ajc_size;
  real_T Apr_size;
  real_T b_size;
  real_T Gir_size;
  real_T Gjc_size;
  real_T Gpr_size;
  real_T h_size;
  real_T q_size;
  real_T y_size;
  real_T l_dim;
  real_T soc_dim[21];
  real_T inertia[9];
  real_T w_max;
  real_T T_max;
  real_T s_min;
  real_T s_max;
  real_T w_v;
  real_T Dq[16];
  real_T Dw[9];
  real_T Dh[9];
  real_T Dx[100];
  real_T iDx[100];
  real_T Du[9];
  real_T Ds;
  real_T Dg;
  real_T DX[10000];
  real_T DU[900];
};

#endif                                 /*struct_tag_sY11QAKtY7AAPAFOIKTlv1B*/

#ifndef typedef_sY11QAKtY7AAPAFOIKTlv1B
#define typedef_sY11QAKtY7AAPAFOIKTlv1B

typedef struct tag_sY11QAKtY7AAPAFOIKTlv1B sY11QAKtY7AAPAFOIKTlv1B;

#endif                                 /*typedef_sY11QAKtY7AAPAFOIKTlv1B*/

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T ResettableDelay_DSTATE[10];   /* '<S4>/Resettable Delay' */
  real_T rtb_TmpSignalConversionAtGprO_m[834];
  real_T rtb_TmpSignalConversionAtAprO_c[1278];
  real_T EH[10000];
  real_T BE[3000];
  real_T G[157368];
  real_T A[38844];
  real_T Air[1278];
  real_T Apr[1278];
  real_T Gir[834];
  real_T Gpr[834];
  real_T Hw[9960];
  real_T Hu[9960];
  real_T Hv[33200];
  real_T Hev[33200];
  real_T Gquad_[30544];
  real_T Gquad__[50464];
  real_T Hv_tmp[10000];
  real_T dv0[10000];
  real_T dv1[900];
  real_T dv2[3000];
  real_T MI[1328];
  real_T UnitDelay_DSTATE;             /* '<S4>/Unit Delay' */
  int32_T rtb_DataTypeConversion9_k[1278];
  uint32_T Counter_Count;              /* '<S1>/Counter' */
  uint32_T Counter_ClkEphState;        /* '<S1>/Counter' */
  uint8_T icLoad;                      /* '<S4>/Resettable Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S3>/Delay Input1' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ResettableDelay_Reset_ZCE;/* '<S4>/Resettable Delay' */
  ZCSigState soar_lib_Trig_ZCE;        /* '<S1>/soar_lib' */
} PrevZCX;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T sc_mode;                      /* '<Root>/sc_mode' */
  real_T quat_in[4];                   /* '<Root>/quat_in' */
  real_T w_body_radps[3];              /* '<Root>/w_body_radps' */
  real_T hw_Nms_init[3];               /* '<Root>/hw_Nms_init' */
  real_T quat_cmd[4];                  /* '<Root>/quat_cmd' */
  real_T w_body_cmd_radps[3];          /* '<Root>/w_body_cmd_radps' */
  real_T sun_inertial_unit[3];         /* '<Root>/sun_inertial_unit' */
  real_T GPS_epoch[2];                 /* '<Root>/GPS_epoch' */
  real_T GPS_time[2];                  /* '<Root>/GPS_time' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T command_torque[3];            /* '<Root>/command_torque' */
  real_T command_state[10];            /* '<Root>/command_state' */
  real_T X_p[100];                     /* '<Root>/X' */
  real_T U[30];                        /* '<Root>/U' */
  real_T s;                            /* '<Root>/s' */
  real_T exitcode[17];                 /* '<Root>/exitcode' */
  real_T time[15];                     /* '<Root>/time' */
  uint32_T soar_count;                 /* '<Root>/soar_count' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void soar_interface_lib0_initialize(void);
extern void soar_interface_lib0_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S4>/Reshape' : Reshape block reduction
 * Block '<S4>/Reshape1' : Reshape block reduction
 * Block '<S10>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion14' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('soac_autocode_test/soar_interface_lib')    - opens subsystem soac_autocode_test/soar_interface_lib
 * hilite_system('soac_autocode_test/soar_interface_lib/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'soac_autocode_test'
 * '<S1>'   : 'soac_autocode_test/soar_interface_lib'
 * '<S2>'   : 'soac_autocode_test/soar_interface_lib/Compare To Constant'
 * '<S3>'   : 'soac_autocode_test/soar_interface_lib/Detect Rise Positive'
 * '<S4>'   : 'soac_autocode_test/soar_interface_lib/soar_interp'
 * '<S5>'   : 'soac_autocode_test/soar_interface_lib/soar_lib'
 * '<S6>'   : 'soac_autocode_test/soar_interface_lib/Detect Rise Positive/Positive'
 * '<S7>'   : 'soac_autocode_test/soar_interface_lib/soar_interp/INTERP'
 * '<S8>'   : 'soac_autocode_test/soar_interface_lib/soar_lib/INITIALIZE'
 * '<S9>'   : 'soac_autocode_test/soar_interface_lib/soar_lib/SOLVE'
 * '<S10>'  : 'soac_autocode_test/soar_interface_lib/soar_lib/call to ECOS SOCP solver (compiled C function)'
 */
#endif                                 /* RTW_HEADER_soar_interface_lib0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

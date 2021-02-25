/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:43:08 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FSW_Lib_h_
#define RTW_HEADER_FSW_Lib_h_
#include <math.h>
#include <string.h>
#ifndef FSW_Lib_COMMON_INCLUDES_
# define FSW_Lib_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include "FSW_Lib_types.h"

/* Child system includes */
#include "MEKF_lib.h"
#include "PD_Controller_Lib.h"
#include "asmController_lib.h"
#include "mode_select_lib.h"
#include "null_control_lib.h"
#include "quat_err_lib.h"
#include "rwa_allocation_lib.h"
#include "sunSeek_lib.h"
#include "target_generation_lib.h"
#include "target_groundpass_lib.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_IfWarningError IfWarningError_p;  /* '<S281>/If Warning//Error' */
  DW_mode_select_lib mode_select_lib_k;/* '<S1>/mode_select_lib' */
  DW_rwa_allocation_lib rwa_allocation_lib_o;/* '<S5>/rwa_allocation_lib' */
  DW_MEKF_lib MEKF_lib_g;              /* '<S1>/MEKF_lib' */
  soar_telemetry soar_telemetry_d;     /* '<S1>/Rate Transition4' */
  soar_telemetry RateTransition4_18_Buffer0;/* '<S1>/Rate Transition4' */
  real_T orbit_tle[9];                 /* '<S1>/Rate Transition' */
  real_T Gain[3];                      /* '<S171>/Gain' */
  real_T RateTransition2[2];           /* '<S2>/Rate Transition2' */
  real_T ss_2_body[3];                 /* '<S12>/ss_2_body' */
  real_T RateTransition3[9];           /* '<S2>/Rate Transition3' */
  real_T RateTransition4[9];           /* '<S2>/Rate Transition4' */
  real_T RateTransition1[4];           /* '<S4>/Rate Transition1' */
  real_T telecom[6];                   /* '<S1>/Rate Transition' */
  real_T target_latlonalt[3];          /* '<S1>/Rate Transition' */
  real_T Product1[3];                  /* '<S169>/Product1' */
  real_T quat_soar_cmd[4];             /* '<S1>/Rate Transition' */
  real_T RateTransition1_h[6];         /* '<S2>/Rate Transition1' */
  real_T Merge[3];                     /* '<S123>/Merge' */
  real_T Merge1[3];                    /* '<S123>/Merge1' */
  real_T rwa_cmd_rpm[4];               /* '<S1>/Rate Transition3' */
  real_T mtq_cmd_Am2[3];               /* '<S1>/Rate Transition3' */
  real_T sc_quat[4];                   /* '<S1>/Rate Transition4' */
  real_T sc_body_rates_radps[3];       /* '<S1>/Rate Transition4' */
  real_T cmd_quat[4];                  /* '<S1>/Rate Transition4' */
  real_T cmd_body_rates_radps[3];      /* '<S1>/Rate Transition4' */
  real_T mekf_3sigma_rad[6];           /* '<S1>/Rate Transition4' */
  real_T mekf_bias_radps[3];           /* '<S1>/Rate Transition4' */
  real_T r_eci_m[3];                   /* '<S1>/Rate Transition4' */
  real_T Merge_n[4];                   /* '<S272>/Merge' */
  real_T opt_state[100];               /* '<S277>/Rate Transition1' */
  real_T opt_ctrl_Nm[30];              /* '<S277>/Rate Transition1' */
  real_T exitcode[17];                 /* '<S277>/Rate Transition1' */
  real_T slv_time_s[15];               /* '<S277>/Rate Transition1' */
  real_T RateTransition6[4];           /* '<S10>/Rate Transition6' */
  real_T RateTransition2_h[3];         /* '<S10>/Rate Transition2' */
  real_T RateTransition5[3];           /* '<S10>/Rate Transition5' */
  real_T X_f[100];                     /* '<S320>/SOLVE' */
  real_T U[30];                        /* '<S320>/SOLVE' */
  real_T exitcode_b[17];               /* '<S320>/SOLVE' */
  real_T time[15];                     /* '<S320>/SOLVE' */
  real_T Sum[3];                       /* '<S22>/Sum' */
  real_T qmerge[4];                    /* '<S3>/q (+) merge' */
  real_T sun_body_unit[3];             /* '<S11>/MATLAB Function' */
  real_T w_err_radps[3];               /* '<S5>/Sum1' */
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<S127>/Discrete-Time Integrator' */
  real_T ResettableDelay_DSTATE[10];   /* '<S319>/Resettable Delay' */
  real_T RateTransition3_1_Buffer0[4]; /* '<S1>/Rate Transition3' */
  real_T RateTransition3_2_Buffer0[3]; /* '<S1>/Rate Transition3' */
  real_T RateTransition4_2_Buffer0[4]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_3_Buffer0[3]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_4_Buffer0[4]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_5_Buffer0[3]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_6_Buffer0[6]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_7_Buffer0[3]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_9_Buffer0[3]; /* '<S1>/Rate Transition4' */
  real_T rtb_TmpSignalConversionAtAprO_m[1278];
  real_T rtb_TmpSignalConversionAtGprO_c[834];
  real_T EH[10000];
  real_T BE[3000];
  real_T G[157368];
  real_T A[38844];
  real_T Apr[1278];
  real_T Gpr[834];
  real_T Hw[9960];
  real_T Hu[9960];
  real_T Hv[33200];
  real_T Hev[33200];
  real_T Gquad_[30544];
  real_T Gquad__[50464];
  real_T Hv_tmp[10000];
  real_T dv0[900];
  real_T dv1[3000];
  real_T MI[1328];
  real_T MET_utc_s;                    /* '<S1>/Rate Transition' */
  real_T MET_soar_utc_s;               /* '<S1>/Rate Transition' */
  real_T ace_err;                      /* '<S1>/Rate Transition4' */
  real_T elev_gs_rad;                  /* '<S1>/Rate Transition4' */
  real_T elev_targ_rad;                /* '<S1>/Rate Transition4' */
  real_T final_time_s;                 /* '<S277>/Rate Transition1' */
  real_T s;                            /* '<S320>/SOLVE' */
  real_T UnitDelay_DSTATE;             /* '<S319>/Unit Delay' */
  real_T RateTransition4_10_Buffer0;   /* '<S1>/Rate Transition4' */
  real_T RateTransition4_16_Buffer0;   /* '<S1>/Rate Transition4' */
  real_T RateTransition4_17_Buffer0;   /* '<S1>/Rate Transition4' */
  real_T Memory_PreviousInput;         /* '<S253>/Memory' */
  int32_T rtb_TmpSignalConversionAtAirO_k[1278];
  int32_T Air[1278];
  uint32_T soar_count;                 /* '<S277>/Rate Transition1' */
  uint32_T Counter_Count;              /* '<S277>/Counter' */
  uint32_T Counter_ClkEphState;        /* '<S277>/Counter' */
  uint8_T gnc_mode;                    /* '<S1>/Rate Transition4' */
  uint8_T mekf_telem;                  /* '<S1>/Rate Transition4' */
  uint8_T sgp4_flag;                   /* '<S1>/Rate Transition4' */
  uint8_T target_gen_flag;             /* '<S1>/Rate Transition4' */
  uint8_T RateTransition8;             /* '<S10>/Rate Transition8' */
  uint8_T gnc_mode_b;                  /* '<S9>/mode_select' */
  uint8_T RateTransition4_1_Buffer0;   /* '<S1>/Rate Transition4' */
  uint8_T RateTransition4_8_Buffer0;   /* '<S1>/Rate Transition4' */
  uint8_T RateTransition4_12_Buffer0;  /* '<S1>/Rate Transition4' */
  uint8_T RateTransition4_15_Buffer0;  /* '<S1>/Rate Transition4' */
  uint8_T icLoad;                      /* '<S319>/Resettable Delay' */
  boolean_T RateTransition6_b[3];      /* '<S2>/Rate Transition6' */
  boolean_T RateTransition7[3];        /* '<S2>/Rate Transition7' */
  boolean_T RateTransition2_l[4];      /* '<S4>/Rate Transition2' */
  boolean_T RateTransition5_i;         /* '<S2>/Rate Transition5' */
  boolean_T Reshape4;                  /* '<S2>/Reshape4' */
  boolean_T triad_override;            /* '<S1>/Rate Transition' */
  boolean_T eclipse;                   /* '<S1>/Rate Transition4' */
  boolean_T sc_above_gs;               /* '<S1>/Rate Transition4' */
  boolean_T sc_above_targ;             /* '<S1>/Rate Transition4' */
  boolean_T DelayInput1_DSTATE;        /* '<S318>/Delay Input1' */
  boolean_T RateTransition4_11_Buffer0;/* '<S1>/Rate Transition4' */
  boolean_T RateTransition4_13_Buffer0;/* '<S1>/Rate Transition4' */
  boolean_T RateTransition4_14_Buffer0;/* '<S1>/Rate Transition4' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ResettableDelay_Reset_ZCE;/* '<S319>/Resettable Delay' */
  ZCSigState soar_lib_Trig_ZCE;        /* '<S277>/soar_lib' */
} PrevZCX;

/* Invariant block signals (default storage) */
typedef struct {
  ConstB_target_groundpass_lib target_groundpass_lib_i;/* '<S169>/target_groundpass_lib' */
  ConstB_null_control_lib null_control_lib_g;/* '<S129>/null_control_lib' */
  ConstB_null_control_lib null_control_lib1;/* '<S130>/null_control_lib1' */
} ConstB;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: fswParams.allocator
   * Referenced by: '<S161>/Constant'
   */
  RWA Constant_Value;
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  sensor_bus sensor_meas;              /* '<Root>/sensor_meas' */
  cdh_data telecommands;               /* '<Root>/telecommands' */
  actuator_meas actuator_meas_l;       /* '<Root>/act_meas' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  fsw_out fsw_out_n;                   /* '<Root>/fsw_out' */
  fsw_telemetry fsw_telem;             /* '<Root>/fsw_telem' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;
extern const ConstB rtConstB;          /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void FSW_Lib_initialize(void);
extern void FSW_Lib_step0(void);
extern void FSW_Lib_step1(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S169>/Product2' : Unused code path elimination
 * Block '<S171>/Gain3' : Unused code path elimination
 * Block '<S171>/Product1' : Unused code path elimination
 * Block '<S7>/Constant1' : Unused code path elimination
 * Block '<S7>/Constant7' : Unused code path elimination
 * Block '<S8>/Constant1' : Unused code path elimination
 * Block '<S8>/Constant10' : Unused code path elimination
 * Block '<S8>/Constant11' : Unused code path elimination
 * Block '<S8>/Constant12' : Unused code path elimination
 * Block '<S8>/Constant13' : Unused code path elimination
 * Block '<S8>/Constant14' : Unused code path elimination
 * Block '<S8>/Constant15' : Unused code path elimination
 * Block '<S8>/Constant16' : Unused code path elimination
 * Block '<S8>/Constant17' : Unused code path elimination
 * Block '<S8>/Constant18' : Unused code path elimination
 * Block '<S8>/Constant2' : Unused code path elimination
 * Block '<S8>/Constant3' : Unused code path elimination
 * Block '<S8>/Constant4' : Unused code path elimination
 * Block '<S8>/Constant5' : Unused code path elimination
 * Block '<S8>/Constant6' : Unused code path elimination
 * Block '<S8>/Constant7' : Unused code path elimination
 * Block '<S8>/Constant8' : Unused code path elimination
 * Block '<S8>/Constant9' : Unused code path elimination
 * Block '<S35>/map_12x1_to_4x3' : Reshape block reduction
 * Block '<S83>/Reshape 3x3 -> 9' : Reshape block reduction
 * Block '<S113>/Reshape' : Reshape block reduction
 * Block '<S120>/Reshape' : Reshape block reduction
 * Block '<S168>/Reshape' : Reshape block reduction
 * Block '<S192>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S203>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S222>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S228>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S243>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S272>/Reshape 3x3 -> 9' : Reshape block reduction
 * Block '<S308>/Reshape' : Reshape block reduction
 * Block '<S315>/Reshape' : Reshape block reduction
 * Block '<S10>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S277>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S319>/Reshape' : Reshape block reduction
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
 * hilite_system('Main_Sim/FSW_Lib')    - opens subsystem Main_Sim/FSW_Lib
 * hilite_system('Main_Sim/FSW_Lib/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main_Sim'
 * '<S1>'   : 'Main_Sim/FSW_Lib'
 * '<S2>'   : 'Main_Sim/FSW_Lib/Conversion_lib'
 * '<S3>'   : 'Main_Sim/FSW_Lib/MEKF_lib'
 * '<S4>'   : 'Main_Sim/FSW_Lib/actuator_processing_lib'
 * '<S5>'   : 'Main_Sim/FSW_Lib/control_command_generation_lib'
 * '<S6>'   : 'Main_Sim/FSW_Lib/environmentEstimation_lib'
 * '<S7>'   : 'Main_Sim/FSW_Lib/fsw_out_bus'
 * '<S8>'   : 'Main_Sim/FSW_Lib/fsw_telemetry_bus'
 * '<S9>'   : 'Main_Sim/FSW_Lib/mode_select_lib'
 * '<S10>'  : 'Main_Sim/FSW_Lib/target_generation_lib'
 * '<S11>'  : 'Main_Sim/FSW_Lib/Conversion_lib/pd_processing_lib'
 * '<S12>'  : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_body_deg2rad'
 * '<S13>'  : 'Main_Sim/FSW_Lib/Conversion_lib/pd_processing_lib/MATLAB Function'
 * '<S14>'  : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_body_deg2rad/create_sz'
 * '<S15>'  : 'Main_Sim/FSW_Lib/MEKF_lib/BypassMeasUpdate'
 * '<S16>'  : 'Main_Sim/FSW_Lib/MEKF_lib/ChooseMEKForPropagation'
 * '<S17>'  : 'Main_Sim/FSW_Lib/MEKF_lib/ChooseQuaternionSource'
 * '<S18>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry'
 * '<S19>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate'
 * '<S20>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TRIADActivation_lib'
 * '<S21>'  : 'Main_Sim/FSW_Lib/MEKF_lib/ThreeSigmaBounds'
 * '<S22>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation'
 * '<S23>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator'
 * '<S24>'  : 'Main_Sim/FSW_Lib/MEKF_lib/ChooseMEKForPropagation/parallel_protection_lib'
 * '<S25>'  : 'Main_Sim/FSW_Lib/MEKF_lib/ChooseQuaternionSource/If Action Subsystem'
 * '<S26>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry/Compare To Constant'
 * '<S27>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry/If Action Subsystem'
 * '<S28>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry/If Action Subsystem1'
 * '<S29>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry/If Action Subsystem2'
 * '<S30>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements'
 * '<S31>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/QR_factorization'
 * '<S32>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Normalize'
 * '<S33>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation'
 * '<S34>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1'
 * '<S35>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/makes_Xi_q'
 * '<S36>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements/CrossProdMatrix_lib'
 * '<S37>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements/CrossProdMatrix_lib1'
 * '<S38>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements/CrossProdMatrix_lib/Create 3x3 Matrix'
 * '<S39>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements/CrossProdMatrix_lib1/Create 3x3 Matrix'
 * '<S40>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Normalize/Quaternion Modulus'
 * '<S41>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S42>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/Quaternion Normalize'
 * '<S43>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/V1'
 * '<S44>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/V2'
 * '<S45>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/V3'
 * '<S46>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S47>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S48>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/Quaternion Normalize'
 * '<S49>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/V1'
 * '<S50>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/V2'
 * '<S51>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/V3'
 * '<S52>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
 * '<S53>'  : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S54>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TRIADActivation_lib/NEdgeDetector_lib'
 * '<S55>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CreateStateTransitionMatrix'
 * '<S56>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CrossProdMatrix_lib'
 * '<S57>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CrossProdMatrix_lib1'
 * '<S58>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/MATLAB Function'
 * '<S59>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/MakePsiVector'
 * '<S60>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/OMEGAMatrix'
 * '<S61>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/Quaternion Normalize'
 * '<S62>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/quat_rectify_lib'
 * '<S63>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CrossProdMatrix_lib/Create 3x3 Matrix'
 * '<S64>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CrossProdMatrix_lib1/Create 3x3 Matrix'
 * '<S65>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/MakePsiVector/If Action Subsystem'
 * '<S66>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/MakePsiVector/If Action Subsystem1'
 * '<S67>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/Quaternion Normalize/Quaternion Modulus'
 * '<S68>'  : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S69>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Bypass Triad'
 * '<S70>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Normalize Vector'
 * '<S71>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Normalize Vector1'
 * '<S72>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Quaternion Normalize'
 * '<S73>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg'
 * '<S74>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/parallel_protection_lib'
 * '<S75>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/parallel_protection_lib1'
 * '<S76>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/quat_rectify_lib'
 * '<S77>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Quaternion Normalize/Quaternion Modulus'
 * '<S78>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S79>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Cross Product4'
 * '<S80>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Cross Product5'
 * '<S81>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Cross Product6'
 * '<S82>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Cross Product7'
 * '<S83>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2'
 * '<S84>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace'
 * '<S85>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Positive Trace'
 * '<S86>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM'
 * '<S87>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/trace(DCM)'
 * '<S88>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S89>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S90>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S91>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/diag(DCM)'
 * '<S92>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S93>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S94>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S95>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S96>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S97>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S98>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S99>'  : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S100>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S101>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S102>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S103>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S104>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S105>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S106>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S107>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S108>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S109>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S110>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error'
 * '<S111>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S112>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper'
 * '<S113>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S114>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper'
 * '<S115>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S116>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S117>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S118>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S119>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S120>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S121>' : 'Main_Sim/FSW_Lib/MEKF_lib/Triad Estimator/Triad_alg/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S122>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/command_converter_lib'
 * '<S123>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib'
 * '<S124>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/degree error'
 * '<S125>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib'
 * '<S126>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib'
 * '<S127>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/command_converter_lib/torque-2-RPM'
 * '<S128>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm'
 * '<S129>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat'
 * '<S130>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_null_control'
 * '<S131>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_reorientation'
 * '<S132>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek'
 * '<S133>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/asmController_lib'
 * '<S134>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desat_Controller_Logic_lib'
 * '<S135>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib'
 * '<S136>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/null_control_lib'
 * '<S137>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desat_Controller_Logic_lib/Desat_control_logic'
 * '<S138>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/Cross Product'
 * '<S139>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/Dipole Saturation'
 * '<S140>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/Div_by_0_protection'
 * '<S141>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/gain_schedule'
 * '<S142>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/Dipole Saturation/Div_by_0_protection'
 * '<S143>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/Dipole Saturation/If Action Subsystem10'
 * '<S144>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/Dipole Saturation/If Action Subsystem9'
 * '<S145>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/gain_schedule/If Action Subsystem10'
 * '<S146>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desat/Desaturation_Controller_Lib/gain_schedule/If Action Subsystem9'
 * '<S147>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_null_control/null_control_lib1'
 * '<S148>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_reorientation/PD_Controller_Lib'
 * '<S149>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib'
 * '<S150>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib/get_error_axis'
 * '<S151>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib/get_error_axis/Cross Product'
 * '<S152>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Conjugate'
 * '<S153>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication'
 * '<S154>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/quat_rectify_lib'
 * '<S155>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q0'
 * '<S156>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q1'
 * '<S157>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q2'
 * '<S158>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q3'
 * '<S159>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem'
 * '<S160>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1'
 * '<S161>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/L_inf_allocation_lib'
 * '<S162>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/L_inf_allocation_lib1'
 * '<S163>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/L_inf_allocation_lib/MATLAB Function'
 * '<S164>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/L_inf_allocation_lib1/MATLAB Function'
 * '<S165>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/Invert  3x3 Matrix'
 * '<S166>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/MATLAB Function'
 * '<S167>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/MATLAB Function1'
 * '<S168>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/Invert  3x3 Matrix/Determinant of 3x3 Matrix'
 * '<S169>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib'
 * '<S170>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib'
 * '<S171>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sgp4_lib_fsw'
 * '<S172>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib'
 * '<S173>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/time_coord_rotations_lib  '
 * '<S174>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position'
 * '<S175>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib'
 * '<S176>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1'
 * '<S177>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED'
 * '<S178>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1'
 * '<S179>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude'
 * '<S180>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap'
 * '<S181>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Radius at Geocentric Latitude'
 * '<S182>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A11'
 * '<S183>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A12'
 * '<S184>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A13'
 * '<S185>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A21'
 * '<S186>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A22'
 * '<S187>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A23'
 * '<S188>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A31'
 * '<S189>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A32'
 * '<S190>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A33'
 * '<S191>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/Angle Conversion'
 * '<S192>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/Create Transformation Matrix'
 * '<S193>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A11'
 * '<S194>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A12'
 * '<S195>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A13'
 * '<S196>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A21'
 * '<S197>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A22'
 * '<S198>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A23'
 * '<S199>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A31'
 * '<S200>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A32'
 * '<S201>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A33'
 * '<S202>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/Angle Conversion'
 * '<S203>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/Create Transformation Matrix'
 * '<S204>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Conversion'
 * '<S205>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Conversion1'
 * '<S206>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Conversion2'
 * '<S207>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Latitude Wrap 90'
 * '<S208>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Radius at Geocentric Latitude'
 * '<S209>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Radius at Geocentric Latitude/Conversion'
 * '<S210>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Latitude Wrap 90'
 * '<S211>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Wrap Longitude'
 * '<S212>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S213>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S214>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S215>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S216>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Radius at Geocentric Latitude/Conversion'
 * '<S217>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/Compare To Constant'
 * '<S218>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/Normalize Vector'
 * '<S219>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/Normalize Vector1'
 * '<S220>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/get_C_F2T'
 * '<S221>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/twonorm'
 * '<S222>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/get_C_F2T/Create 3x3 Matrix'
 * '<S223>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/Compare To Constant'
 * '<S224>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/Normalize Vector'
 * '<S225>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/Normalize Vector1'
 * '<S226>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/get_C_F2T'
 * '<S227>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/twonorm'
 * '<S228>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/get_C_F2T/Create 3x3 Matrix'
 * '<S229>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1'
 * '<S230>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA'
 * '<S231>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/MATLAB Function'
 * '<S232>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/magField_custom_lib'
 * '<S233>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A11'
 * '<S234>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A12'
 * '<S235>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A13'
 * '<S236>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A21'
 * '<S237>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A22'
 * '<S238>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A23'
 * '<S239>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A31'
 * '<S240>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A32'
 * '<S241>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A33'
 * '<S242>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/Angle Conversion'
 * '<S243>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/Create Transformation Matrix'
 * '<S244>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/Conversion'
 * '<S245>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/Subsystem2'
 * '<S246>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/Subsystem3'
 * '<S247>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/While Iterator Subsystem'
 * '<S248>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/e^1'
 * '<S249>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/e^2'
 * '<S250>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/e^3'
 * '<S251>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/While Iterator Subsystem/Subsystem2'
 * '<S252>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/While Iterator Subsystem/Subsystem3'
 * '<S253>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/While Iterator Subsystem/Subsystem4'
 * '<S254>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/magField_custom_lib/MATLAB Function'
 * '<S255>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sgp4_lib_fsw/MATLAB Function'
 * '<S256>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib/MATLAB Function'
 * '<S257>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib/Normalize Vector'
 * '<S258>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib/eclipseCheck_lib'
 * '<S259>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib/eclipseCheck_lib/MATLAB Function'
 * '<S260>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/time_coord_rotations_lib  /MATLAB Function3'
 * '<S261>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/time_coord_rotations_lib  /coord_rotations_lib'
 * '<S262>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/time_coord_rotations_lib  /coord_rotations_lib/MATLAB Function'
 * '<S263>' : 'Main_Sim/FSW_Lib/mode_select_lib/RPM_2_desat_check'
 * '<S264>' : 'Main_Sim/FSW_Lib/mode_select_lib/Subsystem'
 * '<S265>' : 'Main_Sim/FSW_Lib/mode_select_lib/desat_timer_logic_lib'
 * '<S266>' : 'Main_Sim/FSW_Lib/mode_select_lib/mode_select'
 * '<S267>' : 'Main_Sim/FSW_Lib/mode_select_lib/RPM_2_desat_check/twonorm'
 * '<S268>' : 'Main_Sim/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant'
 * '<S269>' : 'Main_Sim/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant1'
 * '<S270>' : 'Main_Sim/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant2'
 * '<S271>' : 'Main_Sim/FSW_Lib/mode_select_lib/desat_timer_logic_lib/desat_timer_logic'
 * '<S272>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions'
 * '<S273>' : 'Main_Sim/FSW_Lib/target_generation_lib/Map to BodyFrame Momentum'
 * '<S274>' : 'Main_Sim/FSW_Lib/target_generation_lib/Normalize Vector1'
 * '<S275>' : 'Main_Sim/FSW_Lib/target_generation_lib/quat_rectify_lib'
 * '<S276>' : 'Main_Sim/FSW_Lib/target_generation_lib/select_outputs'
 * '<S277>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib'
 * '<S278>' : 'Main_Sim/FSW_Lib/target_generation_lib/target_gen'
 * '<S279>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace'
 * '<S280>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace'
 * '<S281>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM'
 * '<S282>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/trace(DCM)'
 * '<S283>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S284>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S285>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S286>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
 * '<S287>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S288>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S289>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S290>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S291>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S292>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S293>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S294>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S295>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S296>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S297>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S298>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S299>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S300>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S301>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S302>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S303>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S304>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S305>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
 * '<S306>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S307>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
 * '<S308>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S309>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
 * '<S310>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S311>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S312>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S313>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S314>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S315>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S316>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S317>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/Compare To Constant'
 * '<S318>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/Detect Rise Positive'
 * '<S319>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_interp'
 * '<S320>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_lib'
 * '<S321>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/Detect Rise Positive/Positive'
 * '<S322>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_interp/soar_INTERP'
 * '<S323>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_lib/INITIALIZE'
 * '<S324>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_lib/SOLVE'
 * '<S325>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_lib/call to ECOS SOCP solver (compiled C function)'
 */
#endif                                 /* RTW_HEADER_FSW_Lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

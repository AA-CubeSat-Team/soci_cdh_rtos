/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_0123.h
 *
 * Code generated for Simulink model 'FSW_0123'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jan 23 23:50:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FSW_0123_h_
#define RTW_HEADER_FSW_0123_h_
#include <stddef.h>
#include <math.h>
#ifndef FSW_0123_COMMON_INCLUDES_
# define FSW_0123_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FSW_0123_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Merge[4];                     /* '<S5>/Merge' */
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<Root>/Discrete-Time Integrator' */
  void* Assertion_slioAccessor;        /* '<S41>/Assertion' */
  void* Assertion_slioAccessor_l;      /* '<S42>/Assertion' */
  void* Assertion_slioAccessor_o;      /* '<S43>/Assertion' */
  void* Assertion_slioAccessor_d;      /* '<S44>/Assertion' */
} DW;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MathFunction1[9];       /* '<Root>/Math Function1' */
} ConstB;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0.5432,0,0.6398;0,0.5432,0.6398;-0.5432,0,0.6398;0,-0.5432,0.6398]
   * Referenced by: '<Root>/body2wheel'
   */
  real_T body2wheel_Value[12];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T mag[9];                       /* '<Root>/mag' */
  real_T sun[2];                       /* '<Root>/sun' */
  real_T gyro[9];                      /* '<Root>/gyro' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T rpm[4];                       /* '<Root>/rpm' */
  real_T am2[5];                       /* '<Root>/am2' */
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
extern const ConstB rtConstB;          /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void FSW_0123_initialize(void);
extern void FSW_0123_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Reshape 3x3 -> 9' : Reshape block reduction
 * Block '<S39>/Reshape' : Reshape block reduction
 * Block '<S46>/Reshape' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FSW_0123'
 * '<S1>'   : 'FSW_0123/Cross Product4'
 * '<S2>'   : 'FSW_0123/Cross Product5'
 * '<S3>'   : 'FSW_0123/Cross Product6'
 * '<S4>'   : 'FSW_0123/Cross Product7'
 * '<S5>'   : 'FSW_0123/Direction Cosine Matrix  to Quaternions2'
 * '<S6>'   : 'FSW_0123/Normalize Vector'
 * '<S7>'   : 'FSW_0123/Normalize Vector1'
 * '<S8>'   : 'FSW_0123/Quaternion Conjugate'
 * '<S9>'   : 'FSW_0123/Quaternion Multiplication'
 * '<S10>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace'
 * '<S11>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Positive Trace'
 * '<S12>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM'
 * '<S13>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/trace(DCM)'
 * '<S14>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S15>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S16>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S17>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/diag(DCM)'
 * '<S18>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S19>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S20>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S21>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S22>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S23>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S24>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S25>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S26>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S27>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S28>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S29>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S30>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S31>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S32>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S33>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S34>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S35>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S36>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error'
 * '<S37>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S38>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper'
 * '<S39>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S40>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper'
 * '<S41>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S42>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S43>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S44>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S45>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S46>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S47>'  : 'FSW_0123/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S48>'  : 'FSW_0123/Quaternion Multiplication/q0'
 * '<S49>'  : 'FSW_0123/Quaternion Multiplication/q1'
 * '<S50>'  : 'FSW_0123/Quaternion Multiplication/q2'
 * '<S51>'  : 'FSW_0123/Quaternion Multiplication/q3'
 */
#endif                                 /* RTW_HEADER_FSW_0123_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

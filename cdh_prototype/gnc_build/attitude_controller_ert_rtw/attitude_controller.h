/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: attitude_controller.h
 *
 * Code generated for Simulink model 'attitude_controller'.
 *
 * Model version                  : 1.51
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Dec  2 22:23:15 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_attitude_controller_h_
#define RTW_HEADER_attitude_controller_h_

#ifndef attitude_controller_COMMON_INCLUDES_
# define attitude_controller_COMMON_INCLUDES_
#include <gnc_build/attitude_controller_ert_rtw/rtwtypes.h>
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* attitude_controller_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: sim_params.control.KP
   * Referenced by: '<S1>/Kp'
   */
  real_T Kp_Gain[9];

  /* Expression: sim_params.control.KD
   * Referenced by: '<S1>/Kd'
   */
  real_T Kd_Gain[9];
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void attitude_controller_initialize(RT_MODEL *const rtM);
extern void attitude_controller_step(RT_MODEL *const rtM, real_T
  rtU_attitude_error[6], real_T rtY_command_torque_Nm[3]);

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
 * hilite_system('sim_simple/attitude_controller')    - opens subsystem sim_simple/attitude_controller
 * hilite_system('sim_simple/attitude_controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sim_simple'
 * '<S1>'   : 'sim_simple/attitude_controller'
 */
#endif                                 /* RTW_HEADER_attitude_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

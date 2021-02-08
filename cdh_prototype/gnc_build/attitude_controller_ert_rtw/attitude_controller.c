/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: attitude_controller.c
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

#include <gnc_build/attitude_controller_ert_rtw/attitude_controller.h>

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

/* Model step function */
void attitude_controller_step(RT_MODEL *const rtM, real_T rtU_attitude_error[6],
  real_T rtY_command_torque_Nm[3])
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    /* Outport: '<Root>/command_torque_Nm' incorporates:
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Kd'
     *  Gain: '<S1>/Kp'
     *  Inport: '<Root>/attitude_error'
     *  Sum: '<S1>/Sum'
     */
    rtY_command_torque_Nm[i] = ((rtConstP.Kp_Gain[i + 3] * rtU_attitude_error[1]
      + rtConstP.Kp_Gain[i] * rtU_attitude_error[0]) + rtConstP.Kp_Gain[i + 6] *
      rtU_attitude_error[2]) + -(rtConstP.Kd_Gain[i + 6] * rtU_attitude_error[5]
      + (rtConstP.Kd_Gain[i + 3] * rtU_attitude_error[4] + rtConstP.Kd_Gain[i] *
         rtU_attitude_error[3]));
  }

  UNUSED_PARAMETER(rtM);
}

/* Model initialize function */
void attitude_controller_initialize(RT_MODEL *const rtM)
{
  /* (no initialization code required) */
  UNUSED_PARAMETER(rtM);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

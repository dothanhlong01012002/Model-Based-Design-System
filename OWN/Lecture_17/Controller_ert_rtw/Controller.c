/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.88
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Dec 14 13:06:05 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Emulation hardware selection:
 *    Differs from embedded hardware (Custom Processor->MATLAB Host Computer)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_private.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Controller_step(void)
{
  real_T rtb_Sum;
  real_T rtb_Sum1;

  /* Outputs for Atomic SubSystem: '<Root>/Controller  ' */
  /* Saturate: '<S1>/Saturation1' incorporates:
   *  Inport: '<Root>/Scaled_RPM'
   */
  if (rtU.Scaled_RPM > 1.0) {
    rtb_Sum = 1.0;
  } else if (rtU.Scaled_RPM < 0.0) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = rtU.Scaled_RPM;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Desired RPM'
   */
  rtb_Sum = rtU.Desired_RPM - rtb_Sum;

  /* Sum: '<S1>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S1>/I'
   *  Gain: '<S1>/I Gain'
   *  Gain: '<S1>/P Gain'
   */
  rtb_Sum1 = 100.0 * rtb_Sum + 10.0 * rtDW.I_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/I' */
  rtDW.I_DSTATE += 0.001 * rtb_Sum;
  if (rtDW.I_DSTATE >= 1.0) {
    rtDW.I_DSTATE = 1.0;
  } else if (rtDW.I_DSTATE <= 0.0) {
    rtDW.I_DSTATE = 0.0;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/I' */

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Sum1 > 1.0) {
    /* Outport: '<Root>/Torque Signal' */
    rtY.TorqueSignal = 1.0;
  } else if (rtb_Sum1 < 0.0) {
    /* Outport: '<Root>/Torque Signal' */
    rtY.TorqueSignal = 0.0;
  } else {
    /* Outport: '<Root>/Torque Signal' */
    rtY.TorqueSignal = rtb_Sum1;
  }

  /* End of Saturate: '<S1>/Saturation' */
  /* End of Outputs for SubSystem: '<Root>/Controller  ' */
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

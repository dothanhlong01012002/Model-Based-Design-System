/*
 * File: LED_1.c
 *
 * Code generated for Simulink model 'LED_1'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec 20 09:48:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LED_1.h"
#include "LED_1_private.h"

/* Block states (default storage) */
DW_LED_1_T LED_1_DW;

/* Real-time model */
static RT_MODEL_LED_1_T LED_1_M_;
RT_MODEL_LED_1_T *const LED_1_M = &LED_1_M_;

/* Model step function */
void LED_1_step(void)
{
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (LED_1_DW.clockTickCounter < LED_1_P.PulseGenerator_Duty)
    && (LED_1_DW.clockTickCounter >= 0L) ? LED_1_P.PulseGenerator_Amp : 0.0;
  if (LED_1_DW.clockTickCounter >= LED_1_P.PulseGenerator_Period - 1.0) {
    LED_1_DW.clockTickCounter = 0L;
  } else {
    LED_1_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  writeDigitalPin(9, (uint8_T)(rtb_PulseGenerator <=
    LED_1_P.CompareToConstant_const));

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  writeDigitalPin(10, (uint8_T)(rtb_PulseGenerator != 0.0));
}

/* Model initialize function */
void LED_1_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Output' */
  LED_1_DW.obj_p.matlabCodegenIsDeleted = false;
  LED_1_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(9, 1);
  LED_1_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  LED_1_DW.obj.matlabCodegenIsDeleted = false;
  LED_1_DW.obj.isInitialized = 1L;
  digitalIOSetup(10, 1);
  LED_1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void LED_1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!LED_1_DW.obj_p.matlabCodegenIsDeleted) {
    LED_1_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!LED_1_DW.obj.matlabCodegenIsDeleted) {
    LED_1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

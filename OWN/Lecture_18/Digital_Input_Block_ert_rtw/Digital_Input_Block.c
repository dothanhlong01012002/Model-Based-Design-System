/*
 * File: Digital_Input_Block.c
 *
 * Code generated for Simulink model 'Digital_Input_Block'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec 20 14:25:24 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Digital_Input_Block.h"
#include "Digital_Input_Block_private.h"

/* Block signals (default storage) */
B_Digital_Input_Block_T Digital_Input_Block_B;

/* Block states (default storage) */
DW_Digital_Input_Block_T Digital_Input_Block_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Digital_Input_Block_T Digital_Input_Block_PrevZCX;

/* Real-time model */
static RT_MODEL_Digital_Input_Block_T Digital_Input_Block_M_;
RT_MODEL_Digital_Input_Block_T *const Digital_Input_Block_M =
  &Digital_Input_Block_M_;

/* Model step function */
void Digital_Input_Block_step(void)
{
  real_T rtb_PulseGenerator;
  boolean_T rtb_Button_0;
  ZCEventType zcEvent;

  /* MATLABSystem: '<Root>/Button' */
  if (Digital_Input_Block_DW.obj.SampleTime !=
      Digital_Input_Block_P.Button_SampleTime) {
    Digital_Input_Block_DW.obj.SampleTime =
      Digital_Input_Block_P.Button_SampleTime;
  }

  rtb_Button_0 = readDigitalPin(2);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (Digital_Input_Block_DW.clockTickCounter <
                        Digital_Input_Block_P.PulseGenerator_Duty) &&
    (Digital_Input_Block_DW.clockTickCounter >= 0L) ?
    Digital_Input_Block_P.PulseGenerator_Amp : 0.0;
  if (Digital_Input_Block_DW.clockTickCounter >=
      Digital_Input_Block_P.PulseGenerator_Period - 1.0) {
    Digital_Input_Block_DW.clockTickCounter = 0L;
  } else {
    Digital_Input_Block_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem ' incorporates:
   *  TriggerPort: '<S9>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Digital_Input_Block_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* Switch: '<S9>/Switch' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  MATLABSystem: '<Root>/Button'
     */
    if ((real_T)rtb_Button_0 > Digital_Input_Block_P.Switch_Threshold) {
      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S10>/Vector'
       *  MultiPortSwitch: '<S10>/Output'
       *  UnitDelay: '<S11>/Output'
       */
      Digital_Input_Block_B.Switch =
        Digital_Input_Block_P.RepeatingSequenceStair_OutValue[Digital_Input_Block_DW.Output_DSTATE];
    } else {
      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S10>/Vector'
       *  Constant: '<S9>/Constant'
       *  MultiPortSwitch: '<S10>/Output'
       *  Sum: '<S9>/Sum'
       *  UnitDelay: '<S11>/Output'
       */
      Digital_Input_Block_B.Switch = Digital_Input_Block_P.Constant_Value -
        Digital_Input_Block_P.RepeatingSequenceStair_OutValue[Digital_Input_Block_DW.Output_DSTATE];
    }

    /* End of Switch: '<S9>/Switch' */

    /* Sum: '<S12>/FixPt Sum1' incorporates:
     *  Constant: '<S12>/FixPt Constant'
     *  UnitDelay: '<S11>/Output'
     */
    Digital_Input_Block_DW.Output_DSTATE = (uint8_T)((uint16_T)
      Digital_Input_Block_DW.Output_DSTATE +
      Digital_Input_Block_P.FixPtConstant_Value);

    /* Switch: '<S13>/FixPt Switch' */
    if (Digital_Input_Block_DW.Output_DSTATE >
        Digital_Input_Block_P.LimitedCounter_uplimit) {
      /* Sum: '<S12>/FixPt Sum1' incorporates:
       *  Constant: '<S13>/Constant'
       */
      Digital_Input_Block_DW.Output_DSTATE =
        Digital_Input_Block_P.Constant_Value_e;
    }

    /* End of Switch: '<S13>/FixPt Switch' */
  }

  /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem ' */

  /* MATLABSystem: '<Root>/LED 1' incorporates:
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  writeDigitalPin(10, (uint8_T)(Digital_Input_Block_B.Switch ==
    Digital_Input_Block_P.Bit0_const));

  /* MATLABSystem: '<Root>/LED 2' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  writeDigitalPin(9, (uint8_T)(Digital_Input_Block_B.Switch ==
    Digital_Input_Block_P.Bit1_const));

  /* MATLABSystem: '<Root>/LED 3' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(Digital_Input_Block_B.Switch ==
    Digital_Input_Block_P.Bit2_const));

  /* MATLABSystem: '<Root>/LED 4' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  writeDigitalPin(7, (uint8_T)(Digital_Input_Block_B.Switch ==
    Digital_Input_Block_P.Bit3_const));

  /* MATLABSystem: '<Root>/LED 5' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  writeDigitalPin(6, (uint8_T)(Digital_Input_Block_B.Switch ==
    Digital_Input_Block_P.Bit4_const));

  /* MATLABSystem: '<Root>/LED 6' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   */
  writeDigitalPin(5, (uint8_T)(Digital_Input_Block_B.Switch ==
    Digital_Input_Block_P.Bit5_const));

  /* MATLABSystem: '<Root>/LED 7' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  writeDigitalPin(4, (uint8_T)(Digital_Input_Block_B.Switch ==
    Digital_Input_Block_P.Bit6_const));

  /* MATLABSystem: '<Root>/LED 8' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  writeDigitalPin(3, (uint8_T)(Digital_Input_Block_B.Switch ==
    Digital_Input_Block_P.Bit7_const));
}

/* Model initialize function */
void Digital_Input_Block_initialize(void)
{
  Digital_Input_Block_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Triggered Subsystem ' */
  /* InitializeConditions for Sum: '<S12>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S11>/Output'
   */
  Digital_Input_Block_DW.Output_DSTATE =
    Digital_Input_Block_P.Output_InitialCondition;

  /* SystemInitialize for Switch: '<S9>/Switch' incorporates:
   *  Outport: '<S9>/Out1'
   */
  Digital_Input_Block_B.Switch = Digital_Input_Block_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Triggered Subsystem ' */

  /* Start for MATLABSystem: '<Root>/Button' */
  Digital_Input_Block_DW.obj.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj.SampleTime =
    Digital_Input_Block_P.Button_SampleTime;
  Digital_Input_Block_DW.obj.isInitialized = 1L;
  digitalIOSetup(2, 2.0);
  Digital_Input_Block_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 1' */
  Digital_Input_Block_DW.obj_p.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(10, 1);
  Digital_Input_Block_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 2' */
  Digital_Input_Block_DW.obj_g.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(9, 1);
  Digital_Input_Block_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 3' */
  Digital_Input_Block_DW.obj_nv.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj_nv.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Digital_Input_Block_DW.obj_nv.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 4' */
  Digital_Input_Block_DW.obj_l0.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj_l0.isInitialized = 1L;
  digitalIOSetup(7, 1);
  Digital_Input_Block_DW.obj_l0.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 5' */
  Digital_Input_Block_DW.obj_k.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj_k.isInitialized = 1L;
  digitalIOSetup(6, 1);
  Digital_Input_Block_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 6' */
  Digital_Input_Block_DW.obj_l.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(5, 1);
  Digital_Input_Block_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 7' */
  Digital_Input_Block_DW.obj_e.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(4, 1);
  Digital_Input_Block_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 8' */
  Digital_Input_Block_DW.obj_n.matlabCodegenIsDeleted = false;
  Digital_Input_Block_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(3, 1);
  Digital_Input_Block_DW.obj_n.isSetupComplete = true;
}

/* Model terminate function */
void Digital_Input_Block_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Button' */
  if (!Digital_Input_Block_DW.obj.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Button' */

  /* Terminate for MATLABSystem: '<Root>/LED 1' */
  if (!Digital_Input_Block_DW.obj_p.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 1' */

  /* Terminate for MATLABSystem: '<Root>/LED 2' */
  if (!Digital_Input_Block_DW.obj_g.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 2' */

  /* Terminate for MATLABSystem: '<Root>/LED 3' */
  if (!Digital_Input_Block_DW.obj_nv.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj_nv.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 3' */

  /* Terminate for MATLABSystem: '<Root>/LED 4' */
  if (!Digital_Input_Block_DW.obj_l0.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj_l0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 4' */

  /* Terminate for MATLABSystem: '<Root>/LED 5' */
  if (!Digital_Input_Block_DW.obj_k.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 5' */

  /* Terminate for MATLABSystem: '<Root>/LED 6' */
  if (!Digital_Input_Block_DW.obj_l.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 6' */

  /* Terminate for MATLABSystem: '<Root>/LED 7' */
  if (!Digital_Input_Block_DW.obj_e.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 7' */

  /* Terminate for MATLABSystem: '<Root>/LED 8' */
  if (!Digital_Input_Block_DW.obj_n.matlabCodegenIsDeleted) {
    Digital_Input_Block_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 8' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

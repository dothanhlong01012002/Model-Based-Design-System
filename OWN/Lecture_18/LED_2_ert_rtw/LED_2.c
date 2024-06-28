/*
 * File: LED_2.c
 *
 * Code generated for Simulink model 'LED_2'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Dec 19 22:00:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LED_2.h"
#include "LED_2_private.h"

/* Block states (default storage) */
DW_LED_2_T LED_2_DW;

/* Real-time model */
static RT_MODEL_LED_2_T LED_2_M_;
RT_MODEL_LED_2_T *const LED_2_M = &LED_2_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void LED_2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(LED_2_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (LED_2_M->Timing.TaskCounters.TID[1])++;
  if ((LED_2_M->Timing.TaskCounters.TID[1]) > 499) {/* Sample time: [0.5s, 0.0s] */
    LED_2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void LED_2_step0(void)                 /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void LED_2_step1(void)                 /* Sample time: [0.5s, 0.0s] */
{
  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S9>/Vector'
   *  MultiPortSwitch: '<S9>/Output'
   *  RelationalOperator: '<S1>/Compare'
   *  UnitDelay: '<S10>/Output'
   */
  writeDigitalPin(10, (uint8_T)
                  (LED_2_P.RepeatingSequenceStair_OutValue[LED_2_DW.Output_DSTATE]
                   == LED_2_P.CompareToConstant_const));

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S9>/Vector'
   *  MultiPortSwitch: '<S9>/Output'
   *  RelationalOperator: '<S2>/Compare'
   *  UnitDelay: '<S10>/Output'
   */
  writeDigitalPin(9, (uint8_T)
                  (LED_2_P.RepeatingSequenceStair_OutValue[LED_2_DW.Output_DSTATE]
                   == LED_2_P.CompareToConstant1_const));

  /* MATLABSystem: '<Root>/Digital Output2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S9>/Vector'
   *  MultiPortSwitch: '<S9>/Output'
   *  RelationalOperator: '<S3>/Compare'
   *  UnitDelay: '<S10>/Output'
   */
  writeDigitalPin(8, (uint8_T)
                  (LED_2_P.RepeatingSequenceStair_OutValue[LED_2_DW.Output_DSTATE]
                   == LED_2_P.CompareToConstant2_const));

  /* MATLABSystem: '<Root>/Digital Output3' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S9>/Vector'
   *  MultiPortSwitch: '<S9>/Output'
   *  RelationalOperator: '<S4>/Compare'
   *  UnitDelay: '<S10>/Output'
   */
  writeDigitalPin(7, (uint8_T)
                  (LED_2_P.RepeatingSequenceStair_OutValue[LED_2_DW.Output_DSTATE]
                   == LED_2_P.CompareToConstant3_const));

  /* MATLABSystem: '<Root>/Digital Output4' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S9>/Vector'
   *  MultiPortSwitch: '<S9>/Output'
   *  RelationalOperator: '<S5>/Compare'
   *  UnitDelay: '<S10>/Output'
   */
  writeDigitalPin(6, (uint8_T)
                  (LED_2_P.RepeatingSequenceStair_OutValue[LED_2_DW.Output_DSTATE]
                   == LED_2_P.CompareToConstant4_const));

  /* MATLABSystem: '<Root>/Digital Output5' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S9>/Vector'
   *  MultiPortSwitch: '<S9>/Output'
   *  RelationalOperator: '<S6>/Compare'
   *  UnitDelay: '<S10>/Output'
   */
  writeDigitalPin(5, (uint8_T)
                  (LED_2_P.RepeatingSequenceStair_OutValue[LED_2_DW.Output_DSTATE]
                   == LED_2_P.CompareToConstant5_const));

  /* MATLABSystem: '<Root>/Digital Output6' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S9>/Vector'
   *  MultiPortSwitch: '<S9>/Output'
   *  RelationalOperator: '<S7>/Compare'
   *  UnitDelay: '<S10>/Output'
   */
  writeDigitalPin(4, (uint8_T)
                  (LED_2_P.RepeatingSequenceStair_OutValue[LED_2_DW.Output_DSTATE]
                   == LED_2_P.CompareToConstant6_const));

  /* MATLABSystem: '<Root>/Digital Output7' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Vector'
   *  MultiPortSwitch: '<S9>/Output'
   *  RelationalOperator: '<S8>/Compare'
   *  UnitDelay: '<S10>/Output'
   */
  writeDigitalPin(3, (uint8_T)
                  (LED_2_P.RepeatingSequenceStair_OutValue[LED_2_DW.Output_DSTATE]
                   == LED_2_P.CompareToConstant7_const));

  /* Sum: '<S11>/FixPt Sum1' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  UnitDelay: '<S10>/Output'
   */
  LED_2_DW.Output_DSTATE = (uint8_T)((uint16_T)LED_2_DW.Output_DSTATE +
    LED_2_P.FixPtConstant_Value);

  /* Switch: '<S12>/FixPt Switch' */
  if (LED_2_DW.Output_DSTATE > LED_2_P.LimitedCounter_uplimit) {
    /* Sum: '<S11>/FixPt Sum1' incorporates:
     *  Constant: '<S12>/Constant'
     */
    LED_2_DW.Output_DSTATE = LED_2_P.Constant_Value;
  }

  /* End of Switch: '<S12>/FixPt Switch' */
}

/* Model initialize function */
void LED_2_initialize(void)
{
  /* InitializeConditions for Sum: '<S11>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S10>/Output'
   */
  LED_2_DW.Output_DSTATE = LED_2_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  LED_2_DW.obj_p.matlabCodegenIsDeleted = false;
  LED_2_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(10, 1);
  LED_2_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  LED_2_DW.obj_g.matlabCodegenIsDeleted = false;
  LED_2_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(9, 1);
  LED_2_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  LED_2_DW.obj_n.matlabCodegenIsDeleted = false;
  LED_2_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(8, 1);
  LED_2_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output3' */
  LED_2_DW.obj_l0.matlabCodegenIsDeleted = false;
  LED_2_DW.obj_l0.isInitialized = 1L;
  digitalIOSetup(7, 1);
  LED_2_DW.obj_l0.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  LED_2_DW.obj_k.matlabCodegenIsDeleted = false;
  LED_2_DW.obj_k.isInitialized = 1L;
  digitalIOSetup(6, 1);
  LED_2_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output5' */
  LED_2_DW.obj_l.matlabCodegenIsDeleted = false;
  LED_2_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(5, 1);
  LED_2_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output6' */
  LED_2_DW.obj_e.matlabCodegenIsDeleted = false;
  LED_2_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(4, 1);
  LED_2_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output7' */
  LED_2_DW.obj.matlabCodegenIsDeleted = false;
  LED_2_DW.obj.isInitialized = 1L;
  digitalIOSetup(3, 1);
  LED_2_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void LED_2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!LED_2_DW.obj_p.matlabCodegenIsDeleted) {
    LED_2_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!LED_2_DW.obj_g.matlabCodegenIsDeleted) {
    LED_2_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!LED_2_DW.obj_n.matlabCodegenIsDeleted) {
    LED_2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!LED_2_DW.obj_l0.matlabCodegenIsDeleted) {
    LED_2_DW.obj_l0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!LED_2_DW.obj_k.matlabCodegenIsDeleted) {
    LED_2_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output5' */
  if (!LED_2_DW.obj_l.matlabCodegenIsDeleted) {
    LED_2_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output6' */
  if (!LED_2_DW.obj_e.matlabCodegenIsDeleted) {
    LED_2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output7' */
  if (!LED_2_DW.obj.matlabCodegenIsDeleted) {
    LED_2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output7' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

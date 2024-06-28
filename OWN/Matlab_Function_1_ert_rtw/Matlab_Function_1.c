/*
 * File: Matlab_Function_1.c
 *
 * Code generated for Simulink model 'Matlab_Function_1'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Dec 20 20:42:42 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Matlab_Function_1.h"
#include "Matlab_Function_1_private.h"

/* Block states (default storage) */
DW_Matlab_Function_1_T Matlab_Function_1_DW;

/* Real-time model */
static RT_MODEL_Matlab_Function_1_T Matlab_Function_1_M_;
RT_MODEL_Matlab_Function_1_T *const Matlab_Function_1_M = &Matlab_Function_1_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Matlab_Function_1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Matlab_Function_1_M, 1));
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
  (Matlab_Function_1_M->Timing.TaskCounters.TID[1])++;
  if ((Matlab_Function_1_M->Timing.TaskCounters.TID[1]) > 499) {/* Sample time: [0.5s, 0.0s] */
    Matlab_Function_1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Matlab_Function_1_step0(void)     /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Matlab_Function_1_step1(void)     /* Sample time: [0.5s, 0.0s] */
{
  int16_T i;
  boolean_T rtb_y[8];

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Vector'
   *  MultiPortSwitch: '<S2>/Output'
   *  UnitDelay: '<S3>/Output'
   */
  for (i = 0; i < 8; i++) {
    rtb_y[i] = false;
  }

  rtb_y[(int16_T)
    Matlab_Function_1_P.RepeatingSequenceStair_OutValue[Matlab_Function_1_DW.Output_DSTATE]
    - 1] = true;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLABSystem: '<Root>/LED 1' */
  writeDigitalPin(10, (uint8_T)rtb_y[0]);

  /* MATLABSystem: '<Root>/LED 2' */
  writeDigitalPin(9, (uint8_T)rtb_y[1]);

  /* MATLABSystem: '<Root>/LED 3' */
  writeDigitalPin(8, (uint8_T)rtb_y[2]);

  /* MATLABSystem: '<Root>/LED 4' */
  writeDigitalPin(7, (uint8_T)rtb_y[3]);

  /* MATLABSystem: '<Root>/LED 5' */
  writeDigitalPin(6, (uint8_T)rtb_y[4]);

  /* MATLABSystem: '<Root>/LED 6' */
  writeDigitalPin(5, (uint8_T)rtb_y[5]);

  /* MATLABSystem: '<Root>/LED 7' */
  writeDigitalPin(4, (uint8_T)rtb_y[6]);

  /* MATLABSystem: '<Root>/LED 8' */
  writeDigitalPin(3, (uint8_T)rtb_y[7]);

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S3>/Output'
   */
  Matlab_Function_1_DW.Output_DSTATE = (uint8_T)((uint16_T)
    Matlab_Function_1_DW.Output_DSTATE + Matlab_Function_1_P.FixPtConstant_Value);

  /* Switch: '<S5>/FixPt Switch' */
  if (Matlab_Function_1_DW.Output_DSTATE >
      Matlab_Function_1_P.LimitedCounter_uplimit) {
    /* Sum: '<S4>/FixPt Sum1' incorporates:
     *  Constant: '<S5>/Constant'
     */
    Matlab_Function_1_DW.Output_DSTATE = Matlab_Function_1_P.Constant_Value;
  }

  /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model initialize function */
void Matlab_Function_1_initialize(void)
{
  /* InitializeConditions for Sum: '<S4>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S3>/Output'
   */
  Matlab_Function_1_DW.Output_DSTATE =
    Matlab_Function_1_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<Root>/LED 1' */
  Matlab_Function_1_DW.obj_p.matlabCodegenIsDeleted = false;
  Matlab_Function_1_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(10, 1);
  Matlab_Function_1_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 2' */
  Matlab_Function_1_DW.obj_g.matlabCodegenIsDeleted = false;
  Matlab_Function_1_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(9, 1);
  Matlab_Function_1_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 3' */
  Matlab_Function_1_DW.obj_n.matlabCodegenIsDeleted = false;
  Matlab_Function_1_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Matlab_Function_1_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 4' */
  Matlab_Function_1_DW.obj_l0.matlabCodegenIsDeleted = false;
  Matlab_Function_1_DW.obj_l0.isInitialized = 1L;
  digitalIOSetup(7, 1);
  Matlab_Function_1_DW.obj_l0.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 5' */
  Matlab_Function_1_DW.obj_k.matlabCodegenIsDeleted = false;
  Matlab_Function_1_DW.obj_k.isInitialized = 1L;
  digitalIOSetup(6, 1);
  Matlab_Function_1_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 6' */
  Matlab_Function_1_DW.obj_l.matlabCodegenIsDeleted = false;
  Matlab_Function_1_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(5, 1);
  Matlab_Function_1_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 7' */
  Matlab_Function_1_DW.obj_e.matlabCodegenIsDeleted = false;
  Matlab_Function_1_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(4, 1);
  Matlab_Function_1_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/LED 8' */
  Matlab_Function_1_DW.obj.matlabCodegenIsDeleted = false;
  Matlab_Function_1_DW.obj.isInitialized = 1L;
  digitalIOSetup(3, 1);
  Matlab_Function_1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Matlab_Function_1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/LED 1' */
  if (!Matlab_Function_1_DW.obj_p.matlabCodegenIsDeleted) {
    Matlab_Function_1_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 1' */

  /* Terminate for MATLABSystem: '<Root>/LED 2' */
  if (!Matlab_Function_1_DW.obj_g.matlabCodegenIsDeleted) {
    Matlab_Function_1_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 2' */

  /* Terminate for MATLABSystem: '<Root>/LED 3' */
  if (!Matlab_Function_1_DW.obj_n.matlabCodegenIsDeleted) {
    Matlab_Function_1_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 3' */

  /* Terminate for MATLABSystem: '<Root>/LED 4' */
  if (!Matlab_Function_1_DW.obj_l0.matlabCodegenIsDeleted) {
    Matlab_Function_1_DW.obj_l0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 4' */

  /* Terminate for MATLABSystem: '<Root>/LED 5' */
  if (!Matlab_Function_1_DW.obj_k.matlabCodegenIsDeleted) {
    Matlab_Function_1_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 5' */

  /* Terminate for MATLABSystem: '<Root>/LED 6' */
  if (!Matlab_Function_1_DW.obj_l.matlabCodegenIsDeleted) {
    Matlab_Function_1_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 6' */

  /* Terminate for MATLABSystem: '<Root>/LED 7' */
  if (!Matlab_Function_1_DW.obj_e.matlabCodegenIsDeleted) {
    Matlab_Function_1_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 7' */

  /* Terminate for MATLABSystem: '<Root>/LED 8' */
  if (!Matlab_Function_1_DW.obj.matlabCodegenIsDeleted) {
    Matlab_Function_1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED 8' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

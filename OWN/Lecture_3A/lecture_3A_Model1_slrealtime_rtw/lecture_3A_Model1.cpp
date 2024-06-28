/*
 * lecture_3A_Model1.cpp
 *
 * Code generation for model "lecture_3A_Model1".
 *
 * Model version              : 1.45
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Tue Dec 19 15:01:40 2023
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lecture_3A_Model1.h"
#include "lecture_3A_Model1_private.h"

/* Block signals (default storage) */
B_lecture_3A_Model1_T lecture_3A_Model1_B;

/* Continuous states */
X_lecture_3A_Model1_T lecture_3A_Model1_X;

/* Block states (default storage) */
DW_lecture_3A_Model1_T lecture_3A_Model1_DW;

/* Real-time model */
RT_MODEL_lecture_3A_Model1_T lecture_3A_Model1_M_ = RT_MODEL_lecture_3A_Model1_T
  ();
RT_MODEL_lecture_3A_Model1_T *const lecture_3A_Model1_M = &lecture_3A_Model1_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = static_cast<ODE4_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  lecture_3A_Model1_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  lecture_3A_Model1_step();
  lecture_3A_Model1_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  lecture_3A_Model1_step();
  lecture_3A_Model1_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  lecture_3A_Model1_step();
  lecture_3A_Model1_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void lecture_3A_Model1_step(void)
{
  LtiIcParams icParams;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  PmRealVector uPr;
  PmRealVector xPr;
  char *msg;
  real_T icVectorsStore[17];
  real_T mX[10];
  real_T mX_0[9];
  real_T mX_1[4];
  real_T mX_2[4];
  real_T mX_5[4];
  real_T mX_6[4];
  real_T x[4];
  real_T mX_3[3];
  real_T mX_4[2];
  real_T u[2];
  real_T u0;
  real_T u1;
  real_T u2;
  real_T *icStorePtr;
  int_T ir[10];
  int_T jc[10];
  int_T jc_1[5];
  int_T jc_3[5];
  int_T ir_0[4];
  int_T ir_1[3];
  int_T jc_0[3];
  int_T jc_2[3];
  int_T jc_4[3];
  int_T ir_2[2];
  int_T k;
  boolean_T first_output;
  if (rtmIsMajorTimeStep(lecture_3A_Model1_M)) {
    /* set solver stop time */
    if (!(lecture_3A_Model1_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lecture_3A_Model1_M->solverInfo,
                            ((lecture_3A_Model1_M->Timing.clockTickH0 + 1) *
        lecture_3A_Model1_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lecture_3A_Model1_M->solverInfo,
                            ((lecture_3A_Model1_M->Timing.clockTick0 + 1) *
        lecture_3A_Model1_M->Timing.stepSize0 +
        lecture_3A_Model1_M->Timing.clockTickH0 *
        lecture_3A_Model1_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lecture_3A_Model1_M)) {
    lecture_3A_Model1_M->Timing.t[0] = rtsiGetT(&lecture_3A_Model1_M->solverInfo);
  }

  /* SimscapeLtiState: '<S17>/LTI_STATE_1' */
  x[0] = lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[0];
  x[1] = lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[1];
  x[2] = lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[2];
  x[3] = lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[3];
  if (lecture_3A_Model1_DW.LTI_STATE_1_FirstOutput == 0.0) {
    lecture_3A_Model1_DW.LTI_STATE_1_FirstOutput = 1.0;
    xPr.mN = 4;
    xPr.mX = &x[0];
    u[0] = lecture_3A_Model1_B.INPUT_1_1_1[0];
    u[1] = lecture_3A_Model1_B.INPUT_2_1_1[0];
    uPr.mN = 2;
    uPr.mX = &u[0];
    icParams.mFirstSolve.mStatesPattern.mNumCol = 9;
    icParams.mFirstSolve.mStatesPattern.mNumRow = 9;
    ir[0] = 4;
    ir[1] = 8;
    ir[2] = 5;
    ir[3] = 6;
    ir[4] = 7;
    ir[5] = 0;
    ir[6] = 1;
    ir[7] = 2;
    ir[8] = 3;
    ir[9] = 0;
    icParams.mFirstSolve.mStatesPattern.mIr = &ir[0];
    jc[0] = 0;
    jc[1] = 2;
    jc[2] = 3;
    jc[3] = 4;
    jc[4] = 5;
    jc[5] = 6;
    jc[6] = 7;
    jc[7] = 8;
    jc[8] = 9;
    jc[9] = 10;
    icParams.mFirstSolve.mStatesPattern.mJc = &jc[0];
    icParams.mFirstSolve.mStatesPr.mN = 10;
    mX[0] = 1.0;
    mX[1] = 1.0;
    mX[2] = 1.0;
    mX[3] = 1.0;
    mX[4] = 1.0;
    mX[5] = 1.0;
    mX[6] = 1.0;
    mX[7] = 1.0;
    mX[8] = 1.0;
    mX[9] = 1.0;
    icParams.mFirstSolve.mStatesPr.mX = &mX[0];
    icParams.mFirstSolve.mInputsPattern.mNumCol = 2;
    icParams.mFirstSolve.mInputsPattern.mNumRow = 9;
    jc_0[0] = 0;
    jc_0[1] = 0;
    jc_0[2] = 0;
    icParams.mFirstSolve.mInputsPattern.mJc = &jc_0[0];
    icParams.mFirstSolve.mInputsPr.mN = 0;
    icParams.mFirstSolve.mConsts.mN = 9;
    mX_0[0] = (rtNaN);
    mX_0[1] = (rtNaN);
    mX_0[2] = (rtNaN);
    mX_0[3] = (rtNaN);
    mX_0[4] = (rtNaN);
    mX_0[5] = (rtNaN);
    mX_0[6] = (rtNaN);
    mX_0[7] = (rtNaN);
    mX_0[8] = (rtNaN);
    icParams.mFirstSolve.mConsts.mX = &mX_0[0];
    icParams.mSecondSolve.mStatesPattern.mNumCol = 4;
    icParams.mSecondSolve.mStatesPattern.mNumRow = 4;
    ir_0[0] = 0;
    ir_0[1] = 1;
    ir_0[2] = 2;
    ir_0[3] = 3;
    icParams.mSecondSolve.mStatesPattern.mIr = &ir_0[0];
    jc_1[0] = 0;
    jc_1[1] = 1;
    jc_1[2] = 2;
    jc_1[3] = 3;
    jc_1[4] = 4;
    icParams.mSecondSolve.mStatesPattern.mJc = &jc_1[0];
    icParams.mSecondSolve.mStatesPr.mN = 4;
    mX_1[0] = 2.0;
    mX_1[1] = 1.0;
    mX_1[2] = 1.0;
    mX_1[3] = 1.0;
    icParams.mSecondSolve.mStatesPr.mX = &mX_1[0];
    icParams.mSecondSolve.mInputsPattern.mNumCol = 2;
    icParams.mSecondSolve.mInputsPattern.mNumRow = 4;
    jc_2[0] = 0;
    jc_2[1] = 0;
    jc_2[2] = 0;
    icParams.mSecondSolve.mInputsPattern.mJc = &jc_2[0];
    icParams.mSecondSolve.mInputsPr.mN = 0;
    icParams.mSecondSolve.mConsts.mN = 4;
    mX_2[0] = (rtNaN);
    mX_2[1] = (rtNaN);
    mX_2[2] = (rtNaN);
    mX_2[3] = (rtNaN);
    icParams.mSecondSolve.mConsts.mX = &mX_2[0];
    icParams.mDcSolve.mAPattern.mNumCol = 4;
    icParams.mDcSolve.mAPattern.mNumRow = 4;
    ir_1[0] = 1;
    ir_1[1] = 2;
    ir_1[2] = 3;
    icParams.mDcSolve.mAPattern.mIr = &ir_1[0];
    jc_3[0] = 0;
    jc_3[1] = 3;
    jc_3[2] = 3;
    jc_3[3] = 3;
    jc_3[4] = 3;
    icParams.mDcSolve.mAPattern.mJc = &jc_3[0];
    icParams.mDcSolve.mAPr.mN = 3;
    mX_3[0] = 1.0;
    mX_3[1] = 1.0;
    mX_3[2] = 1.0;
    icParams.mDcSolve.mAPr.mX = &mX_3[0];
    icParams.mDcSolve.mBPattern.mNumCol = 2;
    icParams.mDcSolve.mBPattern.mNumRow = 4;
    ir_2[0] = 0;
    ir_2[1] = 0;
    icParams.mDcSolve.mBPattern.mIr = &ir_2[0];
    jc_4[0] = 0;
    jc_4[1] = 1;
    jc_4[2] = 2;
    icParams.mDcSolve.mBPattern.mJc = &jc_4[0];
    icParams.mDcSolve.mBPr.mN = 2;
    mX_4[0] = 114207.40063956144;
    mX_4[1] = 114207.40063956144;
    icParams.mDcSolve.mBPr.mX = &mX_4[0];
    icParams.mDcSolve.mFa.mN = 4;
    mX_5[0] = 0.0;
    mX_5[1] = 0.0;
    mX_5[2] = 0.0;
    mX_5[3] = 0.0;
    icParams.mDcSolve.mFa.mX = &mX_5[0];
    icParams.mGuess.mN = 4;
    mX_6[0] = (rtNaN);
    mX_6[1] = (rtNaN);
    mX_6[2] = (rtNaN);
    mX_6[3] = (rtNaN);
    icParams.mGuess.mX = &mX_6[0];
    icParams.mResTol = 1.0E-9;
    icParams.mDoDC = false;
    icStorePtr = &icVectorsStore[0];
    lecture_3A_Model1_5986c43_1_ic_fcn(&icStorePtr);
    icParams.mGuess.mN = 4;
    icParams.mGuess.mX = &icVectorsStore[0];
    icParams.mFirstSolve.mConsts.mN = 9;
    icParams.mFirstSolve.mConsts.mX = &icVectorsStore[4];
    icParams.mSecondSolve.mConsts.mN = 4;
    icParams.mSecondSolve.mConsts.mX = &icVectorsStore[13];
    diagnosticManager = rtw_create_diagnostics();
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    first_output = cgIcSolve(&xPr, &uPr, &icParams, diagnosticManager);
    if (!first_output) {
      first_output = error_buffer_is_empty(rtmGetErrorStatus(lecture_3A_Model1_M));
      if (first_output) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(lecture_3A_Model1_M, msg);
      }
    }

    neu_destroy_diagnostic_manager(diagnosticManager);
    lecture_3A_Model1_B.LTI_STATE_1[0] = x[0];
    lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[0] = x[0];
    lecture_3A_Model1_B.LTI_STATE_1[1] = x[1];
    lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[1] = x[1];
    lecture_3A_Model1_B.LTI_STATE_1[2] = x[2];
    lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[2] = x[2];
    lecture_3A_Model1_B.LTI_STATE_1[3] = x[3];
    lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[3] = x[3];
  } else {
    lecture_3A_Model1_B.LTI_STATE_1[0] =
      lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[0];
    lecture_3A_Model1_B.LTI_STATE_1[1] =
      lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[1];
    lecture_3A_Model1_B.LTI_STATE_1[2] =
      lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[2];
    lecture_3A_Model1_B.LTI_STATE_1[3] =
      lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[3];
  }

  /* End of SimscapeLtiState: '<S17>/LTI_STATE_1' */

  /* SimscapeLtiOutput: '<S17>/LTI_OUTPUT_1_1' */
  lecture_3A_Model1_B.LTI_OUTPUT_1_1[0] = 0.0;
  lecture_3A_Model1_B.LTI_OUTPUT_1_1[1] = 0.0;
  lecture_3A_Model1_B.LTI_OUTPUT_1_1[2] = 0.0;
  for (k = 0; k < 3; k++) {
    lecture_3A_Model1_B.LTI_OUTPUT_1_1[k] += lecture_3A_Model1_B.LTI_STATE_1[0];
  }

  /* End of SimscapeLtiOutput: '<S17>/LTI_OUTPUT_1_1' */

  /* Gain: '<S3>/Gain' */
  lecture_3A_Model1_B.Generator_Torque = 9.5492965855137211 *
    lecture_3A_Model1_B.LTI_OUTPUT_1_1[0];

  /* Gain: '<S3>/Voltage' */
  lecture_3A_Model1_B.GeneratorVoltage = 0.0068571428571428568 *
    lecture_3A_Model1_B.Generator_Torque;

  /* Product: '<S3>/Divide' */
  lecture_3A_Model1_B.GeneratorCurrent = lecture_3A_Model1_B.GeneratorVoltage /
    lecture_3A_Model1_ConstB.Totalresistance;

  /* Gain: '<S3>/OZ-in//Amp' */
  lecture_3A_Model1_B.OZinAmp = 9.1 * lecture_3A_Model1_B.GeneratorCurrent;

  /* Gain: '<S3>/OZ-in to Nm' */
  lecture_3A_Model1_B.OZintoNm = 0.007062 * lecture_3A_Model1_B.OZinAmp;

  /* Gain: '<S3>/Gain2' */
  lecture_3A_Model1_B.Gain2 = (-1.0) * lecture_3A_Model1_B.OZintoNm;

  /* SimscapeInputBlock: '<S17>/INPUT_1_1_1' */
  lecture_3A_Model1_B.INPUT_1_1_1[0] = lecture_3A_Model1_B.Gain2;
  lecture_3A_Model1_B.INPUT_1_1_1[1] = 0.0;
  lecture_3A_Model1_B.INPUT_1_1_1[2] = 0.0;
  lecture_3A_Model1_B.INPUT_1_1_1[3] = 0.0;

  /* Gain: '<S5>/Gain' */
  lecture_3A_Model1_B.Actual_RPM = 9.5492965855137211 *
    lecture_3A_Model1_B.LTI_OUTPUT_1_1[2];

  /* Sum: '<S1>/Sum' */
  lecture_3A_Model1_B.Sum = lecture_3A_Model1_B.Desired_RPM -
    lecture_3A_Model1_B.Actual_RPM;

  /* Gain: '<S1>/Gain' */
  lecture_3A_Model1_B.Gain = 0.01 * lecture_3A_Model1_B.Sum;

  /* Saturate: '<S1>/Saturation' */
  u0 = lecture_3A_Model1_B.Gain;
  u1 = 0.0;
  u2 = 1.0;
  if (u0 > u2) {
    /* Saturate: '<S1>/Saturation' */
    lecture_3A_Model1_B.ControllerTorqueRequest = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S1>/Saturation' */
    lecture_3A_Model1_B.ControllerTorqueRequest = u1;
  } else {
    /* Saturate: '<S1>/Saturation' */
    lecture_3A_Model1_B.ControllerTorqueRequest = u0;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S4>/Gain' */
  lecture_3A_Model1_B.Motor_Torque = 9.5492965855137211 *
    lecture_3A_Model1_B.LTI_OUTPUT_1_1[1];

  /* Lookup_n-D: '<S4>/1-D Lookup Table' incorporates:
   *  Gain: '<S4>/Gain'
   */
  lecture_3A_Model1_B.uDLookupTable = look1_binlxpw
    (lecture_3A_Model1_B.Motor_Torque,
     lecture_3A_Model1_ConstP.uDLookupTable_bp01Data,
     lecture_3A_Model1_ConstP.uDLookupTable_tableData, 4U);

  /* Product: '<S4>/Product' */
  lecture_3A_Model1_B.Torque_Nm = lecture_3A_Model1_B.ControllerTorqueRequest *
    lecture_3A_Model1_B.uDLookupTable;

  /* Saturate: '<S4>/Saturation' */
  u0 = lecture_3A_Model1_B.Torque_Nm;
  if ((u0 <= 0.0) || rtIsNaN(0.0)) {
    /* Saturate: '<S4>/Saturation' */
    lecture_3A_Model1_B.Saturation = 0.0;
  } else {
    /* Saturate: '<S4>/Saturation' */
    lecture_3A_Model1_B.Saturation = u0;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* SimscapeInputBlock: '<S17>/INPUT_2_1_1' */
  lecture_3A_Model1_B.INPUT_2_1_1[0] = lecture_3A_Model1_B.Saturation;
  lecture_3A_Model1_B.INPUT_2_1_1[1] = 0.0;
  lecture_3A_Model1_B.INPUT_2_1_1[2] = 0.0;
  lecture_3A_Model1_B.INPUT_2_1_1[3] = 0.0;

  /* SimscapeLtiOutput: '<S17>/LTI_OUTPUT_1_2' */
  lecture_3A_Model1_B.Torque_NM = 0.0;

  /* SimscapeLtiOutput: '<S17>/LTI_OUTPUT_1_2' */
  u0 = lecture_3A_Model1_B.INPUT_2_1_1[0];

  /* SimscapeLtiOutput: '<S17>/LTI_OUTPUT_1_2' */
  lecture_3A_Model1_B.Torque_NM += u0;
  if (rtmIsMajorTimeStep(lecture_3A_Model1_M)) {
    rt_ertODEUpdateContinuousStates(&lecture_3A_Model1_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lecture_3A_Model1_M->Timing.clockTick0)) {
      ++lecture_3A_Model1_M->Timing.clockTickH0;
    }

    lecture_3A_Model1_M->Timing.t[0] = rtsiGetSolverStopTime
      (&lecture_3A_Model1_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      lecture_3A_Model1_M->Timing.clockTick1++;
      if (!lecture_3A_Model1_M->Timing.clockTick1) {
        lecture_3A_Model1_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void lecture_3A_Model1_derivatives(void)
{
  XDot_lecture_3A_Model1_T *_rtXdot;
  real_T u_idx_0;
  real_T u_idx_1;
  int_T k;
  _rtXdot = ((XDot_lecture_3A_Model1_T *) lecture_3A_Model1_M->derivs);

  /* Derivatives for SimscapeLtiState: '<S17>/LTI_STATE_1' */
  _rtXdot->lecture_3A_Model1PlantGenerator[0] = 0.0;
  _rtXdot->lecture_3A_Model1PlantGenerator[1] = 0.0;
  _rtXdot->lecture_3A_Model1PlantGenerator[2] = 0.0;
  _rtXdot->lecture_3A_Model1PlantGenerator[3] = 0.0;
  for (k = 1; k - 1 < 3; k++) {
    _rtXdot->lecture_3A_Model1PlantGenerator[k] +=
      lecture_3A_Model1_X.lecture_3A_Model1PlantGenerator[0];
  }

  u_idx_0 = lecture_3A_Model1_B.INPUT_1_1_1[0];
  u_idx_1 = lecture_3A_Model1_B.INPUT_2_1_1[0];
  _rtXdot->lecture_3A_Model1PlantGenerator[0] += 114207.40063956144 * u_idx_0;
  _rtXdot->lecture_3A_Model1PlantGenerator[0] += 114207.40063956144 * u_idx_1;

  /* End of Derivatives for SimscapeLtiState: '<S17>/LTI_STATE_1' */
}

/* Model initialize function */
void lecture_3A_Model1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lecture_3A_Model1_M->solverInfo,
                          &lecture_3A_Model1_M->Timing.simTimeStep);
    rtsiSetTPtr(&lecture_3A_Model1_M->solverInfo, &rtmGetTPtr
                (lecture_3A_Model1_M));
    rtsiSetStepSizePtr(&lecture_3A_Model1_M->solverInfo,
                       &lecture_3A_Model1_M->Timing.stepSize0);
    rtsiSetdXPtr(&lecture_3A_Model1_M->solverInfo, &lecture_3A_Model1_M->derivs);
    rtsiSetContStatesPtr(&lecture_3A_Model1_M->solverInfo, (real_T **)
                         &lecture_3A_Model1_M->contStates);
    rtsiSetNumContStatesPtr(&lecture_3A_Model1_M->solverInfo,
      &lecture_3A_Model1_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lecture_3A_Model1_M->solverInfo,
      &lecture_3A_Model1_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lecture_3A_Model1_M->solverInfo,
      &lecture_3A_Model1_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lecture_3A_Model1_M->solverInfo,
      &lecture_3A_Model1_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lecture_3A_Model1_M->solverInfo, (&rtmGetErrorStatus
      (lecture_3A_Model1_M)));
    rtsiSetRTModelPtr(&lecture_3A_Model1_M->solverInfo, lecture_3A_Model1_M);
  }

  rtsiSetSimTimeStep(&lecture_3A_Model1_M->solverInfo, MAJOR_TIME_STEP);
  lecture_3A_Model1_M->intgData.y = lecture_3A_Model1_M->odeY;
  lecture_3A_Model1_M->intgData.f[0] = lecture_3A_Model1_M->odeF[0];
  lecture_3A_Model1_M->intgData.f[1] = lecture_3A_Model1_M->odeF[1];
  lecture_3A_Model1_M->intgData.f[2] = lecture_3A_Model1_M->odeF[2];
  lecture_3A_Model1_M->intgData.f[3] = lecture_3A_Model1_M->odeF[3];
  lecture_3A_Model1_M->contStates = ((X_lecture_3A_Model1_T *)
    &lecture_3A_Model1_X);
  rtsiSetSolverData(&lecture_3A_Model1_M->solverInfo, static_cast<void *>
                    (&lecture_3A_Model1_M->intgData));
  rtsiSetSolverName(&lecture_3A_Model1_M->solverInfo,"ode4");
  rtmSetTPtr(lecture_3A_Model1_M, &lecture_3A_Model1_M->Timing.tArray[0]);
  lecture_3A_Model1_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&lecture_3A_Model1_B)), 0,
                     sizeof(B_lecture_3A_Model1_T));

  {
    lecture_3A_Model1_B.Desired_RPM = 1800.0;
  }

  /* states (continuous) */
  {
    (void) std::memset(static_cast<void *>(&lecture_3A_Model1_X), 0,
                       sizeof(X_lecture_3A_Model1_T));
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&lecture_3A_Model1_DW), 0,
                     sizeof(DW_lecture_3A_Model1_T));

  /* ConstCode for Constant: '<Root>/Desired_speed(RPM)' */
  lecture_3A_Model1_B.Desired_RPM = 1800.0;
}

/* Model terminate function */
void lecture_3A_Model1_terminate(void)
{
  /* (no terminate code required) */
}

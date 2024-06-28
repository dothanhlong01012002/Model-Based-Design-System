/*
 * lecture_3A_Model1.h
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

#ifndef RTW_HEADER_lecture_3A_Model1_h_
#define RTW_HEADER_lecture_3A_Model1_h_
#include <cstring>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "lecture_3A_Model1_5986c43_1_ic_fcn.h"
#include "nesl_rtw_lti.h"
#include "lecture_3A_Model1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
struct B_lecture_3A_Model1_T {
  real_T LTI_STATE_1[4];               /* '<S17>/LTI_STATE_1' */
  real_T LTI_OUTPUT_1_1[3];            /* '<S17>/LTI_OUTPUT_1_1' */
  real_T Generator_Torque;             /* '<S3>/Gain' */
  real_T GeneratorVoltage;             /* '<S3>/Voltage' */
  real_T GeneratorCurrent;             /* '<S3>/Divide' */
  real_T OZinAmp;                      /* '<S3>/OZ-in//Amp' */
  real_T OZintoNm;                     /* '<S3>/OZ-in to Nm' */
  real_T Gain2;                        /* '<S3>/Gain2' */
  real_T INPUT_1_1_1[4];               /* '<S17>/INPUT_1_1_1' */
  real_T Actual_RPM;                   /* '<S5>/Gain' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T ControllerTorqueRequest;      /* '<S1>/Saturation' */
  real_T Motor_Torque;                 /* '<S4>/Gain' */
  real_T uDLookupTable;                /* '<S4>/1-D Lookup Table' */
  real_T Torque_Nm;                    /* '<S4>/Product' */
  real_T Saturation;                   /* '<S4>/Saturation' */
  real_T INPUT_2_1_1[4];               /* '<S17>/INPUT_2_1_1' */
  real_T Torque_NM;                    /* '<S17>/LTI_OUTPUT_1_2' */
  real_T Desired_RPM;                  /* '<Root>/Desired_speed(RPM)' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_lecture_3A_Model1_T {
  real_T LTI_STATE_1_FirstOutput;      /* '<S17>/LTI_STATE_1' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S17>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete[2];      /* '<S17>/INPUT_2_1_1' */
};

/* Continuous states (default storage) */
struct X_lecture_3A_Model1_T {
  real_T lecture_3A_Model1PlantGenerator[4];/* '<S17>/LTI_STATE_1' */
};

/* State derivatives (default storage) */
struct XDot_lecture_3A_Model1_T {
  real_T lecture_3A_Model1PlantGenerator[4];/* '<S17>/LTI_STATE_1' */
};

/* State disabled  */
struct XDis_lecture_3A_Model1_T {
  boolean_T lecture_3A_Model1PlantGenerator[4];/* '<S17>/LTI_STATE_1' */
};

/* Invariant block signals (default storage) */
struct ConstB_lecture_3A_Model1_T {
  real_T Saturation1;                  /* '<S3>/Saturation1' */
  real_T RoundingFunction;             /* '<S3>/Rounding Function' */
  real_T Totalresistance;              /* '<S3>/Divide1' */
};

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
struct ODE4_IntgData {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
};

#endif

/* Constant parameters (default storage) */
struct ConstP_lecture_3A_Model1_T {
  /* Expression: [0.4 0.4 0.3 0.2 0]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[5];

  /* Expression: [0 1000 2000 3000 4000]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[5];
};

/* Real-time Model Data Structure */
struct tag_RTM_lecture_3A_Model1_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_lecture_3A_Model1_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[4][4];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_lecture_3A_Model1_T lecture_3A_Model1_B;

#ifdef __cplusplus

}
#endif

/* Continuous states (default storage) */
extern X_lecture_3A_Model1_T lecture_3A_Model1_X;

/* Block states (default storage) */
extern struct DW_lecture_3A_Model1_T lecture_3A_Model1_DW;
extern const ConstB_lecture_3A_Model1_T lecture_3A_Model1_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_lecture_3A_Model1_T lecture_3A_Model1_ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void lecture_3A_Model1_initialize(void);
  extern void lecture_3A_Model1_step(void);
  extern void lecture_3A_Model1_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_lecture_3A_Model1_T *const lecture_3A_Model1_M;

#ifdef __cplusplus

}
#endif

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
 * '<Root>' : 'lecture_3A_Model1'
 * '<S1>'   : 'lecture_3A_Model1/Controller '
 * '<S2>'   : 'lecture_3A_Model1/Plant'
 * '<S3>'   : 'lecture_3A_Model1/Plant/Generator '
 * '<S4>'   : 'lecture_3A_Model1/Plant/Motor '
 * '<S5>'   : 'lecture_3A_Model1/Plant/Shaft Encoder'
 * '<S6>'   : 'lecture_3A_Model1/Plant/Generator /PS-Simulink Converter'
 * '<S7>'   : 'lecture_3A_Model1/Plant/Generator /Simulink-PS Converter'
 * '<S8>'   : 'lecture_3A_Model1/Plant/Generator /PS-Simulink Converter/EVAL_KEY'
 * '<S9>'   : 'lecture_3A_Model1/Plant/Generator /Simulink-PS Converter/EVAL_KEY'
 * '<S10>'  : 'lecture_3A_Model1/Plant/Motor /PS-Simulink Converter'
 * '<S11>'  : 'lecture_3A_Model1/Plant/Motor /PS-Simulink Converter1'
 * '<S12>'  : 'lecture_3A_Model1/Plant/Motor /Simulink-PS Converter'
 * '<S13>'  : 'lecture_3A_Model1/Plant/Motor /Solver Configuration'
 * '<S14>'  : 'lecture_3A_Model1/Plant/Motor /PS-Simulink Converter/EVAL_KEY'
 * '<S15>'  : 'lecture_3A_Model1/Plant/Motor /PS-Simulink Converter1/EVAL_KEY'
 * '<S16>'  : 'lecture_3A_Model1/Plant/Motor /Simulink-PS Converter/EVAL_KEY'
 * '<S17>'  : 'lecture_3A_Model1/Plant/Motor /Solver Configuration/EVAL_KEY'
 * '<S18>'  : 'lecture_3A_Model1/Plant/Shaft Encoder/PS-Simulink Converter'
 * '<S19>'  : 'lecture_3A_Model1/Plant/Shaft Encoder/PS-Simulink Converter/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_lecture_3A_Model1_h_ */

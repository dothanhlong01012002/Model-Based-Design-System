/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'lecture_3A_Model1/Plant/Motor /Solver Configuration'.
 */
/* lecture_3A_Model1_5986c43_1_ic_fcn.c - body for module lecture_3A_Model1_5986c43_1_ic_fcn */

#include "lecture_3A_Model1_5986c43_1_ic_fcn.h"

void lecture_3A_Model1_5986c43_1_ic_fcn(real_T **out)
{
  real_T t8[17];
  real_T t22[9];
  real_T t5[9];
  real_T t21[4];
  real_T t23[4];
  real_T t4[4];
  uint32_T t11;
  t4[0] = 0.0;
  t4[1] = 0.0;
  t4[2] = 0.0;
  t4[3] = 0.0;
  t5[0] = 0.0;
  t5[1] = 0.0;
  t5[2] = 0.0;
  t5[3] = 0.0;
  t5[4] = 0.0;
  t5[5] = 0.0;
  t5[6] = 0.0;
  t5[7] = 0.0;
  t5[8] = 0.0;
  for (t11 = 0U; t11 < 4U; t11++) {
    t21[t11] = t4[t11];
  }

  for (t11 = 0U; t11 < 9U; t11++) {
    t22[t11] = t5[t11];
  }

  for (t11 = 0U; t11 < 4U; t11++) {
    t23[t11] = t4[t11];
  }

  for (t11 = 0U; t11 < 4U; t11++) {
    t4[t11] = t21[t11];
  }

  for (t11 = 0U; t11 < 9U; t11++) {
    t5[t11] = t22[t11];
  }

  for (t11 = 0U; t11 < 4U; t11++) {
    t21[t11] = t23[t11];
  }

  for (t11 = 0U; t11 < 4U; t11++) {
    t8[t11] = t4[t11];
  }

  for (t11 = 0U; t11 < 9U; t11++) {
    t8[t11 + 4U] = t5[t11];
  }

  for (t11 = 0U; t11 < 4U; t11++) {
    t8[t11 + 13U] = t21[t11];
  }

  (*out)[0] = t8[0];
  (*out)[1] = t8[1];
  (*out)[2] = t8[2];
  (*out)[3] = t8[3];
  (*out)[4] = t8[4];
  (*out)[5] = t8[5];
  (*out)[6] = t8[6];
  (*out)[7] = t8[7];
  (*out)[8] = t8[8];
  (*out)[9] = t8[9];
  (*out)[10] = t8[10];
  (*out)[11] = t8[11];
  (*out)[12] = t8[12];
  (*out)[13] = t8[13];
  (*out)[14] = t8[14];
  (*out)[15] = t8[15];
  (*out)[16] = t8[16];
}

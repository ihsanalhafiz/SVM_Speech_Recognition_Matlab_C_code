/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationECOC.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 24-Dec-2022 01:10:36
 */

/* Include Files */
#include "CompactClassificationECOC.h"
#include "rt_nonfinite.h"
#include "svm_speech_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double obj_Prior[5]
 *                const c_classreg_learning_classif_Com obj_BinaryLearners[10]
 *                const double obj_CodingMatrix[50]
 *                const float Xin[32]
 * Return Type  : double
 */
double c_CompactClassificationECOC_pre(
    const double obj_Prior[5],
    const c_classreg_learning_classif_Com obj_BinaryLearners[10],
    const double obj_CodingMatrix[50], const float Xin[32])
{
  double M_idx_0;
  double M_idx_1;
  double M_idx_10;
  double M_idx_11;
  double M_idx_12;
  double M_idx_13;
  double M_idx_14;
  double M_idx_15;
  double M_idx_16;
  double M_idx_17;
  double M_idx_18;
  double M_idx_19;
  double M_idx_2;
  double M_idx_20;
  double M_idx_21;
  double M_idx_22;
  double M_idx_23;
  double M_idx_24;
  double M_idx_25;
  double M_idx_26;
  double M_idx_27;
  double M_idx_28;
  double M_idx_29;
  double M_idx_3;
  double M_idx_30;
  double M_idx_31;
  double M_idx_32;
  double M_idx_33;
  double M_idx_34;
  double M_idx_35;
  double M_idx_36;
  double M_idx_37;
  double M_idx_38;
  double M_idx_39;
  double M_idx_4;
  double M_idx_40;
  double M_idx_41;
  double M_idx_42;
  double M_idx_43;
  double M_idx_44;
  double M_idx_45;
  double M_idx_46;
  double M_idx_47;
  double M_idx_48;
  double M_idx_49;
  double M_idx_5;
  double M_idx_6;
  double M_idx_7;
  double M_idx_8;
  double M_idx_9;
  double labels;
  float pscore[10];
  float negloss[5];
  float X_tmp;
  float b_X;
  int i;
  int idx;
  int k;
  signed char c_tmp_data[32];
  signed char tmp_data[32];
  bool b[5];
  bool exitg1;
  bool valueisnan;
  M_idx_0 = obj_CodingMatrix[0];
  if (obj_CodingMatrix[0] == 0.0) {
    M_idx_0 = rtNaN;
  }
  M_idx_1 = obj_CodingMatrix[1];
  if (obj_CodingMatrix[1] == 0.0) {
    M_idx_1 = rtNaN;
  }
  M_idx_2 = obj_CodingMatrix[2];
  if (obj_CodingMatrix[2] == 0.0) {
    M_idx_2 = rtNaN;
  }
  M_idx_3 = obj_CodingMatrix[3];
  if (obj_CodingMatrix[3] == 0.0) {
    M_idx_3 = rtNaN;
  }
  M_idx_4 = obj_CodingMatrix[4];
  if (obj_CodingMatrix[4] == 0.0) {
    M_idx_4 = rtNaN;
  }
  M_idx_5 = obj_CodingMatrix[5];
  if (obj_CodingMatrix[5] == 0.0) {
    M_idx_5 = rtNaN;
  }
  M_idx_6 = obj_CodingMatrix[6];
  if (obj_CodingMatrix[6] == 0.0) {
    M_idx_6 = rtNaN;
  }
  M_idx_7 = obj_CodingMatrix[7];
  if (obj_CodingMatrix[7] == 0.0) {
    M_idx_7 = rtNaN;
  }
  M_idx_8 = obj_CodingMatrix[8];
  if (obj_CodingMatrix[8] == 0.0) {
    M_idx_8 = rtNaN;
  }
  M_idx_9 = obj_CodingMatrix[9];
  if (obj_CodingMatrix[9] == 0.0) {
    M_idx_9 = rtNaN;
  }
  M_idx_10 = obj_CodingMatrix[10];
  if (obj_CodingMatrix[10] == 0.0) {
    M_idx_10 = rtNaN;
  }
  M_idx_11 = obj_CodingMatrix[11];
  if (obj_CodingMatrix[11] == 0.0) {
    M_idx_11 = rtNaN;
  }
  M_idx_12 = obj_CodingMatrix[12];
  if (obj_CodingMatrix[12] == 0.0) {
    M_idx_12 = rtNaN;
  }
  M_idx_13 = obj_CodingMatrix[13];
  if (obj_CodingMatrix[13] == 0.0) {
    M_idx_13 = rtNaN;
  }
  M_idx_14 = obj_CodingMatrix[14];
  if (obj_CodingMatrix[14] == 0.0) {
    M_idx_14 = rtNaN;
  }
  M_idx_15 = obj_CodingMatrix[15];
  if (obj_CodingMatrix[15] == 0.0) {
    M_idx_15 = rtNaN;
  }
  M_idx_16 = obj_CodingMatrix[16];
  if (obj_CodingMatrix[16] == 0.0) {
    M_idx_16 = rtNaN;
  }
  M_idx_17 = obj_CodingMatrix[17];
  if (obj_CodingMatrix[17] == 0.0) {
    M_idx_17 = rtNaN;
  }
  M_idx_18 = obj_CodingMatrix[18];
  if (obj_CodingMatrix[18] == 0.0) {
    M_idx_18 = rtNaN;
  }
  M_idx_19 = obj_CodingMatrix[19];
  if (obj_CodingMatrix[19] == 0.0) {
    M_idx_19 = rtNaN;
  }
  M_idx_20 = obj_CodingMatrix[20];
  if (obj_CodingMatrix[20] == 0.0) {
    M_idx_20 = rtNaN;
  }
  M_idx_21 = obj_CodingMatrix[21];
  if (obj_CodingMatrix[21] == 0.0) {
    M_idx_21 = rtNaN;
  }
  M_idx_22 = obj_CodingMatrix[22];
  if (obj_CodingMatrix[22] == 0.0) {
    M_idx_22 = rtNaN;
  }
  M_idx_23 = obj_CodingMatrix[23];
  if (obj_CodingMatrix[23] == 0.0) {
    M_idx_23 = rtNaN;
  }
  M_idx_24 = obj_CodingMatrix[24];
  if (obj_CodingMatrix[24] == 0.0) {
    M_idx_24 = rtNaN;
  }
  M_idx_25 = obj_CodingMatrix[25];
  if (obj_CodingMatrix[25] == 0.0) {
    M_idx_25 = rtNaN;
  }
  M_idx_26 = obj_CodingMatrix[26];
  if (obj_CodingMatrix[26] == 0.0) {
    M_idx_26 = rtNaN;
  }
  M_idx_27 = obj_CodingMatrix[27];
  if (obj_CodingMatrix[27] == 0.0) {
    M_idx_27 = rtNaN;
  }
  M_idx_28 = obj_CodingMatrix[28];
  if (obj_CodingMatrix[28] == 0.0) {
    M_idx_28 = rtNaN;
  }
  M_idx_29 = obj_CodingMatrix[29];
  if (obj_CodingMatrix[29] == 0.0) {
    M_idx_29 = rtNaN;
  }
  M_idx_30 = obj_CodingMatrix[30];
  if (obj_CodingMatrix[30] == 0.0) {
    M_idx_30 = rtNaN;
  }
  M_idx_31 = obj_CodingMatrix[31];
  if (obj_CodingMatrix[31] == 0.0) {
    M_idx_31 = rtNaN;
  }
  M_idx_32 = obj_CodingMatrix[32];
  if (obj_CodingMatrix[32] == 0.0) {
    M_idx_32 = rtNaN;
  }
  M_idx_33 = obj_CodingMatrix[33];
  if (obj_CodingMatrix[33] == 0.0) {
    M_idx_33 = rtNaN;
  }
  M_idx_34 = obj_CodingMatrix[34];
  if (obj_CodingMatrix[34] == 0.0) {
    M_idx_34 = rtNaN;
  }
  M_idx_35 = obj_CodingMatrix[35];
  if (obj_CodingMatrix[35] == 0.0) {
    M_idx_35 = rtNaN;
  }
  M_idx_36 = obj_CodingMatrix[36];
  if (obj_CodingMatrix[36] == 0.0) {
    M_idx_36 = rtNaN;
  }
  M_idx_37 = obj_CodingMatrix[37];
  if (obj_CodingMatrix[37] == 0.0) {
    M_idx_37 = rtNaN;
  }
  M_idx_38 = obj_CodingMatrix[38];
  if (obj_CodingMatrix[38] == 0.0) {
    M_idx_38 = rtNaN;
  }
  M_idx_39 = obj_CodingMatrix[39];
  if (obj_CodingMatrix[39] == 0.0) {
    M_idx_39 = rtNaN;
  }
  M_idx_40 = obj_CodingMatrix[40];
  if (obj_CodingMatrix[40] == 0.0) {
    M_idx_40 = rtNaN;
  }
  M_idx_41 = obj_CodingMatrix[41];
  if (obj_CodingMatrix[41] == 0.0) {
    M_idx_41 = rtNaN;
  }
  M_idx_42 = obj_CodingMatrix[42];
  if (obj_CodingMatrix[42] == 0.0) {
    M_idx_42 = rtNaN;
  }
  M_idx_43 = obj_CodingMatrix[43];
  if (obj_CodingMatrix[43] == 0.0) {
    M_idx_43 = rtNaN;
  }
  M_idx_44 = obj_CodingMatrix[44];
  if (obj_CodingMatrix[44] == 0.0) {
    M_idx_44 = rtNaN;
  }
  M_idx_45 = obj_CodingMatrix[45];
  if (obj_CodingMatrix[45] == 0.0) {
    M_idx_45 = rtNaN;
  }
  M_idx_46 = obj_CodingMatrix[46];
  if (obj_CodingMatrix[46] == 0.0) {
    M_idx_46 = rtNaN;
  }
  M_idx_47 = obj_CodingMatrix[47];
  if (obj_CodingMatrix[47] == 0.0) {
    M_idx_47 = rtNaN;
  }
  M_idx_48 = obj_CodingMatrix[48];
  if (obj_CodingMatrix[48] == 0.0) {
    M_idx_48 = rtNaN;
  }
  M_idx_49 = obj_CodingMatrix[49];
  if (obj_CodingMatrix[49] == 0.0) {
    M_idx_49 = rtNaN;
  }

  // Manual loop unrool

  float X[32];
  bool x[32];

  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[0].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[0].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[0].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[0].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[0].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[0].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[0].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[0].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[0].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[0].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[0].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[0].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[0].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[0].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[0].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[0].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[0].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[0].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[0].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[0].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[0].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[0].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[0].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[0].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[0].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[0].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[0].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[0].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[0].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[0].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[0].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[0].Mu[31] == 0.0);
  valueisnan = true;

  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll

  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[0].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[0].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[0].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[0].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[0].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[0].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[0].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[0].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[0].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[0].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[0].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[0].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[0].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[0].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[0].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[0].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[0].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[0].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[0].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[0].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[0].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[0].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[0].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[0].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[0].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[0].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[0].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[0].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[0].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[0].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[0].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[0].Mu[31];
  }
  x[0] = (obj_BinaryLearners[0].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[0].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[0].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[0].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[0].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[0].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[0].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[0].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[0].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[0].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[0].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[0].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[0].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[0].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[0].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[0].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[0].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[0].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[0].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[0].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[0].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[0].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[0].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[0].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[0].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[0].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[0].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[0].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[0].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[0].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[0].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[0].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_0_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[0].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[0].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[0].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[0].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[0].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[0].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[0].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[0].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[0].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[0].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[0].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[0].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[0].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[0].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[0].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[0].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[0].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[0].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[0].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[0].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[0].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[0].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[0].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[0].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[0].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[0].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[0].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[0].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[0].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[0].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[0].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[0].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_0_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_0_1 = 1;
    } else {
      tmp_size_0_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[0].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[0].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[0].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[0].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_0_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[0].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[0].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[0].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[0].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[0].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[0].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[0].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[0].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[0].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[0].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[0].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[0].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[0].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[0].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[0].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[0].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[0].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[0].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[0].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[0].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[0].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[0].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[0].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[0].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[0].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[0].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[0].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[0].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[0].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[0].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[0].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[0].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[0].Beta[31];
  pscore[0] = b_X + (float)obj_BinaryLearners[0].Bias;

  // number 1


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[1].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[1].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[1].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[1].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[1].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[1].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[1].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[1].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[1].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[1].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[1].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[1].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[1].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[1].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[1].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[1].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[1].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[1].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[1].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[1].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[1].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[1].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[1].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[1].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[1].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[1].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[1].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[1].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[1].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[1].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[1].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[1].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[1].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[1].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[1].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[1].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[1].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[1].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[1].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[1].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[1].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[1].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[1].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[1].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[1].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[1].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[1].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[1].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[1].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[1].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[1].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[1].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[1].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[1].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[1].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[1].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[1].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[1].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[1].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[1].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[1].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[1].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[1].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[1].Mu[31];
  }
  x[0] = (obj_BinaryLearners[1].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[1].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[1].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[1].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[1].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[1].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[1].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[1].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[1].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[1].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[1].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[1].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[1].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[1].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[1].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[1].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[1].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[1].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[1].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[1].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[1].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[1].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[1].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[1].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[1].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[1].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[1].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[1].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[1].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[1].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[1].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[1].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_1_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[1].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[1].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[1].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[1].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[1].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[1].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[1].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[1].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[1].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[1].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[1].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[1].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[1].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[1].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[1].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[1].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[1].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[1].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[1].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[1].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[1].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[1].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[1].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[1].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[1].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[1].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[1].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[1].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[1].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[1].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[1].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[1].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_1_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_1_1 = 1;
    } else {
      tmp_size_1_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[1].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[1].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[1].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[1].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_1_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[1].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[1].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[1].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[1].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[1].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[1].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[1].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[1].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[1].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[1].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[1].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[1].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[1].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[1].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[1].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[1].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[1].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[1].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[1].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[1].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[1].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[1].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[1].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[1].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[1].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[1].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[1].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[1].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[1].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[1].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[1].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[1].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[1].Beta[31];
  pscore[1] = b_X + (float)obj_BinaryLearners[1].Bias;

  // Number 2


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[2].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[2].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[2].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[2].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[2].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[2].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[2].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[2].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[2].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[2].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[2].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[2].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[2].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[2].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[2].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[2].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[2].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[2].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[2].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[2].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[2].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[2].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[2].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[2].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[2].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[2].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[2].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[2].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[2].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[2].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[2].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[2].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[2].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[2].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[2].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[2].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[2].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[2].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[2].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[2].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[2].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[2].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[2].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[2].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[2].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[2].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[2].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[2].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[2].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[2].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[2].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[2].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[2].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[2].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[2].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[2].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[2].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[2].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[2].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[2].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[2].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[2].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[2].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[2].Mu[31];
  }
  x[0] = (obj_BinaryLearners[2].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[2].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[2].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[2].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[2].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[2].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[2].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[2].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[2].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[2].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[2].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[2].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[2].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[2].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[2].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[2].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[2].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[2].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[2].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[2].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[2].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[2].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[2].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[2].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[2].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[2].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[2].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[2].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[2].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[2].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[2].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[2].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_2_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[2].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[2].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[2].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[2].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[2].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[2].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[2].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[2].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[2].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[2].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[2].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[2].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[2].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[2].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[2].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[2].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[2].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[2].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[2].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[2].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[2].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[2].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[2].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[2].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[2].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[2].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[2].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[2].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[2].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[2].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[2].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[2].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_2_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_2_1 = 1;
    } else {
      tmp_size_2_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[2].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[2].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[2].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[2].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_2_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[2].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[2].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[2].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[2].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[2].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[2].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[2].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[2].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[2].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[2].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[2].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[2].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[2].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[2].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[2].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[2].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[2].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[2].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[2].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[2].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[2].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[2].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[2].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[2].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[2].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[2].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[2].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[2].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[2].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[2].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[2].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[2].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[2].Beta[31];
  pscore[2] = b_X + (float)obj_BinaryLearners[2].Bias;

  // number 3


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[3].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[3].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[3].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[3].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[3].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[3].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[3].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[3].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[3].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[3].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[3].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[3].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[3].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[3].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[3].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[3].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[3].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[3].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[3].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[3].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[3].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[3].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[3].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[3].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[3].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[3].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[3].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[3].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[3].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[3].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[3].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[3].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[3].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[3].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[3].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[3].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[3].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[3].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[3].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[3].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[3].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[3].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[3].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[3].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[3].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[3].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[3].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[3].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[3].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[3].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[3].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[3].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[3].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[3].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[3].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[3].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[3].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[3].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[3].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[3].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[3].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[3].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[3].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[3].Mu[31];
  }
  x[0] = (obj_BinaryLearners[3].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[3].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[3].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[3].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[3].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[3].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[3].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[3].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[3].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[3].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[3].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[3].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[3].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[3].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[3].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[3].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[3].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[3].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[3].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[3].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[3].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[3].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[3].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[3].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[3].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[3].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[3].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[3].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[3].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[3].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[3].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[3].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_3_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[3].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[3].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[3].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[3].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[3].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[3].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[3].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[3].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[3].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[3].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[3].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[3].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[3].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[3].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[3].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[3].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[3].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[3].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[3].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[3].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[3].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[3].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[3].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[3].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[3].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[3].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[3].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[3].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[3].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[3].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[3].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[3].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_3_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_3_1 = 1;
    } else {
      tmp_size_3_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[3].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[3].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[3].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[3].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_3_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[3].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[3].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[3].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[3].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[3].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[3].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[3].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[3].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[3].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[3].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[3].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[3].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[3].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[3].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[3].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[3].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[3].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[3].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[3].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[3].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[3].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[3].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[3].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[3].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[3].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[3].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[3].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[3].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[3].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[3].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[3].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[3].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[3].Beta[31];
  pscore[3] = b_X + (float)obj_BinaryLearners[3].Bias;

  // number 4


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[4].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[4].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[4].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[4].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[4].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[4].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[4].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[4].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[4].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[4].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[4].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[4].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[4].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[4].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[4].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[4].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[4].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[4].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[4].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[4].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[4].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[4].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[4].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[4].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[4].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[4].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[4].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[4].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[4].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[4].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[4].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[4].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[4].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[4].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[4].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[4].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[4].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[4].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[4].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[4].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[4].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[4].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[4].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[4].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[4].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[4].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[4].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[4].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[4].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[4].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[4].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[4].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[4].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[4].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[4].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[4].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[4].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[4].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[4].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[4].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[4].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[4].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[4].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[4].Mu[31];
  }
  x[0] = (obj_BinaryLearners[4].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[4].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[4].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[4].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[4].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[4].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[4].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[4].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[4].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[4].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[4].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[4].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[4].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[4].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[4].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[4].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[4].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[4].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[4].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[4].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[4].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[4].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[4].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[4].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[4].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[4].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[4].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[4].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[4].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[4].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[4].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[4].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_4_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[4].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[4].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[4].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[4].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[4].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[4].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[4].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[4].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[4].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[4].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[4].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[4].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[4].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[4].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[4].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[4].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[4].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[4].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[4].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[4].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[4].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[4].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[4].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[4].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[4].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[4].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[4].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[4].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[4].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[4].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[4].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[4].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_4_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_4_1 = 1;
    } else {
      tmp_size_4_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[4].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[4].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[4].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[4].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_4_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[4].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[4].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[4].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[4].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[4].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[4].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[4].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[4].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[4].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[4].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[4].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[4].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[4].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[4].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[4].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[4].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[4].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[4].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[4].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[4].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[4].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[4].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[4].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[4].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[4].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[4].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[4].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[4].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[4].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[4].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[4].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[4].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[4].Beta[31];
  pscore[4] = b_X + (float)obj_BinaryLearners[4].Bias;

  // number 5


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[5].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[5].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[5].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[5].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[5].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[5].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[5].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[5].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[5].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[5].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[5].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[5].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[5].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[5].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[5].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[5].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[5].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[5].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[5].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[5].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[5].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[5].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[5].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[5].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[5].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[5].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[5].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[5].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[5].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[5].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[5].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[5].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[5].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[5].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[5].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[5].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[5].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[5].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[5].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[5].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[5].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[5].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[5].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[5].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[5].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[5].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[5].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[5].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[5].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[5].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[5].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[5].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[5].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[5].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[5].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[5].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[5].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[5].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[5].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[5].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[5].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[5].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[5].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[5].Mu[31];
  }
  x[0] = (obj_BinaryLearners[5].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[5].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[5].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[5].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[5].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[5].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[5].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[5].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[5].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[5].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[5].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[5].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[5].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[5].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[5].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[5].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[5].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[5].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[5].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[5].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[5].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[5].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[5].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[5].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[5].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[5].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[5].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[5].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[5].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[5].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[5].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[5].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_5_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[5].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[5].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[5].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[5].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[5].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[5].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[5].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[5].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[5].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[5].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[5].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[5].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[5].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[5].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[5].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[5].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[5].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[5].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[5].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[5].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[5].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[5].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[5].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[5].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[5].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[5].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[5].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[5].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[5].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[5].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[5].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[5].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_5_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_5_1 = 1;
    } else {
      tmp_size_5_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[5].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[5].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[5].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[5].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_5_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[5].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[5].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[5].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[5].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[5].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[5].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[5].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[5].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[5].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[5].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[5].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[5].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[5].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[5].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[5].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[5].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[5].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[5].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[5].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[5].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[5].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[5].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[5].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[5].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[5].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[5].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[5].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[5].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[5].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[5].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[5].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[5].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[5].Beta[31];
  pscore[5] = b_X + (float)obj_BinaryLearners[5].Bias;

  // number 6


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[6].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[6].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[6].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[6].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[6].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[6].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[6].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[6].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[6].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[6].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[6].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[6].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[6].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[6].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[6].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[6].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[6].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[6].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[6].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[6].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[6].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[6].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[6].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[6].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[6].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[6].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[6].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[6].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[6].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[6].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[6].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[6].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[6].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[6].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[6].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[6].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[6].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[6].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[6].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[6].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[6].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[6].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[6].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[6].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[6].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[6].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[6].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[6].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[6].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[6].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[6].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[6].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[6].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[6].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[6].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[6].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[6].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[6].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[6].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[6].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[6].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[6].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[6].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[6].Mu[31];
  }
  x[0] = (obj_BinaryLearners[6].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[6].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[6].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[6].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[6].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[6].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[6].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[6].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[6].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[6].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[6].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[6].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[6].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[6].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[6].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[6].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[6].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[6].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[6].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[6].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[6].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[6].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[6].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[6].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[6].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[6].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[6].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[6].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[6].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[6].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[6].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[6].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_6_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[6].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[6].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[6].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[6].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[6].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[6].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[6].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[6].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[6].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[6].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[6].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[6].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[6].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[6].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[6].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[6].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[6].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[6].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[6].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[6].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[6].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[6].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[6].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[6].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[6].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[6].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[6].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[6].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[6].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[6].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[6].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[6].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_6_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_6_1 = 1;
    } else {
      tmp_size_6_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[6].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[6].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[6].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[6].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_6_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[6].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[6].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[6].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[6].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[6].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[6].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[6].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[6].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[6].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[6].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[6].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[6].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[6].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[6].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[6].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[6].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[6].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[6].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[6].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[6].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[6].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[6].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[6].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[6].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[6].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[6].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[6].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[6].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[6].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[6].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[6].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[6].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[6].Beta[31];
  pscore[6] = b_X + (float)obj_BinaryLearners[6].Bias;

  // number 7


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[7].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[7].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[7].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[7].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[7].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[7].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[7].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[7].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[7].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[7].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[7].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[7].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[7].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[7].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[7].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[7].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[7].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[7].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[7].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[7].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[7].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[7].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[7].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[7].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[7].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[7].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[7].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[7].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[7].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[7].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[7].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[7].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[7].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[7].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[7].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[7].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[7].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[7].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[7].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[7].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[7].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[7].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[7].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[7].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[7].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[7].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[7].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[7].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[7].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[7].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[7].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[7].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[7].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[7].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[7].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[7].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[7].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[7].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[7].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[7].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[7].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[7].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[7].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[7].Mu[31];
  }
  x[0] = (obj_BinaryLearners[7].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[7].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[7].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[7].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[7].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[7].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[7].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[7].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[7].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[7].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[7].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[7].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[7].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[7].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[7].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[7].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[7].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[7].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[7].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[7].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[7].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[7].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[7].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[7].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[7].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[7].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[7].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[7].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[7].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[7].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[7].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[7].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_7_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[7].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[7].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[7].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[7].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[7].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[7].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[7].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[7].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[7].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[7].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[7].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[7].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[7].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[7].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[7].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[7].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[7].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[7].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[7].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[7].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[7].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[7].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[7].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[7].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[7].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[7].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[7].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[7].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[7].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[7].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[7].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[7].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_7_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_7_1 = 1;
    } else {
      tmp_size_7_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[7].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[7].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[7].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[7].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_7_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[7].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[7].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[7].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[7].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[7].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[7].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[7].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[7].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[7].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[7].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[7].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[7].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[7].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[7].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[7].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[7].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[7].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[7].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[7].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[7].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[7].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[7].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[7].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[7].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[7].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[7].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[7].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[7].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[7].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[7].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[7].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[7].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[7].Beta[31];
  pscore[7] = b_X + (float)obj_BinaryLearners[7].Bias;

  // number 8


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[8].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[8].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[8].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[8].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[8].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[8].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[8].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[8].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[8].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[8].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[8].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[8].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[8].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[8].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[8].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[8].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[8].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[8].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[8].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[8].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[8].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[8].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[8].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[8].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[8].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[8].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[8].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[8].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[8].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[8].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[8].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[8].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[8].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[8].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[8].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[8].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[8].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[8].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[8].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[8].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[8].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[8].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[8].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[8].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[8].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[8].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[8].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[8].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[8].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[8].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[8].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[8].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[8].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[8].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[8].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[8].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[8].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[8].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[8].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[8].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[8].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[8].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[8].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[8].Mu[31];
  }
  x[0] = (obj_BinaryLearners[8].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[8].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[8].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[8].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[8].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[8].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[8].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[8].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[8].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[8].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[8].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[8].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[8].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[8].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[8].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[8].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[8].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[8].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[8].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[8].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[8].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[8].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[8].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[8].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[8].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[8].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[8].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[8].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[8].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[8].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[8].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[8].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_8_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[8].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[8].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[8].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[8].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[8].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[8].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[8].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[8].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[8].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[8].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[8].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[8].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[8].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[8].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[8].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[8].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[8].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[8].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[8].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[8].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[8].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[8].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[8].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[8].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[8].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[8].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[8].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[8].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[8].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[8].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[8].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[8].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_8_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_8_1 = 1;
    } else {
      tmp_size_8_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[8].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[8].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[8].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[8].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_8_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[8].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[8].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[8].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[8].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[8].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[8].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[8].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[8].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[8].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[8].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[8].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[8].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[8].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[8].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[8].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[8].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[8].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[8].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[8].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[8].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[8].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[8].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[8].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[8].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[8].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[8].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[8].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[8].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[8].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[8].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[8].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[8].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[8].Beta[31];
  pscore[8] = b_X + (float)obj_BinaryLearners[8].Bias;

  // number 9


  X[0] = Xin[0];
  x[0] = (obj_BinaryLearners[9].Mu[0] == 0.0);
  X[1] = Xin[1];
  x[1] = (obj_BinaryLearners[9].Mu[1] == 0.0);
  X[2] = Xin[2];
  x[2] = (obj_BinaryLearners[9].Mu[2] == 0.0);
  X[3] = Xin[3];
  x[3] = (obj_BinaryLearners[9].Mu[3] == 0.0);
  X[4] = Xin[4];
  x[4] = (obj_BinaryLearners[9].Mu[4] == 0.0);
  X[5] = Xin[5];
  x[5] = (obj_BinaryLearners[9].Mu[5] == 0.0);
  X[6] = Xin[6];
  x[6] = (obj_BinaryLearners[9].Mu[6] == 0.0);
  X[7] = Xin[7];
  x[7] = (obj_BinaryLearners[9].Mu[7] == 0.0);
  X[8] = Xin[8];
  x[8] = (obj_BinaryLearners[9].Mu[8] == 0.0);
  X[9] = Xin[9];
  x[9] = (obj_BinaryLearners[9].Mu[9] == 0.0);
  X[10] = Xin[10];
  x[10] = (obj_BinaryLearners[9].Mu[10] == 0.0);
  X[11] = Xin[11];
  x[11] = (obj_BinaryLearners[9].Mu[11] == 0.0);
  X[12] = Xin[12];
  x[12] = (obj_BinaryLearners[9].Mu[12] == 0.0);
  X[13] = Xin[13];
  x[13] = (obj_BinaryLearners[9].Mu[13] == 0.0);
  X[14] = Xin[14];
  x[14] = (obj_BinaryLearners[9].Mu[14] == 0.0);
  X[15] = Xin[15];
  x[15] = (obj_BinaryLearners[9].Mu[15] == 0.0);
  X[16] = Xin[16];
  x[16] = (obj_BinaryLearners[9].Mu[16] == 0.0);
  X[17] = Xin[17];
  x[17] = (obj_BinaryLearners[9].Mu[17] == 0.0);
  X[18] = Xin[18];
  x[18] = (obj_BinaryLearners[9].Mu[18] == 0.0);
  X[19] = Xin[19];
  x[19] = (obj_BinaryLearners[9].Mu[19] == 0.0);
  X[20] = Xin[20];
  x[20] = (obj_BinaryLearners[9].Mu[20] == 0.0);
  X[21] = Xin[21];
  x[21] = (obj_BinaryLearners[9].Mu[21] == 0.0);
  X[22] = Xin[22];
  x[22] = (obj_BinaryLearners[9].Mu[22] == 0.0);
  X[23] = Xin[23];
  x[23] = (obj_BinaryLearners[9].Mu[23] == 0.0);
  X[24] = Xin[24];
  x[24] = (obj_BinaryLearners[9].Mu[24] == 0.0);
  X[25] = Xin[25];
  x[25] = (obj_BinaryLearners[9].Mu[25] == 0.0);
  X[26] = Xin[26];
  x[26] = (obj_BinaryLearners[9].Mu[26] == 0.0);
  X[27] = Xin[27];
  x[27] = (obj_BinaryLearners[9].Mu[27] == 0.0);
  X[28] = Xin[28];
  x[28] = (obj_BinaryLearners[9].Mu[28] == 0.0);
  X[29] = Xin[29];
  x[29] = (obj_BinaryLearners[9].Mu[29] == 0.0);
  X[30] = Xin[30];
  x[30] = (obj_BinaryLearners[9].Mu[30] == 0.0);
  X[31] = Xin[31];
  x[31] = (obj_BinaryLearners[9].Mu[31] == 0.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    X[0] = Xin[0] - (float)obj_BinaryLearners[9].Mu[0];
    X[1] = Xin[1] - (float)obj_BinaryLearners[9].Mu[1];
    X[2] = Xin[2] - (float)obj_BinaryLearners[9].Mu[2];
    X[3] = Xin[3] - (float)obj_BinaryLearners[9].Mu[3];
    X[4] = Xin[4] - (float)obj_BinaryLearners[9].Mu[4];
    X[5] = Xin[5] - (float)obj_BinaryLearners[9].Mu[5];
    X[6] = Xin[6] - (float)obj_BinaryLearners[9].Mu[6];
    X[7] = Xin[7] - (float)obj_BinaryLearners[9].Mu[7];
    X[8] = Xin[8] - (float)obj_BinaryLearners[9].Mu[8];
    X[9] = Xin[9] - (float)obj_BinaryLearners[9].Mu[9];
    X[10] = Xin[10] - (float)obj_BinaryLearners[9].Mu[10];
    X[11] = Xin[11] - (float)obj_BinaryLearners[9].Mu[11];
    X[12] = Xin[12] - (float)obj_BinaryLearners[9].Mu[12];
    X[13] = Xin[13] - (float)obj_BinaryLearners[9].Mu[13];
    X[14] = Xin[14] - (float)obj_BinaryLearners[9].Mu[14];
    X[15] = Xin[15] - (float)obj_BinaryLearners[9].Mu[15];
    X[16] = Xin[16] - (float)obj_BinaryLearners[9].Mu[16];
    X[17] = Xin[17] - (float)obj_BinaryLearners[9].Mu[17];
    X[18] = Xin[18] - (float)obj_BinaryLearners[9].Mu[18];
    X[19] = Xin[19] - (float)obj_BinaryLearners[9].Mu[19];
    X[20] = Xin[20] - (float)obj_BinaryLearners[9].Mu[20];
    X[21] = Xin[21] - (float)obj_BinaryLearners[9].Mu[21];
    X[22] = Xin[22] - (float)obj_BinaryLearners[9].Mu[22];
    X[23] = Xin[23] - (float)obj_BinaryLearners[9].Mu[23];
    X[24] = Xin[24] - (float)obj_BinaryLearners[9].Mu[24];
    X[25] = Xin[25] - (float)obj_BinaryLearners[9].Mu[25];
    X[26] = Xin[26] - (float)obj_BinaryLearners[9].Mu[26];
    X[27] = Xin[27] - (float)obj_BinaryLearners[9].Mu[27];
    X[28] = Xin[28] - (float)obj_BinaryLearners[9].Mu[28];
    X[29] = Xin[29] - (float)obj_BinaryLearners[9].Mu[29];
    X[30] = Xin[30] - (float)obj_BinaryLearners[9].Mu[30];
    X[31] = Xin[31] - (float)obj_BinaryLearners[9].Mu[31];
  }
  x[0] = (obj_BinaryLearners[9].Sigma[0] == 1.0);
  x[1] = (obj_BinaryLearners[9].Sigma[1] == 1.0);
  x[2] = (obj_BinaryLearners[9].Sigma[2] == 1.0);
  x[3] = (obj_BinaryLearners[9].Sigma[3] == 1.0);
  x[4] = (obj_BinaryLearners[9].Sigma[4] == 1.0);
  x[5] = (obj_BinaryLearners[9].Sigma[5] == 1.0);
  x[6] = (obj_BinaryLearners[9].Sigma[6] == 1.0);
  x[7] = (obj_BinaryLearners[9].Sigma[7] == 1.0);
  x[8] = (obj_BinaryLearners[9].Sigma[8] == 1.0);
  x[9] = (obj_BinaryLearners[9].Sigma[9] == 1.0);
  x[10] = (obj_BinaryLearners[9].Sigma[10] == 1.0);
  x[11] = (obj_BinaryLearners[9].Sigma[11] == 1.0);
  x[12] = (obj_BinaryLearners[9].Sigma[12] == 1.0);
  x[13] = (obj_BinaryLearners[9].Sigma[13] == 1.0);
  x[14] = (obj_BinaryLearners[9].Sigma[14] == 1.0);
  x[15] = (obj_BinaryLearners[9].Sigma[15] == 1.0);
  x[16] = (obj_BinaryLearners[9].Sigma[16] == 1.0);
  x[17] = (obj_BinaryLearners[9].Sigma[17] == 1.0);
  x[18] = (obj_BinaryLearners[9].Sigma[18] == 1.0);
  x[19] = (obj_BinaryLearners[9].Sigma[19] == 1.0);
  x[20] = (obj_BinaryLearners[9].Sigma[20] == 1.0);
  x[21] = (obj_BinaryLearners[9].Sigma[21] == 1.0);
  x[22] = (obj_BinaryLearners[9].Sigma[22] == 1.0);
  x[23] = (obj_BinaryLearners[9].Sigma[23] == 1.0);
  x[24] = (obj_BinaryLearners[9].Sigma[24] == 1.0);
  x[25] = (obj_BinaryLearners[9].Sigma[25] == 1.0);
  x[26] = (obj_BinaryLearners[9].Sigma[26] == 1.0);
  x[27] = (obj_BinaryLearners[9].Sigma[27] == 1.0);
  x[28] = (obj_BinaryLearners[9].Sigma[28] == 1.0);
  x[29] = (obj_BinaryLearners[9].Sigma[29] == 1.0);
  x[30] = (obj_BinaryLearners[9].Sigma[30] == 1.0);
  x[31] = (obj_BinaryLearners[9].Sigma[31] == 1.0);
  valueisnan = true;
  // unroll
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 31)) {
//    if (!x[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }
//

  if (!x[0]) {
    valueisnan = false;
  } else if (!x[1]) {
    valueisnan = false;
  } else if (!x[2]) {
    valueisnan = false;
  } else if (!x[3]) {
    valueisnan = false;
  } else if (!x[4]) {
    valueisnan = false;
  } else if (!x[5]) {
      valueisnan = false;
  } else if (!x[6]) {
      valueisnan = false;
  } else if (!x[7]) {
      valueisnan = false;
  } else if (!x[8]) {
      valueisnan = false;
  } else if (!x[9]) {
      valueisnan = false;
  } else if (!x[10]) {
      valueisnan = false;
  } else if (!x[11]) {
      valueisnan = false;
  } else if (!x[12]) {
      valueisnan = false;
  } else if (!x[13]) {
      valueisnan = false;
  } else if (!x[14]) {
      valueisnan = false;
  } else if (!x[15]) {
      valueisnan = false;
  } else if (!x[16]) {
      valueisnan = false;
  } else if (!x[17]) {
      valueisnan = false;
  } else if (!x[18]) {
      valueisnan = false;
  } else if (!x[19]) {
      valueisnan = false;
  } else if (!x[20]) {
      valueisnan = false;
  } else if (!x[21]) {
      valueisnan = false;
  } else if (!x[22]) {
      valueisnan = false;
  } else if (!x[23]) {
      valueisnan = false;
  } else if (!x[24]) {
      valueisnan = false;
  } else if (!x[25]) {
      valueisnan = false;
  } else if (!x[26]) {
      valueisnan = false;
  } else if (!x[27]) {
      valueisnan = false;
  } else if (!x[28]) {
      valueisnan = false;
  } else if (!x[29]) {
      valueisnan = false;
  } else if (!x[30]) {
      valueisnan = false;
  } else if (!x[31]) {
    valueisnan = false;
  }
  // end unroll
  if (!valueisnan) {
    double d;
    double d1;
    double d10;
    double d11;
    double d12;
    double d13;
    double d14;
    double d15;
    double d16;
    double d17;
    double d18;
    double d19;
    double d2;
    double d20;
    double d21;
    double d22;
    double d23;
    double d24;
    double d25;
    double d26;
    double d27;
    double d28;
    double d29;
    double d3;
    double d30;
    double d31;
    double d4;
    double d5;
    double d6;
    double d7;
    double d8;
    double d9;
    float b_tmp_data[32];
    int bcoef;
    int tmp_size_9_1;
    signed char i1;
    bcoef = 0;
    d = obj_BinaryLearners[9].Sigma[0];
    if (d > 0.0) {
      bcoef = 1;
    }
    d1 = obj_BinaryLearners[9].Sigma[1];
    if (d1 > 0.0) {
      bcoef++;
    }
    d2 = obj_BinaryLearners[9].Sigma[2];
    if (d2 > 0.0) {
      bcoef++;
    }
    d3 = obj_BinaryLearners[9].Sigma[3];
    if (d3 > 0.0) {
      bcoef++;
    }
    d4 = obj_BinaryLearners[9].Sigma[4];
    if (d4 > 0.0) {
      bcoef++;
    }
    d5 = obj_BinaryLearners[9].Sigma[5];
    if (d5 > 0.0) {
      bcoef++;
    }
    d6 = obj_BinaryLearners[9].Sigma[6];
    if (d6 > 0.0) {
      bcoef++;
    }
    d7 = obj_BinaryLearners[9].Sigma[7];
    if (d7 > 0.0) {
      bcoef++;
    }
    d8 = obj_BinaryLearners[9].Sigma[8];
    if (d8 > 0.0) {
      bcoef++;
    }
    d9 = obj_BinaryLearners[9].Sigma[9];
    if (d9 > 0.0) {
      bcoef++;
    }
    d10 = obj_BinaryLearners[9].Sigma[10];
    if (d10 > 0.0) {
      bcoef++;
    }
    d11 = obj_BinaryLearners[9].Sigma[11];
    if (d11 > 0.0) {
      bcoef++;
    }
    d12 = obj_BinaryLearners[9].Sigma[12];
    if (d12 > 0.0) {
      bcoef++;
    }
    d13 = obj_BinaryLearners[9].Sigma[13];
    if (d13 > 0.0) {
      bcoef++;
    }
    d14 = obj_BinaryLearners[9].Sigma[14];
    if (d14 > 0.0) {
      bcoef++;
    }
    d15 = obj_BinaryLearners[9].Sigma[15];
    if (d15 > 0.0) {
      bcoef++;
    }
    d16 = obj_BinaryLearners[9].Sigma[16];
    if (d16 > 0.0) {
      bcoef++;
    }
    d17 = obj_BinaryLearners[9].Sigma[17];
    if (d17 > 0.0) {
      bcoef++;
    }
    d18 = obj_BinaryLearners[9].Sigma[18];
    if (d18 > 0.0) {
      bcoef++;
    }
    d19 = obj_BinaryLearners[9].Sigma[19];
    if (d19 > 0.0) {
      bcoef++;
    }
    d20 = obj_BinaryLearners[9].Sigma[20];
    if (d20 > 0.0) {
      bcoef++;
    }
    d21 = obj_BinaryLearners[9].Sigma[21];
    if (d21 > 0.0) {
      bcoef++;
    }
    d22 = obj_BinaryLearners[9].Sigma[22];
    if (d22 > 0.0) {
      bcoef++;
    }
    d23 = obj_BinaryLearners[9].Sigma[23];
    if (d23 > 0.0) {
      bcoef++;
    }
    d24 = obj_BinaryLearners[9].Sigma[24];
    if (d24 > 0.0) {
      bcoef++;
    }
    d25 = obj_BinaryLearners[9].Sigma[25];
    if (d25 > 0.0) {
      bcoef++;
    }
    d26 = obj_BinaryLearners[9].Sigma[26];
    if (d26 > 0.0) {
      bcoef++;
    }
    d27 = obj_BinaryLearners[9].Sigma[27];
    if (d27 > 0.0) {
      bcoef++;
    }
    d28 = obj_BinaryLearners[9].Sigma[28];
    if (d28 > 0.0) {
      bcoef++;
    }
    d29 = obj_BinaryLearners[9].Sigma[29];
    if (d29 > 0.0) {
      bcoef++;
    }
    d30 = obj_BinaryLearners[9].Sigma[30];
    if (d30 > 0.0) {
      bcoef++;
    }
    d31 = obj_BinaryLearners[9].Sigma[31];
    if (d31 > 0.0) {
      bcoef++;
    }
    k = 0;
    if (d > 0.0) {
      tmp_data[0] = 1;
      k = 1;
    }
    if (d1 > 0.0) {
      tmp_data[k] = 2;
      k++;
    }
    if (d2 > 0.0) {
      tmp_data[k] = 3;
      k++;
    }
    if (d3 > 0.0) {
      tmp_data[k] = 4;
      k++;
    }
    if (d4 > 0.0) {
      tmp_data[k] = 5;
      k++;
    }
    if (d5 > 0.0) {
      tmp_data[k] = 6;
      k++;
    }
    if (d6 > 0.0) {
      tmp_data[k] = 7;
      k++;
    }
    if (d7 > 0.0) {
      tmp_data[k] = 8;
      k++;
    }
    if (d8 > 0.0) {
      tmp_data[k] = 9;
      k++;
    }
    if (d9 > 0.0) {
      tmp_data[k] = 10;
      k++;
    }
    if (d10 > 0.0) {
      tmp_data[k] = 11;
      k++;
    }
    if (d11 > 0.0) {
      tmp_data[k] = 12;
      k++;
    }
    if (d12 > 0.0) {
      tmp_data[k] = 13;
      k++;
    }
    if (d13 > 0.0) {
      tmp_data[k] = 14;
      k++;
    }
    if (d14 > 0.0) {
      tmp_data[k] = 15;
      k++;
    }
    if (d15 > 0.0) {
      tmp_data[k] = 16;
      k++;
    }
    if (d16 > 0.0) {
      tmp_data[k] = 17;
      k++;
    }
    if (d17 > 0.0) {
      tmp_data[k] = 18;
      k++;
    }
    if (d18 > 0.0) {
      tmp_data[k] = 19;
      k++;
    }
    if (d19 > 0.0) {
      tmp_data[k] = 20;
      k++;
    }
    if (d20 > 0.0) {
      tmp_data[k] = 21;
      k++;
    }
    if (d21 > 0.0) {
      tmp_data[k] = 22;
      k++;
    }
    if (d22 > 0.0) {
      tmp_data[k] = 23;
      k++;
    }
    if (d23 > 0.0) {
      tmp_data[k] = 24;
      k++;
    }
    if (d24 > 0.0) {
      tmp_data[k] = 25;
      k++;
    }
    if (d25 > 0.0) {
      tmp_data[k] = 26;
      k++;
    }
    if (d26 > 0.0) {
      tmp_data[k] = 27;
      k++;
    }
    if (d27 > 0.0) {
      tmp_data[k] = 28;
      k++;
    }
    if (d28 > 0.0) {
      tmp_data[k] = 29;
      k++;
    }
    if (d29 > 0.0) {
      tmp_data[k] = 30;
      k++;
    }
    if (d30 > 0.0) {
      tmp_data[k] = 31;
      k++;
    }
    if (d31 > 0.0) {
      tmp_data[k] = 32;
    }
    if (bcoef == 1) {
      i1 = 1;
    } else if (bcoef == 1) {
      i1 = 1;
    } else {
      i1 = (signed char)bcoef;
    }
    if (bcoef == 1) {
      tmp_size_9_1 = 1;
    } else if (bcoef == 1) {
      tmp_size_9_1 = 1;
    } else {
      tmp_size_9_1 = bcoef;
    }
    if (i1 != 0) {
      int acoef;
      acoef = (bcoef != 1);
      bcoef = (bcoef != 1);
      i = i1 - 1;
      for (k = 0; k <= i; k++) {
        b_tmp_data[k] =
            X[tmp_data[acoef * k] - 1] /
            (float)obj_BinaryLearners[9].Sigma[tmp_data[bcoef * k] - 1];
      }
    }
    k = 0;
    if (obj_BinaryLearners[9].Sigma[0] > 0.0) {
      c_tmp_data[0] = 1;
      k = 1;
    }
    if (obj_BinaryLearners[9].Sigma[1] > 0.0) {
      c_tmp_data[k] = 2;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[2] > 0.0) {
      c_tmp_data[k] = 3;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[3] > 0.0) {
      c_tmp_data[k] = 4;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[4] > 0.0) {
      c_tmp_data[k] = 5;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[5] > 0.0) {
      c_tmp_data[k] = 6;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[6] > 0.0) {
      c_tmp_data[k] = 7;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[7] > 0.0) {
      c_tmp_data[k] = 8;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[8] > 0.0) {
      c_tmp_data[k] = 9;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[9] > 0.0) {
      c_tmp_data[k] = 10;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[10] > 0.0) {
      c_tmp_data[k] = 11;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[11] > 0.0) {
      c_tmp_data[k] = 12;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[12] > 0.0) {
      c_tmp_data[k] = 13;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[13] > 0.0) {
      c_tmp_data[k] = 14;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[14] > 0.0) {
      c_tmp_data[k] = 15;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[15] > 0.0) {
      c_tmp_data[k] = 16;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[16] > 0.0) {
      c_tmp_data[k] = 17;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[17] > 0.0) {
      c_tmp_data[k] = 18;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[18] > 0.0) {
      c_tmp_data[k] = 19;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[19] > 0.0) {
      c_tmp_data[k] = 20;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[20] > 0.0) {
      c_tmp_data[k] = 21;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[21] > 0.0) {
      c_tmp_data[k] = 22;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[22] > 0.0) {
      c_tmp_data[k] = 23;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[23] > 0.0) {
      c_tmp_data[k] = 24;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[24] > 0.0) {
      c_tmp_data[k] = 25;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[25] > 0.0) {
      c_tmp_data[k] = 26;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[26] > 0.0) {
      c_tmp_data[k] = 27;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[27] > 0.0) {
      c_tmp_data[k] = 28;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[28] > 0.0) {
      c_tmp_data[k] = 29;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[29] > 0.0) {
      c_tmp_data[k] = 30;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[30] > 0.0) {
      c_tmp_data[k] = 31;
      k++;
    }
    if (obj_BinaryLearners[9].Sigma[31] > 0.0) {
      c_tmp_data[k] = 32;
    }
    for (i = 0; i < tmp_size_9_1; i++) {
      X[c_tmp_data[i] - 1] = b_tmp_data[i];
    }
  }
  X_tmp = (float)obj_BinaryLearners[9].Scale;
  b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[9].Beta[0] +
                 X[1] / X_tmp * (float)obj_BinaryLearners[9].Beta[1]) +
                X[2] / X_tmp * (float)obj_BinaryLearners[9].Beta[2]) +
               X[3] / X_tmp * (float)obj_BinaryLearners[9].Beta[3]) +
              X[4] / X_tmp * (float)obj_BinaryLearners[9].Beta[4]) +
             X[5] / X_tmp * (float)obj_BinaryLearners[9].Beta[5]) +
            X[6] / X_tmp * (float)obj_BinaryLearners[9].Beta[6]) +
           X[7] / X_tmp * (float)obj_BinaryLearners[9].Beta[7]) +
          X[8] / X_tmp * (float)obj_BinaryLearners[9].Beta[8]) +
         X[9] / X_tmp * (float)obj_BinaryLearners[9].Beta[9]) +
        X[10] / X_tmp * (float)obj_BinaryLearners[9].Beta[10];
  b_X += X[11] / X_tmp * (float)obj_BinaryLearners[9].Beta[11];
  b_X += X[12] / X_tmp * (float)obj_BinaryLearners[9].Beta[12];
  b_X += X[13] / X_tmp * (float)obj_BinaryLearners[9].Beta[13];
  b_X += X[14] / X_tmp * (float)obj_BinaryLearners[9].Beta[14];
  b_X += X[15] / X_tmp * (float)obj_BinaryLearners[9].Beta[15];
  b_X += X[16] / X_tmp * (float)obj_BinaryLearners[9].Beta[16];
  b_X += X[17] / X_tmp * (float)obj_BinaryLearners[9].Beta[17];
  b_X += X[18] / X_tmp * (float)obj_BinaryLearners[9].Beta[18];
  b_X += X[19] / X_tmp * (float)obj_BinaryLearners[9].Beta[19];
  b_X += X[20] / X_tmp * (float)obj_BinaryLearners[9].Beta[20];
  b_X += X[21] / X_tmp * (float)obj_BinaryLearners[9].Beta[21];
  b_X += X[22] / X_tmp * (float)obj_BinaryLearners[9].Beta[22];
  b_X += X[23] / X_tmp * (float)obj_BinaryLearners[9].Beta[23];
  b_X += X[24] / X_tmp * (float)obj_BinaryLearners[9].Beta[24];
  b_X += X[25] / X_tmp * (float)obj_BinaryLearners[9].Beta[25];
  b_X += X[26] / X_tmp * (float)obj_BinaryLearners[9].Beta[26];
  b_X += X[27] / X_tmp * (float)obj_BinaryLearners[9].Beta[27];
  b_X += X[28] / X_tmp * (float)obj_BinaryLearners[9].Beta[28];
  b_X += X[29] / X_tmp * (float)obj_BinaryLearners[9].Beta[29];
  b_X += X[30] / X_tmp * (float)obj_BinaryLearners[9].Beta[30];
  b_X += X[31] / X_tmp * (float)obj_BinaryLearners[9].Beta[31];
  pscore[9] = b_X + (float)obj_BinaryLearners[9].Bias;

  // end loop unrool


  valueisnan = true;
  // unrool this --------------------------------------------------------
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k < 10)) {
//    if (!rtIsNaNF(pscore[k])) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }

  if (!rtIsNaNF(pscore[0])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[1])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[2])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[3])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[4])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[5])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[6])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[7])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[8])) {
    valueisnan = false;
  } else if (!rtIsNaNF(pscore[9])) {
    valueisnan = false;
  }
  // end -----------------------------------------------------------
  negloss[0] = rtNaNF;
  negloss[1] = rtNaNF;
  negloss[2] = rtNaNF;
  negloss[3] = rtNaNF;
  negloss[4] = rtNaNF;
  if (!valueisnan) {
    float maxval_idx_2;
    float maxval_idx_3;
    float maxval_idx_4;
    float maxval_idx_5;
    float maxval_idx_6;
    float maxval_idx_7;
    float maxval_idx_8;
    float maxval_idx_9;
    maxval_idx_9 = 1.0F - (float)M_idx_0 * pscore[0];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      X_tmp = maxval_idx_9;
    } else {
      X_tmp = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_5 * pscore[1];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      b_X = maxval_idx_9;
    } else {
      b_X = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_10 * pscore[2];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_2 = maxval_idx_9;
    } else {
      maxval_idx_2 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_15 * pscore[3];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_3 = maxval_idx_9;
    } else {
      maxval_idx_3 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_20 * pscore[4];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_4 = maxval_idx_9;
    } else {
      maxval_idx_4 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_25 * pscore[5];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_5 = maxval_idx_9;
    } else {
      maxval_idx_5 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_30 * pscore[6];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_6 = maxval_idx_9;
    } else {
      maxval_idx_6 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_35 * pscore[7];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_7 = maxval_idx_9;
    } else {
      maxval_idx_7 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_40 * pscore[8];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_8 = maxval_idx_9;
    } else {
      maxval_idx_8 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_45 * pscore[9];
    if ((!rtIsNaNF(maxval_idx_9)) && (!(maxval_idx_9 > 0.0F))) {
      maxval_idx_9 = 0.0F;
    }
    if (rtIsNaNF(X_tmp)) {
      X_tmp = 0.0F;
      k = 0;
    } else {
      k = 1;
    }
    if (!rtIsNaNF(b_X)) {
      X_tmp += b_X;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_2)) {
      X_tmp += maxval_idx_2;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_3)) {
      X_tmp += maxval_idx_3;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_4)) {
      X_tmp += maxval_idx_4;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_5)) {
      X_tmp += maxval_idx_5;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_6)) {
      X_tmp += maxval_idx_6;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_7)) {
      X_tmp += maxval_idx_7;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_8)) {
      X_tmp += maxval_idx_8;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_9)) {
      X_tmp += maxval_idx_9;
      k++;
    }
    negloss[0] = X_tmp / (float)k / 2.0F;
    maxval_idx_9 = 1.0F - (float)M_idx_1 * pscore[0];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      X_tmp = maxval_idx_9;
    } else {
      X_tmp = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_6 * pscore[1];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      b_X = maxval_idx_9;
    } else {
      b_X = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_11 * pscore[2];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_2 = maxval_idx_9;
    } else {
      maxval_idx_2 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_16 * pscore[3];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_3 = maxval_idx_9;
    } else {
      maxval_idx_3 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_21 * pscore[4];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_4 = maxval_idx_9;
    } else {
      maxval_idx_4 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_26 * pscore[5];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_5 = maxval_idx_9;
    } else {
      maxval_idx_5 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_31 * pscore[6];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_6 = maxval_idx_9;
    } else {
      maxval_idx_6 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_36 * pscore[7];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_7 = maxval_idx_9;
    } else {
      maxval_idx_7 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_41 * pscore[8];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_8 = maxval_idx_9;
    } else {
      maxval_idx_8 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_46 * pscore[9];
    if ((!rtIsNaNF(maxval_idx_9)) && (!(maxval_idx_9 > 0.0F))) {
      maxval_idx_9 = 0.0F;
    }
    if (rtIsNaNF(X_tmp)) {
      X_tmp = 0.0F;
      k = 0;
    } else {
      k = 1;
    }
    if (!rtIsNaNF(b_X)) {
      X_tmp += b_X;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_2)) {
      X_tmp += maxval_idx_2;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_3)) {
      X_tmp += maxval_idx_3;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_4)) {
      X_tmp += maxval_idx_4;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_5)) {
      X_tmp += maxval_idx_5;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_6)) {
      X_tmp += maxval_idx_6;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_7)) {
      X_tmp += maxval_idx_7;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_8)) {
      X_tmp += maxval_idx_8;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_9)) {
      X_tmp += maxval_idx_9;
      k++;
    }
    negloss[1] = X_tmp / (float)k / 2.0F;
    maxval_idx_9 = 1.0F - (float)M_idx_2 * pscore[0];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      X_tmp = maxval_idx_9;
    } else {
      X_tmp = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_7 * pscore[1];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      b_X = maxval_idx_9;
    } else {
      b_X = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_12 * pscore[2];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_2 = maxval_idx_9;
    } else {
      maxval_idx_2 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_17 * pscore[3];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_3 = maxval_idx_9;
    } else {
      maxval_idx_3 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_22 * pscore[4];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_4 = maxval_idx_9;
    } else {
      maxval_idx_4 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_27 * pscore[5];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_5 = maxval_idx_9;
    } else {
      maxval_idx_5 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_32 * pscore[6];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_6 = maxval_idx_9;
    } else {
      maxval_idx_6 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_37 * pscore[7];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_7 = maxval_idx_9;
    } else {
      maxval_idx_7 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_42 * pscore[8];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_8 = maxval_idx_9;
    } else {
      maxval_idx_8 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_47 * pscore[9];
    if ((!rtIsNaNF(maxval_idx_9)) && (!(maxval_idx_9 > 0.0F))) {
      maxval_idx_9 = 0.0F;
    }
    if (rtIsNaNF(X_tmp)) {
      X_tmp = 0.0F;
      k = 0;
    } else {
      k = 1;
    }
    if (!rtIsNaNF(b_X)) {
      X_tmp += b_X;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_2)) {
      X_tmp += maxval_idx_2;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_3)) {
      X_tmp += maxval_idx_3;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_4)) {
      X_tmp += maxval_idx_4;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_5)) {
      X_tmp += maxval_idx_5;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_6)) {
      X_tmp += maxval_idx_6;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_7)) {
      X_tmp += maxval_idx_7;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_8)) {
      X_tmp += maxval_idx_8;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_9)) {
      X_tmp += maxval_idx_9;
      k++;
    }
    negloss[2] = X_tmp / (float)k / 2.0F;
    maxval_idx_9 = 1.0F - (float)M_idx_3 * pscore[0];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      X_tmp = maxval_idx_9;
    } else {
      X_tmp = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_8 * pscore[1];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      b_X = maxval_idx_9;
    } else {
      b_X = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_13 * pscore[2];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_2 = maxval_idx_9;
    } else {
      maxval_idx_2 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_18 * pscore[3];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_3 = maxval_idx_9;
    } else {
      maxval_idx_3 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_23 * pscore[4];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_4 = maxval_idx_9;
    } else {
      maxval_idx_4 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_28 * pscore[5];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_5 = maxval_idx_9;
    } else {
      maxval_idx_5 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_33 * pscore[6];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_6 = maxval_idx_9;
    } else {
      maxval_idx_6 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_38 * pscore[7];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_7 = maxval_idx_9;
    } else {
      maxval_idx_7 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_43 * pscore[8];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_8 = maxval_idx_9;
    } else {
      maxval_idx_8 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_48 * pscore[9];
    if ((!rtIsNaNF(maxval_idx_9)) && (!(maxval_idx_9 > 0.0F))) {
      maxval_idx_9 = 0.0F;
    }
    if (rtIsNaNF(X_tmp)) {
      X_tmp = 0.0F;
      k = 0;
    } else {
      k = 1;
    }
    if (!rtIsNaNF(b_X)) {
      X_tmp += b_X;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_2)) {
      X_tmp += maxval_idx_2;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_3)) {
      X_tmp += maxval_idx_3;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_4)) {
      X_tmp += maxval_idx_4;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_5)) {
      X_tmp += maxval_idx_5;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_6)) {
      X_tmp += maxval_idx_6;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_7)) {
      X_tmp += maxval_idx_7;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_8)) {
      X_tmp += maxval_idx_8;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_9)) {
      X_tmp += maxval_idx_9;
      k++;
    }
    negloss[3] = X_tmp / (float)k / 2.0F;
    maxval_idx_9 = 1.0F - (float)M_idx_4 * pscore[0];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      X_tmp = maxval_idx_9;
    } else {
      X_tmp = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_9 * pscore[1];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      b_X = maxval_idx_9;
    } else {
      b_X = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_14 * pscore[2];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_2 = maxval_idx_9;
    } else {
      maxval_idx_2 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_19 * pscore[3];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_3 = maxval_idx_9;
    } else {
      maxval_idx_3 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_24 * pscore[4];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_4 = maxval_idx_9;
    } else {
      maxval_idx_4 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_29 * pscore[5];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_5 = maxval_idx_9;
    } else {
      maxval_idx_5 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_34 * pscore[6];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_6 = maxval_idx_9;
    } else {
      maxval_idx_6 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_39 * pscore[7];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_7 = maxval_idx_9;
    } else {
      maxval_idx_7 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_44 * pscore[8];
    if (rtIsNaNF(maxval_idx_9) || (maxval_idx_9 > 0.0F)) {
      maxval_idx_8 = maxval_idx_9;
    } else {
      maxval_idx_8 = 0.0F;
    }
    maxval_idx_9 = 1.0F - (float)M_idx_49 * pscore[9];
    if ((!rtIsNaNF(maxval_idx_9)) && (!(maxval_idx_9 > 0.0F))) {
      maxval_idx_9 = 0.0F;
    }
    if (rtIsNaNF(X_tmp)) {
      X_tmp = 0.0F;
      k = 0;
    } else {
      k = 1;
    }
    if (!rtIsNaNF(b_X)) {
      X_tmp += b_X;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_2)) {
      X_tmp += maxval_idx_2;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_3)) {
      X_tmp += maxval_idx_3;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_4)) {
      X_tmp += maxval_idx_4;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_5)) {
      X_tmp += maxval_idx_5;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_6)) {
      X_tmp += maxval_idx_6;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_7)) {
      X_tmp += maxval_idx_7;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_8)) {
      X_tmp += maxval_idx_8;
      k++;
    }
    if (!rtIsNaNF(maxval_idx_9)) {
      X_tmp += maxval_idx_9;
      k++;
    }
    negloss[4] = X_tmp / (float)k / 2.0F;
  }
  X_tmp = -negloss[0];
  negloss[0] = -negloss[0];
  b[0] = rtIsNaNF(X_tmp);
  X_tmp = -negloss[1];
  negloss[1] = -negloss[1];
  b[1] = rtIsNaNF(X_tmp);
  X_tmp = -negloss[2];
  negloss[2] = -negloss[2];
  b[2] = rtIsNaNF(X_tmp);
  X_tmp = -negloss[3];
  negloss[3] = -negloss[3];
  b[3] = rtIsNaNF(X_tmp);
  X_tmp = -negloss[4];
  negloss[4] = -negloss[4];
  b[4] = rtIsNaNF(X_tmp);
  valueisnan = true;

  // unrool ----------------------------------------------
//  k = 0;
//  exitg1 = false;
//  while ((!exitg1) && (k <= 4)) {
//    if (!b[k]) {
//      valueisnan = false;
//      exitg1 = true;
//    } else {
//      k++;
//    }
//  }

  if (!b[0]) {
    valueisnan = false;
  } else if (!b[1]) {
    valueisnan = false;
  } else if (!b[2]) {
    valueisnan = false;
  } else if (!b[3]) {
    valueisnan = false;
  } else if (!b[4]) {
    valueisnan = false;
  }

  // end unrool -------------------------------------------

  M_idx_0 = obj_Prior[0];
  k = -1;
  if (obj_Prior[0] < obj_Prior[1]) {
    M_idx_0 = obj_Prior[1];
    k = 0;
  }
  if (M_idx_0 < obj_Prior[2]) {
    M_idx_0 = obj_Prior[2];
    k = 1;
  }
  if (M_idx_0 < obj_Prior[3]) {
    M_idx_0 = obj_Prior[3];
    k = 2;
  }
  if (M_idx_0 < obj_Prior[4]) {
    k = 3;
  }
  labels = (double)k + 2.0;
  if (!valueisnan) {
    if (!rtIsNaNF(negloss[0])) {
      idx = 1;
    } else {
    	idx = 0;

    	if (!rtIsNaNF(negloss[1])) {
    	  idx = 2;
    	} else if (!rtIsNaNF(negloss[2])) {
    	  idx = 3;
    	} else if (!rtIsNaNF(negloss[3])) {
    	  idx = 4;
    	} else if (!rtIsNaNF(negloss[4])) {
    	  idx = 5;
    	}
    }
    if (idx == 0) {
      idx = 1;
    } else {
      b_X = negloss[idx - 1];
      i = idx + 1;
      for (k = i; k < 6; k++) {
        X_tmp = negloss[k - 1];
        if (b_X < X_tmp) {
          b_X = X_tmp;
          idx = k;
        }
      }
    }
    labels = idx;
  }
  return labels;
}

/*
 * File trailer for CompactClassificationECOC.c
 *
 * [EOF]
 */

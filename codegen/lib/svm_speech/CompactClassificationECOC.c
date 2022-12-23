/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationECOC.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 24-Dec-2022 00:40:56
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
  for (idx = 0; idx < 10; idx++) {
    float X[32];
    bool x[32];
    X[0] = Xin[0];
    x[0] = (obj_BinaryLearners[idx].Mu[0] == 0.0);
    X[1] = Xin[1];
    x[1] = (obj_BinaryLearners[idx].Mu[1] == 0.0);
    X[2] = Xin[2];
    x[2] = (obj_BinaryLearners[idx].Mu[2] == 0.0);
    X[3] = Xin[3];
    x[3] = (obj_BinaryLearners[idx].Mu[3] == 0.0);
    X[4] = Xin[4];
    x[4] = (obj_BinaryLearners[idx].Mu[4] == 0.0);
    X[5] = Xin[5];
    x[5] = (obj_BinaryLearners[idx].Mu[5] == 0.0);
    X[6] = Xin[6];
    x[6] = (obj_BinaryLearners[idx].Mu[6] == 0.0);
    X[7] = Xin[7];
    x[7] = (obj_BinaryLearners[idx].Mu[7] == 0.0);
    X[8] = Xin[8];
    x[8] = (obj_BinaryLearners[idx].Mu[8] == 0.0);
    X[9] = Xin[9];
    x[9] = (obj_BinaryLearners[idx].Mu[9] == 0.0);
    X[10] = Xin[10];
    x[10] = (obj_BinaryLearners[idx].Mu[10] == 0.0);
    X[11] = Xin[11];
    x[11] = (obj_BinaryLearners[idx].Mu[11] == 0.0);
    X[12] = Xin[12];
    x[12] = (obj_BinaryLearners[idx].Mu[12] == 0.0);
    X[13] = Xin[13];
    x[13] = (obj_BinaryLearners[idx].Mu[13] == 0.0);
    X[14] = Xin[14];
    x[14] = (obj_BinaryLearners[idx].Mu[14] == 0.0);
    X[15] = Xin[15];
    x[15] = (obj_BinaryLearners[idx].Mu[15] == 0.0);
    X[16] = Xin[16];
    x[16] = (obj_BinaryLearners[idx].Mu[16] == 0.0);
    X[17] = Xin[17];
    x[17] = (obj_BinaryLearners[idx].Mu[17] == 0.0);
    X[18] = Xin[18];
    x[18] = (obj_BinaryLearners[idx].Mu[18] == 0.0);
    X[19] = Xin[19];
    x[19] = (obj_BinaryLearners[idx].Mu[19] == 0.0);
    X[20] = Xin[20];
    x[20] = (obj_BinaryLearners[idx].Mu[20] == 0.0);
    X[21] = Xin[21];
    x[21] = (obj_BinaryLearners[idx].Mu[21] == 0.0);
    X[22] = Xin[22];
    x[22] = (obj_BinaryLearners[idx].Mu[22] == 0.0);
    X[23] = Xin[23];
    x[23] = (obj_BinaryLearners[idx].Mu[23] == 0.0);
    X[24] = Xin[24];
    x[24] = (obj_BinaryLearners[idx].Mu[24] == 0.0);
    X[25] = Xin[25];
    x[25] = (obj_BinaryLearners[idx].Mu[25] == 0.0);
    X[26] = Xin[26];
    x[26] = (obj_BinaryLearners[idx].Mu[26] == 0.0);
    X[27] = Xin[27];
    x[27] = (obj_BinaryLearners[idx].Mu[27] == 0.0);
    X[28] = Xin[28];
    x[28] = (obj_BinaryLearners[idx].Mu[28] == 0.0);
    X[29] = Xin[29];
    x[29] = (obj_BinaryLearners[idx].Mu[29] == 0.0);
    X[30] = Xin[30];
    x[30] = (obj_BinaryLearners[idx].Mu[30] == 0.0);
    X[31] = Xin[31];
    x[31] = (obj_BinaryLearners[idx].Mu[31] == 0.0);
    valueisnan = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 31)) {
      if (!x[k]) {
        valueisnan = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!valueisnan) {
      X[0] = Xin[0] - (float)obj_BinaryLearners[idx].Mu[0];
      X[1] = Xin[1] - (float)obj_BinaryLearners[idx].Mu[1];
      X[2] = Xin[2] - (float)obj_BinaryLearners[idx].Mu[2];
      X[3] = Xin[3] - (float)obj_BinaryLearners[idx].Mu[3];
      X[4] = Xin[4] - (float)obj_BinaryLearners[idx].Mu[4];
      X[5] = Xin[5] - (float)obj_BinaryLearners[idx].Mu[5];
      X[6] = Xin[6] - (float)obj_BinaryLearners[idx].Mu[6];
      X[7] = Xin[7] - (float)obj_BinaryLearners[idx].Mu[7];
      X[8] = Xin[8] - (float)obj_BinaryLearners[idx].Mu[8];
      X[9] = Xin[9] - (float)obj_BinaryLearners[idx].Mu[9];
      X[10] = Xin[10] - (float)obj_BinaryLearners[idx].Mu[10];
      X[11] = Xin[11] - (float)obj_BinaryLearners[idx].Mu[11];
      X[12] = Xin[12] - (float)obj_BinaryLearners[idx].Mu[12];
      X[13] = Xin[13] - (float)obj_BinaryLearners[idx].Mu[13];
      X[14] = Xin[14] - (float)obj_BinaryLearners[idx].Mu[14];
      X[15] = Xin[15] - (float)obj_BinaryLearners[idx].Mu[15];
      X[16] = Xin[16] - (float)obj_BinaryLearners[idx].Mu[16];
      X[17] = Xin[17] - (float)obj_BinaryLearners[idx].Mu[17];
      X[18] = Xin[18] - (float)obj_BinaryLearners[idx].Mu[18];
      X[19] = Xin[19] - (float)obj_BinaryLearners[idx].Mu[19];
      X[20] = Xin[20] - (float)obj_BinaryLearners[idx].Mu[20];
      X[21] = Xin[21] - (float)obj_BinaryLearners[idx].Mu[21];
      X[22] = Xin[22] - (float)obj_BinaryLearners[idx].Mu[22];
      X[23] = Xin[23] - (float)obj_BinaryLearners[idx].Mu[23];
      X[24] = Xin[24] - (float)obj_BinaryLearners[idx].Mu[24];
      X[25] = Xin[25] - (float)obj_BinaryLearners[idx].Mu[25];
      X[26] = Xin[26] - (float)obj_BinaryLearners[idx].Mu[26];
      X[27] = Xin[27] - (float)obj_BinaryLearners[idx].Mu[27];
      X[28] = Xin[28] - (float)obj_BinaryLearners[idx].Mu[28];
      X[29] = Xin[29] - (float)obj_BinaryLearners[idx].Mu[29];
      X[30] = Xin[30] - (float)obj_BinaryLearners[idx].Mu[30];
      X[31] = Xin[31] - (float)obj_BinaryLearners[idx].Mu[31];
    }
    x[0] = (obj_BinaryLearners[idx].Sigma[0] == 1.0);
    x[1] = (obj_BinaryLearners[idx].Sigma[1] == 1.0);
    x[2] = (obj_BinaryLearners[idx].Sigma[2] == 1.0);
    x[3] = (obj_BinaryLearners[idx].Sigma[3] == 1.0);
    x[4] = (obj_BinaryLearners[idx].Sigma[4] == 1.0);
    x[5] = (obj_BinaryLearners[idx].Sigma[5] == 1.0);
    x[6] = (obj_BinaryLearners[idx].Sigma[6] == 1.0);
    x[7] = (obj_BinaryLearners[idx].Sigma[7] == 1.0);
    x[8] = (obj_BinaryLearners[idx].Sigma[8] == 1.0);
    x[9] = (obj_BinaryLearners[idx].Sigma[9] == 1.0);
    x[10] = (obj_BinaryLearners[idx].Sigma[10] == 1.0);
    x[11] = (obj_BinaryLearners[idx].Sigma[11] == 1.0);
    x[12] = (obj_BinaryLearners[idx].Sigma[12] == 1.0);
    x[13] = (obj_BinaryLearners[idx].Sigma[13] == 1.0);
    x[14] = (obj_BinaryLearners[idx].Sigma[14] == 1.0);
    x[15] = (obj_BinaryLearners[idx].Sigma[15] == 1.0);
    x[16] = (obj_BinaryLearners[idx].Sigma[16] == 1.0);
    x[17] = (obj_BinaryLearners[idx].Sigma[17] == 1.0);
    x[18] = (obj_BinaryLearners[idx].Sigma[18] == 1.0);
    x[19] = (obj_BinaryLearners[idx].Sigma[19] == 1.0);
    x[20] = (obj_BinaryLearners[idx].Sigma[20] == 1.0);
    x[21] = (obj_BinaryLearners[idx].Sigma[21] == 1.0);
    x[22] = (obj_BinaryLearners[idx].Sigma[22] == 1.0);
    x[23] = (obj_BinaryLearners[idx].Sigma[23] == 1.0);
    x[24] = (obj_BinaryLearners[idx].Sigma[24] == 1.0);
    x[25] = (obj_BinaryLearners[idx].Sigma[25] == 1.0);
    x[26] = (obj_BinaryLearners[idx].Sigma[26] == 1.0);
    x[27] = (obj_BinaryLearners[idx].Sigma[27] == 1.0);
    x[28] = (obj_BinaryLearners[idx].Sigma[28] == 1.0);
    x[29] = (obj_BinaryLearners[idx].Sigma[29] == 1.0);
    x[30] = (obj_BinaryLearners[idx].Sigma[30] == 1.0);
    x[31] = (obj_BinaryLearners[idx].Sigma[31] == 1.0);
    valueisnan = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 31)) {
      if (!x[k]) {
        valueisnan = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
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
      int tmp_size_idx_1;
      signed char i1;
      bcoef = 0;
      d = obj_BinaryLearners[idx].Sigma[0];
      if (d > 0.0) {
        bcoef = 1;
      }
      d1 = obj_BinaryLearners[idx].Sigma[1];
      if (d1 > 0.0) {
        bcoef++;
      }
      d2 = obj_BinaryLearners[idx].Sigma[2];
      if (d2 > 0.0) {
        bcoef++;
      }
      d3 = obj_BinaryLearners[idx].Sigma[3];
      if (d3 > 0.0) {
        bcoef++;
      }
      d4 = obj_BinaryLearners[idx].Sigma[4];
      if (d4 > 0.0) {
        bcoef++;
      }
      d5 = obj_BinaryLearners[idx].Sigma[5];
      if (d5 > 0.0) {
        bcoef++;
      }
      d6 = obj_BinaryLearners[idx].Sigma[6];
      if (d6 > 0.0) {
        bcoef++;
      }
      d7 = obj_BinaryLearners[idx].Sigma[7];
      if (d7 > 0.0) {
        bcoef++;
      }
      d8 = obj_BinaryLearners[idx].Sigma[8];
      if (d8 > 0.0) {
        bcoef++;
      }
      d9 = obj_BinaryLearners[idx].Sigma[9];
      if (d9 > 0.0) {
        bcoef++;
      }
      d10 = obj_BinaryLearners[idx].Sigma[10];
      if (d10 > 0.0) {
        bcoef++;
      }
      d11 = obj_BinaryLearners[idx].Sigma[11];
      if (d11 > 0.0) {
        bcoef++;
      }
      d12 = obj_BinaryLearners[idx].Sigma[12];
      if (d12 > 0.0) {
        bcoef++;
      }
      d13 = obj_BinaryLearners[idx].Sigma[13];
      if (d13 > 0.0) {
        bcoef++;
      }
      d14 = obj_BinaryLearners[idx].Sigma[14];
      if (d14 > 0.0) {
        bcoef++;
      }
      d15 = obj_BinaryLearners[idx].Sigma[15];
      if (d15 > 0.0) {
        bcoef++;
      }
      d16 = obj_BinaryLearners[idx].Sigma[16];
      if (d16 > 0.0) {
        bcoef++;
      }
      d17 = obj_BinaryLearners[idx].Sigma[17];
      if (d17 > 0.0) {
        bcoef++;
      }
      d18 = obj_BinaryLearners[idx].Sigma[18];
      if (d18 > 0.0) {
        bcoef++;
      }
      d19 = obj_BinaryLearners[idx].Sigma[19];
      if (d19 > 0.0) {
        bcoef++;
      }
      d20 = obj_BinaryLearners[idx].Sigma[20];
      if (d20 > 0.0) {
        bcoef++;
      }
      d21 = obj_BinaryLearners[idx].Sigma[21];
      if (d21 > 0.0) {
        bcoef++;
      }
      d22 = obj_BinaryLearners[idx].Sigma[22];
      if (d22 > 0.0) {
        bcoef++;
      }
      d23 = obj_BinaryLearners[idx].Sigma[23];
      if (d23 > 0.0) {
        bcoef++;
      }
      d24 = obj_BinaryLearners[idx].Sigma[24];
      if (d24 > 0.0) {
        bcoef++;
      }
      d25 = obj_BinaryLearners[idx].Sigma[25];
      if (d25 > 0.0) {
        bcoef++;
      }
      d26 = obj_BinaryLearners[idx].Sigma[26];
      if (d26 > 0.0) {
        bcoef++;
      }
      d27 = obj_BinaryLearners[idx].Sigma[27];
      if (d27 > 0.0) {
        bcoef++;
      }
      d28 = obj_BinaryLearners[idx].Sigma[28];
      if (d28 > 0.0) {
        bcoef++;
      }
      d29 = obj_BinaryLearners[idx].Sigma[29];
      if (d29 > 0.0) {
        bcoef++;
      }
      d30 = obj_BinaryLearners[idx].Sigma[30];
      if (d30 > 0.0) {
        bcoef++;
      }
      d31 = obj_BinaryLearners[idx].Sigma[31];
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
        tmp_size_idx_1 = 1;
      } else if (bcoef == 1) {
        tmp_size_idx_1 = 1;
      } else {
        tmp_size_idx_1 = bcoef;
      }
      if (i1 != 0) {
        int acoef;
        acoef = (bcoef != 1);
        bcoef = (bcoef != 1);
        i = i1 - 1;
        for (k = 0; k <= i; k++) {
          b_tmp_data[k] =
              X[tmp_data[acoef * k] - 1] /
              (float)obj_BinaryLearners[idx].Sigma[tmp_data[bcoef * k] - 1];
        }
      }
      k = 0;
      if (obj_BinaryLearners[idx].Sigma[0] > 0.0) {
        c_tmp_data[0] = 1;
        k = 1;
      }
      if (obj_BinaryLearners[idx].Sigma[1] > 0.0) {
        c_tmp_data[k] = 2;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[2] > 0.0) {
        c_tmp_data[k] = 3;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[3] > 0.0) {
        c_tmp_data[k] = 4;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[4] > 0.0) {
        c_tmp_data[k] = 5;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[5] > 0.0) {
        c_tmp_data[k] = 6;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[6] > 0.0) {
        c_tmp_data[k] = 7;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[7] > 0.0) {
        c_tmp_data[k] = 8;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[8] > 0.0) {
        c_tmp_data[k] = 9;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[9] > 0.0) {
        c_tmp_data[k] = 10;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[10] > 0.0) {
        c_tmp_data[k] = 11;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[11] > 0.0) {
        c_tmp_data[k] = 12;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[12] > 0.0) {
        c_tmp_data[k] = 13;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[13] > 0.0) {
        c_tmp_data[k] = 14;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[14] > 0.0) {
        c_tmp_data[k] = 15;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[15] > 0.0) {
        c_tmp_data[k] = 16;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[16] > 0.0) {
        c_tmp_data[k] = 17;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[17] > 0.0) {
        c_tmp_data[k] = 18;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[18] > 0.0) {
        c_tmp_data[k] = 19;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[19] > 0.0) {
        c_tmp_data[k] = 20;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[20] > 0.0) {
        c_tmp_data[k] = 21;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[21] > 0.0) {
        c_tmp_data[k] = 22;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[22] > 0.0) {
        c_tmp_data[k] = 23;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[23] > 0.0) {
        c_tmp_data[k] = 24;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[24] > 0.0) {
        c_tmp_data[k] = 25;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[25] > 0.0) {
        c_tmp_data[k] = 26;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[26] > 0.0) {
        c_tmp_data[k] = 27;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[27] > 0.0) {
        c_tmp_data[k] = 28;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[28] > 0.0) {
        c_tmp_data[k] = 29;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[29] > 0.0) {
        c_tmp_data[k] = 30;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[30] > 0.0) {
        c_tmp_data[k] = 31;
        k++;
      }
      if (obj_BinaryLearners[idx].Sigma[31] > 0.0) {
        c_tmp_data[k] = 32;
      }
      for (i = 0; i < tmp_size_idx_1; i++) {
        X[c_tmp_data[i] - 1] = b_tmp_data[i];
      }
    }
    X_tmp = (float)obj_BinaryLearners[idx].Scale;
    b_X = (((((((((X[0] / X_tmp * (float)obj_BinaryLearners[idx].Beta[0] +
                   X[1] / X_tmp * (float)obj_BinaryLearners[idx].Beta[1]) +
                  X[2] / X_tmp * (float)obj_BinaryLearners[idx].Beta[2]) +
                 X[3] / X_tmp * (float)obj_BinaryLearners[idx].Beta[3]) +
                X[4] / X_tmp * (float)obj_BinaryLearners[idx].Beta[4]) +
               X[5] / X_tmp * (float)obj_BinaryLearners[idx].Beta[5]) +
              X[6] / X_tmp * (float)obj_BinaryLearners[idx].Beta[6]) +
             X[7] / X_tmp * (float)obj_BinaryLearners[idx].Beta[7]) +
            X[8] / X_tmp * (float)obj_BinaryLearners[idx].Beta[8]) +
           X[9] / X_tmp * (float)obj_BinaryLearners[idx].Beta[9]) +
          X[10] / X_tmp * (float)obj_BinaryLearners[idx].Beta[10];
    b_X += X[11] / X_tmp * (float)obj_BinaryLearners[idx].Beta[11];
    b_X += X[12] / X_tmp * (float)obj_BinaryLearners[idx].Beta[12];
    b_X += X[13] / X_tmp * (float)obj_BinaryLearners[idx].Beta[13];
    b_X += X[14] / X_tmp * (float)obj_BinaryLearners[idx].Beta[14];
    b_X += X[15] / X_tmp * (float)obj_BinaryLearners[idx].Beta[15];
    b_X += X[16] / X_tmp * (float)obj_BinaryLearners[idx].Beta[16];
    b_X += X[17] / X_tmp * (float)obj_BinaryLearners[idx].Beta[17];
    b_X += X[18] / X_tmp * (float)obj_BinaryLearners[idx].Beta[18];
    b_X += X[19] / X_tmp * (float)obj_BinaryLearners[idx].Beta[19];
    b_X += X[20] / X_tmp * (float)obj_BinaryLearners[idx].Beta[20];
    b_X += X[21] / X_tmp * (float)obj_BinaryLearners[idx].Beta[21];
    b_X += X[22] / X_tmp * (float)obj_BinaryLearners[idx].Beta[22];
    b_X += X[23] / X_tmp * (float)obj_BinaryLearners[idx].Beta[23];
    b_X += X[24] / X_tmp * (float)obj_BinaryLearners[idx].Beta[24];
    b_X += X[25] / X_tmp * (float)obj_BinaryLearners[idx].Beta[25];
    b_X += X[26] / X_tmp * (float)obj_BinaryLearners[idx].Beta[26];
    b_X += X[27] / X_tmp * (float)obj_BinaryLearners[idx].Beta[27];
    b_X += X[28] / X_tmp * (float)obj_BinaryLearners[idx].Beta[28];
    b_X += X[29] / X_tmp * (float)obj_BinaryLearners[idx].Beta[29];
    b_X += X[30] / X_tmp * (float)obj_BinaryLearners[idx].Beta[30];
    b_X += X[31] / X_tmp * (float)obj_BinaryLearners[idx].Beta[31];
    pscore[idx] = b_X + (float)obj_BinaryLearners[idx].Bias;
  }
  valueisnan = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 10)) {
    if (!rtIsNaNF(pscore[k])) {
      valueisnan = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
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
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 4)) {
    if (!b[k]) {
      valueisnan = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
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
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 6)) {
        if (!rtIsNaNF(negloss[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
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

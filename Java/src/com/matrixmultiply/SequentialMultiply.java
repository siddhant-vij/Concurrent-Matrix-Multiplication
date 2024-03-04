package com.matrixmultiply;

public class SequentialMultiply {
  public static void multiply(int[][] matrix1, int[][] matrix2) {
    int[][] result = new int[matrix1.length][matrix2[0].length];

    for (int i = 0; i < matrix1.length; i++) {
      for (int j = 0; j < matrix2[0].length; j++) {
        result[i][j] = 0;
        for (int k = 0; k < matrix2.length; k++) {
          result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
      }
    }
  }
}

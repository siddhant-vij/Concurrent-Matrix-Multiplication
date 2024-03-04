package com.matrixmultiply;

public class TimeComparison {
  public static void timeComparison(int[][] matrix1, int[][] matrix2) {
    long startTime = System.currentTimeMillis();
    SequentialMultiply.multiply(matrix1, matrix2);
    long endTime = System.currentTimeMillis();
    System.out.println("Sequential time: " + (endTime - startTime) + "ms");

    startTime = System.currentTimeMillis();
    ConcurrentMultiply.multiply(matrix1, matrix2);
    endTime = System.currentTimeMillis();
    System.out.println("Concurrent time: " + (endTime - startTime) + "ms");
  }
}

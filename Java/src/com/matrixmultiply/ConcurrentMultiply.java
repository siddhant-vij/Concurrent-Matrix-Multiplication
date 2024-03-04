package com.matrixmultiply;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class ConcurrentMultiply {
  public static void multiply(int[][] matrix1, int[][] matrix2) {
    int[][] result = new int[matrix1.length][matrix2[0].length];
    ExecutorService executor = Executors.newVirtualThreadPerTaskExecutor();

    for (int i = 0; i < matrix1.length; i++) {
      for (int j = 0; j < matrix2[0].length; j++) {
        int row = i;
        int col = j;
        executor.execute(() -> {
          for (int k = 0; k < matrix1[0].length; k++) {
            result[row][col] += matrix1[row][k] * matrix2[k][col];
          }
        });
      }
    }
    executor.shutdown();
    try {
      executor.awaitTermination(Long.MAX_VALUE, TimeUnit.MILLISECONDS);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }
}

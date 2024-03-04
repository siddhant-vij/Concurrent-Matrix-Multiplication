package com.matrixmultiply;

import java.io.FileWriter;
import java.io.IOException;

public class CreateMatrices {
  static String fileName = "src/com/matrixmultiply/Input.txt";
  static int count = 0;

  private static int[][] createRandomMatrix(int rows, int columns) {
    int[][] matrix = new int[rows][columns];
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        matrix[i][j] = (int) (Math.random() * 1000);
      }
    }
    return matrix;
  }

  private static void addMatrixToTextFile(int[][] matrix) {
    count++;
    try {
      FileWriter fileWriter = new FileWriter(fileName, true);
      for (int i = 0; i < matrix.length; i++) {
        for (int j = 0; j < matrix[i].length; j++) {
          fileWriter.write(matrix[i][j] + " ");
        }
        fileWriter.write("\n");
      }
      if (count == 1) {
        fileWriter.write("\n");
      }
      fileWriter.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    System.out.println("Matrix Multiplication: M1 (m*n) X M2 (n*p) = M3 (m*p)");

    System.out.print("Enter the number m: ");
    int m = Integer.parseInt(System.console().readLine());
    System.out.print("Enter the number n: ");
    int n = Integer.parseInt(System.console().readLine());
    System.out.print("Enter the number p: ");
    int p = Integer.parseInt(System.console().readLine());

    int[][] matrix1 = createRandomMatrix(m, n);
    addMatrixToTextFile(matrix1);
    int[][] matrix2 = createRandomMatrix(n, p);
    addMatrixToTextFile(matrix2);
  }
}

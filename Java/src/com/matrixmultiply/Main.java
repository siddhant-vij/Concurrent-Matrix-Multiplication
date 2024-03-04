package com.matrixmultiply;

import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {
  static int[][] matrix1;
  static int[][] matrix2;
  static int[] dim;
  static String fileName = "src/com/matrixmultiply/Input.txt";

  private static void getMatrixDimensions() {
    try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
      dim = new int[3];
      String line = null;
      int count = 0;
      boolean matrix1Reading = true;
      while ((line = br.readLine()) != null) {
        String[] row = line.split(" ");
        if (matrix1Reading) {
          if (dim[1] == 0) {
            dim[1] = row.length;
          }
          dim[0]++;
          if (row.length == 1) {
            matrix1Reading = false;
            dim[0]--;
          }
        } else {
          if (dim[2] == 0) {
            dim[2] = row.length;
          }
          count++;
        }
      }
      if (dim[0] == 0) {
        throw new IOException(
            "This is a matrix multiplication - not a scalar. Need more elements in matrix form for the first matrix.");
      }
      if (count != dim[1]) {
        throw new IOException(
            "The number of rows in the second matrix does not match the number of columns in the first matrix. Multiplication is not possible.");
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static void getMatricesFromTextFile() {
    getMatrixDimensions();
    matrix1 = new int[dim[0]][dim[1]];
    matrix2 = new int[dim[1]][dim[2]];

    try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
      String line = null;
      int count = 0;
      boolean matrix1Reading = true;
      while ((line = br.readLine()) != null) {
        String[] row = line.split(" ");
        if (matrix1Reading) {
          if (count != dim[0]) {
            for (int i = 0; i < row.length; i++) {
              matrix1[count][i] = Integer.parseInt(row[i]);
            }
          }
          count++;
          if (row.length == 1) {
            matrix1Reading = false;
            count = 0;
          }
        } else {
          for (int i = 0; i < row.length; i++) {
            matrix2[count][i] = Integer.parseInt(row[i]);
          }
          count++;
        }
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    getMatricesFromTextFile();
    TimeComparison.timeComparison(matrix1, matrix2);
    // M1: 2500 * 2500
    // M2: 2500 * 2500
    // Sequential time: 163481ms
    // Concurrent time: 36547ms
  }
}

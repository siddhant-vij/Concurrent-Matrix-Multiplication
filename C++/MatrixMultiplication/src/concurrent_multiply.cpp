#include "concurrent_multiply.hpp"
#include <future>
#include <vector>

// Worker function that performs multiplication for a slice of rows.
std::vector<std::vector<int>> multiplySlice(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2, size_t startRow, size_t endRow)
{
  size_t cols = matrix2[0].size();
  size_t inner = matrix2.size();
  std::vector<std::vector<int>> resultSlice(endRow - startRow, std::vector<int>(cols, 0));

  for (size_t i = startRow; i < endRow; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      for (size_t k = 0; k < inner; ++k)
      {
        resultSlice[i - startRow][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return resultSlice;
}

std::vector<std::vector<int>> ConcurrentMultiply::multiply(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2)
{
  size_t rows = matrix1.size();
  size_t cols = matrix2[0].size();
  std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

  size_t numThreads = std::thread::hardware_concurrency();
  std::vector<std::future<std::vector<std::vector<int>>>> futures;

  size_t rowsPerThread = rows / numThreads;
  size_t startRow = 0;

  for (size_t i = 0; i < numThreads; ++i)
  {
    size_t endRow = (i == numThreads - 1) ? rows : startRow + rowsPerThread;
    futures.push_back(std::async(std::launch::async, multiplySlice, std::cref(matrix1), std::cref(matrix2), startRow, endRow));
    startRow = endRow;
  }

  // Combine the results from each slice into the final result matrix.
  for (size_t i = 0, startRow = 0; i < futures.size(); ++i)
  {
    auto slice = futures[i].get();
    for (size_t j = 0; j < slice.size(); ++j, ++startRow)
    {
      result[startRow] = std::move(slice[j]);
    }
  }

  return result;
}

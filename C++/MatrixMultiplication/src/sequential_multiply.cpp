#include "sequential_multiply.hpp"

std::vector<std::vector<int>> SequentialMultiply::multiply(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2)
{
  size_t rows = matrix1.size();
  size_t cols = matrix2[0].size();
  size_t inner = matrix2.size();
  std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      for (size_t k = 0; k < inner; ++k)
      {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return result;
}

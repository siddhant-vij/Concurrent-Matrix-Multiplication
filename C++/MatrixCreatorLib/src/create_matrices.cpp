#include "create_matrices.hpp"
#include <fstream>
#include <random>
#include <stdexcept>

namespace MatrixCreatorLib
{

  int CreateMatrices::count = 0;

  void CreateMatrices::initializeFile()
  {
    std::ofstream out(INPUT_FILE_PATH, std::ios::trunc);
    if (!out.is_open())
    {
      throw std::runtime_error("Unable to initialize the file.");
    }
    out.close();
    count = 0; // Reset count whenever file is initialized
  }

  std::vector<std::vector<int>> CreateMatrices::createRandomMatrix(int rows, int columns)
  {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 999);

    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < columns; ++j)
        matrix[i][j] = distrib(gen);

    return matrix;
  }

  void CreateMatrices::addMatrixToTextFile(const std::vector<std::vector<int>> &matrix)
  {
    std::ofstream out(INPUT_FILE_PATH, std::ios::app);
    if (!out.is_open())
      throw std::runtime_error("Unable to open the file for appending.");

    for (const auto &row : matrix)
    {
      for (const auto &val : row)
        out << val << ' ';
      out << '\n';
    }

    if (count++ == 0)
      out << "\n";
    out.close();
  }

  void CreateMatrices::createAndAddRandomMatrix(int rows, int columns)
  {
    auto matrix = createRandomMatrix(rows, columns);
    addMatrixToTextFile(matrix);
  }

} // namespace MatrixCreatorLib

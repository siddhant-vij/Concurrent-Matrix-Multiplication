#include "matrix_reader.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> MatrixReader::getMatricesFromFile()
{
  std::ifstream file(INPUT_FILE_PATH);
  if (!file.is_open())
  {
    throw std::runtime_error("Could not open the file.");
  }

  std::vector<std::vector<int>> matrix1, matrix2;
  std::vector<std::vector<int>> *currentMatrix = &matrix1;
  std::string line;
  while (std::getline(file, line))
  {
    if (line.empty())
    {
      currentMatrix = &matrix2; // Switch to reading the second matrix
      continue;
    }
    std::istringstream lineStream(line);
    std::vector<int> row;
    int value;
    while (lineStream >> value)
    {
      row.push_back(value);
    }
    currentMatrix->push_back(row);
  }

  if (matrix1.empty() || matrix2.empty())
  {
    throw std::runtime_error("One or both matrices are missing in the file.");
  }

  return {matrix1, matrix2};
}

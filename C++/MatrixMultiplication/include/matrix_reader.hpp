#ifndef MATRIX_READER_HPP
#define MATRIX_READER_HPP

#include <vector>
#include <string>

class MatrixReader
{
public:
  static std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> getMatricesFromFile();
};

#endif // MATRIX_READER_HPP

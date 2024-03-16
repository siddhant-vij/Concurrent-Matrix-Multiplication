#ifndef CREATE_MATRICES_HPP
#define CREATE_MATRICES_HPP

#include <string>
#include <vector>

namespace MatrixCreatorLib
{

  class CreateMatrices
  {
  public:
    static void initializeFile();
    static void createAndAddRandomMatrix(int rows, int columns);

  private:
    static std::vector<std::vector<int>> createRandomMatrix(int rows, int columns);
    static void addMatrixToTextFile(const std::vector<std::vector<int>> &matrix);
    static std::string fileName;
    static int count;
  };

} // namespace MatrixCreatorLib

#endif // CREATE_MATRICES_HPP

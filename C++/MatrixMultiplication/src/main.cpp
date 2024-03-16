#include "create_matrices.hpp"
#include <matrix_reader.hpp>
#include "time_comparison.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  if (!(argc > 1 && std::string(argv[1]) == "--m"))
  {
    std::cout << "Matrix Multiplication: M1 (m*n) X M2 (n*p) = M3 (m*p)\n";

    int m, n, p;
    std::cout << "Enter the number m: ";
    std::cin >> m;
    std::cout << "Enter the number n: ";
    std::cin >> n;
    std::cout << "Enter the number p: ";
    std::cin >> p;

    // Ensure std::cin succeeded for all inputs
    if (!std::cin)
    {
      std::cerr << "Invalid input. Please enter integers only.\n";
      return 1; // Exit with error code
    }

    // Create and add matrices to the file
    MatrixCreatorLib::CreateMatrices::initializeFile();
    MatrixCreatorLib::CreateMatrices::createAndAddRandomMatrix(m, n);
    MatrixCreatorLib::CreateMatrices::createAndAddRandomMatrix(n, p);

    std::cout << "Matrices generated and added to the file.\n";
  }
  else
  {
    auto matrices = MatrixReader::getMatricesFromFile();
    TimeComparison::compare(matrices.first, matrices.second);
  }
  return 0;
}

// To generate the matrices:
// ./MatrixMultiplication

// To run the program:
// ./MatrixMultiplication --m

// M1: 2500 * 2500
// M2: 2500 * 2500
// Sequential time : 350816ms
// Concurrent time : 90949.6ms
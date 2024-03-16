#include "time_comparison.hpp"
#include "sequential_multiply.hpp"
#include "concurrent_multiply.hpp"
#include <iostream>
#include <chrono>

void TimeComparison::compare(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2)
{
  auto start = std::chrono::high_resolution_clock::now();
  SequentialMultiply::multiply(matrix1, matrix2);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> sequentialTime = end - start;
  std::cout << "Sequential time: " << sequentialTime.count() << "ms\n";

  start = std::chrono::high_resolution_clock::now();
  ConcurrentMultiply::multiply(matrix1, matrix2);
  end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> concurrentTime = end - start;
  std::cout << "Concurrent time: " << concurrentTime.count() << "ms\n";
}

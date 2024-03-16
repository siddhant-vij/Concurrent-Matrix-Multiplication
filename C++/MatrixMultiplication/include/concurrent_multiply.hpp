#ifndef CONCURRENT_MULTIPLY_HPP
#define CONCURRENT_MULTIPLY_HPP

#include <vector>

class ConcurrentMultiply
{
public:
  static std::vector<std::vector<int>> multiply(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2);
};

#endif // CONCURRENT_MULTIPLY_HPP

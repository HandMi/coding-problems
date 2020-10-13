#include <iostream>
#include <vector>


long long TriangularNumber(int n) { return (long long)n * (n + 1) / 2; }

long long SumOfMultiplesOf3And5(int n) {
  if (n < 3) {
    return 0;
  }
  auto max_multiple_of_3 = (n - 1) / 3;
  auto max_multiple_of_5 = (n - 1) / 5;
  auto max_multiple_of_15 = (n - 1) / 15;
  auto sums_of_3s = 3 * TriangularNumber(max_multiple_of_3);
  auto sum = 3 * TriangularNumber(max_multiple_of_3) +
         5 * TriangularNumber(max_multiple_of_5) -
         15 * TriangularNumber(max_multiple_of_15);
  return sum;
}

int main() {
  int t;
  std::cin >> t;

  std::vector<int> test_cases(t, 0);
  for (auto& test_case : test_cases) {
    std::cin >> test_case;
  }
  for (auto& test_case : test_cases) {
    std::cout << SumOfMultiplesOf3And5(test_case) << std::endl;
  }

  return 0;
}
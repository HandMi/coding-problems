
#include <algorithm>
#include <iostream>
#include <vector>

void PermuteValueToFront(int& value, std::vector<int>& permutation,
                         std::vector<int>& permutation_index_check) {
  if (value > permutation.size()) {
    return;
  } else {
    auto iter = std::find(permutation.begin(), permutation.end(), value);
    auto index = iter - permutation.begin();
    if ((0 != index) && (0 == permutation_index_check[index - 1]) &&
        (permutation[index] < permutation[index - 1])) {
      permutation_index_check[index - 1] = 1;
      std::iter_swap(iter - 1, iter);
    } else {
      value += 1;
      PermuteValueToFront(value, permutation, permutation_index_check);
    }
  }
}

void MinimalPermutation(std::vector<int>& permutation) {
  if (permutation.size() > 1U) {
    std::vector<int> permutation_index_check(permutation.size() - 1, 0);
    auto value = 1;
    for (auto j = 0U; j < permutation_index_check.size(); ++j) {
      PermuteValueToFront(value, permutation, permutation_index_check);
    }
  }
}

int main() {
  int test_cases;
  std::cin >> test_cases;
  for (auto i = 0; i < test_cases; ++i) {
    int length_of_permutation;
    std::cin >> length_of_permutation;
    std::vector<int> permutation(length_of_permutation);
    for (auto& number : permutation) {
      std::cin >> number;
    }
    MinimalPermutation(permutation);
    for (auto& number : permutation) {
      std::cout << number << " ";
    }
    std::cout << "\n";
  }
  return 0;
}
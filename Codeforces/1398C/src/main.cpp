#include <iostream>
#include <map>
#include <string>
#include <vector>

long long CountGoodSubArrays(const std::string& array_string) {
  long long good_sub_arrays{0};
  std::vector<int> prefix_sum;
  std::map<int, long long> occurences;
  prefix_sum.reserve(array_string.size() + 1);
  prefix_sum.push_back(0);
  for (const auto& character : array_string) {
    prefix_sum.push_back(character - '0');
  }
  occurences[0] = 1;
  for (std::size_t i = 1U; i < prefix_sum.size(); ++i) {
    // -1 to reduce problem to subarrays that sum to 0
    prefix_sum[i] += prefix_sum[i - 1] - 1;
    if (occurences.find(prefix_sum[i]) != occurences.end()) {
      occurences[prefix_sum[i]]++;
    } else {
      occurences[prefix_sum[i]] = 1;
    }
  }
  for (const auto& match : occurences) {
    good_sub_arrays += match.second * (match.second - 1) / 2;
  }
  return good_sub_arrays;
}

int main() {
  std::size_t number_of_tests;
  std::cin >> number_of_tests;

  for (auto i = 0U; i < number_of_tests; ++i) {
    int array_length;
    std::cin >> array_length;
    std::string array;
    std::cin >> array;
    std::cout << CountGoodSubArrays(array) << "\n";
  }

  return 0;
}
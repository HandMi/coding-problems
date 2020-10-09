#include <algorithm>
#include <iostream>
#include <vector>


inline bool TwoAreTrue(bool a, bool b, bool c) {
  return a ? (b || c) : (b && c);
}

long CalculateTotalArea(std::vector<std::vector<int>>& sticks) {
  long total_area{0};
  for (auto& colored_sticks : sticks) {
    std::sort(colored_sticks.rbegin(), colored_sticks.rend());
    colored_sticks.push_back(0);
  }
  std::vector<std::vector<std::vector<long>>> sums(
      sticks[0].size() + 1,
      std::vector<std::vector<long>>(
          sticks[1].size() + 1,
          std::vector<long>(sticks[2].size() + 1, 0)));
  // Iterate over all possible sums where we take i,j,k-times the the longest
  // stick from the red,green,blue stack respectively
  for (auto i = 0U; i < sums.size() - 1; ++i) {
    for (auto j = 0U; j < sums[i].size() - 1; ++j) {
      for (auto k = 0U; k < sums[i][j].size() - 1; ++k) {
        if ((i + j + k) % 2 == 0) {
          sums[i + 1][j + 1][k] =
              std::max(sums[i + 1][j + 1][k],
                       sums[i][j][k] + sticks[0][i] * sticks[1][j]);
          sums[i + 1][j][k + 1] =
              std::max(sums[i + 1][j][k + 1],
                       sums[i][j][k] + sticks[0][i] * sticks[2][k]);
          sums[i][j + 1][k + 1] =
              std::max(sums[i][j + 1][k + 1],
                       sums[i][j][k] + sticks[1][j] * sticks[2][k]);
          total_area = std::max(total_area, sums[i][j][k]);
        }
      }
    }
  }
  return total_area;
}

int main() {
  std::size_t number_of_red_sticks;
  std::size_t number_of_green_sticks;
  std::size_t number_of_blue_sticks;

  std::cin >> number_of_red_sticks;
  std::cin >> number_of_green_sticks;
  std::cin >> number_of_blue_sticks;

  std::vector<std::vector<int>> sticks(3);
  sticks[0].resize(number_of_red_sticks, 0);
  sticks[1].resize(number_of_green_sticks, 0);
  sticks[2].resize(number_of_blue_sticks, 0);

  for (auto& stick : sticks[0]) {
    std::cin >> stick;
  }
  for (auto& stick : sticks[1]) {
    std::cin >> stick;
  }
  for (auto& stick : sticks[2]) {
    std::cin >> stick;
  }
  std::cout << CalculateTotalArea(sticks);

  return 0;
}
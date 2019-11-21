#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

using GridType = std::vector<std::vector<int>>;
using DirectionType = std::vector<std::vector<char>>;

inline std::pair<int, int> CountFactors(int number) {
  int count_2 = 0;
  int count_5 = 0;
  int mod = number % 2;
  while (mod == 0) {
    count_2++;
    number /= 2;
    mod = number % 2;
  }
  mod = number % 5;
  while (mod == 0) {
    count_5++;
    number /= 5;
    mod = number % 5;
  }
  return {count_2, count_5};
}

int FindShortestWeightedPath(GridType& grid, DirectionType& directions) {
  for (auto i = 1U; i < grid.size(); ++i) {
    grid[0][i] += grid[0][i - 1];
    directions[0][i] = 'R';
  }
  for (auto i = 1U; i < grid.size(); ++i) {
    grid[i][0] += grid[i - 1][0];
    directions[i][0] = 'D';
  }

  for (auto i = 1U; i < grid.size(); ++i) {
    for (auto j = 1U; j < grid.size(); ++j) {
      if (grid[i][j - 1] < grid[i - 1][j]) {
        grid[i][j] += grid[i][j - 1];
        directions[i][j] = 'R';
      } else {
        grid[i][j] += grid[i - 1][j];
        directions[i][j] = 'D';
      }
    }
  }

  return grid[grid.size() - 1][grid.size() - 1];
}

inline std::string PathThroughZero(std::size_t dimension, std::size_t row) {
  std::string result;
  for (auto i = 0U; i < row; ++i) {
    result += 'D';
  };
  for (auto i = 0U; i < dimension - 1; ++i) {
    result += 'R';
  };
  for (auto i = 0U; i < dimension - row - 1; ++i) {
    result += 'D';
  };
  return result;
};

std::string ReconstructPath(const DirectionType& directions) {
  auto i = directions.size() - 1;
  auto j = directions.size() - 1;
  std::string total_path{directions[i][j]};

  for (auto turn = 1U; turn < 2 * (directions.size() - 1); turn++) {
    if (directions[i][j] == 'R') {
      total_path += directions[i][j - 1];
      j -= 1;
    } else {
      total_path += directions[i - 1][j];
      i -= 1;
    }
  }

  std::string reversed_path(total_path.rbegin(), total_path.rend());
  return reversed_path;
}

int main() {
  std::size_t dimension;
  std::cin >> dimension;
  GridType grid_of_2s(dimension, std::vector<int>(dimension, 0));

  GridType grid_of_5s(dimension, std::vector<int>(dimension, 0));
  DirectionType parents(dimension, std::vector<char>(dimension, 'R'));

  std::size_t found_zero{dimension};

  for (auto& row : grid_of_2s) {
    for (auto& node : row) {
      std::cin >> node;
    }
  }

  for (auto i = 0U; i < dimension; ++i) {
    for (auto j = 0U; j < dimension; ++j) {
      if (grid_of_2s[i][j] != 0) {
        std::tie(grid_of_2s[i][j], grid_of_5s[i][j]) =
            CountFactors(grid_of_2s[i][j]);
      } else {
        grid_of_2s[i][j] = 1;
        grid_of_5s[i][j] = 1;
        found_zero = i;
      }
    }
  }
  auto minimum_number_of_2s = FindShortestWeightedPath(grid_of_2s, parents);
  auto minimum_2_path = ReconstructPath(parents);
  auto minimum_number_of_5s = FindShortestWeightedPath(grid_of_5s, parents);
  auto minimum_5_path = ReconstructPath(parents);

  if ((found_zero < dimension) && (minimum_number_of_5s > 1) &&
      (minimum_number_of_2s > 1)) {
    auto path = PathThroughZero(dimension, found_zero);
    std::cout << 1 << "\n";
    std::cout << path;
  } else if (minimum_number_of_2s < minimum_number_of_5s) {
    std::cout << minimum_number_of_2s << "\n";
    std::cout << minimum_2_path;
  } else {
    std::cout << minimum_number_of_5s << "\n";
    std::cout << minimum_5_path;
  }

  return 0;
}
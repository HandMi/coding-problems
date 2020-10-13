#include <iostream>
#include <numeric>
#include <vector>


bool CrossRiver(std::vector<int>& river, std::size_t max_jump,
                const std::vector<int>& platforms) {
  max_jump--;
  int total_platform_length =
      std::accumulate(platforms.begin(), platforms.end(), 0);
  auto water_to_cross = river.size() - total_platform_length;
  auto position = 0U;
  auto current_platform = 0U;
  while (position < river.size()) {
    if (current_platform > platforms.size() - 1) {
      return ((river.size() - position) <= max_jump) ? true : false;
    }
    if (water_to_cross > max_jump) {
      position += max_jump;
      water_to_cross -= max_jump;
    } else if (water_to_cross > 0) {
      position += water_to_cross;
      water_to_cross = 0;
    }
    for (auto i = 0; i < platforms[current_platform]; ++i) {
      river[position] = current_platform + 1;
      position++;
    }
    current_platform++;
  }
  return true;
}

int main() {
  std::size_t river_width;
  std::size_t number_of_platforms;
  std::size_t max_jump;

  std::cin >> river_width;
  std::cin >> number_of_platforms;
  std::cin >> max_jump;

  std::vector<int> platforms(number_of_platforms);
  std::vector<int> river(river_width);

  for (auto& platform : platforms) {
    std::cin >> platform;
  }
  auto answer = CrossRiver(river, max_jump, platforms) ? "YES" : "NO";
  std::cout << answer;
  if (answer == "YES") {
    std::cout << "\n";
    for (auto& position : river) {
      std::cout << position << " ";
    }
  }

  return 0;
}
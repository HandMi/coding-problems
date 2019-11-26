#include <iostream>
#include <vector>

bool ConstructStrategy(std::vector<std::uint32_t>& problems,
                       std::uint32_t number_of_problems) {
  auto days = problems.size();
  std::uint32_t triangular_number = (days + 1) * days / 2;
  if ((number_of_problems < triangular_number) ||
      ((days == 2) && (number_of_problems == 4)) ||
      ((days == 3) && (number_of_problems == 8))) {
    return false;
  } else {
    auto base = (number_of_problems - triangular_number) / days;
    auto mod = (number_of_problems - triangular_number) % days;
    for (auto i = 1U; i <= days; ++i) {
      problems[i - 1] = base + i;
    }
    if (mod) {
      problems[days - 1] += 1U;
      mod--;
    }
    for (auto i = 0U; i < mod; ++i) {
      problems[days - mod + i]++;
    }

    return true;
  }
}

int main() {
  std::uint32_t number_of_problems;
  std::uint16_t number_of_days;
  std::cin >> number_of_problems >> number_of_days;
  std::vector<std::uint32_t> problems_per_day(number_of_days);
  if (ConstructStrategy(problems_per_day, number_of_problems)) {
    std::cout << "YES"
              << "\n";
    for (auto& problem_set : problems_per_day) {
      std::cout << problem_set << " ";
    }
  } else {
    std::cout << "NO";
  }

  return 0;
}
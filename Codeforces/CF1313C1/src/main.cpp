#include <algorithm>
#include <iostream>
#include <vector>

long long ConstructSkyscrapers(std::vector<int>& limits,
                               std::vector<int>::iterator it1,
                               std::vector<int>::iterator it2) {
  if (it1 == limits.end()) {
    return 0;
  }
  if (it1 == it2) {
    return 0;
  }
  if ((it1 + 1) == it2) {
    return *(it1);
  }
  auto it_min = std::min_element(it1, it2);
  long long val_min = *it_min;
  auto left =
      ConstructSkyscrapers(limits, it1, it_min) + val_min * (it2 - it_min);
  auto right = ConstructSkyscrapers(limits, it_min + 1, it2) +
               val_min * (it_min + 1 - it1);
  if (left >= right) {
    std::fill(it_min + 1, it2, val_min);
    return left;
  } else {
    std::fill(it1, it_min, val_min);
    return right;
  }
}

void Solve(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<int> limits(n, 0);
  for (auto& limit : limits) {
    in >> limit;
  }
  ConstructSkyscrapers(limits, limits.begin(), limits.end());

  for (auto& limit : limits) {
    out << limit << " ";
  }
}

int main() {
  Solve(std::cin, std::cout);
  return 0;
}
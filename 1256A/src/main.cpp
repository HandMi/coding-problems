#include "check_remainder.h"
#include <iostream>
#include <string>

int main() {
  const auto q = [&](int i) { return std::cin >> i, std::move(i); }({});
  for (int i = 0; i < q; ++i) {
    int a, b, n, S;
    std::cin >> a >> b >> n >> S;
    if (CheckRemainder(a, b, n, S))
      std::cout << "Yes\n";
    else {
      std::cout << "No\n";
    }
  }
  return 0;
}
#include <iostream>
#include <string>


bool CheckRemainder(int a, int b, int dividend, int sum) {
  if ((sum % dividend <= b) &&
      (static_cast<long long int>(dividend) * a + b >= sum)) {
    return true;
  } else {
    return false;
  }
}

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
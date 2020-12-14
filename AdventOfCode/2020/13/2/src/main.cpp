#include <algorithm>
#include <iostream>
#include <vector>

struct Busline {
  long id;
  long remainder;
};

// Euclid Algorithm
// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
long long modular_inverse(long long a, long r) {
  if (r == 1) {
    return 0;
  }
  auto r0 = r;
  long long t, q;
  long long x0{0}, x1{1};
  while (a > 1) {
    q = a / r;
    t = r;
    r = a % r, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }

  if (x1 < 0) {
    x1 += r0;
  }

  return x1;
}

long ShuttleSearch(const std::vector<Busline>& bus_lines) {
  long long product = 1;
  long long result = 0;
  for (const auto& bus_line : bus_lines) {
    product *= bus_line.id;
  }
  for (const auto& bus_line : bus_lines) {
    long long partial_product = product / bus_line.id;
    result += bus_line.remainder *
              modular_inverse(partial_product, bus_line.id) * partial_product;
  }
  return result % product;
};

void Solve(std::istream& in, std::ostream& out) {
  std::string schedule;
  std::vector<Busline> bus_lines{};
  in >> schedule;
  std::size_t pos = 0;
  std::size_t npos = 0;
  long delay = 0;
  while (npos < schedule.length()) {
    npos = schedule.find(",", pos);
    auto bus_line = schedule.substr(pos, npos - pos);
    if (bus_line != "x") {
      auto id = std::stol(bus_line);
      bus_lines.push_back(Busline{id, id - delay});
    }
    ++delay;
    pos = npos + 1;
  }
  out << ShuttleSearch(bus_lines);
}

int main() {
  Solve(std::cin, std::cout);
  return 0;
}
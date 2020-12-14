#include <algorithm>
#include <iostream>
#include <vector>


int ShuttleSearch(int start_time, const std::vector<int>& bus_lines) {
  int wait{bus_lines[0]};
  int line{bus_lines[0]};
  for (auto bus_line : bus_lines) {
    int res = bus_line - start_time % bus_line;
    if (res < wait) {
      wait = res;
      line = bus_line;
    }
  };
  return wait*line;
};

void Solve(std::istream& in, std::ostream& out) {
  int start_time;
  std::string schedule;
  std::vector<int> bus_lines{};
  in >> start_time;
  in >> schedule;
  std::size_t pos = 0;
  std::size_t npos = 0;
  while (npos < schedule.length()) {
    npos = schedule.find(",", pos);
    auto bus_line = schedule.substr(pos, npos - pos);
    if (bus_line != "x") {
      bus_lines.push_back(std::stoi(bus_line));
    }
    pos = npos + 1;
  }
  out << ShuttleSearch(start_time, bus_lines);
}

int main() {
  Solve(std::cin, std::cout);
  return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

using SeatPlan = std::vector<std::string>;

bool SeatingSystem(SeatPlan& seats) {
  bool changed{false};
  SeatPlan old_seats = seats;
  for (std::size_t i = 1U; i < seats.size() - 1; ++i) {
    for (std::size_t j = 1U; j < seats[i].size() - 1; ++j) {
      if (old_seats[i][j] == 'L' &&
          (old_seats[i - 1][j] != '#' && old_seats[i - 1][j + 1] != '#' &&
           old_seats[i - 1][j - 1] != '#' && old_seats[i][j + 1] != '#' &&
           old_seats[i][j - 1] != '#' && old_seats[i + 1][j + 1] != '#' &&
           old_seats[i + 1][j] != '#' && old_seats[i + 1][j - 1] != '#')) {
        changed = true;
        seats[i][j] = '#';
      } else if (old_seats[i][j] == '#') {
        int neighbors =
            (old_seats[i - 1][j] == '#') + (old_seats[i - 1][j + 1] == '#') +
            (old_seats[i - 1][j - 1] == '#') + (old_seats[i][j + 1] == '#') +
            (old_seats[i][j - 1] == '#') + (old_seats[i + 1][j + 1] == '#') +
            (old_seats[i + 1][j] == '#') + (old_seats[i + 1][j - 1] == '#');
        if (neighbors >= 4) {
          changed = true;
          seats[i][j] = 'L';
        }
      }
    }
  }

  return changed;
};

void Solve(std::istream& in, std::ostream& out) {
  SeatPlan seats;
  seats.push_back(".");
  std::string row;
  while (std::getline(in, row)) {
    if (row.empty()) {
      break;
    }
    seats.push_back('.' + row + '.');
  }
  seats[0] = std::string(seats[1].length(), '.');
  seats.push_back(std::string(seats[1].length(), '.'));

  bool changed = true;
  while (changed) {
    changed = SeatingSystem(seats);
  }
  int n = 0;
  for (const auto& row : seats) {
    n += std::count(row.begin(), row.end(), '#');
  }
  out << n << std::endl;
}

void SeatingTest(std::istream& in, std::ostream& out) {
  SeatPlan seats;
  std::string row;
  while (std::getline(in, row)) {
    seats.push_back(row);
  }

  SeatingSystem(seats);
  for (const auto& row : seats) {
    out << row << std::endl;
  }
}

int main() {
  Solve(std::cin, std::cout);
  return 0;
}
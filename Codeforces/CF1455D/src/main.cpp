#include <cmath>
#include <iostream>
#include <vector>


int SequenceSwaps(const std::vector<int>& sequence, int x) {
  int total_swaps{0};
  int swap_count{0};
  for (int i = 1; i < sequence.size(); ++i) {
    if (sequence[i] < sequence[i - 1]) {
      if (sequence[i] >= std::max(sequence[i - 2], x)) {
        total_swaps += swap_count;
        swap_count = 0;
        x = sequence[i - 1];
      } else
        // Sequence is not sorted and can't swap anymore
        return -1;
    }
    if (sequence[i] > x && sequence[i] != sequence[i - 1]) {
      ++swap_count;
    }
  }
  return total_swaps;
};

void Solve(std::istream& in, std::ostream& out) {
  int test_cases;
  in >> test_cases;

  for (int i = 0; i < test_cases; ++i) {
    int n, x;
    in >> n;
    in >> x;
    std::vector<int> sequence(n + 1, INT32_MIN);
    for (std::size_t j = 1; j < sequence.size(); ++j) {
      in >> sequence[j];
    }
    out << SequenceSwaps(sequence, x) << std::endl;
  }
}

int main() {
  Solve(std::cin, std::cout);
  return 0;
}
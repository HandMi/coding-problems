#include <array>
#include <iostream>
#include <unordered_set>


std::array<long long, 3> ReconstructStats(long long n, long long p, int w,
                                          int d) {
  auto max_wins = p / w;
  auto mod = p % w;
  int draws = -1;
  auto wins = max_wins;
  for (wins = max_wins; wins >= max_wins - d; --wins) {
    if ((mod + (max_wins - wins) * w) % d == 0) {
      draws = (mod + (max_wins - wins) * w) / d;
      break;
    } else {
      /* code */
    }
  }
  return {wins, draws, n - wins - draws};
};

int main() {
  long long n, p;
  int w, d;
  std::cin >> n >> p >> w >> d;
  auto solution = ReconstructStats(n, p, w, d);
  if ((solution[2] < 0) || (solution[1] < 0) || (solution[0] < 0)) {
    std::cout << -1;
  } else {
    std::cout << solution[0] << " " << solution[1] << " " << solution[2];
  }

  return 0;
}
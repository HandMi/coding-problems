#include <iostream>
#include <map>
#include <string>

int CountFillableGaps(std::map<int, int> gaps, int k) {
  int filled_gaps = 0;
  for (const auto& gap : gaps) {
    int possibly_filled_gaps = std::min(k / gap.first, gap.second);
    filled_gaps += possibly_filled_gaps;
    k -= possibly_filled_gaps * gap.first;
  }
  return filled_gaps;
}

int MaxScore(const std::string& games, int k) {
  auto next_win = games.find('W');
  if (next_win < games.size()) {
    int streaks = 0;
    int wins = 0;
    std::map<int, int> gaps;
    while(next_win < games.size()) {
      ++streaks;
      auto next_loss = std::min(games.find('L', next_win),games.size());
      wins+=next_loss-next_win;
      next_win = std::min(games.find('W', next_loss),games.size());
      if(next_win<games.size()){
          ++gaps[next_win-next_loss];
      }
    }
    if ((wins + k) >= games.length()) {
      return 2 * games.length() - 1;
    }
    return 2 * (k + wins) - streaks + CountFillableGaps(gaps, k);
  } else {
    return std::max(0, 2 * k - 1);
  }
}

void Solve(std::istream& in, std::ostream& out) {
  int t;
  in >> t;
  for (auto i = 0U; i < t; ++i) {
    int n, k;
    in >> n;
    in >> k;
    std::string games;
    in >> games;
    out << MaxScore(games, k) << std::endl;
  }
}

int main() {
  Solve(std::cin, std::cout);
  return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    int adapter;
    std::vector<int> adapters;
    std::vector<std::int64_t> dp{1, 0, 0, 0};
    adapters.push_back(0);
    while (in >> adapter)
    {
        adapters.push_back(adapter);
    }
    std::sort(adapters.begin(), adapters.end());
    adapters.push_back(adapters.back() + 3);
    int last = adapters[0];
    for (std::size_t i = 1; i < adapters.size(); ++i)
    {
        auto diff = adapters[i] - adapters[i - 1];
        std::rotate(dp.rbegin(), dp.rbegin() + diff, dp.rend());
        std::fill(dp.begin(), dp.begin() + diff, 0);
        dp[0] = dp[1] + dp[2] + dp[3];
    }
    out << dp[0] << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

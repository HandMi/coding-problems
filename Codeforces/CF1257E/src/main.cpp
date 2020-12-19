#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::uint32_t
LongestIncreasingSubsequence(const std::vector<std::uint32_t> &sequence)
{
    std::set<std::uint32_t> lis;
    for (auto &number : sequence)
    {
        auto it_low = lis.lower_bound(number);
        if (it_low != lis.end())
        {
            lis.erase(it_low);
        }
        lis.insert(number);
    }
    return lis.size();
}

std::uint32_t
MinimumMoves(std::vector<std::vector<std::uint32_t>> &participants)
{
    std::size_t size = 0;
    for (auto &participant : participants)
    {
        size += participant.size();
    }
    std::vector<std::uint32_t> configuration;
    configuration.reserve(size);
    for (auto &participant : participants)
    {
        std::sort(participant.begin(), participant.end());
        std::move(participant.begin(), participant.end(),
                  std::back_inserter(configuration));
    }
    return configuration.size() - LongestIncreasingSubsequence(configuration);
}

int main()
{
    std::uint32_t k1, k2, k3;
    std::cin >> k1 >> k2 >> k3;
    std::vector<std::vector<std::uint32_t>> participants{
        std::vector<std::uint32_t>(k1), std::vector<std::uint32_t>(k2),
        std::vector<std::uint32_t>(k3)};
    for (auto &participant : participants)
    {
        for (auto &problem : participant)
        {
            std::cin >> problem;
        }
    }
    std::cout << static_cast<int>(MinimumMoves(participants));

    return 0;
}

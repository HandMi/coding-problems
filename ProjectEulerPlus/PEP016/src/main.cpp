#include "main.h"
#include <iostream>
#include <numeric>
#include <vector>

auto PowerDigitSum(int n, std::vector<std::string> &powers) -> int
{
    std::string power = powers.back();
    for (int i = powers.size(); i <= n; ++i)
    {
        int carry = 0;
        for (auto &c : power)
        {
            int d = (c - '0') * 2 + carry;
            carry = d / 10;
            d = d % 10;
            c = '0' + d;
        }
        if (carry != 0)
        {
            power += '0' + carry;
        }
        powers.push_back(power);
    }

    return std::accumulate(
        powers[n].begin(), powers[n].end(), 0,
        [](int sum, char c) -> int { return sum + c - '0'; });
}

auto main() -> int
{
    std::size_t t;
    std::cin >> t;

    std::vector<int> test_cases(t, 0);
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case;
    }
    std::vector<std::string> powers{"1"};
    for (auto &test_case : test_cases)
    {
        std::cout << PowerDigitSum(test_case, powers) << std::endl;
    }

    return 0;
}

#include <iostream>
#include <main.h>
#include <vector>

auto SumSquareDifference(long n) -> long
{
    return n * n * (n + 1) * (n + 1) / 4 - n * (n + 1) * (2 * n + 1) / 6;
};

auto main() -> int
{
    std::size_t t;
    std::cin >> t;

    std::vector<long> test_cases(t, 0);
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case;
    }
    for (auto &test_case : test_cases)
    {
        std::cout << SumSquareDifference(test_case) << std::endl;
    }

    return 0;
}

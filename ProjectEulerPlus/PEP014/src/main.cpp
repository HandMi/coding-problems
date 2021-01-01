#include "main.h"
#include <iostream>
#include <vector>

int main()
{
    int t;
    std::cin >> t;

    std::vector<std::uint64_t> test_cases(t, 0);
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case;
    }

    CollatzChains collatz_chains;
    collatz_chains.ComputeCollatzChains(5000000U);

    for (auto &test_case : test_cases)
    {
        std::cout << collatz_chains.LongestCollatz(test_case) << std::endl;
    }

    return 0;
}

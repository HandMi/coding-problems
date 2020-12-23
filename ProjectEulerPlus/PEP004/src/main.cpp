
#include <cmath>
#include <iostream>
#include <main.h>
#include <vector>

auto IsPalindrome(int n) -> bool
{
    const auto number = n;
    int reverse = 0;
    while (n > 0)
    {
        auto remainder = n % 10;
        reverse = (reverse * 10) + remainder;
        n /= 10;
    }
    return number == reverse;
}

auto LargestPalindromeProduct(int N) -> int
{
    int result = 0;
    int i_max = std::sqrt(N) + 1;
    int j_min{};
    for (int i = i_max; i >= 100; --i)
    {
        for (int j = std::max(i, j_min); j <= 1000; ++j)
        {
            const auto product = j * i;
            if (product > N)
            {
                break;
            }
            if (IsPalindrome(product))
            {
                j_min = j;
                result = std::max(result, product);
            }
        }
    }
    return result;
}

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
        std::cout << LargestPalindromeProduct(test_case) << std::endl;
    }

    return 0;
}

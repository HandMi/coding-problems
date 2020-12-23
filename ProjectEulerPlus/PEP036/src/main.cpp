
#include "main.h"
#include <cmath>
#include <iostream>
#include <vector>

auto main() -> int
{
    PalindromeGenerator palindrome_generator;
    palindrome_generator.Generate(1000000);

    int N;
    std::cin >> N;

    int K;
    std::cin >> K;

    std::cout << palindrome_generator.SumDoubleBase(N, K) << std::endl;

    return 0;
}

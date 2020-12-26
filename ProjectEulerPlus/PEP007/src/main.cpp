#include <iostream>
#include <main.h>
#include <vector>

void PrimeGenerator::GeneratePrime(long n)
{
    if (n < primes_.back())
    {
        return;
    }
    std::vector<bool> marked(n, true);
    for (auto p : primes_)
    {
        for (long i = p * p; i < n; i += p)
        {
            marked[i] = false;
        }
    }
    for (long i = primes_.back() + 1; i < n; ++i)
    {
        if (marked[i] == true)
        {
            for (long j = i * i; j < n; j += i)
            {
                marked[j] = false;
            }
            primes_.push_back(i);
        }
    }
}

auto main() -> int
{
    std::size_t t;
    PrimeGenerator prime_generator(10000);
    std::cin >> t;

    std::vector<long> test_cases(t, 0);
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case;
    }
    for (auto &test_case : test_cases)
    {
        std::cout << prime_generator.GetPrime(test_case) << std::endl;
    }

    return 0;
}

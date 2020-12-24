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

auto PrimeGenerator::LCM(long n) -> long long
{
    long long lcm = 1;

    for (std::size_t i = 0; i < primes_.size() && primes_[i] <= n; ++i)
    {
        auto prime = primes_[i];
        while (prime * primes_[i] <= n)
        {
            prime *= primes_[i];
        }
        lcm *= prime;
    }
    return lcm;
}

auto main() -> int
{
    std::size_t t;
    PrimeGenerator prime_generator(100);
    std::cin >> t;

    std::vector<long> test_cases(t, 0);
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case;
    }
    for (auto &test_case : test_cases)
    {
        std::cout << prime_generator.LCM(test_case) << std::endl;
    }

    return 0;
}

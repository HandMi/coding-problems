
#include <cmath>
#include <iostream>
#include <main.h>
#include <vector>

inline auto IsDivisible(long n, long k) -> bool { return n > k && n % k == 0; }

auto Factorizer::Factorize(long n) -> std::vector<long>
{
    long limit = std::floor(sqrt(n)) + 1;
    if (primes_.back() < limit)
    {
        GeneratePrime(n);
    }
    std::vector<long> factors;
    for (auto prime : primes_)
    {
        if (prime >= n || prime > limit)
        {
            break;
        }
        while (IsDivisible(n, prime))
        {
            n = n / prime;
            factors.push_back(prime);
        }
    }
    factors.push_back(n);
    return factors;
}
auto Factorizer::LargestPrimeFactor(long n) -> long
{
    const auto factors = Factorize(n);
    return factors.back();
}

void Factorizer::GeneratePrime(long n)
{
    long limit = std::floor(sqrt(n)) + 1;
    if (limit < primes_.back())
    {
        return;
    }
    std::vector<bool> marked(limit, true);
    for (auto p : primes_)
    {
        for (long i = p * p; i < limit; i += p)
        {
            marked[i] = false;
        }
    }
    for (long i = primes_.back() + 1; i < limit; ++i)
    {
        if (marked[i] == true)
        {
            for (long j = i * i; j < limit; j += i)
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
    Factorizer factorizer(20000);
    std::cin >> t;

    std::vector<long> test_cases(t, 0);
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case;
    }
    for (auto &test_case : test_cases)
    {
        std::cout << factorizer.LargestPrimeFactor(test_case) << std::endl;
    }

    return 0;
}


#include <algorithm>
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
    std::vector<long> factors{};
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

auto Factorizer::CountDivisors(const std::vector<long> &factors) -> long
{
    int count{1};
    long divisors{1};
    for (std::size_t i = 1U; i < factors.size(); ++i)
    {
        if (factors[i] == factors[i - 1])
        {
            ++count;
        }
        else
        {
            divisors *= count;
            count = 2;
        }
    }
    return divisors * count;
}

auto Factorizer::HighlyDivisibleTriangularNumber(long n) -> long
{
    if (n < triangular_numbers_.size())
    {
        return triangular_numbers_[n];
    }
    long divisors{};
    long i{max_i_};
    long triangular_number{};
    while (divisors <= n)
    {
        ++i;
        triangular_number = i * (i + 1) / 2;
        GeneratePrime(i + 1);
        auto factors = Factorize(i);
        auto factors2 = Factorize(i + 1);
        factors.insert(factors.end(), factors2.begin(), factors2.end());
        std::sort(factors.begin(), factors.end());
        divisors = CountDivisors(factors);
        if (triangular_numbers_.size() < divisors)
        {
            for (auto i = triangular_numbers_.size(); i < divisors; ++i)
            {
                triangular_numbers_.push_back(triangular_number);
            }
        }
    }
    max_i_ = i;
    return triangular_number;
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
        std::cout << factorizer.HighlyDivisibleTriangularNumber(test_case)
                  << std::endl;
    }

    return 0;
}

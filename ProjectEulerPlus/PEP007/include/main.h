#ifndef MAIN_H
#define MAIN_H

#include <vector>

class PrimeGenerator
{
  private:
    void GeneratePrime(long n);
    std::vector<long> primes_{2, 3, 5, 7, 11, 13, 17};

  public:
    PrimeGenerator(long n) { GeneratePrime(n); }
    auto GetPrime(long n) -> long
    {
        if (primes_.size() < 2 * n)
        {
            GeneratePrime(n * n);
        };
        return primes_[n - 1];
    };
};

#endif

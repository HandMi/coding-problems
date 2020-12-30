#ifndef MAIN_H
#define MAIN_H

#include <vector>

class Factorizer
{
  private:
    auto Factorize(long n) -> std::vector<long>;
    void GeneratePrime(long n);
    auto CountDivisors(const std::vector<long> &factors) -> long;
    std::vector<long> primes_{2, 3, 5, 7, 11, 13, 17};
    std::vector<long> triangular_numbers_{0};
    int max_i_{1};

  public:
    Factorizer(long n) { GeneratePrime(n); }
    auto HighlyDivisibleTriangularNumber(long n) -> long;
};

#endif

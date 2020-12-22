#ifndef MAIN_H
#define MAIN_H

#include <vector>

class Factorizer
{
  private:
    auto Factorize(long n) -> std::vector<long>;
    void GeneratePrime(long n);
    std::vector<long> primes_{2, 3, 5, 7, 11, 13, 17};

  public:
    Factorizer(long n) { GeneratePrime(n); }
    auto LargestPrimeFactor(long n) -> long;
};

#endif

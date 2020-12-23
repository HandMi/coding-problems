#ifndef MAIN_H
#define MAIN_H

#include <cmath>
#include <vector>

class PalindromeGenerator
{
  private:
    auto IsPalindrome(int n, int base = 10) -> bool
    {
        const auto number = n;
        int reverse = 0;
        while (n > 0)
        {
            auto remainder = n % base;
            reverse = (reverse * base) + remainder;
            n /= base;
        }
        return number == reverse;
    }

    auto CreatePalindrome(int n, bool odd) -> int
    {
        int palin = n;
        if (odd)
        {
            n /= 10;
        }
        while (n > 0)
        {
            palin = palin * 10 + (n % 10);
            n /= 10;
        }
        return palin;
    }

  public:
    void Generate(long N)
    {
        int palin{0};
        int i = 1;
        int max = 10;
        while (max < N)
        {
            for (int j = i; j < max; ++j)
            {
                palindromes.push_back(CreatePalindrome(j, true));
            }
            for (int j = i; j < max; ++j)
            {
                palindromes.push_back(CreatePalindrome(j, false));
            }
            i = max;
            max *= 10;
        }
    }

    auto SumDoubleBase(int N, int K) -> int
    {
        int result = 0;
        for (std::size_t i = 0U; i < palindromes.size() && palindromes[i] < N;
             ++i)
        {
            if (IsPalindrome(palindromes[i], K))
            {
                result += palindromes[i];
            }
        }
        return result;
    }

    std::vector<int> palindromes{};
};

#endif

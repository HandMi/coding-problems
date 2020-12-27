#include <algorithm>
#include <iostream>

// Using Euclid's formula to generate Triplets
// https://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
long long PythagoreanTriplet(long N)
{
    long result = -1;
    for (long m = 1; 2 * m * m < N; ++m)
    {
        for (long k = N / (4 * m * m) + 1; k <= N / (2 * m * m); ++k)
        {
            long n = N - 2 * m * m * k;
            if (n % (2 * k * m) == 0 && n > 0)
            {
                n /= 2 * m * k;
                long a, b, c;
                a = k * (m * m - n * n);
                b = k * (2 * m * n);
                c = k * (m * m + n * n);
                long product = a * b * c;
                result = std::max(result, product);
            }
        }
    }
    return result;
}

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        std::cin >> n;
        std::cout << PythagoreanTriplet(n) << std::endl;
    }

    return 0;
}

#include <iostream>
#include <numeric>
#include <string>

long LargestProduct(std::string &n, int k)
{
    long result = 0;
    for (auto it = n.begin(); it != n.end() - k; ++it)
    {
        result = std::max(
            result, std::accumulate(it, it + k, 1l, [](long n, char c) -> long {
                return n * (c - '0');
            }));
    }
    return result;
}

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n, k;
        std::cin >> n >> k;
        std::string input;
        std::cin >> input;
        std::cout << LargestProduct(input, k) << std::endl;
    }

    return 0;
}

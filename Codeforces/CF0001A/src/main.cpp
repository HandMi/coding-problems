#include <iostream>

long long ComputeFlagstones(int n, int m, int a)
{
    long long num_n = (n % a == 0) ? n / a : n / a + 1;
    long long num_m = (m % a == 0) ? m / a : m / a + 1;
    return num_m * num_n;
}

int main()
{
    int n, m, a;
    std::cin >> n >> m >> a;
    std::cout << ComputeFlagstones(n, m, a);
    return 0;
}

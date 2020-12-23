#include <iostream>
#include <map>
#include <vector>

void GetNextFibonacci(long long &fn1, long long &fn2)
{
    auto fn_next = fn1 + fn2;
    fn2 = fn1;
    fn1 = fn_next;
}

void ComputeEvenFibonacciSum(std::map<long long, long long> &fibonacci_sums)
{
    long long fn1 = 2;
    long long fn2 = 1;
    long long sum = 0;
    for (auto &result_pair : fibonacci_sums)
    {
        while (fn1 <= result_pair.first)
        {
            sum += fn1;
            GetNextFibonacci(fn1, fn2);
            GetNextFibonacci(fn1, fn2);
            GetNextFibonacci(fn1, fn2);
        }
        result_pair.second = sum;
    }
}

int main()
{
    int t;
    std::cin >> t;

    std::vector<long long> test_cases(t, 0);
    std::map<long long, long long> results;
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case;
        results[test_case] = 0;
    }

    ComputeEvenFibonacciSum(results);

    for (auto &test_case : test_cases)
    {
        std::cout << results[test_case] << std::endl;
    }

    return 0;
}

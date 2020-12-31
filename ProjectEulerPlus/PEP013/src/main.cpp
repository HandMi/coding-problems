#include <algorithm>
#include <iostream>
#include <vector>

auto Sum(const std::string &s1, const std::string &s2) -> std::string
{
    std::string result{};
    auto it1 = s1.rbegin();
    auto it2 = s2.rbegin();
    int carry{};
    while (it1 != s1.rend() || it2 != s2.rend() || carry != 0)
    {
        int a = 0;
        int b = 0;
        if (it1 != s1.rend())
        {
            a = *it1 - '0';
            ++it1;
        }
        if (it2 != s2.rend())
        {
            b = *it2 - '0';
            ++it2;
        }
        int digit = a + b + carry;
        carry = digit / 10;
        digit = digit % 10;
        result.push_back(digit + '0');
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    in >> n;
    std::vector<std::string> numbers;
    for (int i = 0; i < n; ++i)
    {
        std::string number;
        in >> number;
        numbers.push_back(number);
    }
    std::string result{};
    for (int i = 0; i < n; ++i)
    {
        result = Sum(result, numbers[i]);
    }
    out << result.substr(0, 10) << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

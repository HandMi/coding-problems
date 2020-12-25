#include <algorithm>
#include <deque>
#include <iostream>

void Solve(std::istream &in, std::ostream &out, const std::size_t kPreambleSize,
           const std::int64_t kTarget)
{
    std::int64_t sum{}, n{};
    std::deque<std::int64_t> numbers;
    while (sum < kTarget)
    {
        in >> n;
        sum += n;
        numbers.push_back(n);
        while (sum > kTarget)
        {
            sum -= numbers.front();
            numbers.pop_front();
        }
    }
    out << *std::min_element(numbers.begin(), numbers.end()) +
               *std::max_element(numbers.begin(), numbers.end())
        << std::endl;
}

auto main() -> int
{
    constexpr std::size_t kPreambleSize{25};
    constexpr std::int64_t kTarget{1930745883};
    Solve(std::cin, std::cout, kPreambleSize, kTarget);
    return 0;
}

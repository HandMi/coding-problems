#include <iostream>
#include <queue>
#include <unordered_set>

void Solve(std::istream &in, std::ostream &out, const std::size_t kPreambleSize)
{
    std::queue<std::int64_t> data;
    std::unordered_set<std::int64_t> data_set;
    std::int64_t n;

    for (std::size_t i = 0; i < kPreambleSize; ++i)
    {
        in >> n;
        data.push(n);
        data_set.insert(n);
    }
    while (in >> n)
    {
        bool found = false;
        for (auto it1 = data_set.begin(); it1 != data_set.end() && !found;
             ++it1)
        {
            auto target = n - *it1;
            found =
                (target == n) ? false : data_set.find(target) != data_set.end();
        }
        if (!found)
        {
            out << n << std::endl;
            break;
        }
        data_set.erase(data.front());
        data_set.insert(n);
        data.pop();
        data.push(n);
    }
}

auto main() -> int
{
    constexpr std::size_t kPreambleSize = 25;
    Solve(std::cin, std::cout, kPreambleSize);
    return 0;
}

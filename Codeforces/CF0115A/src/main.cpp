#include <iostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    int N;
    in >> N;
    std::vector<int> employees(N, 0);
    int max_depth{0};
    for (auto &superior : employees)
    {
        in >> superior;
    }
    for (const auto employee : employees)
    {
        int depth{1};
        int superior = employee;
        while (superior > 0)
        {
            ++depth;
            superior = employees[superior - 1];
        }
        max_depth = std::max(depth, max_depth);
    }
    out << max_depth << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

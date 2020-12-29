#include <algorithm>
#include <array>
#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    in >> n;
    std::array<int, 3> F{};

    for (int i = 0; i < n; ++i)
    {
        for (auto &f : F)
        {
            int g;
            in >> g;
            f += g;
        }
    }
    if (std::all_of(F.begin(), F.end(), [](int i) { return i == 0; }))
    {
        out << "YES" << std::endl;
    }
    else
    {
        out << "NO" << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

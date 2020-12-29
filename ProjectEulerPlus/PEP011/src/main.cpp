#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

void Solve(std::istream &in, std::ostream &out)
{
    constexpr std::array<std::pair<int, int>, 4> directions{
        {{1, 0}, {0, 1}, {1, 1}, {-1, 1}}};

    std::array<std::array<int, 26>, 23> grid{};
    long long max_product{};
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 3; j < 23; ++j)
        {
            in >> grid[i][j];
        }
    }

    for (int i = 0; i < 20; ++i)
    {
        for (int j = 3; j < 23; ++j)
        {
            for (const auto &d : directions)
            {
                long long product = grid[i][j];
                for (int k = 1; k < 4; ++k)
                {
                    product *= grid[i + d.second * k][j + d.first * k];
                }
                max_product = std::max(product, max_product);
            }
        }
    }
    out << max_product << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

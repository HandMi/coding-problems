#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <vector>

struct City
{
    bool storage;
    std::vector<std::pair<int, std::uint32_t>> neighbors;
};

void Solve(std::istream &in, std::ostream &out)
{
    int n, m, k;
    in >> n >> m >> k;

    std::vector<City> cities(n + 1, City{});

    for (int i = 0; i < m; ++i)
    {
        int a, b, weight;
        in >> a >> b >> weight;
        cities[a].neighbors.push_back({b, weight});
        cities[b].neighbors.push_back({a, weight});
    }

    std::vector<std::uint32_t> warehouses;
    for (int i = 0; i < k; ++i)
    {
        int a;
        in >> a;
        cities[a].storage = true;
        warehouses.push_back(a);
    }

    std::uint32_t result = INT_MAX;
    bool found{false};
    for (const auto w : warehouses)
    {
        for (const auto neighbor : cities[w].neighbors)
        {
            if (!cities[neighbor.first].storage)
            {
                found = true;
                result = std::min(result, neighbor.second);
            }
        }
    }
    if (found)
    {
        out << result << std::endl;
    }
    else
    {
        out << -1 << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

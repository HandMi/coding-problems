#include <algorithm>
#include <iostream>
#include <numeric>
#include <regex>
#include <vector>

using Hexagons = std::vector<std::vector<bool>>;

void Turn(Hexagons &hexagons, const std::size_t x_min, const std::size_t x_max,
          const std::size_t y_min, const std::size_t y_max)
{
    static const std::vector<std::pair<int, int>> neighbors{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, -1}, {-1, 1}};
    const auto old_hexagons = hexagons;
    for (auto x = x_min; x <= x_max; ++x)
    {
        for (auto y = y_min; y <= y_max; ++y)
        {
            auto black_count = std::count_if(
                neighbors.begin(), neighbors.end(),
                [&old_hexagons, x, y](auto &ngbr) {
                    return old_hexagons[x + ngbr.first][y + ngbr.second];
                });
            if ((old_hexagons[x][y] && (black_count == 0 || black_count > 2)) ||
                (!old_hexagons[x][y] && black_count == 2))
            {
                hexagons[x][y] = !old_hexagons[x][y];
            }
        }
    }
}

void Solve(std::istream &in, std::ostream &out)
{
    constexpr std::size_t FloorSize{150U};
    std::string input;
    std::regex direction_regex("nw|ne|sw|se|w|e");
    Hexagons hexagons(2 * FloorSize, std::vector<bool>(2 * FloorSize, false));
    std::size_t x_max{FloorSize}, x_min{FloorSize}, y_max{FloorSize},
        y_min{FloorSize};

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        auto direction_it =
            std::sregex_iterator(input.begin(), input.end(), direction_regex);
        std::size_t x{FloorSize}, y{FloorSize};
        for (auto it = direction_it; it != std::sregex_iterator(); ++it)
        {
            const auto direction = it->str();
            if (direction == "nw")
            {
                --y;
            }
            else if (direction == "sw")
            {
                --x;
                ++y;
            }
            else if (direction == "ne")
            {
                ++x;
                --y;
            }
            else if (direction == "se")
            {
                ++y;
            }
            else if (direction == "w")
            {
                --x;
            }
            else if (direction == "e")
            {
                ++x;
            }
        }
        hexagons[x][y] = !hexagons[x][y];
        x_min = std::min(x_min, x);
        y_min = std::min(y_min, y);
        x_max = std::max(x_max, x);
        y_max = std::max(y_max, y);
    }
    for (int i = 0; i < 100; ++i)
    {
        Turn(hexagons, --x_min, ++x_max, --y_min, ++y_max);
    }
    const auto hexagon_counter =
        [](long long sum, std::vector<bool> &hexagon_row) -> long long {
        return sum + std::count(hexagon_row.begin(), hexagon_row.end(), true);
    };
    out << std::accumulate(hexagons.begin(), hexagons.end(), 0, hexagon_counter)
        << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

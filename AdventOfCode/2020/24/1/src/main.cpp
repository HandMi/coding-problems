#include <iostream>
#include <map>
#include <regex>
#include <vector>

using Coordinates = std::pair<int, int>;
void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::regex direction_regex("nw|ne|sw|se|w|e");
    std::map<std::pair<int, int>, bool> hexagons;

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        auto direction_it =
            std::sregex_iterator(input.begin(), input.end(), direction_regex);
        Coordinates pos{};
        for (auto it = direction_it; it != std::sregex_iterator(); ++it)
        {
            const auto direction = it->str();
            if (direction == "nw")
            {
                --pos.second;
            }
            else if (direction == "sw")
            {
                --pos.first;
                ++pos.second;
            }
            else if (direction == "ne")
            {
                ++pos.first;
                --pos.second;
            }
            else if (direction == "se")
            {
                ++pos.second;
            }
            else if (direction == "w")
            {
                --pos.first;
            }
            else if (direction == "e")
            {
                ++pos.first;
            }
        }
        hexagons[pos] = !hexagons[pos];
    }
    out << std::count_if(hexagons.begin(), hexagons.end(),
                         [](auto &hexagon) -> bool { return hexagon.second; })
        << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

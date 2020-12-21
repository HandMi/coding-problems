#include <array>
#include <iostream>
#include <regex>
#include <vector>

struct Border
{
    std::string data;
    int neighbor{-1};
};

struct Tile
{
    std::array<std::string, 10> data;
    // clockwise borders
    std::array<Border, 4> borders;
};

void FillBorders(Tile &tile)
{
    for (int i = 0; i < 10; ++i)
    {
        tile.borders[0].data.push_back(tile.data[0][i]);
        tile.borders[1].data.push_back(tile.data[i][9]);
        tile.borders[2].data.push_back(tile.data[9][9 - i]);
        tile.borders[3].data.push_back(tile.data[9 - i][0]);
    }
};

bool IsCorner(const Tile &tile)
{
    int border_tile{0};
    for (const auto &border : tile.borders)
    {
        if (border.neighbor < 0)
        {
            ++border_tile;
        }
    }
    return border_tile > 1;
};

void CreateMap(std::map<int, Tile> &tiles)
{
    for (auto it1 = tiles.begin(); it1 != tiles.end(); ++it1)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (auto it2 = std::next(it1); it2 != tiles.end(); ++it2)
            {
                // Neighbor not found yet
                if (it1->second.borders[i].neighbor < 0)
                {
                    const std::string border1 = it1->second.borders[i].data;
                    for (int j = 0; j < 4; ++j)
                    {
                        const std::string border2 = it2->second.borders[j].data;
                        const std::string reversed2(border2.rbegin(),
                                                    border2.rend());
                        if (border1 == border2 || border1 == reversed2)
                        {
                            it2->second.borders[j].neighbor = it1->first;
                            it1->second.borders[i].neighbor = it2->first;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
};

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::map<int, Tile> tiles;
    long long result{1};

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        Tile new_tile;
        std::string id = std::regex_replace(
            input, std::regex("[^0-9]*([0-9]+).*"), std::string("$1"));
        for (auto &row : new_tile.data)
        {
            std::getline(in, row);
        }
        FillBorders(new_tile);
        tiles[std::stoi(id)] = new_tile;

        // Empty Line
        std::getline(in, input);
    }

    CreateMap(tiles);

    for (const auto &tile : tiles)
    {
        if (IsCorner(tile.second))
        {
            result *= tile.first;
        }
    }
    out << result << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

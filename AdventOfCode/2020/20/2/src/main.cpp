#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <regex>
#include <vector>

using Image = std::vector<std::string>;

struct Border
{
    std::string data;
    int neighbor{-1};
};

struct Tile
{
    std::array<std::string, 10U> data;
    // clockwise borders
    std::array<Border, 4> borders;
};

template <typename ContainerType> void Flip(ContainerType &data)
{
    ContainerType copy = data;
    for (int j = 0; j < data.size(); ++j)
    {
        for (int i = 0; i < data[j].size(); ++i)
        {
            data[j][i] = copy[j][data[j].size() - 1 - i];
        }
    }
}

// RotateLeft
template <typename ContainerType> void Rotate(ContainerType &data)
{
    ContainerType copy = data;
    for (int j = 0; j < data.size(); ++j)
    {
        for (int i = 0; i < data[j].size(); ++i)
        {
            data[j][i] = copy[i][data[i].size() - 1 - j];
        }
    }
}

void FlipTile(Tile &tile)
{
    Flip(tile.data);
    std::reverse(tile.borders[0].data.begin(), tile.borders[0].data.end());
    std::reverse(tile.borders[1].data.begin(), tile.borders[1].data.end());
    std::reverse(tile.borders[2].data.begin(), tile.borders[2].data.end());
    std::reverse(tile.borders[3].data.begin(), tile.borders[3].data.end());
    std::swap(tile.borders[1], tile.borders[3]);
}

void RotateTile(Tile &tile)
{
    Rotate(tile.data);
    auto temp = tile.borders[0];
    tile.borders[0] = tile.borders[1];
    tile.borders[1] = tile.borders[2];
    tile.borders[2] = tile.borders[3];
    tile.borders[3] = temp;
}

const std::array<std::function<void(Tile &)>, 7> tile_transformations{
    RotateTile, RotateTile, RotateTile, FlipTile,
    RotateTile, RotateTile, RotateTile};

const std::array<std::function<void(Image &)>, 7> image_transformations{
    Rotate<Image>, Rotate<Image>, Rotate<Image>, Flip<Image>,
    Rotate<Image>, Rotate<Image>, Rotate<Image>};

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

void Match(std::map<int, Tile> &tiles, Border border, int border_idx)
{
    auto tile_id = border.neighbor;
    std::reverse(border.data.begin(), border.data.end());
    for (const auto &transformation : tile_transformations)
    {
        if (border.data == tiles[tile_id].borders[border_idx].data)
        {
            break;
        }
        else
        {
            transformation(tiles[tile_id]);
        }
    }
}

void Expand(Image &image, std::map<int, Tile> &tiles, int tile_id, int row,
            int col)
{
    if (tile_id < 0 || image[row].size() > col)
    {
        return;
    }
    for (std::size_t i = 0; i < 8U; ++i)
    {
        // Cut off borders
        image[row + i].append(tiles[tile_id].data[i + 1].substr(1U, 8U));
    }
    if (tiles[tile_id].borders[2].neighbor > 0)
    {
        Match(tiles, tiles[tile_id].borders[2], 0);
        Expand(image, tiles, tiles[tile_id].borders[2].neighbor, row + 8U, col);
    }
    if (tiles[tile_id].borders[1].neighbor > 0)
    {
        Match(tiles, tiles[tile_id].borders[1], 3);
        Expand(image, tiles, tiles[tile_id].borders[1].neighbor, row, col + 8U);
    }
}

auto IsCorner(const Tile &tile) -> bool
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

void MatchBorders(std::map<int, Tile> &tiles)
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

auto SearchSeaMonsters(const Image &image) -> int
{
    int monster_count = 0;
    std::regex body_regex("#.{4}##.{4}##.{4}###");
    std::regex feet_regex("#..#..#..#..#..#");
    std::smatch body_match;
    for (std::size_t i = 1U; i < image.size() - 1; ++i)
    {
        auto image_row = image[i];
        std::size_t position = 0;
        while (std::regex_search(image_row, body_match, body_regex))
        {
            position += body_match.position();
            if ((image[i - 1][position + 18U] == '#') &&
                (std::regex_match(image[i + 1].substr(position + 1, 16U),
                                  feet_regex)))
            {
                ++monster_count;
            }
            image_row = image[i].substr(position + 1);
            ++position;
        }
    }
    return monster_count;
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

    MatchBorders(tiles);

    int start_tile;
    for (const auto &tile : tiles)
    {
        if (IsCorner(tile.second))
        {
            start_tile = tile.first;
            break;
        }
    }

    const std::size_t size = std::ceil(std::sqrt(tiles.size())) * 8U;

    Image image(size, "");

    for (const auto &transformation : tile_transformations)
    {
        if (tiles[start_tile].borders[0].neighbor ==
            tiles[start_tile].borders[3].neighbor)
        {
            break;
        }
        else
        {
            transformation(tiles[start_tile]);
        }
    }

    Expand(image, tiles, start_tile, 0, 0);

    int monster_count{0};
    int hash_count{0};
    for (const auto &row : image)
    {
        hash_count += std::count(row.begin(), row.end(), '#');
    }
    for (const auto &transform : image_transformations)
    {
        monster_count = SearchSeaMonsters(image);
        if (monster_count > 0)
        {
            break;
        }
        transform(image);
    }
    out << hash_count - monster_count * 15 << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

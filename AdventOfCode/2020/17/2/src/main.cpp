#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using Cubes = std::array<std::array<std::array<int, 21>, 21>, 21>;
using HyperCubes = std::array<Cubes, 21>;

inline bool InRange(int i) { return i >= 0 && i < 21; };

int Cycle(HyperCubes& cubes)
{
    int result = 0;
    auto old_cubes = cubes;
    for (std::size_t k = 0; k < cubes.size(); ++k)
    {
        for (std::size_t j = 0; j < cubes[k].size(); ++j)
        {
            for (std::size_t i = 0; i < cubes[k][j].size(); ++i)
            {
                for (std::size_t h = 0; h < cubes[k][j][i].size(); ++h)
                {
                    int count = 0;
                    for (int dk = -1; dk <= 1; ++dk)
                    {
                        for (int dj = -1; dj <= 1; ++dj)
                        {
                            for (int di = -1; di <= 1; ++di)
                            {
                                for (int dh = -1; dh <= 1; ++dh)
                                {
                                    if (InRange(h + dh) && InRange(i + di) &&
                                        InRange(j + dj) && InRange(k + dk))
                                    {
                                        if (old_cubes[h + dh][i + di][j + dj]
                                                     [k + dk])
                                        {
                                            ++count;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (old_cubes[h][i][j][k])
                    {
                        if (count == 3 || count == 4)
                        {
                            ++result;
                        }
                        else
                        {
                            cubes[h][i][j][k] = 0;
                        }
                    }
                    else
                    {
                        if (count == 3)
                        {
                            ++result;
                            cubes[h][i][j][k] = 1;
                        }
                    }
                }
            }
        }
    }
    return result;
}

void Solve(std::istream &in, std::ostream &out)
{
    HyperCubes cubes{};
    std::string input;
    int result;

    std::getline(in, input);
    int cycles = std::stoi(input);

    auto y{cycles}, z{cycles}, w{cycles};

    while (std::getline(in, input))
    {
        auto x{cycles};
        if (input.empty())
        {
            break;
        }
        for (const auto state : input)
        {
            if (state == '#')
            {
                cubes[w][z][y][x] = 1;
            }
            ++x;
        }
        ++y;
    }

    for (int i = 0; i < cycles; ++i)
    {
        result = Cycle(cubes);
        // out << std::endl;
        // for (const auto &slice : cubes[cycles])
        // {
        //     for (const auto cube : slice)
        //     {
        //         if (cube)
        //         {
        //             out << "#";
        //         }
        //         else
        //         {
        //             out << ".";
        //         }
        //     }
        //     out << std::endl;
        // }
        // out << std::endl;
    }

    out << result << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

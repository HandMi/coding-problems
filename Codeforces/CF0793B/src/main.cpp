#include <array>
#include <climits>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

bool FindTwoTurnPath(const std::vector<std::string> &map)
{
    int Si, Sj;
    int Ti, Tj;
    std::array<std::pair<int, int>, 4> directions{
        std::make_pair(1, 0), std::make_pair(-1, 0), std::make_pair(0, 1),
        std::make_pair(0, -1)};
    std::vector<std::vector<int>> max_turns(
        map.size(), std::vector<int>(map[0].size(), INT_MAX));

    for (std::size_t i = 0U; i < map.size(); ++i)
    {
        for (std::size_t j = 0U; j < map[i].size(); ++j)
        {
            if (map[i][j] == 'S')
            {
                Si = i;
                Sj = j;
            }
            else if (map[i][j] == 'T')
            {
                Ti = i;
                Tj = j;
            }
        }
    }
    std::deque<std::pair<int, int>> visited_nodes;
    max_turns[Si][Sj] = -1;
    visited_nodes.push_back(std::make_pair(Si, Sj));
    while (!visited_nodes.empty())
    {
        auto x_start = visited_nodes.front().first;
        auto y_start = visited_nodes.front().second;
        visited_nodes.pop_front();
        int turns = max_turns[x_start][y_start];
        for (const auto &direction : directions)
        {
            for (auto i = 1;; ++i)
            {
                int x = x_start + direction.first * i;
                int y = y_start + direction.second * i;
                if (x < 0 || y < 0 || x >= map.size() || y >= map[x].size() ||
                    max_turns[x][y] <= turns || map[x][y] == '*')
                {
                    break;
                }
                else if (max_turns[x][y] < 2)
                {
                    continue;
                }
                else if (max_turns[x][y] > 2)
                {
                    max_turns[x][y] = turns + 1;
                    if (turns < 2)
                    {
                        visited_nodes.push_back(std::make_pair(x, y));
                    }
                }
            }
        }
    }
    return max_turns[Ti][Tj] <= 2;
};

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    int m;
    in >> n;
    in >> m;
    std::vector<std::string> map(n, "");
    for (auto &line : map)
    {
        in >> line;
    }

    auto result = FindTwoTurnPath(map);
    if (result)
    {
        out << "YES";
    }
    else
    {
        out << "NO";
    }
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

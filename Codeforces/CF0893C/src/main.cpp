#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

struct Character
{
    std::uint64_t cost;
    std::vector<int> friends;
    bool visited;
};

void Solve(std::istream &in, std::ostream &out)
{
    int n, m;
    in >> n >> m;
    std::uint64_t cost{};

    std::vector<Character> characters(n, Character{});
    for (int i = 0; i < n; ++i)
    {
        in >> characters[i].cost;
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        in >> a >> b;
        characters[a - 1].friends.push_back(b - 1);
        characters[b - 1].friends.push_back(a - 1);
    }
    for (int i = 0; i < n; ++i)
    {
        if (!characters[i].visited)
        {
            std::stack<int> dfs;
            dfs.push(i);
            auto min_cost = characters[i].cost;
            while (!dfs.empty())
            {
                const auto c = dfs.top();
                characters[c].visited = true;
                min_cost = std::min(min_cost, characters[c].cost);
                dfs.pop();
                for (auto f : characters[c].friends)
                {
                    if (!characters[f].visited)
                    {
                        dfs.push(f);
                    }
                }
            }
            cost += min_cost;
        }
    }

    out << cost << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

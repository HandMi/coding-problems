#include <iostream>
#include <stack>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    in >> n;

    std::vector<std::pair<int, int>> pos(n, {0, 0});
    std::vector<bool> visited(n, false);
    int count{};
    for (int i = 0; i < n; ++i)
    {
        in >> pos[i].first;
        in >> pos[i].second;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            ++count;
            visited[i] = true;
            std::stack<int> dfs;
            dfs.push(i);
            while (!dfs.empty())
            {
                auto j = dfs.top();
                dfs.pop();
                for (int k = 0; k < n; ++k)
                {
                    if (!visited[k] && (pos[k].first == pos[j].first ||
                                        pos[k].second == pos[j].second))
                    {
                        visited[k] = true;
                        dfs.push(k);
                    }
                }
            }
        }
    }
    out << count - 1 << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

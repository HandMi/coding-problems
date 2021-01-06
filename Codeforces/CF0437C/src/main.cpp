#include <algorithm>
#include <iostream>
#include <vector>

struct Node
{
    int energy;
    std::vector<int> neighbors;
    bool visited;
};

void Solve(std::istream &in, std::ostream &out)
{
    int n, m;
    in >> n >> m;
    std::vector<Node> nodes(n + 1, Node{});
    std::vector<std::pair<int, int>> energy(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i)
    {
        in >> nodes[i].energy;
        energy[i].first = nodes[i].energy;
        energy[i].second = i;
    }
    std::sort(energy.rbegin(), energy.rend());
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        in >> a >> b;
        nodes[a].neighbors.push_back(b);
        nodes[b].neighbors.push_back(a);
    }
    int total_energy = 0;
    for (int i = 0; i < n; ++i)
    {
        auto idx = energy[i].second;
        for (const auto j : nodes[idx].neighbors)
        {
            if (!nodes[j].visited)
            {
                total_energy += nodes[j].energy;
            }
        }
        nodes[idx].visited = true;
    }
    out << total_energy << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

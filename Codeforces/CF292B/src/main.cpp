#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int GetDegreeOfTree(const std::vector<std::vector<int>> &tree)
{
    return (*std::max_element(
                tree.begin(), tree.end(),
                [](const std::vector<int> &a, const std::vector<int> &b) {
                    return a.size() < b.size();
                }))
        .size();
}
std::string FindTopology(const std::vector<std::vector<int>> &graph, int nodes,
                         int edges)
{
    const int degree = GetDegreeOfTree(graph);
    if (degree == 2)
    {
        if (nodes == edges)
        {
            return "ring topology";
        }
        else if (nodes == edges + 1)
        {
            return "bus topology";
        }
    }
    else if ((degree == edges) && (nodes == edges + 1))
    {
        return "star topology";
    }
    return "unknown topology";
}

int main()
{
    int n;
    int m;

    std::cin >> n;
    std::cin >> m;

    std::vector<std::vector<int>> graph(n, std::vector<int>{});

    for (auto i = 0U; i < m; ++i)
    {
        int a;
        int b;
        std::cin >> a;
        std::cin >> b;
        // zero based indexing
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    std::cout << FindTopology(graph, n, m);
    return 0;
}
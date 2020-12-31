#include <iostream>
#include <unordered_set>

void Solve(std::istream &in, std::ostream &out)
{
    int n, m;
    in >> n >> m;
    std::unordered_set<int> forbidden_edges;

    for (int i = 0; i < 2 * m; ++i)
    {
        int edge_node;
        in >> edge_node;
        forbidden_edges.insert(edge_node);
    }
    int center{};
    for (int i = 1; i <= n; ++i)
    {
        if (forbidden_edges.find(i) == forbidden_edges.end())
        {
            center = i;
            break;
        }
    }
    out << n - 1 << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        if (i != center)
        {
            out << center << " " << i << std::endl;
        }
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

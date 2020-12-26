#include <iostream>
#include <stack>
#include <vector>

struct Node
{
    bool cat;
    int cat_count;
    std::vector<int> vertices;
    bool visited;
};

void Solve(std::istream &in, std::ostream &out)
{
    int N, max_cats;
    in >> N >> max_cats;
    std::vector<Node> tree(N, Node{});
    std::stack<int> path;

    for (std::size_t i = 0; i < N; ++i)
    {
        in >> tree[i].cat;
    }

    for (std::size_t i = 0; i < N - 1; ++i)
    {
        int first, second;
        in >> first >> second;
        tree[first - 1].vertices.push_back(second - 1);
        tree[second - 1].vertices.push_back(first - 1);
    }

    path.push(0);
    int result{0};
    while (!path.empty())
    {
        auto node = path.top();
        path.pop();
        tree[node].visited = true;
        tree[node].cat_count = tree[node].cat ? tree[node].cat_count + 1 : 0;
        if (tree[node].cat_count <= max_cats)
        {
            result += tree[node].vertices.size() == 1 && node != 0;
            for (const auto vertex : tree[node].vertices)
            {
                if (!tree[vertex].visited)
                {
                    tree[vertex].cat_count = tree[node].cat_count;
                    path.push(vertex);
                }
            }
        }
    }
    out << result << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

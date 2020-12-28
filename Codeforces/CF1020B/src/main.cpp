#include <iostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    in >> n;

    std::vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        in >> p[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        std::vector<bool> hole(n + 1, false);
        int j = i;
        while (!hole[j])
        {
            hole[j] = true;
            j = p[j];
        }
        out << j << " ";
    }
    out << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

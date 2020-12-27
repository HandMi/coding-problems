#include <algorithm>
#include <iostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    int t;
    in >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        in >> n;
        std::vector<bool> princesses(n + 1, false);
        std::vector<bool> princes(n + 1, false);
        for (int p = 1; p <= n; ++p)
        {
            int k;
            in >> k;
            for (int j = 1; j <= k; ++j)
            {
                int g;
                in >> g;
                if (!princes[g] && !princesses[p])
                {
                    princesses[p] = true;
                    princes[g] = true;
                }
            }
        }
        const auto unmarried_princess =
            std::find(princesses.begin() + 1, princesses.end(), false);
        if (unmarried_princess != princesses.end())
        {
            out << "IMPROVE" << std::endl;
            const auto unmarried_prince =
                std::find(princes.begin() + 1, princes.end(), false);
            out << unmarried_princess - princesses.begin() << " "
                << unmarried_prince - princes.begin() << std::endl;
        }
        else
        {
            out << "OPTIMAL" << std::endl;
        }
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

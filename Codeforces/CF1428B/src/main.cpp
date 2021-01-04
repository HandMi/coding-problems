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
        std::string conveyor_belts;

        in >> n;
        in >> conveyor_belts;
        auto left =
            std::count(conveyor_belts.begin(), conveyor_belts.end(), '<');
        auto right =
            std::count(conveyor_belts.begin(), conveyor_belts.end(), '>');
        if (left == 0 || right == 0)
        {
            out << n << std::endl;
        }
        else
        {
            int off{};
            for (int j = 0; j < conveyor_belts.size(); ++j)
            {
                auto l = (j - 1 + n) % n;
                if (conveyor_belts[l] == '-' || conveyor_belts[j] == '-')
                {
                    ++off;
                }
            }
            out << off << std::endl;
        }
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

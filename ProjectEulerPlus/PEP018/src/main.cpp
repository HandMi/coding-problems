#include <iostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    int t;
    in >> t;
    std::vector<std::string> numbers;
    for (int i = 0; i < t; ++i)
    {
        int n;
        in >> n;
        std::vector<std::vector<int>> pyramid;
        for (int j = 1; j <= n; j++)
        {
            std::vector<int> row;
            for (int k = 0; k < j; ++k)
            {
                int num;
                in >> num;
                row.push_back(num);
            }
            pyramid.push_back(row);
        }
        for (int j = n - 2; j >= 0; --j)
        {
            for (int k = 0; k < j + 1; ++k)
            {
                pyramid[j][k] +=
                    std::max(pyramid[j + 1][k], pyramid[j + 1][k + 1]);
            }
        }

        out << pyramid[0][0] << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

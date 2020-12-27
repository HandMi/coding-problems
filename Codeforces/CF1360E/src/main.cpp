#include <iostream>
#include <vector>

std::string CheckSequence(const std::vector<std::string> &polygon)
{
    const int n = polygon.size();
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = n - 2; j >= 0; --j)
        {
            if (polygon[i][j] == '1' && polygon[i][j + 1] == '0' &&
                polygon[i + 1][j] == '0')
            {
                return "NO";
            }
        }
    }
    return "YES";
}

void Solve(std::istream &in, std::ostream &out)
{
    int t;
    in >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        in >> n;
        std::vector<std::string> polygon(n, "");
        for (auto &row : polygon)
        {
            in >> row;
        }
        out << CheckSequence(polygon) << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

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
        std::vector<int> a(n, 0);
        int score = 0;
        for (auto &num : a)
        {
            in >> num;
        }
        for (int j = n - 1; j >= 0; --j)
        {
            if (j + a[j] < n)
            {
                a[j] = a[j] + a[j + a[j]];
            }
            score = std::max(score, a[j]);
        }
        out << score << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

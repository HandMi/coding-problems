#include <iostream>
#include <vector>

auto Zeller(std::int64_t q, std::int64_t m, std::int64_t y) -> std::int64_t
{
    if (m < 3)
    {
        m += 12;
        --y;
    }
    return (q + (13 * (m + 1)) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

void Solve(std::istream &in, std::ostream &out)
{
    int t;
    in >> t;
    for (int i = 0; i < t; ++i)
    {
        std::int64_t Y1, M1, D1, Y2, M2, D2;
        int count{};
        in >> Y1 >> M1 >> D1;
        in >> Y2 >> M2 >> D2;
        auto diff = Y2 - Y1;
        Y1 = Y1 % 2800;
        Y2 = Y1 + diff;
        for (int y = Y1; y <= Y2; ++y)
        {
            for (int m = 1; m <= 12; ++m)
            {
                if ((Y1 < y || (m > M1 || (m == M1 && D1 == 1))) &&
                    (y < Y2 || m <= M2))
                {
                    if (Zeller(1, m, y) == 1)
                    {
                        ++count;
                    }
                }
            }
        }
        out << count << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

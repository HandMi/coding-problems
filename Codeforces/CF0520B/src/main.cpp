#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    int n, m;
    in >> n >> m;
    int count{};
    while (n < m)
    {
        if (m % 2 > 0)
        {
            ++m;
        }
        else
        {
            m /= 2;
        }
        ++count;
    }
    out << count + n - m;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

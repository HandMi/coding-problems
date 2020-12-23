#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    int n, t;
    in >> n >> t;

    int pos{1};
    int a;

    for (int i = 1; i < n; ++i)
    {
        in >> a;
        pos = pos == i ? pos + a : pos;
        if (pos == t)
        {
            out << "YES" << std::endl;
            break;
        }
        else if (pos > t)
        {
            out << "NO" << std::endl;
            break;
        }
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

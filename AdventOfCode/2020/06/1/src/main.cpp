#include <bitset>
#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    std::string boarding_pass;
    unsigned long result{0U};
    while (std::getline(in, boarding_pass))
    {
        if (boarding_pass.empty())
        {
            break;
        }
        std::bitset<7> row;
        std::bitset<3> col;
        for (int i = 0; i < 7; ++i)
        {
            if (boarding_pass[i] == 'B')
            {
                row.set(6U - i);
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            if (boarding_pass[7 + i] == 'R')
            {
                col.set(2U - i);
            }
        }
        result = std::max(result, row.to_ulong() * 8U + col.to_ulong());
    }
    out << result << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::vector<std::uint16_t> boarding_passes;
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        std::uint16_t boarding_pass{0U};
        for (int i = 0; i < 10; ++i)
        {
            boarding_pass <<= 1;
            if (input[i] == 'B' || input[i] == 'R')
            {
                boarding_pass += 1;
            }
        }
        boarding_passes.push_back(boarding_pass);
    }
    std::sort(boarding_passes.begin(), boarding_passes.end());
    for (std::size_t i = 1U; i < boarding_passes.size() - 1; ++i)
    {
        if (boarding_passes[i - 1] + 2 == boarding_passes[i])
        {
            out << boarding_passes[i - 1] + 1 << std::endl;
        }
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

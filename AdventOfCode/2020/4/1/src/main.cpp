#include <array>
#include <bitset>
#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    int valid_passport_count{0};
    const std::array<std::string, 7U> required_fields{
        "byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};
    std::bitset<7U> passport;

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        while (!input.empty())
        {
            for (std::size_t i = 0U; i < 7U; ++i)
            {
                if (!passport[i])
                {
                    if (input.find(required_fields[i]) != std::string::npos)
                    {
                        passport.set(i);
                    }
                }
            }
            std::getline(in, input);
        }
        if (passport.to_ulong() == 127U)
        {
            ++valid_passport_count;
        }
        passport.reset();
    }
    out << valid_passport_count << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

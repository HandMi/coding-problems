#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <map>

using Passport = std::map<std::string, std::string>;

auto CheckByr(const std::string &byr) -> bool
{
    const auto year = std::stoi(byr);
    return 1920 <= year && year <= 2002;
}

auto CheckIyr(const std::string &iyr) -> bool
{
    const auto year = std::stoi(iyr);
    return 2010 <= year && year <= 2020;
}

auto CheckEyr(const std::string &eyr) -> bool
{
    const auto year = std::stoi(eyr);
    return 2020 <= year && year <= 2030;
}

auto CheckHgt(const std::string &hgt) -> bool
{
    std::size_t pos = 0U;
    int value{0};
    while (isdigit(hgt[pos]))
    {
        value *= 10;
        value += hgt[pos] - '0';
        ++pos;
    }
    if (hgt.substr(pos) == "cm")
    {
        return 150 <= value && value <= 193;
    }
    else if (hgt.substr(pos) == "in")
    {
        return 59 <= value && value <= 76;
    }
    else
    {
        return false;
    }
}

auto CheckHcl(const std::string &hcl) -> bool
{
    if (hcl.length() != 7)
    {
        return false;
    }
    if (hcl[0] == '#')
    {
        bool check{true};
        for (std::size_t i = 1U; i < hcl.length(); ++i)
        {
            check = check && std::isalnum(hcl[i]);
        }
        return check;
    }
    return false;
}

auto CheckEcl(const std::string &ecl) -> bool
{
    static const std::array<std::string, 7U> valid_ecl{
        "amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    return std::find(valid_ecl.begin(), valid_ecl.end(), ecl) !=
           valid_ecl.end();
}

auto CheckPid(const std::string &pid) -> bool
{
    if (pid.length() != 9)
    {
        return false;
    }
    bool check{true};
    for (std::size_t i = 1U; i < pid.length(); ++i)
    {
        check = check && std::isdigit(pid[i]);
    }
    return check;
}

auto CheckPassport(Passport &passport) -> bool
{
    if (passport.size() < 7)
    {
        return false;
    }
    return CheckByr(passport["byr:"]) && CheckIyr(passport["iyr:"]) &&
           CheckEyr(passport["eyr:"]) && CheckHgt(passport["hgt:"]) &&
           CheckHcl(passport["hcl:"]) && CheckEcl(passport["ecl:"]) &&
           CheckPid(passport["pid:"]);
}

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    int valid_passport_count{0};
    Passport passport;

    const std::array<std::string, 7U> required_fields{
        "byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        Passport passport;
        while (!input.empty())
        {
            for (const auto &field : required_fields)
            {
                const auto field_pos = input.find(field);
                if (input.find(field) != std::string::npos)
                {
                    const auto field_end = input.find(' ', field_pos);
                    passport[field] = input.substr(field_pos + 4U,
                                                   field_end - field_pos - 4U);
                }
            }
            std::getline(in, input);
        }
        if (CheckPassport(passport))
        {
            ++valid_passport_count;
        }
    }
    out << valid_passport_count << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

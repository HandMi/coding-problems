#include <algorithm>
#include <iostream>
#include <unordered_set>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    int result{0};

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        const auto pos_low = input.find('-');
        const auto pos_high = input.find(' ');
        const auto pos_pwd = input.find(':') + 2;
        const int low = std::stoi(input.substr(0, pos_low)) - 1;
        const int high =
            std::stoi(input.substr(pos_low + 1, pos_high - pos_low - 1)) - 1;
        const auto rule = input[pos_high + 1];
        const auto pwd = input.substr(pos_pwd);
        const auto count = std::count(pwd.begin(), pwd.end(), rule);
        if (pwd.size() > low)
        {
            if (pwd.size() > high)
            {
                if ((pwd[low] == rule && pwd[high] != rule) ||
                    (pwd[low] != rule && pwd[high] == rule))
                {
                    ++result;
                }
            }
            else if (pwd[low] == rule)
            {
                ++result;
            }
        }
    }
    out << result << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

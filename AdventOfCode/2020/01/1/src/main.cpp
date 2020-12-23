#include <iostream>
#include <unordered_set>

void Solve(std::istream &in, std::ostream &out)
{
    std::unordered_set<int> entries;
    std::string input;

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        int num = std::stoi(input);
        if (entries.find(num) != entries.end())
        {
            out << num * (2020 - num) << std::endl;
            break;
        }
        else
        {
            entries.insert(2020 - num);
        }
    }
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

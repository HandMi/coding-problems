#include <iostream>
#include <unordered_set>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    std::unordered_set<int> targets;
    std::string input;
    std::vector<int> entries;

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        int num = std::stoi(input);
        targets.insert(num);
        entries.push_back(num);
    }

    for (auto it1 = entries.begin(); it1 != entries.end() - 1; ++it1)
    {
        for (auto it2 = it1 + 1; it2 != entries.end(); ++it2)
        {
            auto target = 2020 - *it1 - *it2;

            if ((*it1 != target) && (*it2 != target) &&
                (targets.find(target) != targets.end()))
            {
                out << *it1 * *it2 * target << std::endl;
                return;
            }
            else
            {
            }
        }
    }
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

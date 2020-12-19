#include <algorithm>
#include <iostream>
#include <vector>

int GetMaxDistance(const std::string commands, int n)
{
    std::vector<int> forwards(n + 1, -10000);
    std::vector<int> backwards(n + 1, -10000);
    forwards[0] = 0;
    // moving backwards initially is the same as considering the minimum
    backwards[0] = 0;
    for (const auto &command : commands)
    {
        if (command == 'F')
        {
            for (auto j = n; j > 0; --j)
            {
                forwards[j] = std::max(forwards[j] + 1, backwards[j - 1]);
                backwards[j] = std::max(backwards[j] - 1, forwards[j - 1]);
            }
            forwards[0] += 1;
            backwards[0] -= 1;
        }
        else
        {
            for (auto j = n; j > 0; --j)
            {
                auto current_forward = forwards[j];
                forwards[j] = std::max(backwards[j], forwards[j - 1] + 1);
                backwards[j] = std::max(current_forward, backwards[j - 1] - 1);
            }
            std::swap(forwards[0], backwards[0]);
        }
    }
    int result = 0;
    for (auto i = n % 2; i < n + 1; i += 2)
    {
        result = std::max(result, forwards[i]);
        result = std::max(result, backwards[i]);
    }
    return result;
};

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    std::string commands;
    in >> commands;
    in >> n;

    auto distance = GetMaxDistance(commands, n);

    out << distance;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}
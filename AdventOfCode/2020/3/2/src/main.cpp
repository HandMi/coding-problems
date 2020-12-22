#include <array>
#include <functional>
#include <iostream>
#include <numeric>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::array<long long, 5> tree_count{0, 0, 0, 0, 0};
    constexpr std::array<int, 5> step{1, 3, 5, 7, 1};
    std::array<std::size_t, 5> pos{0U, 0U, 0U, 0U, 0U};

    std::getline(in, input);
    const std::size_t N = input.length();
    int line_count = 0;

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        ++line_count;
        for (std::size_t i = 0U; i < 4; ++i)
        {
            pos[i] = (pos[i] + step[i]) % N;
            if (input[pos[i]] == '#')
            {
                ++tree_count[i];
            }
        }
        if (line_count % 2 == 0)
        {
            pos[4] = (pos[4] + step[4]) % N;
            if (input[pos[4]] == '#')
            {
                ++tree_count[4];
            }
        }
    }
    const auto result = std::accumulate(tree_count.begin(), tree_count.end(),
                                        1LL, std::multiplies<>());
    out << result << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

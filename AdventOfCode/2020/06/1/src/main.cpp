#include <algorithm>
#include <array>
#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::array<int, 26U> answers{};
    int result{};
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            result += 26 - std::count(answers.begin(), answers.end(), 0);
            answers.fill(0);
            continue;
        }
        std::for_each(input.begin(), input.end(),
                      [&answers](char c) { ++answers[c - 'a']; });
    }
    result += 26 - std::count(answers.begin(), answers.end(), 0);
    out << result << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

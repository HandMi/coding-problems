#include <algorithm>
#include <array>
#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::array<int, 26U> answers{};
    int result{0};
    int cnt{0};
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            result += std::count(answers.begin(), answers.end(), cnt);
            answers.fill(0);
            cnt = 0;
            continue;
        }
        std::for_each(input.begin(), input.end(),
                      [&answers](char c) { ++answers[c - 'a']; });
        ++cnt;
    }
    result += std::count(answers.begin(), answers.end(), cnt);
    out << result << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

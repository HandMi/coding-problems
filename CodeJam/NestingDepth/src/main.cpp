#include <iostream>

auto NestingDepth(std::string &input) -> std::string
{
    std::string output;
    input += '0';
    int depth = input[0] - '0';
    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = depth; j < 0; ++j)
        {
            output += ')';
        }
        for (int j = 0; j < depth; ++j)
        {
            output += '(';
        }
        output += input[i];
        depth = input[i + 1] - input[i];
    }
    output.pop_back();
    return output;
}

void Solve(std::istream &in, std::ostream &out)
{
    int T;
    in >> T;

    for (int t = 1; t <= T; ++t)
    {
        std::string input;
        in >> input;
        out << "Case #" << t << ": " << NestingDepth(input) << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

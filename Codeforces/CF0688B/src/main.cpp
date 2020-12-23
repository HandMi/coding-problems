#include <algorithm>
#include <iostream>
#include <string>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    in >> input;

    auto reverse = input;
    std::reverse(reverse.begin(), reverse.end());

    out << input + reverse;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

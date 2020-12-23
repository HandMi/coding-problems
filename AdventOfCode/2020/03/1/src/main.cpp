#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    int tree_count{0};
    std::size_t pos{0U};
    std::getline(in, input);
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        pos = (pos + 3) % input.length();
        if (input[pos] == '#')
        {
            ++tree_count;
        }
    }
    out << tree_count << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

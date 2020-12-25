#include <iostream>
#include <vector>

struct Command
{
    std::string cmd;
    int value;
    bool visited;
};

void Solve(std::istream &in, std::ostream &out)
{
    std::string cmd;
    int n;
    std::vector<Command> commands;

    while (in >> cmd)
    {
        in >> n;
        commands.push_back(Command{cmd, n, false});
    }
    int pos{}, acc{};

    while (pos < commands.size() && !commands[pos].visited)
    {
        commands[pos].visited = true;
        if (commands[pos].cmd == "jmp")
        {
            pos += commands[pos].value;
        }
        else if (commands[pos].cmd == "acc")
        {

            acc += commands[pos].value;
            ++pos;
        }
        else
        {
            ++pos;
        }
    }
    out << acc << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

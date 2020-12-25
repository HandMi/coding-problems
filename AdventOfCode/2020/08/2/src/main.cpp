#include <iostream>
#include <vector>

struct Command
{
    std::string cmd;
    int value;
    int acc;
    bool visited;
};

struct Handheld
{
    void Read(std::istream &in)
    {
        std::string cmd;
        int n;

        while (in >> cmd)
        {
            in >> n;
            commands.push_back(Command{cmd, n, false});
        }
    }
    void RunOnce(std::size_t &pos, int &acc)
    {
        log.push_back(pos);
        commands[pos].visited = true;
        commands[pos].acc = acc;
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

    auto Run() -> int
    {
        int acc{};
        std::size_t pos{};
        log.resize(0U);
        while (!commands[pos].visited)
        {
            RunOnce(pos, acc);
        }

        // Backtrack for nodes not visted yet
        for (auto it = log.rbegin(); it != log.rend(); ++it)
        {
            std::size_t pos = *it;
            if (commands[pos].cmd == "jmp")
            {
                int acc = commands[pos].acc;
                ++pos;

                while (!commands[pos].visited)
                {
                    if (pos >= commands.size())
                    {
                        return acc;
                    }
                    RunOnce(pos, acc);
                }
            }
        }
        return -1;
    }

    std::vector<Command> commands;
    std::vector<std::size_t> log;
};

void Solve(std::istream &in, std::ostream &out)
{
    Handheld handheld;

    handheld.Read(in);

    out << handheld.Run() << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

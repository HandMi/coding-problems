#include <algorithm>
#include <iostream>
#include <vector>

struct Instruction
{
    char action;
    int distance;
};

void Turn(int &dx, int &dy)
{
    int old_dx = dx;
    dx = -dy;
    dy = old_dx;
}

void Move(int &x, int &y, int distance, int dx, int dy)
{
    x += distance * dx;
    y += distance * dy;
};

int Distance(const std::vector<Instruction> &instructions)
{
    int x = 0;
    int y = 0;
    int x_wp = 10;
    int y_wp = 1;
    for (const auto &instruction : instructions)
    {
        if (instruction.action == 'F')
        {
            Move(x, y, instruction.distance, x_wp, y_wp);
        }
        else if (instruction.action == 'N')
        {
            Move(x_wp, y_wp, instruction.distance, 0, 1);
        }
        else if (instruction.action == 'S')
        {
            Move(x_wp, y_wp, instruction.distance, 0, -1);
        }
        else if (instruction.action == 'E')
        {
            Move(x_wp, y_wp, instruction.distance, 1, 0);
        }
        else if (instruction.action == 'W')
        {
            Move(x_wp, y_wp, instruction.distance, -1, 0);
        }
        else if (instruction.action == 'L')
        {
            for (auto i = 0U; i < instruction.distance / 90; ++i)
            {
                Turn(x_wp, y_wp);
            }
        }
        else if (instruction.action == 'R')
        {
            for (auto i = 0U; i < instruction.distance / 90; ++i)
            {
                Turn(y_wp, x_wp);
            }
        }
    }
    return std::abs(x) + std::abs(y);
};

void Solve(std::istream &in, std::ostream &out)
{
    std::string command;
    std::vector<Instruction> instructions;
    while (std::getline(in, command))
    {
        if (command.empty())
        {
            break;
        }
        Instruction instruction;
        instruction.action = command[0];
        instruction.distance = std::stoi(command.substr(1));
        instructions.push_back(instruction);
    }
    out << Distance(instructions);
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

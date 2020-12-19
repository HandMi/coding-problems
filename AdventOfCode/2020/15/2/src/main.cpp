#include <iostream>
#include <unordered_map>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    std::unordered_map<std::uint64_t, std::uint64_t> memory;
    std::string input;
    std::getline(in, input);

    std::unordered_map<int, int> numbers;
    int turn = 0;

    int pos = 0;
    int last_pos = 0;
    int num = 0;
    while (last_pos < input.length())
    {
        ++turn;
        pos = input.find(',', last_pos + 1);
        num = std::stoi(input.substr(last_pos, pos - last_pos));
        last_pos = pos + 1;
        numbers[num] = turn;
    }
    while (turn < 30000000)
    {
        ++turn;
        auto previous = numbers.find(num);
        if (previous != numbers.end())
        {
            num = turn - 1 - previous->second;
            if (num > 0)
            {
                previous->second = turn - 1;
            }
        }
        else
        {
            numbers[num] = turn - 1;
            num = 0;
        }
    }
    out << num;
};

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}
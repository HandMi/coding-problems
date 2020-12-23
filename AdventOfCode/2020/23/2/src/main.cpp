
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

constexpr int NUMBER_OF_CUPS = 1'000'000;
constexpr int NUMBER_OF_TURNS = 10'000'000;

auto turn(std::vector<int> &cups, int start) -> int
{
    int first_to_move = cups[start];
    int second_to_move = cups[first_to_move];
    int third_to_move = cups[second_to_move];
    cups[start] = cups[third_to_move];

    int dest = start - 1 ? start - 1 : cups.size() - 1;

    while (dest == first_to_move || dest == second_to_move ||
           dest == third_to_move)
    {
        dest = dest - 1 ? dest - 1 : cups.size() - 1;
    }

    // Relink
    cups[third_to_move] = cups[dest];
    cups[dest] = first_to_move;

    return cups[start];
}
void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::getline(in, input);

    // 1-based indices
    std::vector<int> cups(NUMBER_OF_CUPS + 1, 0);

    int first = input[0] - '0';
    int prev = first;
    int i = 1;
    // The idea is to use cups[i] to store the label of the cup following cup i,
    // effectively creating a simplified linked list
    for (; i < input.size(); ++i)
    {
        cups[prev] = input[i] - '0';
        prev = cups[prev];
    }
    ++i;
    for (; i < cups.size(); ++i)
    {
        cups[prev] = i;
        prev = i;
    }

    cups[prev] = first;
    for (int i = 0; i < NUMBER_OF_TURNS; ++i)
    {
        first = turn(cups, first);
    }

    out << static_cast<std::int64_t>(cups[1]) *
               static_cast<std::int64_t>(cups[cups[1]])
        << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

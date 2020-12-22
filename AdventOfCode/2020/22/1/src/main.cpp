
#include <deque>
#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::deque<int> deck1;
    std::deque<int> deck2;
    int result{0};

    // Player 1
    std::getline(in, input);
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        deck1.push_back(std::stoi(input));
    }

    // Player 2
    std::getline(in, input);
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        deck2.push_back(std::stoi(input));
    }

    while (!deck1.empty() && !deck2.empty())
    {
        if (deck1.front() > deck2.front())
        {
            deck1.push_back(deck1.front());
            deck1.push_back(deck2.front());
        }
        else
        {
            deck2.push_back(deck2.front());
            deck2.push_back(deck1.front());
        }
        deck1.pop_front();
        deck2.pop_front();
    }
    const auto &winner = deck1.empty() ? deck2 : deck1;

    std::size_t count = winner.size();
    for (auto card : winner)
    {
        result += count * card;
        --count;
    }
    out << result << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

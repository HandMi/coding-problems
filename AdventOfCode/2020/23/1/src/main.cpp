
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

// Cudos to https://stackoverflow.com/a/7533658
template <typename T>
void move_range(typename std::vector<T>::iterator start, size_t length,
                typename std::vector<T>::iterator dst, std::vector<T> &v)
{
    typename std::vector<T>::iterator first, middle, last;
    if (start < dst)
    {
        first = start;
        middle = first + length;
        last = dst;
    }
    else
    {
        first = dst;
        middle = start;
        last = middle + length;
    }
    std::rotate(first, middle, last);
}

constexpr auto mod(int a, int b) -> int { return (a % b + b) % b; }

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::getline(in, input);
    std::vector<int> cups;

    for (const auto cup : input)
    {
        cups.push_back(cup - '0');
    }
    const int N = cups.size();

    for (int i = 0; i < 100; ++i)
    {
        auto dest_label = cups[0];
        std::rotate(cups.begin(), cups.begin() + 1, cups.end());

        auto dest_it = cups.end();
        while (dest_it == cups.end())
        {
            // 1-based -1
            dest_label = mod(dest_label - 2, N) + 1;
            dest_it = std::find(cups.begin() + 3, cups.end(), dest_label);
        }
        move_range(cups.begin(), 3, dest_it + 1, cups);
    }

    while (cups[0] != 1)
    {
        std::rotate(cups.begin(), cups.begin() + 1, cups.end());
    }
    std::copy(cups.begin() + 1, cups.end(), std::ostream_iterator<int>(out));
    out << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

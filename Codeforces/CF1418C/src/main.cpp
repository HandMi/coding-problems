#include <iostream>
#include <vector>

int CalculateSkips(const std::vector<int> &bosses)
{
    int number_of_skips{0};
    // First Boss has to be skipped
    if (bosses[0] == 1)
    {
        number_of_skips = 1;
    }
    int consecutive_ones{0};
    // Only when there are three consecutive hard bosses we need to skip
    for (auto it = std::next(bosses.begin()); it != bosses.end(); ++it)
    {
        if (*it == 1)
        {
            ++consecutive_ones;
            if (consecutive_ones == 3)
            {
                ++number_of_skips;
                consecutive_ones = 0;
            }
        }
        else
        {
            consecutive_ones = 0;
        }
    }
    return number_of_skips;
};

int main()
{
    std::size_t number_of_tests;
    std::cin >> number_of_tests;
    std::vector<int> number_of_skips(number_of_tests, 0);

    for (auto i = 0U; i < number_of_tests; ++i)
    {
        int number_of_bosses;
        std::cin >> number_of_bosses;
        std::vector<int> bosses(number_of_bosses, 0);
        for (auto &boss : bosses)
        {
            std::cin >> boss;
        }
        number_of_skips[i] = CalculateSkips(bosses);
    }

    for (auto &result : number_of_skips)
    {
        std::cout << result << "\n";
    }

    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using HeroType = std::pair<int, int>;

struct less_than_pair_second
{
    bool operator()(const HeroType &lhs, const int &rhs)
    {
        return lhs.second < rhs;
    }
};

inline void FilterHeroes(std::vector<HeroType> &heroes)
{
    std::sort(heroes.begin(), heroes.end(), std::greater<HeroType>());
    std::vector<HeroType> filtered;
    filtered.reserve(heroes.size());
    auto max_power = 0;
    for (auto hero : heroes)
    {
        if (hero.second > max_power)
        {
            max_power = hero.second;
            filtered.push_back(hero);
        }
    }
    heroes = filtered;
}

int CalculateDaysInDungeon(const std::vector<HeroType> &heroes,
                           const std::vector<int> &monsters)
{
    int days{0};
    int steps = 0;
    auto it = heroes.begin();
    for (auto i = 0U; i < monsters.size();)
    {
        days++;
        steps = 0;
        it = heroes.begin();
        while (((*it).first > steps))
        {
            if (((*it).second >= monsters[i]))
            {
                steps += 1;
                i++;
            }
            else
            {
                it = std::lower_bound(it, heroes.end(), monsters[i],
                                      less_than_pair_second());
                if (it == heroes.end())
                {
                    if (steps == 0)
                    {
                        return -1;
                    }
                    break;
                }
            }
        }
    }
    return days;
}

int main()
{
    const auto test_cases = [&](int i) {
        return std::cin >> i, std::move(i);
    }({});
    std::vector<int> results(test_cases);
    std::vector<int> monsters;
    std::vector<HeroType> heroes;
    std::size_t number_of_monsters;
    std::size_t number_of_heroes;

    for (auto &result : results)
    {
        std::cin >> number_of_monsters;
        monsters.resize(number_of_monsters);
        for (auto &monster : monsters)
        {
            std::cin >> monster;
        }
        std::cin >> number_of_heroes;
        heroes.resize(number_of_heroes);
        for (auto &hero : heroes)
        {
            std::cin >> hero.second >> hero.first;
        }
        FilterHeroes(heroes);
        result = CalculateDaysInDungeon(heroes, monsters);
    }
    for (auto &result : results)
    {
        std::cout << result << "\n";
    }

    return 0;
}
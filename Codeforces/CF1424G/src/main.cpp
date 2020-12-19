#include <algorithm>
#include <iostream>
#include <vector>

std::pair<int, int> CalculateMaxOverlap(std::vector<int> &birth_years,
                                        std::vector<int> &death_years)
{
    std::sort(birth_years.begin(), birth_years.end());
    std::sort(death_years.begin(), death_years.end());
    int birth_i = 0;
    int death_i = 0;
    int alive = 0;
    int max_alive = 0;
    int max_year = 0;
    while (birth_i < birth_years.size())
    {
        auto next_birth = birth_years[birth_i];
        auto next_death = death_years[death_i];
        if (next_birth < next_death)
        {
            ++alive;
            ++birth_i;
            if (alive > max_alive)
            {
                max_alive = alive;
                max_year = next_birth;
            }
        }
        else
        {
            --alive;
            ++death_i;
        }
    }
    return {max_year, max_alive};
}

void Solve(std::istream &in, std::ostream &out)
{
    int t;
    in >> t;
    std::vector<int> birth_years(t, 0);
    std::vector<int> death_years(t, 0);
    for (auto i = 0U; i < t; ++i)
    {
        in >> birth_years[i];
        in >> death_years[i];
    }
    const auto result = CalculateMaxOverlap(birth_years, death_years);
    out << result.first << " " << result.second << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}


#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

struct City
{
    int distance{-1};
    std::unordered_set<int> neighbors;
};

void Solve(std::istream &in, std::ostream &out)
{
    int n, m;
    in >> n;
    in >> m;
    std::vector<City> railways(n + 1, City{});
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        in >> x >> y;
        railways[x].neighbors.insert(y);
        railways[y].neighbors.insert(x);
    }
    bool railway = railways[1].neighbors.find(n) == railways[1].neighbors.end();
    railways[1].distance = 0;
    std::queue<int> cities;
    cities.push(1);
    while (!cities.empty())
    {
        int i = cities.front();
        cities.pop();
        const auto dist = railways[i].distance + 1;
        if (railway)
        {
            for (const auto idx : railways[i].neighbors)
            {
                if (railways[idx].distance < 0)
                {
                    railways[idx].distance = dist;
                    cities.push(idx);
                }
            }
        }
        else
        {
            for (int j = 1; j <= n; ++j)
            {
                if ((railways[i].neighbors.find(j) ==
                     railways[i].neighbors.end()) &&
                    (j != i) && railways[j].distance < 0)
                {
                    railways[j].distance = dist;
                    cities.push(j);
                }
            }
        }
    }
    out << railways[n].distance;
}

auto main() -> int
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    Solve(std::cin, std::cout);
    return 0;
}

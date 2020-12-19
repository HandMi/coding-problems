#include "main.h"
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> subway_map(n, std::vector<int>{});

    for (auto i = 0U; i < n; ++i)
    {
        int a;
        int b;
        std::cin >> a;
        std::cin >> b;
        // zero based indexing
        subway_map[a - 1].push_back(b - 1);
        subway_map[b - 1].push_back(a - 1);
    }

    Subway subway(subway_map);
    const auto ringroad_distances = subway.GetDistancesFromRingroad();
    for (const auto distance : ringroad_distances)
    {
        std::cout << distance << std::endl;
    }

    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    int adapter;
    int diff1{}, diff3{};
    std::vector<int> adapters;
    adapters.push_back(0);
    while (in >> adapter)
    {
        adapters.push_back(adapter);
    }
    std::sort(adapters.begin(), adapters.end());
    adapters.push_back(adapters.back() + 3);
    for (std::size_t i = 1; i < adapters.size(); ++i)
    {
        diff1 += adapters[i] - adapters[i - 1] == 1 ? 1 : 0;
        diff3 += adapters[i] - adapters[i - 1] == 3 ? 1 : 0;
    }
    out << diff1 * diff3 << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

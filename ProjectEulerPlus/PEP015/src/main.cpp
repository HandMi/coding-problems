#include <iostream>
#include <main.h>
#include <vector>

auto main() -> int
{
    std::size_t t;
    std::cin >> t;

    std::vector<std::pair<int, int>> test_cases(t, {0, 0});
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case.first;
        std::cin >> test_case.second;
    }
    LatticePathCalculator lattice_path_calculator;
    lattice_path_calculator.CalculateLatticePaths(500, 500);
    for (auto &test_case : test_cases)
    {
        std::cout << lattice_path_calculator.GetLatticePath(test_case.first,
                                                            test_case.second)
                  << std::endl;
    }

    return 0;
}

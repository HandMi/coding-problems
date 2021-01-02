#ifndef MAIN_H
#define MAIN_H

#include <cstdint>
#include <vector>

struct LatticePathCalculator
{
    static constexpr std::uint32_t result_mod = 1000000007;
    void CalculateLatticePaths(std::uint32_t max_m, std::uint32_t max_n)
    {
        lattice_paths_ = std::vector<std::vector<std::int32_t>>(
            max_m + 1, std::vector<std::int32_t>(max_n + 1, 1));
        for (std::uint32_t i = 1; i <= max_m; ++i)
        {
            for (std::uint32_t j = 1; j <= max_m; ++j)
            {
                lattice_paths_[i][j] =
                    (lattice_paths_[i - 1][j] + lattice_paths_[i][j - 1]) %
                    result_mod;
            }
        }
    };
    auto GetLatticePath(std::uint32_t n, std::uint32_t m) -> std::uint32_t
    {
        return lattice_paths_[m][n];
    };
    std::vector<std::vector<std::int32_t>> lattice_paths_;
};

#endif

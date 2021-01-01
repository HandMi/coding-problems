#ifndef MAIN_H
#define MAIN_H

#include <algorithm>
#include <cstdint>
#include <stack>
#include <vector>

struct CollatzChains
{
    void ComputeCollatzChains(const std::uint64_t n_max)
    {
        chain_length.resize(n_max + 1, 0);
        max_index.resize(n_max + 1, 0);
        std::uint64_t max_length = 2;
        std::uint64_t max_idx = 2;
        for (std::uint64_t i = 1; i <= n_max; ++i)
        {
            if (chain_length[i] == 0)
            {
                std::uint64_t count = 0;
                std::stack<std::uint64_t> collatz;
                std::uint64_t n = i;
                collatz.push(n);
                while (collatz.top() != 1)
                {
                    n = n % 2 == 0 ? n / 2 : 3 * n + 1;
                    if (n < n_max && chain_length[n] != 0)
                    {
                        count = chain_length[n];
                        break;
                    }
                    collatz.push(n);
                }
                while (!collatz.empty())
                {
                    ++count;
                    if (collatz.top() < n_max)
                    {
                        chain_length[collatz.top()] = count;
                    }
                    collatz.pop();
                }
            }
            if (chain_length[i] >= max_length)
            {
                max_idx = i;
                max_length = chain_length[i];
            }
            max_index[i] = max_idx;
        }
    }

    auto LongestCollatz(std::uint64_t n) -> std::uint64_t
    {
        return max_index[n];
    }

    std::vector<std::uint64_t> chain_length{0, 1, 2};
    std::vector<std::uint64_t> max_index{0, 1, 2};
};

#endif

#include <iostream>
#include <vector>

int ArrayWalk(const std::vector<int> &scores, int k, int z)
{
    int result{};
    const int n = scores.size();
    for (int j = 0; j < z + 1; ++j)
    {
        int idx = k - 2 * j;
        if (idx < 0)
        {
            continue;
        }
        int sum{};
        int max_diff{};

        for (int i = 0; i < idx + 1; ++i)
        {
            if (i < n - 1)
            {
                max_diff = std::max(max_diff, scores[i] + scores[i + 1]);
            }
            sum += scores[i];

            result = std::max(result, sum + max_diff * j);
        }
    }
    return result;
}

void Solve(std::istream &in, std::ostream &out)
{
    int t;
    in >> t;

    for (int i = 0; i < t; ++i)
    {
        int n, k, z;
        in >> n >> k >> z;
        std::vector<int> scores(n, 0);
        for (auto &num : scores)
        {
            in >> num;
        }
        out << ArrayWalk(scores, k, z) << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

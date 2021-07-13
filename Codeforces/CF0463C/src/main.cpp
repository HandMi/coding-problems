
#include <iostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    in >> n;
    std::vector<std::vector<long long>> board(n, std::vector<long long>(n));
    std::vector<long long> diag(2 * n, 0);
    std::vector<long long> off_diag(2 * n, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            in >> board[i][j];
            diag[i + j] += board[i][j];
            off_diag[n + i - j] += board[i][j];
        }
    }
    long long max_even{-1};
    int i_even{};
    int j_even{};
    long long max_odd{-1};
    int i_odd{};
    int j_odd{};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            long long sum = diag[i + j] + off_diag[n + i - j] - board[i][j];
            if ((i + j) % 2 == 0)
            {
                if (sum > max_even)
                {
                    max_even = sum;
                    i_even = i;
                    j_even = j;
                }
            }
            else
            {
                if (sum > max_odd)
                {
                    max_odd = sum;
                    i_odd = i;
                    j_odd = j;
                }
            }
        }
    }
    out << max_even + max_odd << std::endl;
    out << i_even + 1 << " " << j_even + 1 << " " << i_odd + 1 << " "
        << j_odd + 1 << std::endl;
}

auto main() -> int
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    Solve(std::cin, std::cout);
    return 0;
}

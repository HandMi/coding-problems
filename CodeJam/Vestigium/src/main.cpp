#include <iostream>
#include <set>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

struct Solution
{
    int trace;
    int duplirows;
    int duplicols;
};

auto Vestigium(const Matrix &M) -> Solution
{
    Solution s{};
    for (std::size_t i = 0; i < M.size(); ++i)
    {
        s.trace += M[i][i];
        std::set<int> row;
        std::set<int> col;
        for (std::size_t j = 0; j < M.size(); ++j)
        {
            row.insert(M[i][j]);
            col.insert(M[j][i]);
        }
        s.duplirows = row.size() == M.size() ? s.duplirows : s.duplirows + 1;
        s.duplicols = col.size() == M.size() ? s.duplicols : s.duplicols + 1;
    }
    return s;
}

void Solve(std::istream &in, std::ostream &out)
{
    int T;
    in >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        in >> N;
        Matrix M(N, std::vector<int>(N, 0));
        for (auto &row : M)
        {
            for (auto &entry : row)
            {
                in >> entry;
            }
        }
        auto solution = Vestigium(M);
        out << "Case #" << t << ": " << solution.trace << " "
            << solution.duplirows << " " << solution.duplicols << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

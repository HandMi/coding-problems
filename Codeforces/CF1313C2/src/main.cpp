#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

class SegmentTree
{
    std::vector<std::pair<std::size_t, int>> segment_tree_;
    std::size_t n_;

    std::pair<std::size_t, int> construct(const std::vector<int> &values,
                                          const std::size_t segment_start,
                                          const std::size_t segment_end,
                                          const std::size_t node_index)
    {
        if (segment_end == segment_start)
        {
            segment_tree_[node_index] =
                std::make_pair(segment_start, values[segment_start]);
            return segment_tree_[node_index];
        }
        int segment_mid = segment_start + (segment_end - segment_start) / 2;
        const auto left =
            construct(values, segment_start, segment_mid, node_index * 2 + 1);
        const auto right =
            construct(values, segment_mid + 1, segment_end, node_index * 2 + 2);
        if (left.second <= right.second)
        {
            segment_tree_[node_index] = left;
        }
        else
        {
            segment_tree_[node_index] = right;
        }
        return segment_tree_[node_index];
    };

    std::pair<std::size_t, int> query(const std::size_t segment_start,
                                      const std::size_t segment_end,
                                      const std::size_t query_start,
                                      const std::size_t query_end,
                                      const std::size_t node_index) const
    {
        if ((query_start <= segment_start) && (query_end >= segment_end))
            return segment_tree_[node_index];
        if ((query_start > segment_end) || (query_end < segment_start))
            return std::make_pair(n_, INT_MAX);
        int segment_mid = segment_start + (segment_end - segment_start) / 2;
        const auto left = query(segment_start, segment_mid, query_start,
                                query_end, 2 * node_index + 1);
        const auto right = query(segment_mid + 1, segment_end, query_start,
                                 query_end, 2 * node_index + 2);
        if (left.second <= right.second)
        {
            return left;
        }
        else
        {
            return right;
        }
    };

  public:
    void construct(const std::vector<int> &values)
    {
        n_ = values.size();
        std::size_t max_size = 2 * pow(2, std::ceil(std::log2(n_))) - 1;
        segment_tree_ =
            std::vector<std::pair<std::size_t, int>>(max_size, {0U, 0});
        construct(values, 0U, n_ - 1, 0U);
    };

    std::pair<std::size_t, int> query(const std::size_t query_start,
                                      const std::size_t query_end) const
    {
        return query(0U, n_ - 1, query_start, query_end, 0U);
    };
};

long long ConstructSkyscrapers(const SegmentTree &segment_tree,
                               std::vector<int> &limits, const std::size_t i,
                               const std::size_t j)
{
    if (i == limits.size())
    {
        return 0;
    }
    if (i == j)
    {
        return 0;
    }
    if ((i + 1) == j)
    {
        return limits[i];
    }
    auto min = segment_tree.query(i, j - 1);
    auto left = ConstructSkyscrapers(segment_tree, limits, i, min.first) +
                (long long)min.second * (j - min.first);
    auto right = ConstructSkyscrapers(segment_tree, limits, min.first + 1, j) +
                 (long long)min.second * (min.first + 1 - i);
    const auto it_begin = limits.begin();
    if (left >= right)
    {
        std::fill(it_begin + min.first + 1, it_begin + j, min.second);
        return left;
    }
    else
    {
        std::fill(it_begin + i, it_begin + min.first, min.second);
        return right;
    }
}

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    in >> n;
    std::vector<int> limits(n, 0);
    for (auto &limit : limits)
    {
        in >> limit;
    }
    SegmentTree segment_tree;
    segment_tree.construct(limits);
    ConstructSkyscrapers(segment_tree, limits, 0U, limits.size());

    for (auto &limit : limits)
    {
        out << limit << " ";
    }
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

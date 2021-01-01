#include <iostream>
#include <map>

bool case_insensitive_cmp(char lhs, char rhs)
{
    return std::tolower(lhs) < std::tolower(rhs);
}

struct case_insensitive_string_cmp
{
    bool operator()(const std::string &lhs, const std::string &rhs) const
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                            rhs.end(), case_insensitive_cmp);
    }
};

void Solve(std::istream &in, std::ostream &out)
{
    int n;
    in >> n;

    int max_depth = 0;
    std::map<std::string, int, case_insensitive_string_cmp> reposts;
    reposts["polycarp"] = 1;
    for (int i = 0; i < n; ++i)
    {
        std::string key, reposted, repost;
        in >> key;
        in >> reposted;
        in >> repost;
        reposts[key] = reposts[repost] + 1;
        max_depth = std::max(max_depth, reposts[key]);
    }
    out << max_depth << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

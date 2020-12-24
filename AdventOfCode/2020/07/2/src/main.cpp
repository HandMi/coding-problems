#include <iostream>
#include <numeric>
#include <regex>
#include <unordered_map>
#include <vector>

struct BagContent
{
    std::string name;
    int capacity;
};

using Bag = std::vector<BagContent>;
using BagOfBags = std::unordered_map<std::string, Bag>;

auto CountBags(BagOfBags &bags, const std::string &key) -> int
{
    return bags[key].empty()
               ? 1
               : std::accumulate(bags[key].begin(), bags[key].end(), 0,
                                 [&bags, &key](int x, auto &content) -> int {
                                     return x +
                                            content.capacity *
                                                CountBags(bags, content.name);
                                 }) +
                     1;
}

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::regex bag_regex("(^|\\d )\\w+ \\w+");
    BagOfBags bags;

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        auto bag_it =
            std::sregex_iterator(input.begin(), input.end(), bag_regex);
        const std::string current_bag =
            bag_it != std::sregex_iterator() ? bag_it->str() : "";
        for (auto it = ++bag_it; it != std::sregex_iterator(); ++it)
        {
            bags[current_bag].push_back(
                BagContent{it->str().substr(2), it->str()[0] - '0'});
        }
    }
    out << CountBags(bags, "shiny gold") - 1 << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

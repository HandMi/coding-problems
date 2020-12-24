#include <iostream>
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

auto Search(BagOfBags &bags, const std::string &bag,
            const std::string &search_key) -> bool
{
    return bag == search_key ||
           std::any_of(bags[bag].begin(), bags[bag].end(),
                       [&bags, &search_key](auto &content) -> bool {
                           return Search(bags, content.name, search_key);
                       });
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
    out << std::count_if(bags.begin(), bags.end(),
                         [&bags](auto &bag) -> bool {
                             return Search(bags, bag.first, "shiny gold");
                         }) -
               1
        << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

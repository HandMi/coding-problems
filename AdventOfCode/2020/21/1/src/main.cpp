#include <algorithm>
#include <iostream>
#include <regex>
#include <set>
#include <vector>

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::map<std::string, std::set<std::string>> allergens;
    std::map<std::string, int> ingredients;

    const std::regex word_match("[a-z]{1,}");

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        auto separator = input.find('(');
        auto regex_it = std::sregex_iterator(
            input.begin(), input.begin() + separator, word_match);
        std::set<std::string> new_ingredients;
        for (auto it = regex_it; it != std::sregex_iterator(); ++it)
        {
            ++ingredients[(*it).str()];
            new_ingredients.insert((*it).str());
        }
        regex_it = std::sregex_iterator(input.begin() + separator + 9U,
                                        input.end(), word_match);
        for (auto it = regex_it; it != std::sregex_iterator(); ++it)
        {
            const auto allergen = (*it).str();
            if (allergens.find(allergen) == allergens.end())
            {
                allergens[allergen] = new_ingredients;
            }
            else
            {
                std::set<std::string> to_erase;
                for (auto &ingredient : allergens[allergen])
                {
                    if (new_ingredients.find(ingredient) ==
                        new_ingredients.end())
                    {
                        to_erase.insert(ingredient);
                    }
                }
                for (auto &ingredient : to_erase)
                {
                    allergens[allergen].erase(ingredient);
                }
            }
        }
    }

    int result{0};
    for (const auto &ingredient : ingredients)
    {
        if (std::find_if(allergens.begin(), allergens.end(),
                         [&ingredient](const auto allergen) {
                             return allergen.second.find(ingredient.first) !=
                                    allergen.second.end();
                         }) == allergens.end())
        {
            result += ingredient.second;
        }
    }

    out << result << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

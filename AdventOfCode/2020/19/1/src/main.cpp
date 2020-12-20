#include <iostream>
#include <regex>
#include <stack>
#include <vector>

std::string ExpandRule(std::map<std::string, std::string> &rules,
                       std::string key)
{
    if (isalpha(rules[key][0]))
    {
        return rules[key];
    }
    else
    {
        std::regex key_regex("[0-9]+");
        std::smatch key_match;
        while (std::regex_search(rules[key], key_match, key_regex))
        {
            auto replacement = ExpandRule(rules, key_match.str());
            if (replacement.size() > 1)
            {
                rules[key].replace(key_match.position(), key_match.length() + 1,
                                   "(" + ExpandRule(rules, key_match.str()) +
                                       ")");
            }
            else
            {
                rules[key].replace(key_match.position(), key_match.length() + 1,
                                   ExpandRule(rules, key_match.str()));
            }
        }
        return rules[key];
    }
}

void Solve(std::istream &in, std::ostream &out)
{
    std::regex rule_regex("[0-9]+|\\||[a-zA-Z]+");
    std::string input;
    std::map<std::string, std::string> rules;
    int result{};

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        std::string rule;
        auto regex_it =
            std::sregex_iterator(input.begin(), input.end(), rule_regex);
        if (regex_it != std::sregex_iterator())
        {
            auto rule_number = (*regex_it).str();
            for (auto it = ++regex_it; it != std::sregex_iterator(); ++it)
            {
                auto token = (*it).str();
                if (token == "|" || isalpha(token[0]))
                {
                    rule.append(token);
                }
                else
                {
                    rule.append((*it).str() + " ");
                }
            }
            rules[rule_number] = rule;
        }
    }

    ExpandRule(rules, "0");
    std::regex rule0_regex(rules["0"]);

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        std::smatch rule0_match;
        if (std::regex_match(input, rule0_match, rule0_regex))
        {
            ++result;
        }
    }
    out << result << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

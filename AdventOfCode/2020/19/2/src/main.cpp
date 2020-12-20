#include <iostream>
#include <regex>
#include <stack>
#include <vector>

static constexpr int MAX_RECURSION_LEVEL = 3;

struct Rule
{
    std::string rule;
    bool matched{false};
};

std::string ExpandRule(std::map<std::string, Rule> &rules, std::string key)
{
    if (rules[key].matched)
    {
        return rules[key].rule;
    }

    if (isalpha(rules[key].rule[0]))
    {
        rules[key].matched = true;
        return rules[key].rule;
    }
    else
    {
        std::regex key_regex("[0-9]+");
        std::smatch key_match;
        while (std::regex_search(rules[key].rule, key_match, key_regex))
        {
            if (key_match.str() != key)
            {
                auto replacement = ExpandRule(rules, key_match.str());
                if (replacement.size() > 1)
                {
                    rules[key].rule.replace(
                        key_match.position(), key_match.length() + 1,
                        "(" + ExpandRule(rules, key_match.str()) + ")");
                }
                else
                {
                    rules[key].rule.replace(key_match.position(),
                                            key_match.length() + 1,
                                            ExpandRule(rules, key_match.str()));
                }
            }
            else
            {
                std::regex self_key_regex(key);
                for (int i = 0; i < MAX_RECURSION_LEVEL; ++i)
                {
                    if (std::regex_search(rules[key].rule, key_match,
                                          self_key_regex))
                    {
                        rules[key].rule.replace(key_match.position(),
                                                key_match.length() + 1,
                                                "(" + rules[key].rule + ")");
                    }
                }
                if (std::regex_search(rules[key].rule, key_match,
                                      self_key_regex))
                {
                    rules[key].rule.replace(key_match.position(),
                                            key_match.length() + 1, "");
                }
            }
        }
        rules[key].matched = true;
        return rules[key].rule;
    }
}

void Solve(std::istream &in, std::ostream &out)
{
    std::regex rule_regex("[0-9]+|\\||[a-zA-Z]+");
    std::string input;
    std::map<std::string, Rule> rules;
    int result{};

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        std::string rule_string;
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
                    rule_string.append(token);
                }
                else
                {
                    rule_string.append((*it).str() + " ");
                }
            }
            rules[rule_number] = Rule{};
            rules[rule_number].rule = rule_string;
        }
    }

    ExpandRule(rules, "0");
    std::regex rule0_regex(rules["0"].rule);

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

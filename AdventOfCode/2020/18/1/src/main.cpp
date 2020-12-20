#include <iostream>
#include <regex>
#include <stack>

long Compute(const std::string &input)
{
    long result{};
    std::regex expression_regex("([0-9]+)|(\\+)|(\\*)|(\\()|(\\))");
    char last_operation = '+';
    std::stack<long> results;
    std::stack<char> operations;

    auto regex_it =
        std::sregex_iterator(input.begin(), input.end(), expression_regex);
    for (auto it = regex_it; it != std::sregex_iterator(); ++it)
    {
        auto operand = (*it).str();
        if (isdigit(operand[0]))
        {
            if (last_operation == '+')
            {
                result += std::stoi((*it).str());
            }
            else if (last_operation == '*')
            {
                result *= std::stoi((*it).str());
            }
        }
        else if (operand == "(")
        {
            results.push(result);
            operations.push(last_operation);
            result = 0;
            last_operation = '+';
        }
        else if (operand == ")")
        {
            last_operation = operations.top();
            auto last_result = results.top();
            if (last_operation == '+')
            {
                last_result += result;
            }
            else if (last_operation == '*')
            {
                last_result *= result;
            }
            result = last_result;
            operations.pop();
            results.pop();
        }
        else
        {
            last_operation = operand[0];
        }
    }
    return result;
}

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    long result{};

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        result += Compute(input);
    }
    out << result << std::endl;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

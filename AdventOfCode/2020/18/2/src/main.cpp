#include <iostream>
#include <regex>
#include <stack>

long Compute(const std::string &input)
{
    long result{};
    std::regex expression_regex("([0-9]+)|(\\+)|(\\*)|(\\()|(\\))");
    char last_operation = '+';
    std::stack<std::stack<long>> results{};
    std::stack<char> operations;
    auto top_stack = std::stack<long>();

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
                top_stack.push(result);
                result = std::stoi((*it).str());
            }
        }
        else if (operand == "(")
        {
            top_stack.push(result);
            results.push(top_stack);
            operations.push(last_operation);
            top_stack = std::stack<long>();
            result = 0;
            last_operation = '+';
        }
        else if (operand == ")")
        {
            while (!top_stack.empty())
            {
                result *= top_stack.top();
                top_stack.pop();
            }

            if (operations.top() == '+')
            {
                result += results.top().top();
                results.top().pop();
            }

            top_stack = results.top();
            operations.pop();
            results.pop();
        }
        else
        {
            last_operation = operand[0];
        }
    }
    while (!top_stack.empty())
    {
        result *= top_stack.top();
        top_stack.pop();
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

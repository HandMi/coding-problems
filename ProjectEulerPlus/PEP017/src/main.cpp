#include <iostream>
#include <main.h>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>

auto Hundreds(std::uint64_t number) -> std::vector<std::string>
{
    number = number % 1000;
    std::vector<std::string> result;
    static const std::vector<std::string> ones = {
        "Zero",    "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    static const std::vector<std::string> tens = {"Twenty", "Thirty", "Forty",
                                                  "Fifty",  "Sixty",  "Seventy",
                                                  "Eighty", "Ninety"};
    const auto hundreds = number / 100;
    number %= 100;
    if (hundreds > 0)
    {
        result.push_back(ones[hundreds]);
        result.push_back("Hundred");
    }
    if (number >= 20)
    {
        const auto ten = (number - 20) / 10;
        result.push_back(tens[ten]);
        number %= 10;
    }
    if (number > 0)
    {
        result.push_back(ones[number]);
    }
    return result;
}

auto NumberToWords(std::uint64_t number) -> std::string
{
    std::vector<std::vector<std::string>> result;
    if (number == 0)
    {
        return "Zero";
    }
    static const std::vector<std::string> thousands = {
        "", "Thousand ", "Million ", "Billion ", "Trillion "};
    while (number > 0)
    {
        auto res = number % 1000;
        result.push_back(Hundreds(res));
        number /= 1000;
    }
    std::string result_string;
    for (int i = result.size() - 1; i >= 0; --i)
    {
        for (const auto &number : result[i])
        {
            result_string += number + " ";
        }
        if (result[i].size() > 0)
        {
            result_string += thousands[i];
        }
    }
    return result_string.substr(0, result_string.length() - 1);
};

auto WordsToNumber(std::string &words) -> std::uint64_t
{
    std::uint64_t result = 0;
    static const std::map<std::string, std::uint64_t> ones = {
        {"Zero", 0},     {"One", 1},        {"Two", 2},       {"Three", 3},
        {"Four", 4},     {"Five", 5},       {"Six", 6},       {"Seven", 7},
        {"Eight", 8},    {"Nine", 9},       {"Ten", 10},      {"Eleven", 11},
        {"Twelve", 12},  {"Thirteen", 13},  {"Fourteen", 14}, {"Fifteen", 15},
        {"Sixteen", 16}, {"Seventeen", 17}, {"Eighteen", 18}, {"Nineteen", 19},
        {"Twenty", 20},  {"Thirty", 30},    {"Fourty", 40},   {"Fifty", 50},
        {"Sixty", 60},   {"Seventy", 70},   {"Eighty", 80},   {"Ninety", 90}};
    static const std::map<std::string, std::uint64_t> thousands = {
        {"Thousand", 1000}, {"Million", 1000000}, {"Billion", 1000000000}};
    std::istringstream iss(words);
    std::string word;
    std::uint64_t temp = 0;
    while (iss >> word)
    {
        if (ones.find(word) != ones.end())
        {
            temp += ones.at(word);
        }
        else if (thousands.find(word) != thousands.end())
        {
            temp *= thousands.at(word);
            result += temp;
            temp = 0;
        }
        else
        {
            temp *= 100;
        }
    }
    result += temp;

    return result;
}

auto main() -> int
{
    std::size_t t;
    std::cin >> t;

    std::vector<std::uint64_t> test_cases(t, 0);
    for (auto &test_case : test_cases)
    {
        std::cin >> test_case;
    }
    for (auto &test_case : test_cases)
    {
        std::cout << NumberToWords(test_case) << std::endl;
    }

    return 0;
}

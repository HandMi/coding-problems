#include <iostream>
#include <numeric>
#include <regex>
#include <vector>

struct Interval
{
    int low;
    int high;
};

void MergeIntervals(std::vector<Interval> &intervals)
{
    std::sort(intervals.begin(), intervals.end(),
              [](const Interval &a, const Interval &b) -> bool {
                  return a.low < b.low || (a.low == b.low && a.high < b.high);
              });
    std::vector<Interval> results{intervals[0]};
    auto j = 0U;
    for (auto i = 1U; i < intervals.size(); ++i)
    {
        if (intervals[i].low > results[j].high + 1)
        {
            results.push_back(intervals[i]);
            ++j;
        }
        else if (intervals[i].high > results[j].high)
        {
            results[j].high = intervals[i].high;
        }
    }
    intervals = results;
}

bool IsValid(const std::vector<Interval> &intervals, int ticket)
{
    auto matched_interval =
        std::lower_bound(intervals.begin(), intervals.end(), ticket,
                         [](const Interval &interval, int value) {
                             return value > interval.high;
                         });
    if (matched_interval == intervals.end() || ticket < (*matched_interval).low)
    {
        return false;
    }
    return true;
}

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::regex range_regex("[0-9]+-[0-9]+");
    std::regex ticket_regex("[0-9]+");
    std::vector<Interval> intervals;
    std::vector<int> invalid_tickets;

    // Read Intervals
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        auto range_it =
            std::sregex_iterator(input.begin(), input.end(), range_regex);
        for (auto i = range_it; i != std::sregex_iterator(); ++i)
        {
            auto range_string = (*i).str();
            auto delim_pos = range_string.find('-');
            int low = std::stoi(range_string.substr(0, delim_pos));
            int high = std::stoi(range_string.substr(delim_pos + 1));
            intervals.push_back({low, high});
        }
    }

    MergeIntervals(intervals);

    while (std::getline(in, input))
    {
        if (input == "exit")
        {
            break;
        }
        auto ticket_it =
            std::sregex_iterator(input.begin(), input.end(), ticket_regex);
        for (auto i = ticket_it; i != std::sregex_iterator(); ++i)
        {
            int ticket = std::stoi((*i).str());
            if (!IsValid(intervals, ticket))
            {
                invalid_tickets.push_back(ticket);
            };
        }
    }
    out << std::accumulate(invalid_tickets.begin(), invalid_tickets.end(), 0)
        << std::endl;
};

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

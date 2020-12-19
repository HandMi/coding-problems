#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <set>
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

bool IsValid(const std::vector<Interval> &intervals, int ticket_field)
{
    auto matched_interval =
        std::lower_bound(intervals.begin(), intervals.end(), ticket_field,
                         [](const Interval &interval, int value) {
                             return value > interval.high;
                         });
    if (matched_interval == intervals.end() ||
        ticket_field < (*matched_interval).low)
    {
        return false;
    }
    return true;
}

bool IsValid(const std::vector<Interval> &intervals, std::vector<int> ticket)
{
    bool valid = true;
    for (const auto field : ticket)
    {
        valid = valid && IsValid(intervals, field);
    }
    return valid;
}

bool IsPlausible(const std::vector<Interval> &intervals, int ticket)
{
    return (intervals[0].low <= ticket && ticket <= intervals[0].high) ||
           (intervals[1].low <= ticket && ticket <= intervals[1].high);
}

void CheckSingles(std::vector<std::set<int>> &field_sets,
                  std::map<int, int> &field_to_index_map)
{
    bool check_again{false};
    for (int i = 0; i < field_sets.size(); ++i)
    {
        if (field_sets[i].size() == 1)
        {
            check_again = true;
            int index = *(field_sets[i].begin());
            field_to_index_map[i] = index;
            for (auto &field_set : field_sets)
            {
                field_set.erase(index);
            }
        }
    }
    if (check_again)
    {
        CheckSingles(field_sets, field_to_index_map);
    }
};

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    std::regex range_regex("[0-9]+-[0-9]+");
    std::regex ticket_regex("[0-9]+");
    std::vector<std::vector<Interval>> filters;
    std::vector<Interval> merged_intervals;
    std::vector<int> my_ticket;
    std::map<int, int> field_to_index_map;
    int n;

    // number of fields to multiply
    std::getline(in, input);
    n = std::stoi(input);

    // Read Intervals
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        std::vector<Interval> intervals;
        auto range_it =
            std::sregex_iterator(input.begin(), input.end(), range_regex);
        for (auto i = range_it; i != std::sregex_iterator(); ++i)
        {
            auto range_string = (*i).str();
            auto delim_pos = range_string.find('-');
            int low = std::stoi(range_string.substr(0, delim_pos));
            int high = std::stoi(range_string.substr(delim_pos + 1));
            intervals.push_back({low, high});
            merged_intervals.push_back({low, high});
        }
        if (intervals.size() == 2)
        {
            filters.push_back(intervals);
        }
    }

    MergeIntervals(merged_intervals);

    // Empty Line
    std::getline(in, input);

    // Set up sets for potential associations
    std::set<int> field_index_set;
    int field_count = 0;
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        auto ticket_it =
            std::sregex_iterator(input.begin(), input.end(), ticket_regex);
        for (auto i = ticket_it; i != std::sregex_iterator(); ++i)
        {
            int field = std::stoi((*i).str());
            my_ticket.push_back(field);
            field_index_set.insert(field_count);
            ++field_count;
        }
    }
    std::vector<std::set<int>> field_index_sets(field_count, field_index_set);

    // Empty Line
    std::getline(in, input);

    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        std::vector<int> ticket;
        auto ticket_it =
            std::sregex_iterator(input.begin(), input.end(), ticket_regex);
        for (auto i = ticket_it; i != std::sregex_iterator(); ++i)
        {
            int field = std::stoi((*i).str());
            ticket.push_back(field);
        }
        if (ticket.size() != field_count)
        {
            out << "ERROR: ticket parsing failed" << std::endl;
        }
        if (IsValid(merged_intervals, ticket))
        {
            for (int i = 0; i < field_count; ++i)
            {
                std::vector<int> to_erase;
                for (auto field_index : field_index_sets[i])
                {
                    // Erase if contradicting Validity
                    if (!IsPlausible(filters[i], ticket[field_index]))
                    {
                        to_erase.push_back(field_index);
                    }
                }

                for (const auto field_index : to_erase)
                {
                    field_index_sets[i].erase(field_index);
                }
                if (to_erase.size() > 0)
                {
                    CheckSingles(field_index_sets, field_to_index_map);
                }
            }
        }
    }

    long long result = 1;
    for (int i = 0; i < n; ++i)
    {
        result *= my_ticket[field_to_index_map[i]];
    }
    out << result << std::endl;
};

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

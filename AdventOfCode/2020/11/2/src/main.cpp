#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using SeatPlan = std::vector<std::string>;

struct Direction
{
    int x;
    int y;
};

enum struct Occupancy
{
    kEmpty = 0,
    kTolerable,
    kOccupied
};

constexpr std::array<Direction, 8U> directions{
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

Occupancy CheckVisibility(const SeatPlan &seats, std::size_t i, std::size_t j)
{
    int count{0};
    for (const auto dir : directions)
    {
        auto x = i + dir.x;
        auto y = j + dir.y;
        while (x > 0 && y > 0 && x < seats.size() - 1 &&
               y < seats[x].size() - 1)
        {
            if (seats[x][y] == '#')
            {
                ++count;
                break;
            }
            else if (seats[x][y] == 'L')
            {
                break;
            }
            x += dir.x;
            y += dir.y;
        }
        if (count == 5)
        {
            return Occupancy::kOccupied;
        }
    }
    if (count > 0)
    {
        return Occupancy::kTolerable;
    }
    else
    {
        return Occupancy::kEmpty;
    }
};

bool SeatingSystem(SeatPlan &seats)
{
    bool changed{false};
    SeatPlan old_seats = seats;
    for (std::size_t i = 1U; i < seats.size() - 1; ++i)
    {
        for (std::size_t j = 1U; j < seats[i].size() - 1; ++j)
        {
            if (old_seats[i][j] == 'L' &&
                CheckVisibility(old_seats, i, j) == Occupancy::kEmpty)
            {
                changed = true;
                seats[i][j] = '#';
            }
            else if (old_seats[i][j] == '#' &&
                     CheckVisibility(old_seats, i, j) == Occupancy::kOccupied)
            {
                changed = true;
                seats[i][j] = 'L';
            }
        }
    }

    return changed;
};

void Solve(std::istream &in, std::ostream &out)
{
    SeatPlan seats;
    seats.push_back(".");
    std::string row;
    while (std::getline(in, row))
    {
        if (row.empty())
        {
            break;
        }
        seats.push_back('.' + row + '.');
    }
    seats[0] = std::string(seats[1].length(), '.');
    seats.push_back(std::string(seats[1].length(), '.'));

    bool changed = true;
    while (changed)
    {
        changed = SeatingSystem(seats);
    }
    int n = 0;
    for (const auto &row : seats)
    {
        n += std::count(row.begin(), row.end(), '#');
    }
    out << n << std::endl;
}

void SeatingTest(std::istream &in, std::ostream &out)
{
    SeatPlan seats;
    std::string row;
    while (std::getline(in, row))
    {
        seats.push_back(row);
    }

    SeatingSystem(seats);
    for (const auto &row : seats)
    {
        out << row << std::endl;
    }
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}
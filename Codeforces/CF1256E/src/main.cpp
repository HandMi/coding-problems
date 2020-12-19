#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using StudentType = std::pair<int, std::size_t>;

std::pair<long long, int> TeamComplexity(std::vector<StudentType> &students,
                                         std::vector<int> &id_to_team_map)
{
    auto number_of_students = students.size();
    std::vector<long long> complexity(number_of_students + 1, 2e+14);
    complexity[0] = 0;
    std::vector<int> team_size;
    team_size.resize(number_of_students + 1);
    id_to_team_map.resize(number_of_students);
    std::sort(students.begin(), students.end());

    for (std::size_t i = 0; i < number_of_students; i++)
    {
        for (auto j = 3; j <= 5; j++)
        {
            if (i + j <= number_of_students)
            {
                auto split_diff = complexity[i] + students[i + j - 1].first -
                                  students[i].first;
                if (split_diff < complexity[i + j])
                {
                    complexity[i + j] = split_diff;
                    team_size[i + j] = j;
                }
            }
        }
    }

    auto team = 1;
    int i = number_of_students - 1;
    while (i > 0)
    {
        for (int j = 0; j < team_size[i + 1]; j++)
        {
            id_to_team_map[students[i - j].second] = team;
        }
        i -= team_size[i + 1];
        team++;
    }

    return std::make_pair(complexity[number_of_students], team - 1);
}

int main()
{
    int number_of_students;
    std::cin >> number_of_students;
    std::vector<StudentType> students(number_of_students);
    std::vector<int> id_to_team_map;
    std::size_t index = 0;
    for (auto &student : students)
    {
        std::cin >> student.first;
        student.second = index;
        index++;
    }
    long long total_complexity = 0ll;
    int number_of_teams = 0;
    std::tie(total_complexity, number_of_teams) =
        TeamComplexity(students, id_to_team_map);

    std::cout << total_complexity << " " << number_of_teams << "\n";
    for (auto &id_to_team : id_to_team_map)
    {
        std::cout << id_to_team << " ";
    }

    return 0;
}
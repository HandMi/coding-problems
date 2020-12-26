#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct Task
{
    int id;
    int start;
    int end;
    char assignee;
};

auto AssignTasks(std::vector<Task> &tasks) -> std::string
{
    int cam_time{}, jam_time{};
    std::sort(tasks.begin(), tasks.end(),
              [](Task &a, Task &b) { return a.start < b.start; });
    for (auto &task : tasks)
    {
        if (cam_time <= task.start)
        {
            cam_time = task.end;
            task.assignee = 'C';
        }
        else if (jam_time <= task.start)
        {
            jam_time = task.end;
            task.assignee = 'J';
        }
        else
        {
            return "IMPOSSIBLE";
        }
    }
    std::sort(tasks.begin(), tasks.end(),
              [](Task &a, Task &b) { return a.id < b.id; });
    const auto answer =
        std::accumulate(tasks.begin(), tasks.end(), std::string(),
                        [](std::string &result, Task &task) -> std::string & {
                            return result += task.assignee;
                        });
    return answer;
}

void Solve(std::istream &in, std::ostream &out)
{
    int T;
    in >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        in >> N;
        std::vector<Task> tasks;
        for (int i = 0; i < N; ++i)
        {
            Task task;

            task.id = i;
            in >> task.start;
            in >> task.end;
            tasks.push_back(task);
        }

        out << "Case #" << t << ": " << AssignTasks(tasks) << std::endl;
    }
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}


#include <climits>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using Edge = std::pair<int, int>;
using Node = std::vector<std::pair<int, int>>;
using Graph = std::vector<Node>;
using Arrivals = std::vector<std::unordered_set<int>>;

int Dijkstra(const Graph &graph, const Arrivals &arrivals, int target)
{
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>
        edges_to_process;
    std::vector<long long> travel_time(graph.size(), LLONG_MAX);
    std::vector<int> root(graph.size(), 0);
    // add origin
    edges_to_process.push(std::make_pair(1, 0));
    travel_time[1] = 0;
    root[1] = 0;
    while (!edges_to_process.empty())
    {
        auto current_node = edges_to_process.top().first;
        if (current_node == target)
        {
            return travel_time[target];
        }
        // Plan for waiting time
        while (arrivals[current_node].find(travel_time[current_node]) !=
               arrivals[current_node].end())
        {
            ++travel_time[current_node];
        }
        edges_to_process.pop();
        for (const auto &edge : graph[current_node])
        {
            auto neighbor = edge.first;
            auto transfer_time = edge.second;
            auto total_travel_time = travel_time[current_node] + transfer_time;
            if (travel_time[neighbor] > total_travel_time)
            {
                travel_time[neighbor] = total_travel_time;
                root[neighbor] = current_node;
                edges_to_process.push(
                    std::make_pair(neighbor, travel_time[neighbor]));
            }
        }
    }
    return -1;
};

void Solve(std::istream &in, std::ostream &out)
{
    int n, m;
    in >> n;
    in >> m;
    Graph graph(n + 1, Node());
    std::vector<std::unordered_set<int>> arrivals(n + 1,
                                                  std::unordered_set<int>());
    for (int i = 0; i < m; ++i)
    {
        int p1, p2, transfer_time;
        in >> p1;
        in >> p2;
        in >> transfer_time;
        graph[p1].push_back(std::make_pair(p2, transfer_time));
        graph[p2].push_back(std::make_pair(p1, transfer_time));
    }
    for (int i = 1; i <= n; ++i)
    {
        int number_of_arrivals;
        in >> number_of_arrivals;
        for (int j = 0U; j < number_of_arrivals; ++j)
        {
            int arrival_time;
            in >> arrival_time;
            arrivals[i].insert(arrival_time);
        }
    }
    auto time = Dijkstra(graph, arrivals, n);
    out << time;
}

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}

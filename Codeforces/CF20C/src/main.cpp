
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using Edge = std::pair<int, int>;
using Node = std::vector<std::pair<int, int>>;
using Graph = std::vector<Node>;

std::stack<int> Dijkstra(const Graph& graph, int target) {
  std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>
      edges_to_process;
  std::vector<long long> distance(graph.size(), LLONG_MAX);
  std::vector<int> root(graph.size(), 0);
  std::stack<int> path;
  // add origin
  edges_to_process.push(std::make_pair(0, 1));
  distance[1] = 0;
  root[1] = 0;
  while (!edges_to_process.empty()) {
    auto current_node = edges_to_process.top().second;
    edges_to_process.pop();
    for (const auto& edge : graph[current_node]) {
      auto neighbor = edge.first;
      auto weight = edge.second;
      if (distance[neighbor] > distance[current_node] + weight) {
        // Updating distance of v
        distance[neighbor] = distance[current_node] + weight;
        root[neighbor] = current_node;
        edges_to_process.push(std::make_pair(distance[neighbor], neighbor));
      }
    }
    if (current_node == target) {
      while (root[current_node] > 0) {
        path.push(current_node);
        current_node = root[current_node];
      }
      path.push(1);

      return path;
    }
  }
  path.push(-1);
  return path;
};

void Solve(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n;
  in >> m;
  Graph graph(n + 1, Node());
  for (std::size_t i = 0U; i < m; ++i) {
    int v1, v2, weight;
    in >> v1;
    in >> v2;
    in >> weight;
    graph[v1].push_back(std::make_pair(v2, weight));
    graph[v2].push_back(std::make_pair(v1, weight));
  }
  auto path = Dijkstra(graph, n);
  while (!path.empty()) {
    out << path.top() << " ";
    path.pop();
  }
}

int main() {
  Solve(std::cin, std::cout);
  return 0;
}
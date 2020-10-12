#ifndef MAIN_H
#define MAIN_H

#include <algorithm>
#include <vector>

using Graph = std::vector<std::vector<int>>;

class Subway {
 public:
  Subway(const std::vector<std::vector<int>>& graph)
      : subway_map_{graph}, n_{graph.size()}, distances_(n_, 3001){};

  void FindNodesOnRingRoad() {
    std::vector<int> parents{};
    dfs_find_ring(0, -1, parents);
  }

  // Find all edges that haven't been used twice already
  std::vector<int> GetDistancesFromRingroad() {
    FindNodesOnRingRoad();
    for (auto i = 0U; i < distances_.size(); ++i) {
      if (distances_[i] > 3000) {
        dfs_distance_to_ring(i, -1);
      }
    }
    return distances_;
  }

 private:
  const std::vector<std::vector<int>> subway_map_;
  std::size_t n_;
  std::vector<int> distances_;

  bool dfs_find_ring(int node, int parent, std::vector<int>& parents) {
    parents.push_back(parent);
    if (std::find(parents.begin(), parents.end(), node) != parents.end()) {
      const auto occurence = std::find(parents.begin(), parents.end(), node);
      for (auto it = occurence; it != parents.end(); ++it) {
        distances_[*it] = 0;
      };
      return true;
    }
    for (auto& next_node : subway_map_[node]) {
      // exclude the node we come from
      if (next_node == parent) continue;
      if (dfs_find_ring(next_node, node, parents)) {
        return true;
      }
      parents.pop_back();
    }
    return false;
  }

  int dfs_distance_to_ring(int node, int parent) {
    if (distances_[node] == 0) {
      return 0;
    }
    for (auto& next_node : subway_map_[node]) {
      // exclude the node we come from
      if (next_node == parent) continue;
      distances_[node] =
          std::min(distances_[node], dfs_distance_to_ring(next_node, node) + 1);
    }
    return distances_[node];
  }
};

#endif
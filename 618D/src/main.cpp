#include <algorithm>
#include <iostream>
#include <vector>


bool dfs(const std::vector<std::vector<int>>& tree, int node, int parent,
         int& count) {
  int uses{2};
  for (auto& next_node : tree[node]) {
    // exclude the node we come from
    if (next_node == parent) continue;
    auto next_still_free = dfs(tree, next_node, node, count);
    if (next_still_free && (uses > 0)) {
      --uses;
      ++count;
    }
  }
  return uses > 0;
}

int GetDegreeOfTree(const std::vector<std::vector<int>>& tree) {
  return (*std::max_element(
              tree.begin(), tree.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                return a.size() < b.size();
              }))
      .size();
}

// Find all edges that haven't been used twice already
int CountUseableEdges(const std::vector<std::vector<int>>& tree) {
  int count{0};
  dfs(tree, 0, -1, count);
  return count;
}

int main() {
  long long result{0};

  int n;
  long long x;
  long long y;

  std::cin >> n;
  std::cin >> x;
  std::cin >> y;

  int degree{0};

  std::vector<std::vector<int>> spanning_tree(n, std::vector<int>{});

  for (auto i = 0U; i < n - 1; ++i) {
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    // zero based indexing
    spanning_tree[a - 1].push_back(b - 1);
    spanning_tree[b - 1].push_back(a - 1);
  }
  degree = GetDegreeOfTree(spanning_tree);
  if (x < y) {
    int useable_edges = CountUseableEdges(spanning_tree);
    result = (n - useable_edges - 1) * y + useable_edges * x;
  } else if (degree == (n - 1)) {
    result = (n - 2) * y + x;
  } else {
    result = (n - 1) * y;
  }
  std::cout << result;
  return 0;
}
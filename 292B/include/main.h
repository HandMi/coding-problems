#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>

using Graph = std::vector<std::vector<int>>;

std::string FindTopology(const Graph& graph, int nodes, int edges);

#endif
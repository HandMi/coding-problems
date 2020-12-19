#ifndef MAIN_H
#define MAIN_H

#include <vector>

using Tree = std::vector<std::vector<int>>;

int GetDegreeOfTree(const Tree &tree);

int CountUseableEdges(const Tree &tree);

#endif
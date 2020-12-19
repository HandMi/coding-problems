#ifndef MAIN_H
#define MAIN_H

#include <vector>

using GridType = std::vector<std::vector<int>>;
using DirectionType = std::vector<std::vector<char>>;

std::pair<int, int> CountFactors(int number);
int FindShortestWeightedPath(GridType &grid, DirectionType &directions);
std::string ReconstructPath(const DirectionType &directions);
std::string PathThroughZero(std::size_t dimension, std::size_t row);

#endif
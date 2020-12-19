#ifndef MAIN_H
#define MAIN_H

#include <vector>

using StudentType = std::pair<int, std::size_t>;

std::pair<long long, int> TeamComplexity(std::vector<StudentType> &students,
                                         std::vector<int> &id_to_team);

#endif

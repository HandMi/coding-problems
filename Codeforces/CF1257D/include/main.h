#ifndef MAIN_H
#define MAIN_H

#include <vector>

using HeroType = std::pair<int, int>;

void FilterHeroes(std::vector<HeroType> &heroes);
int CalculateDaysInDungeon(const std::vector<HeroType> &heroes,
                           const std::vector<int> &monsters);

#endif

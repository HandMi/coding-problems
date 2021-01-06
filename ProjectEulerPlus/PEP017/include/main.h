#ifndef MAIN_H
#define MAIN_H

#include <cstdint>
#include <string>

auto NumberToWords(std::uint64_t number) -> std::string;
auto WordsToNumber(std::string &words) -> std::uint64_t;

#endif

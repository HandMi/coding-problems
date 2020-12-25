#include <iostream>

void Solve(std::istream &in, std::ostream &out)
{
    constexpr std::uint64_t MAGIC_NUMBER = 20201227;
    constexpr std::uint64_t SUBJECT = 7;
    std::uint64_t card_public_key{}, card_loop_size{}, door_public_key{},
        key{1};
    in >> card_public_key;
    in >> door_public_key;

    while (key != card_public_key)
    {
        ++card_loop_size;
        key = (key * SUBJECT) % MAGIC_NUMBER;
    }
    key = 1;
    while (card_loop_size > 0)
    {
        --card_loop_size;
        key = (key * door_public_key) % MAGIC_NUMBER;
    }
    out << key << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

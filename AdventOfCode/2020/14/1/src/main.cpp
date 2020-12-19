#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

std::tuple<std::uint64_t, std::uint64_t> GetBitMask(const std::string bit_mask)
{
    std::uint64_t mask_one{0};
    std::uint64_t mask_zero{0};
    for (const auto bit : bit_mask)
    {
        mask_one <<= 1;
        mask_zero <<= 1;
        if (bit == '1')
        {
            ++mask_one;
        }
        if (bit != '0')
        {
            ++mask_zero;
        }
    }
    return std::make_tuple(mask_zero, mask_one);
};

void Solve(std::istream &in, std::ostream &out)
{
    std::unordered_map<std::uint64_t, std::uint64_t> memory;
    std::string line;
    std::string mem;
    std::uint64_t mask_one;
    std::uint64_t mask_zero;
    std::uint64_t result{0U};
    while (std::getline(in, line))
    {
        if (line.empty())
        {
            break;
        }
        const auto mask_pos = line.find("mask = ");
        if (mask_pos != std::string::npos)
        {
            std::string bit_mask = line.substr(7U);
            std::tie(mask_zero, mask_one) = GetBitMask(bit_mask);
        }
        else
        {
            const auto mem_pos = line.find("mem[");
            if (mem_pos != std::string::npos)
            {
                const auto end_pos = line.find("]");
                const auto address = std::stoull(line.substr(4, end_pos));
                auto value = std::stoull(line.substr(end_pos + 4));
                value &= mask_zero;
                value |= mask_one;
                memory[address] = value;
            }
        }
    }
    for (auto &mem : memory)
    {
        result += mem.second;
    }
    out << result;
};

int main()
{
    Solve(std::cin, std::cout);
    return 0;
}
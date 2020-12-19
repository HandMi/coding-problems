#include <bitset>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

std::tuple<std::uint64_t, std::vector<std::uint64_t>>
GetBitMask(const std::string bit_mask)
{
    std::uint64_t mask_one{0};
    std::vector<std::uint64_t> floating_bits;
    int i = 0;
    const int max_bit = bit_mask.length();
    for (const auto bit : bit_mask)
    {
        mask_one <<= 1;
        ++i;
        if (bit == '1')
        {
            ++mask_one;
        }
        if (bit == 'X')
        {
            floating_bits.push_back(1ULL << (max_bit - i));
        }
    }
    return std::make_tuple(mask_one, floating_bits);
};

void Solve(std::istream &in, std::ostream &out)
{
    std::unordered_map<std::uint64_t, std::uint64_t> memory;
    std::string line;
    std::string mem;
    std::uint64_t mask_one;
    std::vector<std::uint64_t> floating_bits;
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
            std::tie(mask_one, floating_bits) = GetBitMask(bit_mask);
        }
        else
        {
            const auto mem_pos = line.find("mem[");
            if (mem_pos != std::string::npos)
            {
                const auto end_pos = line.find("]");
                const auto address =
                    std::stoull(line.substr(4, end_pos)) | mask_one;
                auto value = std::stoull(line.substr(end_pos + 4));
                for (int i = 0; i < (1 << floating_bits.size()); ++i)
                {
                    auto masked_address = address;
                    std::bitset<36U> bit_set(i);
                    for (int j = 0; j < floating_bits.size(); ++j)
                    {
                        if (bit_set[j])
                        {
                            masked_address = masked_address | floating_bits[j];
                        }
                        else
                        {
                            masked_address = masked_address & ~floating_bits[j];
                        }
                    }
                    memory[masked_address] = value;
                }
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
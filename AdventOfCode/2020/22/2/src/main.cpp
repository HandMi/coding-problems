
#include <bitset>
#include <deque>
#include <iostream>
#include <set>

using CrabState = std::pair<std::deque<std::uint8_t>, std::deque<std::uint8_t>>;

struct Crab
{
    void Push(std::uint8_t n) { deck_.push_back(n); }

    auto Pop() -> std::uint8_t
    {
        auto n = deck_.front();
        deck_.pop_front();
        return n;
    }

    auto CountCards() const -> std::size_t { return deck_.size(); }
    auto HasCards() const -> bool { return !deck_.empty(); }

    auto Score() const -> int
    {
        int result{0};
        std::size_t count = deck_.size();
        for (auto card : deck_)
        {
            result += count * card;
            --count;
        }
        return result;
    }

    std::deque<std::uint8_t> deck_;
};

struct CrabCombat
{
    enum class Winner
    {
        kPlayerOneWon = 0,
        kPlayerTwoWon
    };

    void DealToCrab1(std::uint8_t n) { crab1_.Push(n); }
    void DealToCrab2(std::uint8_t n) { crab2_.Push(n); }

    auto CheckLoop() -> bool
    {
        const auto state = std::make_pair(crab1_.deck_, crab2_.deck_);
        if (previous_games_.find(state) != previous_games_.end())
        {
            return true;
        }
        else
        {
            previous_games_.insert(state);
        }
        return false;
    }

    auto Recurse() -> Winner
    {
        while (crab1_.HasCards() && crab2_.HasCards())
        {
            if (CheckLoop())
            {
                return Winner::kPlayerOneWon;
            }
            const auto card1 = crab1_.Pop();
            const auto card2 = crab2_.Pop();
            if (crab1_.CountCards() >= card1 && crab2_.CountCards() >= card2)
            {
                CrabCombat recursive_combat;
                for (int i = 0; i < card1; ++i)
                {
                    recursive_combat.DealToCrab1(crab1_.deck_[i]);
                }
                for (int i = 0; i < card2; ++i)
                {
                    recursive_combat.DealToCrab2(crab2_.deck_[i]);
                }

                const auto sub_winner = recursive_combat.Recurse();
                if (sub_winner == Winner::kPlayerOneWon)
                {
                    crab1_.Push(card1);
                    crab1_.Push(card2);
                }
                else
                {
                    crab2_.Push(card2);
                    crab2_.Push(card1);
                }
            }
            else if (card1 > card2)
            {
                crab1_.Push(card1);
                crab1_.Push(card2);
            }
            else
            {
                crab2_.Push(card2);
                crab2_.Push(card1);
            }
        }
        const auto &winner =
            crab1_.HasCards() ? Winner::kPlayerOneWon : Winner::kPlayerTwoWon;
        return winner;
    }

    auto Play() -> int
    {
        const auto &winner = Recurse();
        if (winner == Winner::kPlayerOneWon)
        {
            return crab1_.Score();
        }
        else
        {
            return crab2_.Score();
        }
    }

    Crab crab1_;
    Crab crab2_;
    std::set<CrabState> previous_games_;
};

void Solve(std::istream &in, std::ostream &out)
{
    std::string input;
    CrabCombat crab_combat;

    // Player 1
    std::getline(in, input);
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        crab_combat.DealToCrab1(std::stoi(input));
    }

    // Player 2
    std::getline(in, input);
    while (std::getline(in, input))
    {
        if (input.empty())
        {
            break;
        }
        crab_combat.DealToCrab2(std::stoi(input));
    }
    const auto result = crab_combat.Play();

    out << result << std::endl;
}

auto main() -> int
{
    Solve(std::cin, std::cout);
    return 0;
}

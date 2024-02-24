#include <array>
#include <string_view>
#include <iostream>
#include "../Random.h"

//  Question #2

namespace Potion {
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };

    constexpr std::array types { healing, mana, speed, invisibility }; // An array of our enumerators


    constexpr std::array<int, max_potions> prices { 20, 30, 12, 50 };
    constexpr std::array<std::string_view, max_potions> entrees { "healing", "mana", "speed", "invisibility" };

    static_assert(std::size(types) == max_potions);  // ensure 'all' contains the correct number of enumerators
    static_assert(std::size(prices) == max_potions);
    static_assert(std::size(entrees) == max_potions);
}

class Player {
public:
    explicit Player(std::string_view name) :
        m_name { name },
        m_gold { Random::get(80, 120) }
    {
    }

    [[nodiscard]] int gold() const { return m_gold; }
    [[nodiscard]] std::string_view name() const { return m_name; }
    [[nodiscard]] int inventory(Potion::Type t) { return m_inventory[t]; }

private:
    std::string_view m_name;
    int m_gold;
    std::array<int, Potion::max_potions> m_inventory {};
};

void process(Player& client) {
    while (true) {
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit:";
        char c {};
        std::cin >> c;

    }
}

void shop(Player& client) {
    std::cout << "\nHere is our selection for today:\n";
    for (auto p: Potion::types)
        std::cout << p << ") " << Potion::entrees[p] << " costs " << Potion::prices[p] << '\n';

    process(client);
}

int main() {
    std::cout << "Welcome to Roscoe's potion emporium!\n";

    std::cout << "Enter your name:";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    Player player { name };

    std::cout << "Hello, " << player.name() << " you have " << player.gold() << " gold.\n";

    shop(player);

    std::cout << "\nThanks for shopping at Roscoe's potion emporium!";

    return 0;
}
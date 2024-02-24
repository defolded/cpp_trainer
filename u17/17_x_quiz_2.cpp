#include <array>
#include <string_view>
#include <iostream>
#include "../Random.h"

//  Question #2

namespace Potion
{
    enum Type
    {
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

class Player
{
public:
    explicit Player(std::string_view name) :
        m_name { name },
        m_gold { Random::get(80, 120) }
    {
    }

    [[nodiscard]] int gold() const { return m_gold; }
    [[nodiscard]] std::string_view name() const { return m_name; }
    [[nodiscard]] int inventory(int t) { return m_inventory[t]; }

    bool buy(const Potion::Type item)
    {
        if (m_gold >= Potion::prices[item])
        {
            m_gold -= Potion::prices[item];
            ++m_inventory[item];
            return true;
        } else
        {
            std::cout << "You can not afford that.\n";
            return false;
        }
    }

private:
    std::string_view m_name;
    int m_gold;
    std::array<int, Potion::max_potions> m_inventory {};
};

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charNumToInt(char c)
{
    return c - '0';
}

void process(Player& client)
{
    char input{};
    while (true)
    {
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit:";
        std::cin >> input;
        if (!std::cin)
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            continue;
        }

        // If there is extraneous input, treat as failure case
        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cout << "I didn't understand what you said.  Try again.\n";
            ignoreLine(); // ignore any extraneous input
            continue;
        }

        if (input == 'q')
            break;

        // Convert the char to a number and see if it's a valid potion selection
        int val { charNumToInt(input) };
        if (val >= 0 && val < Potion::max_potions)
        {
            client.buy(static_cast<Potion::Type>(val));
            std::cout << "You purchased a potion of " << Potion::entrees[static_cast<Potion::Type>(val)] << ". You have " << client.gold() << " gold left.\n\n";
        } else
        {
            // It wasn't a valid potion selection
            std::cout << "I didn't understand what you said.  Try again.\n";
            ignoreLine();
        }
    }
}

void printInventory(Player& client)
{
    for (auto p: Potion::types)
    {
        if (client.inventory(p) > 0)
            std::cout << client.inventory(p) << "x potion of " << Potion::entrees[p] << '\n';
    }

    std::cout << "You escaped with " << client.gold() << " gold remaining.\n";
}

void shop(Player& client)
{
    std::cout << "\nHere is our selection for today:\n";
    for (auto p: Potion::types)
        std::cout << p << ") " << Potion::entrees[p] << " costs " << Potion::prices[p] << '\n';

    process(client);

    printInventory(client);
    std::cout << "\nThanks for shopping at Roscoe's potion emporium!";
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";

    std::cout << "Enter your name:";

    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    Player player { name };

    std::cout << "Hello, " << player.name() << " you have " << player.gold() << " gold.\n";

    shop(player);

    return 0;
}
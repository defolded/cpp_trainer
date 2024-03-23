#include "../Random.h"
#include <iostream>

namespace Potion
{
    enum PotionsType
    {
        regen,
        amplify,
        invisibility,
        poison,
        max_potions
    };

    constexpr std::array<int, max_potions> chanceToFind { 20, 30, 12, 50 };
    constexpr std::array<std::string_view, max_potions> potions { "Regen", "Amplify", "Invisibility", "Poison" };
}

namespace Enemy
{
    enum EnemyType
    {
        orc,
        mage,
        dragon,
        kung_fu_panda,
        max_enemies
    };

    constexpr std::array<int, max_enemies> chanceToFlee { 50, 40, 15, 5 };
    constexpr std::array<int, max_enemies> health { 5, 2, 10, 15 };
    constexpr std::array<int, max_enemies> damage { 1, 3, 5, 7 };
    constexpr std::array<std::string_view, max_enemies> enemies { "Orc", "Mage", "Dragon", "Kung Fu Panda" };
}

class Creature
{
protected:
    int m_health{};
    int m_damage_dealt{};

public:
    Creature(int health, int damage_dealt)
        : m_health{health}, m_damage_dealt{damage_dealt}
    {}

    [[nodiscard]] int getHp() const { return m_health; }
    [[nodiscard]] int getDmg() const { return m_damage_dealt; }

    void setHp(int n) { m_health = n; }
};

class Monster : public Creature
{
private:
    std::string m_name{};
    int m_flee_chance{};

public:
    explicit Monster(const int id)
        : Creature(Enemy::health.at(id), Enemy::damage.at(id)),
        m_name{Enemy::enemies.at(id)},
        m_flee_chance{Enemy::chanceToFlee.at(id)}
    {}

    [[nodiscard]] std::string_view getName() const { return m_name; }
    [[nodiscard]] int getFleeChance() const { return m_flee_chance; }
};

class Player : public Creature
{
private:
    int m_gold{};
    bool m_won{};
    bool m_lost{};
    std::vector<std::string_view> m_inventory{};
public:
    Player()
        : Creature(10, 3),
        m_gold{0}, m_won{false}, m_lost{false}
    {}

    [[nodiscard]] int getGold() const { return m_gold; }
    [[nodiscard]] bool getWon() const { return m_won; }
    [[nodiscard]] bool getLost() const { return m_lost; }
    std::vector<std::string_view>& getInventory() { return m_inventory; }
    std::string_view getInventory(int index) { return m_inventory.at(index); }

    void setGold(int g) { m_gold += g; }
    void setWon() { m_won = true; }
    void setLost() { m_lost = true; }

    void addItem(std::string_view item) { m_inventory.emplace_back(item); }
    void removeItem(int index) { m_inventory.erase(m_inventory.begin()+index); }
};

void findPotion(Player& player)
{
    int lucky_number{ Random::get(1, 100) };

    for (int i{0}; i < Potion::chanceToFind.size(); ++i)
    {
        if (lucky_number <= Potion::chanceToFind.at(i))
        {
            player.addItem(Potion::potions.at(i));
        }
    }

    for (auto p : player.getInventory())
        std::cout << "You've found " << p << " potion.\n";

}

void lose(Player& player) {
    std::cout << "You died with " << player.getGold() << " gold.\n";
    player.setLost();
}

void lose(const Monster& enemy, Player& player) {
    std::cout << "You killed " << enemy.getName() << "!\n\n";

    int goldReward{ Random::get(0,enemy.getFleeChance()) };

    std::cout << "You found " << goldReward << " gold.\n";
    player.setGold(goldReward);

    int h {Random::get(2, 3)};
    std::cout << "You've restored " << h << " hp.\n";
    player.setHp(player.getHp() + h);

    findPotion(player);
}

void hit(Monster& enemy, Player& player)
{
    player.setHp(player.getHp() - enemy.getDmg());
    std::cout << "You received " << enemy.getDmg() << " damage.\n";
}

void hit(Player& player, Monster& enemy)
{
    enemy.setHp(enemy.getHp() - player.getDmg());
    std::cout << "You hit " << enemy.getName() << " for " << player.getDmg() << " damage.\n";
}

void fight(Player& player, Monster& enemy)
{
    while (player.getHp() > 0 && enemy.getHp() > 0)
    {
        hit(player, enemy);
        hit(enemy, player);
    }

    if (player.getHp() < 1)
    {
        lose(player);
    }
    else if (enemy.getHp() < 1)
    {
        lose(enemy, player);
    }
}

bool run(Player& player, Monster& enemy)
{
    if (enemy.getFleeChance() < Random::get(1, 100))
    {
        std::cout << "You failed to flee.\n";
        hit(enemy, player);
        if (player.getHp() < 0)
        {
            lose(player);
            return false;
        }
        else
        {
            std::cout << "You have " << player.getHp() << " hp.\n\n";
            return false;
        }
    }
    else
    {
        std::cout << "You successfully fled.\n";
        return true;
    }
}

void gameloop(Player& player)
{
    bool condition{};

    while (!player.getWon() && !player.getLost()) {
        condition = true;
        char c{};

        Monster enemy = Monster(Random::get(0, (Enemy::EnemyType::max_enemies - 1)));
        std::cout << "\n\nYou've encountered " << enemy.getName() << ".\n";

        while (condition)
        {
            if (!player.getInventory().empty())
            {
                std::cout << "You have " << player.getInventory().size() << " potions, would you like to consume them? (type \"y\" or \"n\")\n";

                std::cin >> c;

                switch(c)
                {
                    case 'y':
                        std::cout << "Your potions are:\n";
                        for (int i{0}; i < player.getInventory().size(); ++i)
                        {
                            std::cout << "[" << i << "] " << player.getInventory(i) << '\n';
                        }
                        break;
                    case 'n':
                        continue;
                    default:
                        break;
                }
            }
            std::cout << "(R)un or (F)ight: ";
            std::cin >> c;

            switch (c)
            {
                case 'r':
                    if (run(player, enemy))
                    {
                        condition = false;
                    }
                    break;
                case 'f':
                    if (enemy.getName() == "Garfield")
                    {
                        lose(player);
                        condition = false;
                    } else {
                        fight(player, enemy);
                        condition = false;
                    }
                    break;
                default:
                    std::cin >> c;
                    break;
            }
        }

    }
}

int main()
{
//    std::cout << "Hello traveller. Here stands before you an impossible dungeon. Would you like to enter?\n";

    try
    {
        Player p1{};

        gameloop(p1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }

    return 0;
}
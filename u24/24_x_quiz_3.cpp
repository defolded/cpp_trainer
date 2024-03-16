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

    constexpr std::array types { regen, amplify, invisibility, poison };


    constexpr std::array<int, max_potions> chanceToFind { 20, 30, 12, 50 };
    constexpr std::array<std::string_view, max_potions> potions { "regen", "amplify", "invisibility", "poison" };
}

namespace Enemy
{
    enum EnemyType
    {
        orc,
        mage,
        dragon,
        garfield,
        kung_fu_panda,
        yana,
        max_enemies
    };

    constexpr std::array types { orc, mage, dragon, garfield, kung_fu_panda, yana };


    constexpr std::array<int, max_enemies> chanceToFlee { 50, 40, 15, 100, 5 };
    constexpr std::array<int, max_enemies> health { 5, 2, 10, 1, 15 };
    constexpr std::array<int, max_enemies> damage { 1, 3, 5, 0, 7 };
    constexpr std::array<std::string_view, max_enemies> enemies { "Orc", "Mage", "Dragon", "Garfield", "Kung Fu Panda" };
}

class Monster;

class Creature
{
protected:
    int m_health{};
    int m_damage_dealt{};
public:
    Creature(int health, int damage_dealt)
        : m_health{health}, m_damage_dealt{damage_dealt}
    {}

    int getHp() const { return m_health; }
    int getDmg() const { return m_damage_dealt; }

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
    {
    }

    std::string_view getName() const { return m_name; }
    int getFleeChance() const { return m_flee_chance; }
};

class Player : public Creature
{
private:
    int m_gold{};
public:
    Player()
        : Creature(10, 3),
        m_gold{0}
    {
    }

    int getGold() const { return m_gold; }

    void setGold(int g) { m_gold += g; }
};

void findPotion(Player& player)
{
    int lucky_number{ Random::get(1, 100) };
    std::cout << lucky_number;
    std::vector<std::string_view> inventory{};

    for (int i{0}; i < Potion::chanceToFind.size(); ++i)
    {
        for (auto n : Potion::chanceToFind)
        {
            if (lucky_number <= n)
            {
                inventory.emplace_back(Potion::potions.at(i));
            }
        }
    }

    for (auto p : inventory)
        std::cout << "You've found " << p << " potion.\n";
}

void lose(const Player& player) {
    std::cout << "You died with " << player.getGold() << " gold.\n";
}

void lose(const Monster& enemy, Player& player) {
    if (enemy.getName() == "Garfield")
    {
        std::cout << "mrrrr meow";
    } else {
        std::cout << "You killed " << enemy.getName() << "!\n";

        int goldReward{ Random::get(0,enemy.getFleeChance()) };

        std::cout << "You found " << goldReward << " gold.\n";
        player.setGold(goldReward);

        findPotion(player);
    }
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
    } else if (enemy.getHp() < 1) {
        lose(enemy, player);
    }
}

void run(Player& player, Monster& enemy)
{
    if (enemy.getFleeChance() < Random::get(1, 100))
    {
        std::cout << "You failed to flee.\n";
        hit(enemy, player);
        if (player.getHp() < 0)
        {
            lose(player);
        } else {
            // TODO: call Run or Fight if played fails to flee
            std::cout << "\n\n\n*NOT IMPLEMENTED*\n\n\n";
        }
    } else {
        std::cout << "You successfully fled.\n";
    }
}

void gameloop(Player& player)
{
    while (player.getHp() > 0) {
        Monster enemy = Monster(Random::get(0, (Enemy::EnemyType::max_enemies - 1)));
        std::cout << "You've encountered " << enemy.getName() << ".\n";
        std::cout << "(R)un or (F)ight: ";
        char c{};
        std::cin >> c;

        switch (c) {
            case 'r':
                run(player, enemy);
                break;
            case 'f':
                if (enemy.getName() == "Garfield")
                {
                    lose(player);
                } else {
                    fight(player, enemy);
                }
                break;
            default:
                std::cin >> c;
                break;
        }
    }
}

int main()
{
//    std::cout << "Hello traveller. Here stands before you an impossible dungeon. Would you like to enter?\n";

    Player p1{};

    gameloop(p1);

    return 0;
}
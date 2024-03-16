#include <string>
#include <utility>
#include <iostream>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};
public:
    Fruit(std::string name, std::string color)
        : m_name{std::move( name )}, m_color{std::move( color )}
    {}

    std::string& getName() { return m_name; }
    std::string& getColor() { return m_color; }
};

class Apple : public Fruit
{
public:
    explicit Apple(std::string color)
        : Fruit("apple", std::move(color))
    {}
};

class Banana : public Fruit
{
public:
    Banana()
        : Fruit("banana", "yellow")
    {}
};

int main()
{
    Apple a{ "red" };
    Banana b{};

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

    return 0;
}
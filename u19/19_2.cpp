#include <iostream>
#include <algorithm>

int main()
{
    std::cout << "How many names would you like to enter?";
    int num {};
    std::cin >> num;

    auto* names{ new std::string[num]{} };

    for (std::size_t i { 0 }; i < num; ++i)
    {
        std::cout << "Enter name #" << ( i + 1 ) << ":";
        std::string name{};
        std::getline(std::cin >> std::ws, names[i]);
    }

    std::sort(names, names + num);

    for (auto i { 0 }; i < num; ++i)
    {
        std::cout << names[i] << std::endl;
    }

    delete[] names;
    return 0;
}
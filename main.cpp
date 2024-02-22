#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Animal {
    enum Animals {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };
    struct Data {
        std::string_view name;
        int num_legs;
        std::string_view sound;
    };

    constexpr std::array types{chicken, dog, cat, elephant, duck, snake};
    constexpr std::array<Data, 6> zoo {{
        { "chicken",    2, "cluck" },
        { "dog",        4, "woof" },
        { "cat",        4, "meow" },
        { "elephant",   4, "pawoo" },
        { "duck",       2, "quack" },
        { "snake",      0, "hissss" },
    }};
}

// Teach operator>> how to input an Animal by name
// Consider this magic for now
// We pass color by non-const reference, so we can have the function modify its value
std::istream& operator>> (std::istream& in, Animal::Animals& animal)
{
    std::string input {};
    std::getline(in >> std::ws, input);

    // See if we can find a match
    for (std::size_t index=0; index < Animal::zoo.size(); ++index)
    {
        if (input == Animal::zoo[index].name)
        {
            animal = static_cast<Animal::Animals>(index);
            return in;
        }
    }

    // We didn't find a match, so input must have been invalid,
    // so we will set input stream to fail state
    in.setstate(std::ios_base::failbit);
    return in;
}

void printAnimalData(Animal::Animals type)
{
    const Animal::Data& animal { Animal::zoo[type] };
    std::cout << "A " << animal.name << " has " << animal.num_legs << " legs and says " << animal.sound << ".\n";
}

int main()
{
    Animal::Animals i_name{};

    std:: cout << "Please enter animal's name: ";
    std::cin >> i_name;

    // If users input didn't match
    if (!std::cin)
    {
        std::cin.clear();
        std::cout << "That animal couldn't be found.\n";
        i_name = Animal::max_animals; // set to invalid option so we don't match below
    }
    else
        printAnimalData(i_name);


    std::cout << "\nHere is the data for the rest of the animals:\n";
    for (auto a : Animal::types)
    {
        if (a != i_name)
            printAnimalData(a);
    }

    return 0;
}
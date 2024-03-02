#include <iostream>
#include <vector>
#include "../Random.h"

static std::vector<int> v{};
static int count{};
const int random = Random::get(2, 4);
static int guess{};

void generateNumbers()
{
    std::cout << "Start where?\n";
    int start{};
    std::cin >> start;

    std::cout << "How many?\n";
    std::cin >> count;

    for (int i { count }; i > 0; --i)
    {
        v.push_back( (start*start) * random );
        ++start;
    }

    std::cout << "I generated " << count << " square numbers. Do you know what each number is after multiplying it by " << random << " ?\n";
}

// Finds the value in @numbers that is closest to @guess.
int findClosestNumber()
{
    return *std::min_element(v.begin(), v.end(), [=](int a, int b) {
        return std::abs(a - guess) < std::abs(b - guess);
    });
}

bool getResults(int& num)
{
    auto val = std::find(v.begin(), v.end(), num);

    if (val != std::end(v)) {
        v.erase(val);
        if (v.empty())
        {
            std::cout << "Nice! You found all numbers, good job!\n";
            return false;
        } else {
            std::cout << "Nice! " << v.size() << " number(s) left.\n";
            return true;
        }
    } else {

        if (std::abs(findClosestNumber() - guess) <= 4)
        {
            std::cout << num << " is wrong! Try " << *std::find(v.begin(), v.end(), findClosestNumber()) << " next time.\n";
            return false;
        } else {
            std::cout << num << " is wrong!\n";
            return false;
        }
    }

}

int main()
{
    generateNumbers();

    do {
        std::cout << " > ";
        std::cin >> guess;

        if (!getResults(guess))
            break;

    } while (true);

    return 0;
}
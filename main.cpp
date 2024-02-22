#include <array>
#include <iostream>

int main()
{
    int numbers[] { 0, 1, 4, 9 };
    int x{0};

    while (true) {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> x;

        if (x == -1) {
            std::cout << "Bye\n";
            break;
        } else if (x < std::ssize(numbers)) {
            for (auto i{0}; i < std::ssize(numbers); ++i) {
                if (x == numbers[i]) {
                    std::cout << x << " is a perfect square\n";
                    break;
                } else {
                    std::cout << x << " is not a perfect square\n";
                    break;
                }
            }
        } else {
            std::cerr << "Error\n";
            return 1;
        }
    }

    return 0;
}
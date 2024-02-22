#include <array>
#include <iostream>

int main()
{
    constexpr int numbers[] { 0, 1, 4, 9 };

    while (true) {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        int x{};
        std::cin >> x;

        if (x == -1) {
            std::cout << "Bye\n";
            break;
        } else if (x <= numbers[std::ssize(numbers)-1]) {
            for (auto i : numbers) {
                if (x == i) {
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
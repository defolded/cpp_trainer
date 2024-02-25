#include <array>
#include <iostream>

//  Question 3

auto bubbleSort(auto numbers)
{
    for (int i { 0 }; (i < std::size(numbers) - 1); ++i)
    {
        for (int j { 0 }; (j < (std::size(numbers) - 1)); ++j)
        {
            if (numbers[j] > numbers[j + 1])
                std::swap(numbers[j], numbers[j + 1]);
        }
    }

    return numbers;
}

int main()
{
    std::array numbers { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    for (int i : numbers)
        std::cout << i << '\n';

    auto sortedNumbers = bubbleSort(numbers);

    std::cout << "\n\n\n";

    for (int i : sortedNumbers)
        std::cout << i << '\n';

    return 0;
};
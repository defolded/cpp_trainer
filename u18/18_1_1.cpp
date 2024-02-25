#include <array>
#include <iostream>

// Question 1

auto selectionSort(auto numbers)
{
    for (int i {0}; i < (std::size(numbers) - 1); ++i)
    {
        int lower { i };

        for (int j { i + 1 }; j < (std::size(numbers)); ++j)
        {
            if (numbers[lower] > numbers[j])
                lower = j;
        }

        std::swap(numbers[i], numbers[lower]);
    }

    return numbers;
}

int main()
{
    std::array numbers { 30, 60, 20, 50, 40, 10 };

    for (int i : numbers)
        std::cout << i << '\n';

    auto sortedNums = selectionSort(numbers);

    std::cout << "\n\n\n";

    for (int i : sortedNums)
        std::cout << i << '\n';

    return 0;
}
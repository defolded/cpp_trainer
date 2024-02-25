#include <array>
#include <iostream>

// Question 2

auto selectionSort(auto numbers)
{
    for (int i {0}; i < (std::size(numbers) - 1); ++i)
    {
        int higher { i };

        for (int j { i + 1 }; j < (std::size(numbers)); ++j)
        {
            if (numbers[higher] < numbers[j])
                higher = j;
        }

        std::swap(numbers[i], numbers[higher]);
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
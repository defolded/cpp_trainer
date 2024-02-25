#include <array>
#include <iostream>

//  Question 4

auto optimizedBubbleSort(auto numbers)
{
    int iterationCount { 0 };
    bool arrayChanged{ true };

    for (int i { 0 }; (i < std::size(numbers) - 1); ++i)
    {
        if (!arrayChanged)
            continue;

        arrayChanged = false;

        for (int j { 0 }; (j < (std::size(numbers) - i - 1)); ++j)
        {
            if (numbers[j] > numbers[j + 1])
            {
                std::swap(numbers[j], numbers[j + 1]);
                arrayChanged = true;
            }
        }
        ++iterationCount;
    }

    std::cout << "Early termination on iteration " << iterationCount << '\n';
    return numbers;
}

int main()
{
    std::array numbers { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    auto sortedNumbers = optimizedBubbleSort(numbers);

    for (int i : sortedNumbers)
        std::cout << i << ' ';

    return 0;
};
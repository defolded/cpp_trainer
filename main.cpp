#include <array>
#include <iostream>

template<typename T, std::size_t U>
void printArray(const std::array<T, U>& inputArray) {
    for (T val : inputArray) {
        std::cout << val;
    }
    std::cout << "\narray done\n";
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
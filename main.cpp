#include "my_array_implementation.h"
#include <iostream>

int main()
{
    GeniusArray<int> morocco { 1, 2, 3, 4, 5 };

    int i = morocco.binarySearchArr(5);
    std::cout << i << '\n';

    return 0;
}
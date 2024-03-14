#include "my_array_implementation.h"
#include <iostream>

int main()
{
    GeniusArray<int> morocco { 1, 2, 3, 4, 5 };

    for (int i { 0 }; i < morocco.length(); ++i)
        std::cout << morocco[i] << '\n';

    return 0;
}
#include "my_array_implementation.h"
#include <iostream>

int main()
{
    GeniusArray<int> morocco { 1, 4, 2, 8, 5 };

    morocco.bubbleSortArrDesc();
    morocco.print();

    return 0;
}
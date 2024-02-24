#include <iostream>

void printString(const char* s) {
    while (*s != '\0') {
        std::cout << *s;
        ++s;
    }
}

int main()
{
    printString("Hello World!");

    return 0;
}
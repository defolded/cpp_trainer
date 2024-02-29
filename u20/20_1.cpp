#include <iostream>
#include "vector"

int main()
{
    std::cout << "Please enter two ints(each on a new line) you want to perform operation on:\n";

    std::vector<int> store { };
    char operation {};

    for (int i { 0 }; i < 2; ++i)
    {
        int num{};
        std::cin >> num;
        store.push_back(num);
    }

    std::cout << "\nPlease enter the operation you would like to perform:\n";

    std::cin >> operation;

    std::cout << operation;

    return 0;
}
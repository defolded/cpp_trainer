#include <iostream>
#include <vector>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char c)
{
    switch (c)
    {
        case '+': return &add;
        case '-': return &subtract;
        case '*': return &multiply;
        case '/': return divide;
        default: return nullptr;
    }
}

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

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> operation;
    }
    while (operation!='+' && operation!='-' && operation!='*' && operation!='/');

    std::cout << operation;

    ArithmeticFunction res{getArithmeticFunction(operation)};
    if (res)
        std::cout << "\n\nResult is: " << res(store[0], store[1]);

    return 0;
}
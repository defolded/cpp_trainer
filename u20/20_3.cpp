#include <iostream>
#include <vector>
#include <cmath>

// Question 1

int factorial(int num)
{
    static int res{ 1 };

    if (num > 0)
    {
        res *= num;
        factorial(num-1);
    }

    return res;
}

// Question 2

int numSum(int num)
{
    if (num < 10) {
        return num;
    }

    return numSum(num / 10) + num % 10;
}

// Question 3

void printVector(const std::vector<int>& v)
{
    if (!v.empty())
    {
        for (auto i : v)
            std::cout << i;
    } else {
        std::cout << "0";
    }
}

int convertBinary(int num)
{
    num = std::abs(num);
    static std::vector<int> converted{};

    if (num == 0) {
        printVector(converted);
        return num;
    }

    auto operation = std::div(num, 2);
    converted.insert(converted.begin(), operation.rem);
    convertBinary(operation.quot);
}

int main()
{
//    Question 1
//    std::cout << factorial(5);

//    Question 2
//    std::cout << '\n' << numSum(93427);

//    Question 3
    std::cout << "Enter your integer:";
    int number {};
    std::cin >> number;

    convertBinary(number);

    return 0;
}
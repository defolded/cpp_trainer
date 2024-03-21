#include <iostream>

template <typename T, typename D>
class Pair
{
private:
    T first_val {};
    D second_val {};
public:
    Pair(T val1, D val2)
            : first_val{ val1 }, second_val{ val2 }
    {}

    const T& first() const { return first_val; }
    T& first() { return first_val; }

    const D& second() const { return second_val; }
    D& second() { return second_val; }
};

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(std::string_view s, T v)
        : Pair<std::string, T>(static_cast<std::string>(s), v)
    {}
};

int main()
{
    StringValuePair<int> svp { "Hello", 5 };
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
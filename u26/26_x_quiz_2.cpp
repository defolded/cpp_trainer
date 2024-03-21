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

int main()
{
    Pair<int, double> p1 { 5, 6.7 };
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2 { 2.3, 4 };
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
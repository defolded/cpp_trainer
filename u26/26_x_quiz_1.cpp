#include <iostream>

template <typename T>
class Pair1
{
private:
    T first_val{};
    T second_val{};
public:
    Pair1(const T val1, const T val2)
    : first_val{ val1 }, second_val{ val2 }
    {
    }

    const T& first() const { return first_val; }
    T& first() { return first_val; }

    const T& second() const { return second_val; }
    T& second() { return second_val; }

    friend std::ostream& operator<<(std::ostream& out, const Pair1& p)
    {
        out << "Pair: " << p.first_val << p.second_val;

        return out;
    }
};

int main()
{
    Pair1<int> p1 { 5, 8 };
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2 { 2.3, 4.5 };
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
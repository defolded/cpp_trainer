#include <iostream>

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};
public:
    explicit Fraction(int n = 0, int d = 1)
        : m_numerator{n}, m_denominator{d}
    {
        if (m_denominator == 0)
            throw std::runtime_error("Can't be zero.");

    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
    {
        out << f.m_numerator << '/' << f.m_denominator;

        return out;
    }
};

int main()
{
    int numerator{};
    int denominator{};

    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;

    try
    {
        Fraction f{ numerator, denominator };
        std::cout << "Your fraction is: " << f;
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
    }

    return 0;
}
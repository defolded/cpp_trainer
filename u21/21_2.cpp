#include <iostream>

class Fraction {
public:
    Fraction(const int n, const int d) :
        m_numerator { n }, m_denominator { d }
    {}

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(int value, const Fraction& f1);
    friend Fraction operator*(const Fraction& f1, int value);

    [[nodiscard]] int getNumerator() const { return m_numerator; }
    [[nodiscard]] int getDenominator() const { return m_denominator; }
private:
    int m_numerator{};
    int m_denominator{};
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, const int value)
{
    return { f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(const int value, const Fraction& f1)
{
    return { value * f1.m_numerator, f1.m_denominator };
}

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    return 0;
}
#include <vector>
#include <iostream>

class Point
{
protected:
    int m_x{};
    int m_y{};

public:
    explicit Point(int x = 0, int y = 0)
        : m_x{x}, m_y{y}
    {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        return out << "Point(" << p.m_x << ", " << p.m_y << ')';
    }
};

class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& sh)
    {
        return sh.print(out);
    }

    virtual ~Shape() = default;
};

class Triangle : public Shape
{
protected:
    Point m_one{};
    Point m_two{};
    Point m_three{};

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : m_one{p1}, m_two{p2}, m_three{p3}
    {}

    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_one << ", " << m_two << ", " << m_three << ")";

        return out;
    }
};

class Circle : public Shape
{
protected:
    Point m_point{};
    int m_radius{};

public:
    Circle(const Point &p, int r)
            : m_point{p}, m_radius{r} {}

    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_point << " , radius " << m_radius << ")";

        return out;
    }

    int getRadius() const { return m_radius; }
};

int getLargestRadius(const std::vector<Shape*>& v)
{
    int largestIndex{};

    for (const auto* sh : v)
    {
        if (const auto * c{ dynamic_cast<const Circle*>(sh) })
        {
            largestIndex = std::max(largestIndex, c->getRadius());
        }
    }

    return largestIndex;
}

int main()
{
    std::vector<Shape*> v{
            new Circle{Point{ 1, 2 }, 7},
            new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
            new Circle{Point{ 7, 8 }, 3}
    };

    // print each shape in vector v on its own line here
    for (const auto* sh : v)
        std::cout << *sh << "\n";

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    // delete each element in the vector here
    for (const auto* sh : v)
        delete sh;

    return 0;
}
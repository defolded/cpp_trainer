#include <iostream>
#include <vector>

//class TimeEntry
//{
//private:
//    uint8_t m_number {};
//    uint8_t m_fraction {};
//
//public:
//    TimeEntry() = default;
//
//    friend std::ostream& operator<< (std::ostream& out, const TimeEntry& fr)
//    {
//        out << fr.m_number << '.' << fr.m_fraction;
//
//        return out;
//    }
//
//};

double calculateAverageTime(const double& t1, const double& t2, const double& t3)
{
    return ((t1 + t2 + t3)/3);
}

double calculateExperimentalAcceleration(const double& x, const double& t)
{
    return ((2*x)/std::pow(t, 2));
}

double calculateTheoreticalAcceleration(const double& m1, const double& m2)
{
    return ((m1 - m2)/(m1 + m2));
}

double calculatePercentError(const auto& meas, const auto& actual)
{
    std::cout << "measured number received: " << meas << '\n';
    std::cout << "actual number received: " << actual << '\n';
    return std::abs((((meas - actual)/actual)*100));
}

int main()
{
    const std::vector<double> m1 { 57, 60, 77, 80, 107, 119, 157, 160, 165 };
    const std::vector<double> m2 { 55, 55, 75, 75, 105, 105, 155, 155, 155 };

    const double x { 1.5 };

    const std::vector<double> t1 { 5.2, 2.75 };
    const std::vector<double> t2 { 5.1, 2.8 };
    const std::vector<double> t3 { 4.95, 2.73 };

    std::vector<double> averageTime {};

    for (int i { 0 }; i < std::ssize(t1); ++i)
    {
       averageTime.emplace_back(calculateAverageTime(t1.at(i), t2.at(i), t3.at(i)));
    }

    std::vector<double> accelerationExperimental {};

    for (int i { 0 }; i < std::ssize(averageTime); ++i)
    {
        accelerationExperimental.emplace_back(calculateExperimentalAcceleration(x, averageTime.at(i)));
    }

    std::vector<double> accelerationTheoretical {};

    for (int i { 0 }; i < std::ssize(m1); ++i)
    {
        accelerationTheoretical.emplace_back(calculateTheoreticalAcceleration(m1.at(i), m2.at(i)));
    }

    std::vector<double> percentageError {};

    for (int i { 0 }; i < std::ssize(accelerationExperimental); ++i)
    {
        percentageError.emplace_back(calculatePercentError(accelerationExperimental.at(i), accelerationTheoretical.at(i)));
    }

    for (auto const& n : percentageError)
        std::cout << n << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include "../Random.h"

int main()
{
    const int random = Random::get(2, 4);

    std::cout << "Start where?\n";
    int start{};
    std::cin >> start;

    std::cout << "How many?\n";
    int count{};
    std::cin >> count;

    std::vector<int> v{};

    for (int i { count }; i > 0; --i)
    {
        v.push_back( (start*start) * 4 );
        ++start;
    }

    std::cout << "I generated " << count << " square numbers. Do you know what each number is after multiplying it by " << random << " ?\n";
    std::cout << " > ";
    int guess{};
    std::cin >> guess;

    while (true)
    {
        auto val = std::find(v.begin(), v.end(), guess);
        if (val == std::end(v))
        {
            v.erase(val);
            if (!v.empty())
            {
                std::cout << "Nice! " << v.size() << " number(s) left.";
            } else {
                std::cout << "Nice! You found all numbers, good job!\n";
                break;
            }
        }
//        else {
//            auto copy { v };
//            for (auto& n : copy)
//                n %= guess;
//
//            auto minElement = std::min_element(copy.begin(), copy.end(), [](const auto& a, const auto& b) {
//                return a < b;
//            });
//
//            if (*minElement <= 4)
//            {
//                std::cout << guess << " is wrong! Try " << v.at(*minElement) << " next time.\n";
//                break;
//            }
//        }
    }


    return 0;
}
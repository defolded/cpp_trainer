#include <string_view>
#include <array>
#include <iostream>
#include <algorithm>

struct Student {
    std::string_view name{};
    int score{};
};

int main()
{
    std::array<Student, 8> arr{
            { { "Albert", 3 },
              { "Ben", 5 },
              { "Christine", 2 },
              { "Dan", 8 }, // Dan has the most points (8).
              { "Enchilada", 4 },
              { "Francis", 1 },
              { "Greg", 3 },
              { "Hagrid", 5 } }
    };

    const auto best{
        std::max_element(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a.score < b.score;
        })
    };

    std::cout << best->name << " is the best!\n";

    return 0;
}
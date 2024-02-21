#include <array>
#include <string_view>
#include <iostream>

struct Item {
    std::string_view name{};
    int gold{};
};

int main()
{
    using namespace std::literals;
    constexpr std::array<Item, 4> arr{
            {

                    {"sword"sv, 5},
                    {"dagger"sv, 3},
                    {"club"sv, 2},
                    {"spear"sv, 7}
            }
    };

    for (const auto& item : arr) {
        std::cout << "A " << item.name << " costs " << item.gold << " gold." << std::endl;
    }

    return 0;
}
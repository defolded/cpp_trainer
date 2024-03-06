#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class MyString
{
private:
    std::string m_str{};
public:
    explicit MyString(std::string_view str)
        : m_str{str}
    {}

    friend std::ostream& operator<< (std::ostream& out, const MyString& str);
    std::string_view operator() (int start, int length);
};

std::string_view MyString::operator() (int start, int length)
{
    assert(length <= m_str.length());
    assert(start >= 0 && ((start+length) <= m_str.length()));

    return std::string_view{ m_str }.substr(start, length);
}

std::ostream& operator<< (std::ostream& out, const MyString& str)
{
    out << str.m_str;

    return out;
}

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
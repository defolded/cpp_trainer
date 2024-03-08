#include <iostream>
#include <cassert>

class IntArray
{
private:
    int* m_arr{};
    int m_len{};
public:
    explicit IntArray(int length)
        : m_len { length }
    {
        assert(length);

        m_arr = new int[m_len] {};
    }

    IntArray(const IntArray& arr)
        : m_len { arr.m_len }
    {
        assert(arr.m_arr && arr.m_len);

        m_arr = new int[m_len];

        for (int i {0}; i < arr.m_len; ++i)
            m_arr[i] = arr.m_arr[i];
    }

    ~IntArray()
    {
        delete[] m_arr;
    }

    friend std::ostream& operator<< (std::ostream& out, const IntArray& arr)
    {
        for (int i { 0 }; i < arr.m_len; ++i)
            out << arr.m_arr[i] << ' ';

        return out;
    }

    int& operator[] (const int i)
    {
        assert(i >= 0);
        assert(i < m_len);

        return m_arr[i];
    }

    IntArray& operator= (const IntArray& arr)
    {
        if (this == &arr)
            return *this;

        delete[] m_arr;

        m_len = arr.m_len;

        m_arr = new int[m_len];

        for (int i { 0 }; i < m_len; ++i)
            m_arr[i] = arr.m_arr[i];

        return *this;
    }

};

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{ fillArray() };

    std::cout << a << '\n';

    auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}
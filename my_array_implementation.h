#ifndef GENIUS_ARRAY_H
#define GENIUS_ARRAY_H

#include <cassert>
#include <initializer_list>

template <typename T>
class GeniusArray
{
private:
    int m_length{ 0 };
    T* m_array = new T[]{};
public:
    explicit GeniusArray(const int len)
        : m_length{ len }
    {
        assert(len > 0);

        if (m_length != len)
        {
            delete[] m_array;
            m_array = new T[m_length]{};
        }
    }

    GeniusArray(const int len, std::initializer_list<T> ls)
            : m_length{ len }
    {
        assert(len > 0);

        int count{ 0 };
        for (auto i : ls)
        {
            m_array[count] = i;  // Assign the individual element
            ++count;
        }
    }

    GeniusArray(std::initializer_list<T> ls)
    {
        int len = static_cast<int>(ls.size());
        m_length = len;
        m_array = new T[len]{};

        int count{ 0 };
        for (auto i : ls)
        {
            m_array[count] = i;  // Assign the individual element
            ++count;
        }
    }

    ~GeniusArray()
    {
        delete[] m_array;
    }

    GeniusArray& operator=(std::initializer_list<T> ls)
    {
        int len = static_cast<int>(ls.size());
        if (m_length != len)
        {
            delete[] m_array;
            m_length = len;
            m_array = new T[len]{};
        }

        int count{ 0 };
        for (auto i : ls)
        {
            m_array[count] = i;
            ++count;
        }

        return *this;
    }

    const int length() const
    {
        return m_length;
    }

    const T& operator[] (int index) const { return m_array[index]; }
    T& operator[] (int index)  { return m_array[index]; }
};


#endif
#ifndef GENIUS_ARRAY_H
#define GENIUS_ARRAY_H

#include <cassert>
#include <initializer_list>
#include <iostream>

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

    [[nodiscard]] int length() const
    {
        return m_length;
    }

    void print() const
    {
        for (int i{ 0 }; i < m_length; ++i)
            std::cout << m_array[i] << '\n';
    }

    int binarySearchArr(const int search_val)
    {
        int index = 0;
        int max = m_length - 1;

        while (index <= max)
        {
            int mid = ((index + max) / 2);
            if (search_val == m_array[mid])
            {
                return mid;
            }
            else if (search_val < m_array[mid])
            {
                max = mid - 1;
            }
            else
            {
                index = mid + 1;
            }
        }

        return NULL;
    }

    void bubbleSortArrAsc()
    {
        for (int i{ 0 }; i < m_length - 1; ++i) {
            for (int j{ 0 }; j < m_length - i - 1; ++j)
            {
                if (m_array[j] > m_array[j + 1])
                {
                    auto temp = m_array[j];
                    m_array[j] = m_array[j + 1];
                    m_array[j + 1] = temp;
                }
            }
        }
        std::cout << "Array sorted in ascending order!\n";
    }


    void bubbleSortArrDesc()
    {
        for (int i{ 0 }; i < m_length - 1; ++i) {
            for (int j{ 0 }; j < m_length - i - 1; ++j)
            {
                if (m_array[j] < m_array[j + 1])
                {
                    auto temp = m_array[j];
                    m_array[j] = m_array[j + 1];
                    m_array[j + 1] = temp;
                }
            }
        }
        std::cout << "Array sorted in ascending order!\n";
    }


    const T& operator[] (int index) const { return m_array[index]; }
    T& operator[] (int index)  { return m_array[index]; }
};


#endif
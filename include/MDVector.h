#ifndef MDVECTOR_H
#define MDVECTOR_H

#include <cstdint>

template<size_t N, typename T>
class MDVector
{
private:
    T m_Elements[N];

public:
    MDVector()
    {
        // Initialize all elements to zero
        for (T* i = m_Elements[0]; i < m_Elements[N]; i++)
            *i = T();
    }

    T& GetElement(size_t i) const
    {
        return m_Elements[i];
    }

    T* GetElementsList() const
    {
        return m_Elements;
    }

    T& operator[](size_t i)
    {
        return GetData(i);
    }

    T operator[](size_t i) const
    {
        return GetData(i);
    }

    size_t GetSize() const
    {
        return N;
    }

    size_t GetSizeInBytes() const
    {
        return N * sizeof(T);
    }

    size_t Sum() const
    {
        size_t nSum = 0;
        for (T* i = m_Elements[0]; i < m_Elements[N]; i++)
            nSum += *i;

        return nSum;
    }

    T GetAverage() const
    {
        return Sum() / N;
    }
};

#endif

#pragma once
#include <vector>

template<typename T>
class Cells
{
public:
    Cells(int w, int h) : m_width{w}, m_height{h}
    {
        m_data.resize(w * h);
    }

    T Read(int x, int y) const
    {
        return m_data[y * m_width + x];
    }

    void Write(int x, int y, const T& value)
    {
        m_data[y * m_width + x] = value;
    }
    
    int m_width{0};
    int m_height{0};

    std::vector<T> m_data;
};

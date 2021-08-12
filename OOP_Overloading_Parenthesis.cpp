#include <bits/stdc++.h>
#include <cassert>

using namespace std;

class Matrix
{
private:
    double m_data[4][4]{};

public:
    double &operator()(int row, int col);
    double operator()(int row, int col) const; //for const objects
    void operator()();
};

double &Matrix::operator()(int row, int col)
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);
    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);
    return m_data[row][col];
}

void Matrix::operator()()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            m_data[row][col] = 0.0;
        }
    }
}
#include <iostream>

int main()
{
    Matrix matrix{};
    matrix(1, 2) = 4.5;
    matrix(); // erase matrix
    std::cout << matrix(1, 2) << '\n';

    return 0;
}
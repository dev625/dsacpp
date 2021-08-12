#include <iostream>
using namespace std;

class Digit
{
private:
    int m_digit;

public:
    Digit(int digit = 0) : m_digit{digit}
    {
    }
    Digit &operator++(); //prefix
    Digit &operator--();
    Digit operator++(int); //postfix
    Digit operator--(int);

    friend std::ostream &operator<<(std::ostream &out, const Digit &d);
};
Digit &Digit::operator++()
{
    if (m_digit == 9)
        m_digit = 0;
    else
        ++m_digit;
    return *this;
}

Digit &Digit::operator--()
{
    if (m_digit == 0)
        m_digit = 9;
    else
        --m_digit;
    return *this;
}

Digit Digit::operator++(int)
{
    Digit temp{*this};
    ++(*this);
    return temp;
}

Digit Digit::operator--(int)
{
    Digit temp{*this};
    --(*this);
    return temp;
}
#include <cassert>
#include <iostream>
using namespace std;
class Fraction
{
private:
    int m_num{};
    int m_den{};

public:
    Fraction(int num = 0, int den = 1) : m_num{num}, m_den{den}
    {
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1);
};
/*
 Similarly, member functions of a class can access the private members of parameters of the same class type.
*/
std::ostream &operator<<(std::ostream &out, const Fraction &f1)
{
    out << f1.m_num << "/" << f1.m_den;
    return out;
}

int main()
{
    Fraction fivethirds(5, 3);
    Fraction fcopy(fivethirds);
    cout << fcopy << "\n";
}
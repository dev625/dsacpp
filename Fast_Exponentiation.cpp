#include <iostream>
using namespace std;

int power_recursive(int a, int b)
{
    if (b == 0)
        return 1;
    int tmp = power_recursive(a, b / 2);
    int result = tmp * tmp;
    if (b % 2 == 1)
        result *= a;
    return result;
}

int power_iterative(int a, int b)
{
    int result{1};
    while (b > 0)
    {
        if (b % 2 == 1)
            result *= a; //%M
        a *= a;          //%M
        b /= 2;
    }
    return result;
}

int inverse(int a, int p)
{
    return power_iterative(a, p - 2);
}

int main()
{
    cout << power(2, 5) << "\n";
    cout << power(4, 6) << "\n";
    cout << power(3, 8) << "\n";
}
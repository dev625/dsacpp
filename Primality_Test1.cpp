#include <iostream>
using namespace std;
/*
All primes greater than 3 are of the form 
6k±1, where k>0.
all integers are of the form 6k+i
where i=-1,0,1,2,3 or 4.
2 divides 6k+0,6k+2,6k+4
3 divides 6k+3


*/
bool isPrime(int k)
{
    if (k <= 1)
        return false;
    if (k <= 3)
        return true;
    if (k % 2 == 0 || k % 3 == 0)
        return false;
    for (int i = 5; i * i <= k; i = i + 6)
    {
        if (k % i == 0 || k % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << isPrime(199);
}
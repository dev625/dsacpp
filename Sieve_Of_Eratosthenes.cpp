/*Algorithm to find all primes smaller than or
equal to n. Works well when n is smaller than 
about 10 million.*/

#include <iostream>
#include <cstring>
using namespace std;

void SieveofEratosthenes(int n)
{
    /*Initialize all the values in the boolean 
    array to be true first meaning all the prime*/
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    //Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << "\n";
}

int main()
{
    int n = 10000;
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    SieveofEratosthenes(n);
    return 0;
}
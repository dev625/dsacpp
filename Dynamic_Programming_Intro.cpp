#include <iostream>
using namespace std;

int solve(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0 || n == 1)
        return 1;
    return solve(n - 1) + solve(n - 3) + solve(n - 5);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
}
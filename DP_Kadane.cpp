#include <bits/stdc++.h>
using namespace std;

int Kadane1(const vector<int> &V)
{
    //non empty subarray
    //change best to 0 if 0 sum is allowed
    int sum{0}, best{INT_MIN};
    int n = V.size();
    for (int i = 0; i < n; i++)
    {
        sum += V[i];
        best = max(sum, best);
        sum = max(sum, 0);
    }
    return best;
}

int main()
{
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    int ans = Kadane1(V);
    cout << ans << "\n";
}
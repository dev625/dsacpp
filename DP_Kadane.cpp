/*
So Kadane's algorithm basically gives us the result of the maximum possible
subarray sum in an array, the array may have negative numbers as well.

We may have 2 cases of this problem : 
1. 0 sum is allowed
2. 0 sum is not allowed

Case 1 : 0 sum is allowed
In this case : If a negative number is encountered, then we dont add it further
to our sum variable. Also if a negatice number is encountered best does not 
chagnge but the sum does change so if more positive numbers are available 
later in the array, we are not neglecting them as well.

Case 2 : 0 sum is not allowed(non empty subarray)
In this case : We need to have a subarray of length atleast 1 as the answer.
So here we basically compare the best sum with INT_MIN so we atleast 
get some answer.

Some good explanation : https://www.youtube.com/watch?v=HCL4_bOd3-4
*/

#include <bits/stdc++.h>
using namespace std;

int Kadane1(const vector<int> &V)
{
    //non empty subarray
    //change best to 0 if 0 sum is allowed, INT_MIN if not allowed
    int sum{0}, best{0};
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
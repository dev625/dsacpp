#include <bits/stdc++.h>
using namespace std;


void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void hp(int a[],int size,int n)
{
    if(size==1)
    {
        printarr(a,n);
        return;
    }
    for(int i=0;i<size;i++)
    {
        hp(a,size-1,n);
        if(size%2==1)
            swap(a[0],a[size-1]);
        else 
            swap(a[i],a[size-1]);
    }
}

int main()
{
    int a[] = {1,2,3};
    int n = sizeof(a)/sizeof(a[0]);
    hp(a,n,n);
    return 0;
}
#include <iostream>
using namespace std;
/*O(n) program to clockwise rotate an array of size n by d elements. */

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void reverse(int arr[],int l, int r)
{
    int i;
    int len = r-l+1;
    for(i=0;i<len/2;i++)
        swap(arr[l+i],arr[r-i]); 
}

void rotate(int arr[],int d,int n)
{
    if(d==0)
        return;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int d = 3;
    d = d%size;
    rotate(arr,d,size);
    printArray(arr,size);
    return 0;
}
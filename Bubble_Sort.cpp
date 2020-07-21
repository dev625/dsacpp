#include <iostream>
using namespace std;

void swap(int &x,int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void bubblesort(int arr[],int len)
{
    int i,j;
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printarray(int arr[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        cout << arr[i]<<" ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {9,8,7,6,5,2,87};
    printarray(arr,7);
    bubblesort(arr,7); //arrays by default are passed by address
    printarray(arr,7);
}
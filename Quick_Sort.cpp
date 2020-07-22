#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int Partition(int *arr, int l,int r)
{
    /*How this works is that we set the first element as pivot,
    and go through all the other elements in the array, if we encounter
    a element less than the pivot element then it is swapped with 
    a greater element encountered previously.
    Also, if a greater than pivot element is encountered only i is incremented 
    and not j.
    */
    int x = arr[l]; //selecting the first element of array as pivot element
    int i, j=l;
    for(i=l+1;i<=r;i++)
    {
        if(arr[i]<=x)
        {
            j++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[l],arr[j]);
    return j;

}

void QuickSort(int *arr,int l, int r)
{
    if(l>=r)
        return;
    int m = Partition(arr,l,r);
    /*After the partition the array element at index m
    is at its final postion*/
    QuickSort(arr,l,m-1);
    QuickSort(arr,m+1,r);
}

void printArray(int *arr,int size)
{
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
    int size;
    cout << "Enter the number of array elements : \n";
    cin >> size;
    int *arr = new int[size];

    cout << "Enter the array elements : \n";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    cout << "The array entered is : \n";
    printArray(arr,size);

    QuickSort(arr,0,size-1);
    
    cout <<"The array after sorting is : \n";
    printArray(arr,size);
}
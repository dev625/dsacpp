#include <iostream>
using namespace std;
/*Introduction : This algorithm is used to segregate an array of 0's,1s and 2s, it works kind of similar
as compared to the partition procedure of the 3 way quicksort algorithm*/

void swap(int &x, int &y)
{
    int temp{x};
    x = y;
    y = temp;
}

void segregate(int *arr, int n)
{
    /*Main idea is to keep the 1's in place and move the 0's and 2's accordingly*/
    int low{0}, mid{0}, high{n - 1};
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;
        }
    }
}

int main()
{
    int i, n;
    cout << "Enter the size of the array please : \n";
    cin >> n;
    int *arr = new int[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    segregate(arr, n);
    cout << "The array after the sorting procedure applied to it is :\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
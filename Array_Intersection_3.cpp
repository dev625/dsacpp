#include <iostream>
using namespace std;

void find_common(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
    int i{0}, j{0}, k{0};
    while (i < n1 && j < n2 && k < n3)
    {
        /* If x = y and y = z print any of them and
        move ahead in all arrays.
        */
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
            k++;
        }
        //x<y
        else if (arr1[i] < arr2[j])
            i++;
        //y<z
        else if (arr2[j] < arr3[k])
            j++;
        //x>y and z<y ; z is smallest
        else
            k++;
    }
}

int main()
{
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    find_common(arr1, arr2, arr3, n1, n2, n3);
    return 0;
}
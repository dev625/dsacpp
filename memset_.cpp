/* Converts the value ch to unsigned char and 
   copies it into each of the first n characters
   of the object pointed to by str[].

   If the object is not trivially copyable(
       eg : scalar, array or C compatible struct
   ),
   the behavior is undefined. If n is greater
   than the size of the object pointed to by
   str, the behavior is undefined.*/

/*Syntax :
void* memset(void *str, int ch , size_t n);
Parameters
str[] : Pointer to the object to copy the character
ch : The character to copy.
n : Number of bytes to copy.
Return value : 
memset() functions returns str, the pointer to destination string
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[] = "geeksforgeeks";
    memset(str, 'b', sizeof(str));
    cout << str << endl;
    string s1 = "geeksforgeeks";

    cout << sizeof(s1) << endl;  //32 bytes
    cout << sizeof(str) << endl; //14 bytes

    /*memset can also be used to set all values
    as 0 or -1 for integral data types also. It will
    not work if we use it to set as other values.
    The reason is simple, memset works byte by byte.*/
    int a[5];

    //All elements of A are 0
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;

    //All elements of A are -1
    memset(a, -1, sizeof(a));
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;

    //Would not work
    memset(a, 5, sizeof(a)); //wrong
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
}
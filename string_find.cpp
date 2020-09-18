/*String find is used to find the first occurence
of sub-string in the specified string being called
upon. It returns the first index of the first
occurence of the substring in the string from 
given starting position. The default starting
position is 0.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "hello there hello there!";
    string str1 = "there";
    size_t found = str.find(str1);
    if (found != string::npos)
        cout << "First occurence is : " << found << "\n";
    //for C style strings we have
    char arr[] = "there";
    found = str.find(arr, found + 1);
    if (found != string::npos)
        cout << "Next occurence is : " << found << "\n";
    return 0;
}
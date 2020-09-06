/*getline is used to read a string or a line from an 
input stream. getline() functions extracts characters from
the input stream and appends it to the string object until
the delimiting character is encountered.

Syntax :

isstream& getline(isstream& is, string& str, char delim)
is : object of istream class and tells the function about the
stream from where to read the input from.

str : string object, the input is stored in this object
after being read from the stream.

delim : delimitation character which tells the function to
stop reading further input after reaching this character.

*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string S, T;
    getline(cin, S);
    stringstream X(S);
    while (getline(X, T, ' '))
    {
        cout << T << endl;
    }
    return 0;
}

/*Caution : getline function considers a new line character
as the delimitation character and new line character is 
valid input for this function.*/

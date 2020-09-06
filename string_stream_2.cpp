/*Removing spaces from string using string stream
1. Enter the whole string into stringstream
2. Empty the string 
3. Extract word by word and concatenate to the string.
*/

#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string str)
{
    stringstream ss;
    string temp;
    //storing the whole string into string stream
    ss << str;
    str = "";
    while (!ss.eof())
    {
        //extracting word by word from stream
        ss >> temp;
        str = str + temp;
    }
    return str;
}

string removeSpaces2(string str)
{
    stringstream ss(str);
    string temp;
    str = "";
    while (getline(ss, temp, ' '))
    {
        str += temp;
    }
    return str;
}

int main()
{
    string s = "This is a test.";
    cout << removeSpaces(s) << endl;
    s = "geeks for geeks yeahhh";
    cout << removeSpaces2(s) << endl;
}
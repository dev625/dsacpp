/*A string stream associates a  string object
with a stream allowing you to read from a string
as if it were a stream(like cin)*/

//Counting number of words in a string

#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int count_words(string str)
{
    //breaking input into word using string streams
    stringstream s(str); //used for breaking words
    string word;         //to store individual words

    int count{0};
    while (s >> word)
        count++;
    return count;
}

void printFrequency(string st)
{
    map<string, int> FW;
    stringstream s(st); //used for breaking words
    string word;        //to store individual words

    while (s >> word)
        FW[word]++;
    map<string, int>::iterator m;
    for (m = FW.begin(); m != FW.end(); m++)
    {
        cout << m->first << " -> "
             << m->second << "\n";
    }
}
int main()
{
    string s;
    getline(cin, s);
    cout << count_words(s) << "\n";
    getline(cin, s);
    printFrequency(s);
}
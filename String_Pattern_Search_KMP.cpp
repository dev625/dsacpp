#include <iostream>
#include <string>
using namespace std;

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void prefix_array(const string &pattern, int M, int *prefix)
{
    /*
    prefix[i] : the longest proper prefix of pat[0..i]
    which is also a suffix of pat[0..i].
    
    We search for longest proper prefix in sub patterns. 
    More clearly we focus on sub-strings that are 
    either prefix and suffix.
    
    For each pattern sub-pattern pat[0..i] where i=0 to 
    m-1 ,prefix[i] stores the maximum matching proper prefix
    which is also a suffix of sub-pattern pat[0..i];
    */

    // length of the previous longest prefix suffix
    int j{0};
    prefix[0] = 0; //this is always 0
    int i{1};
    while (i < M)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            prefix[i] = j;
            i++;
        }
        else //pattern[i]!=pattern[j]
        {
            if (j != 0)
                j = prefix[j - 1];
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string &text, const string &pattern)
{
    int m = pattern.length();
    int n = text.length();

    int prefix[m];
    prefix_array(pattern, m, prefix);
    print_array(prefix, m);
    int i{0}; //index for text
    int j{0}; //index for pattern
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            cout << "Found pattern at index " << i - j << "\n";
            j = prefix[j - 1];
        }
        //mismatch after j matches
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = prefix[j - 1];
            else
                i = i + 1;
        }
    }
}

int main()
{
    string s1 = "ABABABC";
    string s2 = "ABABC";
    KMPSearch(s1, s2);
}
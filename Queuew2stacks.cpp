#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() 
{
    stack<int>s1,s2;
    int q;
    cin >> q;
    cin.ignore(32767,'\n');
    int top{-1};
    for(int i=0;i<q;i++)
    {
        string s;
        getline(cin,s);
        if(s.size()>1)
        {
            int num = stoi(s.substr(2,s.size()-2));
            if(s1.empty())
                top = num;
            s1.push(num);
        }
        else if(s[0]=='2')
        {
            while(s1.size()!=1)
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.pop();
            if(!s2.empty())
                top = s2.top();
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            
        }
        else if(s[0]=='3')
            cout << top << "\n";
    }
}

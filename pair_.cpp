/*
Syntax : pair(data_type1, data_type2) Pair_name;
*/

#include <iostream>
#include <utility>

using namespace std;

int main()
{
    pair<int, char> PAIR1;
    PAIR1.first = 100;
    PAIR1.second = 'G';
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
    //Differrent ways of initialization
    pair<int, int> g1;
    pair<int, char> g2 = make_pair(1, 'a');
    pair<int, int> g3(1, 10);
    pair<int, int> g4(g3);
    pair<int, int> h = make_pair(1, 20);
    pair<int, int> h1 = make_pair(1, 10);
    cout << (h > h1) << endl;
}
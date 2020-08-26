#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main()
{
    map<int, int> M;
    M.insert(pair<int, int>(1, 40));
    M.insert(pair<int, int>(2, 30));
    M.insert(pair<int, int>(3, 60));
    M.insert(pair<int, int>(4, 20));
    M.insert(pair<int, int>(5, 50));
    M.insert(pair<int, int>(6, 50));
    M.insert(pair<int, int>(7, 10));

    //Printing map M
    map<int, int>::iterator itr;
    for (itr = M.begin(); itr != M.end(); itr++)
    {
        cout << "\t" << itr->first
             << "\t" << itr->second << "\n";
    }
    cout << "\n";

    //assigning the elements from M to N
    map<int, int> N(M.begin(), M.end());
    for (itr = N.begin(); itr != N.end(); itr++)
    {
        cout << "\t" << itr->first
             << "\t" << itr->second << "\n";
    }

    /*Erasing all the elements with key less than 3, N.find(3)
    std::map erase is not inclusive of the last element int the range. */
    cout << "\nN after removal of elements less than key = 3\n";
    N.erase(N.begin(), N.find(3));
    for (itr = N.begin(); itr != N.end(); itr++)
    {
        cout << "\t" << itr->first
             << "\t" << itr->second << "\n";
    }
    cout << endl;

    //remove all the elements with key = 4
    int num;
    num = N.erase(4);
    cout << num << " removed \n";

    //lower bound and upper bound for map M key=5
    cout << M.lower_bound(5)->first << "\n";
    cout << M.lower_bound(5)->second << "\n";
    cout << M.upper_bound(5)->first << "\n";
    cout << M.upper_bound(5)->second << "\n";
}
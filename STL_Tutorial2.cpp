#include <iostream>
#include <vector>
#include <list>
using namespace std;

// int main()
// {
//     //Declare size of 2D array and initialize
//     //Below is a 3X2 matrix
//     vector<vector<int>> vmatrix(3, vector<int>(2, 0));
//     vmatrix[0][0] = 0;
//     vmatrix[0][1] = 1;
//     vmatrix[1][0] = 10;
//     vmatrix[1][1] = 11;
//     vmatrix[2][0] = 20;
//     vmatrix[2][1] = 21;
//     cout << "Loop By Index: " << endl;
//     int ii, jj;
//     for (ii = 0; ii < 3; ii++)
//     {
//         for (jj = 0; jj < 2; jj++)
//         {
//             cout << vmatrix[ii][jj] << " ";
//         }
//         cout << endl;
//     }
// }

/*Examples of Iterators used with a 2-D Vector*/

// int main()
// {
//     vector<vector<int>> vmatrix;
//     vector<int> A, B;
//     vector<vector<int>>::iterator ii;
//     vector<int>::iterator jj;

//     A.push_back(10);
//     A.push_back(20);
//     A.push_back(30);

//     B.push_back(100);
//     B.push_back(200);
//     B.push_back(300);
//     vmatrix.push_back(A);
//     vmatrix.push_back(B);
//     cout << endl
//          << "Using Iterator : " << endl;
//     for (ii = vmatrix.begin(); ii != vmatrix.end(); ii++)
//     {
//         for (jj = (*ii).begin(); jj != (*ii).end(); jj++)
//         {
//             cout << *jj << " ";
//         }
//         cout << endl;
//     }
// }

int main()
{
    list<int> L;
    L.push_back(0);
    L.push_front(0);
    L.insert(++L.begin(), 2); //insert 2 right after the first
    L.push_back(5);
    L.push_back(6);
    list<int>::iterator i;
    for (i = L.begin(); i != L.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}
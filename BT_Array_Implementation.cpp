/*Array based representation of Binary Trees*/
#include <iostream>
using namespace std;

/*Main idea :
In this 0 index based array representation 
if father is at index p, then left child is at
index (2p+1) and right child is at index (2p+2)
 */

char tree[10];
int root(char key)
{
    if (tree[0] != '\0')
        cout << "Tree already had root.\n";
    else
        tree[0] = key;
    return 0;
}

int set_left(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        cout << "Can't set child at " << (parent * 2) + 1 << " , no parent found.\n";
    }
    else
        tree[(parent * 2) + 1] = key;
}

int set_right(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        cout << "Can't set child at " << (parent * 2) + 2 << " , no parent found.\n";
    }
    else
        tree[(parent * 2) + 2] = key;
    return 0;
}
int print_tree()
{
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] != '\0')
            cout << tree[i] << " ";
        else
            cout << "-";
    }
    return 0;
}

int main()
{
    root('A');
    set_left('B', 0);
    set_right('C', 2);
    print_tree();
}
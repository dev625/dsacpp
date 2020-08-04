#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
    int *harr;     //pointer to array of elements in the heap;
    int capacity;  //maximum possible size of min heap
    int heap_size; //current size of min heap
public:
    //Constructor
    MinHeap(int capacity);

    //to heapify a subtree with the root at given index
    void MinHeapify(int k);

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (2 * i) + 1;
    }
    int right(int i)
    {
        return (2 * i) + 2;
    }
    //to extract the root which is the minimum element
    int extractMin();

    //Decreases key value of key at index i to new_val
    void decreasekey(int i, int new_val);

    //Returns the minimum key(key at root) from min heap
    int getMin()
    {
        return harr[0];
    }

    //deletes a key stored at index i
    void deleteKey(int i);

    //Inserts a new key k
    void insertKey(int k);
};

//Constructor : Builds a heap from a given array a[]
//of given size

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

//Function to Insert a new key k

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow : Could not insert Key\n";
        return;
    }
    //First insert a new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    //Fix the main heap property if is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

//Function to decrease key at index 'i' to new_val.
//It is assumed that new_val is smaller than harr[i]
void MinHeap::decreasekey(int i, int new_val)
{
    //Basically replace the key and then heapify
    //at that point
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

//Method to remove minimum element ( or root)
//from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    //We store the minimum value and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}

//Method to delete key at index i. First we reduce
//the key value to minus infinite, then we
//simply extract that value

void MinHeap::deleteKey(int i)
{
    decreasekey(i, INT_MIN);
    //Decrease key here automatically makes
    //that key available at the root node
    extractMin();
}

//A recursive method to heapify a subtree with the root at
//the given index, this method assumes that the subtrees
//are already heapified.
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreasekey(2, 1);
    cout << h.getMin();
    return 0;
}
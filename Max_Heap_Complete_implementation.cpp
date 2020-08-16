#include <iostream>
#include <climits>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MaxHeap
{
    int *H;        //Pointer to array of elements in the Heap
    int capacity;  //Maxmimum possible size of Max Heap
    int heap_size; //Current Size of the Max

public:
    MaxHeap(int cap)
    {
        capacity = cap;
        heap_size = 0;
        H = new int[cap];
    }
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

    void MaxHeapify(int k)
    {
        int l = left(k);
        int r = right(k);
        int largest = k;
        if (l < heap_size && H[l] > H[k])
            largest = l;
        if (r < heap_size && H[r] > H[largest])
            largest = r;
        if (largest != k)
        {
            swap(H[k], H[largest]);
            MaxHeapify(largest);
        }
    }

    int GetMaximum()
    {
        return H[0];
    }

    int ExtractMaximum()
    {
        if (heap_size <= 0)
            return INT_MIN;
        if (heap_size == 1)
        {
            heap_size--;
            return H[0];
        }
        //Store the Maximum Value and remove it from the heap
        int root = H[0];
        H[0] = H[heap_size - 1];
        heap_size--;
        MaxHeapify(0);
        return root;
    }

    void IncreaseKey(int i, int new_val)
    {
        /*Assumption  : new_val is greater than the 
        key at the index that we are increasing.
        
        Concept : Simply Replace the key at that new index,
        and basically take that key up the heap until it
        is at a proper location satisfying max heap 
        property*/
        H[i] = new_val;
        while (i != 0 && H[parent(i)] < H[i])
        {
            swap(H[i], H[parent(i)]);
            i = parent(i);
        }
    }

    void InsertKey(int k)
    {
        if (heap_size == capacity)
            cout << "\nOverflow Error : Heap is at its maximum capacity\n";
        /*Concept : We Insert a new key with value of
            negative infinity at the end of the heap, and then
            call increase key method on that node with the desired
            key value
        */
        heap_size++;
        int new_index = heap_size - 1;
        H[new_index] = INT_MIN;
        IncreaseKey(new_index, k);
    }

    void DeleteKey(int i)
    {
        /*Concept : To delete a key at a particular index,
        we Increase the key of */
        IncreaseKey(i, INT_MAX);
        ExtractMaximum();
    }

    void Display()
    {
        for (int i = 0; i < heap_size; i++)
            cout << H[i] << " ";
        cout << "\n";
    }
};

int main()
{
    MaxHeap A(20);
    A.InsertKey(12);
    A.InsertKey(20);
    A.InsertKey(32);
    A.InsertKey(14);
    A.InsertKey(19);
    A.InsertKey(89);
    A.Display();
}
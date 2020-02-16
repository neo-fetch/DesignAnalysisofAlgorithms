/**
 * DAA LAB CODE- Heapsort
 * Mayank Deshpande - 18xj1a0529
 * Koushik  - 
*/

#include <iostream>

using namespace std;

void heapify(int unsortdheap[], int size, int parent)
{
    /**
     * This is a simple heapify algorithm done in the DAA class.
     * I start from the last element
     * Find the children 2i + 2, 2i + 1
     * look for the largest among the three
     * replace.
     * repeat for the children.
    */

    //assign indexes
    int largest = parent; // default
    int l = 2 * parent + 1; // left child
    int r = 2 * parent + 2; // right child

    if (l < size && unsortdheap[l] > unsortdheap[largest])
    {
        largest = l; //meaning left child is larger
    }
    if (r < size && unsortdheap[r] > unsortdheap[largest])
    {
        largest = r; // meaning right child is largest among the 3.
    }
    if (largest != parent)
    {
        swap(unsortdheap[parent], unsortdheap[largest]);

        heapify(unsortdheap, size, largest);// i repeat this for their children by making them the parent until no child can be created.
    }
}

void heapSort(int unsortdheap[], int size)
{
    /**
     * I just use the heapify method above to sort the whole algorithm
    */
    for (int i = size / 2 - 1; i >= 0; i--) // I assign the parent to be heapified and work my way up to the root to get a max- heap.
    {
        heapify(unsortdheap, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(unsortdheap[0], unsortdheap[i]);
        // i simulteneously sort and heapify in the same array by taking the root to the end of the array, and heapify the rest to make it a max heap of size-1.
        heapify(unsortdheap, i, 0);
    }
}

void print(int heap[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main()
{
    int heap[100];
    
    cout << "enter your heap: (-1 is exit)" << endl;
    
    int inp, size = 0, i = 0;
    
    while (true)
    {
        cin >> inp; 
        if (inp == -1)
        {
            break;
        }
        heap[i] = inp;
        i = i + 1;
        size = size+1;
    }


    cout << "before sorting:" << endl;
    
    print(heap, size);
    
    heapSort(heap, size);
    
    cout << "After sorting:" << endl;
    
    print(heap, size);
    //et voila!
}

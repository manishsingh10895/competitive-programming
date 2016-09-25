#include <iostream>
#define MAX_HEAP_SIZE 1000

using namespace std;

template <class T>
class Heap
{
    private: 
        T heap[MAX_HEAP_SIZE];
        void maxHeapify(int);
        void setMaxHeap();
        int parent(int i)
        {
            return floor((i - 1)/2);
        }
        int leftChild(int i)
        {
            return 2*i + 1;
        }
        int rightChild(int i)
        {
            return 2*i + 2;
        }
        
    public:
        void Insert(T element);
        T DeleteElement(T element);
        Heap(T array)
        {
            heap = array;
            setMaxHeap();
        }
        void Print();
};

template <class T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void Heap<T> :: maxHeapify(int i)
{
    int left = leftChild(i);
    int right = rightChild(i);
    int largest;

    if(left < heap.size() && heap[left] > heap[i]) 
        largest = left;
    else
        largest = i;

    if(right <= heap.size() && heap[right] > heap[i])
        largest = right;

    if(largest != i)
    {
        swap(heap[i], heap[largest]);
    }
}

template <class T>
T Heap<T> :: DeleteElement(T element)
{
    return element;
}

template <class T>
void Heap<T> :: setMaxHeap()
{
    for(int i = heap.size(); i > 1; i--)
    {
        maxHeapify(i);
    }
}

template <class T>
void Heap<T> :: Print()
{
    cout << "The heap ---------------------\n";
    for(int i =0; i < heap.size(); i++)
    {
        cout << heap[i] << " "; 
    }
    cout << "\n";
}

int main()
{
    int array[] = {1,8,2,7,9,3,10,4,14,16};
    Heap<int> heap = new Heap<int>(array);
    heap.Print();
}
#include <iostream>
#include <climits>
#define MAX_HEAP_SIZE 1000

using namespace std;

void Swap(int &x, int &y);

class MinHeap
{
    int Heap[MAX_HEAP_SIZE];
    int heapSize;
    void PostChangePreserveHeap(int);
    public:
        MinHeap(){
            heapSize = 0;
        };
        int Parent(int i) { return (i - 1)/2; }
        int Left(int i) { return (2*i + 1); }
        int Right(int i) { return (2*i + 2); }

        // Extract the minimum Element i.e. root
        int ExtractMin();

        // Decrease value of element at i
        void DecreaseKey(int i, int newVal);

        // Return the minimum element, i.e the first element
        int GetMin() { return Heap[0]; }

        void DeleteKey(int i);

        void InsertKey(int key);

        void Heapify(int);

        void Print();
};

void MinHeap :: PostChangePreserveHeap(int i)
{
    while(i != 0 && Heap[Parent(i)] > Heap[i])
    {
        Swap(Heap[i], Heap[Parent(i)]);
        i = Parent(i);
    }
}

void MinHeap:: InsertKey(int key) 
{
    if(heapSize == MAX_HEAP_SIZE) {
        std::cout << "HEAP OVERFLOW" << endl;
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    Heap[i] = key;

    // Fix the Min Heap property for the current path
    PostChangePreserveHeap(i); 
}

void MinHeap :: DecreaseKey(int i, int newVal) 
{
    Heap[i] = newVal;
    
    PostChangePreserveHeap(i);
}

int MinHeap :: ExtractMin()
{
    if(heapSize <= 0) return INT_MAX;

    if(heapSize == 1) {
        heapSize--;
        return Heap[0];
    }

    // Min is the root of the heap
    int min = Heap[0];
    // Replace root with the last element in the heap
    Heap[0] = Heap[heapSize-1]; 
    heapSize--;
    Heapify(0);

    return min;
}

// Tread down the heap, making things all right
void MinHeap :: Heapify(int i)
{
    int l = Left(i);
    int r = Right(i);

    int smallest = i;

    if(l < heapSize && Heap[l] < Heap[i])
        smallest = l;
    if(r < heapSize && Heap[r] < Heap[i])
        smallest = r;
    
    if(smallest != i) {
        Swap(Heap[smallest], Heap[i]);
        Heapify(smallest);
    }
}

void MinHeap :: Print()
{
    for(int i =0; i< heapSize; i++) {
        std::cout << Heap[i] << " ";
    }
    std::cout << endl;
}

void MinHeap :: DeleteKey(int i) 
{
    // Step1: Decrease the wanted element to lowest value
    // Step2: After this the element will on the root
    // Step3: ExtractMin(), 
    DecreaseKey(i, INT_MIN);
    ExtractMin();
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


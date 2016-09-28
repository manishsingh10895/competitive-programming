// Program to find a number in a sorted but rotated array
#include <iostream>
using namespace std;

int BinarySearch(int array[], int, int, int);

// Find the pivot element, i.e the first element where the next elements value is less
int FindPivot(int array[], int start, int end)
{
    if(start > end) return -1;
    if(start == end) return end;

    int mid = (start + end)/2;
    if(array[mid] < end && array[mid] > array[mid + 1])
        return mid;
    if(array[mid] >  start && array[mid] < array[mid - 1])
        return mid - 1;
    
    if(array[start] > array[mid])
        return FindPivot(array, start, mid - 1);
    
    return FindPivot(array, mid + 1, end);
}

// Find an element in the pivoted array
int PivotedSearch(int array[], int size, int key)
{
    int pivot = FindPivot(array, 0, size - 1);

    if(pivot == -1) 
        return BinarySearch(array, key, 0, size - 1);
    
    if(array[0] < key) 
        return BinarySearch(array, key, 0, pivot);
    
    return BinarySearch(array, key, pivot+1, size - 1);
}


// Good old Binary Search 
int BinarySearch(int array[], int key, int start, int end)
{
    if(start == end) return array[end];

    int mid = (start + end) / 2;
    if(array[mid] > key) return BinarySearch(array, key, mid + 1, end);
    if(array[mid] < key) return BinarySearch(array, key, start, mid - 1);

    if(array[mid] == key) return mid;
}

int main()
{
    int array[10] = {5, 8, 20, 23, 25, 87, 89, 1, 2, 3};

    cout << PivotedSearch(array, 10, 23) << endl; 
}


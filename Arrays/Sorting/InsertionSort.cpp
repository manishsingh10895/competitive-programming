#include <iostream>
using namespace std;

void Print(int array[], int);

void InsertionSort(int array[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int key = array[i];
        int pos = i;
        while(pos > 0 && array[pos - 1] > key)
        {    
            array[pos] = array[pos - 1];
            pos = pos - 1;
        }
        array[pos] = key;
    }
}

void Print(int array[], int size)
{
    cout << endl;
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

int main()
{
    int array[10] = {3, 2, 25, 20, 89, 5, 23, 1, 87, 8 };
    InsertionSort(array, 10);
    Print(array, 10);
}
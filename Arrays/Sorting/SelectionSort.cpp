#include <iostream>
#include <limits>
#define INFINITY std::numeric_limits<int>::max()

using namespace std;

void Swap(int array[], int pos1, int pos2)
{
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void SelectionSort(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int min = INFINITY; //making min the largest possible number
        int pos = i;
        for(int j = i; j < size; j++)
        {
            if(array[j] <= min) 
            {
                min = array[j];
                pos = j;
            }
        }
        Swap(array, i, pos);
    }
}

void Print(int array[], int size)
{
    cout << endl;
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[10] = {3, 2, 25, 20, 89, 5, 23, 1, 87, 8 };
    SelectionSort(array, 10);

    Print(array, 10);
}
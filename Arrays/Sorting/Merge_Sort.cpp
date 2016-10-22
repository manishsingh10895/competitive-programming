#include <iostream>
#include <limits>

using namespace std;

// Merging two arrays into a bigger array
void Merge(int Array[], int l, int m, int r)
{
    int nLeft = m - l + 1;
    int nRight = r - m;

    int Left[nLeft + 1]; int Right[nRight + 1];

    // Filling the partitioned arrays with relevant values
    for(int i = 0; i < nLeft; i++) {
        Left[i] = Array[l + i];
    }
    for(int i = 0; i < nRight; i++) {
        Right[i] = Array[m+i+1];
    }

    // Ending both arrays with Sentinal element i.e MAX 
    Left[nLeft] = numeric_limits<int> :: max();
    Right[nRight] = numeric_limits<int> :: max();

    int j = 0; int k = 0;
    int i = l;
    // Loop to fill the bigger array with sorted elements
    while(j < nLeft && k < nRight)
    {
        if(Left[j] < Right[k]) {
            Array[i] = Left[j];
            j++;
        } else {
            Array[i] = Right[k];
            k++; 
        } 

        i++;
    }

    // If any one of the sub arrays is not traversed completely 
    // lets do it
    while(j < nLeft) {
        Array[i] = Left[j];
        j++;
        i++;
    }

    while(k < nRight) {
        Array[i] = Right[k];
        k++;
        i++;
    }
} 

void MergeSort(int Array[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        MergeSort(Array, l, m);
        MergeSort(Array, m+1, r);

        Merge(Array, l, m, r);
    } 
}

int main()
{
    int a[10] = {1,4,2,6,7,5,10,9,3,8};

    MergeSort(a, 0,10);

    for(int i = 0; i < 10;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
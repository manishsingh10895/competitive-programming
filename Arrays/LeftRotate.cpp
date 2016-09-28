//Rotating a 1-D array by a a number of places
//Based on Juggling Algorithms

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if(b==0)
        return a;
    return GCD(b, a%b);
}

//Rotate the array by x places
void LeftRotate(int array[], int x, int size)
{   
    int j,k;
    for(int i = 0; i < GCD(size, x); i++)
    {
        int temp  = array[i];
        j = i;
        while(true)
        {
            k = j + x;
            if(k >= size) 
                k = k - size;

            if(k == i) break; // while loop traversed the whole array

            array[j] = array[k]; 
            j = k;
        }
        array[j] = temp;
    }
}

void Print(int array[], int size)
{
    cout << endl;
    for(int i =0; i< size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}


int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    LeftRotate(array, 3, 12);

    Print(array, 12);
}

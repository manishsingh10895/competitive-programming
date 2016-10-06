#include <iostream>
#include <limits>

void Merge(int Left[], int Right[], int Array[], int size)
{
    int i = 0; int l = 0; int r = 0;
    while(i < size)
    {
        // cout << "Left " << Left[l] << " " << l;
        // cout << "Right " << Right[r] << " " << r;
        
        if(Left[l] < Right[r])
        {
            std::cout << "L " << l; 
            Array[i] = Left[l];
            l++;
        }
        else 
        {
            Array[i] = Right[r];
            r++;
        }
        i++;
    }
}


void Print(int array[], int size)
{
    std::cout << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;
}


int main()
{
    int L[6] = {1,2,3,4,5, std::numeric_limits<int>::max()};
    int R[6] = {6,7,8,9,10, std::numeric_limits<int>::max()};

    int Array[10] = {1,5,6,7,2,3,10,9,8,4};

    Merge(L, R, Array, 10);

    Print(Array, 10);
}
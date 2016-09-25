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
void LeftRotate(int array[], int x)
{   
    
    for(int i = 0; i < GCD(array.size(), x); i++)
    {
        
    }
}


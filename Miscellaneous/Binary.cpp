// Converting from a deciml number to Binary
#include <iostream>
#include <cmath>
using namespace std;

string ToBinary(int n)
{
   string bin = "";
   while(n >0)
   {
       int rem = n%2;
       n /= 2;
       bin += rem;
   }

   return bin;
}

int main()
{
    
    string binary = ToBinary(27);

    cout << binary << endl;
}

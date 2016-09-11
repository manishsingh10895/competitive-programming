#include <iostream>

using namespace std;

long Exponent(long, long);

int main()
{
    long a,b;
    cout << "Enter the base number\t";
    cin >> a;

    cout << "Enter the power \t";
    cin >> b;

    long result = Exponent(a, b);
    cout << "The power of " << a << " to " << b << " is " << result << "\n";
    
}

/**
    CS-11 Asn 2
    
    Purpose: Calculate Power of a to b

    @author Manish Singh
    @version 1.1 4/10/16 
*/
long Exponent(long a, long b)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    //Calculate half of the power of a
    long temp = Exponent(a, b/2);

    //Then multiply again twice 
    return temp * temp * Exponent(a, (b%2)); // for odd and even consideration
}
//Program for implementing GCD of two number
#include <iostream>
using namespace std;

long GCD(long, long);

int main()
{      
    long a,b;
    
    cout << "Enter the first number\t\t";
    cin >> a;
    cout << "Enter the second number\t\t";
    cin >> b;

    cout << "GCD of the two numbers is \t";
    cout << GCD(a, b) << endl;
}

long GCD(long a, long b)
{
    if(b==0) {
        return a;
    }

    GCD(b, a%b);
}
// for calculating prime number within range
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long> GetPrimes(long);

void PrintVector(vector<long>);

int main()
{   
    long n;
    //Input
    cout << "Enter upto which number you want to prime numbers\t";
    cin >> n;

    vector<long> primes = GetPrimes(n);

    cout << "\nThere are " << primes.size() << " primes within the range\n";

    cout << "All Primes between 1 and "<< n << endl;
    PrintVector(primes);

    cin.get();
}

void PrintVector(vector<long> v)
{
    vector<long>::iterator iter = v.begin();

    while(iter != v.end())
    {
        cout << *iter << endl;
        iter++;
    }
}

vector<long> GetPrimes(long n)
{
    //Reserves the approximate size in vector
    vector<long> primes;

    //Push 2 in the vector
    primes.push_back(2);

    if(n == 2) 
    {
        return primes;
    }

    for(long i = 3; i <= n; i+= 2) //eliminating all the even numbers 
    {
        bool isPrime = true;
            
        for(long j = 0; primes[j] * primes[j] <= i; j++)  //similar to using sqrt() as the ending condition, but it takes less time
        {
            if(i % primes[j] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if(isPrime)
        {
            primes.push_back(i);
        }
    }

    return primes;
}
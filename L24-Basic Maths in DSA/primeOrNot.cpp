// Sieve of Eratosthenes.
// Most efficient way for finding all prime no till n.(can be a million)
// 1st Consider all the no from 0 to n as prime
// Then remove the no which are multiples.

#include <bits/stdc++.h>
using namespace std;

int noOfPrime(int n)
{
    int count = 0;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = false;
            }
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << noOfPrime(n) << endl;

    return 0;
}
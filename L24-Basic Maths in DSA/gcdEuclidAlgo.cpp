// GCD of 2 no.s using Elucid Algorithm.
// GCD of a,b is gcd of(a-b,b)
// Process goes until one side is zero.
// Then return the other no.

#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n)
{

    while (m - n != 0)
    {
        if (m > n)
            m = m - n;
        else
            n = n - m;
    }

    return m;
}

int main()
{
    int m, n;
    cin >> m >> n;
    if (m > n)
        cout << gcd(m, n) << endl;
    else
        cout << gcd(n, m) << endl;
    return 0;
}
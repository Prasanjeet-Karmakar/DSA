// Finding (a^b) % n without going O(n) times and increasing the variable size.
// When b is odd => a^((b/2)^2) * a
// When b is even => a^((b/2)^2)
// Iterate it and will ultimately reach the result.

#include <bits/stdc++.h>
using namespace std;

int moduloExponent(int a, int b, int n)
{

    int result = 1;
    while (b > 0)
    {

        if (b & 1) // using bitwise is more efficient than modulous.
        {
            result = (1LL * result * (a) % n) % n;
        }
        a = (1LL * (a) % n * (a) % n) % n;
        b = b >> 1; // Dividing by 2
    }

    return result;
}

int main()
{
    int a, b, n;
    cin >> a >> b >> n;

    cout << moduloExponent(a, b, n) << endl;

    return 0;
}
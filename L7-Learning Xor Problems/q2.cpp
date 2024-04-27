// Complement of base 10 integer
// Eg. 5 -> 2
// 101 -> 010

#include <iostream>

using namespace std;

int main()
{

    int n, m;
    cin >> n;
    m = n;
    int mask = 0;

    if (m == 0)
        cout << 1;

    else
    {
        while (m != 0)
        {
            mask = (mask << 1) | 1; // creating 2^n - 1 where n is the no of digit.
            m = m >> 1;
        }
        // cout << ~n << endl;
        int ans = (~n) & mask; // negation will reverse the 0's to 1's and vice versa.
        cout << ans;
    }
}
// Reverse Integer
// Return 0 if reversing the integer exceed the 32 bit limit.

#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int rev = 0;

    while (n != 0)
    {
        if ((rev > INT32_MAX / 10) || (rev < INT32_MIN / 10))
        {
            rev = 0;
            break;
        }
        else
        {
            rev = (rev * 10) + n % 10;
            n = n / 10;
        }
    }

    cout << rev;
}
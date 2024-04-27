// Check if the no is power of 2 or not.
// Not a optimised solution , as it is a brute force.

#include <iostream>
using namespace std;

int main()
{

    int n;
    int ans = 1;
    for (int i = 0; i < 30; i++)
    { // checking with everypower of 2 till INT_MAX

        if (ans == n)
        {
            cout << "Yes" << endl;
            break;
        }

        if (ans < INT32_MAX / 2)
            ans = ans * 2;
    }

    return 0;
}
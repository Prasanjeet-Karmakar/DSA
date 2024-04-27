// Check if the no is power of 2 or not.

#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter the no: " << endl;
    cin >> n;

    int f = 0;
    while (n != 0)
    {
        int bit = n & 1;
        if (bit == 1)
        {
            f++;
        }
        if (f > 1)
            break;

        n = n >> 1;
    }

    if (f == 1)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

    return 0;
}
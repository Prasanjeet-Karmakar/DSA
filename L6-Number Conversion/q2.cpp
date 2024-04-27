// Conversion of -ve no to binary

#include <math.h>
#include <iostream>

using namespace std;

int main()
{

    int n, ans = 0, i = 0;
    cout << "Enter the -ve no" << endl;
    cin >> n;

    while (n != 0)
    {
        int bit = n & 2;
        ans = (bit * pow(10, i)) + ans;
        i++;
        n = n >> 2;
    }

    cout << n;
}
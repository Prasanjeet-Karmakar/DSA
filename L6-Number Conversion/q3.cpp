// binary to decimal

#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int n, ans = 0, i = 0;
    cout << "Enter the binary no." << endl;
    cin >> n;

    while (n != 0)
    {
        int bit = n % 10;
        ans = ans + (bit * pow(2, i));
        n = n / 10;
        i++;
    }

    cout << ans;
}
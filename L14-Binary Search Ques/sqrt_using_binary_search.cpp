// Find square root of a number using binary search.
// O(n) -> O(log n)

#include <iostream>
using namespace std;

// Returns only the integer part of the square root.
int sqrt(int n)
{
    int s = 1, e = n, mid;

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (mid * mid == n)
            return mid;

        else if (mid * mid > n)
        {
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }

    return mid - 1;
}

// Returns the double part of the square root.

double squareRoot(int a, int n)
{
    int pre;
    cout << "Enter the precision" << endl;
    cin >> pre;
    double ans = a;
    double factor = 1;

    for (int i = 1; i <= pre; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;

    int sqt = sqrt(n);

    cout << sqt << endl;
    double sq = squareRoot(sqt, n);
    cout << sq << endl;

    return 0;
}
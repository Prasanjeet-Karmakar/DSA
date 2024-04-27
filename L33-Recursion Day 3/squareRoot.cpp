// Find the square root of a no. using recursion.

#include <iostream>
#include <vector>
using namespace std;

int sqrt(int s, int n, int target)
{
    // Base Case
    if (s > n)
        return -1;

    int mid = s + (n - s) / 2;
    if (mid * mid == target)
    {
        return mid;
    }
    else if (mid * mid > target)
    {
        sqrt(s, mid - 1, target);
    }
    else
    {
        int ans = mid;
        int final = sqrt(mid + 1, n, target);
        if (final != -1)
            return final;
        else
            return ans;
    }
}

int main()
{

    int n;
    cin >> n;
    cout << sqrt(1, n, n) << endl;

    return -1;
}
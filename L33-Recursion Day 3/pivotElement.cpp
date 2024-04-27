// Finding pivot element in a rotated array using recursion.

#include <vector>
#include <iostream>
using namespace std;

int pivotElement(vector<int> &v, int s, int e)
{
    // Base Case
    if (s > e)
        return -1;

    // Recursive Call
    int mid = s + (e - s) / 2;
    if (v[mid] >= v[0])
    {
        int ans = mid;
        int final = pivotElement(v, mid + 1, e);
        if (final == -1)
            return ans;
        else
            ans = final;

        return ans;
    }

    else
    {
        pivotElement(v, s, mid - 1);
    }
}

int main()
{

    int n, temp;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << pivotElement(v, 0, n - 1) << endl;

    return 0;
}
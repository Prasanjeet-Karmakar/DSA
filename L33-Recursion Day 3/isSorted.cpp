// Check by recursion whether the array is sorted or not?

#include <iostream>
#include <vector>
using namespace std;

void isSorted(vector<int> &v, int n)
{
    if (n == 0)
    {
        cout << "sorted" << endl;
        return;
    }
    if (v[n] >= v[n - 1])
        isSorted(v, n - 1);
    else
    {
        cout << "not sorted" << endl;
        return;
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    isSorted(v, n - 1);

    return 0;
}
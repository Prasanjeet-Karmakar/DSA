// Find the element which has appeared only once in a sorted array.
// Time complexity = O(log n)
// {1,1,2,2,3,4,4} => 3
// {1,2,2,3,3,4,4} => 1
// {1,1,2,3,3} => 2
#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int> v)
{
    int s = 0, e = v.size() - 1;

    if (e == 0)
        return v[e];

    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (v[mid] != v[mid - 1] && v[mid] != v[mid + 1] && mid != 0 && mid != v.size() - 1)
            return v[mid];

        if (mid & 1)
        {
            if (v[mid] == v[mid - 1])
                s = mid + 1;
            else if (v[mid] == v[mid + 1])
            {
                e = mid - 1;
            }
        }
        else
        {
            if (v[mid] == v[mid - 1])
            {
                e = mid - 2;
                if (e == s - 1)
                    e++;
            }
            else if (v[mid] == v[mid + 1])
            {
                s = mid + 2;
                if (s == e + 1)
                    s--;
            }
        }
        mid = s + (e - s) / 2;
    }

    return v[mid];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << searchElement(v) << endl;

    return 0;
}
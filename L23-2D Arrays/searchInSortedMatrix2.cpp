// Matrix are arranged in such a way that:
// Elements in the row are in ascending order.
// Elements in the column are in ascending order.
// Eg.   1 2 6 8
//       3 5 11 17
//       9 10 13 21
//       12 15 18 23
// Binary Search.

#include <bits/stdc++.h>
using namespace std;

bool searchElement(vector<vector<int>> &arr, int target)
{
    int n = arr.size() - 1, m = arr[0].size() - 1;
    int i = 0, j = m;

    while (i <= n && j >= 0)
    {
        if (arr[i][j] == target)
            return 1;

        else if (arr[i][j] > target)
            j--;

        else
            i++;
    }

    return 0;
}

int main()
{

    int n, m, temp;
    cin >> n >> m;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        arr.push_back(v);
    }

    cin >> temp;

    cout << searchElement(arr, temp) << endl;

    return 0;
}
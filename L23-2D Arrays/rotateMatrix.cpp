// Rotate the matrix by 90 deg clockwise.
// Eg: 1 2 3        7 4 1
//     4 5 6   =>   8 5 2
//     7 8 9        9 6 3

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<vector<int>> &arr, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateArray(vector<vector<int>> &arr)
{
    int n = arr.size() - 1;
    vector<vector<int>> ans;
    vector<int> temp;
    for (int i = 0; i <= n; i++)
    {
        vector<int> temp;
        for (int j = n; j >= 0; j--)
        {
            temp.push_back(arr[j][i]);
        }
        ans.push_back(temp);
    }

    arr = ans;
    printArray(arr, n);
}

int main()
{
    int n, temp;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        arr.push_back(v);
    }
    printArray(arr, n - 1);
    cout << endl
         << endl;
    rotateArray(arr);

    return 0;
}
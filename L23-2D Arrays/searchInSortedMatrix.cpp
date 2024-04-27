// Elements stored in matrix are sorted in ascending order in row column format.
// Find the element in the matrix in O(log(nm))

#include <bits/stdc++.h>
using namespace std;

bool searchElement(vector<vector<int>> &matrix, int target)
{
    int s = 0, e = matrix.size() - 1;
    int st = 0, en = matrix[0].size() - 1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        // If element is present in the mid row.
        if (matrix[mid][0] <= target && matrix[mid][matrix[0].size() - 1] >= target)
        {
            while (st <= en)
            {
                int m = st + (en - st) / 2;
                if (matrix[mid][m] == target)
                    return true;

                else if (matrix[mid][m] > target)
                    en = m - 1;

                else if (matrix[mid][m] < target)
                    st = m + 1;
            }
            return false;
        }

        // Element not present in the mid row.
        else if (matrix[mid][matrix[0].size() - 1] < target)
            s = mid + 1;

        else if (matrix[mid][0] > target)
            e = mid - 1;
    }

    return false;
}

// Approach 2 (Love Babbar)

bool searchEle(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int s = 0, e = m * n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int i = mid / n, j = mid % n;
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return false;
}

int main()
{
    int n, m, temp;
    cin >> n >> m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        matrix.push_back(v);
    }

    cin >> temp;
    cout << searchElement(matrix, temp) << endl;
    cout << searchEle(matrix, temp) << endl;

    return 0;
}
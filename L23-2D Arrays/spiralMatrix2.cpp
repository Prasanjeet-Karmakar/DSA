// Creating a spiral matrix with given value n.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n);
        ans.push_back(temp);
    }

    int startRow = 0, startCol = 0;
    int endRow = n - 1, endCol = n - 1;
    int count = 1, i = 0, j = 0;
    while (startRow <= endRow && startCol <= endCol)
    {
        for (j = startCol; j <= endCol; j++)
            ans[i][j] = count++;

        startRow++;
        j--;

        for (i = startRow; i <= endRow; i++)
            ans[i][j] = count++;

        i--;
        endCol--;
        for (j = endCol; j >= startCol; j--)
            ans[i][j] = count++;

        endRow--;
        j++;
        for (i = endRow; i >= startRow; i--)
            ans[i][j] = count++;

        startCol++;
        i++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans = generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
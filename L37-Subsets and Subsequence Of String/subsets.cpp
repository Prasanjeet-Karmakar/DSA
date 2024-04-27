// Find all the subsets of the array.
// Recursion, include and exclude principle.
// Eg: [1,2,3] => [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int index, vector<int> output, vector<vector<int>> &ans)
{
    // Base Case ...
    if (index >= v.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude Case
    solve(v, index + 1, output, ans);

    // Include Case
    output.push_back(v[index]);
    solve(v, index + 1, output, ans);
}

vector<vector<int>> subSet(vector<int> &v)
{

    vector<vector<int>> ans;
    vector<int> output;

    solve(v, 0, output, ans);

    return ans;
}

int main()
{

    int n, temp;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    vector<vector<int>> ans = subSet(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
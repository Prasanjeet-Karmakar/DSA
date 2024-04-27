// Possible 4 length combinations of an array..

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int index, vector<int> output, vector<vector<int>> &ans)
{
    // Base Condition...
    if (output.size() >= 4)
    {
        ans.push_back(output);
        return;
    }
    if (index >= v.size())
    {
        return;
    }
    // Exclusion and Inclusion..
    solve(v, index + 1, output, ans);
    output.push_back(v[index]);
    solve(v, index + 1, output, ans);
}

vector<vector<int>> combination(vector<int> &v)
{
    vector<vector<int>> ans;
    vector<int> output;
    solve(v, 0, output, ans);

    return ans;
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
    cout << endl;
    vector<vector<int>> ans = combination(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
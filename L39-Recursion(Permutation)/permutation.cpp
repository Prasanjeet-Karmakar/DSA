// Permutaion of a given vector...
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> v, int index, vector<vector<int>> &ans)
{
    // Base Condition
    if (index >= v.size() - 1)
    {
        ans.push_back(v);
        return;
    }

    for (int i = index; i < v.size(); i++)
    {
        swap(v[i], v[index]);
        solve(v, index + 1, ans);
    }
}

vector<vector<int>> permutation(vector<int> &v)
{
    vector<vector<int>> ans;
    solve(v, 0, ans);

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
    vector<vector<int>> ans = permutation(v);

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
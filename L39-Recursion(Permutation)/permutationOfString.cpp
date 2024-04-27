// Find all the possible permutations of the string.
// abc = abc, acb, bac, bca, cab, cba

#include <bits/stdc++.h>
using namespace std;

void solve(string s, int index, string temp, vector<string> &ans)
{
    // Base Case...
    if (index >= s.size() - 1)
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        solve(s, index + 1, temp, ans);
    }
}

vector<string> permutation(string s)
{
    vector<string> ans;
    string temp = "";
    solve(s, 0, temp, ans);

    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = permutation(s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
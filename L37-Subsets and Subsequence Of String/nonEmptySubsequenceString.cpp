// Find all the non empty subsequence of the string.
// A subsequence is subsets where order is preserved.
// abc = a, b, c, ab, ac, bc, abc

#include <bits/stdc++.h>
using namespace std;

void solve(string s, int index, string output, vector<string> &ans)
{

    // Base Case..
    if (index >= s.size())
    {
        if (output != "")
            ans.push_back(output);
        return;
    }
    // Exclude
    solve(s, index + 1, output, ans);

    // Include
    output += s[index];
    solve(s, index + 1, output, ans);
}

vector<string> subsequence(string s)
{
    vector<string> ans;
    string output;
    solve(s, 0, output, ans);

    return ans;
}

int main()
{

    string s;
    cin >> s;
    vector<string> ans = subsequence(s);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(string s, int index, string output, vector<string> &ans)
{
    if (index >= s.size())
    {
        ans.push_back(output);
        return;
    }

    string keyPad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int sindex = s[index] - '0';
    for (int i = 0; i < keyPad[sindex].size(); i++)
    {
        output += keyPad[sindex][i];
        solve(s, index + 1, output, ans);
        output.pop_back();
    }
}

vector<string> keypad(string s)
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
    vector<string> ans = keypad(s);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
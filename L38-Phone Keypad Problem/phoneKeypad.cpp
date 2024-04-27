// Find the total no combinations we can make when pressing specific key.
// Eg. {2,3} => {a,d}, {a,e}, {a,f}, {b,d}, {b,e}, {b,f}, {c,d}, {c,e}, {c,f}.

#include <bits/stdc++.h>
using namespace std;

void solve(string &digits, int index, string temp, vector<string> &ans)
{
    string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // Base Case...
    if (index >= digits.size())
    {
        ans.push_back(temp);
        return;
    }

    int number = digits[index] - '0';

    for (int i = 0; i < keypad[number].size(); i++)
    {
        temp += keypad[number][i];
        solve(digits, index + 1, temp, ans);
        temp.pop_back();
    }
}

vector<string> combinations(string &digits)
{
    vector<string> ans;
    string temp = "";

    solve(digits, 0, temp, ans);
    return ans;
}

int main()
{

    string digits;
    cin >> digits;

    vector<string> ans = combinations(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
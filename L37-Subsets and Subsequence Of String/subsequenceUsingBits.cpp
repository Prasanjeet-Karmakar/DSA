// Finding subsequences using bits manipulation

#include <bits/stdc++.h>
using namespace std;

vector<string> subsequence(string s)
{

    vector<string> ans;
    string output = "";
    for (int i = 0; i < (1 << s.size()); i++)
    {
        output = "";
        for (int j = 0; j <= s.size() - 1; j++)
        {
            if (i & (1 << j))
                output += s[j];
        }
        ans.push_back(output);
    }

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
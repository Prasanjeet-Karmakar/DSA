// Remove the adjacent characters in the string.
// Eg. abbaca => ca

#include <bits/stdc++.h>
using namespace std;

string removeAdjacent(string s)
{
    int i = 1;
    while (s.length() > 0 && i < s.length())
    {
        if (s[i] == s[i - 1])
        {
            s.erase(i - 1, 2);
            i--;
        }
        else if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
        }
        else
            i++;
    }

    return s;
}

// Approach 2
string removeDuplicates(string s)
{

    string ans;
    ans.push_back(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == ans.back())
            ans.pop_back();
        else
            ans.push_back(s[i]);
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << removeAdjacent(s) << endl;

    return 0;
}
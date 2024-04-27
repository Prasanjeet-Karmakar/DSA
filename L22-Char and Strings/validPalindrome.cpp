// LeetCode que
// Remove all the non alphanumeric character and check whether the string is plaindrome or not (not case sensitive.)

// "8V8K;G;K;V;" -> TLE

#include <bits/stdc++.h>
using namespace std;

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        ch = ch - 'A' + 'a';

    return ch;
}

bool isPalindrome(string s)
{
    int i = 0, e = s.length() - 1;
    while (i < e)
    {
        s[i] = toLower(s[i]);
        s[e] = toLower(s[e]);
        if (((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) && ((s[e] >= 'a' && s[e] <= 'z') || (s[e] >= '0' && s[e] <= '9')))
        {
            if (s[i] != s[e])
            {
                return false;
            }
            i++;
            e--;
        }
        else if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
            i++;
        else if (!((s[e] >= 'a' && s[e] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
            e--;
    }
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    cout << isPalindrome(s) << endl;

    return 1;
}
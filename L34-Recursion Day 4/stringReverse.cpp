// Print the string reverse using recursion.
// Reverse the string using recursion.
#include <bits/stdc++.h>
using namespace std;

// Printing the string in reverse.
void print(string s, int n = 0)
{
    if (n == s.size())
        return;

    print(s, n + 1);
    cout << s[n];
}

// Reversing the actual string
void reverse(string &s, int st = 0)
{
    // Base Case...
    if (st > s.size() - 1 - st)
    {
        return;
    }
    swap(s[st], s[s.size() - 1 - st]);
    reverse(s, st + 1);
}

// Checking if the string is palindrome or not.
bool checkPalindrome(string &s, int st = 0)
{

    // Base Case
    if (s.size() == 1)
        return true;
    if (st > s.size() - 1 - st)
        return true;

    // End Case
    if (s[st] != s[s.size() - 1 - st])
        return false;

    return checkPalindrome(s, st + 1);
}

int main()
{

    string s;
    cin >> s;
    // print(s);
    // cout << endl;
    // reverse(s);
    // cout << s << endl;
    cout << checkPalindrome(s) << endl;

    return 0;
}
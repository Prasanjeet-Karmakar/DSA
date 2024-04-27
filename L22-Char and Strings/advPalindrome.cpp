// Check whether the string is palindrome or not.
// Do not bother about the whitespace and special characters.

#include <bits/stdc++.h>
using namespace std;

void checkPalindrome(string str)
{
    cout << str << endl;
    int s = 0, e = str.size() - 1;
    while (s <= e)
    {
        if ((str[s] >= 'a' && str[s] <= 'z') && (str[e] >= 'a' && str[e] <= 'z') || (str[s] >= 'A' && str[s] <= 'Z') && (str[e] >= 'A' && str[e] <= 'Z'))
        {
            str[s] -= 'A' + 'a';
            str[e] -= 'A' + 'a';
            cout << str[s] << str[e] << endl;
            if (str[s] != str[e])
            {
                cout << "Not a Palindrome" << endl;
                return;
            }
            s++;
            e--;
        }
        else if (!(str[s] >= 'a' && str[s] <= 'z') || (str[s] >= 'A' && str[s] <= 'Z'))
        {
            s++;
        }
        else if (!(str[e] >= 'a' && str[e] <= 'z') || (str[e] >= 'A' && str[e] <= 'Z'))
        {
            e--;
        }
    }

    cout << "Palindrome" << endl;
}

int main()
{

    string str;
    cin >> str;
    checkPalindrome(str);
}
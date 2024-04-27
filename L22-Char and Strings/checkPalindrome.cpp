// Check whether the string is palindrome or not?
// Palindrome is one in which reverse of the string is the string itself.
// Eg. mom is palindrome.
// Eg. go is not a palindrome.

#include <bits/stdc++.h>
using namespace std;

void checkPalindrome(char str1[])
{
    int len = 0;
    while (str1[len] != '\0')
    {
        len++;
    }
    len = len - 1;
    int s = 0, e = len;
    while (s < e)
    {
        if (str1[s] != str1[e])
        {
            cout << "Not a Palindrome" << endl;
            return;
        }
        else
        {
            s++;
            e--;
        }
    }

    cout << "Palindrome" << endl;
}

int main()
{

    char str1[20];
    cin >> str1;

    checkPalindrome(str1);

    return 0;
}
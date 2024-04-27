// Check the maximum occuring character in the string.
// Eg. test
// output => t

#include <bits/stdc++.h>
using namespace std;

char checkMaxOccurence(string s)
{
    int val;
    int count[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            val = s[i] - 'A';
            count[val]++;
        }

        else
        {
            val = s[i] - 'a';
            count[val]++;
        }
    }

    // Checking the character with the largest frequency.
    int max = 0;
    for (int i = 1; i < 26; i++)
    {
        if (count[max] < count[i])
            max = i;
    }

    cout << max << endl;
    char c = char('a' + max);

    return c;
}

int main()
{

    string s;
    cin >> s;

    cout << checkMaxOccurence(s) << endl;

    return 0;
}
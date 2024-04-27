// Premium leetcode que
// Reverse words in string.
// i/p = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'}
// output = {'b','l','u','e',' ','i','s',' ','s','k','y',' ','t','h','e'}
// Solve the problem without taking extra space.

#include <bits/stdc++.h>
using namespace std;

void reverseWords(vector<char> &v)
{
    vector<char> temp;
    int s = v.size() - 1, e;
    for (int i = v.size() - 1; i >= 0; i++)
    {

        if (v[i] == ' ')
        {
            e = i;
            for (int j = s; s >= e; s--)
            {
                        }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);
    }

    reverseWords(v);
}

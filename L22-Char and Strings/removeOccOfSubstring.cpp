// Provided a string and a sub string and we have to replace all the possible substring in the main string
// Return the final string.
// Eg. string = daabcbaabcbc and substring = abc
// dabaabcbc => dababc => dab
// cplusplus site reference..

#include <bits/stdc++.h>
using namespace std;

string removeSubString(string s, string ss)
{

    while (s.length() > 0 && s.find(ss) < s.length()) // s.find() returns the starting index of the substring.
    {
        s.erase(s.find(ss), ss.length()); // takes starting index and length as parameter.
    }

    return s;
}

int main()
{
    string s, ss;
    cin >> s >> ss;

    cout << removeSubString(s, ss) << endl;

    return 0;
}
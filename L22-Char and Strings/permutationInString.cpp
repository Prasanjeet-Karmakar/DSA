// There are 2 strings provided s1 and s2.
// Check whether the permutation of s1 is present in s2.
// Eg. s1 = ab   s2 = eidbaooo
// Output : true

#include <bits/stdc++.h>
using namespace std;

bool checkPermutation(string s1, string s2)
{
    int len1 = s1.length();
    int itr = 0;
    int arr[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        arr[s1[i] - 'a']++;
    }

    int count[26] = {0};
    int itr = 0, i = 0;
    for (int i = 0; i < s2.length(); i++)
    {
        if (i - itr <= s1.length())
        {
            count[s2[i] - 'a']++;
            if (count[s2[i] - 'a'] > arr[s2[i] - 'a'])
            {
            }
        }
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << checkPermutation(s1, s2) << endl;
}
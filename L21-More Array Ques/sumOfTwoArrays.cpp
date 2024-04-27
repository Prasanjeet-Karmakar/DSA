// 2 arrays are provided and we have to return the array with the result sum.
// Eg. [1,2,3,4] and [3,3]
//  1 2 3 4
// +    3 3
//  1 2 6 7 will be the output.

#include <bits/stdc++.h>
using namespace std;

void sum(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int carry = 0, sum, ivalue, jvalue;
    vector<int> result;

    for (int i = arr1.size() - 1, j = arr2.size() - 1; i >= 0 || j >= 0; i--, j--)
    {
        // Checking for not equal no of elements in both array.
        if (i < 0)
            ivalue = 0;
        else
            ivalue = arr1[i];
        if (j < 0)
            jvalue = 0;
        else
            jvalue = arr2[j];

        if (ivalue + jvalue + carry < 10)
        {
            sum = ivalue + jvalue + carry;
            carry = 0;
            result.push_back(sum);
        }
        else
        {
            sum = ivalue + jvalue + carry;
            carry = 1;
            sum = sum % 10;
            result.push_back(sum);
        }
    }

    if (carry == 1)
    {
        result.push_back(carry);
        cout << result[result.size() - 1] << endl;
    }

    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, m, temp;
    vector<int> arr1, arr2;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr1.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        arr2.push_back(temp);
    }

    sum(arr1, n, arr2, m);

    return 0;
}
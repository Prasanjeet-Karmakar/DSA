// Print the matrix m x n in a spiral form.
// Important que asked frequently in Amazon.
// 1 2 3
// 4 5 6
// 7 8 9

// Output => 1 2 3 6 9 8 7 4 5

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Print spiral ...

    int flag = 0, Mrow = n - 1, Mcol = m - 1, mrow = 0, mcol = 0;
    int i = 0, j = 0;

    while (Mrow >= mrow && Mcol >= mcol)
    {
        if (flag == 0)
        {
            while (j <= Mcol)
            {
                cout << arr[i][j] << " ";
                j++;
            }
            mrow++;
            i++;
            j--;
            flag = 1;
        }
        else if (flag == 1)
        {
            while (i <= Mrow)
            {
                cout << arr[i][j] << " ";
                i++;
            }
            Mcol--;
            i--;
            j--;
            flag = 2;
        }
        else if (flag == 2)
        {
            while (j >= mcol)
            {
                cout << arr[i][j] << " ";
                j--;
            }
            j++;
            Mrow--;
            i--;
            flag = 3;
        }
        else if (flag == 3)
        {
            while (i >= mrow)
            {
                cout << arr[i][j] << " ";
                i--;
            }
            i++;
            mcol++;
            j++;
            flag = 0;
        }
    }

    return 0;
}
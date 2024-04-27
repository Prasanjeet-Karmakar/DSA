// Similar to Book Allocation Problem.
// m boards and n painters where m>n
// arr of m contains unit of work required for each board.
// Each painter can perform 1 unit of work in 1 unit time.
// Find the minimum time req for the painter.
// Eg. [10,10,10,10] and n=2
// Output: 20

#include <iostream>
using namespace std;

int isPossibleSoln(int arr[], int m, int n, int mid)
{
    int work = 0;
    int painterCount = 1;
    for (int i = 0; i < m; i++)
    {
        if (work + arr[i] <= mid)
        {
            work += arr[i];
        }
        else
        {
            painterCount++;
            if (painterCount > n || arr[i] > mid)
            {
                return false;
            }
            work = arr[i];
        }
    }

    return true;
}

int minWork(int arr[], int m, int n)
{

    int s = 0, e = 0;
    int ans = -1;
    for (int i = 0; i < m; i++)
    {
        e += arr[i];
    }

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossibleSoln(arr, m, n, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int main()
{

    int m, n;
    cin >> m >> n;
    int arr[m];

    for (int i = 0; i < m; i++)
        cin >> arr[i];

    cout << minWork(arr, m, n) << endl;

    return 0;
}
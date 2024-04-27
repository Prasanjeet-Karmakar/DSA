// m no of stalls and n no of cows (m>n).
// Arr of m consisting of stall no.
// Assign cows in such a way that the distance between cows are maximum.
// Binary Search Application.

#include <iostream>
using namespace std;

int maxDistance(int stalls[], int m, int n)
{
}

int main()
{
    int m, n;
    cin >> m >> n;
    int stalls[m];

    for (int i = 0; i < m; i++)
    {
        cin >> stalls[i];
    }

    cout << maxDistance(stalls, m, n);
    return 0;
}
// There are m books and n students (m>n) and n>=2.
// Array consits of m elements and each index represent the pages of the book.
// Distribute the book among the students such that
//  1. Each student gets atleast 1 book.
//  2. Book distributed should be contiguous in manner.
//  3. Every book should be distributed.

// Return the maximum of minimum no of pages assigned to the students.
// Eg. m = [10,20,30,40] n=2
// [10], [20,30,40] =>90
// [10,20], [30,40] =>70
// [10,20,30], [40] =>60
// Output is 60.

#include <iostream>
using namespace std;

bool isPossibleSoln(int books[], int m, int n, int mid)
{
    int count = 0, pages = 0;

    for (int i = 0; i < m; i++)
    {
        if (pages + books[i] <= mid)
        {
            pages += books[i];
        }
        else
        {
            count++;
            if (count >= n || books[i] > mid)
                return false;
            else
            {
                pages = books[i];
            }
        }
    }
}

int minPage(int books[], int m, int n)
{
    int s = 0, e = 0, mid, ans = -1;
    for (int i = 0; i < m; i++)
        e += books[i];

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (isPossibleSoln(books, m, n, mid))
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
    int books[m];

    for (int i = 0; i < m; i++)
    {
        cin >> books[i];
    }

    cout << minPage(books, m, n) << endl;

    return 0;
}
// Matrix of boolean values are present in n x m.
// Find the largest area of rectangle which consists of only ones.
// Required logic of nearest smallest/greatest element and largest rectangle in a histogram.
// Using stack.

#include <bits/stdc++.h>
using namespace std;

void leftMin(vector<int> &nLength, vector<int> &lMin)
{
    // Finding the nearest smallest element in left.

    stack<int> st;

    for (int i = 0; i < nLength.size(); i++)
    {
        while (!st.empty() && nLength[i] <= nLength[st.top()])
        {
            st.pop();
        }
        if (st.empty())
            lMin[i] = -1;
        else
            lMin[i] = st.top();

        st.push(i);
    }
}

void rightMin(vector<int> &nLength, vector<int> &rMin)
{
    // Finding the nearest smallest element in right.

    stack<int> st;

    for (int i = nLength.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && nLength[i] <= nLength[st.top()])
        {
            st.pop();
        }
        if (st.empty())
            rMin[i] = nLength.size();
        else
            rMin[i] = st.top();

        st.push(i);
    }
}

int maxArea(vector<int> &nLength, vector<int> &lMin, vector<int> &rMin)
{
    // Finding the maximum area for the histogram formed above nth row.

    leftMin(nLength, lMin);
    rightMin(nLength, rMin);
    int maxi = -1;

    // Finding the largest area of every col.

    for (int i = 0; i < nLength.size(); i++)
    {
        int area = (rMin[i] - lMin[i] - 1) * nLength[i];

        if (area > maxi)
            maxi = area;
    }

    return maxi;
}

int largestArea(vector<vector<int>> &rect)
{
    int row = rect.size();
    int col = rect[0].size();
    int fAns = -1;

    vector<int> nLength(col);         // Contains length of the each column.
    vector<int> lMin(col), rMin(col); // Contains value of nearest smallest element for that column in left and right direction.

    // Intialising values of nLength and lMin and rMin from 1st row.

    for (int i = 0; i < col; i++)
    {
        nLength[i] = rect[0][i];
    }

    // Finding largest area present in histogram of any col.
    int result = maxArea(nLength, lMin, rMin);
    if (result > fAns)
        fAns = result;

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (rect[i][j] == 0)
            {
                nLength[j] = 0;
            }
            else
            {
                nLength[j] += 1;
            }
        }
        result = maxArea(nLength, lMin, rMin);
        if (result > fAns)
            fAns = result;
    }

    return fAns;
}

int main()
{

    vector<vector<int>> rect;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int t;
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            temp.push_back(t);
        }
        rect.push_back(temp);
    }

    cout << largestArea(rect) << endl;

    return 0;
}
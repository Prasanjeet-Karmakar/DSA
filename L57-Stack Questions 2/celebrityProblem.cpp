// Optimal approach of celebrity problem using stack.
// T.C = O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int findCelebrity(vector<vector<int>> &peoples)
{
    stack<int> st;

    // insert index of all the peoples present.
    for (int i = 0; i < peoples.size(); i++)
        st.push(i);

    // Compare two top elements of the stack.
    // If one knows another he/she cannot be a celebrity.
    // Repeat this process until 1 element is present in the stack.
    // That will be the celebrity.

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (peoples[a][b] == 0)
            st.push(a);

        if (peoples[b][a] == 0)
            st.push(b);
    }

    if (st.size() == 1)
        return st.top();
    else
        return -1;
}

int main()
{
    vector<vector<int>> peoples;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int t;
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            temp.push_back(t);
        }
        peoples.push_back(temp);
    }

    cout << findCelebrity(peoples) << "\n";

    return 0;
}
// Remove the middle element in a stack.
// Eg. 1 2 3 4 5 -> 1 2 4 5
// Eg. 1 2 3 4 -> 1 3 4

#include <iostream>
#include <stack>
using namespace std;

// Approach 2: Using recursion

void removeMiddleUtil(stack<int> &st, int count, int size)
{
    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int a = st.top();

    st.pop();
    removeMiddleUtil(st, count + 1, size);

    st.push(a);
}

void removeMiddle1(stack<int> &st)
{
    int count = 0;

    removeMiddleUtil(st, count, st.size());
}

// Approach 1: Using another stack.
void removeMiddle(stack<int> &st)
{
    stack<int> s;

    while (s.size() != st.size())
    {
        int a = st.top();
        st.pop();

        if (s.size() != st.size())
            s.push(a);
    }

    while (!s.empty())
    {
        st.push(s.top());
        s.pop();
    }
}

void display(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(5);
    display(st);
    removeMiddle1(st);
    display(st);

    return 0;
}
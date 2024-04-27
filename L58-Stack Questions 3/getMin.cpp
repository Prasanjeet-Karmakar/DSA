// Create a stack in such a way that it does all its operations as well as find minimum in O(1) T.C.
// Approach 1: Create another stack to store the minimum for every elements. S.C = O(n)
// Approach 2: Using mathematical technique to store the updated element in original stack itself. S.C = O(1)

#include <iostream>
#include <stack>
using namespace std;

// Approach 1: Using another stack.

void push1(stack<int> &st, int &minim)
{
    stack<int> mini;

    int data;
    cin >> data;

    if (st.empty())
    {
        minim = data;
        mini.push(minim);
        st.push(data);
    }

    else
    {
        minim = min(data, minim);
        mini.push(minim);
        st.push(data);
    }
}

void pop1(stack<int> &st, int &minim)
{
    int a = st.top();
    st.pop();
}

// Approach 2: Using mathematical logic.
void push2(stack<int> &st, int &minim)
{
    int data;
    cin >> data;

    if (st.empty())
    {
        minim = data;
        st.push(data);
    }

    else
    {
        if (data >= minim)
        {
            st.push(data);
        }

        else
        {
            st.push(2 * data - minim);
            minim = data;
        }
    }
}

int pop2(stack<int> &st, int &minim)
{

    if (st.empty())
    {
        return -1;
    }

    if (minim < st.top())
    {
        int a = minim;
        minim = 2 * minim - st.top();
        st.pop();
        return a;
    }
    else
    {
        int a = st.top();
        st.pop();
        return a;
    }
}

int main()
{

    stack<int> st;
    int min = 0;

    return 0;
}
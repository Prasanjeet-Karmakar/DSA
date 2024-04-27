// Check for validation of parantheses in expression.
#include <iostream>
#include <stack>
using namespace std;

bool valid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (st.empty())
                return false;

            if (s[i] == ')' && st.top() != '(')
                return false;

            else if (s[i] == ']' && st.top() != '[')
                return false;

            else if (s[i] == '}' && st.top() != '{')
                return false;

            else
                st.pop();
        }
    }

    if (!st.empty())
        return false;

    return true;
}

int main()
{
    string s;
    cin >> s;

    bool ans = valid(s);
    if (ans == true)
    {
        cout << "Valid \n";
    }
    else
    {
        cout << "Invalid \n";
    }

    return 0;
}
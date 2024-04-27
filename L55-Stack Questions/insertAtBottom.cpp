// Implement a program to insert at the bottom of the stack.

#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

void insertAtBottom(stack<int> &s, int temp)
{
    // Base Case
    if (s.empty())
    {
        s.push(temp);
        return;
    }

    int a = s.top();
    s.pop();

    insertAtBottom(s, temp);
    s.push(a);
}

int main()
{

    stack<int> s;

    s.push(1);
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(3);
    display(s);
    int temp;
    cin >> temp;

    insertAtBottom(s, temp);
    display(s);

    return 0;
}
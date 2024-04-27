// Reverse stack without using any extra memory and only through recursion.

#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &s)
{
}

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(9);
    s.push(4);
    s.push(3);
    s.push(5);
    display(s);

    reverseStack(s);
    display(s);

    return 0;
}
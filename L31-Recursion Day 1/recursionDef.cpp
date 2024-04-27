// Understanding Recursion.

#include <iostream>
using namespace std;

void fibonacci(int n, int i = 0, int j = 1)
{
    if (n == 1)
    {
        cout << i << endl;
        return;
    }

    fibonacci(n - 1, j, i + j);
}

void print(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    print(n - 1);
}

long long int factorial(int n)
{
    if (n == 0)
        return 1; // Base Case or Condition.
    else
        return n * factorial(n - 1);
}

int main()
{

    int n;
    cin >> n;
    cout << factorial(n) << endl;
    print(n);
    cout << endl;
    fibonacci(n);
    return 0;
}
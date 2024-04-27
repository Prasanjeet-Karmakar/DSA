// Find the power using fast exponentiation using recursion.
#include <iostream>

long int pow(int n, int m)
{

    // Base Case..
    if (m == 0)
        return 1;

    int ans = pow(n, m / 2);

    if (m & 1)
    {
        return n * ans * ans;
    }
    else
    {
        return ans * ans;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::cout << pow(n, m) << std::endl;

    return 0;
}
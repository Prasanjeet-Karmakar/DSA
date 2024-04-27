// A man can jump 1 or 2 stairs.
// Find the no of ways he can climb the n no of stairs.
// Basic Recursion and for optimal solution required DP.

// Eg - n = 3 , {1,1,1}, {1,2}, {2,1}
// output : 2

#include <iostream>
using namespace std;

int noOfWays(int nStairs)
{

    if (nStairs == 0)
        return 1;
    else if (nStairs < 0)
        return 0;

    // First all the 1 steps will return and then the respective 2s steps.
    return noOfWays(nStairs - 1) + noOfWays(nStairs - 2);
}

int main()
{

    int nStairs;
    cin >> nStairs;
    cout << noOfWays(nStairs) << endl;

    return 0;
}
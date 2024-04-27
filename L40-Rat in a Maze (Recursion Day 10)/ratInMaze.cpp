// Find all the possible ways in which rat can move from source to destination.
// (0,0) be the source pos while (n-1,m-1) be the destination.
// Backtracking and recursion..

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &v, int sx, int sy, int dx, int dy, string output, vector<string> &ans, vector<vector<int>> visited)
{
    // Base Case:
    if (sx == dx && sy == dy)
    {
        ans.push_back(output);
        visited[sx][sy] = 0;
        return;
    }
    visited[sx][sy] = 1;

    // Conditions:

    // Moving Right..
    if (sy + 1 < v[0].size() && v[sx][sy + 1] == 1 && visited[sx][sy + 1] == 0)
    {
        output += "R";
        solve(v, sx, sy + 1, dx, dy, output, ans, visited);
        output.pop_back(); // Backtracking when retruning to previous node we are clearing the output as the output is not required.
    }
    // Moving Down..
    if (sx + 1 < v.size() && v[sx + 1][sy] == 1 && visited[sx + 1][sy] == 0)
    {
        output += "D";
        solve(v, sx + 1, sy, dx, dy, output, ans, visited);
        output.pop_back();
    }
    // Moving Left..
    if (sy - 1 > -1 && v[sx][sy - 1] == 1 && visited[sx][sy - 1] == 0)
    {
        output += "L";
        solve(v, sx, sy - 1, dx, dy, output, ans, visited);
        output.pop_back();
    }
    // Moving Up..
    if (sx - 1 < -1 && v[sx - 1][sy] == 1 && visited[sx - 1][sy] == 0)
    {
        output += "U";
        solve(v, sx - 1, sy, dx, dy, output, ans, visited);
        output.pop_back();
    }

    visited[sx][sy] = 0;
}

vector<string> ratMaze(vector<vector<int>> &v)
{
    vector<string> ans;
    string output = "";
    int sx = 0;
    int sy = 0;
    int dx = v.size() - 1;
    int dy = dx;

    vector<vector<int>> visited(dx + 1);
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < v.size(); j++)
        {
            temp.push_back(0);
        }
        visited[i] = temp;
    }

    solve(v, sx, sy, dx, dy, output, ans, visited);

    return ans;
}

int main()
{

    int n, key;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            cin >> key;
            temp.push_back(key);
        }
        v[i] = temp;
    }

    vector<string> ans = ratMaze(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
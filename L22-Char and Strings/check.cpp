// Checking whether the char of array is passed as a reference like the same with other data type arrays.
// Yes

#include <bits/stdc++.h>
using namespace std;

void change(char name[])
{

    name[2] = '^';
    cout << name << endl;
}

int main()
{
    char ch[20];
    cin >> ch;

    change(ch);
    cout << ch << endl;

    return 0;
}
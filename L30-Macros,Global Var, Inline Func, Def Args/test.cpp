// Using macros, global var, inline function and understanding default arguments.

#include <iostream>
using namespace std;
#define PI 3.14 // Before compile time, the program will replace all location where PI is used with 3.14.
// No extra memory is required for macros.

const float pi = 3.14; // Const variable should be intialized during declaration.

// Global variable
int n = 15; // Bad practise as any func can modify the contents, rather use reference variable during sharing.

inline int update(int &a)
{
    return ++a;
}

int main()
{

    int radius;
    cin >> radius;
    double area = PI * radius * radius;
    cout << area << endl;
    int num = 10;
    num = update(num);
    cout << num << endl;
    return 0;
}
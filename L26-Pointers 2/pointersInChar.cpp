// Using pointers in char.

#include <iostream>
using namespace std;

void print(int *p)
{
    p = p + 1;
}

void update(int *p)
{
    *p = *p + 1;
}

int main()
{
    int num = 4;
    int *ptr = &num;

    cout << ptr << endl;
    char ch = 'a';
    char *c = &ch;       // pointing to 1st index of c.
    cout << &ch << endl; // printing the address of starting character.
    // like int or double pointer cout works differently for char as it prints the contents instead of address.
    cout << c << endl; // printing from address of c till there is no null.
    cout << &c << endl;

    char str[6] = "abcde"; // 1 extra length for null character
    cout << str << endl;   // print the contents of the char array.
    // char *pstr = "abcde"; // Bad practise should be avoided as it choose random memory for allocation which can also be read only.
    char *pstr = &str[0];
    cout << &str << endl;
    cout << pstr << endl;
    cout << &pstr << endl;

    print(ptr);
    cout << ptr << endl;
    cout << num << endl;
    update(ptr);
    cout << num << endl;

    return 0;
}
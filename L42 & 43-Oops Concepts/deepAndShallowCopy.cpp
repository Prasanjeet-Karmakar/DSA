// Understanding the concept of deep and shallow copy of copy constructor.

#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int rollNo;
    char *name;
    char grade;

public:
    // If anyone of the constructor is created then the default constructor by the compiler is removed.
    // Parameterised Constructor:
    Student(int rollNo, char *name, char grade)
    {
        cout << "Address Of current object : " << this << endl;
        this->rollNo = rollNo;
        strcpy(this->name, name);
        this->grade = grade;
    }

    Student(Student &S)
    {
        this->rollNo = S.rollNo;
        this->grade = S.grade;
        // Creating Deep Copy
        char *temp = new char[strlen(S.name) + 1];
        strcpy(temp, S.name);
        strcpy(this->name, temp);
    }

    // Getter and Setter
    void setRollNo(int r)
    {
        rollNo = r;
    }
    void setName(char *s)
    {
        strcpy(name, s);
    }
    void setGrade(char g)
    {
        grade = g;
    }
    int getRollNo()
    {
        return rollNo;
    }
    char *getName()
    {
        return name;
    }
    char getGrade()
    {
        return grade;
    }
};

int main()
{

    // Shallow Copy -> Using default copy constructor.
    Student s1(29, "Prasanjeet", 'B');

    Student s2(s1);

    s2.setName("Ashish");
    cout << s2.getName() << endl;
    // Here the s1 name is also changed, as the pointer for s1.name and s2.name remains the same which led to change in one change to others.
    // This phenomenon is called shallow copy, which can be rectified using the concept of deep copy by creating a copy constuctor
    // with new name pointer pointing to another address and copying the contents..
    cout << s1.getName() << endl;

    return 0;
}
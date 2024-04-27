// Understanding concept of oops in C++

#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    char grade;

public:
    // If anyone of the constructor is created then the default constructor by the compiler is removed.
    // Parameterised Constructor:
    Student(int rollNo, string name, char grade)
    {
        cout << "Address Of current object : " << this << endl;
        this->rollNo = rollNo;
        this->name = name;
        this->grade = grade;
    }

    // copy constructor
    //  The argument is passed as called by reference as in pass by value the copy is made and for copying the object again the copy constructor
    //  will be called. Hence, there will be an infinite loop of process for creation of copy object.
    Student(Student &S)
    {
        this->name = S.name;
        this->rollNo = S.rollNo;
        this->grade = S.grade;
    }
    // Getter and Setter
    void setRollNo(int r)
    {
        rollNo = r;
    }
    void setName(string s)
    {
        name = s;
    }
    void setGrade(char g)
    {
        grade = g;
    }
    int getRollNo()
    {
        return rollNo;
    }
    string getName()
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
    Student s(29, "Prasanjeet", 'B');
    cout << s.getName() << " " << s.getRollNo() << " " << s.getGrade() << endl;

    Student s2(39, "Ashish", 'A');

    Student s3(s2); // Copy constructor called, can be defined or created automatically by compiler if not present.
    cout << s3.getName() << " " << s3.getRollNo() << " " << s3.getGrade() << endl;

    return 0;
}
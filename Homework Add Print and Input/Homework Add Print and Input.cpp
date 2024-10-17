#include<iostream>
#include<cstring> 
using namespace std;

class Student
{
    char* name;
    int age;
public:
    Student();
    Student(const char* n, int a);
    Student(const Student& obj);
    ~Student();
    void Print();
    void Input();
};
Student::Student()
{
    name = nullptr;
    age = 0;
}
Student::Student(const char* n, int a)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    age = a;
}
Student::Student(const Student& obj)
{
    name = new char[strlen(obj.name) + 1];
    strcpy_s(name, strlen(obj.name) + 1, obj.name);
    age = obj.age;
    cout << "Copy constructor\n";
}
Student::~Student()
{
    cout << "Destructor\n";
    delete[] name;
    age = 0;
}
void Student::Print()
{
    cout << "Name: " << name << "\tAge: " << age << endl;
}
void Student::Input()
{
    char buffer[100];
    cout << "Enter name: ";
    cin >> buffer; 
    name = new char[strlen(buffer) + 1];
    strcpy_s(name, strlen(buffer) + 1, buffer);

    cout << "Enter age: ";
    cin >> age; 
}

int main()
{
    Student a("Ivan", 16);
    a.Print();

    Student b = a; 
    b.Print();

    Student c;
    c.Input(); 
    c.Print(); 
}

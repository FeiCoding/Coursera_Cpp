#include <iostream>
#include <string>
using namespace std;

class Student{
    int age;
    string name;
    public:
    void Print();
    Student(string name, int age): name(name), age(age){
        cout << "Constructor Called" << endl;
    };
    ~Student();  
};

Student::~Student(){
    cout << this->name << " Destructor Called." << endl;
}

void Student::Print(){
    cout << "Name is " << name << " Age is " << age << endl;
}

int main(){
    Student s("Fei", 25);
    Student *p = new Student("Xie", 24);
    p->Print();
    delete p;
    return 0;
}
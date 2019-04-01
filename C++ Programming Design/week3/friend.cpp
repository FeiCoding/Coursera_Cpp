#include <iostream>
#include <string>
using namespace std;

class Student{
    int age;
    string name;
    public:
    Student(const Student &ss){
        age = ss.age;
        name = ss.name;
        cout << ss.name << " Copy Constructor Called.  " << &ss << endl;
    }
    Student(int age, string name):age(age), name(name){cout << "Constructor Called" << endl;}
    ~Student();
    friend class Member;
};
Student::~Student(){
    cout << this-> name << " Destructor Called" << endl;
}
class Member{
    Student s;
    int mark;
    public:
    Member(const Student &ss, int mark): s(ss), mark(mark){};
    void Print();
};
void Member::Print(){
    cout << "Name: " << s.name << " Age: " << s.age << " Grade: " << mark << endl;
}

int main(){
    Student s(25, "Fei");
    //Student s2 = s;
    Member m(s, 90);
    m.Print();
    return 0;
}
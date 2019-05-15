#include <iostream>
#include <string>
using namespace std;

class Student{
    int age;
    string name;
    int id;

    public:
        Student(){}
        Student(int a, string n, int i):age(a),name(n),id(i){}
        ~Student(){
            cout << "Desctruct Student" << endl;
        }
        void print(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "id: " << id << endl;
        }
        void print2(){
            cout << "Hello" << endl;
        }
};

int main(){
    Student ss1 = Student(12, "Fei11111", 1200287);
    Student ss2(12, "Fei22222", 1200287);
    Student *ss3 = new Student(12, "Fei33333", 1200287);
    ss1.print();
    ss2.print();
    ss3->print();
    delete ss3;
    Student s1 = Student();
    Student s2;
    Student *s3;
    s1.print2();
    s2.print2();
    s3->print2();
    delete s3;
    return 0;
}
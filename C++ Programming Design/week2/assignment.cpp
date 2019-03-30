#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

class Student{
    private: 
    string name;
    int age;
    string id;
    int mark1;
    int mark2;
    int mark3;
    int mark4;

    public:
     void average(){
         int average = (mark1 + mark2 + mark3 + mark4) / 4;
         cout << name << ',' << age << ',' << id << ',' << average << endl;
     }
     void init(string name_, int age_, string id_, int mark1_, int mark2_, int mark3_, int mark4_){
         name = name_;
         age = age_;
         id = id_;
         mark1 = mark1_;
         mark2 = mark2_;
         mark3 = mark3_;
         mark4 = mark4_;
     }
};

int main(){
    char comma;
    string name;
    int age;
    string id;
    int mark1;
    int mark2;
    int mark3;
    int mark4;
    getline(cin, name, ',');
    cin >> age >> comma;
    getline(cin, id, ',');
    cin >> mark1 >> comma >> mark2 >> comma >> mark3 >> comma >> mark4;
    Student s;
    s.init(name, age, id, mark1, mark2, mark3, mark4);
    s.average();
    return 0;
}
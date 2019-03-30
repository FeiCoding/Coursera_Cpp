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
     void init(){
        char comma;
        getline(cin, name, ',');
        cin >> age >> comma;
        getline(cin, id, ',');
        cin >> mark1 >> comma >> mark2 >> comma >> mark3 >> comma >> mark4;
     }
    void average(){
         int average = (mark1 + mark2 + mark3 + mark4) / 4;
         cout << name << ',' << age << ',' << id << ',' << average << endl;
     }
};

int main(){
    
    Student s;
    s.init();
    s.average();
    return 0;
}
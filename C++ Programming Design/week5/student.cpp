#include <iostream>
#include <string>
using namespace std;

class CStudent{
    string name;
    int age;
    int id;
    char gender;

    public:
        void setInfo(const string &name_, int age_, int id_, char gender_);
        void PrintInfo();
        string getName(){
            return name;
        }
};

class CMaster: public CStudent{
    string department;
    public:
        CMaster (const string &name_, int age_, int id_, char gender_,string department_){
            CStudent::setInfo(name_, age_, id_, gender_);
            department = department_;
        }
        void PrintInfo(){
            CStudent::PrintInfo();
            cout << " Department:" << department << endl;
        }
};

void CStudent::setInfo(const string &name_, int age_, int id_, char gender_){
    name = name_;
    age = age_;
    id = id_;
    gender = gender_;
}
void CStudent::PrintInfo(){
    cout << "Name: " << name << " ID: " << id << " Age: " << age;
}

int main(){
    CMaster cm("Fei", 25, 1200287, 'M', "Computer Science");
    cm.PrintInfo();
    return 0;
}
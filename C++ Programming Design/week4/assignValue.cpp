#include <iostream>
#include <string.H>
using namespace std;

class MyString{
    char *str;
    public:
        MyString():str(NULL){}
        MyString(MyString &ss);
        char * operator =(const char* s);
        const char* c_str(){ return str; }
        MyString & operator=(const MyString &ss);
        ~MyString();
        void print();
};

char * MyString::operator =(const char* s){
    if(str){
        delete []str;
    }
    if(s){
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else{
        return NULL;
    }
    return str;
}

MyString & MyString::operator =(const MyString &ss){
    if(str == ss.str){
        return *this;
    }
    if(str){
        delete []str;
    }
    str = new char[strlen(ss.str) + 1];
    strcpy(str, ss.str);
    return *this;
}
MyString::MyString(MyString &ss){
    if(ss.str){
        str = new char[strlen(ss.str) + 1];
        strcpy(str, ss.str);
    }else{
        str = NULL;
    }
}
MyString::~MyString(){
    if(str){
        delete []str;
    }
}

void MyString::print(){
    cout << str << endl;
}
int main(){
    MyString s;
    s = "Hello World!";
    MyString ss;
    ss = s;
    ss.print();
    s.print();
    return 0;
}
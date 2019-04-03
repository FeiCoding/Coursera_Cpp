#include <iostream>
using namespace std;
class MyInt{
    int i;
    public:
    MyInt(int j):i(j){}
    MyInt &operator ++();//前置++ --
    MyInt &operator --();
    MyInt operator ++(int);//后置++ --
    MyInt operator --(int);
    operator int(){ return i; }
};
MyInt & MyInt::operator ++(){
        i++;
        return *this; 
}

MyInt &MyInt::operator --(){
        i--;
        return *this; 
}

MyInt MyInt::operator ++(int){
    MyInt temp = *this;
    i++;
    return temp;
}

MyInt MyInt::operator --(int){
    MyInt temp = *this;
    i--;
    return temp;
}

int main(){
    MyInt a(2);
    cout << a++ << endl;
    cout << ++a << endl;
    cout << --a << endl;
    cout << a-- << endl;
}
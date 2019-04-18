#include <iostream>
using namespace std;

void PrintMax();

int MAX = 10;

int main(){
    PrintMax();
    return 0;
}

void PrintMax(){
    int MAX = 1;
    cout << MAX << endl;//当全局变量与局部变量冲突时，局部变量将屏蔽同名的全局变量
}
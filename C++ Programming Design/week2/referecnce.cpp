#include <iostream>
using namespace std;
void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

int main(){
    int a = 1, b = 2;
    swap(a, b);
    cout << a << ' ' << b << endl;
}

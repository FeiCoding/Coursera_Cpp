#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int a = 34;
    int b = 27;
    int c = a & b;
    int d = -12 >> 2;
    int e = 26 | 14;
    int f = 18 ^ 22;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    return 0;

}
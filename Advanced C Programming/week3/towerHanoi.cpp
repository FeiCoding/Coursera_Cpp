#include <iostream>
using namespace std;

void move(int n, char x, char y, char z){
    if(n == 1){
        cout << "Moving " << 1 << " from " << x << " to " << z << endl;
    }
    else{
        move(n - 1, x, z, y);
        cout << "Moving " << n << " from " << x << " to " << z << endl;
        move(n - 1, y, x, z);
    }
}

int main(){
    int n = 0;
    cin >> n;
    move(n, '1', '2', '3');
    return 0;
}
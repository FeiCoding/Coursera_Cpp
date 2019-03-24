#include <iostream>

using namespace std;
void cacal(int n){
    if(n == 1){
        cout << "End" << endl;
        return;
    }
    if(n % 2 == 1){
        int res = n*3+1;
        printf("%d*3+1=%d\n",n,res);
        cacal(res);
    }
    else{
        int res = n/2;
        printf("%d/2=%d\n", n, res);
        cacal(res);
    }
}

int main(){
    int n = 0;
    cin >> n;
    cacal(n);
    return 0;
}
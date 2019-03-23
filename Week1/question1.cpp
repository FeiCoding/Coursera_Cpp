#include <iostream>
using namespace std;

int main(){
    int len = 0; 
    cin >> len;
    int num[len];
    bool flag = false;
    for( int i = 0; i < len; i++ ){
        cin >> num[i];
        if(num[i] == i)
        {
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag) {cout << 'N' << endl;}
    return 0;
}
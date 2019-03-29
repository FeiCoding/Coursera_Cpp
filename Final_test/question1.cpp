#include <iostream>
using namespace std;

int count_num(int num){
    int a[6] = {0};
    int index = 0;
    while(num != 0){
        a[index++] = num % 10;
        num /= 10;
    }
    int count = 0;
    for(int i = 0; i < 6; i++){
        if(a[i] == 3){
            count ++;
        }
    }
    return count;
}
int main(){
    int m = 0;
    int k = 0;
    cin >> m >> k;
    int count = count_num(m);
    if(m % 19 == 0 && count == k){
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
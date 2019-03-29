#include <iostream>
using namespace std;

char boy;

int find(char str[100], int index){
    if(str[index] != boy){
        return index;
    }
    else{
        int boyIndex = index;
        int girlIndex = find(str, index + 1);
        cout << boyIndex << ' ' << girlIndex << endl;
        find(str, girlIndex + 1);
    }
}

int main(){
    char str[100];
    cin >> str;
    boy = str[0];
    find(str, 0);    
    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;


int main(){
    int num = 0;
    cin >> num;
    char word[40];
    int count = 0;
    for(int i = 0; i < num; i ++){       
        cin >> word;
        if(strlen(word) + count + 1 > 80){
            count = 0;
            cout << endl;
        }
        else if(count > 0){
            cout << ' ';
            count ++;
        }
        cout << word;
        count = strlen(word) + count;
    }
    return 0;
}
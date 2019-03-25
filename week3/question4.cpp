#include <iostream>
#include <cstring>
using namespace std;

int find(char str[100], int index, bool matched[100]){
    if(strlen(str) == index){
        return -1;
    }
    else{
        if(str[index] == '('){
            int co = find(str, index + 1, matched);
            if(str[co] == ')'){
                matched[index] = true;
                matched[co] = true;
                return find(str, co + 1, matched);
            }else{
                return co;
            }
            
        }
        else if(str[index] == ')'){
            return index;
        }
        else{
            return find(str, index + 1, matched);
        }
    }
}

int main(){
    char str[100];
    bool matched[100] = {false};
    while(cin.getline(str, 101)){
        int n = find(str, 0, matched);
        while(n != -1){
            n = find(str, n + 1, matched);
        }

        cout << str << endl;
        
        for(int i = 0; str[i] != '\0'; i++){
            char output = ' ';
            if(!matched[i]){
                if(str[i] == '('){
                    output = '$';
                }
                else if(str[i] == ')'){
                    output = '?';
                }
            }
            cout << output;
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
struct letter{
    char ch;
    int count;
    int position;
    bool show;
};

int main(){
    char a[501];
    letter le[26];
    for(int i = 0; i < 26; i++){
        le[i] = {char(97 + i), 0, 0, false};
    }

    cin.getline(a, 500);
    for(int i = 0; a[i] != '\0'; i++){
        a[i] = tolower(a[i]);
        if(isalpha(a[i])){
            int index = a[i] - 'a';
            le[index].ch = a[i];
            le[index].count++;
            if(!le[index].show){
                le[index].show = true;
                le[index].position = i;
            }
            
        }    
    }

    letter max = {0, 0, 0};
    letter second = {0, 0, 0};
    for(int i = 0; i < 26; i++){
        if(le[i].count > max.count){
            max = le[i];
        }
    }
    for(int i = 0; i < 26; i++){
        if(le[i].show && le[i].count < max.count){
            if(le[i].count > second.count){
                second = le[i];
            }
            
            else if(le[i].count == second.count && le[i].position < second.position){
                second = le[i];
            }
        }
    }
    cout << (char)toupper(second.ch) << '+' << second.ch << ':' << second.count << endl;
    return 0;
}
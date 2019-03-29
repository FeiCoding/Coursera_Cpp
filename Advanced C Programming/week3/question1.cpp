#include <iostream>
using namespace std;

void reverse(char str[500], int startIndex, int endIndex){
    while(startIndex < endIndex){
        char temp = str[startIndex];
        str[startIndex] = str[endIndex];
        str[endIndex] = temp;
        startIndex++;
        endIndex--; 
    }
}

int main(){
    char str[500];
    cin.getline(str, 500);
    int startIndex = 0;
    int endIndex = 0;
    int index = 0;
    while(str[index] != '\0' && index < 500){
        while(str[index] == ' '){
            index++;
        }
        if(str[index] == '\0'){
            break;
        }
        startIndex = index;
        endIndex = index;
        while(str[index] != ' ' && str[index] != '\0'){
            endIndex++;
            index++;
        }
        reverse(str, startIndex, endIndex - 1);
    }
    cout << str << endl;
    return 0;
}
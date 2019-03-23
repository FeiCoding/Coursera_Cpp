#include <iostream>
using namespace std;

int main(){
    char date[11];
    cin >> date;
    char year[4];
    char month[2];
    char day[2];
    for(int i = 0; i < 10; i ++){
        if(i< 4){
            year[i] = date[i];
        }
        if(i > 4 && i < 7){
            month[i] = date[i];
        }
        if(i > 7 && i < 10){
            day[i] = date[i];
        }
    }
    cout << year << ' ' << month << ' ' << day << endl;
    return 0;
}
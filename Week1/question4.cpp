#include <iostream>
using namespace std;

int count_day(int year){
    if(year % 4 == 0 && year % 100 != 0){
        return 29;
    }else if (year % 400 == 0) {
		return true;	
	}else{
        return 28;
    }
}

int main(){
    int year = 0;
    int month = 0;
    int day = 0;
    char slash;
    cin >> year >> slash >> month >> slash >> day;
    cout << year << ' ' << month << ' ' << day << endl;
    int J_day = count_day(year);
    int month_day[12] = {31, J_day, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(day + 1 <= month_day[month - 1]){
        printf("%d-%02d-%02d\n", year, month, day + 1);
    }
    else if(month < 12){
        printf("%d-%02d-%02d\n", year, month + 1, 01);
    }else{
        printf("%d-%02d-%02d\n", year + 1, 01, 01);
    }
    return 0;
}
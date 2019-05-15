#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	
    if(freopen("file2.txt", "w", stdout) == NULL){
        cout << "Error" << endl;
    }
    if(freopen("file2.txt", "r", stdin) == NULL){
        cout << "Error" << endl;
    }
    string ss = "I love cpp";
    int a = 10;
    int b = 12;
    cout << a << endl;
    cout << b << endl;
    cout << ss << endl;
    fclose(stdout);

    int c;
	int d;
	string st;
	
	cin >> c >> d >> st;
    cout << "Hahaha" << endl;
	cout << c << endl;
	cout << d << endl;
	cout << st << endl;
	
    fclose(stdin);
    
	return 0;
}
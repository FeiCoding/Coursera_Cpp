#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double num;
    cin >> num;

    cout << fixed << setprecision(5) << num << endl;
	cout << scientific << setprecision(7) << num << endl;
    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    cout << hex << num << endl;
    cout << dec << setw(10) << setfill('0') << num << endl;
    return 0;
}
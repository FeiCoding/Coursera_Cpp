#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    cin.get();
    for(int i = 0; i < n; i++){
        char str[256];
        cin.getline(str, 256);
        int index = 0;
        while(str[index] != '\0'){
            switch (str[index++])
            {
                case 'A':
                    cout << 'T';
                    break;
                case 'T':
                    cout << 'A';
                    break;
                case 'G':
                    cout << 'C';
                    break;
                case 'C':
                    cout << 'G';
                    break;
            }
        }
        cout << endl;
    }
    return 0;
}
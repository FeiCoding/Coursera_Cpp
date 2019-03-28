#include <iostream>
using namespace std;

void bubble_sort(int a[], int size){
    for(int i = size; i >= 0; i--){
        for(int j = 0; j < i - 1; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                cout << j << " " << i << endl;
            }
        }
    }
    for(int i = 0; i < size; i++){
        cout << a[i];
    }
    cout << endl;
}

int main(){
    int a[5] = {3, 2, 5, 7 ,1};
    bubble_sort(a, 5);
    return 0;
}
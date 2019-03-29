#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// return negtive integer: elem1 is before elem2
// return 0: order not matter
// return positive integer: elem1 is after elem2
int compare(const void *elem1, const void *elem2){
    unsigned int *p1, *p2;
    p1 = (unsigned int *) elem1; // casting to unsigned pointer type
    p2 = (unsigned int *) elem2; // casting to unsigned pointer type
    return *p1 - *p2;
}

int main(){
    int a[7] = {5, 2, 4, 0, 8, 12, 3};
    int (*pfCompare)(const void *, const void *); // pfCompare is a function pointer
    pfCompare = compare;
    qsort(a, 7, 4, pfCompare);
    for(int i = 0; i < 7; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
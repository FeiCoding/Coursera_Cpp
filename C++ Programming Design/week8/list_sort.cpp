#include <iostream>
#include <list>
#include <functional>
using namespace std;

template<class T>
class MyLess{
    public:
    bool operator ()(const T &t1, const T &t2){
        return (t1 % 10) < (t2 % 10);
    }
};


template <class T>
void PrintAll(T b, T e){
    for(; b!=e; b++){
        cout << *b << ' ';
    }
    cout << endl;
}

int main(){
    int SIZE = 5;
    int a[] = {4,1,37,12,83};
    list<int> ll(a, a+SIZE);
    ll.sort();
    PrintAll(ll.begin(), ll.end());
    
    ll.sort(MyLess<int>());
    PrintAll(ll.begin(), ll.end());

    ll.sort(greater<int>());
    PrintAll(ll.begin(), ll.end());
    
    return 0;
}
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

template <class T>
void PrintAll(T begin, T end){
    for(;begin != end; begin++){
        cout << *begin << " ";
    }
    cout << endl;
}

template <class T>
class MyLess{
    public:
    bool operator ()(const T &t1, const T &t2) const{
        return (t1 % 10) < (t2 % 10);
    }
};

template <class T>
bool mycompare(const T &t1, const T &t2){
    if((t1 % 10) < (t2 % 10))
        return false;
    else
        return true;
}
template <class T, class Func>
T MyMax(T begin, T end, Func fun){
    T temp = begin;
    for(;begin != end; begin++){
        if(fun(*temp, *begin)){
            temp = begin;
        }
    }
    return temp;
}

int main(){
    int Size = 5;
    int a[] = {12, 43, 54, 91, 33};
    list<int> ll(a, a+Size);
    PrintAll(ll.begin(), ll.end());

    ll.sort(MyLess<int>());
    PrintAll(ll.begin(), ll.end());

    ll.sort(mycompare<int>);
    PrintAll(ll.begin(), ll.end());

    cout << *MyMax(ll.begin(), ll.end(), MyLess<int>());
    cout << endl;
    cout << *MyMax(ll.begin(), ll.end(), mycompare<int>) << endl;
    return 0;
}
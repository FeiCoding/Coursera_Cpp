#include <iostream>
#include <set>
using namespace std;
class A{
    int num;
    public:
        A(int _num):num(_num){}
        friend bool operator <(const A &a1, const A &a2){
            return a1.num < a2.num;
        }
        friend ostream & operator <<(ostream &o, const A &a){
            o << a.num;
            return o;
        }
        friend class MyLess;
};

struct MyLess{
    bool operator ()(const A &a1, const A &a2){
        return (a1.num % 10) < (a2.num % 10);//按个位数比大小
    }
};

typedef multiset<A> MSET1;
typedef multiset<A, MyLess> MSET2;

void PrintAll(MSET1::iterator b, MSET1::iterator e){
    while(b != e){
        cout << *b << " ";
        b++;
    }
    cout << endl;
}


int main(){
    const int SIZE = 6;
    A a[SIZE] = {4, 22, 19, 8, 33, 40};
    MSET1 ms1(a, a+SIZE);
    
    ms1.insert(22);
    cout << "1)" << ms1.count(22) << endl;    
    cout << "2)"; PrintAll(ms1.begin(), ms1.end());
    MSET1::iterator pp = ms1.find(19);
    if(pp != ms1.end()){
        cout << "found" << endl;
    }
    cout << "3)" << *ms1.lower_bound(22) << "," << *ms1.upper_bound(22) << endl;
    // pp = ms1.erase(ms1.lower_bound(22), ms1.upper_bound(22));
     cout << "4)"; PrintAll(ms1.begin(), ms1.end());
    // cout << "5)" << *pp << endl;

    MSET2 ms2;
    ms2.insert(a, a+SIZE);
    cout << "6)"; PrintAll(ms2.begin(), ms2.end());
    return 0;
}
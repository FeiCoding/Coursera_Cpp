#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
using namespace std;
class A{
    int n;
    public:
    A(int n):n(n){}
    friend bool operator<(const A &a1, const A &a2);
    friend bool operator==(const A &a1, const A &a2);
    friend ostream &operator<<(ostream &o, const A &a);
};
bool operator<(const A &a1, const A &a2){
    return a1.n < a2.n;
}
bool operator==(const A &a1, const A &a2){
    return a1.n == a2.n;
}
ostream &operator<<(ostream &o, const A &a){
    o << a.n;
    return o;
}
template <class T>
void PrintList(const list<T> &lst){
    typename list<T>::const_iterator li;
    li = lst.begin();
    while(li != lst.end()){
        cout << *li << " ";
        li++;
    }
    cout << endl;
}
int main(){
    list<A> lst1, lst2;
    lst1.push_back(1);lst1.push_back(3);
    lst1.push_back(2);lst1.push_back(4);lst1.push_back(2);
    lst2.push_back(10);lst2.push_back(20);
    lst2.push_back(10);lst2.push_back(30);
    lst2.push_back(30);lst2.push_back(20);lst2.push_back(40);
    cout << "1)";PrintList(lst1);cout << endl;
    cout << "2)";PrintList(lst2);cout << endl;
    lst2.sort();
    cout << "3)";PrintList(lst2);cout << endl;
    lst2.pop_front();//delete the first element
    cout << "4)";PrintList(lst2);cout << endl;
    lst1.remove(2);
    cout << "5)";PrintList(lst1);cout << endl;
    lst2.unique();//delete all the duplicated element
    cout << "6)";PrintList(lst2);cout << endl;
    lst1.merge(lst2);//merge lst1 and lst2 then delete lst2
    cout << "7)";PrintList(lst1);cout << endl;
    cout << "8)";PrintList(lst2);cout << endl;
    lst1.reverse();
    cout << "9)";PrintList(lst1);cout << endl;
    lst2.push_back(100);lst2.push_back(200);
    lst2.push_back(300);lst2.push_back(400);
    list<A>::iterator p1, p2, p3;
    p1 = find(lst1.begin(), lst1.end(), 3);
    p2 = find(lst2.begin(), lst2.end(), 200);
    p3 = find(lst2.begin(), lst2.end(), 400);
    lst1.splice(p1, lst2, p2, p3);//将list2的[p2, p3)的元素从p1之前的位置插入list1
    cout << "10)";PrintList(lst1);cout << endl;
    cout << "11)";PrintList(lst2);cout << endl;
    return 0;
}
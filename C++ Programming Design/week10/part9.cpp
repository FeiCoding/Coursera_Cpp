#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
class A{
    public:
    char type;
    int age;
    A(int a):age(a){
        type = 'A';
    }
};

class B: public A{
    public:
    B(int a):A(a){
        type = 'B';
    }
};


struct Comp{
    bool operator ()(A* t1, A* t2){
        return t1->age < t2->age;
    }
};


void Print(A *a){
    cout << a->type << " " << a->age << endl;
}


int main()
{

        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)	{
                        char c; int k;
                        cin >> c >> k;

                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}
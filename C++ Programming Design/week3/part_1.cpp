#include <iostream>
using namespace std;

class A {
public:
    int val;
// 在此处补充你的代码
    A(int i = 0){val = i;}
    A& GetObj(){
        return *this;
    }
};
main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}
#include <iostream>
#include <string>

using namespace std;

class Son{
    public:
        Son(){cout << "Construct Son." << endl;}
        //一般情况下一个类中如果有虚函数，我们都会把其析构函数定义为虚函数
        virtual ~Son(){
            cout << "Destruct Son." << endl;
        }
};

class Grandson: public Son{
    public:
        Grandson(){cout << "Construct Grandson." << endl;}
        ~Grandson(){
            cout << "Destruct Grandson." << endl;
        }
};

int main(){
    Son *pg = new Grandson;
    delete pg;
    return 0;
}
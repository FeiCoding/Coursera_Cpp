#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType{
    int num;
    public:
    void setvalue(int n){
        num = n;
    }
    int operator ++(int){
        return num;
    }
    friend ostream& operator <<(ostream& o, const CType &ct);

};

ostream& operator <<(ostream& o, const CType &ct){
        int nn = ct.num * ct.num;
        o << nn;
        return o;
}

int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<<obj++<<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}
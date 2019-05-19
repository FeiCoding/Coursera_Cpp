// 在此处补充你的代码
class A{
    public:
        static int count;
        int num;
        A(int n):num(n){
            count ++;
        }
        A(){
            count ++;
        }
        A(A &a){
            count ++;
        }
        virtual ~A(){
            count--;
            cout << "A::destructor" << endl;
        }
};

class B: public A{
    public:
        B(int n):A(n){}
        B():A(){}
        ~B(){
            cout << "B::destructor" << endl;
        }
};

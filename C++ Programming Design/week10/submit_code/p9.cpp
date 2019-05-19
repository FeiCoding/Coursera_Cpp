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

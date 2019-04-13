#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class CShape{
    public:
    virtual double Area() = 0;
    virtual void Print() = 0;
};

class CCircle: public CShape{
    int radius;
    public:
    CCircle(int radius):radius(radius){}
    virtual double Area();
    virtual void Print();
};

class CTriangle:public CShape{
    int l, m, n;
    public:
    CTriangle(int l, int m, int n):l(l),m(m),n(n){}
    virtual double Area();
    virtual void Print();
};

class CRectangle:public CShape{
    int l, m;
    public:
    CRectangle(int l, int m):l(l),m(m){}
    virtual double Area();
    virtual void Print();
};

double CCircle::Area(){
    return 2 * radius * atan(1)*4;
}

void CCircle::Print(){
    cout << Area() << endl;
}

double CTriangle::Area(){
    return l + m + n;
}

void CTriangle::Print(){
    cout << Area() << endl;
}

double CRectangle::Area(){
    return 2 * (l + m);
}

void CRectangle::Print(){
    cout << Area() << endl;
}

int MyCompare(const void *s1, const void *s2){
    CShape ** p1 = (CShape **) s1;//强制转换原因是s1和s2是void型的，不可直接取得所指内容
    CShape ** p2 = (CShape **) s2;
    if((*p1)->Area() < (*p2)->Area()){
        return 1;
    }
    else if((*p1)->Area() > (*p2)->Area()){
        return -1;
    }
    else{
        return 0;
    }
}

int main(){
    cout << "Please input how many shape you want to create:" << endl;
    int n = 0;
    cin >> n;
    CShape *shapes[100];
    for(int i = 0; i < n; i++){
        cout << "Please Input the " << i+1 <<"th shape you want:" << endl;
        CTriangle *pt = NULL;
        CRectangle *pr = NULL;
        CCircle *pc = NULL;
        int r, l, m;
        char c;
        cin >> c;
        switch (c)
        {
        case 'C':
            cin >> r;
            pc = new CCircle(r);
            pc->Print();
            shapes[i] = pc;
            break;

        case 'R':
            cin >> l >> m;
            pr = new CRectangle(l, m);
            pr->Print();
            shapes[i] = pr;
            break;

        case 'T':
            cin >> l >> m >> r;
            pt = new CTriangle(l, m, r);
            pt->Print();
            shapes[i] = pt;
            break;
        }
    }
    qsort(shapes, n, sizeof(CShape*), MyCompare);
    for(int i = 0; i < n; i++){
        shapes[i] -> Print();
    }
    return 0;
}
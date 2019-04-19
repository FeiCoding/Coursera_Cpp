// 实现一个三维数组模版CArray3D，可以用来生成元素为任意类型变量的三维数组，使得下面程序输出结果是：

// 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,

#include <iostream>
using namespace std;

template <class T>
class CArray3D{
    T ***p;
    T x;
    T y;
    T z;
    public:
    CArray3D(int x, int y, int z):x(x),y(y),z(z){
        if(x == 0 || y == 0 || z == 0){
            p = NULL;
        }
        p = new T**[x];
        for(int i = 0; i < x; i++){
            p[i] = new T*[y];      
            for(int j = 0; j < y; j++){
                p[i][j] = new T[z];
            }
        }
    }
    ~CArray3D(){
        if(p){
            for(int i = 0; i < x; i++){
                for(int j = 0; j < y; j++){
                    delete []p[i][j];
                }
                delete [] p[i];
            }
        }
    }
    
    T** operator [](int i){
        return p[i];
    }

};
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
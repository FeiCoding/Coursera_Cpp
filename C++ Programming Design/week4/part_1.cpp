#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex():r(0),i(0){}
    Complex & operator =(const char *s){
        char *real = new char[strlen(s) + 1];
        char *imag = new char[strlen(s) + 1];
        int index = 0;
        while(s[index] != '+'){
            real[index] = s[index];
            index++;
        }
        index++;
        int imag_index = 0;
        while(s[index] != 'i'){
            imag[imag_index++] = s[index++];
        }
        r = atoi(real);
        i = atoi(imag);
        delete []real;
        delete []imag;
        return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
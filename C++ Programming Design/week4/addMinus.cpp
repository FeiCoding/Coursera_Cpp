#include <iostream>
using namespace std;

class ComplexValue{
    double real, imag;
    public:
        ComplexValue(double real, double imag):real(real),imag(imag){} 
        ComplexValue operator+(const ComplexValue & obj);
        ComplexValue operator-(const ComplexValue & obj);
        friend void print(const ComplexValue&);
};

ComplexValue  ComplexValue::operator+(const ComplexValue & obj){
    return ComplexValue(real + obj.real, imag + obj.imag);
}


ComplexValue ComplexValue::operator-(const ComplexValue & obj){
    return ComplexValue(real - obj.real, imag - obj.imag);
}

void print(const ComplexValue & obj){
    cout << obj.real << "+" << obj.imag << "i" << endl;
}

int main(){
    ComplexValue a(11, 12);
    ComplexValue b(13, 14);
    print(a + b);    
    return 0;
}
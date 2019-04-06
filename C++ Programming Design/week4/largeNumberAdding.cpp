#include <iostream>
using namespace std;

class BigNumber{
    string num;
    char sign;
    public:
    BigNumber(string n_str){
        if(bn[0] == '-'){
            num = n_str.substr(1, n_str.length() - 1);
            sign = '-';
        }
        else{
            sign = '+';
            num = n_str;
        }
    }
    BigNumber &operator +(BigNumber &bn);
    BigNumber &operator -(BigNumber &bn);
    BigNumber &operator *(BigNumber &bn);
    BigNumber &operator /(BigNumber &bn);
    void print(){
        if(sign == '-'){
            num.insert(0, '-');
        }
        cout << num << endl;
    }
};
void swap(string &s1, string &s2){
    string temp = s1;
    s1 = s2;
    s2 = temp;
}
BigNumber & BigNumber::operator +(BigNumber &bn){
    if(sign == '-' && bn.sign == '+'){
        return bn - *this;
    }
    else if(sign == '+' && bn.sign == '-'){
        return *this - bn;
    }
    else{
        string t_num = bn.num;
        int maxLen = num.length() > t_num.length() ? num.length() : t_num.length();
        while(num.length() < maxLen){
            num.insert(0, "0");
        }
        while(t_num.length() < maxLen){
            t_num.insert(0, "0");
        }
        int cur = 0;
        string result = "";
        for(int i = maxLen - 1; i >= 0; i--){
            int add1 = num[i] - '0';
            int add2 = t_num[i] - '0';
            int res = (add1 + add2 + cur) % 10;
            cur = (add1 + add2 + cur) / 10;
            result.insert(0, res + '0');
        }
        if(cur){
            result.insert(0, '1');
        }
        BigNumber temp(result);
        temp.sign = sign;
        return temp;
    }
}
BigNumber & BigNumber::operator -(BigNumber &bn){
    if(sign == '-' && bn.sign == '+'){
        bn.sign = '-';
        return bn + *this;
    }
    else if(sign == '+' && bn.sign == '-'){
        bn.sign = '+';
        return bn + *this;
    }
    else{
        string t_num = bn.num;
        char new_sign = '+';
        if(num.length() < t_num.length() || num < t_num){
            new_sign = '-';
            swap(num, t_num);
        }
        int maxLen = num.length();
        while(t_num.length() < maxLen){
            t_num.insert(0, "0");
        }
        int cur = 0;
        string result = "";
        for(int i = maxLen - 1; i >= 0; i--){
            int min1 = num[i] - '0';
            int min2 = t_num[i] - '0';
            int res = 0;
            if(min1 - cur >= min2){
                res = min1 - min2 - cur;
                cur = 0;        
            }
            else{
                res = min1 + 10 - min2 - cur;
                cur = 1;
            }
            result.insert(0, res + '0');
        }
        if(new_sign == '-'){
            result.insert(0, new_sign);
        }
        BigNumber temp(result);
        return temp;
    }

}
BigNumber & BigNumber::operator *(BigNumber &bn){

}
BigNumber & BigNumber::operator /(BigNumber &bn){

}

int main(){
    BigNumber n1("20000");
    BigNumber n2("-2000");
    BigNumber n3 = n1 - n2;
    n3.print();
}

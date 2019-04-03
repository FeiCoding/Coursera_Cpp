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
};

BigNumber & BigNumber::operator +(BigNumber &bn){
    string t_num = bn.num;
    if(t_num[0] = '-'){    
        return *this - BigNumber(t_num.substr(1, bn.length() - 1))
    }
    else{
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

}
BigNumber & BigNumber::operator *(BigNumber &bn){

}
BigNumber & BigNumber::operator /(BigNumber &bn){

}

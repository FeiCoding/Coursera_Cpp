#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <class T>
class CMyistream_iterator{
    istream &in;
    T content;

    public:
        CMyistream_iterator(istream &i):in(i){
            in >> content;
        }
        T operator *(){
            return content;
        }
        void operator ++(int){ // ++(int)重载后缀的++
            in >> content;
        }
};

int main()
{
    CMyistream_iterator<int> inputInt(cin);
    int n1,n2,n3;
    n1 = * inputInt; //读入 n1
    int tmp = * inputInt;
    cout << tmp << endl;
    inputInt ++;
    n2 = * inputInt; //读入 n2
    inputInt ++;
    n3 = * inputInt; //读入 n3
    cout << n1 << "," << n2<< "," << n3 << endl;
    CMyistream_iterator<string> inputStr(cin);
    string s1,s2;
    s1 = * inputStr;
    inputStr ++;
    s2 = * inputStr;
    cout << s1 << "," << s2 << endl;
    return 0;
}
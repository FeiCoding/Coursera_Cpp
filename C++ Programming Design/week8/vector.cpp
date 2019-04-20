#include <iostream>
#include <vector>
using namespace std;
// vector在中间插入会导致速度很慢，所有的STL算法都可以用于vector
void print(const vector<int> &v){
    vector<int>::const_iterator vi;
    vi = v.begin();
    while(vi < v.end()) {
        cout << *vi << " ";
        vi++;
    }
    cout << endl;
}
int main(){
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v1();
    vector<int> v2(5);
    cout << v2.end() - v2.begin() << endl;
    for(int i = 0; i < 5; i ++) v2[i] = i;
    print(v2);
    v2.at(3) = 150;
    print(v2);
    vector<int> v3(3, 2);//初始化3个元素都是2
    vector<int> v4(a, a + 5);
    print(v4);
    v4.insert(v4.begin()+ 3, 150);
    print(v4);
    return 0;
}
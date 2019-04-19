#include <iostream>
#include <vector>
#include <list>
using namespace std;
//支持迭代器种类：
// vector          随机访问
// deque           随机访问
// list            双向
// set/multiset    双向
// map/multimap    双向
// stack           不支持迭代器
// queue           不支持迭代器
// priority_queue  不支持迭代器

int main(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i*i);
    }
    vector<int>::const_iterator ii;
    ii = v.begin();
    while(ii < v.end()){ //随机迭代器支持小于号
        cout << *ii << " ";
        ii = ii + 2;
    }
    cout << "\nstart list" << endl;
    list<int> l;
    list<int>::const_iterator li;
    for(int i = 0; i < 10; i++){
        l.push_back(i * i);
    }
    li = l.begin();
    while(li != l.end()){//此处用小于号则会报错
        cout << *li << " ";
        li++;
    }
    return 0;
}
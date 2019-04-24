#include <iostream>
#include <map>
using namespace std;
typedef map<int, double, less<int> > MAP;
void Print(const MAP & pair, int num){
    MAP::const_iterator mi;
    mi = pair.begin();
    cout << num << ")";
    while(mi != pair.end()){
        cout <<  "Key: "<< mi->first << " Value: " << mi->second << "\t";
        mi++;
    }
}
int main(){
    MAP pairs;
    pairs.insert(MAP::value_type(10, 12.5));
    int count = 1;
    Print(pairs, count++);
    pair<MAP::iterator, bool>result;
    result = pairs.insert(make_pair(10, 12));
    if(result.second)
        cout << count++ << ") Insert Successfully" << endl;
    else
        cout << count++ << ") Insert Failed" << endl;
    Print(pairs, count++);
    cout << count++ << ") " << pairs.count(10) << endl;
    pairs.insert(make_pair(12, 30.5));
    Print(pairs, count++);
    int n = pairs[40];
    Print(pairs, count++);
    pairs[40] = 55.22;
    Print(pairs, count++);
    return 0;
}
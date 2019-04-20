#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i*i);
    }
    vector<int>::const_iterator vi;
    vi = find(v.begin(), v.end(), 9);
    if(vi == v.end()){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found 1" << endl;
    }
    vector<int>::const_iterator vi2;
    vi2 = find(v.begin() + 2, v.end() - 3, 16);
    
    if(vi == v.end()){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found 2" << endl;
    }
    return 0;
}
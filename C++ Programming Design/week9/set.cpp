#include <iostream>
#include <set>
using namespace std;

int main(){
    typedef set<int>::iterator IT;
    int a[5] = {3, 4, 6, 1, 2};
    set<int> st(a, a+5);
    pair<IT, bool> result;
    result = st.insert(5);
    if(result.second)
        cout << "Insert Successfully. " << *result.first << " inserted." << endl;

    result = st.insert(5);
    if(result.second) cout << *result.first << endl;
    else cout << *result.first << "Already Existed." << endl;
    pair<IT, IT> bound = st.equal_range(4);
    cout << *bound.first << " " << *bound.second << endl;
    return 0;
}
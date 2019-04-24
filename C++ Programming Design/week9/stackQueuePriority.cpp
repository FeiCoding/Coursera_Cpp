#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

template<class T>
void Print(T &structure, string name){
    cout << name << ": " << endl;
    while(!structure.empty()){
        cout << structure.top() << endl;
        structure.pop();
    }
}
int main(){
    priority_queue<double> pq;
    stack<double> st;
    queue<double> qu;
    st.push(11.2);
    st.push(4.2);
    st.push(11.3);
    st.push(12.6);
    st.push(1.9);
    pq.push(11.2);
    pq.push(4.2);
    pq.push(11.3);
    pq.push(12.6);
    pq.push(1.9);
    qu.push(11.2);
    qu.push(4.2);
    qu.push(11.3);
    qu.push(12.6);
    qu.push(1.9);
    Print(pq,"priority queue");
    Print(st, "stack");
    cout << "queue: " << endl;
    while(!qu.empty()){        
        cout << qu.front() << endl;
        qu.pop();
    }
    return 0;
}
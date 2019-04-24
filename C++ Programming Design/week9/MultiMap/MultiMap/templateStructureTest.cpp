#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
void Print(T structure) {
	while (structure.empty()) {
		cout << structure.top() << endl;
		structure.pop();
	}
}
int main() {
	priority_queue<double> pq;
	stack<double> st;
	pq.push(11.2);
	pq.push(4.2);
	pq.push(11.3);
	pq.push(12.6);
	pq.push(1.9);
	pq.push(11.2);
	pq.push(4.2);
	pq.push(11.3);
	pq.push(12.6);
	pq.push(1.9);
	Print(pq);
	return 0;
}
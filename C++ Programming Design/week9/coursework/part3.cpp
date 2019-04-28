#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	typedef multiset<int> MST;
	typedef set<int> MS;
	int n;
	cin >> n;
	MST ms;
	MS s;
	for (int i = 0; i < n; i++) {
		string operation;
		cin >> operation;
		if (operation == "add") {
			int num;
			cin >> num;
			ms.insert(num);
			s.insert(num);
			cout << ms.size() << endl;
		}
		else if (operation == "ask") {
			int num;
			cin >> num;
			MST::iterator p = s.find(num);
			if (p != s.end()) {
				cout << 1 << " " << ms.count(num) << endl;
			}
			else {
				cout << 0 << " " << ms.count(num) << endl;
			}
		}
		else if (operation == "del") {
			int num;
			cin >> num;
			cout << ms.count(num) << endl;
			ms.erase(num);	
		}
	}
	return 0;
}
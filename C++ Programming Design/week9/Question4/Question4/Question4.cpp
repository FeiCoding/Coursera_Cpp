#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> ve;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		ve.push_back(str);
	}
	string operation;
	while (cin >> operation) {
		if (operation == "find") {
			string S;
			int N;
			cin >> S >> N;
			ve[N].find(S);
		}
		else if (operation == "copy") {
			int N, X, L;
			cin >> N >> X >> L;
			cout << ve[N].substr(X, L) << endl;
		}
		else if (operation == "add") {
			
		}
		else if (operation == "rfind") {

		}
		else if (operation == "insert") {
			string S;
			int N, X;
			ve[N].insert(X, S);
		}
		else if (operation == "reset") {
			string S;
			int N;
			cin >> S >> N;
			ve[N] = S;
		}
		else if (operation == "print") {

		}
		else if (operation == "printall") {

		}
		else if (operation == "over") {
			return 0;
		}
	}	
}
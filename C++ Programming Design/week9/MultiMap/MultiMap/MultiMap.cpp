#include <iostream>
#include <map>
#include <string>
using namespace std;

class Student {
public:
	struct Info {
		int id;
		string name;
	};
	int score;
	Info info;
};

typedef multimap<int, Student::Info> MAP_STD;

int main() {
	int n = 0;
	cin >> n;
	MAP_STD mp;
	Student st;
	for (int i = 0; i < n; i++) {
		string operation;
		cin >> operation;
		if (operation == "Add") {
			string name;
			int id;
			int score;
			cin >> st.info.name >> st.info.id >> st.score;
			mp.insert(MAP_STD::value_type(st.score, st.info));
		}
		else if (operation == "Query") {
			int score;
			cin >> score;
			MAP_STD::iterator mi = mp.lower_bound(score);
			if (mi != mp.begin()) {
				--mi;
				MAP_STD::iterator max_p = mi;
				int max_score = mi->first;
				int max_id = mi->second.id;
				for (; mi != mp.begin() && mi->first == max_score; --mi) {
					if (mi->second.id > max_id) {
						max_p = mi;
						max_id = mi->second.id;
					}
				}
				if (mi->first == score) {
					if (mi->second.id > max_id) {
						max_p = mi;
						max_id = mi->second.id;
					}
				}
				cout << max_p->second.name << " " << max_p->second.id << " " << max_p->first << endl;
			}
			else {
				cout << "Nobody" << endl;
			}
		}

	}
	return 0;
}
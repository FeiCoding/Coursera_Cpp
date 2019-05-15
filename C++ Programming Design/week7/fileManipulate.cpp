#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class Student {
public:
	string name;
	int age;
	Student() {}
	Student(string name_, int age_) :name(name_), age(age_) {}
};


int main() {
	Student s;
	fstream file("file.txt", ios::in | ios::out | ios::binary);
	if (!file) {
		cout << "Cannot open file." << endl;
		return 0;
	}
	 file.seekp(0, ios::beg);
	 int count = 0;
	 while(count < 2){
	     cin >> s.name >> s.age;
	     file.write((char *) &s, sizeof(s));
	     count ++;
	 }
	file.seekg(0, ios::beg);
	while (file.read((char *)&s, sizeof(s))) {
		cout << s.name << " " << s.age << endl;
	}
	file.close();

	fstream file2("file2.txt", ios::in | ios::out);
	file2 << "fei" << endl;
	string ans;
	file2 >> ans;
	cout << ans << endl;
	file2.close();

	return 0;
}
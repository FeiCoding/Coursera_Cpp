#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;
//֧�ֵ��������ࣺ
// vector          �������
// deque           �������
// list            ˫��
// set/multiset    ˫��
// map/multimap    ˫��
// stack           ��֧�ֵ�����
// queue           ��֧�ֵ�����
// priority_queue  ��֧�ֵ�����

int main() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i*i);
	}
	vector<int>::const_iterator ii;
	ii = v.begin();
	while (ii < v.end()) { //���������֧��С�ں�
		cout << *ii << " ";
		ii = ii + 2;
	}
	cout << "\nstart list" << endl;
	list<int> l;
	list<int>::const_iterator li;
	for (int i = 0; i < 10; i++) {
		l.push_back(i * i);
	}
	li = l.begin();
	while (li != l.end()) {//�˴���С�ں���ᱨ��,˫�������
		cout << *li << " ";
		li++;
	}

	set<int> s;
	set<int>::const_iterator si;
	for (int i = 0; i < 10; i++) {
		s.insert(i * i);
	}
	si = s.begin();
	while (si != s.end()) {
		cout << *si << " ";
		si++;
	}


	return 0;
}
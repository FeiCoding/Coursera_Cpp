#include <iostream>
#include <vector>
#include <list>
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
	while (li != l.end()) {//�˴���С�ں���ᱨ��
		cout << *li << " ";
		li++;
	}
	return 0;
}
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

const string redProduceQueue[5] = { "iceman","lion","wolf","ninja","dragon" };
const string blueProduceQueue[5] = { "lion","dragon","ninja","iceman","wolf" };
const string monsterLife[5] = { "dragon","ninja","iceman","lion","wolf" };
static int countQueue[5] = { 0 };
class Monster {
public:
	string type;
	int id;
	int life;
	int strength;
	string side;

public:
	Monster(string type, int id, int life, int strength, string side) : type(type), id(id), life(life), strength(strength), side(side) {}
};

class Commander {
public:
	string name;
	int totalLife;
	int queue[5];
public:
	Commander(string name, int totalLife) :name(name), totalLife(totalLife) { queue[5] = { 0 }; }
	void addQueue(int i);
	int produce(string name, int num, int life, int strength, string side);
};

void Commander::addQueue(int i) {
	queue[i]++;
}
int Commander::produce(string name, int num, int life, int strength, string side) {
	Monster m(name, num, life, strength, side);
	int index = 0;
	for (; index < 5; index++) {
		if (name == monsterLife[index]) {
			countQueue[index]++;
			break;
		}
	}
	return index;
}

void assignValue(int lifeCost[5], int life[5], const string side, const string nameProduceQueue[5] = NULL) {
	if (side == "red") {
		nameProduceQueue = redProduceQueue;
	}
	else {
		nameProduceQueue = blueProduceQueue;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (nameProduceQueue[i] == monsterLife[j]) {
				lifeCost[i] = life[j];
				break;
			}
		}
	}
}

int main() {
	int group = 0;
	cin >> group;

	int M = 0;
	cin >> M;
	int life[5] = { 0 };
	Commander red("Red", M);
	Commander blue("Blue", M);
	for (int i = 0; i < 5; i++) {
		cin >> life[i];
	}
	int redLifeCost[5] = { 0 };
	int blueLifeCost[5] = { 0 };
	int redCount[5] = { 0 };
	int blueCount[5] = { 0 };
	assignValue(redLifeCost, life, "red");
	assignValue(blueLifeCost, life, "blue");
	int time = 0;
	while (red.totalLife >= 0 || blue.totalLife >= 0) {
		int index_red = time % 5;
		while (index_red < 5) {
			if (red.totalLife >= redLifeCost[index_red]) {
				int index_count = red.produce(redProduceQueue[index_red], redLifeCost[index_red], redLifeCost[index_red], 0, "red");
				cout << setw(3) << setfill('0') << time << " red " << redProduceQueue[index_red] << countQueue[index_count] << " born with strength " << redLifeCost[index_red] << "," << redCount[index_red] << " " << redProduceQueue[index_red] << " in red headquarter" << endl;
				red.totalLife -= redLifeCost[index_red];
				break;
			}
			index_red++;
		}
		if (index_red == 5) {
			cout << setw(3) << setfill('0') << time << " red headquarter stops making warriors" << endl;
		}
		int blue_index = time % 5;
		while (blue_index < 5) {
			if (blue.totalLife >= blueLifeCost[blue_index]) {
				int index_count = blue.produce(blueProduceQueue[blue_index], blueLifeCost[blue_index], blueLifeCost[blue_index], 0, "blue");
				cout << setw(3) << setfill('0') << time << " blue " << blueProduceQueue[blue_index] << countQueue[index_count] << " born with strength " << blueLifeCost[blue_index] << "," << blueCount[blue_index] << " " << blueProduceQueue[blue_index] << " in blue headquarter" << endl;
				blue.totalLife -= blueLifeCost[blue_index];
				break;
			}
			blue_index++;
		}
		if (blue_index == 5) {
			cout << setw(3) << setfill('0') << time << " red headquarter stops making warriors" << endl;
		}
		time++;
	}
	system("Pause");
	return 0;
}
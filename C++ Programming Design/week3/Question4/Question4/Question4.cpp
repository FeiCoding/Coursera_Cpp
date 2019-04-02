#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

const string redProduceQueue[5] = { "iceman","lion","wolf","ninja","dragon" };
const string blueProduceQueue[5] = { "lion","dragon","ninja","iceman","wolf" };
const string monsterNameOrder[5] = { "dragon","ninja","iceman","lion","wolf" };

class Warrior {

};


class Commander {
private:
	string name;
	int totalLife;
	int count = 0;
	static int minProduceCost;
	static int produceIndex[5];
	int produceCost[5] = { 0 };
	int produceCount[5] = { 0 };
	bool finish = false;
public:
	Commander(string name, int totalLife) :name(name),totalLife(totalLife){}
	void costValue(const int life[5], const string produceQueue[5] = NULL);
	void formProduceIndex(const int start_index);
	static void setMinCost(int cost) {
		minProduceCost = cost;
	}
	static int getMinCost() {
		return minProduceCost;
	}
	void setFinish() {
		finish = !finish;
	}
	bool getFinish() {
		return finish;
	}
	int* getProduceIndex() {
		return produceIndex;
	}
	void produce(const int time, const string produceQueue[5] = NULL);
};


void Commander::costValue(const int life[5], const string produceQueue[5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (produceQueue[i] == monsterNameOrder[j]) {
				produceCost[i] = life[j];
				break;
			}
		}
	}
}

void Commander::formProduceIndex(const int start_index) {
	int index = start_index;
	for (int i = 0; i < start_index; i++) {
		produceIndex[i] = index++;
	}
	index = 0;
	for (int i = start_index; i < 5; i++) {
		produceIndex[i] = index++;
	}
}

void Commander::produce(const int time, const string produceQueue[5]) {
	if (finish) {
		return;
	}
	int start_index = time % 5;
	formProduceIndex(start_index);
	if (totalLife < minProduceCost && !finish) {
		cout << setw(3) << setfill('0') << time << " " << name << " headquarter stops making warriors" << endl;
		setFinish();
	}
	int rolling_index = 0;
	while (rolling_index < 5) {
		cout << setw(3) << setfill('0') << time;
		int index = produceIndex[rolling_index];
		if (totalLife >= produceCost[index]) {
			cout << " " << name << " " << produceQueue[index] << " " << ++count << " born with strength " << produceCost[index] << ",";
			cout << ++produceCount[index] << " " << produceQueue[index] << " in " << name << " headquarter" << endl;
			totalLife -= produceCost[index];
			break;
		}
		rolling_index++;
	}
}

int Commander::minProduceCost = 100000;
int Commander::produceIndex[5] = { 0 };

int main() {
	int group = 0;
	cin >> group;
	for (int lt = 0; lt < group; lt++) {
		int M = 0;
		cin >> M;
		int life[5] = { 0 };
		Commander red("red", M);
		Commander blue("blue", M);
		for (int i = 0; i < 5; i++) {
			cin >> life[i];
			if (life[i] < Commander::getMinCost())
				Commander::setMinCost(life[i]);
		}
		red.costValue(life, redProduceQueue);
		blue.costValue(life, blueProduceQueue);
		int time = 0;
		while (!red.getFinish() || !blue.getFinish()) {
			red.produce(time, redProduceQueue);
			blue.produce(time, blueProduceQueue);
			time++;
		}
	}
	return 0;
}
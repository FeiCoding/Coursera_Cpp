#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

const string redProduceQueue[5] = { "iceman","lion","wolf","ninja","dragon" };
const string blueProduceQueue[5] = { "lion","dragon","ninja","iceman","wolf" };
const string monsterNameOrder[5] = { "dragon","ninja","iceman","lion","wolf" };
static int red_id = 1;
static int blue_id = 1;

class Commander {
public:
	string name;
	int totalLife;
public:
	Commander(string name, int totalLife) :name(name), totalLife(totalLife) { }
};


void costValue(int lifeCost[5], int life[5], const string side, const string produceQueue[5] = NULL) {
	if (side == "red") {
		produceQueue = redProduceQueue;
	}
	else {
		produceQueue = blueProduceQueue;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (produceQueue[i] == monsterNameOrder[j]) {
				lifeCost[i] = life[j];
				break;
			}
		}
	}
}

void getIndex(int arr[5], int start_index) {
	int index = start_index;
	for (int i = 0; i < start_index; i++) {
		arr[i] = index++;
	}
	index = 0;
	for (int i = start_index; i < 5; i++) {
		arr[i] = index++;
	}
}

int main() {
	int group = 0;
	cin >> group;
	for (int lt = 0; lt < group; lt++) {
		int M = 0;
		cin >> M;
		int life[5] = { 0 };
		Commander red("Red", M);
		Commander blue("Blue", M);
		int minCost = 100000;
		for (int i = 0; i < 5; i++) {
			cin >> life[i];
			if (life[i] < minCost)
				minCost = life[i];
		}
		int redLifeCost[5] = { 0 };
		int blueLifeCost[5] = { 0 };
		int redCount[5] = { 0 };
		int blueCount[5] = { 0 };
		costValue(redLifeCost, life, "red");
		costValue(blueLifeCost, life, "blue");
		int time = 0;
		bool red_finish = false;
		bool blue_finish = false;
		while (!red_finish || !blue_finish) {
			int start_index = time % 5;
			int rolling_arr[5] = { 0 };
			getIndex(rolling_arr, start_index);
			int rolling_index_red = 0;
			if (red.totalLife < minCost && !red_finish) {
				cout << setw(3) << setfill('0') << time << " red headquarter stops making warriors" << endl;
				red_finish = true;
			}
			while (red.totalLife >= minCost && rolling_index_red < 5) {
				int index_red = rolling_arr[rolling_index_red];
				if (red.totalLife >= redLifeCost[index_red]) {
					cout << setw(3) << setfill('0') << time << " red " << redProduceQueue[index_red] << " " << red_id++ << " born with strength " << redLifeCost[index_red] << "," << ++redCount[index_red] << " " << redProduceQueue[index_red] << " in red headquarter" << endl;
					red.totalLife = red.totalLife - redLifeCost[index_red];
					break;
				}
				rolling_index_red++;
				
			}

			int rolling_index_blue = 0;
			if (blue.totalLife < minCost && !blue_finish) {
				cout << setw(3) << setfill('0') << time << " blue headquarter stops making warriors" << endl;
				blue_finish = true;
			}
			while (blue.totalLife >= minCost && rolling_index_blue < 5) {
				int index_blue = rolling_arr[rolling_index_blue];
				if (blue.totalLife >= blueLifeCost[index_blue]) {
					cout << setw(3) << setfill('0') << time << " blue " << blueProduceQueue[index_blue] << " " << blue_id++ << " born with strength " << blueLifeCost[index_blue] << "," << ++blueCount[index_blue] << " " << blueProduceQueue[index_blue] << " in blue headquarter" << endl;
					blue.totalLife = blue.totalLife - blueLifeCost[index_blue];
					break;
				}
				rolling_index_blue++;
			}
			time++;
		}
	}
	return 0;
}
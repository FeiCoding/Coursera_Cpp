#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    double *rate = new double[n];
    int *id = new int[n];
    for(int i = 0; i < n; i++){
        int before_num = 0;
        int after_num = 0;
        cin >> before_num >> after_num;
        rate[i] = (double)after_num / before_num;
    }
    
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (rate[j + 1] > rate[j]) {
                    int tmpId = id[j];
                    id[j] = id[j + 1];
                    id[j + 1] = tmpId;
                    double tmpRate = rate[j];
                    rate[j] = rate[j + 1];
                    rate[j + 1] = tmpRate;
                }
            }
    }
    // 记录最大的差  
	double maxDiff = 0;
	// 和最大差的下标  
	int maxDiffIndex = 0;
	for (int i = 0; i < n - 1; i++) {
		double diff = rate[i] - rate[i + 1];
		if (maxDiff < diff) {
			maxDiff = diff;
			maxDiffIndex = i;
		}
	}
 
	//输出繁殖率较大的那组细菌  
	cout << maxDiffIndex + 1 << endl;
	for (int i = maxDiffIndex; i >= 0; i--) {
		cout << id[i] << endl;
	}
 
	//输出繁殖率较小的那组细菌  
	cout << n - maxDiffIndex - 1 << endl;
	for (int i = n - 1; i >= maxDiffIndex + 1; i--) {
		cout << id[i] << endl;
	}
    cin >> n;
    return 0;
}
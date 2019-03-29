#include <iostream>
using namespace std;

int main(){
    int k = 0;
    cin >> k;
    int res[100] = {0};
    int index = 0;
    for(int i = 0; i < k; i++){
        int m, n;
        cin >> m >> n;
        int a[100][100] = {0};
        int count = 0;
        for(int j = 0; j < m; j++){
            for(int l = 0; l < n; l++){
                cin >> a[j][l];
                if(j == 0 || j == m - 1 || l == 0 || l == n-1){
                    count += a[j][l];
                }
            }
        }
        res[index++] = count;
    }
    for(int i = 0; i < k; i++){
        cout << res[i] << endl;
    }
    return 0;
}
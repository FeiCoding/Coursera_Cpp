#include <iostream>
using namespace std;

void print(int a[100][100], int row, int col){
    
	for (int i = 0; i < col; i++)
	{
		for (int j = 0, k = i; j < row && k >= 0; j++, k--)
		{
			cout << a[j][k] << endl;
		}
	}
	for (int i = 1; i < row; i++)
	{
		for (int j = i, k = col - 1; j < row && k >= 0; j++, k--)
		{
			cout << a[j][k] << endl;
		}
	}
}

int main(){
    int m, n;
    cin >> m >> n;
    int a[100][100] = {0};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    print(a, m, n);
    return 0;
}
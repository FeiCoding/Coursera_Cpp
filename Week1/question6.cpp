// 输入
// 第一行一个数字n，n不超过100，表示有n*n的宿舍房间。

// 接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。

// 接下来的一行是一个整数m，m不超过100.

// 输出
// 输出第m天，得流感的人数
#include <iostream>
using namespace std;

void infection(char a[100][100], int n){
    char newA[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newA[i][j] = a[i][j];
			if (a[i][j] == '.')
			{
				if ((a[i][j - 1] == '@' && j - 1 >= 0) ||
					(a[i][j + 1] == '@' && j + 1 < n) ||
					(a[i - 1][j] == '@' && i - 1 >= 0) ||
					(a[i + 1][j] == '@' && i + 1 < n))
				{
					newA[i][j] = '@';
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = newA[i][j];
		}
	}
}

int main(){
    int size = 0;
    cin >> size;
    char room[100][100];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin >> room[i][j] ;
        }
    }
    
    int times = 0;
    cin >> times;
    for(int i = 0; i < times - 1; i++){
        infection(room, size);  
    }

    int count = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j ++){
            if(room[i][j] == '@'){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
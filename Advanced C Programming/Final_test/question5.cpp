#include <iostream>
using namespace std;

int n, m; // 行数，列数
int Step[100][100] = { 0 }; // 步数矩阵

/*
 *	遍历迷宫可走的路，并且把当前步数记录在Step矩阵中，重复的位置判断步数，如果步数更少则替换
 *	
 *	输入：
 *		char map[][100]: 地图
 *		int row: 当前所在行
 *		int col: 当前所在列
 *		int step: 移动到当前位置所行走的步数
 *	最终步数保存在Step矩阵在出口位置
 */

void move(char map[][100], int row, int col, int step)
{
	if (step >= Step[row][col])
	{
		return;
	}
	Step[row][col] = step;
	if (map[row][col] == 'T')
	{
		return;
	}
	// 最后一个条件防止数组越界
	if ((map[row + 1][col] == '.' || map[row + 1][col] == 'T') && row + 1 < n)
	{
		move(map, row + 1, col, step + 1);
	}
	if ((map[row - 1][col] == '.' || map[row - 1][col] == 'T') && row - 1 >= 0)
	{
		move(map, row - 1, col, step + 1);
	}
	if ((map[row][col + 1] == '.' || map[row][col + 1] == 'T') && col + 1 < m)
	{
		move(map, row, col + 1, step + 1);
	}
	if ((map[row][col - 1] == '.' || map[row][col - 1] == 'T') && col - 1 >= 0)
	{
		move(map, row, col - 1, step + 1);
	}
}

int main()
{
	cin >> n >> m;

	int startRow = 0, startCol = 0;
	int endRow = 0, endCol = 0;
	char map[100][100];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
			{
				startRow = i;
				startCol = j;
			}
			if (map[i][j] == 'T')
			{
				endRow = i;
				endCol = j;
			}
			// 步数最多为 100*100 = 10000
			Step[i][j] = 10000;
		}
	}

	move(map, startRow, startCol, 0);

	cout << Step[endRow][endCol] << endl;
	return 0;
}